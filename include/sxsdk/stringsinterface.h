#pragma once

namespace sxsdk {
	class strings_interface : public shade_interface {
	public:
	virtual const char* get_string (int at, void* aux = 0) = 0; // 0
	};
}
