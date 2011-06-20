#include "sx/core.cxx"
#include "./debug.hpp"

bool sx::debug::settings::debug = false;
bool sx::debug::settings::trace_functions = false;

int sx::debug_level = 0;

bool sx::check (void *p) {
	return true;
}
void sx::debugbreak (const char *file, int line) {
	std::cerr << "debugbreak " << file << " " << line << std::endl;
	#if SXIOS
		::abort();
	#elif SXMACOSX
		::Debugger();
		::abort();
	//#elif SXWINDOWS
	//	::DebugBreak(); for some reason DebugBreak() seems to destroy call stack information on 32-bit windows release build...
	#else
		*(char *)(0) = 0;
	#endif
}

namespace {
	class tracer_class {
	public:
		explicit tracer_class (const char *function_name);
		~tracer_class ();
	private:
		const char *const function_name;
	};
}
sx::debug::tracer_class::tracer_class (const char *function_name) : function_name(function_name) {
	if (sx::debug::settings::trace_functions) {
		std::cerr << ">>>> " << function_name << std::endl;
	}
}
sx::debug::tracer_class::~tracer_class () {
	if (sx::debug::settings::trace_functions) {
		std::cerr << "<<<< " << function_name << std::endl;
	}
}
