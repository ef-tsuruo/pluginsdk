#pragma once

namespace sxsdk {
	class motion_interface : public shade_interface {
	public:
	virtual void save (const char*const& in, void* aux = 0) = 0; // 0
	virtual void load (const char*const& from, void* aux = 0) = 0; // 1
	virtual motion_interface &set_current_joint_value (float current_joint_value_param, void * = 0) = 0; // 2
	virtual float get_current_joint_value (void * = 0) const = 0; // 3
	virtual void set_motion_point_value (int i, float f, void* aux = 0) = 0; // 4
		void set_sequence_joint_value (int i, float f, void* aux = 0) { set_motion_point_value(i, f); }
	virtual float get_motion_point_value (int i, void* aux = 0) = 0; // 5
		float get_sequence_joint_value (int i, void* aux = 0) { return get_motion_point_value(i); }
	virtual motion_interface &set_sequence (float sequence_param, void * = 0) = 0; // 6
	virtual float get_sequence (void * = 0) const = 0; // 7
	virtual void disable_sequence (void* aux = 0) = 0; // 8
	virtual void set_motion_point_corner (int i, bool b, void* aux = 0) = 0; // 9
		void set_corner (int i, bool b, void* aux = 0) { set_motion_point_corner(i, b); }
	virtual bool get_motion_point_corner (int i, void* aux = 0) = 0; // 10
		bool get_corner (int i, void* aux = 0) { return get_motion_point_corner(i); }
	virtual int get_number_of_motion_points (void* aux = 0) = 0; // 11
		int get_number_of_key_points (void* aux = 0) { return get_number_of_motion_points(); }
	virtual void select_motion_point (int i, void* aux = 0) = 0; // 12
		void select_key_point (int i, void* aux = 0) { select_motion_point(i); }
	virtual void select_all_motion_points (void* aux = 0) = 0; // 13
		void select_all_key_points (void* aux = 0) { select_all_motion_points(); }
	virtual void deselect_all_motion_points (void* aux = 0) = 0; // 14
		void deselect_all_key_points (void* aux = 0) { deselect_all_motion_points(); }
	virtual int get_first_selected_motion_point (void* aux = 0) = 0; // 15
		int get_first_selected_key_point (void* aux = 0) { return get_first_selected_motion_point(); }
	virtual int get_next_selected_motion_point (void* aux = 0) = 0; // 16
		int get_next_selected_key_point (void* aux = 0) { return get_next_selected_motion_point(); }
	virtual void set_motion_point_sequence (int i, float f, void* aux = 0) = 0; // 17
		void set_key_point_sequence_value (int i, float f, void* aux = 0) { set_motion_point_sequence(i, f); }
	virtual float get_motion_point_sequence (int i, void* aux = 0) = 0; // 18
		float get_key_point_sequence_value (int i, void* aux = 0) { return get_motion_point_sequence(i); }
	virtual void set_motion_point_slow_in (int i, float f, void* aux = 0) = 0; // 19
		void set_slow_in (int i, float f, void* aux = 0) { set_motion_point_slow_in(i, f); }
	virtual float get_motion_point_slow_in (int i, void* aux = 0) = 0; // 20
		float get_slow_in (int i, void* aux = 0) { return get_motion_point_slow_in(i); }
	virtual void set_motion_point_slow_out (int i, float f, void* aux = 0) = 0; // 21
		void set_slow_out (int i, float f, void* aux = 0) { set_motion_point_slow_out(i, f); }
	virtual float get_motion_point_slow_out (int i, void* aux = 0) = 0; // 22
		float get_slow_out (int i, void* aux = 0) { return get_motion_point_slow_out(i); }
	virtual motion_interface &set_repetition (int repetition_param, void * = 0) = 0; // 23
	virtual int get_repetition (void * = 0) const = 0; // 24
	virtual motion_interface &set_shift_obsoleted (bool shift_obsoleted_param, void * = 0) = 0; // 25
	virtual bool get_shift_obsoleted (void * = 0) const = 0; // 26
	virtual int create_motion_point (float at, void* aux = 0) = 0; // 27
		int create_key_point (float at, void* aux = 0) { return create_motion_point(at); }
	virtual void delete_motion_points (void* aux = 0) = 0; // 28
		void delete_key_points (void* aux = 0) { delete_motion_points(); }
	virtual void copy (void* aux = 0) = 0; // 29
	virtual void paste (void* aux = 0) = 0; // 30
	virtual float get_min_joint_value (void * = 0) const = 0; // 31
	virtual motion_interface &set_min_joint_value (float min_joint_value_param, void * = 0) = 0; // 32
	virtual float get_max_joint_value (void * = 0) const = 0; // 33
	virtual motion_interface &set_max_joint_value (float max_joint_value_param, void * = 0) = 0; // 34
	virtual void delete_motion_point (int i, void* aux = 0) = 0; // 35
		void delete_key_point (int i, void* aux = 0) { delete_motion_point(i); }
	virtual float get_default_min_joint_value (void * = 0) const = 0; // 36
	virtual motion_interface &set_default_min_joint_value (float default_min_joint_value_param, void * = 0) = 0; // 37
	virtual float get_default_max_joint_value (void * = 0) const = 0; // 38
	virtual motion_interface &set_default_max_joint_value (float default_max_joint_value_param, void * = 0) = 0; // 39
	virtual float get_default_joint_value (void * = 0) const = 0; // 40
	virtual motion_interface &set_default_joint_value (float default_joint_value_param, void * = 0) = 0; // 41
	virtual motion_interface &set_current_joint_rotation (const sxsdk::quaternion_class &current_joint_rotation_param, void * = 0) = 0; // 42
	virtual sxsdk::quaternion_class get_current_joint_rotation (void * = 0) const = 0; // 43
	virtual void set_motion_point_rotation (int i, const sxsdk::quaternion_class& q, void* aux = 0) = 0; // 44
		void set_sequence_joint_rotation_value (int i, const sxsdk::quaternion_class& q, void* aux = 0) { set_motion_point_rotation(i, q); }
	virtual sxsdk::quaternion_class get_motion_point_rotation (int i, void* aux = 0) = 0; // 45
		sxsdk::quaternion_class get_sequence_joint_rotation_value (int i, void* aux = 0) { return get_motion_point_rotation(i); }
	virtual motion_interface &set_default_joint_rotation (const sxsdk::quaternion_class &default_joint_rotation_param, void * = 0) = 0; // 46
	virtual sxsdk::quaternion_class get_default_joint_rotation (void * = 0) const = 0; // 47
	virtual motion_interface &set_current_joint_offset (const sxsdk::vec3 &current_joint_offset_param, void * = 0) = 0; // 48
	virtual sxsdk::vec3 get_current_joint_offset (void * = 0) const = 0; // 49
	virtual void set_motion_point_offset (int i, const sxsdk::vec3& q, void* aux = 0) = 0; // 50
		void set_sequence_joint_offset_value (int i, const sxsdk::vec3& q, void* aux = 0) { set_motion_point_offset(i, q); }
	virtual sxsdk::vec3 get_motion_point_offset (int i, void* aux = 0) = 0; // 51
		sxsdk::vec3 get_sequence_joint_offset_value (int i, void* aux = 0) { return get_motion_point_offset(i); }
	virtual motion_interface &set_default_joint_offset (const sxsdk::vec3 &default_joint_offset_param, void * = 0) = 0; // 52
	virtual sxsdk::vec3 get_default_joint_offset (void * = 0) const = 0; // 53
	virtual void prohibit_update (void* aux = 0) = 0; // 54
	virtual void resume_update (void* aux = 0) = 0; // 55
	virtual sxsdk::motion_point_interface* get_motion_point_interface (int i, void* aux = 0) = 0; // 56
	virtual motion_interface &set_sequence_mode (bool sequence_mode_param, void * = 0) = 0; // 57
	virtual bool get_sequence_mode (void * = 0) const = 0; // 58
	virtual void add_group (const char* as, int color_index) = 0; // 59
	virtual void select_group (int i, void* aux = 0) = 0; // 60
	virtual motion_interface &set_auto_key (bool auto_key_param, void * = 0) = 0; // 61
	virtual bool get_auto_key (void * = 0) const = 0; // 62
	virtual int get_interpolation_type (void * = 0) const = 0; // 63
	virtual motion_interface &set_interpolation_type (int interpolation_type_param, void * = 0) = 0; // 64
	virtual int get_number_of_sequence_key_points (void * = 0) const = 0; // 65
	virtual sxsdk::vec3 get_position (void * = 0) const = 0; // 66
	virtual float get_size (void * = 0) const = 0; // 67
	virtual sxsdk::vec3 get_end_point (void * = 0) const = 0; // 68
	virtual int motion_interface_test_1 ( void* aux =0 ) { return 1; } // 69
	virtual float get_joint_value (float at, void* aux = 0) = 0; // 70
	virtual sxsdk::quaternion_class get_joint_rotation (float at, void* aux = 0) = 0; // 71
	virtual sxsdk::vec3 get_joint_offset (float at, void* aux = 0) = 0; // 72
	};

