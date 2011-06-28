#pragma once
SXCORE
#include "sx/core/debug.hpp"

namespace sx {
	template<unsigned SIGNATURE=0xB13919F7> class signature {
	#if SXSIGNATURE
		public:
			explicit signature () : _signature(SIGNATURE) {
				SXTEST(sx::check_invariant(*this));
			}
			~signature () {
				SXTEST(sx::check_invariant(*this));
				_signature = 0x0;
			}
			void check_invariant () const {
				SXASSERT(bool(this));
				check_signature();
			}
			void check_signature () const {
				SXASSERT(_signature == SIGNATURE);
			}
		private:
			unsigned _signature;
	#else
		public:
			void check_invariant () const { }
			void check_signature () const { }
	#endif
	};
	
}
