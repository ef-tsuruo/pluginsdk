#pragma once

namespace sxsdk {
	class scene_interface : public shade_interface {
	public:
	virtual sxsdk::rendering_interface* get_rendering_interface (void * = 0) const = 0; // 0
	virtual camera_interface* get_camera_interface (void * = 0) const = 0; // 1
	virtual sxsdk::distant_light_interface* get_distant_light_interface (void * = 0) const = 0; // 2
	virtual sxsdk::background_interface* get_background_interface (void * = 0) const = 0; // 3
	virtual sxsdk::correction_interface* get_correction_interface (void * = 0) const = 0; // 4
	virtual shape_interface* get_shape_interface (void* aux = 0) = 0; // 5
	virtual void close_scene (bool save = true, void* aux = 0) = 0; // 6
	virtual void cut (void* aux = 0) = 0; // 7
	virtual void copy (void* aux = 0) = 0; // 8
	virtual void paste (void* aux = 0) = 0; // 9
	virtual void clear (void* aux = 0) = 0; // 10
	virtual void select_all (void* aux = 0) = 0; // 11
	virtual void begin_creating (void* aux = 0) = 0; // 12
	virtual void end_creating (void* aux = 0) = 0; // 13
	virtual sphere_class& create_sphere (const char* as, const sxsdk::vec3& at, float r, void* aux = 0) = 0; // 14
	virtual disk_class& create_disk (const char* as, const sxsdk::vec3& at, float r, int axis, void* aux = 0) = 0; // 15
	virtual light_class& create_point_light (const char* as, const sxsdk::vec3& at, float r, void* aux = 0) = 0; // 16
	virtual light_class& create_spotlight (const char* as, const sxsdk::vec3& from, const sxsdk::vec3& to, float intensity, void* aux = 0) = 0; // 17
	virtual sxsdk::master_surface_class& create_master_surface (const char* as, void* aux = 0) = 0; // 18
	virtual line_class& begin_line (const char* as, bool closed = true, void* aux = 0) = 0; // 19
		line_class& begin_polygon (const char* as, bool closed = true, void* aux = 0) { return begin_line(as, closed); }
	virtual void append_point (const sxsdk::vec3& at, const sxsdk::vec3* in = 0, const sxsdk::vec3* out = 0, const sxsdk::vec3* lateral_in = 0, const sxsdk::vec3* lateral_out = 0, void* aux = 0) = 0; // 20
	virtual void end_line (void* aux = 0) = 0; // 21
		void end_polygon (void* aux = 0) { end_line(); }
	virtual line_class& begin_truetype (const char* as = 0, bool hole = false, void* aux = 0) = 0; // 22
	virtual void append_truetype_point (bool on, float x, float y, float z = 0.0, void* aux = 0) = 0; // 23
	virtual void end_truetype (void* aux = 0) = 0; // 24
	virtual part_class& begin_part (const char* as = 0, void* aux = 0) = 0; // 25
	virtual void end_part (void* aux = 0) = 0; // 26
	virtual part_class& begin_surface_part (const char* as = 0, void* aux = 0) = 0; // 27
	virtual void end_surface_part (void* aux = 0) = 0; // 28
	virtual part_class& begin_rotator_joint (const sxsdk::vec3& from, const sxsdk::vec3& to, const char* as = 0, void* aux = 0) = 0; // 29
	virtual void end_rotator_joint (void* aux = 0) = 0; // 30
	virtual part_class& begin_slider_joint (const sxsdk::vec3& from, const sxsdk::vec3& to, const char* as = 0, void* aux = 0) = 0; // 31
	virtual void end_slider_joint (void* aux = 0) = 0; // 32
	virtual part_class& begin_scale_joint (const sxsdk::vec3& from, const sxsdk::vec3& to, const char* as = 0, void* aux = 0) = 0; // 33
	virtual void end_scale_joint (void* aux = 0) = 0; // 34
	virtual part_class& begin_uniscale_joint (const sxsdk::vec3& at, float r, const char* as = 0, void* aux = 0) = 0; // 35
	virtual void end_uniscale_joint (void* aux = 0) = 0; // 36
	virtual part_class& begin_light_effector (const char* as = 0, void* aux = 0) = 0; // 37
		part_class& begin_light_joint (const char* as = 0, void* aux = 0) { return begin_light_effector(as); }
	virtual void end_light_effector (void* aux = 0) = 0; // 38
		void end_light_joint (void* aux = 0) { end_light_effector(); }
	virtual part_class& begin_path_joint (const char* as = 0, void* aux = 0) = 0; // 39
	virtual void end_path_joint (void* aux = 0) = 0; // 40
	virtual part_class& begin_morph_effector (const char* as = 0, void* aux = 0) = 0; // 41
		part_class& begin_morph_joint (const char* as = 0, void* aux = 0) { return begin_morph_effector(as); }
	virtual void end_morph_effector (void* aux = 0) = 0; // 42
		void end_morph_joint (void* aux = 0) { end_morph_effector(); }
	virtual void move_object (const sxsdk::vec3* around, const sxsdk::vec3* scale, const sxsdk::vec3* rotate, const sxsdk::vec3* translate, void* aux = 0) = 0; // 43
	virtual sxsdk::shape_class& copy_object (const sxsdk::vec3* around, const sxsdk::vec3* scale, const sxsdk::vec3* rotate, const sxsdk::vec3* translate, void* aux = 0) = 0; // 44
	virtual void clear_transformation (void* aux = 0) = 0; // 45
	virtual void repeat (int n = 1, void* aux = 0) = 0; // 46
	virtual void solid_extrude (const sxsdk::vec3& by, void* aux = 0) = 0; // 47
	virtual void solid_revolve (const sxsdk::vec3& v0, const sxsdk::vec3& v1, void* aux = 0) = 0; // 48
	virtual void solid_clear (void* aux = 0) = 0; // 49
	virtual void iron (void* aux = 0) = 0; // 50
	virtual void smooth (void* aux = 0) = 0; // 51
	virtual void unsmooth (void* aux = 0) = 0; // 52
	virtual void degenerate (void* aux = 0) = 0; // 53
	virtual void reverse (void* aux = 0) = 0; // 54
	virtual void switch_ (void* aux = 0) = 0; // 55
	virtual void convert (int* v = 0, void* aux = 0) = 0; // 56
	virtual void round_edge (float by, void* aux = 0) = 0; // 57
	virtual void bevel_edge (float by, void* aux = 0) = 0; // 58
	virtual void place_parent (int by, void* aux = 0) = 0; // 59
	virtual void place_child (int at, void* aux = 0) = 0; // 60
	virtual void place_brother (int by, void* aux = 0) = 0; // 61
	virtual void place_sister (int by, void* aux = 0) = 0; // 62
	virtual void place (sxsdk::shape_class* new_bro, void* aux = 0) = 0; // 63
	virtual bool select_obsolete (const char* name, void* aux = 0) = 0; // 64
	virtual bool select_parent (int by = 1, void* aux = 0) = 0; // 65
	virtual bool select_child (int at = 1, void* aux = 0) = 0; // 66
	virtual bool select_brother (int by = 1, void* aux = 0) = 0; // 67
	virtual bool select_sister (int by = 1, void* aux = 0) = 0; // 68
	virtual void select (void* shape_handle, void* aux = 0) = 0; // 69
	virtual int get_number_of_selected_shapes_obsolete (void* aux = 0) = 0; // 70
	virtual shape_interface* get_first_selected_shape_obsolete (void* aux = 0) = 0; // 71
	virtual shape_interface* get_next_selected_shape_obsolete (void* aux = 0) = 0; // 72
	virtual void memory (void* aux = 0) = 0; // 73
	virtual void apply (void* aux = 0) = 0; // 74
	virtual void append (void* aux = 0) = 0; // 75
	virtual void sweep (void* aux = 0) = 0; // 76
	virtual void magnify (const sxsdk::vec3* at = 0, void* aux = 0) = 0; // 77
	virtual void shrink (const sxsdk::vec3* at = 0, void* aux = 0) = 0; // 78
	virtual void scroll (const sxsdk::vec3& to, void* aux = 0) = 0; // 79
	virtual void clear_template (void* aux = 0) = 0; // 80
	virtual void use_local (void* aux = 0) = 0; // 81
	virtual void use_global (void* aux = 0) = 0; // 82
	virtual void write (const char*const& in, void* aux = 0) = 0; // 83
		void save_scene (const char*const& in, void* aux = 0) { write(in); }
	virtual void save_shape (const char*const& in, void* aux = 0) = 0; // 84
	virtual void save_DXF (const char*const& in, const sxsdk::exporter_settings_interface* settings = 0) = 0; // 85
	virtual void save_RIB (const char*const& in, const sxsdk::exporter_settings_interface* settings = 0) = 0; // 86
	virtual void save_lock (const char*const& in, void* aux = 0) = 0; // 87
	virtual void save_text (const char*const& in, void* aux = 0) = 0; // 88
	virtual int scene_interface_dummy89(void *) { assert(false); throw "invalid interface scene_interface"; return 0; } // 89
	virtual void save_VRML (const char*const& in, const sxsdk::exporter_settings_interface* settings = 0) = 0; // 90
	virtual int scene_interface_dummy91(void *) { assert(false); throw "invalid interface scene_interface"; return 0; } // 91
	virtual int scene_interface_dummy92(void *) { assert(false); throw "invalid interface scene_interface"; return 0; } // 92
	virtual void save_Animation_Master (const char*const& in, const sxsdk::exporter_settings_interface* settings = 0) = 0; // 93
	virtual void save_image (const char*const& in, void* aux = 0) = 0; // 94
	virtual void load_shape_deprecated (const char*const& from, const bool* option = 0) = 0; // 95
	virtual void load_DXF (const char*const& from, void* aux = 0) = 0; // 96
	virtual void load_pose (const char*const& from, void* aux = 0) = 0; // 97
	virtual void load_mapping_image (const char*const& from, void* aux = 0) = 0; // 98
	virtual void load_background_image (enums::background_part part, int i, const char*const& from, void* aux = 0) = 0; // 99
	virtual void load_image_obsolete (const char*const& from, void* aux = 0) = 0; // 100
	virtual void inhibit_update (void* aux = 0) = 0; // 101
	virtual void allow_update (void* aux = 0) = 0; // 102
	virtual void force_update (void* aux = 0) = 0; // 103
	virtual void hide_active (void* aux = 0) = 0; // 104
	virtual void hide_inactive (void* aux = 0) = 0; // 105
	virtual void show_active (void* aux = 0) = 0; // 106
	virtual void show_all (void* aux = 0) = 0; // 107
	virtual scene_interface &set_unit (sxsdk::enums::unit unit_param, void * = 0) = 0; // 108
	virtual sxsdk::enums::unit get_unit (void * = 0) const = 0; // 109
	virtual scene_interface &set_cursor_position (const sxsdk::vec3 &cursor_position_param, void * = 0) = 0; // 110
	virtual sxsdk::vec3 get_cursor_position (void * = 0) const = 0; // 111
	virtual scene_interface &set_figure_view_mode (int figure_view_mode_param, void * = 0); scene_interface &set_figure_view (int figure_view_mode_param) { return set_figure_view_mode(figure_view_mode_param); }  // 112
	virtual int get_figure_view_mode (void * = 0) const; int get_figure_view() const { return get_figure_view_mode(); }  // 113
	virtual scene_interface &set_snap (bool snap_param, void * = 0) = 0; // 114
	virtual bool get_snap (void * = 0) const = 0; // 115
	virtual scene_interface &set_grid (bool grid_param, void * = 0) = 0; // 116
	virtual bool get_grid (void * = 0) const = 0; // 117
	virtual scene_interface &set_large_cursor (bool large_cursor_param, void * = 0) = 0; // 118
	virtual bool get_large_cursor (void * = 0) const = 0; // 119
	virtual scene_interface &set_template (bool template_param, void * = 0) = 0; // 120
	virtual bool get_template (void * = 0) const = 0; // 121
	virtual scene_interface &set_color_mode (bool color_mode_param, void * = 0) = 0; // 122
	virtual bool get_color_mode (void * = 0) const = 0; // 123
	virtual sxsdk::mat4 get_user_to_world_matrix (void * = 0) const = 0; // 124
	virtual int get_number_of_active_shapes (void * = 0) const = 0; // 125
	virtual shape_interface* get_active_shape_interface (int i = 0, void* aux = 0) = 0; // 126
		shape_interface* get_active_shape (int i = 0, void* aux = 0) { return get_active_shape_interface(i); }
	virtual shape_interface* get_first_active_shape_interface (void* aux = 0) = 0; // 127
		shape_interface* get_first_active_shape (void* aux = 0) { return get_first_active_shape_interface(); }
	virtual shape_interface* get_next_active_shape_interface (void* aux = 0) = 0; // 128
		shape_interface* get_next_active_shape (void* aux = 0) { return get_next_active_shape_interface(); }
	virtual float get_pixel_size (void * = 0) const = 0; // 129
	virtual float get_default_radius (void * = 0) const = 0; // 130
	virtual part_interface* get_first_master_surface_part_interface (void* aux = 0) = 0; // 131
		part_interface* get_first_master_surface_part (void* aux = 0) { return get_first_master_surface_part_interface(); }
	virtual part_interface* get_next_master_surface_part_interface (void* aux = 0) = 0; // 132
		part_interface* get_next_master_surface_part (void* aux = 0) { return get_next_master_surface_part_interface(); }
	virtual quickrendering_interface* get_quickrendering_interface (void * = 0) const = 0; // 133
	virtual sxsdk::fog_interface* get_fog_interface (void * = 0) const = 0; // 134
	virtual void save_pose (const char*const& in, void* aux = 0) = 0; // 135
	virtual void load_template_image_to_side_view (const char*const& from, void* aux = 0) = 0; // 136
	virtual void load_template_image_to_top_view (const char*const& from, void* aux = 0) = 0; // 137
	virtual void load_template_image_to_front_view (const char*const& from, void* aux = 0) = 0; // 138
	virtual void load_template_image_to_pers_view (const char*const& from, void* aux = 0) = 0; // 139
	virtual void load_template_image_to_all_views (const char*const& from, void* aux = 0) = 0; // 140
	virtual void load_backdrop_image (const char*const& from, void* aux = 0) = 0; // 141
	virtual scene_interface &set_backdrop (bool backdrop_param, void * = 0) = 0; // 142
	virtual bool get_backdrop (void * = 0) const = 0; // 143
	virtual void save_mapping_image (const char*const& to, void* aux = 0) = 0; // 144
	virtual void save_background_image (enums::background_part part, int i, const char*const& path, void* aux = 0) = 0; // 145
	virtual void save_backdrop_image (const char*const& to, void* aux = 0) = 0; // 146
	virtual void merge_backdrop (const char*const& , void* aux = 0) = 0; // 147
	virtual void revert (void* aux = 0) = 0; // 148
	virtual float get_native_to_user_unit (void * = 0) const = 0; // 149
	virtual float get_user_to_native_unit (void * = 0) const = 0; // 150
	virtual sxsdk::mat4 get_world_to_user_matrix (void * = 0) const = 0; // 151
	virtual void load_EPSF (const char*const& from, void* aux = 0) = 0; // 152
	virtual scene_interface &set_sequence_value (float sequence_value_param, void * = 0) = 0; // 153
	virtual float get_sequence_value (void * = 0) const = 0; // 154
	virtual polygon_mesh_class& begin_polygon_mesh (const char* as, void* aux = 0) = 0; // 155
	virtual void append_polygon_mesh_vertex (const sxsdk::vec3& at, void* aux = 0) = 0; // 156
		void append_polygon_mesh_point (const sxsdk::vec3& at, void* aux = 0) { append_polygon_mesh_vertex(at); }
	virtual void append_polygon_mesh_edge (int vertex0, int vertex1, void* aux = 0) = 0; // 157
	virtual void end_polygon_mesh (void* aux = 0) = 0; // 158
	virtual int get_number_of_memorized_shapes (void * = 0) const = 0; // 159
	virtual shape_interface* get_memorized_shape_interface (int i = 0, void* aux = 0) = 0; // 160
		shape_interface* get_memorized_shape (int i = 0, void* aux = 0) { return get_memorized_shape_interface(i); }
	virtual shape_interface* get_first_memorized_shape_interface (void* aux = 0) = 0; // 161
		shape_interface* get_first_memorized_shape (void* aux = 0) { return get_first_memorized_shape_interface(); }
	virtual shape_interface* get_next_memorized_shape_interface (void* aux = 0) = 0; // 162
		shape_interface* get_next_memorized_shape (void* aux = 0) { return get_next_memorized_shape_interface(); }
	virtual void save (void* aux = 0) = 0; // 163
	virtual void save_as (void* aux = 0) = 0; // 164
	virtual void save_shape (void* aux = 0) = 0; // 165
	virtual void save_lock (void* aux = 0) = 0; // 166
	virtual void save_pose (void* aux = 0) = 0; // 167
	virtual void save_DXF (void* aux = 0) = 0; // 168
	virtual void save_Animation_Master (void* aux = 0) = 0; // 169
	virtual void save_RIB (void* aux = 0) = 0; // 170
	virtual void print (void* aux = 0) = 0; // 171
	virtual void append_polygon_mesh_face (int i0, int i1, int i2, void* aux = 0) = 0; // 172
	virtual void append_polygon_mesh_face (int i0, int i1, int i2, int i3, void* aux = 0) = 0; // 173
	virtual void set_polygon_mesh_threshold (float f, void* aux = 0) = 0; // 174
	virtual void append_polygon_mesh_edges (void* aux = 0) = 0; // 175
	virtual int get_total_frames (void * = 0) const = 0; // 176
	virtual void set_total_frames (int n, bool adjust, void* aux = 0) = 0; // 177
	virtual int get_start_frame (void * = 0) const = 0; // 178
	virtual scene_interface &set_start_frame (int start_frame_param, void * = 0) = 0; // 179
	virtual int get_end_frame (void * = 0) const = 0; // 180
	virtual scene_interface &set_end_frame (int end_frame_param, void * = 0) = 0; // 181
	virtual int get_frame_rate (void * = 0) const = 0; // 182
	virtual scene_interface &set_frame_rate (int frame_rate_param, void * = 0) = 0; // 183
	virtual void begin_creating_mode_1 (void* aux = 0) = 0; // 184
	virtual void save_VRML_2 (void* aux = 0) = 0; // 185
	virtual int scene_interface_dummy186(void *) { assert(false); throw "invalid interface scene_interface"; return 0; } // 186
	virtual void convert_2 (int* v = 0, bool option = false, void* aux = 0) = 0; // 187
	virtual int get_number_of_appended_points (void * = 0) const = 0; // 188
	virtual void cancel_line_object (void* aux = 0) = 0; // 189
		void cancel_polygon (void* aux = 0) { cancel_line_object(); }
	virtual bool can_save (void * = 0) const = 0; // 190
	virtual bool can_export_foreign (void * = 0) const = 0; // 191
	virtual bool can_export_native (void * = 0) const = 0; // 192
	virtual bool can_create (void * = 0) const = 0; // 193
	virtual bool can_save_rendered_image (void * = 0) const = 0; // 194
	virtual void append_polygon_mesh_mesh (mesh_interface* mesh, void* aux = 0) = 0; // 195
	virtual bool is_modify_mode (void * = 0) const = 0; // 196
	virtual bool is_line_modify_mode_obsolete (void* aux = 0) = 0; // 197
	virtual bool is_polygonmesh_modify_mode_obsolete (void* aux = 0) = 0; // 198
	virtual void deselect_all_key_points (void* aux = 0) = 0; // 199
	virtual void append_polygon_mesh_face_n (int n_v, const int v[], void* aux = 0) = 0; // 200
	virtual shape_interface* get_shape_interface_by_handle (void* h, void* aux = 0) = 0; // 201
	virtual shape_interface* get_shape_interface_by_ordinal (int n, void* aux = 0) = 0; // 202
	virtual shape_interface* get_shape_interface_by_attribute (int id, int n, void* attribute, void* aux = 0) = 0; // 203
	virtual void select_shape (shape_interface* s, void* aux = 0) = 0; // 204
	virtual void set_insertion_point (shape_interface* shape, void* aux = 0) = 0; // 205
	virtual shape_interface* get_insertion_point_shape_interface (void* aux = 0) = 0; // 206
		shape_interface* get_insertion_point (void* aux = 0) { return get_insertion_point_shape_interface(); }
	virtual sxsdk::shape_class* get_insertion_shape (void * = 0) const = 0; // 207
	virtual sxsdk::shape_class* get_shape_by_handle (void* h, void* aux = 0) = 0; // 208
	virtual sxsdk::shape_class* get_shape_by_ordinal (int n, void* aux = 0) = 0; // 209
	virtual sxsdk::shape_class* get_shape_by_attribute (int id, int n, void* attribute, void* aux = 0) = 0; // 210
	virtual int get_step_frames (void * = 0) const = 0; // 211
	virtual scene_interface &set_step_frames (int step_frames_param, void * = 0) = 0; // 212
	virtual sxsdk::shape_class& active_shape (int i = 0, void* aux = 0) = 0; // 213
	virtual sxsdk::shape_class& first_active_shape (void* aux = 0) = 0; // 214
	virtual sxsdk::shape_class& next_active_shape (void* aux = 0) = 0; // 215
	virtual sxsdk::shape_class& memorized_shape (int i = 0, void* aux = 0) = 0; // 216
	virtual sxsdk::shape_class& first_memorized_shape (void* aux = 0) = 0; // 217
	virtual sxsdk::shape_class& next_memorized_shape (void* aux = 0) = 0; // 218
	virtual shape_interface* get_shape_interface_by_name (const char* name, void* aux = 0) = 0; // 219
	virtual sxsdk::shape_class* get_shape_by_name (const char* name, const bool& default_name = false) = 0; // 220
sxsdk::shape_class* get_shape_by_name_using_default (const char* name) { const bool b = true; return get_shape_by_name(name, b); }
	virtual void begin_creating_at (sxsdk::shape_class* insertion_point, void* aux = 0) = 0; // 221
	virtual int get_active_shapes (sxsdk::shape_class* list[], void * = 0) const = 0; // 222
	virtual scene_interface &set_active_shapes (int n, sxsdk::shape_class* list[], void * = 0) = 0; // 223
	virtual bool is_rendering_thread (void * = 0) const = 0; // 224
	virtual rendering_context_interface* get_rendering_context_interface (void * = 0) const = 0; // 225
	virtual part_class& begin_custom_joint (const char* as = 0, void* aux = 0) = 0; // 226
	virtual void end_custom_joint (void* aux = 0) = 0; // 227
	virtual void set_joint_default_min (float at, void* aux = 0) = 0; // 228
	virtual void set_joint_default_max (float at, void* aux = 0) = 0; // 229
	virtual void set_joint_default_value (float at, void* aux = 0) = 0; // 230
	virtual sxsdk::radiosity_interface* get_radiosity_interface (void * = 0) const = 0; // 231
	virtual bool check_handle (void* handle, void* aux = 0) = 0; // 232
	virtual void enter_modify_mode (void* aux = 0) = 0; // 233
	virtual void exit_modify_mode (void* aux = 0) = 0; // 234
	virtual void select_by_handle_list (int n, void** handle_list, void* aux = 0) = 0; // 235
	virtual void reset_transformation (void* aux = 0) = 0; // 236
	virtual void reset_all_transformation (void* aux = 0) = 0; // 237
	virtual sxsdk::shape_class& get_shape (void * = 0) const = 0; // 238
	virtual void load_text (const char*const& from, const sxsdk::vec3* at = 0) = 0; // 239
	virtual void adjust_transformation (void* aux = 0) = 0; // 240
	virtual part_class& begin_ball_joint (const sxsdk::vec3& at, float r, const char* as = 0, void* aux = 0) = 0; // 241
	virtual void end_ball_joint (void* aux = 0) = 0; // 242
	virtual float get_default_bevel_radius (void * = 0) const = 0; // 243
	virtual scene_interface &set_default_bevel_radius (float default_bevel_radius_param, void * = 0) = 0; // 244
	virtual float get_default_disk_radius (void * = 0) const = 0; // 245
	virtual scene_interface &set_default_disk_radius (float default_disk_radius_param, void * = 0) = 0; // 246
	virtual float get_default_sphere_radius (void * = 0) const = 0; // 247
	virtual scene_interface &set_default_sphere_radius (float default_sphere_radius_param, void * = 0) = 0; // 248
	virtual float get_default_light_radius (void * = 0) const = 0; // 249
	virtual scene_interface &set_default_light_radius (float default_light_radius_param, void * = 0) = 0; // 250
	virtual part_class& begin_camera_joint (const sxsdk::vec3& eye, const sxsdk::vec3& target, const char* as = 0, void* aux = 0) = 0; // 251
	virtual void end_camera_joint (void* aux = 0) = 0; // 252
	virtual void fit_to_window (int key_flags = 0, void* aux = 0) = 0; // 253
	virtual bool has_backing_store (void* aux = 0) = 0; // 254
	virtual sxsdk::animation_settings_interface* get_animation_settings_interface (void * = 0) const = 0; // 255
	virtual bool get_mapping_modify_mode (void * = 0) const = 0; // 256
	virtual scene_interface &set_mapping_modify_mode (bool mapping_modify_mode_param, void * = 0) = 0; // 257
	virtual part_class& create_part (const char* as = 0, void* aux = 0) = 0; // 258
	virtual part_class& create_surface_part (const char* as = 0, void* aux = 0) = 0; // 259
	virtual part_class& create_rotator_joint (const sxsdk::vec3& from, const sxsdk::vec3& to, const char* as = 0, void* aux = 0) = 0; // 260
	virtual part_class& create_slider_joint (const sxsdk::vec3& from, const sxsdk::vec3& to, const char* as = 0, void* aux = 0) = 0; // 261
	virtual part_class& create_scale_joint (const sxsdk::vec3& from, const sxsdk::vec3& to, const char* as = 0, void* aux = 0) = 0; // 262
	virtual part_class& create_uniscale_joint (const sxsdk::vec3& at, float r, const char* as = 0, void* aux = 0) = 0; // 263
	virtual part_class& create_light_effector (const char* as = 0, void* aux = 0) = 0; // 264
		part_class& create_light_joint (const char* as = 0, void* aux = 0) { return create_light_effector(as); }
	virtual part_class& create_path_joint (const char* as = 0, void* aux = 0) = 0; // 265
	virtual part_class& create_morph_effector (const char* as = 0, void* aux = 0) = 0; // 266
		part_class& create_morph_joint (const char* as = 0, void* aux = 0) { return create_morph_effector(as); }
	virtual part_class& create_ball_joint (const sxsdk::vec3& at, float r, const char* as = 0, void* aux = 0) = 0; // 267
	virtual part_class& create_camera (const sxsdk::vec3& eye, const sxsdk::vec3& target, const char* as = 0, void* aux = 0) = 0; // 268
		part_class& create_camera_joint (const sxsdk::vec3& eye, const sxsdk::vec3& target, const char* as = 0, void* aux = 0) { return create_camera(eye, target, as); }
	virtual part_class& create_custom_joint (const char* as = 0, void* aux = 0) = 0; // 269
	virtual scene_interface &set_dirty (bool dirty_param, void * = 0) = 0; // 270
	virtual bool get_dirty (void * = 0) const = 0; // 271
	virtual void update_figure_window (void* aux = 0) = 0; // 272
	virtual int get_redraw_time_obsolete (void* aux = 0) = 0; // 273
	virtual void select_shapes (int n, sxsdk::shape_class** shapes, void* aux = 0) = 0; // 274
	virtual line_class& create_line (const char* as, int n_points, const sxsdk::vec3 points[], bool closed = true, void* aux = 0) = 0; // 275
	virtual float get_light_scale (void * = 0) const = 0; // 276
	virtual scene_interface &set_light_scale (float light_scale_param, void * = 0) = 0; // 277
	virtual sxsdk::mat4 get_world_to_device_matrix (void * = 0) const = 0; // 278
	virtual sxsdk::mat4 get_world_to_view_matrix (void * = 0) const = 0; // 279
	virtual sxsdk::mat4 get_world_to_perspective_matrix (void * = 0) const = 0; // 280
	virtual int get_camera_objects (sxsdk::shape_class** shapes, sxsdk::shape_class* root = 0, void* aux = 0) const = 0; // 281
	virtual sxsdk::stream_interface* create_attribute_stream_interface (int id, void* aux = 0) = 0; // 282
	virtual sxsdk::stream_interface* get_attribute_stream_interface (int id, void* aux = 0) = 0; // 283
	virtual bool delete_attribute (int id, void* aux = 0) = 0; // 284
	virtual int scene_interface_test_1 ( void* aux =0 ) { return 1; } // 285
	virtual void save_control_points (int n, sxsdk::shape_class** shapes, bool active_control_points_only, bool deep, void* aux = 0) = 0; // 286
	virtual void undo_modify_control_points (int n, sxsdk::shape_class** shapes, bool active_control_points_only, bool deep, void* aux = 0) = 0; // 287
	virtual void clear_saved_control_points (void* aux = 0) = 0; // 288
	virtual void reset_undo_obsolete (void* aux = 0) = 0; // 289
	virtual void enter_create_line_mode (bool closed, void* aux = 0) = 0; // 290
	virtual void exit_create_line_mode (void* aux = 0) = 0; // 291
	virtual bool is_create_line_mode (void * = 0) const = 0; // 292
	virtual sxsdk::vec3 get_center (void * = 0) const = 0; // 293
	virtual sxsdk::keyframes_interface* get_keyframes_interface (void * = 0) const = 0; // 294
	virtual sxsdk::vec3 get_current_cursor_position (void * = 0) const = 0; // 295
	virtual void cancel_transformation (void* aux = 0) = 0; // 296
	virtual void link (void* aux = 0) = 0; // 297
	virtual sxsdk::quaternion_class get_lathe_rotation (void * = 0) const = 0; // 298
	virtual scene_interface &set_lathe_rotation (const sxsdk::quaternion_class &lathe_rotation_param, void * = 0) = 0; // 299
	virtual sxsdk::shape_class* get_local (void * = 0) const = 0; // 300
	virtual void set_local (sxsdk::shape_class* local, void* aux = 0) = 0; // 301
	virtual sxsdk::mat4 get_local_matrix (void * = 0) const = 0; // 302
	virtual scene_interface &set_local_matrix (const sxsdk::mat4 &local_matrix_param, void * = 0) = 0; // 303
	virtual void close (void* aux = 0) = 0; // 304
	virtual int get_number_of_metacameras (void * = 0) const = 0; // 305
	virtual int get_number_of_cameras (void * = 0) const = 0; // 306
	virtual scene_interface &set_current_camera (int current_camera_param, void * = 0) = 0; // 307
	virtual int get_current_camera (void * = 0) const = 0; // 308
	virtual camera_interface* get_nth_camera_interface (int n, void* aux = 0) = 0; // 309
	virtual scene_interface &set_sequence_mode (bool sequence_mode_param, void * = 0) = 0; // 310
	virtual bool get_sequence_mode (void * = 0) const = 0; // 311
	virtual sx::rectangle_class get_view_rectangle (int view, void* aux = 0) = 0; // 312
	virtual void screen_to_world (int view, const sx::vec<int,2>& cp, sxsdk::vec3& p, void* aux = 0) = 0; // 313
	virtual shape_interface* get_shape_interface_by_position (int n, int* position, void* aux = 0) = 0; // 314
	virtual sxsdk::shape_class* get_shape_by_position (int n_position, const int position[], void* aux = 0) = 0; // 315
	virtual void link_object (const sxsdk::vec3* around, const sxsdk::vec3* scale, const sxsdk::vec3* rotate, const sxsdk::vec3* translate, void* aux = 0) = 0; // 316
	virtual void convert_to_curved_surface (void* aux = 0) = 0; // 317
	virtual void convert_to_polygon_mesh (int m = 1, int n = 1, void* aux = 0) = 0; // 318
	virtual void draw_figure_window (void* aux = 0) = 0; // 319
	virtual scene_interface &set_window_frame (const sx::rectangle_class &window_frame_param, void * = 0) = 0; // 320
	virtual sx::rectangle_class get_window_frame (void * = 0) const = 0; // 321
	virtual float get_fps (void * = 0) const = 0; // 322
	virtual sxsdk::figure_window_interface* get_figure_window_interface (void * = 0) const = 0; // 323
	virtual camera_class& get_camera (void * = 0) const = 0; // 324
	virtual void read (const char* from, void* aux = 0) = 0; // 325
	virtual scene_interface &set_pers_grid (bool pers_grid_param, void * = 0) = 0; // 326
	virtual bool get_pers_grid (void * = 0) const = 0; // 327
	virtual bool is_undo_mode (void * = 0) const = 0; // 328
	virtual void browser_active (void* aux = 0) = 0; // 329
	virtual void load_shape (const char* from, const bool* option = 0, const sxsdk::vec3* at = 0, void* aux = 0) = 0; // 330
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 331
	virtual scene_interface &set_cursor_plane (int cursor_plane_param, void * = 0) = 0; // 332
	virtual int get_cursor_plane (void * = 0) const = 0; // 333
	virtual void append_metacamera (void* aux = 0) = 0; // 334
	virtual sxsdk::master_surface_class& create_sub_surface (const char* as, void* aux = 0) = 0; // 335
std::vector<sxsdk::shape_class*> get_shapes_by_name_scriptimplementation (const char* name, bool default_name = false, void* aux = 0) ;
	virtual sxsdk::stream_interface* create_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 336
	virtual sxsdk::stream_interface* get_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 337
	virtual bool delete_attribute_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 338
	virtual sxsdk::figure_view_interface* get_figure_view_interface (void * = 0) const = 0; // 339
	virtual sxsdk::display_interface* get_display_interface (void * = 0) const = 0; // 340
	virtual bool is_redo_mode (void * = 0) const = 0; // 341
	virtual void convert_to_line_object (void* aux = 0) = 0; // 342
	virtual void render_shading (sxsdk::image_interface* image, void* aux = 0) = 0; // 343
	virtual void export_with_uuid (const sx::uuid_class& plugin_id, const char* path, void* aux = 0) = 0; // 344
	virtual int get_open_time (void * = 0) const = 0; // 345
	virtual int get_save_time (void * = 0) const = 0; // 346
	virtual scene_interface &set_show_normals (bool show_normals_param, void * = 0) = 0; // 347
	virtual bool get_show_normals (void * = 0) const = 0; // 348
	virtual scene_interface &set_large_point (bool large_point_param, void * = 0) = 0; // 349
	virtual bool get_large_point (void * = 0) const = 0; // 350
	virtual void unpurge_images (void* aux = 0) = 0; // 351
	virtual scene_interface &set_selection_mode (int selection_mode_param, void * = 0) = 0; // 352
	virtual int get_selection_mode (void * = 0) const = 0; // 353
	virtual part_class& begin_sound_object (const char* path, const sxsdk::vec3& at, float r, const char* as = 0, void* aux = 0) = 0; // 354
	virtual void end_sound_object (void* aux = 0) = 0; // 355
	virtual part_class& create_sound_object (const char* path, const sxsdk::vec3& at, float r, const char* as = 0, void* aux = 0) = 0; // 356
	virtual const char* get_file_path (void * = 0) const = 0; // 357
	virtual void revert_to_saved (bool revert_rendering = true, void* aux = 0) = 0; // 358
	virtual master_image_class& create_master_image (const char* as, void* aux = 0) = 0; // 359
	virtual void load_BVH (const char*const& from, void* aux = 0) = 0; // 360
	virtual bool is_locked (void * = 0) const = 0; // 361
	virtual void push_dirty (void* aux = 0) = 0; // 362
	virtual void pop_dirty (void* aux = 0) = 0; // 363
	virtual void read_from_stream (stream_interface& stream, void* aux = 0) = 0; // 364
	virtual void write_to_stream (stream_interface& stream, void* aux = 0) = 0; // 365
	virtual void load_poser (const char*const& from, void* aux = 0) = 0; // 366
	virtual void load_OBJ (const char*const& from, void* aux = 0) = 0; // 367
	virtual void save_OBJ (const char*const& in, const sxsdk::exporter_settings_interface* settings = 0) = 0; // 368
	virtual void save_OBJ (void* aux = 0) = 0; // 369
	virtual bool is_motion_playing (void * = 0) const = 0; // 370
	virtual part_class& begin_switch_effector (const char* as = 0, void* aux = 0) = 0; // 371
	virtual void end_switch_effector (void* aux = 0) = 0; // 372
	virtual part_class& create_switch_effector (const char* as = 0, void* aux = 0) = 0; // 373
	virtual void export_scene (const char*const& in, int external_reference = 0, void* aux = 0) = 0; // 374
	virtual void load_3DS (const char*const& from, void* aux = 0) = 0; // 375
	virtual void save_3DS (const char*const& in, const sxsdk::exporter_settings_interface* settings = 0) = 0; // 376
	virtual void save_3DS (void* aux = 0) = 0; // 377
	virtual void write_noncompatible (const char*const& in, void* aux = 0) = 0; // 378
	virtual void write_compatible (const char*const& in, void* aux = 0) = 0; // 379
	virtual void write_R4compatible (const char*const& in, void* aux = 0) = 0; // 380
	virtual void write_xml (const char*const& in, void* aux = 0) = 0; // 381
	virtual bool get_grid_shown (int pane, void* aux = 0) const = 0; // 382
	virtual void set_grid_shown (int pane, bool shown, void* aux = 0) = 0; // 383
	virtual const char* open_database (void* aux = 0) = 0; // 384
	virtual void close_database (const char* dbid, void* aux = 0) = 0; // 385
	virtual bool is_database (const char* dbid, void* aux = 0) = 0; // 386
	virtual int database_execute (const char* dbid, const char* sql, void* aux = 0) = 0; // 387
	virtual const char* database_resultText (const char* dbid, void* aux = 0) = 0; // 388
	virtual const char* database_statement (const char* dbid, const char* sql, void* aux = 0) = 0; // 389
	virtual bool is_database_statement (const char* stmtid, void* aux = 0) = 0; // 390
	virtual const char* database_laseError (const char* dbid, void* aux = 0) = 0; // 391
	virtual int database_errorCode (const char* dbid, void* aux = 0) = 0; // 392
	virtual int database_statement_step (const char* stmtid, void* aux = 0) = 0; // 393
	virtual int database_statement_reset (const char* stmtid, void* aux = 0) = 0; // 394
	virtual int database_statement_finalize (const char* stmtid, void* aux = 0) = 0; // 395
	virtual int database_statement_bind_int (const char* stmtid, int index, int iValue, void* aux = 0) = 0; // 396
	virtual int database_statement_bind_string (const char* stmtid, int index, const char* text, void* aux = 0) = 0; // 397
	virtual int database_statement_bind_double (const char* stmtid, int index, double rValue, void* aux = 0) = 0; // 398
	virtual int database_statement_bind_blob (const char* stmtid, int index, const void* data, int n, void* aux = 0) = 0; // 399
	virtual int database_statement_bind_null (const char* stmtid, int index, void* aux = 0) = 0; // 400
	virtual int database_statement_dataType (const char* stmtid, int index, void* aux = 0) = 0; // 401
	virtual int database_statement_intValue (const char* stmtid, int index, void* aux = 0) = 0; // 402
	virtual double database_statement_doubleValue (const char* stmtid, int index, void* aux = 0) = 0; // 403
	virtual const char* database_statement_stringValue (const char* stmtid, int index, void* aux = 0) = 0; // 404
	virtual const void* database_statement_blob (const char* stmtid, int index, void* aux = 0) = 0; // 405
	virtual int database_statement_byts (const char* stmtid, int index, void* aux = 0) = 0; // 406
	virtual bool database_statement_nextRow (const char* stmtid, void* aux = 0) = 0; // 407
	virtual std::vector<const char*> tag_path_array (void* aux = 0) = 0; // 408
	virtual std::vector<sxsdk::shape_class*> shapes_from_tag_path (const char* path, void* aux = 0) = 0; // 409
	virtual sxsdk::shape_class* get_shape_by_uuid (const sx::uuid_class& uuid, void* aux = 0) = 0; // 410
	virtual sxsdk::mat4 get_sequence_world_to_device_matrix (float sequence_value, void* aux = 0) const = 0; // 411
	virtual sxsdk::mat4 get_sequence_world_to_view_matrix (float sequence_value, void* aux = 0) const = 0; // 412
	virtual sxsdk::mat4 get_sequence_world_to_perspective_matrix (float sequence_value, void* aux = 0) const = 0; // 413
	virtual void save_images (const char*const& in, void* aux = 0) = 0; // 414
	virtual void save_EPX (const char*const& in, void* aux = 0) = 0; // 415
	virtual scene_interface &set_work_plane (bool work_plane_param, void * = 0) = 0; // 416
	virtual bool get_work_plane (void * = 0) const = 0; // 417
	virtual void* get_linedrawing_interface (void * = 0) const = 0; // 418
	virtual void clear_memory (void* aux = 0) = 0; // 419
	virtual part_class& create_local_axis (void* aux = 0) = 0; // 420
	virtual part_class& save_local_axis (const char* as = 0, void* aux = 0) = 0; // 421
	virtual bool use_local_axis (const char* name = 0, void* aux = 0) = 0; // 422
	virtual scene_interface &set_selection_method (int selection_method_param, void * = 0) = 0; // 423
	virtual int get_selection_method (void * = 0) const = 0; // 424
	virtual part_class& create_master_part (sxsdk::enums::part_type type, void* aux = 0) = 0; // 425
	virtual database::blobdata database_statement_blobdata (const char* stmtid, int index, void* aux = 0) = 0; // 426
	virtual void export_save (const char* type, const char* in, void* aux = 0) = 0; // 427
	virtual void import_load (const char* type, const char* in, void* aux = 0) = 0; // 428
	virtual part_class& begin_path_replicator (const char* as = 0, void* aux = 0) = 0; // 429
	virtual void end_path_replicator (void* aux = 0) = 0; // 430
	virtual part_class& create_path_replicator (const char* as = 0, void* aux = 0) = 0; // 431
	virtual sxsdk::speed_interface* get_speed_interface (void * = 0) const = 0; // 432
	virtual bool get_skipped (void * = 0) const = 0; // 433
	virtual scene_interface &set_pivot_position (sxsdk::vec3 pivot_position_param, void * = 0) = 0; // 434
	virtual sxsdk::vec3 get_pivot_position (void * = 0) const = 0; // 435
	virtual scene_interface &set_manip_type (int manip_type_param, void * = 0) = 0; // 436
	virtual int get_manip_type (void * = 0) const = 0; // 437
	virtual bool check_invariant (void* aux = 0) = 0; // 438
	virtual void hide_select_faces (void* aux = 0) = 0; // 439
	virtual void hide_unselect_faces (void* aux = 0) = 0; // 440
	virtual void flip_hide_faces (void* aux = 0) = 0; // 441
	virtual void show_all_faces (void* aux = 0) = 0; // 442
	virtual sxsdk::shape_class& create_primitive_plane (const char* as, int type, bool set_uv, int du, int dv, const sxsdk::vec3& v0, const sxsdk::vec3& v1, const sxsdk::vec3& v2, const sxsdk::vec3& v3, void* aux = 0) = 0; // 443
	virtual sxsdk::shape_class& create_primitive_box (const char* as, int type, bool set_uv, int du, int dv, int dw, const sxsdk::vec3& v0, const sxsdk::vec3& v1, const sxsdk::vec3& v2, const sxsdk::vec3& v3, const sxsdk::vec3& edir, bool top_face = true, bool bottom_face = true, void* aux = 0) = 0; // 444
	virtual sxsdk::shape_class& create_primitive_sphere (const char* as, int type, bool set_uv, int du, int dv, const sxsdk::vec3& at, float r, void* aux = 0) = 0; // 445
	virtual sxsdk::shape_class& create_primitive_pyramid (const char* as, int type, bool set_uv, int du, int dv, int dw, const sxsdk::vec3& v0, const sxsdk::vec3& v1, const sxsdk::vec3& v2, const sxsdk::vec3& v3, const sxsdk::vec3& edir, bool bottom_face = true, void* aux = 0) = 0; // 446
	virtual sxsdk::shape_class& create_primitive_cone (const char* as, int type, bool set_uv, int du, int dv, const sxsdk::vec3& at, float r, int axis, const sxsdk::vec3& edir, bool bottom_face = true, void* aux = 0) = 0; // 447
	virtual sxsdk::shape_class& create_primitive_cylinder (const char* as, int type, bool set_uv, int du, int dv, const sxsdk::vec3& at, float r, int axis, const sxsdk::vec3& edir, bool top_face = true, bool bottom_face = true, void* aux = 0) = 0; // 448
	virtual sxsdk::shape_class& create_primitive_capsule (const char* as, int type, bool set_uv, int du, int dv, const sxsdk::vec3& at, float r, int axis, const sxsdk::vec3& edir, void* aux = 0) = 0; // 449
	virtual sxsdk::shape_class& create_primitive_torus (const char* as, int type, bool set_uv, int du, int dv, const sxsdk::vec3& at, float r, float r2, int axis, void* aux = 0) = 0; // 450
	virtual void save_XVL (const char*const& in, const sxsdk::exporter_settings_interface* settings = 0) = 0; // 451
	virtual void draw_select_edges (bool draw = true, void* aux = 0) = 0; // 452
	virtual float get_step_frames_float (void * = 0) const = 0; // 453
	virtual scene_interface &set_step_frames_float (float step_frames_float_param, void * = 0) = 0; // 454
	};
}
