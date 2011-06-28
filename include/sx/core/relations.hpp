#pragma once
SXCORE

namespace sx {
	// Association represents the ability of one instance to send a message to another instance.
	// |A|----------->|B|
	template<typename T> class association : public sx::signature<0x8541F65E> {
	public:
		association (T *p = 0) : p(p) { } // allow implicit conversion
		T &operator* () const {
			SXASSERT(p);
			return *p;
		}
		T *operator-> () const {
			SXASSERT(p);
			return p;
		}
		T *get () const {
			return p;
		}
		operator T *() const {
			return p;
		}
		association<T> &operator= (T *p) {
			this->p = p;
			return *this;
		}
		void check_invariant () const {
			check_signature();
		}
	private:
		T *p;
	};

	// Aggregation [...] is the typical whole/part relationship. This is exactly the same as an association with the exception that instances cannot have cyclic aggregation relationships (i.e. a part cannot contain its whole).
	// |Node|<>-------->|Node|
	template<typename T> class aggregation : public sx::signature<0x7D12AD1D> {
	public:
		aggregation (T *p = 0) : p(p) { } // allow implicit conversion
		T &operator* () const {
			SXASSERT(p);
			return *p;
		}
		T *operator-> () const {
			SXASSERT(p);
			return p;
		}
		T *get () const {
			return p;
		}
		operator T *() const {
			return p;
		}
		aggregation<T> &operator= (T *p) {
			this->p = p;
			return *this;
		}
		void reset (T *p) {
			this->p = p;
		}
		void check_invariant () const {
			check_signature();
		}
	private:
		T *p;
	};

	//Composition is exactly like Aggregation except that the lifetime of the 'part' is controlled by the 'whole'. This control may be direct or transitive. That is, the 'whole' may take direct responsibility for creating or destroying the 'part', or it may accept an already created part, and later pass it on to some other whole that assumes responsibility for it.
	// |Car|<#>-------->|Carburetor|
	template<typename T, bool DEFERRED=false> class composition : public sx::signature<0xCA14672F> {
	public:
		explicit composition () { }
		template<typename U> explicit composition (const U &u) : t(u) { }
		template<typename U> explicit composition (U &u) : t(u) { }
		template<typename U, typename V> explicit composition (U u, V v) : t(u, v) { }
		template<typename U, typename V, typename W> explicit composition (U u, V v, W w) : t(u, v, w) { }
		const T &operator() () const {
			return t;
		}
		T &operator() () {
			return t;
		}
		operator T & () {
			return t;
		}
		operator const T & () const {
			return t;
		}
		void swap (composition<T,DEFERRED> &c) { adl::swap(t, c.t); }
		void check_invariant () const {
			check_signature();
			sx::check_invariant(t);
		}
	private:
		T t;
	};

	template<typename T> class composition<T *, false> : public sx::signature<0x9B783936> {
	public:
		explicit composition () : p(new T) { }
		explicit composition (T *p) : p(p) { }
		template<typename U> explicit composition (const U &u) : p(new T(u)) { }
		template<typename U> explicit composition (U &u) : p(new T(u)) { }
		template<typename U, typename V> explicit composition (U u, V v) : p(new T(u, v)) { }
		template<typename U, typename V, typename W> explicit composition (U u, V v, W w) : p(new T(u, v, w)) { }
		explicit composition (const composition &t) : p(t.p ? new T(*t.p) : 0) { }
		composition &operator= (const composition &t) {
			if (this != &t) {
				SXASSERT(p);
				*p = t();
			}
			return *this;
		}
		const T &operator() () const {
			SXASSERT(p);
			return *p;
		}
		T &operator() () {
			SXASSERT(p);
			return *p;
		}
		operator T & () {
			SXASSERT(p);
			return *p;
		}
		operator const T & () const {
			SXASSERT(p);
			return *p;
		}
		void swap (composition<T> &c) { p.swap(c.p); }
		void check_invariant  () const {
			check_signature();
			SXASSERT(p);
			sx::check_invariant(*p);
		}
	private:
		std::unique_ptr<T> p;
	};
	template<typename T> class composition<T *, true> : public sx::signature<0xF6D6B916> {
	public:
		explicit composition () { }
		explicit composition (T *p) : p(p) { }
		template<typename U> explicit composition (const U &u) : p(new T(u)) { }
		template<typename U> explicit composition (U &u) : p(new T(u)) { }
		template<typename U, typename V> explicit composition (U u, V v) : p(new T(u, v)) { }
		template<typename U, typename V, typename W> explicit composition (U u, V v, W w) : p(new T(u, v, w)) { }
		explicit composition (const composition &t) : p(t.p ? new T(*t.p) : 0) { }
		void reset (T *t = 0) {
			p.reset(t);
		}
		composition &operator= (const composition &t) {
			if (this != &t) {
				if (t.p) {
					if (p)	*p = t();
					else	p.reset(new T(t()));
				}
				else {
					p.reset();
				}
			}
			return *this;
		}
		const T &operator() () const {
			if (!p) p.reset(new T);
			return *p;
		}
		T &operator() () {
			if (!p) p.reset(new T);
			return *p;
		}
		operator T & () {
			return *p;
		}
		operator const T & () const {
			return *p;
		}
		void swap (composition<T> &c) { p.swap(c.p); }
		void check_invariant  () const {
			check_signature();
			if (p) sx::check_invariant(*p);
		}
	private:
		mutable std::unique_ptr<T> p;
	};
	template<typename T, bool DEFERRED> inline void swap (composition<T,DEFERRED> &a, composition<T,DEFERRED> &b) {
		a.swap(b);
	}

	template<typename T> class reference : public sx::signature<0xC79FCE32> {
	public:
		typedef T element_type;

		explicit reference (T *p) : p(p) { } // do NOT allow implicit conversion
		T &operator* () const {
			SXASSERT(p);
			return *p;
		}
		T *operator-> () const {
			SXASSERT(p);
			return p;
		}
		T *get () const {
			return p;
		}
		reference &operator= (const reference &t) { // do nothing
			return *this;
		}
		operator T *() const {
			return p;
		}
	private:
		T *const p;
	};
}

