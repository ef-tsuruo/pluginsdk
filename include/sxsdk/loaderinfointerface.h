#pragma once

namespace sxsdk {
	class loader_info_interface : public shade_interface {
	public:
	virtual bool is_same_as (shade_interface* i, void* aux = 0) = 0; // -1
	virtual int get_subdivision_level (void * = 0) const = 0; // 0
	virtual loader_info_interface &set_subdivision_level (int subdivision_level_param, void * = 0) = 0; // 1
	virtual sxsdk::shape_class* get_current_shape (void* aux = 0) = 0; // 2
	virtual const sxsdk::shape_class* get_surface_shape (void* aux = 0) = 0; // 3
	virtual sxsdk::proxy_shape_class* get_current_proxy_shape (void* aux = 0) = 0; // 4
	virtual sxsdk::proxy_shape_class* get_root_proxy_shape (void* aux = 0) = 0; // 5
	virtual sxsdk::mat4 get_transformation (void* aux = 0) = 0; // 6
	virtual sxsdk::mat4 get_inverse_texture_transformation (void* aux = 0) = 0; // 7
	virtual bool get_flip_face (void* aux = 0) = 0; // 8
	virtual bool get_flip_face_shade (void* aux = 0) = 0; // 9
	virtual bool get_active (void * = 0) const = 0; // 10
	virtual bool get_render (void* aux = 0) = 0; // 11
	virtual int get_rendering_flag (void * = 0) const = 0; // 12
	};
}

