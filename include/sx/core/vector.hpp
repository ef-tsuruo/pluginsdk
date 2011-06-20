#pragma once
SXCORE
#include "sx/core/adl.hpp"
#include "sx/core/memory.hpp"
#include "sx/core/type_traits.hpp"
#include "sx/core/debug.hpp"
#include "sx/core/simd.hpp"

#undef check

namespace sx {
	typedef vectorx alignment_type;
	
	template<typename T, std::size_t N> class xvector_data_template {
	public:
		explicit xvector_data_template (T *p) : p(p) { }
		T *const get_p () const { return (p ? p : (T *)storage); }
		T *const storagep () const {
			//sxassert(is_aligned(storage));
			return (T *)storage;
		}
		operator T *const () const { return p; }
		T *const operator= (T *q) { return (p = q); }
		void swap (xvector_data_template<T,N> &t) { adl::swap(p, t.p); }
		bool check_invariant () const {
			SXASSERT(sx::memory::check_address(p));
			return true;
		}
	private:
		alignment_type storage[(sizeof(T) * N + sizeof(alignment_type) - 1) / sizeof(alignment_type)];
		T *p;
	};
	template<typename T> class xvector_data_template<T, 0> {
	public:
		explicit xvector_data_template (T *p) : p(p) { }
		T *const get_p () const { return p; }
		T *const storagep () const { return 0; }
		operator T *const () const { return p; }
		T *const operator= (T *q) { return (p = q); }
		void swap (xvector_data_template<T,0> &t) { adl::swap(p, t.p); }
		bool check_invariant () const {
			SXASSERT(sx::memory::check_address(p));
			return true;
		}
	private:
		T *p;
	};
	template<typename T, std::size_t N> inline void swap (xvector_data_template<T,N> &a, xvector_data_template<T,N> &b) {
		a.swap(b);
	}
	
	template <typename T, std::size_t N> class vector;

