#pragma once

namespace sxsdk {
	class shade_interface : public unknown_interface {
	public:
		static compointer<shade_interface> shadei; // used by shade library client (not plugin)
		class output_function_class {
		public:
			virtual ~output_function_class () { }
			virtual void output (int i0 , int i1 , int i2 , int i3) {
			}
		};
	virtual void* get_extended_interface (void* aux = 0); // 0
	virtual void get_error_code_obsolete (void* aux = 0) { } // 1
	virtual void reset_error_code (void* aux = 0); // 2
	virtual shade_interface &set_throw_exception (bool throw_exception_param, void * = 0); // 3
	virtual bool get_throw_exception (void * = 0) const; // 4
	virtual bool is_japanese_mode (void * = 0) const; // 5
	virtual sxsdk::scene_interface* get_scene_interface (void * = 0) const; // 6
	virtual void new_scene (compointer<scene_interface>* aux = 0); // 7
	virtual const char* open_scene (const char*const& path, compointer<scene_interface>* aux = 0); // 8
	virtual const char* open_scene (compointer<scene_interface>* aux = 0); // 9
	virtual void quit (void* aux = 0); // 10
	virtual void save_color_list_1 (const char*const& path, void* aux = 0); // 11
	virtual void load_color_list_1 (const char*const& path, void* aux = 0); // 12
	virtual void save_color_list_2 (const char*const& path, void* aux = 0); // 13
	virtual void load_color_list_2 (const char*const& path, void* aux = 0); // 14
	virtual void save_shortcut (const char*const& path, void* aux = 0); // 15
	virtual void load_shortcut (const char*const& path, void* aux = 0); // 16
	virtual shade_interface &set_visible (bool visible_param, void * = 0); // 17
	virtual bool get_visible (void * = 0) const; // 18
	virtual shade_interface &set_smooth_apply (bool smooth_apply_param, void * = 0); // 19
	virtual bool get_smooth_apply (void * = 0) const; // 20
	virtual int get_version (void * = 0) const; // 21
	virtual void beep (void* aux = 0); // 22
	virtual void message (const char* message, void* aux = 0); // 23
void message (const std::string s) { message(s.c_str()); }
	virtual sxsdk::mat4 make_tv (const sxsdk::vec3& f, const sxsdk::vec3& a, float bank, bool shift, float h_shift, float v_shift, float parallel, bool top_view, void* aux = 0); // 24
	virtual void plane_equation (int n, const sxsdk::vec3* p, sxsdk::vec4& param, void* aux = 0); // 25
	virtual const char* get_active_document (void * = 0) const; // 26
	virtual float sin (float x, void* aux = 0); // 27
	virtual float cos (float x, void* aux = 0); // 28
	virtual float tan (float x, void* aux = 0); // 29
	virtual float asin (float x, void* aux = 0); // 30
	virtual float acos (float x, void* aux = 0); // 31
	virtual float atan (float x, void* aux = 0); // 32
	virtual float sqrt (float x, void* aux = 0); // 33
	virtual void set_preview_size_limit (int flag, int limit, void* aux = 0); // 34
	virtual const char* get_special_characters (void * = 0) const; // 35
	virtual shade_interface &set_current_texture (int current_texture_param, void * = 0); // 36
	virtual int get_current_texture (void * = 0) const; // 37
	virtual sxsdk::shortcut_interface* get_shortcut_interface (void * = 0) const; // 38
	virtual shade_interface &set_relative (bool relative_param, void * = 0); // 39
	virtual bool get_relative (void * = 0) const; // 40
	virtual void unmatrix (const sxsdk::mat4& m, float& scale_x, float& scale_y, float& scale_z, float& shear_xy, float& shear_xz, float& shear_yz, float& rotate_x, float& rotate_y, float& rotate_z, float& trans_x, float& trans_y, float& trans_z, void* aux = 0); // 41
	virtual shade_interface &set_background_selection (enums::background_part background_selection_param, void * = 0); // 42
	virtual enums::background_part get_background_selection (void * = 0) const; // 43
	virtual shade_interface &set_current_background_texture (int current_background_texture_param, void * = 0); // 44
	virtual int get_current_background_texture (void * = 0) const; // 45
	virtual shade_interface &set_current_light (int current_light_param, void * = 0); // 46
	virtual int get_current_light (void * = 0) const; // 47
	virtual sxsdk::dialog_interface* create_dialog_interface (int dialog_id = 0, void* aux = 0); // 48
		sxsdk::dialog_interface* get_dialog_interface (int dialog_id = 0, void* aux = 0) { return create_dialog_interface(dialog_id); }
	virtual float get_path_obsolete (void* aux = 0) { return 0.0; } // 49
	virtual bool show_message_box (const char* s, bool cancel, void* aux = 0); // 50
	virtual sxsdk::image_interface* get_new_image_interface (const sx::vec<int,2>& size, void* aux = 0); // 51
	virtual sxsdk::image_interface* get_new_image_interface (const char*const& path = "", void* aux = 0); // 52
	virtual sxsdk::image_interface* get_new_image_interface (void* aux = 0); // 53
	virtual void page_setup (void* aux = 0); // 54
	virtual void* malloc (size_t size, void* aux = 0); // 55
	virtual void free (void* p, void* aux = 0); // 56
	virtual shade_interface &set_image_window_shown (bool image_window_shown_param, void * = 0); // 57
	virtual bool get_image_window_shown (void * = 0) const; // 58
	virtual shade_interface &set_tool_box_window_shown (bool tool_box_window_shown_param, void * = 0); // 59
	virtual bool get_tool_box_window_shown (void * = 0) const; // 60
	virtual void set_figure_controller_window_shown_obsolete (bool b, void* aux = 0) { } // 61
	virtual bool get_figure_controller_window_shown_obsolete (void* aux = 0) { return false; } // 62
	virtual shade_interface &set_camera_window_shown (bool camera_window_shown_param, void * = 0); // 63
	virtual bool get_camera_window_shown (void * = 0) const; // 64
	virtual shade_interface &set_distant_light_window_shown (bool distant_light_window_shown_param, void * = 0); // 65
	virtual bool get_distant_light_window_shown (void * = 0) const; // 66
	virtual shade_interface &set_color_window_shown (bool color_window_shown_param, void * = 0); // 67
	virtual bool get_color_window_shown (void * = 0) const; // 68
	virtual shade_interface &set_color_list_window_shown (bool color_list_window_shown_param, void * = 0); // 69
	virtual bool get_color_list_window_shown (void * = 0) const; // 70
	virtual shade_interface &set_background_window_shown (bool background_window_shown_param, void * = 0); // 71
	virtual bool get_background_window_shown (void * = 0) const; // 72
	virtual shade_interface &set_surface_window_shown (bool surface_window_shown_param, void * = 0); // 73
	virtual bool get_surface_window_shown (void * = 0) const; // 74
	virtual shade_interface &set_browser_window_shown (bool browser_window_shown_param, void * = 0); // 75
	virtual bool get_browser_window_shown (void * = 0) const; // 76
	virtual shade_interface &set_correction_window_shown (bool correction_window_shown_param, void * = 0); // 77
	virtual bool get_correction_window_shown (void * = 0) const; // 78
	virtual shade_interface &set_backdrop_window_shown (bool backdrop_window_shown_param, void * = 0); // 79
	virtual bool get_backdrop_window_shown (void * = 0) const; // 80
	virtual shade_interface &set_ruler_window_shown (bool ruler_window_shown_param, void * = 0); // 81
	virtual bool get_ruler_window_shown (void * = 0) const; // 82
	virtual shade_interface &set_shortcut_window_shown (bool shortcut_window_shown_param, void * = 0); // 83
	virtual bool get_shortcut_window_shown (void * = 0) const; // 84
	virtual shade_interface &set_script_window_shown (bool script_window_shown_param, void * = 0); // 85
	virtual bool get_script_window_shown (void * = 0) const; // 86
	virtual shade_interface &set_message_window_shown (bool message_window_shown_param, void * = 0); // 87
	virtual bool get_message_window_shown (void * = 0) const; // 88
	virtual void from_little_endian (int n, void* data, void* aux = 0); // 89
	virtual void from_big_endian (int n, void* data, void* aux = 0); // 90
	virtual void to_little_endian (int n, void* data, void* aux = 0); // 91
	virtual void to_big_endian (int n, void* data, void* aux = 0); // 92
	virtual void* get_application (void * = 0) const; // 93
	virtual bool still_updating (void* aux = 0); // 94
	virtual void wait_updating (void* aux = 0); // 95
	virtual bool is_japanese_system (void * = 0) const; // 96
	virtual bool is_little_endian (void * = 0) const; // 97
	virtual bool is_big_endian (void * = 0) const; // 98
	virtual script_interface* get_script_interface (void * = 0) const; // 99
	virtual bool is_same_as (shade_interface* i, void* aux = 0); // 100
	virtual int get_development_version (void* aux = 0); // 101
	virtual bool is_personal (void * = 0) const; // 102
	virtual bool is_professional (void * = 0) const; // 103
	virtual void* realloc (void* p, size_t size, void* aux = 0); // 104
	virtual bool is_korean_system (void * = 0) const; // 105
	virtual bool is_korean_mode (void * = 0) const; // 106
	virtual progress_dialog_interface* create_progress_dialog_interface (const char* title, void* aux = 0); // 107
	virtual bool is_heap_ok (void * = 0) const; // 108
	virtual sxsdk::mat4 get_zmat (const sxsdk::vec3& v, void* aux = 0); // 109
	virtual sxsdk::mat4 get_amat (const sxsdk::vec3& v0, const sxsdk::vec3& v1, void* aux = 0); // 110
	virtual bool is_rendering_server (void * = 0) const; // 111
	virtual text_stream_interface* get_log_text_stream_interface (void * = 0) const; // 112
	virtual shade_interface &set_radiosity_window_shown (bool radiosity_window_shown_param, void * = 0); // 113
	virtual bool get_radiosity_window_shown (void * = 0) const; // 114
	virtual void divide_polygon (output_function_class& output, int n, const sxsdk::vec3* p, bool triangulate = false, bool triangulate_if_nonplanar = false, bool triangulate_if_concave = false, void* aux = 0); // 115
	virtual HWND get_main_window (void * = 0) const; // 116
	virtual critical_section_interface* create_critical_section_interface (void* aux = 0); // 117
	virtual color_interface* get_color_interface (void * = 0) const; // 118
	virtual color_list_interface* get_color_list_interface (void * = 0) const; // 119
	virtual shade_interface &set_skin_window_shown (bool skin_window_shown_param, void * = 0); // 120
	virtual bool get_skin_window_shown (void * = 0) const; // 121
	virtual preference_interface* get_preference_interface (void * = 0) const; // 122
	virtual shade_interface &set_motion_window_shown (bool motion_window_shown_param, void * = 0); // 123
	virtual bool get_motion_window_shown (void * = 0) const; // 124
	virtual void set_control_bar_shown_obsolete (bool b, void* aux = 0); // 125
	virtual bool get_control_bar_shown_obsolete (void* aux = 0); // 126
	virtual bool check_system_language (int languageid, void* aux = 0); // 127
	virtual bool check_shade_language (int languageid, void* aux = 0); // 128
	virtual bool update_port (void* a, void* aux = 0) { return false; } // 129
	virtual sxsdk::image_interface* create_empty_image_interface (void* aux = 0); // 130
		sxsdk::image_interface* get_empty_image_interface (void* aux = 0) { return create_empty_image_interface(); }
	virtual implementation_interface& implementation (void* aux = 0); // 131
	virtual const char* get_error_string (void* aux = 0); // 132
	virtual int get_error_code (void* aux = 0); // 133
	virtual int shade_interface_test_1 (void* aux = 0) { return 1; } // 134
#if SXMACOSX 
	virtual sxsdk::image_interface* create_image_interface_from_resource_deprecated (const char* image_id, void* aux = 0); // 135
		sxsdk::image_interface* get_image_interface_from_resource_deprecated (const char* image_id, void* aux = 0) { return create_image_interface_from_resource_deprecated(image_id); }
#elif SXWINDOWS 
	virtual sxsdk::image_interface* create_image_interface_from_resource_deprecated (int image_id, void* aux = 0); // 135
		sxsdk::image_interface* get_image_interface_from_resource_deprecated (int image_id, void* aux = 0) { return create_image_interface_from_resource_deprecated(image_id); }
#else 
	virtual sxsdk::image_interface* get_image_interface_from_resource_deprecated (void* image_id, void* aux = 0); // 135
#endif 
	virtual const char* get_exception (void* aux = 0); // 136
	virtual sxsdk::rgb_class get_wireframe_color_obsolete (void * = 0) const; // 137
	virtual shade_interface &set_wireframe_color_obsolete (const sxsdk::rgb_class &wireframe_color_obsolete_param, void * = 0); // 138
	virtual void calculate_internal_points (std::array<std::array<sxsdk::vec3, 4>, 4>& p, const bool correction, const sxsdk::mat4& lw, void* aux = 0); // 139
	virtual sxsdk::vec2 calculate_blending_weights (const sxsdk::vec2& uv, void* aux = 0); // 140
	virtual int get_number_of_accepted_dlls (void * = 0) const; // 141
	virtual dll_interface* get_accepted_dll_interface (int index, void* aux = 0); // 142
	virtual bool is_renderer (void * = 0) const; // 143
	virtual bool is_demo (void * = 0) const; // 144
	virtual int enumerate_control_windows (sxsdk::window_interface** windows, void* aux = 0); // 145
	virtual const char* get_exception_string () const; // 146
	virtual sxsdk::plugin_interface* find_plugin_interface (int plugin_id, void* aux = 0); // 147
	virtual int get_number_of_dlls (void * = 0) const; // 148
	virtual dll_interface* get_dll_interface (int i, void* aux = 0); // 149
	virtual const char* get_path (void * = 0) const; // 150
	virtual const char* get_scripts_path (void * = 0) const; // 151
	virtual const char* encode (const char* s, enums::text_encoding_enum encoding = enums::default_encoding); // 152
	virtual const char* decode (const char* s, enums::text_encoding_enum encoding = enums::default_encoding); // 153
	virtual void clone_surface_window_obsolete (void* aux = 0); // 154
	virtual const char* get_embedded_scripts_path (void * = 0) const; // 155
	virtual const char* get_script_path (void * = 0) const; // 156
	virtual sxsdk::image_interface* get_active_image_interface (void * = 0) const; // 157
	virtual void sleep (int ms, void* aux = 0); // 158
	virtual void begin_timing (void* aux = 0); // 159
	virtual int end_timing (void* aux = 0); // 160
	virtual void reset_timing (void* aux = 0); // 161
	virtual void begin_timing_figure_window (void* aux = 0); // 162
	virtual int end_timing_figure_window (void* aux = 0); // 163
	virtual image_window_interface* get_image_window_interface (void * = 0) const; // 164
	virtual tool_box_window_interface* get_tool_box_window_interface (void * = 0) const; // 165
	virtual camera_window_interface* get_camera_window_interface (void * = 0) const; // 166
	virtual distant_light_window_interface* get_distant_light_window_interface (void * = 0) const; // 167
	virtual color_window_interface* get_color_window_interface (void * = 0) const; // 168
	virtual color_list_window_interface* get_color_list_window_interface (void * = 0) const; // 169
	virtual background_window_interface* get_background_window_interface (void * = 0) const; // 170
	virtual surface_window_interface* get_surface_window_interface (void * = 0) const; // 171
	virtual browser_window_interface* get_browser_window_interface (void * = 0) const; // 172
	virtual correction_window_interface* get_correction_window_interface (void * = 0) const; // 173
	virtual void* get_backdrop_window_interface (void * = 0) const; // 174
	virtual ruler_window_interface* get_ruler_window_interface (void * = 0) const; // 175
	virtual radiosity_window_interface* get_radiosity_window_interface (void * = 0) const; // 176
	virtual shortcut_window_interface* get_shortcut_window_interface (void * = 0) const; // 177
	virtual script_window_interface* get_script_window_interface (void * = 0) const; // 178
	virtual skin_window_interface* get_skin_window_interface (void * = 0) const; // 179
	virtual motion_window_interface* get_motion_window_interface (void * = 0) const; // 180
	virtual aggregate_window_interface* get_aggregate_window_interface (void * = 0) const; // 181
	virtual sxsdk::stream_interface* create_file_interface (const char* path, void* aux = 0); // 182
	virtual text_stream_interface* create_text_file_interface (const char* path, bool read_mode = false); // 183
	virtual void register_python_object (PyObject* object, void* aux = 0); // 184
	virtual sxsdk::image_interface* create_joined_image_interface (int n_images, sxsdk::image_interface* const images[], void* aux = 0); // 185
	virtual message_window_interface* get_message_window_interface (void * = 0) const; // 186
	virtual int shade_interface_dummy187(void *) { assert(false); throw "invalid interface shade_interface"; return 0; } // 187
	virtual int shade_interface_dummy188(void *) { assert(false); throw "invalid interface shade_interface"; return 0; } // 188
	virtual object_info_window_interface* get_object_info_window_interface (void * = 0) const; // 189
	virtual strings_interface* create_strings_interface (const char* from = 0, void* aux = 0); // 190
	virtual bool is_french_mode (void * = 0) const; // 191
	virtual sxsdk::plugin_interface* find_plugin_interface_with_uuid (const sx::uuid_class& plugin_id, void* aux = 0); // 192
	virtual sxsdk::dialog_interface* create_dialog_interface_with_uuid (const sx::uuid_class& dialog_id = sx::uuid_class(0u), void* aux = 0); // 193
	virtual bool is_simplified_chinese_mode (void * = 0) const; // 194
	virtual int get_renderers (const char* list[], void * = 0) const; // 195
	virtual bool play_sound (const char* path, int repeat = 1, void* aux = 0); // 196
	virtual void stop_sound (void* aux = 0); // 197
	virtual bool is_playing (void * = 0) const; // 198
	virtual int show_yesnocancel_message_box (const char* s, void* aux = 0); // 199
image_view_interface* get_image_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_image_view_interface(); }
tool_box_view_interface* get_tool_box_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_tool_box_view_interface(); }
color_view_interface* get_color_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_color_view_interface(); }
background_view_interface* get_background_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_background_view_interface(); }
surface_view_interface* get_surface_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_surface_view_interface(); }
browser_view_interface* get_browser_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_browser_view_interface(); }
correction_view_interface* get_correction_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_correction_view_interface(); }
camera_view_interface* get_camera_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_camera_view_interface(); }
distant_light_view_interface* get_distant_light_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_distant_light_view_interface(); }
ruler_view_interface* get_ruler_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_ruler_view_interface(); }
message_view_interface* get_message_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_message_view_interface(); }
script_view_interface* get_script_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_script_view_interface(); }
shortcut_view_interface* get_shortcut_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_shortcut_view_interface(); }
radiosity_view_interface* get_radiosity_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_radiosity_view_interface(); }
skin_view_interface* get_skin_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_skin_view_interface(); }
motion_view_interface* get_motion_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_motion_view_interface(); }
object_info_view_interface* get_object_info_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_object_info_view_interface(); }
aggregate_view_interface* get_aggregate_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_aggregate_view_interface(); }
rendering_options_view_interface* get_rendering_options_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_rendering_options_view_interface(); }
radiosity_options_view_interface* get_radiosity_options_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_radiosity_options_view_interface(); }
sxsdk::quaternion_class quaternion_from_euler (const sxsdk::vec3& euler, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().quaternion_from_euler(euler); }
sxsdk::vec3 euler_from_quaternion (const sxsdk::quaternion_class& quaternion, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().euler_from_quaternion(quaternion); }
sxsdk::vec4 make_plane_equation (int n_p, const sxsdk::vec3 p[], void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().make_plane_equation(n_p, p); }
sxsdk::image_interface* create_image_interface (const sx::vec<int,2>& size, int depth = 32, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().create_image_interface(size, depth); }
sxsdk::image_interface* create_image_interface (const char* name, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().create_image_interface_from_resource(name); }
sxsdk::image_interface* create_image_interface_from_file (const char* path, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().create_image_interface_from_file(path); }
const char* gettext (const char* message) { return (const_cast<shade_interface *>(this))->implementation().gettext(message); }
void pump () { (const_cast<shade_interface *>(this))->implementation().pump(); }
void idle (int duration) { (const_cast<shade_interface *>(this))->implementation().idle(duration); }
sx::rectangle_class uniscale_rectangle (const sx::rectangle_class& destination, const sx::rectangle_class& source) { return (const_cast<shade_interface *>(this))->implementation().uniscale_rectangle(destination, source); }
std::vector<sxsdk::vec3> unmatrix_scriptimplementation (const sxsdk::mat4& t, void* aux = 0) { std::vector<sxsdk::vec3> v(4); unmatrix(t, v[0].x, v[0].y, v[0].z, v[1].x, v[1].y, v[1].z, v[2].x, v[2].y, v[2].z, v[3].x, v[3].y, v[3].z); return v; }
int create_mouse_cursor_from_resource (const char* name, const sx::vec<int,2>& hotspot, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().create_mouse_cursor_from_resource(name, hotspot); }
void set_mouse_cursor (int index, void* aux = 0) { (const_cast<shade_interface *>(this))->implementation().set_mouse_cursor(index); }
bool is_key_down (int key_code, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().is_key_down(key_code); }
void set_tiled_logo (bool flag, void * aux = 0) { (const_cast<shade_interface *>(this))->implementation().set_tiled_logo(flag, aux); }
const char* get_note (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_note(); }
const char* get_commit (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_commit(); }
int check_serial_number (const char* serial, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().check_serial_number(serial); }
bool is_licensed (const char* product_name, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().is_licensed(product_name); }
bool add_license (const char* product_name, const char* serial, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().add_license(product_name, serial); }
bool remove_license (const char* product_name, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().remove_license(product_name); }
bool is_japanese_build () { return (const_cast<shade_interface *>(this))->implementation().is_japanese_build(); }
bool is_english_build () { return (const_cast<shade_interface *>(this))->implementation().is_english_build(); }
bool is_simplified_chinese_build () { return (const_cast<shade_interface *>(this))->implementation().is_simplified_chinese_build(); }
bool is_french_build () { return (const_cast<shade_interface *>(this))->implementation().is_french_build(); }
void plugin_registration (const char* serial, void* aux = 0) { implementation().plugin_registration(serial); }
int get_used_memory (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_used_memory(); }
int get_max_used_memory (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_max_used_memory(); }
void reset_max_used_memory () { implementation().reset_max_used_memory(); }
void initialize_library () { implementation().initialize_library(); }
meshtools_view_interface* get_meshtools_view_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_meshtools_view_interface(); }
meshtools_window_interface* get_meshtools_window_interface (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().view_get_meshtools_window_interface(); }
bool get_meshtools_window_shown (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_meshtools_window_shown(); }
shade_interface &set_meshtools_window_shown (bool meshtools_window_shown_param, void * = 0) { (const_cast<shade_interface *>(this))->implementation().set_meshtools_window_shown(meshtools_window_shown_param); return *this; }
bool get_shadeexplorer_window_shown (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_shadeexplorer_window_shown(); }
shade_interface &set_shadeexplorer_window_shown (bool shadeexplorer_window_shown_param, void * = 0) { (const_cast<shade_interface *>(this))->implementation().set_shadeexplorer_window_shown(shadeexplorer_window_shown_param); return *this; }
bool get_aggregate_window_shown (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_aggregate_window_shown(); }
shade_interface &set_aggregate_window_shown (bool aggregate_window_shown_param, void * = 0) { (const_cast<shade_interface *>(this))->implementation().set_aggregate_window_shown(aggregate_window_shown_param); return *this; }
sxsdk::stream_interface* create_stdio_stream_interface ( 
			 ) { return implementation().create_stdio_stream_interface(); }
