// created by configure.py
#pragma once
SXCORE

#ifdef NDEBUG
	#define sxassert(a)
#else
	#define sxassert(a) do { if (!(a)) sx::debugbreak(__FILE__, __LINE__); } while (false)
#endif
#define SXASSERTDEFINED 1
#if SXASSERTDEFINED
	#define SXASSERT(b) do { if (!(b)) sx::debugbreak(__FILE__, __LINE__); } while (false)
#else
	#define SXASSERT(b) sxassert(b)
#endif
#define SXSIGNATURE 1
#if _WIN32
	#if _WIN64
		#define SXSIMD 3
	#else
		#define SXSIMD 2
	#endif
#elif SXIOS
	#define SXSIMD 1
#elif __SSE__
	#define SXSIMD 3
#else
	#define SXSIMD 0
#endif
//#define SXCUSTOMSPINLOCK 1 // uses home made spinlock implementation.
//#define SXCUSTOMRECURSIVEMUTEXK 1 // uses home made recursive mutex implementation.
//#define SXSHAREDMUTEXBLOCKING 1
//#define SXCHECKSHAREDMUTEX (!defined(NDEBUG))
//#define SXCHECKNONRECURSIVEMUTEX (!defined(NDEBUG))