	template <typename T, std::size_t N = 0> class vector {
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef vector<T,N> type;
		typedef std::size_t difference_type;
		typedef std::size_t size_type;;
		typedef T *iterator, *reverse_iterator;
		typedef const T *const_iterator, *const_reverse_iterator;

		inline explicit vector ();
		inline vector (const vector &t);
		inline explicit vector (std::size_t n);
		inline explicit vector (std::size_t n, const T &t);
		inline vector &operator= (const vector &t);
		inline ~vector ();
		inline void reserve (std::size_t k);
		inline void resize (std::size_t k);
		inline void resize (std::size_t k, const T &t);
		inline void clear ();
		inline void push_back (const T &t);
		inline void pop_back ();
		inline T *insert (iterator loc, const T& t);
		inline void insert (iterator loc, std::size_t num, const T& t);
		inline void insert (iterator loc, const_iterator start, const_iterator end);
		inline const T &operator[] (std::size_t i) const;
		inline T &operator[] (std::size_t i) {
			return const_cast<T &>(static_cast<const vector &>(*this)[i]);
		}
		inline const T &front () const;
		inline T &front ();
		inline const T &back () const;
		inline T &back ();
		inline void erase (T *i);
		const T *begin () const {
			return get_p();
		}
		T *begin () {
			return get_p();
		}
		const T *end () const {
			return (get_p() + n);
		}
		T *end () {
			return (get_p() + n);
		}
		const T *rbegin () const {
			return get_p()+(n-1);
		}
		T *rbegin () {
			return get_p()+(n-1);
		}
		const T *rend () const {
			return (get_p() - 1);
		}
		T *rend () {
			return (get_p() - 1);
		}
		bool empty () const { return n == 0; }
		std::size_t size () const { return n; }
		std::size_t capacity () const {
			if (p == 0) return N;
			return get_size(p);
		}

		inline void swap (vector &v);

		inline bool operator== (const vector<T, N> &) const;
		inline bool operator!= (const vector<T, N> &) const;
		vector<T, N> &operator<< (const T &t) {
			push_back(t);
			return *this;
		}
		inline void shrink_to_fit ();
		bool check_invariant () const;
	private:
		xvector_data_template<T,N> p;
		std::size_t n;

		T *get_p () const { return p.get_p(); }
		T *storagep () const { return p.storagep(); }
		T *allocate (std::size_t n) const {
			return (T *)sx::memory::allocate(sx::memory::get_optimum_size(sizeof(T)*n) / sizeof(T) * sizeof(T));
		}
		void free (T *p) const {
			sx::memory::free(p);
		}
		std::size_t get_size (T *p) const {
			sxassert(sx::memory::get_size(p) % sizeof(T) == 0);
			return (sx::memory::get_size(p) / sizeof(T));
		}
		
		// no need to inline
		void cleanup (T *p, std::size_t begin, std::size_t end);
		void copy_imp (const vector<T,N> &t);
		void shrink_to_fit_imp ();
		void assign_imp (const vector &t);
		void reserve_imp (std::size_t k);
		void resize_imp (std::size_t k);
		void resize_imp (std::size_t k, const T &t);
		void append_imp (const_iterator start, const_iterator end);
		void insert_imp (iterator loc, std::size_t tn, const T& t);
		void insert_imp (iterator loc, const_iterator first, const_iterator last);

		void append (const_iterator start, const_iterator end);
	};
	template<typename T, std::size_t N> void vector<T, N>::cleanup (T *p, std::size_t begin, std::size_t end) {
		if (p) {
			for (std::size_t i = begin; i < end; ++i) p[i].~T();
		}
	}
	template<typename T, std::size_t N> inline T *get (vector<T, N> &v) {
		sxassert(v.check_invariant());
		return v.empty() ? 0 : &(v[0]);
	}
	template<typename T, std::size_t N> inline const T *get (const vector<T, N> &v) {
		sxassert(v.check_invariant());
		return v.empty() ? 0 : &(v[0]);
	}
	template<typename T, std::size_t N> inline void swap (vector<T, N> &a, vector<T, N> &b) {
		sxassert(a.check_invariant());
		sxassert(b.check_invariant());
		a.swap(b);
		sxassert(a.check_invariant());
		sxassert(b.check_invariant());
	}
	template<typename T, std::size_t N> inline void vector<T, N>::swap (vector &v) {
		SXASSERT(check_invariant());
		sxassert(v.check_invariant());
		if (0 < N) {
			if (p) {
				if (v.p) {
					adl::swap(n, v.n);
					adl::swap(p, v.p);
				}
				else {
					if (!boost::has_trivial_constructor<T>::value) { std::size_t i; try { for (i = 0; i < v.n; ++i) ::new (storagep() + i) T; } catch (...) { cleanup(storagep(), 0, i); throw; } }
					{ std::size_t i; try { for (i = 0; i < v.n; ++i) adl::swap(storagep()[i], v.storagep()[i]); } catch (...) { cleanup(storagep(), 0, v.n); throw; } }
					if (!boost::has_trivial_destructor<T>::value) { for (std::size_t i = 0; i < v.n; ++i) v.storagep()[i].~T(); }
					adl::swap(n, v.n);
					adl::swap(p, v.p);
				}
			}
			else {
				if (v.p) {
					if (!boost::has_trivial_constructor<T>::value) { std::size_t i; try { for (i = 0; i < n; ++i) ::new (v.storagep() + i) T; } catch (...) { cleanup(v.storagep(), 0, i); throw; } }
					try { for (std::size_t i = 0; i < n; ++i) adl::swap(storagep()[i], v.storagep()[i]); } catch (...) { cleanup(v.storagep(), 0, v.n); throw; }
					if (!boost::has_trivial_destructor<T>::value) { for (std::size_t i = 0; i < n; ++i) v.storagep()[i].~T(); }
					adl::swap(n, v.n);
					adl::swap(p, v.p);
				}
				else {
					if (n < v.n) {
						if (!boost::has_trivial_constructor<T>::value) { std::size_t i; try { for (i = n; i < v.n; ++i) ::new (storagep()+i) T; } catch (...) { cleanup(storagep(), n, i); throw; } }
						try { for (std::size_t i = 0; i < v.n; ++i) adl::swap(storagep()[i], v.storagep()[i]); } catch (...) { cleanup(storagep(), n, v.n); throw; }
						if (!boost::has_trivial_destructor<T>::value) { for (std::size_t i = n; i < v.n; ++i) v.storagep()[i].~T(); }
					}
					else {
						if (!boost::has_trivial_constructor<T>::value) { std::size_t i; try { for (i = v.n; i < n; ++i) ::new (v.storagep()+i) T; } catch (...) { cleanup(v.storagep(), v.n, i); throw; } }
						try { for (std::size_t i = 0; i < n; ++i) adl::swap(storagep()[i], v.storagep()[i]); } catch (...) { cleanup(v.storagep(), v.n, n); throw; }
						if (!boost::has_trivial_destructor<T>::value) { for (std::size_t i = v.n; i < n; ++i) storagep()[i].~T(); }
					}
					adl::swap(n, v.n);
				}
			}
		}
		else {
			adl::swap(n, v.n);
			adl::swap(p, v.p);
		}
		SXASSERT(check_invariant());
		sxassert(v.check_invariant());
	}
	template<typename T, std::size_t N> void vector<T, N>::shrink_to_fit_imp () {
		SXASSERT(check_invariant());
		sxassert(p);
		if ((0 < N) && (n <= N)) {
			if (sx::is_movable<T>::value) {
				if (0 < n) ::memcpy(storagep(), p, sizeof(T)*n);
			}
			else {
				if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) new (storagep()+i) T; } catch (...) { cleanup(storagep(), 0, i); throw; } }
				if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(storagep()[i], p[i]); } catch (...) { cleanup(storagep(), 0, n); throw; } }
				else											{ if (0 < n) ::memcpy(storagep(), p, sizeof(T)*n); }
				if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) p[i].~T(); }
			}
			free(p); p = 0;
		}
		else if (n < get_size(p)) {
			if (!sx::memory::shrink(p, sx::memory::get_optimum_size(sizeof(T)*n) / sizeof(T) * sizeof(T))) {
				T *const q = allocate(n);
				if (sx::is_movable<T>::value) {
					if (0 < n) ::memcpy(q, p, sizeof(T)*n);
				}
				else {
					if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) new (q+i) T; } catch (...) { cleanup(q, 0, i); free(q); throw; } }
					if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(p[i], q[i]); } catch (...) { cleanup(q, 0, n); free(q); throw; } }
					else											{ if (0 < n) ::memcpy(q, p, sizeof(T)*n); }
					if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) p[i].~T(); }
				}
				free(p); p = q;
			}
		}
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline void vector<T, N>::shrink_to_fit () {
		SXASSERT(check_invariant());
		if (p) {
			shrink_to_fit_imp();
		}
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline vector<T, N>::vector () : p(0), n(0) {
		SXASSERT(check_invariant());
	}

	template<typename T, std::size_t N> void vector<T, N>::copy_imp (const vector &t) {
		if (N < t.n) {
			p = allocate(t.n);
		}
		T *const q = get_p();
		const T *const r = t.get_p();
		if (!boost::has_trivial_copy<T>::value)	{ std::size_t i; try { for (i = 0; i < t.n; ++i) ::new (q+i) T(r[i]); } catch (...) { cleanup(q, 0, i); free(p); throw; } }
		else									{ if (0 < t.n) ::memcpy(q, r, sizeof(T)*t.n); }
		n = t.n;
	}
	template<typename T, std::size_t N> inline vector<T, N>::vector (const vector &t) : p(0), n(0) {
		SXASSERT(check_invariant());
		sxassert(t.check_invariant());
		if (0 < t.n) {
			copy_imp(t);
		}
		SXASSERT(check_invariant());
		sxassert(t.check_invariant());
	}
	template<typename T, std::size_t N> inline vector<T, N>::vector (std::size_t n) : p(0), n(0) {
		SXASSERT(check_invariant());
		if (N < n) p = allocate(n);
		T *q = get_p();
		if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) ::new (q+i) T; } catch (...) { cleanup(q, 0, i); free(p); throw; } }
		this->n = n;
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline vector<T, N>::vector (std::size_t n, const T &t) : p(0), n(0) {
		SXASSERT(check_invariant());
		if (N < n) p = allocate(n);
		T *q = get_p();
		if (!boost::has_trivial_copy<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) ::new (q+i) T(t); } catch (...) { cleanup(q, 0, i); free(p); throw; } }
		else									{ for (std::size_t i = 0; i < n; ++i) *(q+i) = t; }
		this->n = n;
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> void vector<T, N>::assign_imp (const vector &t) {
		sxassert(t.p);
		if (!boost::has_trivial_destructor<T>::value)	{ T *q = get_p(); for (std::size_t i = 0; i < n; ++i) q[i].~T(); }
		free(p);
		retain(p = t.p);
		n = t.n;
	}
	template<typename T, std::size_t N> inline vector<T, N> &vector<T, N>::operator= (const vector &t) {
		SXASSERT(check_invariant());
		sxassert(t.check_invariant());
		if (this != &t) {
			if (!boost::has_trivial_assign<T>::value)	{
				if (!boost::has_nothrow_assign<T>::value)	{ vector<T, N> tmp(t); swap(tmp); }
				else										{ resize(t.n); T *p = get_p(); const T *q = t.get_p(); for (std::size_t i = 0; i < t.n; ++i) *p++ = *q++; }
			}
			else											{ resize(t.n); T *p = get_p(); const T *q = t.get_p(); if (0 < t.n) ::memcpy(p, q, sizeof(T)*t.n); }
		}
		SXASSERT(check_invariant());
		sxassert(n == t.n);
		return *this;
	}
	template<typename T, std::size_t N> inline vector<T, N>::~vector () {
		SXASSERT(check_invariant());
		if (!boost::has_trivial_destructor<T>::value) {
			T *const p = get_p();
			SXASSERT((n == 0) || p);
			for (std::size_t i = 0; i < n; ++i) p[i].~T();
		}
		free(p);
	}
	template<typename T, std::size_t N> void vector<T, N>::reserve_imp (std::size_t k) {
		T *const q = allocate(k);
		{	T *const p = get_p();
			if (sx::is_movable<T>::value) {
				if (0 < n) ::memcpy(q, p, sizeof(T)*n);
			}
			else {
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { for (i = 0; i < n; ++i) ::new (q+i) T(p[i]); } catch (...) { cleanup(q, 0, i); free(q); throw; } }
				else											{ if (0 < n) ::memcpy(q, p, sizeof(T)*n); }
				if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) p[i].~T(); }
			}
		}
		free(p);
		p = q;
	}
	template<typename T, std::size_t N> inline void vector<T, N>::reserve (std::size_t k) {
		SXASSERT(check_invariant());
		if (capacity() < k) {
			reserve_imp(k);
		}
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline void vector<T, N>::clear () {
		SXASSERT(check_invariant());
		if (!boost::has_trivial_destructor<T>::value)	{ T *const p = get_p(); for (std::size_t i = 0; i < n; ++i) p[i].~T(); }
		free(p);
		p = 0;
		n = 0;
	}
	template<typename T, std::size_t N> void vector<T, N>::resize_imp (std::size_t k) {
		sxassert(n < k);
		if (p) {
			if (get_size(p) < k) {
				T *const q = allocate(k);
				if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < k; ++i) ::new (q+i) T; } catch (...) { cleanup(q, 0, i); free(q); throw; } }
				if (sx::is_movable<T>::value) {
					if (0 < n) ::memcpy(q, p, sizeof(T)*n);
				}
				else {
					if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(p[i], q[i]); } catch (...) { cleanup(q, 0, n); free(q); throw; } }
					else											{ if (0 < n) ::memcpy(q, p, sizeof(T)*n); }
					if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) p[i].~T(); }
				}
				free(p); p = q;
			}
			else {
				if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = n; i < k; ++i) ::new (p+i) T; } catch (...) { cleanup(p, n, i); throw; } }
			}
		}
		else {
			if (N < k) {
				T *const q = allocate(k);
				if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < k; ++i) ::new (q+i) T; } catch (...) { cleanup(q, 0, i); free(q); throw; } }
				if (sx::is_movable<T>::value) {
					if (0 < n) ::memcpy(q, storagep(), sizeof(T)*n);
				}
				else {
					if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(storagep()[i], q[i]); } catch (...) { cleanup(q, 0, n); free(q); throw; } }
					else											{ if (0 < n) ::memcpy(q, storagep(), sizeof(T)*n); }
					if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) storagep()[i].~T(); }
				}
				p = q;
			}
			else {
				if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = n; i < k; ++i) ::new (storagep()+i) T; } catch (...) { cleanup(storagep(), n, i); throw; } }
			}
		}
		n = k;
	}
	template<typename T, std::size_t N> inline void vector<T, N>::resize (std::size_t k) {
		SXASSERT(check_invariant());
		#ifndef NDEBUG
			const std::size_t old_capacity = capacity();
		#endif
		if (k < n) {
			if (!boost::has_trivial_destructor<T>::value)	{ T *const p = get_p(); for (std::size_t i = k; i < n; ++i) p[i].~T(); }
			n = k;
		}
		else if (n < k) {
			resize_imp(k);
		}
		#ifndef NDEBUG
			if (n <= old_capacity) sxassert(old_capacity == capacity());
		#endif
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> void vector<T, N>::resize_imp (std::size_t k, const T &t) {
		sxassert(n < k);
		if (p) {
			if (get_size(p) < k) {
				T *const q = allocate(k);
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { for (i = n; i < k; ++i) ::new (q+i) T(t); } catch (...) { cleanup(q, n, i); free(q); throw; } }
				else											{ for (std::size_t i = n; i < k; ++i) *(q+i) = t; }
				
				if (sx::is_movable<T>::value) {
					if (0 < n) ::memcpy(q, p, sizeof(T)*n);
				}
				else {
					if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) ::new (q+i) T; } catch (...) { cleanup(q, 0, i); cleanup(q, n, k); free(q); throw; } }
					if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(p[i], q[i]); } catch (...) { cleanup(q, 0, k); free(q); throw; } }
					else											{ if (0 < n) ::memcpy(q, p, sizeof(T)*n); }
					if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) p[i].~T(); }
				}
				free(p);
				p = q;
			}
			else {
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { for (i = n; i < k; ++i) ::new (p+i) T(t); } catch (...) { cleanup(p, n, i); throw; } }
				else											{ for (std::size_t i = n; i < k; ++i) *(p+i) = t; }
			}
		}
		else {
			if (N < k) {
				T *const q = allocate(k);
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { for (i = n; i < k; ++i) ::new (q+i) T(t); } catch (...) { cleanup(q, n, i); free(q); throw; } }
				else											{ for (std::size_t i = n; i < k; ++i) *(q+i) = t;}

				if (sx::is_movable<T>::value) {
					if (0 < n) ::memcpy(q, storagep(), sizeof(T)*n);
				}
				else {
					if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) ::new (q+i) T; } catch (...) { cleanup(q, 0, i); cleanup(q, n, k); free(q); throw; } }
					if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(storagep()[i], q[i]); } catch (...) { cleanup(q, 0, k); free(q); throw; } }
					else											{ if (0 < n) ::memcpy(q, storagep(), sizeof(T)*n); }
					if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) storagep()[i].~T(); }
				}
				p = q;
			}
			else {
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { for (i = n; i < k; ++i) ::new (storagep()+i) T(t); } catch (...) { cleanup(storagep(), n, i); throw; } }
				else											{ for (std::size_t i = n; i < k; ++i) *(storagep()+i) = t; }
			}
		}
		n = k;
	}
	template<typename T, std::size_t N> inline void vector<T, N>::resize (std::size_t k, const T &t) {
		SXASSERT(check_invariant());
		#ifndef NDEBUG
			const std::size_t old_capacity = capacity();
		#endif
		if (k < n) {
			if (!boost::has_trivial_destructor<T>::value)	{ T *q = get_p(); for (std::size_t i = k; i < n; ++i) q[i].~T(); }
			n = k;
		}
		else if (n < k) {
			resize_imp(k, t);
		}
		#ifndef NDEBUG
			if (n <= old_capacity) sxassert(old_capacity == capacity());
		#endif
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> void vector<T, N>::append_imp (const_iterator start, const_iterator end) {
		const std::size_t k = n + (end - start);
		if (p) {
			if (get_size(p) < k) {
				T *const q = allocate(k);
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { const_iterator t = start; for (i = n; i < k; ++i) ::new (q+i) T(*t++); } catch (...) { cleanup(q, n, i); free(q); throw; } }
				else											{ if (0 < (k-n)) ::memcpy(q+n, start, sizeof(T)*(k-n)); }

				if (sx::is_movable<T>::value) {
					if (0 < n) ::memcpy(q, p, sizeof(T)*n);
				}
				else {
					if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) ::new (q+i) T; } catch (...) { cleanup(q, 0, i); cleanup(q, n, k); free(q); throw; } }
					if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(p[i], q[i]); } catch (...) { cleanup(q, 0, k); free(q); throw; } }
					else											{ if (0 < n) ::memcpy(q, p, sizeof(T)*n); }
					if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) p[i].~T(); }
				}
				free(p);
				p = q;
			}
			else {
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { const_iterator t = start; for (i = n; i < k; ++i) ::new (p+i) T(*t++); } catch (...) { cleanup(p, n, i); throw; } }
				else											{ if (0 < (k-n)) ::memcpy(p+n, start, sizeof(T)*(k-n)); }
			}
		}
		else {
			if (N < k) {
				T *const q = allocate(k);
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { const_iterator t = start; for (i = n; i < k; ++i) ::new (q+i) T(*t++); } catch (...) { cleanup(q, n, i); free(q); throw; } }
				else											{ if (0 < (k-n)) ::memcpy(q+n, start, sizeof(T)*(k-n)); }
				
				if (sx::is_movable<T>::value) {
					if (0 < n) ::memcpy(q, storagep(), sizeof(T)*n);
				}
				else {
					if (!boost::has_trivial_constructor<T>::value)	{ std::size_t i; try { for (i = 0; i < n; ++i) ::new (q+i) T; } catch (...) { cleanup(q, 0, i); cleanup(q, n, k); free(q); throw; } }
					if (!boost::has_trivial_assign<T>::value)		{ try { for (std::size_t i = 0; i < n; ++i) adl::swap(storagep()[i], q[i]); } catch (...) { cleanup(q, 0, k); free(q); throw; } }
					else											{ if (0 < n) ::memcpy(q, storagep(), sizeof(T)*n); }
					if (!boost::has_trivial_destructor<T>::value)	{ for (std::size_t i = 0; i < n; ++i) storagep()[i].~T(); }
				}
				free(p);
				p = q;
			}
			else {
				if (!boost::has_trivial_copy<T>::value)			{ std::size_t i; try { const_iterator t = start; for (i = n; i < k; ++i) ::new (storagep()+i) T(*t++); } catch (...) { cleanup(storagep(), n, i); throw; } }
				else											{ if (0 < (k-n)) ::memcpy(storagep()+n, start, sizeof(T)*(k-n)); }
			}
		}
		n = k;
	}
	template<typename T, std::size_t N> inline void vector<T, N>::append (const_iterator start, const_iterator end) {
		SXASSERT(check_invariant());
		#ifndef NDEBUG
			const std::size_t old_capacity = capacity();
		#endif
		append_imp(start, end);
		#ifndef NDEBUG
			if (n <= old_capacity) sxassert(old_capacity == capacity());
		#endif
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline void vector<T, N>::push_back (const T &t) {
		SXASSERT(check_invariant());
		resize(n+1, t);
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline void vector<T, N>::pop_back () {
		SXASSERT(check_invariant());
		sxassert(0 < n);
		get_p()[n-1].~T();
		--n;
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline T *vector<T, N>::insert (iterator loc, const T& t) {
		const std::size_t s = loc - begin();
		insert(loc, 1, t);
		return begin() + s;
	}
	template<typename T, std::size_t N> void vector<T, N>::insert_imp (iterator loc, std::size_t tn, const T& t) {
		const std::size_t s = loc - begin();
		resize(n+tn);
		T *const p = get_p();
		if (!boost::has_trivial_assign<T>::value)		{ for (std::size_t i = n-tn; s < i; --i) adl::swap(p[i-1], p[i-1+tn]); }
		else											{ for (std::size_t i = n-tn; s < i; --i) p[i-1+tn] = p[i-1]; }
		for (std::size_t i = 0; i < tn; ++i) p[s+i] = t;
	}
	template<typename T, std::size_t N> inline void vector<T, N>::insert (iterator loc, std::size_t tn, const T& t) {
		SXASSERT(check_invariant());
		if (0 < tn) {
			if (loc == end())	resize(n+tn, t);
			else				insert_imp(loc, tn, t);
		}
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> void vector<T, N>::insert_imp (iterator loc, const_iterator first, const_iterator last) {
		const std::size_t s = loc - begin();
		const std::size_t tn = last - first;
		resize(n+tn);
		T *const p = get_p();
		if (!boost::has_trivial_assign<T>::value)		{ for (std::size_t i = n-tn; s < i; --i) adl::swap(p[i-1], p[i-1+tn]); }
		else											{ for (std::size_t i = n-tn; s < i; --i) p[i-1+tn] = p[i-1]; }
		for (std::size_t i = 0; i < tn; ++i) p[s+i] = *(first+i);
	}
	template<typename T, std::size_t N> inline void vector<T, N>::insert (iterator loc, const_iterator first, const_iterator last) {
		SXASSERT(check_invariant());
		if (loc == end())	append(first, last);
		else				insert_imp(loc, first, last);
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline const T &vector<T, N>::operator[] (std::size_t i) const {
		SXASSERT(check_invariant());
		sxassert(i < n);
		return get_p()[i];
	}
	template<typename T, std::size_t N> inline const T &vector<T, N>::front () const {
		SXASSERT(check_invariant());
		sxassert(0 < n);
		return get_p()[0];
	}
	template<typename T, std::size_t N> bool vector<T, N>::check_invariant () const {
		SXASSERT(p.check_invariant());
		SXASSERT((n <= N) || (n <= get_size(p)));
		#if !defined(NDEBUG) || SXASSERTDEFINED
			if (N < n) {
				sx::memory::header_class *q = sx::memory::header(get_p());
				if (q->offset != -1) {
					const std::size_t s = sx::memory::get_optimum_size(sizeof(T)*n)/sizeof(T)*sizeof(T);
					SXASSERT(s <= q->size);
				}
			}
		#endif
		return true;
	}
	template<typename T, std::size_t N> inline T &vector<T, N>::front () {
		SXASSERT(check_invariant());
		sxassert(0 < n);
		return get_p()[0];
	}
	template<typename T, std::size_t N> inline const T &vector<T, N>::back () const {
		SXASSERT(check_invariant());
		sxassert(0 < n);
		return get_p()[n-1];
	}
	template<typename T, std::size_t N> inline T &vector<T, N>::back () {
		SXASSERT(check_invariant());
		sxassert(0 < n);
		return get_p()[n-1];
	}
	template<typename T, std::size_t N> inline bool vector<T, N>::operator== (const vector<T, N> &b) const {
		SXASSERT(check_invariant());
		sxassert(b.check_invariant());
		const vector<T, N> &a = *this;
		if (a.n != b.n) return false;
		T *ap = a.get_p();
		T *bp = b.get_p();
		const std::size_t n = a.n;
		for (std::size_t i = 0; i < n; ++i) {
			if (*ap++ != *bp++) return false;
		}
		return true;
	}
	template<typename T, std::size_t N> inline bool vector<T, N>::operator!= (const vector<T, N> &b) const {
		const vector<T, N> &a = *this;
		return !(a == b);
	}
	template<typename T, std::size_t N> inline void vector<T, N>::erase (T *q) {
		SXASSERT(check_invariant());
		if (!q) return;
		sxassert(begin() <= q && q < end());
		{	T *const p = get_p();
			if (!boost::has_trivial_assign<T>::value)		{ for (std::size_t i = q - p; i+1 < n; ++i) adl::swap(p[i], p[i+1]); }
			else											{ for (std::size_t i = q - p; i+1 < n; ++i) p[i] = p[i+1]; }
			if (!boost::has_trivial_destructor<T>::value)	{ p[n-1].~T(); }
		}
		--n;
		SXASSERT(check_invariant());
	}
	template<typename T, std::size_t N> inline void shrink_to_fit (vector<T, N> &v) {
		v.shrink_to_fit();
	}

	template<typename T, std::size_t N> bool check_invariant (const sx::vector<T, N> &v) {
		foreach (const T &t, v) t.check_invariant();
		return true;
	}
	template<typename T, std::size_t N> bool check_invariant (const sx::vector<T *, N> &v) {
		foreach (T *const t, v) if (t) t->check_invariant();
		return true;
	}
	
	namespace core {
		namespace unittest {
			void test_xvector ();
		}
	}
}

template<typename T, std::size_t N> std::ostream &operator<< (std::ostream &stream, const sx::vector<T,N> &v) {
	foreach (const T &t, v) stream << t << std::endl;
	return stream;
}
