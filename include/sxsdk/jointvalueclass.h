#pragma once

namespace sxsdk {
	class joint_value_class {
	public:
		virtual ~joint_value_class () { }
		VTABLE_PADDING
	virtual float get_scalar (void * = 0) const = 0; // 0
	};
}
