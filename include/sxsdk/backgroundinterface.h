#pragma once

namespace sxsdk {
	class background_interface : public shade_interface {
	public:
	virtual void save (const char*const& in, void* aux = 0) = 0; // 0
	virtual void load (const char*const& from, void* aux = 0) = 0; // 1
	virtual void set_color_deprecated (enums::background_part e, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 2
	virtual sxsdk::rgb_class get_color_deprecated (enums::background_part e, void* aux = 0) = 0; // 3
	virtual void set_texture_deprecated (enums::background_part p, int i, enums::background_texture e, void* aux = 0) = 0; // 4
	virtual enums::background_texture get_texture_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 5
	virtual void set_mapping_deprecated (enums::background_part p, int i, float r, void* aux = 0) = 0; // 6
	virtual float get_mapping_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 7
	virtual void set_mapping_color_deprecated (enums::background_part p, int i, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 8
	virtual sxsdk::rgb_class get_mapping_color_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 9
	virtual void set_density_deprecated (enums::background_part p, int i, float r, void* aux = 0) = 0; // 10
	virtual float get_density_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 11
	virtual void set_size_x_deprecated (enums::background_part p, int i, float r, void* aux = 0) = 0; // 12
	virtual float get_size_x_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 13
	virtual void set_size_z_deprecated (enums::background_part p, int i, float r, void* aux = 0) = 0; // 14
	virtual float get_size_z_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 15
	virtual void set_horizontal_flip_deprecated (enums::background_part p, int i, bool b, void* aux = 0) = 0; // 16
	virtual bool get_horizontal_flip_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 17
	virtual void set_vertical_flip_deprecated (enums::background_part p, int i, bool b, void* aux = 0) = 0; // 18
	virtual bool get_vertical_flip_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 19
	virtual void set_swap_axes_deprecated (enums::background_part p, int i, bool b, void* aux = 0) = 0; // 20
	virtual bool get_swap_axes_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 21
	virtual void set_phase_deprecated (enums::background_part p, int i, float phase, void* aux = 0) = 0; // 22
	virtual float get_phase_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 23
	virtual int background_interface_test_1 ( void* aux =0 ) { return 1; } // 24
	virtual void set_image_deprecated (enums::background_part p, int i, sxsdk::image_interface* image, void* aux = 0) = 0; // 25
	virtual sxsdk::image_interface* get_image_interface_deprecated (enums::background_part p, int i, void* aux = 0) = 0; // 26
	virtual background_interface &set_lighting_intensity_factor (float lighting_intensity_factor_param, void * = 0) = 0; // 27
	virtual float get_lighting_intensity_factor (void * = 0) const = 0; // 28
	virtual background_layer_class& background_layer (int i, void* aux = 0) = 0; // 29
	virtual background_layer_class& append_background_layer (void* aux = 0) = 0; // 30
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 31
	virtual int get_active_layer (void * = 0) const = 0; // 32
	virtual background_interface &set_active_layer (int active_layer_param, void * = 0) = 0; // 33
	virtual sxsdk::rgb_class get_upper_base_color (void * = 0) const = 0; // 34
	virtual background_interface &set_upper_base_color (const sxsdk::rgb_class &upper_base_color_param, void * = 0) = 0; // 35
	virtual sxsdk::rgb_class get_lower_base_color (void * = 0) const = 0; // 36
	virtual background_interface &set_lower_base_color (const sxsdk::rgb_class &lower_base_color_param, void * = 0) = 0; // 37
	virtual int get_number_of_background_layers (void * = 0) const = 0; // 38
	virtual void move_up_background_layer (int go, int select = -1, void* aux = 0) = 0; // 39
	virtual void move_down_background_layer (int go, int select = -1, void* aux = 0) = 0; // 40
	};
}
