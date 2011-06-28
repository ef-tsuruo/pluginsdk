#pragma once
SXCORE

class half;

namespace sx {
	namespace debug {
		namespace settings {
			extern bool debug;
		}
		
		class tracer_class {
		public:
			explicit tracer_class (const char *name);
			~tracer_class ();
		private:
			const char *const _name;
		};
	}

	inline void check_invariant (const boost::any &) { }
	inline void check_invariant (const bool &) { }
	inline void check_invariant (const signed char &) { }
	inline void check_invariant (const unsigned char &) { }
	inline void check_invariant (const char &) { }
	inline void check_invariant (const short &) { }
	inline void check_invariant (const unsigned short &) { }
	inline void check_invariant (const int &) { }
	inline void check_invariant (const unsigned int &) { }
	inline void check_invariant (const long &) { }
	inline void check_invariant (const unsigned long &) { }
	inline void check_invariant (const long long &) { }
	inline void check_invariant (const unsigned long long &) { }
	inline void check_invariant (const float &) { }
	inline void check_invariant (const double &) { }
	inline void check_invariant (const half &) { }
	template<typename T> inline void check_invariant (T *) { }
	template<typename T> inline void check_invariant (const T *) { }
	template<typename T> inline void check_invariant (const std::vector<T> &) { }
	template<typename T> inline void check_invariant (const std::shared_ptr<T> &) { }
	template<typename T, long unsigned int N> inline void check_invariant (const std::array<T,N> &) { }
	template<typename T, typename U> inline void check_invariant (const std::pair<T,U> &v) {
//		sx::check(v.first);
//		sx::check(v.second);
	}
	template<typename T> inline void check_invariant (const T &t) {
		t.check_invariant();
	}

	extern int debug_level;
	void debugbreak (const char *file, int line);
}

#if __GNUG__
	#define SXTRACE sx::debug::tracer_class sxdebugtracer(__PRETTY_FUNCTION__);
#else
	#define SXTRACE
#endif

#ifdef NDEBUG
	#define sxassert(a)
#else
	#define sxassert(a) do { if (!(a)) sx::debugbreak(__FILE__, __LINE__); } while (false)
#endif

#if SXASSERTDEFINED
	#define SXASSERT(b) do { if (!(b)) sx::debugbreak(__FILE__, __LINE__); } while (false)
#else
	#define SXASSERT(b) sxassert(b)
#endif

#if SXTESTDEFINED
	#define SXTEST(b) do { b; } while (false);
#else
	#define SXTEST(b)
#endif
