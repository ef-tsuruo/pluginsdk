#pragma once

namespace sxsdk {
	class speed_interface : public shade_interface {
	public:
	virtual sxsdk::expression_interface* get_expression_interface (void * = 0) const = 0; // 0
	virtual void load (sxsdk::loader_interface* i, sxsdk::shape_class* starting_shape = 0, void* aux = 0) = 0; // 1
	virtual int get_speed_tags (sxsdk::shape_class& shape, int* tags = 0, void* aux = 0) = 0; // 2
	virtual const char* get_vendor_id_history (void * = 0) const = 0; // 3
	};
}
