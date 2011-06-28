#include "sx/core.cxx"
#include "./debug.hpp"

bool sx::debug::settings::debug = false;

int sx::debug_level = 0;

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

sx::debug::tracer_class::tracer_class (const char *const name) : _name(name) {
	std::cerr << ">>>> " << _name << std::endl;
}
sx::debug::tracer_class::~tracer_class () {
	try { std::cerr << "<<<< " << _name << std::endl; } catch (...) { }
}
