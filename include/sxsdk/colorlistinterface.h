#pragma once

namespace sxsdk {
	class color_list_interface : public shade_interface {
	public:
	virtual int get_number_of_items (int i, void* aux = 0) = 0; // 0
	virtual sxsdk::rgb_class get_color (int i, int j, void* aux = 0) = 0; // 1
	virtual void set_color (int i, int j, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 2
	virtual void append_color (int i, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 3
	virtual int color_list_interface_test_1 ( void* aux =0 ) { return 1; } // 4
	};
}
