#include "sxsdk/shadebuildnumber.h"
#include "sxsdk/com.h"

unknown_interface::unknown_interface () : ref(0) {
}

unknown_interface:: ~unknown_interface () {
}

ULONG __stdcall unknown_interface::AddRef () {
	return ++ref;
}

ULONG __stdcall unknown_interface::Release () {
	if (--ref == 0) {
		delete this;
		return 0;
	}
	return ref;
}
int unknown_interface::get_shade_build_number () const {
	return SHADE_BUILD_NUMBER;
}