sxsdk::stream_interface* create_fixed_memory_stream_interface (void* memory, std::size_t size) { return implementation().create_fixed_memory_stream_interface(memory, size); }
sxsdk::stream_interface* create_memory_stream_interface () { return implementation().create_memory_stream_interface(); }
sxsdk::scene_interface* create_scene_interface (enums::preset_scene_enum scene_type = enums::empty_scene) { return implementation().create_scene_interface(scene_type); }
bool is_traditional_chinese_mode (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().is_traditional_chinese_mode(); }
bool is_traditional_chinese_build () { return (const_cast<shade_interface *>(this))->implementation().is_traditional_chinese_build(); }
void finalize_library () { implementation().finalize_library(); }
const char* open_database () { return (const_cast<shade_interface *>(this))->implementation().open_database(); }
void close_database (const char* dbid) { implementation().close_database(dbid); }
bool is_database (const char* dbid) { return (const_cast<shade_interface *>(this))->implementation().is_database(dbid); }
int database_execute (const char* dbid, const char* sql, void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().database_execute(dbid,sql); }
const char* database_resultText (const char* dbid) { return (const_cast<shade_interface *>(this))->implementation().database_resultText(dbid); }
const char* database_statement (const char* dbid, const char* sql) { return (const_cast<shade_interface *>(this))->implementation().database_statement(dbid,sql); }
bool is_database_statement (const char* stmtid) { return (const_cast<shade_interface *>(this))->implementation().is_database_statement(stmtid); }
const char* database_laseError (const char* dbid) { return (const_cast<shade_interface *>(this))->implementation().database_laseError(dbid); }
int database_errorCode (const char* dbid) { return (const_cast<shade_interface *>(this))->implementation().database_errorCode(dbid); }
int database_statement_step (const char* stmtid) { return (const_cast<shade_interface *>(this))->implementation().database_statement_step(stmtid); }
int database_statement_reset (const char* stmtid) { return (const_cast<shade_interface *>(this))->implementation().database_statement_reset(stmtid); }
int database_statement_finalize (const char* stmtid) { return (const_cast<shade_interface *>(this))->implementation().database_statement_finalize(stmtid); }
int database_statement_bind_int (const char* stmtid, int index, int iValue) { return (const_cast<shade_interface *>(this))->implementation().database_statement_bind_int(stmtid,index,iValue); }
int database_statement_bind_string (const char* stmtid, int index, const char* text) { return (const_cast<shade_interface *>(this))->implementation().database_statement_bind_string(stmtid,index,text); }
int database_statement_bind_double (const char* stmtid, int index, double rValue) { return (const_cast<shade_interface *>(this))->implementation().database_statement_bind_double(stmtid,index,rValue); }
int database_statement_bind_null (const char* stmtid, int index) { return (const_cast<shade_interface *>(this))->implementation().database_statement_bind_null(stmtid,index); }
int database_statement_dataType (const char* stmtid, int index) { return (const_cast<shade_interface *>(this))->implementation().database_statement_dataType(stmtid,index); }
int database_statement_intValue (const char* stmtid, int index) { return (const_cast<shade_interface *>(this))->implementation().database_statement_intValue(stmtid,index); }
double database_statement_doubleValue (const char* stmtid, int index) { return (const_cast<shade_interface *>(this))->implementation().database_statement_doubleValue(stmtid,index); }
const char* database_statement_stringValue (const char* stmtid, int index) { return (const_cast<shade_interface *>(this))->implementation().database_statement_stringValue(stmtid,index); }
int database_statement_byts (const char* stmtid, int index) { return (const_cast<shade_interface *>(this))->implementation().database_statement_byts(stmtid,index); }
bool database_statement_nextRow (const char* stmtid) { return (const_cast<shade_interface *>(this))->implementation().database_statement_nextRow(stmtid); }
bool is_speed_build () { return (const_cast<shade_interface *>(this))->implementation().is_speed_build(); }
sxsdk::exporter_settings_interface* create_exporter_settings_interface (const sx::uuid_class& exporter_id = sx::uuid_class(0,0,0,0), void* aux = 0) { return (const_cast<shade_interface *>(this))->implementation().create_exporter_settings_interface(exporter_id); }
void purge_images () { (const_cast<shade_interface *>(this))->implementation().purge_images(); }
int get_build_date (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_build_date(); }
int get_bits (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_bits(); }
const char* get_processor (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_processor(); }
const char* get_shadeexplorer_data_path () { return (const_cast<shade_interface *>(this))->implementation().get_shadeexplorer_data_path(); }
bool open_backup (const char* file_path, const char* output_folder = 0, int flags = 0) { return (const_cast<shade_interface *>(this))->implementation().open_backup(file_path, output_folder, flags); }
const char* get_version_info (void * = 0) const { return (const_cast<shade_interface *>(this))->implementation().get_version_info(); }
void virtual_query () { return (const_cast<shade_interface *>(this))->implementation().virtual_query(); }
int get_current_time () { return (const_cast<shade_interface *>(this))->implementation().get_current_time(); }
	};
}
