#pragma once
SXCORE
#include "Half/half.h"
//#include "Half/halfLimits.h"

namespace sx {
	typedef unsigned char		byte;
	typedef signed char			int8;
	typedef unsigned char		unsigned8;
	typedef short				int16;
	typedef unsigned short		unsigned16;
	typedef int					int32;
	typedef unsigned			unsigned32;
	typedef long long			int64;
	typedef unsigned long long	unsigned64;
	typedef half				float16;
	typedef float				float32;
	typedef double				float64;

	namespace image {
		/// \en blah \enden \ja イメージの合成モード \endja
		enum mix_mode {
			blend_mode,			///< \en blah \enden \ja 通常\endja
			alpha_blend_mode,	///< \en blah \enden \ja αブレンド\endja
			add_mode,			///< \en blah \enden \ja 加算\endja
			sub_mode,			///< \en blah \enden \ja 減算\endja
			mul_mode,			///< \en blah \enden \ja 乗算\endja
			max_mode,			///< \en blah \enden \ja 比較(明)\endja
			min_mode,			///< \en blah \enden \ja 比較(暗)\endja
			last_mix_mode		///< \en blah \enden \ja 未使用\endja
		};
	}
}
