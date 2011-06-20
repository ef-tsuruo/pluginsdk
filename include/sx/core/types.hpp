#pragma once
SXCORE
#include "Half/half.h"

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
		/// \en blah \enden \ja ÉCÉÅÅ[ÉWÇÃçáê¨ÉÇÅ[Éh \endja
		enum mix_mode {
			blend_mode,			///< \en blah \enden \ja í èÌ\endja
			alpha_blend_mode,	///< \en blah \enden \ja ÉøÉuÉåÉìÉh\endja
			add_mode,			///< \en blah \enden \ja â¡éZ\endja
			sub_mode,			///< \en blah \enden \ja å∏éZ\endja
			mul_mode,			///< \en blah \enden \ja èÊéZ\endja
			max_mode,			///< \en blah \enden \ja î‰är(ñæ)\endja
			min_mode,			///< \en blah \enden \ja î‰är(à√)\endja
			last_mix_mode		///< \en blah \enden \ja ñ¢égóp\endja
		};
	}
}
