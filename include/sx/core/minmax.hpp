#pragma once
SXCORE
#include "types.hpp"

namespace sx {
	inline int8 min (int8 a, int8 b) { return std::min(a, b); }
	inline unsigned8 min (unsigned8 a, unsigned8 b) { return std::min(a, b); }
	inline int8 max (int8 a, int8 b) { return std::max(a, b); }
	inline unsigned8 max (unsigned8 a, unsigned8 b) { return std::max(a, b); }

	inline int16 min (int16 a, int16 b) { return std::min(a, b); }
	inline unsigned16 min (unsigned16 a, unsigned16 b) { return std::min(a, b); }
	inline int16 max (int16 a, int16 b) { return std::max(a, b); }
	inline unsigned16 max (unsigned16 a, unsigned16 b) { return std::max(a, b); }

	inline int32 min (int32 a, int32 b) { return std::min(a, b); }
	inline unsigned32 min (unsigned32 a, unsigned32 b) { return std::min(a, b); }
	inline int32 max (int32 a, int32 b) { return std::max(a, b); }
	inline unsigned32 max (unsigned32 a, unsigned32 b) { return std::max(a, b); }

	inline int64 min (int64 a, int64 b) { return std::min(a, b); }
	inline unsigned64 min (unsigned64 a, unsigned64 b) { return std::min(a, b); }
	inline int64 max (int64 a, int64 b) { return std::max(a, b); }
	inline unsigned64 max (unsigned64 a, unsigned64 b) { return std::max(a, b); }

	inline float16 min (float16 a, float16 b) { return std::min(a, b); }
	inline float16 max (float16 a, float16 b) { return std::max(a, b); }

	inline float32 min (float32 a, float32 b) { return std::min(a, b); }
	inline float32 max (float32 a, float32 b) { return std::max(a, b); }

	inline float64 min (float64 a, float64 b) { return std::min(a, b); }
	inline float64 max (float64 a, float64 b) { return std::max(a, b); }
	
	namespace core {
		namespace unittest {
			inline void test_minmax () {
			}
		}
	}
}
