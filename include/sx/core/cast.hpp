#pragma once
SXCORE
#include "sx/core/debug.hpp"
#include "boost/type_traits.hpp"

namespace sx {
	// catchhing self cast
	template<typename T> const T *cast (const T *u);
	template<typename T> T *cast (T *u);
	template<typename T> const T &cast (const T &u);
	template<typename T> T &cast (T &u);

	template<typename T, typename U> inline const T *cast (const U *u) {
		if (u) SXTEST(sx::check_invariant(*u));
		const T *const t = dynamic_cast<const T *>(u);
		if (t) SXTEST(sx::check_invariant(*t));
		return t;
	}
	template<typename T, typename U> inline T *cast (U *u) {
		if (u) SXTEST(sx::check_invariant(*u));
		T *const t = dynamic_cast<T *>(u);
		if (t) SXTEST(sx::check_invariant(*t));
		return t;
	}

	template<typename T, typename U> inline const T &cast (const U &u) {
		SXTEST(sx::check_invariant(u));
		const T *const t = dynamic_cast<const T *>(&u);
		SXASSERT(t);
		SXTEST(sx::check_invariant(*t));
		return *t;
	}
	template<typename T, typename U> inline T &cast (U &u) {
		SXTEST(sx::check_invariant(u));
		T *const t = dynamic_cast<T *>(&u);
		SXASSERT(t);
		SXTEST(sx::check_invariant(*t));
		return *t;
	}
}
