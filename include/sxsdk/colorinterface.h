#pragma once

namespace sxsdk {
	class color_interface : public shade_interface {
	public:
	virtual sxsdk::rgb_class get_color (void * = 0) const = 0; // 0
	virtual color_interface &set_color (const sxsdk::rgb_class &color_param, void * = 0) = 0; // 1
	virtual int color_interface_test_1 ( void* aux =0 ) { return 1; } // 2
	};
}
