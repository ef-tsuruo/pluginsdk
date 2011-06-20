#pragma once
SXCORE
#include "sx/core/adl.hpp"
#include "sx/core/debug.hpp"
#include "sx/core/vector.hpp"

// see http://accu.org/index.php/journals/255

namespace sx {
	template<typename T> class property {
	public:
		explicit property () { }
		template<typename U> explicit property (const U &u) : data(u) { }
		template<typename U> explicit property (U &u) : data(u) { }

		const T operator () (const T &t) { // setter
			data = t;
			return data;
		}
		template<typename U0> const T operator () (const U0 &u0) { // setter
			data = T(u0);
			return data;
		}
		template<typename U0, typename U1> const T operator () (const U0 &u0, const U1 &u1) { // setter
			data = T(u0, u1);
			return data;
		}
		template<typename U0, typename U1, typename U2> const T operator () (const U0 &u0, const U1 &u1, const U2 &u2) { // setter
			data = T(u0, u1, u2);
			return data;
		}
		template<typename U0, typename U1, typename U2, typename U3> const T operator () (const U0 &u0, const U1 &u1, const U2 &u2, const U3 &u3) { // setter
			data = T(u0, u1, u2, u3);
			return data;
		}
		const T &operator() () const { // getter
			return data;
		}
		template<typename U> const T &operator<< (const U &value) {
			data << value;
			return data;
		}
		template<typename U> const T &operator^= (const U &value) {
			data ^= value;
			return data;
		}
		template<typename U> const T &operator|= (const U &value) {
			data |= value;
			return data;
		}
		template<typename U> const T &operator&= (const U &value) {
			data &= value;
			return data;
		}
		template<typename U> const T &operator+= (const U &value) {
			data += value;
			return data;
		}
		template<typename U> const T &operator-= (const U &value) {
			data -= value;
			return data;
		}
		template<typename U> const T &operator*= (const U &value) {
			data *= value;
			return data;
		}
		template<typename U> const T &operator/= (const U &value) {
			data /= value;
			return data;
		}
		T &operator++ () {
			return ++data;
		}
		T &operator-- () {
			return --data;
		}
		T operator++ (int) {
			const T t = data;
			++data;
			return t;
		}
		T operator-- (int) {
			const T t = data;
			--data;
			return t;
		}
		void swap (property<T> &t) { adl::swap(data, t.data); }
	private:
		T data;
	};
	template<typename T> inline void swap (property<T> &a, property<T> &b) {
		a.swap(b);
	}

	// pointers and (simple) containers should not be treated as properties
	template<typename T> class property<std::unique_ptr<T> > {
	private:
		property ();
	};
	template<typename T> class property<std::shared_ptr<T> > {
	private:
		property ();
	};
	template<typename T> class property<T *> {
	private:
		property ();
	};
	template<typename T> class property<std::vector<T> > {
	private:
		property ();
	};
	template<typename T> class property<sx::vector<T> > {
	private:
		property ();
	};
}
