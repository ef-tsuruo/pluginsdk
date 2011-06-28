#pragma once
SXCORE
#include "sx/core/adl.hpp"
#include "boost/ptr_container/ptr_vector.hpp"
#include "sx/core/settings.hpp"

namespace sx {

	template<typename T, typename Alloc> T *get (std::vector<T, Alloc> &v) {
		if (!v.empty()) return &(v[0]);
		return 0;
	}
	template<typename T, typename Alloc> const T *get (const std::vector<T, Alloc> &v) {
		if (!v.empty()) return const_cast<T *>(&(v[0]));
		return 0;
	}
	template<typename T> typename T::size_type find_index (const T &v, const typename T::value_type &u) {
		sxassert(std::find(v.begin(), v.end(), u) != v.end());
		return std::find(v.begin(), v.end(), u)-v.begin();
	}
	template<typename T> inline void verify_index (const T &v, typename T::size_type i) {
		if (v.size() <= i) throw "Index out of range.";
	}
	template<typename T> class is_delete_flag_set {
	public:
		bool operator() (const T &t) const { return t.delete_flag(); }
	};
	template<typename T> void remove (T &v) {
		v.resize(std::remove_if(v.begin(), v.end(), is_delete_flag_set<typename T::value_type>()) - v.begin());
		sxassert(std::find_if(v.begin(), v.end(), is_delete_flag_set<typename T::value_type>()) == v.end());
	}
	template<typename T> class vector_item_template : public sx::signature<> {
	public:	// property
		const bool delete_flag () const { sxassert(p); return p->delete_flag(); }
	public:
		explicit vector_item_template () : p(0) { }
		vector_item_template (T *c) : p(c) { } // allow implicit conversion
		vector_item_template (const vector_item_template<T> &t) : p(t.p) {
			const_cast<vector_item_template<T> &>(t).p = 0; // caution: ownership is transfered FROM the const item.
		}
		const vector_item_template<T> &operator= (const vector_item_template<T> &t) {
			if (this != &t) {
				delete p;
				p = t.p;
				const_cast<vector_item_template<T> &>(t).p = 0; // caution: ownership is transfered FROM the const item.
			}
			return *this;
		}
		~vector_item_template () { delete p; }
		const T &operator () () const { sxassert(p); return *p; }
		T &operator () () { sxassert(p); return *p; }
		operator const T &() const { sxassert(p); return *p; }
		operator T &() { sxassert(p); return *p; }
		const T *get () const { return p; }
		T *get () { return p; }
		void swap (vector_item_template<T> &t) { sx::adl::swap(p, t.p); }
	private:
		T *p;
	};
	template<typename T> inline void swap (vector_item_template<T> &a, vector_item_template<T> &b) {
		a.swap(b);
	}

	typedef std::vector<int> ints;
	typedef std::vector<float> floats;
	
	template<typename T> class vector_accessor_interface {
	public:
		typedef T value_type;

		virtual ~vector_accessor_interface () { }
		std::size_t size () const { return size_imp(); }
		bool empty () const { return empty_imp(); }
		T &operator[] (std::size_t i) {
			SXTEST(sx::check_invariant(*this));
			return const_cast<T &>(const_cast<const vector_accessor_interface<T> &>(*this)[i]);
		}
		const T &operator[] (std::size_t i) const {
			SXTEST(sx::check_invariant(*this));
			return item_at_imp(i);
		}
		void check_invariant () const {
			if (sx::core::settings::check_invariant()) check_invariant_imp();
		}
	private:
		virtual std::size_t size_imp () const = 0;
		virtual bool empty_imp () const = 0;
		virtual const T &item_at_imp (std::size_t i) const = 0;
		virtual void check_invariant_imp () const { SXASSERT(false); }
	};

	template<typename T> class vector_accessor : public vector_accessor_interface<typename T::value_type> {
	public:
		explicit vector_accessor (T &t) : t(t) { }
	private:
		T &t;

		virtual std::size_t size_imp () const { return t.size(); }
		virtual bool empty_imp () const { return t.empty(); }
		virtual const typename T::value_type &item_at_imp (std::size_t i) const { return t[i]; }
		virtual void check_invariant_imp () const { }
	};
	template<typename T> class vector_accessor<T *> : public vector_accessor_interface<T> {
	public:
		explicit vector_accessor (const T *t, std::size_t n) : t(t), n(n) { }
	private:
		const T *const t;
		const std::size_t n;

		virtual std::size_t size_imp () const { return n; }
		virtual bool empty_imp () const { return (n == 0); }
		virtual const T &item_at_imp (std::size_t i) const { return t[i]; }
		virtual void check_invariant_imp () const { }
	};
	template<typename T, typename S> class vector_index_accessor : public vector_accessor_interface<typename T::value_type> {
	public:
		explicit vector_index_accessor (T &t, const S &indices) : t(t), indices(indices) { }
	private:
		T &t;
		const S &indices;

		virtual std::size_t size_imp () const { return t.size(); }
		virtual bool empty_imp () const { return t.empty(); }
		virtual const typename T::value_type &item_at_imp (std::size_t i) const { return t[indices[i]]; }
		virtual void check_invariant_imp () const { }
	};
	template<typename T, typename S> class vector_index_accessor<T *, S *> : public vector_accessor_interface<T> {
	public:
		explicit vector_index_accessor (const T *t, const S *indices, std::size_t n) : t(t), indices(indices), n(n) { }
	private:
		const T *const t;
		const S *const indices;
		const std::size_t n;

		virtual std::size_t size_imp () const { return n; }
		virtual bool empty_imp () const { return (n == 0); }
		virtual const T &item_at_imp (std::size_t i) const { return t[indices[i]]; }
		virtual void check_invariant_imp () const { }
	};
	template<typename T> class vector_fill_accessor : public vector_accessor_interface<T> {
	public:
		explicit vector_fill_accessor (const T &t, std::size_t n) : t(t), n(n) { }
	private:
		const T &t;
		const std::size_t n;

		virtual std::size_t size_imp () const { return n; }
		virtual bool empty_imp () const { return (n == 0); }
		virtual const T &item_at_imp (std::size_t i) const { return t; }
		virtual void check_invariant_imp () const { }
	};
}

namespace boost {
	template<typename T, typename U> inline boost::ptr_vector<T> &operator<< (boost::ptr_vector<T> &v, const U &u) {
		v.push_back(u);
		return v;
	}
}
template<typename T, typename Alloc, typename U> inline std::vector<T, Alloc> &operator<< (std::vector<T, Alloc> &v, const U &u) {
	v.push_back(u);
	return v;
}
template<typename T, typename Alloc> void shrink_to_fit (std::vector<T, Alloc> &v) {
	std::vector<T, Alloc>(v).swap(v);
}
namespace sx {
	template<typename T, typename Alloc> void check_invariant (const std::vector<T, Alloc> &v) {
//		foreach (const T &t, v) check_invariant(t);
	}
}
