#pragma once

namespace sxsdk {
	class image_layer_interface : public shade_interface {
	public:
	virtual sxsdk::image_interface* get_image_interface (void * = 0) const = 0; // 0
	virtual image_layer_interface &set_name (const char* name_param, void * = 0) = 0; // 1
	virtual const char* get_name (void * = 0) const = 0; // 2
	virtual image_layer_interface &set_id_name (const char* id_name_param, void * = 0) = 0; // 3
	virtual const char* get_id_name (void * = 0) const = 0; // 4
	virtual void set_channel_name (int index, const char* name, void* aux = 0) = 0; // 5
	virtual const char* get_channel_name (int index, void* aux = 0) const = 0; // 6
	virtual int get_number_of_channels (void * = 0) const = 0; // 7
	virtual image_layer_interface &set_pixel_depth (int pixel_depth_param, void * = 0) = 0; // 8
	virtual int get_pixel_depth (void * = 0) const = 0; // 9
	virtual image_layer_interface &set_mix_mode (sx::image::mix_mode mix_mode_param, void * = 0) = 0; // 10
	virtual sx::image::mix_mode get_mix_mode (void * = 0) const = 0; // 11
	virtual image_layer_interface &set_maximum_value (sxsdk::rgba_class maximum_value_param, void * = 0) = 0; // 12
	virtual sxsdk::rgba_class get_maximum_value (void * = 0) const = 0; // 13
	virtual image_layer_interface &set_minimum_value (sxsdk::rgba_class minimum_value_param, void * = 0) = 0; // 14
	virtual sxsdk::rgba_class get_minimum_value (void * = 0) const = 0; // 15
	};
}
