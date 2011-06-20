#pragma once

namespace sxsdk {
	class camera_interface : public shade_interface {
	public:
	virtual void save (const char*const& path, void* aux = 0) = 0; // 0
	virtual void load (const char*const& path, void* aux = 0) = 0; // 1
	virtual int get_number_of_views (void* aux = 0) = 0; // 2
	virtual void set_eye (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 3
	virtual sxsdk::vec3 get_eye (int i, void* aux = 0) = 0; // 4
	virtual void set_target (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 5
	virtual sxsdk::vec3 get_target (int i, void* aux = 0) = 0; // 6
	virtual void set_zoom (int i, float zoom, void* aux = 0) = 0; // 7
	virtual float get_zoom (int i, void* aux = 0) = 0; // 8
	virtual int camera_interface_dummy9(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 9
	virtual int camera_interface_dummy10(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 10
	virtual void set_distant_camera (int i, bool b, void* aux = 0) = 0; // 11
	virtual bool get_distant_camera (int i, void* aux = 0) = 0; // 12
	virtual int camera_interface_dummy13(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 13
	virtual int camera_interface_dummy14(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 14
	virtual int camera_interface_dummy15(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 15
	virtual void set_bank (int i, float bank, void* aux = 0) = 0; // 16
	virtual float get_bank (int i, void* aux = 0) = 0; // 17
	virtual void set_focus (int i, float focus, void* aux = 0) = 0; // 18
	virtual float get_focus (int i, void* aux = 0) = 0; // 19
	virtual void set_focus_point (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 20
	virtual sxsdk::vec3 get_focus_point (int i, void* aux = 0) = 0; // 21
	virtual void set_shift (int i, float shift, void* aux = 0) = 0; // 22
		void set_horizontal_shift (int i, float shift, void* aux = 0) { set_shift(i, shift); }
	virtual float get_shift (int i, void* aux = 0) = 0; // 23
		float get_horizontal_shift (int i, void* aux = 0) { return get_shift(i); }
	virtual void set_rise (int i, float rise, void* aux = 0) = 0; // 24
		void set_vertical_shift (int i, float rise, void* aux = 0) { set_rise(i, rise); }
	virtual float get_rise (int i, void* aux = 0) = 0; // 25
		float get_vertical_shift (int i, void* aux = 0) { return get_rise(i); }
	virtual int camera_interface_dummy26(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 26
	virtual bool get_top_view_obsolete (int i, void* aux = 0) = 0; // 27
	virtual int camera_interface_dummy28(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 28
	virtual int camera_interface_dummy29(void *) { assert(false); throw "invalid interface camera_interface"; return 0; } // 29
	virtual void memorize_as_line_object (void* aux = 0) = 0; // 30
	virtual void memorize_as_spotlight (void* aux = 0) = 0; // 31
	virtual void recall_from_object_obsolete (shape_interface* shape, void* aux = 0) = 0; // 32
	virtual sxsdk::stream_interface* create_attribute_stream_interface (int i, int attribute_id, void* aux = 0) = 0; // 33
		sxsdk::stream_interface* create_attribute_stream (int i, int attribute_id, void* aux = 0) { return create_attribute_stream_interface(i, attribute_id); }
	virtual sxsdk::stream_interface* get_attribute_stream_interface (int i, int attribute_id, void* aux = 0) = 0; // 34
		sxsdk::stream_interface* get_attribute_stream (int i, int attribute_id, void* aux = 0) { return get_attribute_stream_interface(i, attribute_id); }
	virtual sxsdk::mat4 get_world_to_view_matrix (int i, void* aux = 0) = 0; // 35
	virtual sxsdk::mat4 get_world_to_perspective_matrix (int i, void* aux = 0) = 0; // 36
	virtual bool delete_attribute (int i, int attribute_id, void* aux = 0) = 0; // 37
	virtual void restore_from_object (sxsdk::shape_class& shape, void* aux = 0) = 0; // 38
		void recall_from_object (sxsdk::shape_class& shape, void* aux = 0) { restore_from_object(shape); }
	virtual void restore_from_default (void* aux = 0) = 0; // 39
	virtual void back (void* aux = 0) = 0; // 40
	virtual void forward (void* aux = 0) = 0; // 41
	virtual camera_interface &set_correction (float correction_param, void * = 0) = 0; // 42
	virtual float get_correction (void * = 0) const = 0; // 43
	virtual camera_interface &set_film_shift (float film_shift_param, void * = 0) = 0; // 44
	virtual float get_film_shift (void * = 0) const = 0; // 45
	virtual camera_interface &set_film_rise (float film_rise_param, void * = 0) = 0; // 46
	virtual float get_film_rise (void * = 0) const = 0; // 47
	virtual camera_interface &set_film_swing (float film_swing_param, void * = 0) = 0; // 48
	virtual float get_film_swing (void * = 0) const = 0; // 49
	virtual camera_interface &set_film_tilt (float film_tilt_param, void * = 0) = 0; // 50
	virtual float get_film_tilt (void * = 0) const = 0; // 51
	virtual camera_interface &set_lens_swing (float lens_swing_param, void * = 0) = 0; // 52
	virtual float get_lens_swing (void * = 0) const = 0; // 53
	virtual camera_interface &set_lens_tilt (float lens_tilt_param, void * = 0) = 0; // 54
	virtual float get_lens_tilt (void * = 0) const = 0; // 55
	virtual camera_interface &set_scale (float scale_param, void * = 0) = 0; // 56
	virtual float get_scale (void * = 0) const = 0; // 57
	virtual camera_interface &set_current_camera (int current_camera_param, void * = 0) = 0; // 58
	virtual int get_current_camera (void * = 0) const = 0; // 59
	virtual void remove_metacamera (void* aux = 0) = 0; // 60
	virtual void memorize_as_camera (void* aux = 0) = 0; // 61
	virtual sxsdk::enums::camera_mode get_camera_mode (void * = 0) const = 0; // 62
	virtual camera_interface &set_camera_mode (sxsdk::enums::camera_mode camera_mode_param, void * = 0) = 0; // 63
	virtual enums::master_camera_mode get_master_camera_mode (void * = 0) const = 0; // 64
	virtual camera_interface &set_master_camera_mode (enums::master_camera_mode master_camera_mode_param, void * = 0) = 0; // 65
	virtual part_interface* get_camera_object_interface (void* aux = 0) = 0; // 66
	virtual part_class* get_camera_object (void * = 0) const = 0; // 67
	virtual int get_number_of_metacameras (void * = 0) const = 0; // 68
	virtual int test_1 ( void* aux =0 ) { return 1; } // 69
	virtual void memorize_as_metacamera (void* aux = 0) = 0; // 70
	};
}
