#pragma once

namespace sxsdk {
	class shader_node_class : public sx::signature<0xB044FD83> {
	public:
		virtual ~shader_node_class () { }
		VTABLE_PADDING
	virtual int get_patterns (int* patterns, void* aux = 0) const = 0; // 0
	virtual shader_node_class &set_pattern (int pattern_param, void * = 0) = 0; // 1
	virtual int get_pattern (void * = 0) const = 0; // 2
	virtual int get_types (int* types, void* aux = 0) const = 0; // 3
	virtual shader_node_class &set_type (int type_param, void * = 0) = 0; // 4
	virtual int get_type (void * = 0) const = 0; // 5
	virtual shader_node_class &set_transformation (const sxsdk::mat4 &transformation_param, void * = 0) = 0; // 6
	virtual sxsdk::mat4 get_transformation (void * = 0) const = 0; // 7
	virtual shader_node_class &set_origin (const sxsdk::vec3 &origin_param, void * = 0) = 0; // 8
	virtual sxsdk::vec3 get_origin (void * = 0) const = 0; // 9
	virtual shader_node_class &set_weight (float weight_param, void * = 0) = 0; // 10
	virtual float get_weight (void * = 0) const = 0; // 11
	virtual shader_node_class &set_mapping_color (const sxsdk::rgb_class &mapping_color_param, void * = 0) = 0; // 12
	virtual sxsdk::rgb_class get_mapping_color (void * = 0) const = 0; // 13
	virtual shader_node_class &set_mapping_size (float mapping_size_param, void * = 0) = 0; // 14
	virtual float get_mapping_size (void * = 0) const = 0; // 15
	virtual shader_node_class &set_turbulence (float turbulence_param, void * = 0) = 0; // 16
	virtual float get_turbulence (void * = 0) const = 0; // 17
	virtual shader_node_class &set_softness (float softness_param, void * = 0) = 0; // 18
	virtual float get_softness (void * = 0) const = 0; // 19
	virtual shader_node_class &set_horizontal_flip (bool horizontal_flip_param, void * = 0) = 0; // 20
	virtual bool get_horizontal_flip (void * = 0) const = 0; // 21
	virtual shader_node_class &set_vertical_flip (bool vertical_flip_param, void * = 0) = 0; // 22
	virtual bool get_vertical_flip (void * = 0) const = 0; // 23
	virtual shader_node_class &set_swap_axes (bool swap_axes_param, void * = 0) = 0; // 24
	virtual bool get_swap_axes (void * = 0) const = 0; // 25
	virtual shader_node_class &set_flip_color (bool flip_color_param, void * = 0) = 0; // 26
	virtual bool get_flip_color (void * = 0) const = 0; // 27
	virtual shader_node_class &set_blur (bool blur_param, void * = 0) = 0; // 28
	virtual bool get_blur (void * = 0) const = 0; // 29
	virtual int get_projections (int* projections, void* aux = 0) = 0; // 30
	virtual shader_node_class &set_projection (int projection_param, void * = 0) = 0; // 31
	virtual int get_projection (void * = 0) const = 0; // 32
	virtual shader_node_class &set_repetition_x (int repetition_x_param, void * = 0) = 0; // 33
	virtual int get_repetition_x (void * = 0) const = 0; // 34
	virtual shader_node_class &set_repetition_y (int repetition_y_param, void * = 0) = 0; // 35
	virtual int get_repetition_y (void * = 0) const = 0; // 36
	virtual shader_node_class &set_image_interface (sxsdk::image_interface* image_interface_param, void * = 0) = 0; // 37
	virtual sxsdk::image_interface* get_image_interface (void * = 0) const = 0; // 38
	virtual shader_node_class &set_phase (float phase_param, void * = 0) = 0; // 39
	virtual float get_phase (void * = 0) const = 0; // 40
	virtual shader_node_class &set_area (const sx::rectangle_class &area_param, void * = 0) = 0; // 41
	virtual sx::rectangle_class get_area (void * = 0) const = 0; // 42
	virtual shader_node_class &set_blend_mode (int blend_mode_param, void * = 0) = 0; // 43
	virtual int get_blend_mode (void * = 0) const = 0; // 44
	virtual sxsdk::stream_interface* get_attribute_stream_interface (int id, void* aux = 0) = 0; // 45
	virtual sxsdk::stream_interface* create_attribute_stream_interface (int id, void* aux = 0) = 0; // 46
	virtual bool delete_attribute (int id, void* aux = 0) = 0; // 47
	virtual const char* get_pattern_name (void * = 0) const = 0; // 48
	virtual const char* get_exception_string () const = 0; // 49
	virtual shader_node_class &set_premultiplied (bool premultiplied_param, void * = 0) = 0; // 50
	virtual bool get_premultiplied (void * = 0) const = 0; // 51
	virtual void load_image (const char* path, void* aux = 0) = 0; // 52
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 53
	virtual sxsdk::stream_interface* get_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) const = 0; // 54
	virtual sxsdk::stream_interface* create_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 55
	virtual bool delete_attribute_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 56
	virtual shader_node_class &set_pattern_uuid (const sx::uuid_class &pattern_uuid_param, void * = 0) = 0; // 57
	virtual sx::uuid_class get_pattern_uuid (void * = 0) const = 0; // 58
	virtual shader_node_class &set_parameter_mapping (bool parameter_mapping_param, void * = 0) = 0; // 59
	virtual bool get_parameter_mapping (void * = 0) const = 0; // 60
	virtual shader_node_class &set_bump_height (float bump_height_param, void * = 0) = 0; // 61
	virtual float get_bump_height (void * = 0) const = 0; // 62
	virtual int get_shader_nodes (sxsdk::shader_node_class* list[], void * = 0) const = 0; // 63
	virtual shader_node_class &set_uv_mapping (int uv_mapping_param, void * = 0) = 0; // 64
	virtual int get_uv_mapping (void * = 0) const = 0; // 65
	};
}
