#pragma once

namespace sxsdk {
	class surface_class {
	public:
		virtual ~surface_class () { }
		VTABLE_PADDING
	virtual void save (const char* in, void* aux = 0) = 0; // 0
	virtual void load (const char* from, void* aux = 0) = 0; // 1
	virtual surface_class &set_no_shading (bool no_shading_param, void * = 0) = 0; // 2
	virtual bool get_no_shading (void * = 0) const = 0; // 3
	virtual surface_class &set_do_not_cast_shadow (bool do_not_cast_shadow_param, void * = 0) = 0; // 4
	virtual bool get_do_not_cast_shadow (void * = 0) const = 0; // 5
	virtual surface_class &set_do_not_show_shadow (bool do_not_show_shadow_param, void * = 0) = 0; // 6
	virtual bool get_do_not_show_shadow (void * = 0) const = 0; // 7
	virtual surface_class &set_black_key_mask (bool black_key_mask_param, void * = 0) = 0; // 8
	virtual bool get_black_key_mask (void * = 0) const = 0; // 9
	virtual surface_class &set_white_key_mask (bool white_key_mask_param, void * = 0) = 0; // 10
	virtual bool get_white_key_mask (void * = 0) const = 0; // 11
	virtual surface_class &set_smoother_shading (bool smoother_shading_param, void * = 0) = 0; // 12
	virtual bool get_smoother_shading (void * = 0) const = 0; // 13
	virtual surface_class &set_do_not_reflect (bool do_not_reflect_param, void * = 0) = 0; // 14
	virtual bool get_do_not_reflect (void * = 0) const = 0; // 15
	virtual surface_class &set_texture_transformation (bool texture_transformation_param, void * = 0) = 0; // 16
	virtual bool get_texture_transformation (void * = 0) const = 0; // 17
	virtual surface_class &set_highlight (float highlight_param, void * = 0) = 0; // 18
	virtual float get_highlight (void * = 0) const = 0; // 19
	virtual surface_class &set_highlight_2 (float highlight_2_param, void * = 0) = 0; // 20
	virtual float get_highlight_2 (void * = 0) const = 0; // 21
	virtual surface_class &set_highlight_color (const sxsdk::rgb_class &highlight_color_param, void * = 0) = 0; // 22
	virtual sxsdk::rgb_class get_highlight_color (void * = 0) const = 0; // 23
	virtual surface_class &set_highlight_color_2 (const sxsdk::rgb_class &highlight_color_2_param, void * = 0) = 0; // 24
	virtual sxsdk::rgb_class get_highlight_color_2 (void * = 0) const = 0; // 25
	virtual surface_class &set_highlight_size (float highlight_size_param, void * = 0) = 0; // 26
	virtual float get_highlight_size (void * = 0) const = 0; // 27
	virtual surface_class &set_highlight_size_2 (float highlight_size_2_param, void * = 0) = 0; // 28
	virtual float get_highlight_size_2 (void * = 0) const = 0; // 29
	virtual surface_class &set_reflection (float reflection_param, void * = 0) = 0; // 30
	virtual float get_reflection (void * = 0) const = 0; // 31
	virtual surface_class &set_reflection_color (const sxsdk::rgb_class &reflection_color_param, void * = 0) = 0; // 32
	virtual sxsdk::rgb_class get_reflection_color (void * = 0) const = 0; // 33
	virtual surface_class &set_roughness (float roughness_param, void * = 0) = 0; // 34
	virtual float get_roughness (void * = 0) const = 0; // 35
	virtual surface_class &set_transparency (float transparency_param, void * = 0) = 0; // 36
	virtual float get_transparency (void * = 0) const = 0; // 37
	virtual surface_class &set_transparency_color (const sxsdk::rgb_class &transparency_color_param, void * = 0) = 0; // 38
	virtual sxsdk::rgb_class get_transparency_color (void * = 0) const = 0; // 39
	virtual surface_class &set_refraction (float refraction_param, void * = 0) = 0; // 40
	virtual float get_refraction (void * = 0) const = 0; // 41
	virtual surface_class &set_metallic (float metallic_param, void * = 0) = 0; // 42
	virtual float get_metallic (void * = 0) const = 0; // 43
	virtual surface_class &set_metallic_color (const sxsdk::rgb_class &metallic_color_param, void * = 0) = 0; // 44
	virtual sxsdk::rgb_class get_metallic_color (void * = 0) const = 0; // 45
	virtual surface_class &set_glow (float glow_param, void * = 0) = 0; // 46
	virtual float get_glow (void * = 0) const = 0; // 47
	virtual surface_class &set_soft_glow (float soft_glow_param, void * = 0) = 0; // 48
	virtual float get_soft_glow (void * = 0) const = 0; // 49
	virtual surface_class &set_glow_color (const sxsdk::rgb_class &glow_color_param, void * = 0) = 0; // 50
	virtual sxsdk::rgb_class get_glow_color (void * = 0) const = 0; // 51
	virtual int get_number_of_mapping_layers (void * = 0) const = 0; // 52
	virtual surface_class &set_pseudo_caustics (float pseudo_caustics_param, void * = 0) = 0; // 53
	virtual float get_pseudo_caustics (void * = 0) const = 0; // 54
	virtual surface_class &set_pseudo_caustics_brightness (float pseudo_caustics_brightness_param, void * = 0) = 0; // 55
	virtual float get_pseudo_caustics_brightness (void * = 0) const = 0; // 56
	virtual surface_class &set_pseudo_caustics_bump (float pseudo_caustics_bump_param, void * = 0) = 0; // 57
	virtual float get_pseudo_caustics_bump (void * = 0) const = 0; // 58
	virtual surface_class &set_pseudo_caustics_aberration (float pseudo_caustics_aberration_param, void * = 0) = 0; // 59
	virtual float get_pseudo_caustics_aberration (void * = 0) const = 0; // 60
	virtual surface_class &set_aberration (float aberration_param, void * = 0) = 0; // 61
	virtual float get_aberration (void * = 0) const = 0; // 62
	virtual surface_class &set_backlight (float backlight_param, void * = 0) = 0; // 63
	virtual float get_backlight (void * = 0) const = 0; // 64
	virtual surface_class &set_backlight_color (const sxsdk::rgb_class &backlight_color_param, void * = 0) = 0; // 65
	virtual sxsdk::rgb_class get_backlight_color (void * = 0) const = 0; // 66
	virtual mapping_layer_class& mapping_layer (int i, void* aux = 0) = 0; // 67
	virtual void remove_mapping (int i, void* aux = 0) = 0; // 68
	virtual void insert_mapping (int i, void* aux = 0) = 0; // 69
	virtual void move_mapping (int i, int j, void* aux = 0) = 0; // 70
	virtual surface_class &set_anisotropic (float anisotropic_param, void * = 0) = 0; // 71
	virtual float get_anisotropic (void * = 0) const = 0; // 72
	virtual surface_class &set_fresnel_reflection (float fresnel_reflection_param, void * = 0) = 0; // 73
	virtual float get_fresnel_reflection (void * = 0) const = 0; // 74
	virtual surface_class &set_diffuse (float diffuse_param, void * = 0) = 0; // 75
	virtual float get_diffuse (void * = 0) const = 0; // 76
	virtual surface_class &set_diffuse_color (const sxsdk::rgb_class &diffuse_color_param, void * = 0) = 0; // 77
	virtual sxsdk::rgb_class get_diffuse_color (void * = 0) const = 0; // 78
	virtual surface_class &set_has_diffuse (bool has_diffuse_param, void * = 0) = 0; // 79
	virtual bool get_has_diffuse (void * = 0) const = 0; // 80
	virtual surface_class &set_has_specular_1 (bool has_specular_1_param, void * = 0) = 0; // 81
	virtual bool get_has_specular_1 (void * = 0) const = 0; // 82
	virtual surface_class &set_has_specular_2 (bool has_specular_2_param, void * = 0) = 0; // 83
	virtual bool get_has_specular_2 (void * = 0) const = 0; // 84
	virtual surface_class &set_has_roughness (bool has_roughness_param, void * = 0) = 0; // 85
	virtual bool get_has_roughness (void * = 0) const = 0; // 86
	virtual surface_class &set_has_anisotropic (bool has_anisotropic_param, void * = 0) = 0; // 87
	virtual bool get_has_anisotropic (void * = 0) const = 0; // 88
	virtual surface_class &set_has_reflection (bool has_reflection_param, void * = 0) = 0; // 89
	virtual bool get_has_reflection (void * = 0) const = 0; // 90
	virtual surface_class &set_has_transparency (bool has_transparency_param, void * = 0) = 0; // 91
	virtual bool get_has_transparency (void * = 0) const = 0; // 92
	virtual surface_class &set_has_refraction (bool has_refraction_param, void * = 0) = 0; // 93
	virtual bool get_has_refraction (void * = 0) const = 0; // 94
	virtual surface_class &set_has_fresnel_reflection (bool has_fresnel_reflection_param, void * = 0) = 0; // 95
	virtual bool get_has_fresnel_reflection (void * = 0) const = 0; // 96
	virtual surface_class &set_has_metallic (bool has_metallic_param, void * = 0) = 0; // 97
	virtual bool get_has_metallic (void * = 0) const = 0; // 98
	virtual surface_class &set_has_glow (bool has_glow_param, void * = 0) = 0; // 99
	virtual bool get_has_glow (void * = 0) const = 0; // 100
	virtual surface_class &set_has_backlight (bool has_backlight_param, void * = 0) = 0; // 101
	virtual bool get_has_backlight (void * = 0) const = 0; // 102
	virtual surface_class &set_has_pseudo_caustics (bool has_pseudo_caustics_param, void * = 0) = 0; // 103
	virtual bool get_has_pseudo_caustics (void * = 0) const = 0; // 104
	virtual surface_class &set_has_aberration (bool has_aberration_param, void * = 0) = 0; // 105
	virtual bool get_has_aberration (void * = 0) const = 0; // 106
	virtual surface_class &set_has_aux (bool has_aux_param, void * = 0) = 0; // 107
	virtual bool get_has_aux (void * = 0) const = 0; // 108
	virtual surface_class &set_has_mapping_layers (bool has_mapping_layers_param, void * = 0) = 0; // 109
	virtual bool get_has_mapping_layers (void * = 0) const = 0; // 110
	virtual void append_mapping_layer (void* aux = 0) = 0; // 111
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 112
	virtual surface_class &set_thumbnail_image_interface (sxsdk::image_interface* thumbnail_image_interface_param, void * = 0) = 0; // 113
	virtual sxsdk::image_interface* get_thumbnail_image_interface (void * = 0) const = 0; // 114
	virtual sxsdk::stream_interface* get_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 115
	virtual sxsdk::stream_interface* create_attribute_stream_interface_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 116
	virtual bool delete_attribute_with_uuid (const sx::uuid_class& attribute_id, void* aux = 0) = 0; // 117
	virtual bool find_no_shading (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 118
	virtual bool find_do_not_cast_shadow (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 119
	virtual bool find_do_not_show_shadow (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 120
	virtual bool find_black_key_mask (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 121
	virtual bool find_white_key_mask (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 122
	virtual bool find_smoother_shading (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 123
	virtual bool find_do_not_reflect (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 124
	virtual bool find_texture_transformation (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 125
	virtual float find_highlight (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 126
	virtual float find_highlight_2 (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 127
	virtual sxsdk::rgb_class find_highlight_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 128
	virtual sxsdk::rgb_class find_highlight_color_2 (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 129
	virtual float find_highlight_size (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 130
	virtual float find_highlight_size_2 (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 131
	virtual float find_reflection (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 132
	virtual sxsdk::rgb_class find_reflection_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 133
	virtual float find_roughness (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 134
	virtual float find_transparency (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 135
	virtual sxsdk::rgb_class find_transparency_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 136
	virtual float find_refraction (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 137
	virtual float find_metallic (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 138
	virtual sxsdk::rgb_class find_metallic_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 139
	virtual float find_glow (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 140
	virtual float find_soft_glow (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 141
	virtual sxsdk::rgb_class find_glow_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 142
	virtual int find_number_of_mapping_layers (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 143
	virtual float find_pseudo_caustics (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 144
	virtual float find_pseudo_caustics_brightness (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 145
	virtual float find_pseudo_caustics_bump (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 146
	virtual float find_pseudo_caustics_aberration (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 147
	virtual float find_aberration (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 148
	virtual float find_backlight (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 149
	virtual sxsdk::rgb_class find_backlight_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 150
	virtual mapping_layer_class& find_mapping_layer (int i, const sxsdk::shape_class& shape, void* aux = 0) = 0; // 151
	virtual float find_anisotropic (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 152
	virtual float find_fresnel_reflection (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 153
	virtual float find_diffuse (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 154
	virtual sxsdk::rgb_class find_diffuse_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 155
	virtual surface_class &set_has_volume_density (bool has_volume_density_param, void * = 0) = 0; // 156
	virtual bool get_has_volume_density (void * = 0) const = 0; // 157
	virtual surface_class &set_volume_density (float volume_density_param, void * = 0) = 0; // 158
	virtual float get_volume_density (void * = 0) const = 0; // 159
	virtual bool get_has_shader_node (void * = 0) const = 0; // 160
	virtual surface_class &set_has_shader_node (bool has_shader_node_param, void * = 0) = 0; // 161
	virtual sxsdk::shader_node_class& get_shader_node (void * = 0) const = 0; // 162
	virtual mapping_layer_class& get_current_mapping_layer (void * = 0) const = 0; // 163
	virtual surface_class &set_current_mapping_layer_index (int current_mapping_layer_index_param, void * = 0) = 0; // 164
	virtual int get_current_mapping_layer_index (void * = 0) const = 0; // 165
	virtual bool has_current_mapping_layer (void * = 0) const = 0; // 166
	virtual bool is_master_surface (void * = 0) const = 0; // 167
	virtual void move_up_mapping_layer (int n, int index = -1, void* aux = 0) = 0; // 168
	virtual void move_down_mapping_layer (int n, int index = -1, void* aux = 0) = 0; // 169
	virtual surface_class &set_ambient_color (const sxsdk::rgb_class &ambient_color_param, void * = 0) = 0; // 170
	virtual sxsdk::rgb_class get_ambient_color (void * = 0) const = 0; // 171
	virtual surface_class &set_ambient (const float &ambient_param, void * = 0) = 0; // 172
	virtual float get_ambient (void * = 0) const = 0; // 173
	virtual surface_class &set_has_ambient (bool has_ambient_param, void * = 0) = 0; // 174
	virtual bool get_has_ambient (void * = 0) const = 0; // 175
	virtual float find_ambient (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 176
	virtual sxsdk::rgb_class find_ambient_color (const sxsdk::shape_class& shape, void* aux = 0) const = 0; // 177
	};
}
