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
		BOOST_STATIC_ASSERT((boost::is_base_of<U, T>::value));
		SXASSERT(!u || u->check_signature());
		const T *const t = dynamic_cast<const T *>(u);
		SXASSERT(!t || t->check_signature());
		return t;
	}
	template<typename T, typename U> inline T *cast (U *u) {
		BOOST_STATIC_ASSERT((boost::is_base_of<U, T>::value));
		SXASSERT(!u || u->check_signature());
		T *const t = dynamic_cast<T *>(u);
		SXASSERT(!t || t->check_signature());
		return t;
	}

	template<typename T, typename U> inline const T &cast (const U &u) {
		BOOST_STATIC_ASSERT((boost::is_base_of<U, T>::value));
		SXASSERT(u.check_signature());
		const T *const t = dynamic_cast<const T *>(&u);
		SXASSERT(t);
		SXASSERT(t->check_signature());
		return *t;
	}
	template<typename T, typename U> inline T &cast (U &u) {
		BOOST_STATIC_ASSERT((boost::is_base_of<U, T>::value));
		SXASSERT(u.check_signature());
		T *const t = dynamic_cast<T *>(&u);
		SXASSERT(t);
		SXASSERT(t->check_signature());
		return *t;
	}
}
