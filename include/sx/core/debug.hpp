#pragma once
SXCORE

namespace sx {
	namespace debug {
		namespace settings {
			extern bool debug;
			extern bool trace_functions;
		}
		
		class tracer_class {
		public:
			explicit tracer_class (const char *function_name);
			~tracer_class ();
		private:
			const char *const function_name;
		};
	}

	bool check (void *);
	static bool check (char) { return true; }
	static bool check (int) { return true; }
	static bool check (unsigned) { return true; }
	static bool check (float) { return true; }
	static bool check (double) { return true; }
	template<typename T> bool check (const T &t) {
		t.check_invariant();
		return true;
	}

	extern int debug_level;
	void debugbreak (const char *file, int line);
}

#if __GNUG__
	#define SXTRACE sx::debug::tracer_class sxdebugtracer(__PRETTY_FUNCTION__);
#else
	#define SXTRACE
#endif
