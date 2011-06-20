#pragma once

namespace sxsdk {
	class rendering_interface : public shade_interface {
	public:
		enum algorithm_enum {	///< \en blah \enden \ja レンダリングアルゴリズム \endja
			ray_tracing,			///< \en blah \enden \ja レイトレーシング \endja
			path_tracing,			///< \en blah \enden \ja パストレーシング \endja
			draft_ray_tracing,		///< \en blah \enden \ja ドラフトレイトレーシング \endja
			last_algorithm,
			default_rendering = ray_tracing,
			scan_line = draft_ray_tracing,
		};
		virtual ~rendering_interface () { }
	virtual void render_deprecated (progress_dialog_interface* aux = 0) = 0; // 0
	virtual void start (sxsdk::plugin_interface* auxplugin = 0) = 0; // 1
	virtual bool is_still_rendering (void * = 0) const = 0; // 2
	virtual void stop (void* aux = 0) = 0; // 3
	virtual void resume (void* aux = 0) = 0; // 4
	virtual void fit_image_window (void* aux = 0) = 0; // 5
	virtual void magnify_image (int by, void* aux = 0) = 0; // 6
	virtual void shrink_image (int n, void* aux = 0) = 0; // 7
	virtual void start_animation (const char*const& in = "", void* aux = 0) = 0; // 8
	virtual void append_animation (void* aux = 0) = 0; // 9
	virtual void finish_animation (void* aux = 0) = 0; // 10
	virtual rendering_interface &set_premultiplied_pixel (bool premultiplied_pixel_param, void * = 0) = 0; // 11
	virtual bool get_premultiplied_pixel (void * = 0) const = 0; // 12
	virtual rendering_interface &set_transparency_affects_alpha (bool transparency_affects_alpha_param, void * = 0) = 0; // 13
	virtual bool get_transparency_affects_alpha (void * = 0) const = 0; // 14
	virtual rendering_interface &set_render_transparency_deprecated (bool render_transparency_deprecated_param, void * = 0) = 0; // 15
	virtual bool get_render_transparency_deprecated (void * = 0) const = 0; // 16
	virtual bool can_resume (void * = 0) const = 0; // 17
	virtual rendering_interface &set_image_size (const sx::vec<int,2> &image_size_param, void * = 0) = 0; // 18
	virtual sx::vec<int,2> get_image_size (void * = 0) const = 0; // 19
	virtual void set_raytracing_mindiv (int i, void* aux = 0) = 0; // 20
	virtual int get_raytracing_mindiv (void* aux = 0) = 0; // 21
	virtual void set_raytracing_maxdiv (int i, void* aux = 0) = 0; // 22
	virtual int get_raytracing_maxdiv (void* aux = 0) = 0; // 23
	virtual void set_raytracing_maxlevel (int i, void* aux = 0) = 0; // 24
	virtual int get_raytracing_maxlevel (void* aux = 0) = 0; // 25
	virtual void set_raytracing_initial_threshold (int i, void* aux = 0) = 0; // 26
	virtual int get_raytracing_initial_threshold (void* aux = 0) = 0; // 27
	virtual void set_raytracing_threshold_increment (int i, void* aux = 0) = 0; // 28
	virtual int get_raytracing_threshold_increment (void* aux = 0) = 0; // 29
	virtual rendering_interface &set_method (int method_param, void * = 0) = 0; // 30
	virtual int get_method (void * = 0) const = 0; // 31
	virtual rendering_interface &set_surface_division_level (int surface_division_level_param, void * = 0) = 0; // 32
	virtual int get_surface_division_level (void * = 0) const = 0; // 33
	virtual rendering_interface &set_antialiasing (bool antialiasing_param, void * = 0) = 0; // 34
	virtual bool get_antialiasing (void * = 0) const = 0; // 35
	virtual rendering_interface &set_show_texture (bool show_texture_param, void * = 0) = 0; // 36
	virtual bool get_show_texture (void * = 0) const = 0; // 37
	virtual rendering_interface &set_show_background (bool show_background_param, void * = 0) = 0; // 38
	virtual bool get_show_background (void * = 0) const = 0; // 39
	virtual rendering_interface &set_reflect_background (bool reflect_background_param, void * = 0) = 0; // 40
	virtual bool get_reflect_background (void * = 0) const = 0; // 41
	virtual rendering_interface &set_show_shadow (bool show_shadow_param, void * = 0) = 0; // 42
	virtual bool get_show_shadow (void * = 0) const = 0; // 43
	virtual rendering_interface &set_panorama_deprecated (bool panorama_deprecated_param, void * = 0) = 0; // 44
	virtual bool get_panorama_deprecated (void * = 0) const = 0; // 45
	virtual rendering_interface &set_sideways_obsoleted (bool sideways_obsoleted_param, void * = 0) = 0; // 46
	virtual bool get_sideways_obsoleted (void * = 0) const = 0; // 47
	virtual rendering_interface &set_alpha_channel (bool alpha_channel_param, void * = 0) = 0; // 48
	virtual bool get_alpha_channel (void * = 0) const = 0; // 49
	virtual rendering_interface &set_single_sided_face (bool single_sided_face_param, void * = 0) = 0; // 50
	virtual bool get_single_sided_face (void * = 0) const = 0; // 51
	virtual void set_tiling_obsolete (bool b, void* aux = 0) = 0; // 52
	virtual bool get_tiling_obsolete (void* aux = 0) = 0; // 53
	virtual rendering_interface &set_pixel_ratio (float pixel_ratio_param, void * = 0) = 0; // 54
	virtual float get_pixel_ratio (void * = 0) const = 0; // 55
	virtual rendering_interface &set_ray_cast_level (int ray_cast_level_param, void * = 0) = 0; // 56
	virtual int get_ray_cast_level (void * = 0) const = 0; // 57
	virtual rendering_interface &set_ray_tracing_quality (float ray_tracing_quality_param, void * = 0) = 0; // 58
	virtual float get_ray_tracing_quality (void * = 0) const = 0; // 59
	virtual rendering_interface &set_ray_tracing_delta (float ray_tracing_delta_param, void * = 0) = 0; // 60
	virtual float get_ray_tracing_delta (void * = 0) const = 0; // 61
	virtual rendering_interface &set_fisheye_distortion (float fisheye_distortion_param, void * = 0) = 0; // 62
	virtual float get_fisheye_distortion (void * = 0) const = 0; // 63
	virtual sxsdk::image_interface* get_image_interface (void * = 0) const = 0; // 64
	virtual void update_image (void* aux = 0) = 0; // 65
	virtual void start_animation_mov (const char*const& path, bool ask, const CodecType* codec, const int* depth, const CodecQ* spatial_quality, const CodecQ* temporal_quality, const int* frame_rate, const int* key_frame_rate, void* aux = 0) = 0; // 66
	virtual rendering_interface &set_keep_z_deprecated (bool keep_z_deprecated_param, void * = 0) = 0; // 67
	virtual bool get_keep_z_deprecated (void * = 0) const = 0; // 68
	virtual void render_area_deprecated (const sx::rectangle_class& area, progress_dialog_interface* aux = 0) = 0; // 69
	virtual void start_area (const sx::rectangle_class& area, sxsdk::plugin_interface* auxplugin = 0) = 0; // 70
	virtual rendering_interface &set_real_color (bool real_color_param, void * = 0) = 0; // 71
	virtual bool get_real_color (void * = 0) const = 0; // 72
	virtual rendering_interface &set_uses_rendering_servers (bool uses_rendering_servers_param, void * = 0) = 0; // 73
	virtual bool get_uses_rendering_servers (void * = 0) const = 0; // 74
	virtual rendering_interface &set_uses_radiosity (bool uses_radiosity_param, void * = 0) = 0; // 75
	virtual bool get_uses_radiosity (void * = 0) const = 0; // 76
	virtual rendering_interface &set_number_of_threads (int number_of_threads_param, void * = 0) = 0; // 77
	virtual int get_number_of_threads (void * = 0) const = 0; // 78
	virtual rendering_interface &set_over_sampling (int over_sampling_param, void * = 0) = 0; // 79
	virtual int get_over_sampling (void * = 0) const = 0; // 80
	virtual rendering_interface &set_total_energy (bool total_energy_param, void * = 0) = 0; // 81
	virtual bool get_total_energy (void * = 0) const = 0; // 82
	virtual rendering_interface &set_uses_rendering_servers_only (bool uses_rendering_servers_only_param, void * = 0) = 0; // 83
	virtual bool get_uses_rendering_servers_only (void * = 0) const = 0; // 84
	virtual rendering_interface &set_shadow_map_size (int shadow_map_size_param, void * = 0) = 0; // 85
	virtual int get_shadow_map_size (void * = 0) const = 0; // 86
	virtual rendering_interface &set_shadow_map_bias (float shadow_map_bias_param, void * = 0) = 0; // 87
	virtual float get_shadow_map_bias (void * = 0) const = 0; // 88
	virtual rendering_interface &set_shadow_map_blur (float shadow_map_blur_param, void * = 0) = 0; // 89
	virtual float get_shadow_map_blur (void * = 0) const = 0; // 90
	virtual rendering_interface &set_shadow_type (int shadow_type_param, void * = 0) = 0; // 91
	virtual int get_shadow_type (void * = 0) const = 0; // 92
	virtual int get_number_of_sets (void * = 0) const = 0; // 93
	virtual int get_current_index (void * = 0) const = 0; // 94
	virtual rendering_interface &set_current_index (int current_index_param, void * = 0) = 0; // 95
	virtual sxsdk::stream_interface* create_renderer_attribute_stream_interface (int id, void* aux = 0) = 0; // 96
	virtual sxsdk::stream_interface* get_renderer_attribute_stream_interface (int id, void* aux = 0) = 0; // 97
	virtual bool delete_renderer_attribute (int id, void* aux = 0) = 0; // 98
	virtual sxsdk::stream_interface* create_effector_attribute_stream_interface (int id, void* aux = 0) = 0; // 99
	virtual sxsdk::stream_interface* get_effector_attribute_stream_interface (int id, void* aux = 0) = 0; // 100
	virtual bool delete_effector_attribute (int id, void* aux = 0) = 0; // 101
	virtual int rendering_interface_test_1 ( void* aux =0 ) { return 1; } // 102
	virtual sxsdk::stream_interface* create_attribute_stream_interface (int id, void* aux = 0) = 0; // 103
	virtual sxsdk::stream_interface* get_attribute_stream_interface (int id, void* aux = 0) = 0; // 104
	virtual bool delete_attribute (int id, void* aux = 0) = 0; // 105
	virtual sxsdk::stream_interface* get_effector_index_attribute_stream_interface (int effector_index, void* aux = 0) = 0; // 106
	virtual int get_number_of_effectors (void * = 0) const = 0; // 107
	virtual int get_effector_id (int effector_index, void* aux = 0) = 0; // 108
	virtual void set_effector_id (int effector_index, int id, void* aux = 0) = 0; // 109
	virtual int get_target_number_of_photons (void * = 0) const = 0; // 110
	virtual rendering_interface &set_target_number_of_photons (int target_number_of_photons_param, void * = 0) = 0; // 111
	virtual rendering_interface &set_reflection_factor (float reflection_factor_param, void * = 0) = 0; // 112
	virtual float get_reflection_factor (void * = 0) const = 0; // 113
	virtual rendering_interface &set_shadow_map_sampling (int shadow_map_sampling_param, void * = 0) = 0; // 114
	virtual int get_shadow_map_sampling (void * = 0) const = 0; // 115
	virtual int get_global_illumination (void * = 0) const = 0; // 116
	virtual rendering_interface &set_global_illumination (int global_illumination_param, void * = 0) = 0; // 117
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 118
	virtual int get_style (void * = 0) const = 0; // 119
	virtual rendering_interface &set_style (int style_param, void * = 0) = 0; // 120
	virtual const char* get_style_name (void * = 0) const = 0; // 121
	virtual rendering_interface &set_style_name (const char* style_name_param, void * = 0) = 0; // 122
	virtual rendering_interface &set_method_uuid (const sx::uuid_class &method_uuid_param, void * = 0) = 0; // 123
	virtual sx::uuid_class get_method_uuid (void * = 0) const = 0; // 124
	virtual sx::uuid_class get_effector_uuid (int effector_index, void* aux = 0) = 0; // 125
	virtual void set_effector_uuid (int effector_index, const sx::uuid_class& uuid, void* aux = 0) = 0; // 126
	virtual sxsdk::stream_interface* create_renderer_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 127
	virtual sxsdk::stream_interface* get_renderer_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 128
	virtual bool delete_renderer_attribute_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 129
	virtual sxsdk::stream_interface* create_effector_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 130
	virtual sxsdk::stream_interface* get_effector_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 131
	virtual bool delete_effector_attribute_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 132
	virtual sxsdk::stream_interface* create_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 133
	virtual sxsdk::stream_interface* get_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 134
	virtual bool delete_attribute_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 135
	virtual int render (progress_dialog_interface* auxprogress = 0, sxsdk::plugin_interface* auxplugin = 0) = 0; // 136
	virtual int render_area (const sx::rectangle_class& area, progress_dialog_interface* auxdialog = 0, sxsdk::plugin_interface* auxplugin = 0) = 0; // 137
	virtual rendering_interface &set_panorama_projection (int panorama_projection_param, void * = 0) = 0; // 138
	virtual int get_panorama_projection (void * = 0) const = 0; // 139
	virtual int get_renderer_index (void * = 0) const = 0; // 140
	virtual bool has_renderer (void * = 0) const = 0; // 141
	virtual bool can_use_rendering_server (void * = 0) const = 0; // 142
	virtual rendering_interface &set_ray_offset (float ray_offset_param, void * = 0) = 0; // 143
	virtual float get_ray_offset (void * = 0) const = 0; // 144
	virtual rendering_interface &set_ray_offset_type (int ray_offset_type_param, void * = 0) = 0; // 145
	virtual int get_ray_offset_type (void * = 0) const = 0; // 146
	virtual sxsdk::image_interface* get_scaled_image_interface (void * = 0) const = 0; // 147
	virtual bool has_effectors (void * = 0) const = 0; // 148
	virtual rendering_interface &set_uses_rendering_process (bool uses_rendering_process_param, void * = 0) = 0; // 149
	virtual bool get_uses_rendering_process (void * = 0) const = 0; // 150
	virtual rendering_interface &set_script (const char* script_param, void * = 0) = 0; // 151
	virtual const char* get_script (void * = 0) const = 0; // 152
	virtual int get_setup_wall_time (void * = 0) const = 0; // 153
	virtual int get_photonmap_time (void * = 0) const = 0; // 154
	virtual void unscale_image (void* aux = 0) = 0; // 155
	virtual float get_photons_gathering_shape_comparison_scale (void * = 0) const = 0; // 156
	virtual rendering_interface &set_photons_gathering_shape_comparison_scale (float photons_gathering_shape_comparison_scale_param, void * = 0) = 0; // 157
	virtual float get_raytracing_adaptive_threshold (void * = 0) const = 0; // 158
	virtual rendering_interface &set_raytracing_adaptive_threshold (float raytracing_adaptive_threshold_param, void * = 0) = 0; // 159
	virtual float get_raytracing_grid_threshold (void * = 0) const = 0; // 160
	virtual rendering_interface &set_raytracing_grid_threshold (float raytracing_grid_threshold_param, void * = 0) = 0; // 161
	virtual int get_animation (void * = 0) const = 0; // 162
	virtual rendering_interface &set_animation (int animation_param, void * = 0) = 0; // 163
	virtual float get_volume_rendering_gamma (void * = 0) const = 0; // 164
	virtual rendering_interface &set_volume_rendering_gamma (float volume_rendering_gamma_param, void * = 0) = 0; // 165
	virtual float get_volume_rendering_beta (void * = 0) const = 0; // 166
	virtual rendering_interface &set_volume_rendering_beta (float volume_rendering_beta_param, void * = 0) = 0; // 167
	virtual int get_rendering_wall_time (void * = 0) const = 0; // 168
	virtual int get_rendering_user_time (void * = 0) const = 0; // 169
	virtual int get_rendering_system_time (void * = 0) const = 0; // 170
	virtual void start_with_window (sxsdk::window_interface* window, sxsdk::plugin_interface* plugin = 0, void* aux = 0) = 0; // 171
	virtual void start_area_with_window (const sx::rectangle_class& area, sxsdk::window_interface* window, sxsdk::plugin_interface* plugin = 0, void* aux = 0) = 0; // 172
	virtual float get_image_dpi (void * = 0) const = 0; // 173
	virtual rendering_interface &set_image_dpi (float image_dpi_param, void * = 0) = 0; // 174
	virtual sxsdk::image_interface* get_image_layer_image_interface_obsolete (const sx::uuid_class& uuid, void* aux = 0) const = 0; // 175
	virtual void create_image_layer_obsolete (const sx::uuid_class& uuid, const char* name, int pixel_depth = 0, void* aux = 0) = 0; // 176
	virtual bool delete_image_layer_obsolete (const sx::uuid_class& uuid, void* aux = 0) = 0; // 177
	virtual int get_number_of_image_layers_obsolete (void * = 0) const = 0; // 178
	virtual const char* get_image_layer_name_obsolete (const sx::uuid_class& uuid, void* aux = 0) const = 0; // 179
	virtual void set_image_layer_name_obsolete (const sx::uuid_class& uuid, const char* name, void* aux = 0) = 0; // 180
	virtual int get_image_layer_pixel_depth_obsolete (const sx::uuid_class& uuid, void* aux = 0) const = 0; // 181
	virtual void set_image_layer_pixel_depth_obsolete (const sx::uuid_class& uuid, int pixel_depth = 0, void* aux = 0) = 0; // 182
	virtual const sx::uuid_class get_image_layer_uuid_obsolete (int index, void* aux = 0) const = 0; // 183
	virtual int get_setup_user_time (void * = 0) const = 0; // 184
	virtual int get_setup_system_time (void * = 0) const = 0; // 185
	virtual int get_photons_gathering_scale_type (void * = 0) const = 0; // 186
	virtual rendering_interface &set_photons_gathering_scale_type (int photons_gathering_scale_type_param, void * = 0) = 0; // 187
	virtual float get_photons_gathering_adaptive_scale (void * = 0) const = 0; // 188
	virtual rendering_interface &set_photons_gathering_adaptive_scale (float photons_gathering_adaptive_scale_param, void * = 0) = 0; // 189
	virtual float get_photons_caustics_gathering_scale (void * = 0) const = 0; // 190
	virtual rendering_interface &set_photons_caustics_gathering_scale (float photons_caustics_gathering_scale_param, void * = 0) = 0; // 191
	virtual bool get_irradiance_caching (void * = 0) const = 0; // 192
	virtual rendering_interface &set_irradiance_caching (bool irradiance_caching_param, void * = 0) = 0; // 193
	virtual float get_irradiance_cache_tolerance (void * = 0) const = 0; // 194
	virtual rendering_interface &set_irradiance_cache_tolerance (float irradiance_cache_tolerance_param, void * = 0) = 0; // 195
	virtual float get_indirectenergy_factor (void * = 0) const = 0; // 196
	virtual rendering_interface &set_indirectenergy_factor (float indirectenergy_factor_param, void * = 0) = 0; // 197
	virtual rendering_interface &set_pixel_depth (int pixel_depth_param, void * = 0) = 0; // 198
	virtual int get_pixel_depth (void * = 0) const = 0; // 199
	virtual void set_current_camera (sxsdk::shape_class& camera_object, void* aux = 0) = 0; // 200
	virtual rendering_interface &set_multipass_rendering (bool multipass_rendering_param, void * = 0) = 0; // 201
	virtual bool get_multipass_rendering (void * = 0) const = 0; // 202
	virtual void set_image_layer_enable_obsolete (const sx::uuid_class& uuid, bool enable, void* aux = 0) = 0; // 203
	virtual bool get_image_layer_enable_obsolete (const sx::uuid_class& uuid, void* aux = 0) const = 0; // 204
	virtual int get_total_number_of_rendering_blocks (void * = 0) const = 0; // 205
	virtual void start_with_invalidator (rendering_image_invalidator_interface& invalidator, plugin_interface* plugin = 0, void* aux = 0) = 0; // 206
	virtual void start_area_with_invalidator (const sx::rectangle_class& area, rendering_image_invalidator_interface& invalidator, plugin_interface* plugin = 0, void* aux = 0) = 0; // 207
	virtual sxsdk::image_layer_interface* get_image_layer_interface (const char* id_name, void* aux = 0) const = 0; // 208
	virtual sxsdk::image_layer_interface* get_custom_image_layer_interface (const sx::uuid_class& layer_uuid, const char* id_name, void* aux = 0) const = 0; // 209
	virtual sxsdk::image_layer_interface* create_image_layer (const sx::uuid_class& layer_uuid, const char* id_name, int pixel_depth = 0, void* aux = 0) = 0; // 210
	virtual bool delete_image_layer (const char* id_name, void* aux = 0) = 0; // 211
	virtual bool delete_custom_image_layer (const sx::uuid_class& layer_uuid, const char* id_name, void* aux = 0) = 0; // 212
	virtual int get_number_of_image_layers (int type = -1, void* aux = 0) const = 0; // 213
	virtual sxsdk::image_layer_interface* get_image_layer_interface_by_index (unsigned index, int type = -1, void* aux = 0) const = 0; // 214
	virtual void set_image_layer_enable (const char* id_name, bool enable, void* aux = 0) = 0; // 215
	virtual bool get_image_layer_enable (const char* id_name, void* aux = 0) const = 0; // 216
	virtual void set_custom_image_layer_enable (const sx::uuid_class& layer_uuid, const char* id_name, bool enable, void* aux = 0) = 0; // 217
	virtual bool get_custom_image_layer_enable (const sx::uuid_class& layer_uuid, const char* id_name, void* aux = 0) const = 0; // 218
	virtual rendering_interface &set_auto_maximum_distance (bool auto_maximum_distance_param, void * = 0) = 0; // 219
	virtual bool get_auto_maximum_distance (void * = 0) const = 0; // 220
	virtual rendering_interface &set_maximum_distance (float maximum_distance_param, void * = 0) = 0; // 221
	virtual float get_maximum_distance (void * = 0) const = 0; // 222
	virtual rendering_interface &set_no_antialiasing_data_paths (bool no_antialiasing_data_paths_param, void * = 0) = 0; // 223
	virtual bool get_no_antialiasing_data_paths (void * = 0) const = 0; // 224
	virtual void resume_with_invalidator (rendering_image_invalidator_interface& invalidator, plugin_interface* plugin = 0, void* aux = 0) = 0; // 225
	virtual float get_irradiance_gradient (void * = 0) const = 0; // 226
	virtual rendering_interface &set_irradiance_gradient (float irradiance_gradient_param, void * = 0) = 0; // 227
	virtual bool get_always_solve_radiosity (void * = 0) const = 0; // 228
	virtual rendering_interface &set_always_solve_radiosity (bool always_solve_radiosity_param, void * = 0) = 0; // 229
	virtual const char* get_method_name (void * = 0) const = 0; // 230
	virtual graphics_interface* get_graphics (void * = 0) const = 0; // 231
	virtual rendering_interface &set_graphics (graphics_interface* graphics_param, void * = 0) = 0; // 232
	virtual void add_style (const char* name, void* aux = 0) = 0; // 233
	virtual bool get_own_image (void * = 0) const = 0; // 234
	virtual rendering_interface &set_own_image (bool own_image_param, void * = 0) = 0; // 235
	};

	class rendering_image_invalidator_interface : public unknown_interface {
	public:
		virtual ~rendering_image_invalidator_interface () { }
	virtual void block_being_started (const sx::rectangle_class & area, int thread_index, bool server, void* aux = 0) { } // -1
	virtual void block_finished (const sx::rectangle_class & area, int thread_index, bool server, void* aux = 0) { } // -1
	virtual void invalidate (const sx::rectangle_class * area = 0, void* aux = 0) { } // -1
	virtual void rendering_started (void* aux = 0) { } // -1
	virtual void rendering_finished (void* aux = 0) { } // -1
	};
}
