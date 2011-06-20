#pragma once
SXCORE
#include "sx/core/debug.hpp"

namespace sx {
	template<unsigned SIGNATURE> class signature {
	#if SXSIGNATURE
		public:
			explicit signature () : _signature(SIGNATURE) { }
			~signature () { _signature = 0; }
			bool check_signature () const { SXASSERT(_signature == SIGNATURE); return true; }
			bool check_invariant () const { SXASSERT(this); check_signature(); return true; }
		private:
			unsigned _signature;
	#else
		public:
			bool check_signature () const { return true; }
			bool check_invariant () const { return true; }
	#endif
	};
}
