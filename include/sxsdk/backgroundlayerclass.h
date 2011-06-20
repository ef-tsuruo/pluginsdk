#pragma once

namespace sxsdk {
	class background_layer_class {
	public:
		virtual ~background_layer_class () { }
		VTABLE_PADDING
	virtual background_layer_class &set_target (int target_param, void * = 0) = 0; // 0
	virtual int get_target (void * = 0) const = 0; // 1
	virtual background_layer_class &set_texture (int texture_param, void * = 0) = 0; // 2
	virtual int get_texture (void * = 0) const = 0; // 3
	virtual background_layer_class &set_mapping_color (const sxsdk::rgb_class &mapping_color_param, void * = 0) = 0; // 4
	virtual sxsdk::rgb_class get_mapping_color (void * = 0) const = 0; // 5
	virtual background_layer_class &set_image_interface (sxsdk::image_interface* image_interface_param, void * = 0) = 0; // 6
	virtual sxsdk::image_interface* get_image_interface (void * = 0) const = 0; // 7
	virtual background_layer_class &set_area (const sx::rectangle_class &area_param, void * = 0) = 0; // 8
	virtual sx::rectangle_class get_area (void * = 0) const = 0; // 9
	virtual background_layer_class &set_horizontal_flip (bool horizontal_flip_param, void * = 0) = 0; // 10
	virtual bool get_horizontal_flip (void * = 0) const = 0; // 11
	virtual background_layer_class &set_vertical_flip (bool vertical_flip_param, void * = 0) = 0; // 12
	virtual bool get_vertical_flip (void * = 0) const = 0; // 13
	virtual background_layer_class &set_swap_axes (bool swap_axes_param, void * = 0) = 0; // 14
	virtual bool get_swap_axes (void * = 0) const = 0; // 15
	virtual background_layer_class &set_weight (float weight_param, void * = 0) = 0; // 16
	virtual float get_weight (void * = 0) const = 0; // 17
	virtual background_layer_class &set_density (float density_param, void * = 0) = 0; // 18
	virtual float get_density (void * = 0) const = 0; // 19
	virtual background_layer_class &set_mapping_size (float mapping_size_param, void * = 0) = 0; // 20
	virtual float get_mapping_size (void * = 0) const = 0; // 21
	virtual background_layer_class &set_anisotropic (float anisotropic_param, void * = 0) = 0; // 22
	virtual float get_anisotropic (void * = 0) const = 0; // 23
	virtual background_layer_class &set_phase (float phase_param, void * = 0) = 0; // 24
	virtual float get_phase (void * = 0) const = 0; // 25
	virtual background_layer_class &set_blend_mode (int blend_mode_param, void * = 0) = 0; // 26
	virtual int get_blend_mode (void * = 0) const = 0; // 27
	virtual background_layer_class &set_premultiplied (bool premultiplied_param, void * = 0) = 0; // 28
	virtual bool get_premultiplied (void * = 0) const = 0; // 29
	virtual background_layer_class &set_projection (int projection_param, void * = 0) = 0; // 30
	virtual int get_projection (void * = 0) const = 0; // 31
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 32
	virtual background_layer_class &set_orientation (float orientation_param, void * = 0) = 0; // 33
	virtual float get_orientation (void * = 0) const = 0; // 34
	};
}
