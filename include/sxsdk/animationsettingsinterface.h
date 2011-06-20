#pragma once

namespace sxsdk {
	class animation_settings_interface : public shade_interface {
	public:
	virtual bool get_timecode_mode (void * = 0) const = 0; // 0
	virtual animation_settings_interface &set_timecode_mode (bool timecode_mode_param, void * = 0) = 0; // 1
	virtual int get_leading_frames (void * = 0) const = 0; // 2
	virtual animation_settings_interface &set_leading_frames (int leading_frames_param, void * = 0) = 0; // 3
	virtual int get_trailing_frames (void * = 0) const = 0; // 4
	virtual animation_settings_interface &set_trailing_frames (int trailing_frames_param, void * = 0) = 0; // 5
	virtual int get_step (void * = 0) const = 0; // 6
	virtual animation_settings_interface &set_step (int step_param, void * = 0) = 0; // 7
	virtual int get_starting_frame (void * = 0) const = 0; // 8
	virtual animation_settings_interface &set_starting_frame (int starting_frame_param, void * = 0) = 0; // 9
	virtual int get_ending_frame (void * = 0) const = 0; // 10
	virtual animation_settings_interface &set_ending_frame (int ending_frame_param, void * = 0) = 0; // 11
	virtual int get_frame_rate (void * = 0) const = 0; // 12
	virtual animation_settings_interface &set_frame_rate (int frame_rate_param, void * = 0) = 0; // 13
	virtual bool get_object_movie_mode (void * = 0) const = 0; // 14
	virtual animation_settings_interface &set_object_movie_mode (bool object_movie_mode_param, void * = 0) = 0; // 15
	virtual int get_rows (void * = 0) const = 0; // 16
	virtual animation_settings_interface &set_rows (int rows_param, void * = 0) = 0; // 17
	virtual bool get_dropframe (void * = 0) const = 0; // 18
	virtual animation_settings_interface &set_dropframe (bool dropframe_param, void * = 0) = 0; // 19
	virtual bool get_auto_scaling (void * = 0) const = 0; // 20
	virtual animation_settings_interface &set_auto_scaling (bool auto_scaling_param, void * = 0) = 0; // 21
	virtual void make_timecode_string (char *s, float frame, bool fraction, void* aux = 0) = 0; // 22
	virtual float get_step_float (void * = 0) const = 0; // 23
	virtual animation_settings_interface &set_step_float (float step_float_param, void * = 0) = 0; // 24
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 25
	virtual bool get_soundpreview (void * = 0) const = 0; // 26
	virtual animation_settings_interface &set_soundpreview (bool soundpreview_param, void * = 0) = 0; // 27
	virtual bool get_sound3d (void * = 0) const = 0; // 28
	virtual animation_settings_interface &set_sound3d (bool sound3d_param, void * = 0) = 0; // 29
	};
}
