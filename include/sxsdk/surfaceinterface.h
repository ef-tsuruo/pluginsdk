#pragma once

namespace sxsdk {
	class surface_interface : public shade_interface {
	public:
		enum type_enum { // for R4 compatibility 
			no_mapping, 
			check, 
			marble, 
			spotted, 
			bumpy, 
			wrinkle, 
			wave, 
			waves, 
			stripe, 
			picture_mapping, 
			bump_mapping, 
			metallic, 
			woody, 
			log, 
			reflection_mapping, 
			transparency_mapping, 
			trim_mapping, 
			holes, 
			end 
		}; 
		virtual ~surface_interface ();
	virtual void save (const char*const& in, void* aux = 0) = 0; // 0
	virtual void load (const char*const& from, void* aux = 0) = 0; // 1
	virtual void set_mapping_origin (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 2
	virtual sxsdk::vec3 get_mapping_origin (int i, void* aux = 0) = 0; // 3
	virtual surface_interface &set_no_shading (bool no_shading_param, void * = 0) = 0; // 4
	virtual bool get_no_shading (void * = 0) const = 0; // 5
	virtual surface_interface &set_dont_cast_shadow (bool dont_cast_shadow_param, void * = 0) = 0; // 6
	virtual bool get_dont_cast_shadow (void * = 0) const = 0; // 7
	virtual surface_interface &set_dont_show_shadow (bool dont_show_shadow_param, void * = 0) = 0; // 8
	virtual bool get_dont_show_shadow (void * = 0) const = 0; // 9
	virtual surface_interface &set_black_key_mask (bool black_key_mask_param, void * = 0) = 0; // 10
	virtual bool get_black_key_mask (void * = 0) const = 0; // 11
	virtual surface_interface &set_white_key_mask (bool white_key_mask_param, void * = 0) = 0; // 12
	virtual bool get_white_key_mask (void * = 0) const = 0; // 13
	virtual int surface_interface_dummy14(void *) { assert(false); throw "invalid interface surface_interface"; return 0; } // 14
	virtual int surface_interface_dummy15(void *) { assert(false); throw "invalid interface surface_interface"; return 0; } // 15
	virtual void set_back_light_obsolete (bool b, void* aux = 0) = 0; // 16
	virtual bool get_back_light_obsolete (void* aux = 0) = 0; // 17
	virtual surface_interface &set_smoother_shading (bool smoother_shading_param, void * = 0) = 0; // 18
	virtual bool get_smoother_shading (void * = 0) const = 0; // 19
	virtual surface_interface &set_dracula (bool dracula_param, void * = 0) = 0; // 20
	virtual bool get_dracula (void * = 0) const = 0; // 21
	virtual surface_interface &set_texture_transformation (bool texture_transformation_param, void * = 0) = 0; // 22
	virtual bool get_texture_transformation (void * = 0) const = 0; // 23
	virtual surface_interface &set_highlight (float highlight_param, void * = 0) = 0; // 24
	virtual float get_highlight (void * = 0) const = 0; // 25
	virtual surface_interface &set_highlight_2 (float highlight_2_param, void * = 0) = 0; // 26
	virtual float get_highlight_2 (void * = 0) const = 0; // 27
	virtual surface_interface &set_highlight_color (const sxsdk::rgb_class &highlight_color_param, void * = 0) = 0; // 28
	virtual sxsdk::rgb_class get_highlight_color (void * = 0) const = 0; // 29
	virtual surface_interface &set_highlight_color_2 (const sxsdk::rgb_class &highlight_color_2_param, void * = 0) = 0; // 30
	virtual sxsdk::rgb_class get_highlight_color_2 (void * = 0) const = 0; // 31
	virtual surface_interface &set_highlight_size (float highlight_size_param, void * = 0) = 0; // 32
	virtual float get_highlight_size (void * = 0) const = 0; // 33
	virtual surface_interface &set_highlight_size_2 (float highlight_size_2_param, void * = 0) = 0; // 34
	virtual float get_highlight_size_2 (void * = 0) const = 0; // 35
	virtual surface_interface &set_reflection (float reflection_param, void * = 0) = 0; // 36
	virtual float get_reflection (void * = 0) const = 0; // 37
	virtual surface_interface &set_reflection_color (const sxsdk::rgb_class &reflection_color_param, void * = 0) = 0; // 38
	virtual sxsdk::rgb_class get_reflection_color (void * = 0) const = 0; // 39
	virtual surface_interface &set_roughness (float roughness_param, void * = 0) = 0; // 40
	virtual float get_roughness (void * = 0) const = 0; // 41
	virtual surface_interface &set_transparency (float transparency_param, void * = 0) = 0; // 42
	virtual float get_transparency (void * = 0) const = 0; // 43
	virtual surface_interface &set_transparency_color (const sxsdk::rgb_class &transparency_color_param, void * = 0) = 0; // 44
	virtual sxsdk::rgb_class get_transparency_color (void * = 0) const = 0; // 45
	virtual surface_interface &set_refraction (float refraction_param, void * = 0) = 0; // 46
	virtual float get_refraction (void * = 0) const = 0; // 47
	virtual surface_interface &set_metallic (float metallic_param, void * = 0) = 0; // 48
	virtual float get_metallic (void * = 0) const = 0; // 49
	virtual surface_interface &set_metallic_color (const sxsdk::rgb_class &metallic_color_param, void * = 0) = 0; // 50
	virtual sxsdk::rgb_class get_metallic_color (void * = 0) const = 0; // 51
	virtual surface_interface &set_glow (float glow_param, void * = 0) = 0; // 52
	virtual float get_glow (void * = 0) const = 0; // 53
	virtual surface_interface &set_soft_glow (float soft_glow_param, void * = 0) = 0; // 54
	virtual float get_soft_glow (void * = 0) const = 0; // 55
	virtual surface_interface &set_glow_color (const sxsdk::rgb_class &glow_color_param, void * = 0) = 0; // 56
	virtual sxsdk::rgb_class get_glow_color (void * = 0) const = 0; // 57
	virtual int get_number_of_mapping_layers (void * = 0) const = 0; // 58
	virtual void set_texture (int i, surface_interface::type_enum e, void* aux = 0) = 0; // 59
	virtual surface_interface::type_enum get_texture (int i, void* aux = 0) = 0; // 60
	virtual void set_mapping (int i, float mapping, void* aux = 0) = 0; // 61
	virtual float get_mapping (int i, void* aux = 0) = 0; // 62
	virtual void set_mapping_color (int i, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 63
	virtual sxsdk::rgb_class get_mapping_color (int i, void* aux = 0) = 0; // 64
	virtual void set_mapping_size (int i, float size, void* aux = 0) = 0; // 65
	virtual float get_mapping_size (int i, void* aux = 0) = 0; // 66
	virtual void set_turbulence (int i, float turbulence, void* aux = 0) = 0; // 67
	virtual float get_turbulence (int i, void* aux = 0) = 0; // 68
	virtual void set_softness (int i, float softness, void* aux = 0) = 0; // 69
	virtual float get_softness (int i, void* aux = 0) = 0; // 70
	virtual void set_horizontal_flip (int i, bool flip, void* aux = 0) = 0; // 71
	virtual bool get_horizontal_flip (int i, void* aux = 0) = 0; // 72
	virtual void set_vertical_flip (int i, bool flip, void* aux = 0) = 0; // 73
	virtual bool get_vertical_flip (int i, void* aux = 0) = 0; // 74
	virtual void set_swap_axes (int i, bool swap, void* aux = 0) = 0; // 75
		void set_swap_axis (int i, bool swap, void* aux = 0) { set_swap_axes(i, swap); }
	virtual bool get_swap_axes (int i, void* aux = 0) = 0; // 76
		bool get_swap_axis (int i, void* aux = 0) { return get_swap_axes(i); }
	virtual void set_flip (int i, bool flip, void* aux = 0) = 0; // 77
	virtual bool get_flip (int i, void* aux = 0) = 0; // 78
	virtual void set_smooth_mapping (int i, bool b, void* aux = 0) = 0; // 79
	virtual bool get_smooth_mapping (int i, void* aux = 0) = 0; // 80
	virtual void set_mapping_projection (int i, int j, void* aux = 0) = 0; // 81
	virtual int get_mapping_projection (int i, void* aux = 0) = 0; // 82
	virtual void set_repetition_x (int i, int n, void* aux = 0) = 0; // 83
	virtual int get_repetition_x (int i, void* aux = 0) = 0; // 84
	virtual void set_repetition_y (int i, int n, void* aux = 0) = 0; // 85
	virtual int get_repetition_y (int i, void* aux = 0) = 0; // 86
	virtual bool is_master_surface (void * = 0) const = 0; // 87
	virtual void load_mapping_image (int i, const char*const& path, void* aux = 0) = 0; // 88
	virtual sxsdk::image_interface* get_mapping_image_interface (int i, void* aux = 0) = 0; // 89
	virtual surface_interface &set_pseudo_caustics (float pseudo_caustics_param, void * = 0) = 0; // 90
	virtual float get_pseudo_caustics (void * = 0) const = 0; // 91
	virtual void create_mapping_image (int i, int width, int height, void* aux = 0) = 0; // 92
	virtual surface_interface* create_duplicate_surface_interface (void* aux = 0) = 0; // 93
		surface_interface* clone (void* aux = 0) { return create_duplicate_surface_interface(); }
	virtual surface_interface &set_pseudo_caustics_brightness (float pseudo_caustics_brightness_param, void * = 0) = 0; // 94
	virtual float get_pseudo_caustics_brightness (void * = 0) const = 0; // 95
	virtual surface_interface &set_pseudo_caustics_bump (float pseudo_caustics_bump_param, void * = 0) = 0; // 96
	virtual float get_pseudo_caustics_bump (void * = 0) const = 0; // 97
	virtual surface_interface &set_pseudo_caustics_aberration (float pseudo_caustics_aberration_param, void * = 0) = 0; // 98
	virtual float get_pseudo_caustics_aberration (void * = 0) const = 0; // 99
	virtual surface_interface &set_aberration (float aberration_param, void * = 0) = 0; // 100
	virtual float get_aberration (void * = 0) const = 0; // 101
	virtual void set_phase (int i, float phase, void* aux = 0) = 0; // 102
	virtual float get_phase (int i, void* aux = 0) = 0; // 103
	virtual void set_mapping_area (int i, const sx::rectangle_class& area, void* aux = 0) = 0; // 104
	virtual sx::rectangle_class get_mapping_area (int i, void* aux = 0) = 0; // 105
	virtual void update_preview_image (void* aux = 0) = 0; // 106
	virtual void set_mapping_image (int i, sxsdk::image_interface* image, void* aux = 0) = 0; // 107
	virtual surface_interface &set_backlight (float backlight_param, void * = 0) = 0; // 108
	virtual float get_backlight (void * = 0) const = 0; // 109
	virtual surface_interface &set_backlight_color (const sxsdk::rgb_class &backlight_color_param, void * = 0) = 0; // 110
	virtual sxsdk::rgb_class get_backlight_color (void * = 0) const = 0; // 111
	virtual enums::pattern_type get_pattern_type (int i, void* aux = 0) = 0; // 112
	virtual void set_pattern_type (int i, enums::pattern_type pattern_type, void* aux = 0) = 0; // 113
	virtual enums::mapping_type get_mapping_type (int i, void* aux = 0) = 0; // 114
	virtual void set_mapping_type (int i, enums::mapping_type mapping_type, void* aux = 0) = 0; // 115
	virtual sxsdk::mat4 get_mapping_transformation (int i, void* aux = 0) = 0; // 116
	virtual void set_mapping_transformation (int i, const sxsdk::mat4& t, void* aux = 0) = 0; // 117
	virtual void update (void* aux = 0) = 0; // 118
	virtual mapping_layer_class& mapping_layer (int i, void* aux = 0) = 0; // 119
	virtual sxsdk::stream_interface* get_attribute_stream_interface (int id, void* aux = 0) = 0; // 120
	virtual sxsdk::stream_interface* create_attribute_stream_interface (int id, void* aux = 0) = 0; // 121
	virtual int surface_interface_test_1 ( void* aux =0 ) { return 1; } // 122
	virtual bool delete_attribute (int id, void* aux = 0) = 0; // 123
	virtual void set_parameter_mapping (int i, bool b, void* aux = 0) = 0; // 124
	virtual bool get_parameter_mapping (int i, void* aux = 0) = 0; // 125
	virtual sxsdk::scene_interface* get_scene_interface (void * = 0) const = 0; // 126
	virtual shape_interface* get_shape_interface (void* aux = 0) = 0; // 127
	virtual sxsdk::shape_class* get_shape (void * = 0) const = 0; // 128
	virtual void remove_mapping (int i, void* aux = 0) = 0; // 129
	virtual void insert_mapping (int i, void* aux = 0) = 0; // 130
	virtual void move_mapping (int i, int j, void* aux = 0) = 0; // 131
	virtual const char* get_pattern_name (int pattern, void* aux = 0) = 0; // 132
	virtual int get_active_layer (void * = 0) const = 0; // 133
	virtual surface_interface &set_active_layer (int active_layer_param, void * = 0) = 0; // 134
	virtual surface_interface &set_anisotropic (float anisotropic_param, void * = 0) = 0; // 135
	virtual float get_anisotropic (void * = 0) const = 0; // 136
	virtual surface_interface &set_fresnel_reflection (float fresnel_reflection_param, void * = 0) = 0; // 137
	virtual float get_fresnel_reflection (void * = 0) const = 0; // 138
	virtual bool has_current_mapping_layer (void * = 0) const = 0; // 139
	virtual mapping_layer_class& get_current_mapping_layer (void * = 0) const = 0; // 140
	virtual surface_interface &set_diffuse (float diffuse_param, void * = 0) = 0; // 141
	virtual float get_diffuse (void * = 0) const = 0; // 142
	virtual surface_interface &set_diffuse_color (const sxsdk::rgb_class &diffuse_color_param, void * = 0) = 0; // 143
	virtual sxsdk::rgb_class get_diffuse_color (void * = 0) const = 0; // 144
	virtual surface_interface &set_has_diffuse (bool has_diffuse_param, void * = 0) = 0; // 145
	virtual bool get_has_diffuse (void * = 0) const = 0; // 146
	virtual surface_interface &set_has_specular_1 (bool has_specular_1_param, void * = 0) = 0; // 147
	virtual bool get_has_specular_1 (void * = 0) const = 0; // 148
	virtual surface_interface &set_has_specular_2 (bool has_specular_2_param, void * = 0) = 0; // 149
	virtual bool get_has_specular_2 (void * = 0) const = 0; // 150
	virtual surface_interface &set_has_roughness (bool has_roughness_param, void * = 0) = 0; // 151
	virtual bool get_has_roughness (void * = 0) const = 0; // 152
	virtual surface_interface &set_has_anisotropic (bool has_anisotropic_param, void * = 0) = 0; // 153
	virtual bool get_has_anisotropic (void * = 0) const = 0; // 154
	virtual surface_interface &set_has_reflection (bool has_reflection_param, void * = 0) = 0; // 155
	virtual bool get_has_reflection (void * = 0) const = 0; // 156
	virtual surface_interface &set_has_transparency (bool has_transparency_param, void * = 0) = 0; // 157
	virtual bool get_has_transparency (void * = 0) const = 0; // 158
	virtual surface_interface &set_has_refraction (bool has_refraction_param, void * = 0) = 0; // 159
	virtual bool get_has_refraction (void * = 0) const = 0; // 160
	virtual surface_interface &set_has_fresnel_reflection (bool has_fresnel_reflection_param, void * = 0) = 0; // 161
	virtual bool get_has_fresnel_reflection (void * = 0) const = 0; // 162
	virtual surface_interface &set_has_metallic (bool has_metallic_param, void * = 0) = 0; // 163
	virtual bool get_has_metallic (void * = 0) const = 0; // 164
	virtual surface_interface &set_has_glow (bool has_glow_param, void * = 0) = 0; // 165
	virtual bool get_has_glow (void * = 0) const = 0; // 166
	virtual surface_interface &set_has_backlight (bool has_backlight_param, void * = 0) = 0; // 167
	virtual bool get_has_backlight (void * = 0) const = 0; // 168
	virtual surface_interface &set_has_pseudo_caustics (bool has_pseudo_caustics_param, void * = 0) = 0; // 169
	virtual bool get_has_pseudo_caustics (void * = 0) const = 0; // 170
	virtual surface_interface &set_has_aberration (bool has_aberration_param, void * = 0) = 0; // 171
	virtual bool get_has_aberration (void * = 0) const = 0; // 172
	virtual surface_interface &set_has_aux (bool has_aux_param, void * = 0) = 0; // 173
	virtual bool get_has_aux (void * = 0) const = 0; // 174
	virtual surface_interface &set_has_mapping_layers (bool has_mapping_layers_param, void * = 0) = 0; // 175
	virtual bool get_has_mapping_layers (void * = 0) const = 0; // 176
	virtual surface_interface &set_current_mapping_layer_index (int current_mapping_layer_index_param, void * = 0) = 0; // 177
	virtual int get_current_mapping_layer_index (void * = 0) const = 0; // 178
	virtual void append_mapping_layer (void* aux = 0) = 0; // 179
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 180
	virtual surface_interface &set_thumbnail_image_interface (sxsdk::image_interface* thumbnail_image_interface_param, void * = 0) = 0; // 181
	virtual sxsdk::image_interface* get_thumbnail_image_interface (void * = 0) const = 0; // 182
	virtual sxsdk::stream_interface* get_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 183
	virtual sxsdk::stream_interface* create_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 184
	virtual bool delete_attribute_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 185
	virtual surface_interface &set_has_volume_density (bool has_volume_density_param, void * = 0) = 0; // 186
	virtual bool get_has_volume_density (void * = 0) const = 0; // 187
	virtual surface_interface &set_volume_density (float volume_density_param, void * = 0) = 0; // 188
	virtual float get_volume_density (void * = 0) const = 0; // 189
	virtual surface_interface &set_ambient_color (const sxsdk::rgb_class &ambient_color_param, void * = 0) = 0; // 190
	virtual sxsdk::rgb_class get_ambient_color (void * = 0) const = 0; // 191
	virtual surface_interface &set_ambient (const float &ambient_param, void * = 0) = 0; // 192
	virtual float get_ambient (void * = 0) const = 0; // 193
	virtual surface_interface &set_has_ambient (bool has_ambient_param, void * = 0) = 0; // 194
	virtual bool get_has_ambient (void * = 0) const = 0; // 195
	virtual float find_ambient (const sxsdk::shape_class& shape, void* aux = 0) = 0; // 196
	};
}
