#pragma once
SXCORE
#include "sx/core/types.hpp"

namespace sx {
	inline bool little_endian () {
		#if __LITTLE_ENDIAN__
			return true;
		#elif __BIG_ENDIAN__
			return false;
		#else
			unsigned u = 0x01234567;
			return *(unsigned char *)&u == 0x67;
		#endif
	}
	inline bool big_endian () {
		#if __BIG_ENDIAN__
			return true;
		#elif __LITTLE_ENDIAN__
			return false;
		#else
			unsigned u = 0x01234567;
			return *(unsigned char *)&u == 0x01;
		#endif
	}
	namespace imp {
		template<int N> inline void revert_endian (void *p) {
			char b[N];
			for (int i = 0; i < N; ++i) b[N-1-i] = ((char *)(p))[i];
			memcpy(p, b, N);
		}
	}
	inline void revert_endian (sx::unsigned16 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	inline void revert_endian (sx::int16 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	inline void revert_endian (sx::unsigned32 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	inline void revert_endian (sx::int32 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	inline void revert_endian (sx::unsigned64 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	inline void revert_endian (sx::int64 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	inline void revert_endian (sx::float32 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	inline void revert_endian (sx::float64 &i) {
		sx::imp::revert_endian<sizeof(i)>(&i);
	}
	template<typename T> inline void to_little_endian (T &t) {
		if (big_endian()) revert_endian(t);
	}
	template<typename T> inline void to_big_endian (T &t) {
		if (little_endian()) revert_endian(t);
	}
	template<typename T> inline void from_little_endian (T &t) {
		if (big_endian()) revert_endian(t);
	}
	template<typename T> inline void from_big_endian (T &t) {
		if (little_endian()) revert_endian(t);
	}
	
	namespace core {
		namespace unittest {
			inline void test_endian () {
				#if __BIG_ENDIAN__
					SXUNITTEST(sx::big_endian());
				#endif
				#if __LITTLE_ENDIAN__
					SXUNITTEST(sx::little_endian());
				#endif
				{	sx::unsigned16 i = 0x0123;
					sx::revert_endian(i);
					SXUNITTEST(i == 0x2301);
				}
				{	sx::int16 i = 0x0123;
					sx::revert_endian(i);
					SXUNITTEST(i == 0x2301);
				}
				{	sx::unsigned32 i = 0x01234567;
					sx::revert_endian(i);
					SXUNITTEST(i == 0x67452301);
				}
				{	sx::int32 i = 0x01234567;
					sx::revert_endian(i);
					SXUNITTEST(i == 0x67452301);
				}
				{	sx::unsigned64 i = 0x0123456789abcdefLL;
					sx::revert_endian(i);
					SXUNITTEST(i == 0xefcdab8967452301LL);
				}
				{	sx::int64 i = 0x0123456789abcdefLL;
					sx::revert_endian(i);
					SXUNITTEST(i == 0xefcdab8967452301LL);
				}
			}
		}
	}
}
