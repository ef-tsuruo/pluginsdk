#pragma once

namespace sxsdk {
	class implementation_interface : public unknown_interface {
	public:
	virtual xshade::window_class* window_new (sxsdk::window_interface& wi, sxsdk::window_interface* parent, int flags) = 0; // 0
	virtual void window_show (sxsdk::window_interface& w) = 0; // 1
	virtual void window_hide (sxsdk::window_interface& w) = 0; // 2
	virtual bool window_is_shown (const window_interface& w) = 0; // 3
	virtual void window_set_title (sxsdk::window_interface& w, const char* title) = 0; // 4
	virtual void window_set_size (sxsdk::window_interface& w, sx::vec<int,2> size) = 0; // 5
	virtual void window_set_client (sxsdk::window_interface& w, const sx::rectangle_class& rect) = 0; // 6
	virtual void window_set_canvas_size (sxsdk::window_interface& w, sx::vec<int,2> size) = 0; // 7
	virtual plugin_push_button_class& window_create_button (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 8
	virtual plugin_checkbox_class& window_create_check_box (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 9
	virtual plugin_slider_class& window_create_slider (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int size, bool vertical, const char* title, bool show_marks) = 0; // 10
	virtual plugin_number_class& window_create_number_without_title (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy) = 0; // 11
	virtual plugin_popup_menu_class& window_create_popup (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, const char* title, int width, const char* items) = 0; // 12
	virtual plugin_color_disk_class& window_create_color_disk (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y) = 0; // 13
	virtual plugin_color_box_class& window_create_color_box (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy) = 0; // 14
	virtual plugin_image_box_class& window_create_image_box (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy) = 0; // 15
	virtual plugin_static_text_class& window_create_static_text (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 16
	virtual plugin_radio_button_class& window_create_radio_button (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 17
	virtual void window_set_check_box_int_value (sxsdk::window_interface& w, plugin_checkbox_class& c, int i) = 0; // 18
	virtual int window_get_check_box_int_value (sxsdk::window_interface& w, plugin_checkbox_class& c) = 0; // 19
	virtual void window_set_number_float_value (sxsdk::window_interface& w, plugin_number_class& c, float f) = 0; // 20
	virtual float window_get_number_float_value (sxsdk::window_interface& w, plugin_number_class& c) = 0; // 21
	virtual void window_set_popup_int_value (sxsdk::window_interface& w, plugin_popup_menu_class& c, int i) = 0; // 22
	virtual int window_get_popup_int_value (sxsdk::window_interface& w, plugin_popup_menu_class& c) = 0; // 23
	virtual void window_set_radio_button_int_value (sxsdk::window_interface& w, plugin_radio_button_class& c, int i) = 0; // 24
	virtual int window_get_radio_button_int_value (sxsdk::window_interface& w, plugin_radio_button_class& c) = 0; // 25
	virtual void window_set_color_disk_vec2_value (sxsdk::window_interface& w, plugin_color_disk_class& c, const sxsdk::vec2& v) = 0; // 26
	virtual sxsdk::vec2 window_get_color_disk_vec2_value (sxsdk::window_interface& w, plugin_color_disk_class& c) = 0; // 27
	virtual void window_set_color_box_rgb_value (sxsdk::window_interface& w, plugin_color_box_class& c, const sxsdk::rgb_class& r) = 0; // 28
	virtual sxsdk::rgb_class window_get_color_box_rgb_value (sxsdk::window_interface& w, plugin_color_box_class& c) = 0; // 29
	virtual void window_set_image_box_image_value (sxsdk::window_interface& w, plugin_image_box_class& c, sxsdk::image_interface* i) = 0; // 30
	virtual sxsdk::image_interface* window_get_image_box_image_value (sxsdk::window_interface& w, plugin_image_box_class& c) = 0; // 31
	virtual void window_set_slider_float_value (sxsdk::window_interface& w, plugin_slider_class& c, float f) = 0; // 32
	virtual float window_get_slider_float_value (sxsdk::window_interface& w, plugin_slider_class& c) = 0; // 33
	virtual int window_get_control_id (sxsdk::window_interface& w, xshade::control::control_class& c) = 0; // 34
	virtual void window_clear (sxsdk::window_interface& w, sxsdk::graphic_context_interface& gc) = 0; // 35
	virtual void window_paint (sxsdk::window_interface& w, sxsdk::graphic_context_interface& gc, const sx::rectangle_class* visible_rectangle) = 0; // 36
	virtual void window_resize (sxsdk::window_interface& w, int x, int y, bool remake) = 0; // 37
	virtual void window_mouse_enter (sxsdk::window_interface& w) = 0; // 38
	virtual void window_mouse_move (sxsdk::window_interface& w, sx::vec<int,2> p) = 0; // 39
	virtual void window_mouse_exit (sxsdk::window_interface& w) = 0; // 40
	virtual bool window_mouse_down (sxsdk::window_interface& w, int button, sx::vec<int,2> p, int key_down, int time, bool double_click) = 0; // 41
	virtual void window_idle (sxsdk::window_interface& w) = 0; // 42
	virtual void window_scrolled (sxsdk::window_interface& w, sx::vec<int,2> offset) = 0; // 43
	virtual bool control_select (xshade::control::control_class& control, bool select, bool invalidate_flag) = 0; // 44
	virtual void control_set_tooltip (xshade::control::control_class& control, const char* s) = 0; // 45
	virtual void control_set_active (xshade::control::control_class& control, bool active) = 0; // 46
	virtual void control_invalidate (xshade::control::control_class& control) = 0; // 47
	virtual void window_select (sxsdk::window_interface& w) = 0; // 48
	virtual sx::rectangle_class control_get_bounding_rectangle_deprecated (xshade::control::control_class& control) = 0; // 49
	virtual sx::rectangle_class window_get_client_rectangle_excluding_scroll_bars (const window_interface& w) = 0; // 50
	virtual void window_invalidate (sxsdk::window_interface& w) = 0; // 51
	virtual void control_show (xshade::control::control_class& control) = 0; // 52
	virtual void control_hide (xshade::control::control_class& control) = 0; // 53
	virtual void control_set_image (xshade::control::control_class& control, sxsdk::image_interface& image) = 0; // 54
	virtual void control_set_popup_menu (xshade::control::control_class& control, const char* title) = 0; // 55
	virtual int window_get_button_int_value (sxsdk::window_interface& w, plugin_push_button_class& c) = 0; // 56
	virtual void* window_get_text_object (sxsdk::window_interface& w) = 0; // 57
	virtual sx::vec<int,2> control_get_position (xshade::control::control_class& c) = 0; // 58
	virtual void control_set_position (xshade::control::control_class& c, const sx::vec<int,2>& position) = 0; // 59
	virtual sx::vec<int,2> control_get_size (xshade::control::control_class& c) = 0; // 60
	virtual void control_set_size (xshade::control::control_class& c, const sx::vec<int,2>& size) = 0; // 61
	virtual const char* control_get_title (xshade::control::control_class& c) = 0; // 62
	virtual void control_set_title (xshade::control::control_class& c, const char* title) = 0; // 63
	virtual void window_set_slider_range (sxsdk::window_interface& w, plugin_slider_class& c, float min, float max) = 0; // 64
	virtual sx::mouse_tracker_class& window_create_mouse_tracker (sxsdk::window_interface& w, void* mouse_tracker, const sx::vec<int,2>& where) = 0; // 65
	virtual void control_set_bounds (xshade::control::control_class& c, const sx::rectangle_class& bounds) = 0; // 66
	virtual sx::rectangle_class control_get_bounds (xshade::control::control_class& c) = 0; // 67
	virtual void control_delete_self (xshade::control::control_class& c) = 0; // 68
	virtual void control_set_items (xshade::control::control_class& c, const char* items) = 0; // 69
	virtual void window_set_client_rectangle (sxsdk::window_interface& w, const sx::rectangle_class& client) = 0; // 70
	virtual void window_set_frame_rectangle (sxsdk::window_interface& w, const sx::rectangle_class& frame) = 0; // 71
	virtual sx::vec<int,2> window_global_to_window_point (const window_interface& w, const sx::vec<int,2>& p) = 0; // 72
	virtual sx::rectangle_class window_global_to_window_rectangle (const window_interface& w, const sx::rectangle_class& r) = 0; // 73
	virtual sx::vec<int,2> window_window_to_global_point (const window_interface& w, const sx::vec<int,2>& p) = 0; // 74
	virtual sx::rectangle_class window_window_to_global_rectangle (const window_interface& w, const sx::rectangle_class& r) = 0; // 75
	virtual const char* window_get_title (const window_interface& w) = 0; // 76
	virtual shader_info_base_class* shader_get_shader_info ( 
			 ) = 0; // 77
	virtual float shader_get_mapping ( 
			 ) = 0; // 78
	virtual sxsdk::rgb_class shader_get_mapping_color ( 
			 ) = 0; // 79
	virtual float shader_get_turbulence ( 
			 ) = 0; // 80
	virtual float shader_get_softness ( 
			 ) = 0; // 81
	virtual rgba_class shader_sample_image (float u, float v) = 0; // 82
	virtual sxsdk::vec2 shader_sample_bump (float u, float v) = 0; // 83
	virtual sxsdk::vec3 shader_get_P ( 
			 ) = 0; // 84
	virtual void shader_set_P (const sxsdk::vec3& P) = 0; // 85
	virtual sxsdk::vec3 shader_get_N ( 
			 ) = 0; // 86
	virtual void shader_set_N (const sxsdk::vec3& N) = 0; // 87
	virtual sxsdk::vec3 shader_get_Ng ( 
			 ) = 0; // 88
	virtual sxsdk::vec3 shader_get_I ( 
			 ) = 0; // 89
	virtual sxsdk::rgb_class shader_get_Cs ( 
			 ) = 0; // 90
	virtual sxsdk::rgb_class shader_get_Os ( 
			 ) = 0; // 91
	virtual float shader_get_u ( 
			 ) = 0; // 92
	virtual float shader_get_v ( 
			 ) = 0; // 93
	virtual float shader_get_s ( 
			 ) = 0; // 94
	virtual float shader_get_t ( 
			 ) = 0; // 95
	virtual sxsdk::vec3 shader_get_dPdu ( 
			 ) = 0; // 96
	virtual sxsdk::vec3 shader_get_dPdv ( 
			 ) = 0; // 97
	virtual float shader_get_time ( 
			 ) = 0; // 98
	virtual float shader_get_du ( 
			 ) = 0; // 99
	virtual float shader_get_dv ( 
			 ) = 0; // 100
	virtual sxsdk::vec3 shader_get_L ( 
			 ) = 0; // 101
	virtual sxsdk::rgb_class shader_get_Cl ( 
			 ) = 0; // 102
	virtual sxsdk::rgb_class shader_get_Ci ( 
			 ) = 0; // 103
	virtual void shader_set_Ci (const sxsdk::rgb_class& Ci) = 0; // 104
	virtual sxsdk::rgb_class shader_get_Oi ( 
			 ) = 0; // 105
	virtual void shader_set_Oi (const sxsdk::rgb_class& Oi) = 0; // 106
	virtual sxsdk::vec3 shader_normalize (const sxsdk::vec3& v) = 0; // 107
	virtual float shader_mod (float x, float p) = 0; // 108
	virtual float shader_step (float edge, float x) = 0; // 109
	virtual float shader_smoothstep (float edge0, float edge1, float x) = 0; // 110
	virtual float shader_noise11 (float x) = 0; // 111
	virtual float shader_noise12 (const sxsdk::vec2& p) = 0; // 112
	virtual float shader_noise13 (const sxsdk::vec3& p) = 0; // 113
	virtual float shader_noise14 (const sxsdk::vec4& p) = 0; // 114
	virtual sxsdk::vec2 shader_noise21 (float x) = 0; // 115
	virtual sxsdk::vec2 shader_noise22 (const sxsdk::vec2& p) = 0; // 116
	virtual sxsdk::vec2 shader_noise23 (const sxsdk::vec3& p) = 0; // 117
	virtual sxsdk::vec2 shader_noise24 (const sxsdk::vec4& p) = 0; // 118
	virtual sxsdk::vec3 shader_noise31 (float x) = 0; // 119
	virtual sxsdk::vec3 shader_noise32 (const sxsdk::vec2& p) = 0; // 120
	virtual sxsdk::vec3 shader_noise33 (const sxsdk::vec3& p) = 0; // 121
	virtual sxsdk::vec3 shader_noise34 (const sxsdk::vec4& p) = 0; // 122
	virtual sxsdk::vec4 shader_noise41 (float x) = 0; // 123
	virtual sxsdk::vec4 shader_noise42 (const sxsdk::vec2& p) = 0; // 124
	virtual sxsdk::vec4 shader_noise43 (const sxsdk::vec3& p) = 0; // 125
	virtual sxsdk::vec4 shader_noise44 (const sxsdk::vec4& p) = 0; // 126
	virtual float shader_cellnoise11 (float x) = 0; // 127
	virtual float shader_cellnoise12 (const sxsdk::vec2& p) = 0; // 128
	virtual float shader_cellnoise13 (const sxsdk::vec3& p) = 0; // 129
	virtual float shader_cellnoise14 (const sxsdk::vec4& p) = 0; // 130
	virtual sxsdk::vec2 shader_cellnoise21 (float x) = 0; // 131
	virtual sxsdk::vec2 shader_cellnoise22 (const sxsdk::vec2& p) = 0; // 132
	virtual sxsdk::vec2 shader_cellnoise23 (const sxsdk::vec3& p) = 0; // 133
	virtual sxsdk::vec2 shader_cellnoise24 (const sxsdk::vec4& p) = 0; // 134
	virtual sxsdk::vec3 shader_cellnoise31 (float x) = 0; // 135
	virtual sxsdk::vec3 shader_cellnoise32 (const sxsdk::vec2& p) = 0; // 136
	virtual sxsdk::vec3 shader_cellnoise33 (const sxsdk::vec3& p) = 0; // 137
	virtual sxsdk::vec3 shader_cellnoise34 (const sxsdk::vec4& p) = 0; // 138
	virtual sxsdk::vec4 shader_cellnoise41 (float x) = 0; // 139
	virtual sxsdk::vec4 shader_cellnoise42 (const sxsdk::vec2& p) = 0; // 140
	virtual sxsdk::vec4 shader_cellnoise43 (const sxsdk::vec3& p) = 0; // 141
	virtual sxsdk::vec4 shader_cellnoise44 (const sxsdk::vec4& p) = 0; // 142
	virtual float shader_pnoise11 (float x, float period) = 0; // 143
	virtual float shader_pnoise12 (const sxsdk::vec2& p, const sxsdk::vec2& period) = 0; // 144
	virtual float shader_pnoise13 (const sxsdk::vec3& p, const sxsdk::vec3& period) = 0; // 145
	virtual float shader_pnoise14 (const sxsdk::vec4& p, const sxsdk::vec4& period) = 0; // 146
	virtual sxsdk::vec2 shader_pnoise21 (float x, float period) = 0; // 147
	virtual sxsdk::vec2 shader_pnoise22 (const sxsdk::vec2& p, const sxsdk::vec2& period) = 0; // 148
	virtual sxsdk::vec2 shader_pnoise23 (const sxsdk::vec3& p, const sxsdk::vec3& period) = 0; // 149
	virtual sxsdk::vec2 shader_pnoise24 (const sxsdk::vec4& p, const sxsdk::vec4& period) = 0; // 150
	virtual sxsdk::vec3 shader_pnoise31 (float x, float period) = 0; // 151
	virtual sxsdk::vec3 shader_pnoise32 (const sxsdk::vec2& p, const sxsdk::vec2& period) = 0; // 152
	virtual sxsdk::vec3 shader_pnoise33 (const sxsdk::vec3& p, const sxsdk::vec3& period) = 0; // 153
	virtual sxsdk::vec3 shader_pnoise34 (const sxsdk::vec4& p, const sxsdk::vec4& period) = 0; // 154
	virtual sxsdk::vec4 shader_pnoise41 (float x, float period) = 0; // 155
	virtual sxsdk::vec4 shader_pnoise42 (const sxsdk::vec2& p, const sxsdk::vec2& period) = 0; // 156
	virtual sxsdk::vec4 shader_pnoise43 (const sxsdk::vec3& p, const sxsdk::vec3& period) = 0; // 157
	virtual sxsdk::vec4 shader_pnoise44 (const sxsdk::vec4& p, const sxsdk::vec4& period) = 0; // 158
	virtual void control_set_handler_obsolete (xshade::control::control_class& control, unknown_interface& handler) { control_set_handler(control , handler , 0); } // 159
	virtual void mousetracker_set_handler (sx::mouse_tracker_class& m, unknown_interface& handler) = 0; // 160
	virtual void window_delete_self (sxsdk::window_interface& w) = 0; // 161
	virtual int get_current_time ( 
			 ) = 0; // 162
	virtual sxsdk::stream_interface* shader_get_stream_interface ( 
			 ) = 0; // 163
	virtual sx::rectangle_class window_get_client_rectangle (const window_interface& w, bool include_scroll_bars) = 0; // 164
	virtual void window_set_client_size (sxsdk::window_interface& w, sx::vec<int,2> size) = 0; // 165
	virtual void window_reset_control_position (sxsdk::window_interface& w) = 0; // 166
	virtual sx::vec<int,2> window_get_scroll_position (const window_interface& w) = 0; // 167
	virtual void window_set_scroll_position (sxsdk::window_interface& w, sx::vec<int,2> position) = 0; // 168
	virtual int shader_get_projection ( 
			 ) = 0; // 169
	virtual bool shader_has_uv ( 
			 ) = 0; // 170
	virtual bool shader_has_st ( 
			 ) = 0; // 171
	virtual bool shader_has_tangents ( 
			 ) = 0; // 172
	virtual void control_set_handler (xshade::control::control_class& control, unknown_interface& handler, int plugin_id) = 0; // 173
	virtual sx::rectangle_class window_get_frame_rectangle (const window_interface& w) = 0; // 174
	virtual sxsdk::rgb_class get_highlight_color ( 
			 ) = 0; // 175
	virtual sxsdk::rgb_class get_face_color ( 
			 ) = 0; // 176
	virtual sxsdk::rgb_class get_shadow_color ( 
			 ) = 0; // 177
	virtual sxsdk::rgb_class get_text_color ( 
			 ) = 0; // 178
	virtual sxsdk::rgb_class get_graytext_color ( 
			 ) = 0; // 179
	virtual sxsdk::rgb_class get_selected_color ( 
			 ) = 0; // 180
	virtual sxsdk::rgb_class get_selectedtext_color ( 
			 ) = 0; // 181
	virtual void window_set_number_integer (sxsdk::window_interface& w, plugin_number_class& c) = 0; // 182
	virtual void window_set_number_columns (sxsdk::window_interface& w, plugin_number_class& c, int i) = 0; // 183
	virtual void window_set_slider_integer (sxsdk::window_interface& w, plugin_slider_class& c) = 0; // 184
	virtual void window_set_slider_columns (sxsdk::window_interface& w, plugin_slider_class& c, int i) = 0; // 185
	virtual const char* get_exception_string () const = 0; // 186
	virtual plugin_disclosure_button_class& window_create_disclosure_button (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, bool reversed) = 0; // 187
	virtual void window_set_disclosure_button_int_value (sxsdk::window_interface& w, plugin_disclosure_button_class& c, int i) = 0; // 188
	virtual int window_get_disclosure_button_int_value (sxsdk::window_interface& w, plugin_disclosure_button_class& c) = 0; // 189
	virtual plugin_number_class& window_create_number (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 190
	virtual void window_set_number_fraction (sxsdk::window_interface& w, plugin_number_class& c, int fraction) = 0; // 191
	virtual void window_set_number_format_obsolete (sxsdk::window_interface& w, plugin_number_class& c, const char* format) = 0; // 192
	virtual void window_activate (sxsdk::window_interface& w) = 0; // 193
	virtual void window_deactivate (sxsdk::window_interface& w) = 0; // 194
	virtual void window_drag_file (sxsdk::window_interface& w, const char* path) = 0; // 195
	virtual plugin_tab_class& window_create_tab (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 196
	virtual void window_set_tab_int_value (sxsdk::window_interface& w, plugin_tab_class& c, int i) = 0; // 197
	virtual int window_get_tab_int_value (sxsdk::window_interface& w, plugin_tab_class& c) = 0; // 198
	virtual void window_push_anchor_control (sxsdk::window_interface& w) = 0; // 199
	virtual void window_pop_anchor_control (sxsdk::window_interface& w) = 0; // 200
	virtual sxsdk::image_interface* window_get_image_interface (sxsdk::window_interface& w) = 0; // 201
	virtual int control_get_title_width (xshade::control::control_class& c) = 0; // 202
	virtual void window_set_minimum_size (sxsdk::window_interface& w, sx::vec<int,2> size) = 0; // 203
	virtual void window_set_maximum_size (sxsdk::window_interface& w, sx::vec<int,2> size) = 0; // 204
	virtual void* window_get_native_window (sxsdk::window_interface& w) = 0; // 205
	virtual float window_get_horizontal_line_scroll (const window_interface& w) = 0; // 206
	virtual void window_set_horizontal_line_scroll (sxsdk::window_interface& w, float s) = 0; // 207
	virtual float window_get_vertical_line_scroll (const window_interface& w) = 0; // 208
	virtual void window_set_vertical_line_scroll (sxsdk::window_interface& w, float s) = 0; // 209
	virtual float window_get_horizontal_page_scroll (const window_interface& w) = 0; // 210
	virtual void window_set_horizontal_page_scroll (sxsdk::window_interface& w, float s) = 0; // 211
	virtual float window_get_vertical_page_scroll (const window_interface& w) = 0; // 212
	virtual void window_set_vertical_page_scroll (sxsdk::window_interface& w, float s) = 0; // 213
	virtual void window_set_tab_lazy (sxsdk::window_interface& w, plugin_tab_class& c, bool lazy) = 0; // 214
	virtual bool window_get_tab_lazy (sxsdk::window_interface& w, plugin_tab_class& c) = 0; // 215
	virtual sx::vec<int,2> window_get_canvas_size (const window_interface& w) = 0; // 216
	virtual sx::vec<int,2> window_get_client_size (const window_interface& w) = 0; // 217
	virtual image_view_interface* view_get_image_view_interface () = 0; // 218
	virtual tool_box_view_interface* view_get_tool_box_view_interface () = 0; // 219
	virtual color_view_interface* view_get_color_view_interface () = 0; // 220
	virtual background_view_interface* view_get_background_view_interface () = 0; // 221
	virtual surface_view_interface* view_get_surface_view_interface () = 0; // 222
	virtual browser_view_interface* view_get_browser_view_interface () = 0; // 223
	virtual correction_view_interface* view_get_correction_view_interface () = 0; // 224
	virtual camera_view_interface* view_get_camera_view_interface () = 0; // 225
	virtual distant_light_view_interface* view_get_distant_light_view_interface () = 0; // 226
	virtual ruler_view_interface* view_get_ruler_view_interface () = 0; // 227
	virtual message_view_interface* view_get_message_view_interface () = 0; // 228
	virtual script_view_interface* view_get_script_view_interface () = 0; // 229
	virtual shortcut_view_interface* view_get_shortcut_view_interface () = 0; // 230
	virtual radiosity_view_interface* view_get_radiosity_view_interface () = 0; // 231
	virtual skin_view_interface* view_get_skin_view_interface () = 0; // 232
	virtual motion_view_interface* view_get_motion_view_interface () = 0; // 233
	virtual int implementation_interface_dummy234(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 234
	virtual int implementation_interface_dummy235(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 235
	virtual object_info_view_interface* view_get_object_info_view_interface () = 0; // 236
	virtual aggregate_view_interface* view_get_aggregate_view_interface () = 0; // 237
	virtual rendering_options_view_interface* view_get_rendering_options_view_interface () = 0; // 238
	virtual radiosity_options_view_interface* view_get_radiosity_options_view_interface () = 0; // 239
	virtual void window_set_number_double_value (sxsdk::window_interface& w, plugin_number_class& c, double d) = 0; // 240
	virtual double window_get_number_double_value (sxsdk::window_interface& w, plugin_number_class& c) = 0; // 241
	virtual void window_set_number_min (sxsdk::window_interface& w, plugin_number_class& c, double min) = 0; // 242
	virtual void window_set_number_max (sxsdk::window_interface& w, plugin_number_class& c, double max) = 0; // 243
	virtual sxsdk::vec3 euler_from_quaternion (const sxsdk::quaternion_class& quaternion) = 0; // 244
	virtual sxsdk::quaternion_class quaternion_from_euler (const sxsdk::vec3& euler) = 0; // 245
	virtual sxsdk::vec4 make_plane_equation (int n, const sxsdk::vec3* p) = 0; // 246
	virtual xshade::window_class* window_new_dialog_item (sxsdk::window_interface& wi, sxsdk::dialog_interface& dialog, dialog_item_class& item, int flags) = 0; // 247
	virtual sxsdk::image_interface* create_image_interface (const sx::vec<int,2>& size, int depth) = 0; // 248
	virtual sxsdk::image_interface* create_image_interface_from_file (const char* path) = 0; // 249
	virtual const char* gettext (const char* message) = 0; // 250
	virtual float shader_turbulence1 (const sxsdk::vec3& p, int m) = 0; // 251
	virtual sxsdk::vec2 shader_turbulence2 (const sxsdk::vec3& p, int m) = 0; // 252
	virtual sxsdk::vec3 shader_turbulence3 (const sxsdk::vec3& p, int m) = 0; // 253
	virtual sxsdk::vec4 shader_turbulence4 (const sxsdk::vec3& p, int m) = 0; // 254
	virtual void window_load_sxul (sxsdk::window_interface& w, const char* sxul) = 0; // 255
	virtual const char* window_get_control_idname (sxsdk::window_interface& w, xshade::control::control_class& c) = 0; // 256
	virtual plugin_vec2_control_class& window_create_vec2_control (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 257
	virtual void window_set_vec2_control_value (sxsdk::window_interface& w, plugin_vec2_control_class& c, const sxsdk::vec2& v) = 0; // 258
	virtual sxsdk::vec2 window_get_vec2_control_value (sxsdk::window_interface& w, plugin_vec2_control_class& c) = 0; // 259
	virtual plugin_vec3_control_class& window_create_vec3_control (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 260
	virtual void window_set_vec3_control_value (sxsdk::window_interface& w, plugin_vec3_control_class& c, const sxsdk::vec3& v) = 0; // 261
	virtual sxsdk::vec3 window_get_vec3_control_value (sxsdk::window_interface& w, plugin_vec3_control_class& c) = 0; // 262
	virtual plugin_vec4_control_class& window_create_vec4_control (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 263
	virtual void window_set_vec4_control_value (sxsdk::window_interface& w, plugin_vec4_control_class& c, const sxsdk::vec4& v) = 0; // 264
	virtual sxsdk::vec4 window_get_vec4_control_value (sxsdk::window_interface& w, plugin_vec4_control_class& c) = 0; // 265
	virtual plugin_quaternion_control_class& window_create_quaternion_control (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 266
	virtual void window_set_quaternion_control_value (sxsdk::window_interface& w, plugin_quaternion_control_class& c, const sxsdk::quaternion_class& v) = 0; // 267
	virtual sxsdk::quaternion_class window_get_quaternion_control_value (sxsdk::window_interface& w, plugin_quaternion_control_class& c) = 0; // 268
	virtual plugin_matrix_control_class& window_create_matrix_control (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title) = 0; // 269
	virtual void window_set_matrix_control_value (sxsdk::window_interface& w, plugin_matrix_control_class& c, const sxsdk::mat4& v) = 0; // 270
	virtual sxsdk::mat4 window_get_matrix_control_value (sxsdk::window_interface& w, plugin_matrix_control_class& c) = 0; // 271
	virtual plugin_scale_control_class& window_create_scale_control (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, const char* title) = 0; // 272
	virtual void window_set_scale_control_value (sxsdk::window_interface& w, plugin_scale_control_class& c, int s) = 0; // 273
	virtual int window_get_scale_control_value (sxsdk::window_interface& w, plugin_scale_control_class& c) = 0; // 274
	virtual plugin_flasher_class& window_create_flasher (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy) = 0; // 275
	virtual void window_set_trigger (sxsdk::window_interface& w, enums::trigger_enum trigger) = 0; // 276
	virtual sxsdk::image_interface* create_image_interface_from_resource (const char* name) = 0; // 277
	virtual void control_set_handler_with_uuid (xshade::control::control_class& control, unknown_interface& handler, const sx::uuid_class& plugin_id) = 0; // 278
	virtual void window_pump (sxsdk::window_interface& w) = 0; // 279
	virtual void window_paintself (sxsdk::window_interface& w) = 0; // 280
	virtual void pump () = 0; // 281
	virtual void idle (int duration) = 0; // 282
	virtual bool window_key_down (sxsdk::window_interface& w, int code, int flags) = 0; // 283
	virtual sx::rectangle_class window_get_layout_bounds (const window_interface& w) = 0; // 284
	virtual sx::rectangle_class uniscale_rectangle (const sx::rectangle_class& destination, const sx::rectangle_class& source) = 0; // 285
	virtual void window_begin_opengl (sxsdk::window_interface& w) = 0; // 286
	virtual void window_end_opengl (sxsdk::window_interface& w) = 0; // 287
	virtual int create_mouse_cursor_from_resource (const char* name, const sx::vec<int,2>& hotspot) = 0; // 288
	virtual void set_mouse_cursor (int index) = 0; // 289
	virtual bool window_scroll_wheel (sxsdk::window_interface& w, const sxsdk::vec2& delta_, sx::vec<int,2> p, int key_down) = 0; // 290
	virtual renderingservice_interface* interface_get_renderingservice_interface () = 0; // 291
	virtual bool is_key_down (int key_code) = 0; // 292
	virtual sxsdk::rgb_class get_theme_color (int flags) = 0; // 293
	virtual plugin_table_control_class& window_create_table_control (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy) = 0; // 294
	virtual void window_insert_table_column (sxsdk::window_interface& w, plugin_table_control_class& c, int type, int width, const char* label, int col) = 0; // 295
	virtual void window_remove_table_column (sxsdk::window_interface& w, plugin_table_control_class& c, int col) = 0; // 296
	virtual void window_insert_table_row (sxsdk::window_interface& w, plugin_table_control_class& c, int row) = 0; // 297
	virtual void window_remove_table_row (sxsdk::window_interface& w, plugin_table_control_class& c, int row) = 0; // 298
	virtual void window_clear_table (sxsdk::window_interface& w, plugin_table_control_class& c) = 0; // 299
	virtual void window_set_table_bool_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col, bool value) = 0; // 300
	virtual void window_set_table_int_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col, int value) = 0; // 301
	virtual void window_set_table_float_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col, float value) = 0; // 302
	virtual void window_set_table_string_value_deprecated (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col, const std::string &value) = 0; // 303
	virtual void window_set_table_color_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col, const sxsdk::rgb_class &value) = 0; // 304
	virtual bool window_get_table_bool_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col) = 0; // 305
	virtual int window_get_table_int_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col) = 0; // 306
	virtual float window_get_table_float_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col) = 0; // 307
	virtual std::string window_get_table_string_value_deprecated (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col) = 0; // 308
	virtual sxsdk::rgb_class window_get_table_color_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col) = 0; // 309
	virtual void set_tiled_logo (bool flag, void * aux) = 0; // 310
	virtual void window_set_cursor (sxsdk::window_interface& w, int cursor_index) = 0; // 311
	virtual const char* get_note () = 0; // 312
	virtual int check_serial_number (const char* serial) = 0; // 313
	virtual bool is_licensed (const char* product_name) = 0; // 314
	virtual bool add_license (const char* product_name, const char* serial) = 0; // 315
	virtual bool remove_license (const char* product_name) = 0; // 316
	virtual int get_string_height () = 0; // 317
	virtual bool is_japanese_build () = 0; // 318
	virtual bool is_english_build () = 0; // 319
	virtual bool is_simplified_chinese_build () = 0; // 320
	virtual bool is_french_build () = 0; // 321
	virtual void plugin_registration (const char* serial) = 0; // 322
	virtual std::size_t get_used_memory () = 0; // 323
	virtual std::size_t get_max_used_memory () = 0; // 324
	virtual void reset_max_used_memory () = 0; // 325
	virtual void initialize_library () = 0; // 326
	virtual sxsdk::stream_interface* create_stdio_stream_interface () = 0; // 327
	virtual sxsdk::scene_interface* create_scene_interface (enums::preset_scene_enum scene_type) = 0; // 328
	virtual void* shader_get_vertexdata (int index) = 0; // 329
	virtual meshtools_view_interface* view_get_meshtools_view_interface () = 0; // 330
	virtual meshtools_window_interface* view_get_meshtools_window_interface () = 0; // 331
	virtual void set_meshtools_window_shown (bool b) = 0; // 332
	virtual bool get_meshtools_window_shown () = 0; // 333
	virtual void set_shadeexplorer_window_shown (bool b) = 0; // 334
	virtual bool get_shadeexplorer_window_shown () = 0; // 335
	virtual void set_aggregate_window_shown (bool b) = 0; // 336
	virtual bool get_aggregate_window_shown () = 0; // 337
	virtual bool is_traditional_chinese_mode () = 0; // 338
	virtual bool is_traditional_chinese_build () = 0; // 339
	virtual void finalize_library () = 0; // 340
	virtual custom_element_info_base_class* shader_get_custom_element_info () = 0; // 341
	virtual custom_element_info_base_class* shader_get_custom_element_per_thread_info () = 0; // 342
	virtual int shader_get_intersection_number () = 0; // 343
	virtual int implementation_interface_dummy344(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 344
	virtual int implementation_interface_dummy345(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 345
	virtual int implementation_interface_dummy346(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 346
	virtual void window_obsolete (sxsdk::window_interface& w) = 0; // 347
	virtual const char* get_commit () = 0; // 348
	virtual const char* open_database () = 0; // 349
	virtual void close_database (const char* dbid) = 0; // 350
	virtual bool is_database (const char* stmtid) = 0; // 351
	virtual int database_execute (const char* dbid, const char* sql) = 0; // 352
	virtual const char* database_resultText (const char* dbid) = 0; // 353
	virtual const char* database_statement (const char* dbid, const char* sql) = 0; // 354
	virtual bool is_database_statement (const char* stmtid) = 0; // 355
	virtual const char* database_laseError (const char* dbid) = 0; // 356
	virtual int database_errorCode (const char* dbid) = 0; // 357
	virtual int database_statement_step (const char* stmtid) = 0; // 358
	virtual int database_statement_reset (const char* stmtid) = 0; // 359
	virtual int database_statement_finalize (const char* stmtid) = 0; // 360
	virtual int database_statement_bind_int (const char* stmtid, int index, int iValue) = 0; // 361
	virtual int database_statement_bind_string (const char* stmtid, int index, const char* text) = 0; // 362
	virtual int database_statement_bind_double (const char* stmtid, int index, double rValue) = 0; // 363
	virtual int database_statement_bind_blob (const char* stmtid, int index, const void* data, int n) = 0; // 364
	virtual int database_statement_bind_null (const char* stmtid, int index) = 0; // 365
	virtual int database_statement_dataType (const char* stmtid, int index) = 0; // 366
	virtual int database_statement_intValue (const char* stmtid, int index) = 0; // 367
	virtual double database_statement_doubleValue (const char* stmtid, int index) = 0; // 368
	virtual const char* database_statement_stringValue (const char* stmtid, int index) = 0; // 369
	virtual const void* database_statement_blob (const char* stmtid, int index) = 0; // 370
	virtual int database_statement_byts (const char* stmtid, int index) = 0; // 371
	virtual bool database_statement_nextRow (const char* stmtid) = 0; // 372
	virtual int get_tag_intValue (sxsdk::shape_class& shape, const char* tagName) = 0; // 373
	virtual double get_tag_doubleValue (sxsdk::shape_class& shape, const char* tagName) = 0; // 374
	virtual float get_tag_floatValue (sxsdk::shape_class& shape, const char* tagName) = 0; // 375
	virtual const char* get_tag_stringValue (sxsdk::shape_class& shape, const char* tagName) = 0; // 376
	virtual bool get_tag_boolValue (sxsdk::shape_class& shape, const char* tagName) = 0; // 377
	virtual void set_tag_intValue (sxsdk::shape_class& shape, const char* tagName, int value) = 0; // 378
	virtual void set_tag_doubleValue (sxsdk::shape_class& shape, const char* tagName, double value) = 0; // 379
	virtual void set_tag_floatValue (sxsdk::shape_class& shape, const char* tagName, float value) = 0; // 380
	virtual void set_tag_stringValue (sxsdk::shape_class& shape, const char* tagName, const char* value) = 0; // 381
	virtual void set_tag_boolValue (sxsdk::shape_class& shape, const char* tagName, bool value) = 0; // 382
	virtual int tag_value_type (sxsdk::shape_class& shape, const char* tagName) = 0; // 383
	virtual std::vector<const char*> tags (sxsdk::shape_class& shape) = 0; // 384
	virtual bool has_tag (sxsdk::shape_class& shape, const char* tagName) = 0; // 385
	virtual void remove_tag (sxsdk::shape_class& shape, const char* tagName) = 0; // 386
	virtual const sx::uuid_class uuid (const sxsdk::shape_class& shape) = 0; // 387
	virtual bool is_speed_build () = 0; // 388
	virtual sxsdk::polygon_mesh_interface * create_converted_polygon_mesh_interface (const sxsdk::shape_class& shape, int level, int texture, bool triangulate, bool divide) = 0; // 389
	virtual sxsdk::mat4 get_sequence_transformation (const sxsdk::shape_class& shape, float sequence_value) = 0; // 390
	virtual sxsdk::mat4 get_sequence_joint_matrix (const sxsdk::shape_class& shape, float sequence_value) = 0; // 391
	virtual sxsdk::mat4 get_sequence_local_to_world_matrix (const sxsdk::shape_class& shape, float sequence_value) = 0; // 392
	virtual sxsdk::mat4 get_sequence_world_to_local_matrix (const sxsdk::shape_class& shape, float sequence_value) = 0; // 393
	virtual sxsdk::shape_class& do_manifold_boolean (sxsdk::shape_class& target_shape, sxsdk::shape_class& src_shape, sxsdk::smlib::boolean_operation_type bo_type, int& err) = 0; // 394
	virtual sxsdk::shape_class& do_manifold_boolean_with_n (sxsdk::shape_class& target_shape, const std::vector<shape_class*>& src_shapes, sxsdk::smlib::boolean_operation_type bo_type, int& err) = 0; // 395
	virtual sxsdk::polygon_mesh_interface * create_boolean_polygon_mesh_interface (sxsdk::shape_class& target_shape, sxsdk::shape_class& src_shape, sxsdk::smlib::boolean_operation_type bo_type) = 0; // 396
	virtual sxsdk::exporter_settings_interface * create_exporter_settings_interface (const sx::uuid_class& exporter_id) = 0; // 397
	virtual sxsdk::points_interface * create_converted_polyline_points_interface (sxsdk::shape_class& shape, int level) = 0; // 398
	virtual bool is_path_replicator (const sxsdk::shape_class& shape) = 0; // 399
	virtual void purge_images () = 0; // 400
	virtual void window_load_sxul_stream (sxsdk::window_interface& w, sxsdk::stream_interface& stream) = 0; // 401
	virtual sxsdk::stream_interface* create_fixed_memory_stream_interface (void* memory, std::size_t size) = 0; // 402
	virtual sxsdk::stream_interface* create_memory_stream_interface () = 0; // 403
	virtual int get_build_date () = 0; // 404
	virtual int get_bits () = 0; // 405
	virtual const char* get_processor () = 0; // 406
	virtual void window_set_table_style (sxsdk::window_interface& w, plugin_table_control_class& c, int mode) = 0; // 407
	virtual int window_get_table_style (sxsdk::window_interface& w, plugin_table_control_class& c) = 0; // 408
	virtual void window_select_table_item (sxsdk::window_interface& w, plugin_table_control_class& c, int row) = 0; // 409
	virtual void window_select_all_table_items (sxsdk::window_interface& w, plugin_table_control_class& c, bool b) = 0; // 410
	virtual int window_number_of_selected_table_items (sxsdk::window_interface& w, plugin_table_control_class& c) = 0; // 411
	virtual int window_get_first_selected_table_item (sxsdk::window_interface& w, plugin_table_control_class& c) = 0; // 412
	virtual int window_get_next_selected_table_item (sxsdk::window_interface& w, plugin_table_control_class& c, int i) = 0; // 413
	virtual bool window_table_has_selection (sxsdk::window_interface& w, plugin_table_control_class& c) = 0; // 414
	virtual void window_check_all_table_items (sxsdk::window_interface& w, plugin_table_control_class& c, int col, bool b) = 0; // 415
	virtual int window_get_first_checked_table_item (sxsdk::window_interface& w, plugin_table_control_class& c, int col) = 0; // 416
	virtual int window_get_next_checked_table_item (sxsdk::window_interface& w, plugin_table_control_class& c, int col, int i) = 0; // 417
	virtual bool window_table_item_has_check (sxsdk::window_interface& w, plugin_table_control_class& c, int col) = 0; // 418
	virtual bool window_get_table_item_selected (sxsdk::window_interface& w, plugin_table_control_class& c, int row) = 0; // 419
	virtual void window_set_table_item_selected (sxsdk::window_interface& w, plugin_table_control_class& c, int row, bool b) = 0; // 420
	virtual bool window_get_table_item_active (sxsdk::window_interface& w, plugin_table_control_class& c, int row) = 0; // 421
	virtual void window_set_table_item_active (sxsdk::window_interface& w, plugin_table_control_class& c, int row, bool b) = 0; // 422
	virtual bool window_get_table_cell_active (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col) = 0; // 423
	virtual void window_set_table_cell_active (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col, bool b) = 0; // 424
	virtual int window_get_number_of_table_rows (sxsdk::window_interface& w, plugin_table_control_class& c) = 0; // 425
	virtual int window_get_number_of_table_columns (sxsdk::window_interface& w, plugin_table_control_class& c) = 0; // 426
	virtual sxsdk::path_replicator_interface* get_path_replicator_interface (const sxsdk::shape_class& shape) = 0; // 427
	virtual const char* get_shadeexplorer_data_path () = 0; // 428
	virtual plugin_number_class& window_create_number_with_unit (sxsdk::window_interface& w, handler_interface& handler, int control_id, int x, int y, int dx, int dy, const char* title, const char* unit) = 0; // 429
	virtual bool open_backup (const char * file_path, const char * output_folder, int flags) = 0; // 430
	virtual void window_set_table_string_value (sxsdk::window_interface& w, plugin_table_control_class& c, int row, int col, const char* value) = 0; // 431
	virtual const char* window_get_table_string_value (window_interface& w, plugin_table_control_class& c, int row, int col) = 0; // 432
	virtual int get_numof_file_paths () = 0; // 433
	virtual sxsdk::image_interface* create_image_interface_from_index (int file_index) = 0; // 434
	virtual void set_bounding_box_size (sxsdk::shape_class& shape, sxsdk::vec3 bounding_box_size) = 0; // 435
	virtual sxsdk::vec3 get_bounding_box_size (const sxsdk::shape_class& shape) const = 0; // 436
	virtual plugin_editable_text_class& window_create_editable_text (sxsdk::window_interface& w, handler_interface& hanlder, int control_id, int x, int y, int dx, int dy, const char * title) = 0; // 437
	virtual void window_set_editable_text_string_value (sxsdk::window_interface& w, plugin_editable_text_class& c, const char * s) = 0; // 438
	virtual const char * window_get_editable_text_string_value (sxsdk::window_interface& w, plugin_editable_text_class& c) = 0; // 439
	virtual sxsdk::surface_class& get_surface_reference (const sxsdk::shape_class& shape) const = 0; // 440
	virtual void set_bounding_box_center (sxsdk::shape_class& shape, sxsdk::vec3 cemter_position) = 0; // 441
	virtual sxsdk::vec3 get_bounding_box_center (const sxsdk::shape_class& shape) const = 0; // 442
	virtual void set_active_vertex_indices (sxsdk::shape_class& shape, int n, int * indices) = 0; // 443
	virtual int get_active_vertex_indices (const sxsdk::shape_class& shape, int * indices) const = 0; // 444
	virtual const char * get_version_info () const = 0; // 445
	virtual void update_skin_bindings (sxsdk::shape_class& shape) = 0; // 446
	virtual void virtual_query () = 0; // 447
	virtual bool control_get_active (xshade::control::control_class& control) = 0; // 448
	virtual int control_get_focused (xshade::control::control_class& control) = 0; // 449
	virtual int implementation_interface_dummy450(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 450
	virtual int implementation_interface_dummy451(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 451
	virtual int implementation_interface_dummy452(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 452
	virtual int implementation_interface_dummy453(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 453
	virtual int implementation_interface_dummy454(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 454
	virtual int implementation_interface_dummy455(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 455
	virtual int implementation_interface_dummy456(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 456
	virtual int implementation_interface_dummy457(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 457
	virtual int implementation_interface_dummy458(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 458
	virtual int implementation_interface_dummy459(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 459
	virtual int implementation_interface_dummy460(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 460
	virtual int implementation_interface_dummy461(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 461
	virtual int implementation_interface_dummy462(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 462
	virtual int implementation_interface_dummy463(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 463
	virtual int implementation_interface_dummy464(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 464
	virtual int implementation_interface_dummy465(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 465
	virtual int implementation_interface_dummy466(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 466
	virtual int implementation_interface_dummy467(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 467
	virtual int implementation_interface_dummy468(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 468
	virtual int implementation_interface_dummy469(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 469
	virtual int implementation_interface_dummy470(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 470
	virtual int implementation_interface_dummy471(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 471
	virtual int implementation_interface_dummy472(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 472
	virtual int implementation_interface_dummy473(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 473
	virtual int implementation_interface_dummy474(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 474
	virtual int implementation_interface_dummy475(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 475
	virtual int implementation_interface_dummy476(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 476
	virtual int implementation_interface_dummy477(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 477
	virtual int implementation_interface_dummy478(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 478
	virtual int implementation_interface_dummy479(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 479
	virtual int implementation_interface_dummy480(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 480
	virtual int implementation_interface_dummy481(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 481
	virtual int implementation_interface_dummy482(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 482
	virtual int implementation_interface_dummy483(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 483
	virtual int implementation_interface_dummy484(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 484
	virtual int implementation_interface_dummy485(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 485
	virtual int implementation_interface_dummy486(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 486
	virtual int implementation_interface_dummy487(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 487
	virtual int implementation_interface_dummy488(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 488
	virtual int implementation_interface_dummy489(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 489
	virtual int implementation_interface_dummy490(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 490
	virtual int implementation_interface_dummy491(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 491
	virtual int implementation_interface_dummy492(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 492
	virtual int implementation_interface_dummy493(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 493
	virtual int implementation_interface_dummy494(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 494
	virtual int implementation_interface_dummy495(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 495
	virtual int implementation_interface_dummy496(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 496
	virtual int implementation_interface_dummy497(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 497
	virtual int implementation_interface_dummy498(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 498
	virtual int implementation_interface_dummy499(void *) { assert(false); throw "invalid interface implementation_interface"; return 0; } // 499
	virtual void set_ambient_color (sxsdk::shape_class& shape_, const sxsdk::rgb_class& control) = 0; // 500
	virtual sxsdk::rgb_class get_ambient_color (sxsdk::shape_class& shape_) = 0; // 501
	virtual sxsdk::shape_class & set_ambient_value (sxsdk::shape_class& shape_, float f) = 0; // 502
	virtual float get_ambient_value (sxsdk::shape_class& shape_) = 0; // 503
	virtual sxsdk::texture_interface* create_texture_interface2 (sxsdk::shape_class& shape_, int self = 0, const sxsdk::vec3& point = sxsdk::vec3(0.0f,0.0f,0.0f), const sxsdk::vec3& shading_normal = sxsdk::vec3(0.0f,1.0f,0.0f), const sxsdk::vec3& geometric_normal = sxsdk::vec3(0.0f,1.0f,0.0f), const sxsdk::vec3& incident = sxsdk::vec3(0.0f,0.0f,-1.0f), const sxsdk::vec2* uv = 0, const sxsdk::vec3* du = 0, const sxsdk::vec3* dv = 0, int n_uvs = 0, const sxsdk::vec2* uvs = 0, sxsdk::master_surface_class* master_surface = 0) = 0; // 504
	};
}
