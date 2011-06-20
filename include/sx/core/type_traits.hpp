#pragma once
SXCORE
#include "boost/type_traits.hpp"

namespace sx {
	template <typename T> struct is_movable : public boost::is_fundamental<T> { };
}
