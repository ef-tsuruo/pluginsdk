#pragma once

namespace sxsdk {
	class critical_section_interface : public unknown_interface {
	public:
	virtual void enter (void * aux = 0) = 0; // 0
	virtual void leave (void * aux = 0) = 0; // 1
	};
}