	class motion_point_interface : public shade_interface {
	public:
	virtual motion_point_interface &set_value (float value_param, void * = 0) = 0; // 0
	virtual float get_value (void * = 0) const = 0; // 1
	virtual motion_point_interface &set_corner (bool corner_param, void * = 0) = 0; // 2
	virtual bool get_corner (void * = 0) const = 0; // 3
	virtual void select (void* aux = 0) = 0; // 4
	virtual motion_point_interface &set_sequence (float sequence_param, void * = 0) = 0; // 5
	virtual float get_sequence (void * = 0) const = 0; // 6
	virtual motion_point_interface &set_slow_in (float slow_in_param, void * = 0) = 0; // 7
	virtual float get_slow_in (void * = 0) const = 0; // 8
	virtual motion_point_interface &set_slow_out (float slow_out_param, void * = 0) = 0; // 9
	virtual float get_slow_out (void * = 0) const = 0; // 10
	virtual void delete_ (void* aux = 0) = 0; // 11
	virtual motion_point_interface &set_rotation (const sxsdk::quaternion_class &rotation_param, void * = 0) = 0; // 12
	virtual sxsdk::quaternion_class get_rotation (void * = 0) const = 0; // 13
	virtual motion_point_interface &set_offset (const sxsdk::vec3 &offset_param, void * = 0) = 0; // 14
	virtual sxsdk::vec3 get_offset (void * = 0) const = 0; // 15
	virtual void set_scalar (int index, float scalar, void* aux = 0) = 0; // 16
	virtual float get_scalar (int index, void* aux = 0) = 0; // 17
	virtual float get_distance (void * = 0) const = 0; // 18
	virtual motion_point_interface &set_distance (float distance_param, void * = 0) = 0; // 19
	virtual float get_zoom (void * = 0) const = 0; // 20
	virtual motion_point_interface &set_zoom (float zoom_param, void * = 0) = 0; // 21
	virtual float get_bank (void * = 0) const = 0; // 22
	virtual motion_point_interface &set_bank (float bank_param, void * = 0) = 0; // 23
	virtual float get_perspective_correction (void * = 0) const = 0; // 24
	virtual motion_point_interface &set_perspective_correction (float perspective_correction_param, void * = 0) = 0; // 25
	virtual float get_focal_value (void * = 0) const = 0; // 26
	virtual motion_point_interface &set_focal_value (float focal_value_param, void * = 0) = 0; // 27
	virtual sxsdk::vec3 get_focal_point (void * = 0) const = 0; // 28
	virtual motion_point_interface &set_focal_point (const sxsdk::vec3 &focal_point_param, void * = 0) = 0; // 29
	virtual sxsdk::vec2 get_shift (void * = 0) const = 0; // 30
	virtual motion_point_interface &set_shift (const sxsdk::vec2 &shift_param, void * = 0) = 0; // 31
	virtual sxsdk::vec2 get_film_shift (void * = 0) const = 0; // 32
	virtual motion_point_interface &set_film_shift (const sxsdk::vec2 &film_shift_param, void * = 0) = 0; // 33
	virtual sxsdk::vec2 get_film_tilt (void * = 0) const = 0; // 34
	virtual motion_point_interface &set_film_tilt (const sxsdk::vec2 &film_tilt_param, void * = 0) = 0; // 35
	virtual sxsdk::vec2 get_lens_tilt (void * = 0) const = 0; // 36
	virtual motion_point_interface &set_lens_tilt (const sxsdk::vec2 &lens_tilt_param, void * = 0) = 0; // 37
	virtual float get_parallel (void * = 0) const = 0; // 38
	virtual motion_point_interface &set_parallel (float parallel_param, void * = 0) = 0; // 39
	virtual float get_scale (void * = 0) const = 0; // 40
	virtual motion_point_interface &set_scale (float scale_param, void * = 0) = 0; // 41
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 42
	virtual int get_keyframe_index (void * = 0) const = 0; // 43
	};
}
