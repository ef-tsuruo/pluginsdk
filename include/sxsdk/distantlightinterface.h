#pragma once

namespace sxsdk {
	class distant_light_interface : public shade_interface {
	public:
	virtual void save (const char*const& in, void* aux = 0) = 0; // 0
	virtual void load (const char*const& from, void* aux = 0) = 0; // 1
	virtual int get_number_of_lights (void * = 0) const = 0; // 2
	virtual void set_intensity_deprecated (int , float , void*  = 0) = 0; // 3
	virtual float get_intensity_deprecated (int , void*  = 0) = 0; // 4
	virtual void set_ambient_deprecated (int , float , void*  = 0) = 0; // 5
	virtual float get_ambient_deprecated (int , void*  = 0) = 0; // 6
	virtual void set_color_deprecated (int i, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 7
	virtual sxsdk::rgb_class get_color_deprecated (int , void*  = 0) = 0; // 8
	virtual void set_direction_deprecated (int i, const sxsdk::vec3& direction, void* aux = 0) = 0; // 9
	virtual sxsdk::vec3 get_direction_deprecated (int , void*  = 0) = 0; // 10
	virtual void set_shadow_deprecated (int , float , void*  = 0) = 0; // 11
	virtual float get_shadow_deprecated (int , void*  = 0) = 0; // 12
	virtual void set_softness_deprecated (int , float , void*  = 0) = 0; // 13
	virtual float get_softness_deprecated (int , void*  = 0) = 0; // 14
	virtual void set_glare_deprecated (int , float , void*  = 0) = 0; // 15
	virtual float get_glare_deprecated (int , void*  = 0) = 0; // 16
	virtual void set_size_deprecated (int , float , void*  = 0) = 0; // 17
	virtual float get_size_deprecated (int , void*  = 0) = 0; // 18
	virtual void set_specular_deprecated (int , float , void*  = 0) = 0; // 19
	virtual float get_specular_deprecated (int , void*  = 0) = 0; // 20
	virtual void set_diffuse_deprecated (int , float , void*  = 0) = 0; // 21
	virtual float get_diffuse_deprecated (int , void*  = 0) = 0; // 22
	virtual sxsdk::stream_interface* create_attribute_stream_interface_deprecated (int i, int attribute_id, void* aux = 0) = 0; // 23
		sxsdk::stream_interface* create_attribute_stream (int i, int attribute_id, void* aux = 0) { return create_attribute_stream_interface_deprecated(i, attribute_id); }
	virtual sxsdk::stream_interface* get_attribute_stream_interface_deprecated (int i, int attribute_id, void* aux = 0) = 0; // 24
		sxsdk::stream_interface* get_attribute_stream (int i, int attribute_id, void* aux = 0) { return get_attribute_stream_interface_deprecated(i, attribute_id); }
	virtual bool delete_attribute_deprecated (int i, int attribute_id, void* aux = 0) = 0; // 25
	virtual distant_light_interface &set_sky_light_color (const sxsdk::rgb_class &sky_light_color_param, void * = 0) = 0; // 26
	virtual sxsdk::rgb_class get_sky_light_color (void * = 0) const = 0; // 27
	virtual distant_light_interface &set_sky_light (float sky_light_param, void * = 0) = 0; // 28
	virtual float get_sky_light (void * = 0) const = 0; // 29
	virtual void set_has_shadow_map_size_deprecated (int , bool , void*  = 0) = 0; // 30
	virtual bool get_has_shadow_map_size_deprecated (int , void*  = 0) = 0; // 31
	virtual void set_shadow_map_size_deprecated (int , int , void*  = 0) = 0; // 32
	virtual int get_shadow_map_size_deprecated (int , void*  = 0) = 0; // 33
	virtual void set_has_shadow_map_bias_deprecated (int , bool , void*  = 0) = 0; // 34
	virtual bool get_has_shadow_map_bias_deprecated (int , void*  = 0) = 0; // 35
	virtual void set_shadow_map_bias_deprecated (int , float , void*  = 0) = 0; // 36
	virtual float get_shadow_map_bias_deprecated (int , void*  = 0) = 0; // 37
	virtual void set_has_shadow_map_blur_deprecated (int , bool , void*  = 0) = 0; // 38
	virtual bool get_has_shadow_map_blur_deprecated (int , void*  = 0) = 0; // 39
	virtual void set_shadow_map_blur_deprecated (int , float , void*  = 0) = 0; // 40
	virtual float get_shadow_map_blur_deprecated (int , void*  = 0) = 0; // 41
	virtual void set_shadow_type_deprecated (int , sxsdk::enums::shadow_type , void*  = 0) = 0; // 42
	virtual sxsdk::enums::shadow_type get_shadow_type_deprecated (int , void*  = 0) = 0; // 43
	virtual int distant_light_interface_test_1 ( void* aux =0 ) { return 1; } // 44
	virtual distant_light_item_class& distant_light_item (int i, void* aux = 0) = 0; // 45
	virtual void append_light_item (void* aux = 0) = 0; // 46
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 47
	virtual int get_active_item (void * = 0) const = 0; // 48
	virtual distant_light_interface &set_active_item (int active_item_param, void * = 0) = 0; // 49
	virtual void remove_light_item (int i, void* aux = 0) = 0; // 50
	};
}
