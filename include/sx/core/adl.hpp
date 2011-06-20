#pragma once
SXCORE
// workaround for ADL (Koenig lookup) problem. see http://std.dkuug.dk/jtc1/sc22/wg21/docs/papers/2000/n1252.pdf

namespace sx {
	namespace adl {
		template<typename T> inline void swap (T &a, T &b) {
			using std::swap;
			swap(a, b);
		}
	}
}
