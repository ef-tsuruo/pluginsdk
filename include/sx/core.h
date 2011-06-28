#pragma once

#define SX64 (__LP64__ || _WIN64)

#ifdef _WIN32
	#ifndef _WINDOWS_
		#include <Windows.h>
	#endif
	#include <Gdiplus.h> // Gdiplus.h uses "min" and "max" macro symbol which shall be undefined to avoid conflict with std::max.
	#undef min
	#undef max
#endif
	
#undef SXQUICKTIME
#define SXQUICKTIME 0

#ifdef _WIN64
	#ifndef SXWIN64
		#define SXWIN64 1
	#endif
#endif

#if SXMACOSX
	#if __LP64__
		#define SXQUICKTIME 0
	#else
		#include <Carbon/Carbon.h>
	#endif
	#ifdef __OBJC__
		#import <Cocoa/Cocoa.h>
	#endif
#endif

#include <assert.h>

#define SXUNIMPLEMENTED //((void)0)

#if __cplusplus
	// std headers
	#include <iostream>
	#include <stack>
	#include <list>
	#include <map>
	#include <queue>
	#include <set>
	#include <vector>
	#include <iostream>
	#include <sstream>
	#include <cmath>
	#include <string>
	#include <cctype>
	#include <algorithm>
	#include <limits>
	#include <memory>
	#include <functional>
	#include <iomanip>

	// tr1 headers
	#include <boost/tr1/array.hpp>
	#include <boost/tr1/functional.hpp>
	#include <boost/tr1/memory.hpp>
	#include <boost/tr1/tuple.hpp>
	#include <boost/tr1/unordered_map.hpp>
	#include <boost/tr1/type_traits.hpp>
	namespace std {
		using namespace tr1;
	}

	#include "boost/any.hpp"
	#include "boost/version.hpp"
	#include "boost/static_assert.hpp"
	BOOST_STATIC_ASSERT(104200 <= BOOST_VERSION);

	// boost headers
	#include <boost/noncopyable.hpp>
	#include "boost/foreach.hpp"
	#define foreach BOOST_FOREACH
	#ifndef __GNUG__
		#include "boost/typeof/typeof.hpp"
		#define typeof BOOST_TYPEOF
	#endif

	#ifdef __GNUG__
		// workaround for broken warning supression.
		#define for if (false) { } else for
	#endif
	#if _MSC_VER
		BOOST_STATIC_ASSERT(_SECURE_SCL == 0);
	#endif

	#if (_MSC_VER < 1600)
		#include "sx/core/uniqueptr.hpp"
		namespace std {
			using boost::unique_ptr;
		}
		const class {
		public:
			template<class T> operator T*() const { return 0; }
			template<class C, class T> operator T C::*() const { return 0; }
		private:
		  void operator&() const;
		} nullptr = {};
	#endif

	#include "sx/core/config.hpp" // must be included early
	//#include "sx/core/assert.hpp"
	#include "sx/core/signature.hpp"
	#include "sx/core/types.hpp"
	#include "sx/core/adl.hpp"
	#include "sx/core/cast.hpp"
	#include "sx/core/property.hpp"
	#include "sx/core/relations.hpp"
	#include "sx/core/vectorutility.hpp"
	#include "sx/core/debug.hpp"

#endif
