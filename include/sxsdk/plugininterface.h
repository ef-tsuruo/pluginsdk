#pragma once

namespace sxsdk {
	class plugin_interface : public unknown_interface {
	public:
		  enum {
			flag_mask = 0xf0000000,
			initialized_flag = 0x10000000, // Initialized from the preference file. (thus should not be overwritten)
			force_flag = 0x20000000,
		  };
		  enum {
			#if SXMACOSX || SXIOS
				#ifndef __COREFOUNDATION_CFSTRINGENCODINGEXT__
					#error
				#endif
				japanese_encoding = kCFStringEncodingMacJapanese,
			#elif SXWINDOWS
				japanese_encoding = 932,
			#else
				japanese_encoding = 1,
			#endif
			utf8_encoding = 0
		  };
		  enum {
			wireframe_pick_mode_flag = 0x01,
			wireframe_bounding_box_mode_flag = 0x02
		  };
	virtual int get_id (void* aux = 0) { return 0; }  // 0
	virtual unknown_interface::property_type_enum get_property_type (int index, void* aux = 0) { return unknown_interface::void_type; } // 1
	virtual int get_property_id (int index, void* aux = 0) { return 0; } // 2
	virtual const char* get_property_name (shade_interface* shade, int index, void* aux = 0) { return 0; } // 3
	virtual void get_bool_property_value (int index, bool& value, void* aux = 0) { } // 4
	virtual void set_bool_property_value (int index, bool value, void* aux = 0) { } // 5
	virtual void get_int_property_value (int index, int& value, void* aux = 0) { } // 6
	virtual void set_int_property_value (int index, int value, void* aux = 0) { } // 7
	virtual void get_float_property_value (int index, float& value, void* aux = 0) { } // 8
	virtual void set_float_property_value (int index, float value, void* aux = 0) { } // 9
	virtual void get_vec3_property_value (int index, sxsdk::vec3& value, void* aux = 0) { } // 10
	virtual void set_vec3_property_value (int index, const sxsdk::vec3& value, void* aux = 0) { } // 11
	virtual void get_rgb_property_value (int index, sxsdk::rgb_class& value, void* aux = 0) { } // 12
	virtual void set_rgb_property_value (int index, const sxsdk::rgb_class& value, void* aux = 0) { } // 13
	virtual void get_selection_property_value (int index, unsigned& value, void* aux = 0) { } // 14
	virtual void set_selection_property_value (int index, unsigned value, void* aux = 0) { } // 15
	virtual void get_string_property_value (int index, const char*& value, void* aux = 0) { } // 16
	virtual void set_string_property_value (int index, const char* value, void* aux = 0) { } // 17
	virtual const char* get_dialog_title (shade_interface* shade, void* aux = 0) { return 0; } // 18
	virtual void get_double_property_value (int index, double& value, void* aux = 0) { } // 19
	virtual void set_double_property_value (int index, double value, void* aux = 0) { } // 20
	virtual const char* get_property_unit (shade_interface* shade, int index, void* aux = 0) { return 0; } // 21
	virtual void shapes_moved (bool& b, sxsdk::scene_interface* scene, int n, sxsdk::shape_class*const* shapes, const sxsdk::mat4& t, void* aux = 0) { b = false; } // 22
	virtual void active_shapes_changed (bool& b, sxsdk::scene_interface* scene, int old_n, sxsdk::shape_class*const* old_shapes, int n, sxsdk::shape_class*const* shapes, void* aux = 0) { b = false; } // 23
	virtual void current_joint_value_changed (bool& b, sxsdk::scene_interface* scene, int n, part_class*const* parts, void* aux = 0) { b = false; } // 24
	virtual void scene_opened (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 25
	virtual void scene_closed (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 26
	virtual void do_it (shade_interface* shade, sxsdk::scene_interface* scene, void* aux = 0) { } // 27
	virtual void camera_changed (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 28
	virtual void sequence_changed (bool& b, float sequence, sxsdk::scene_interface* scene, int n, part_class*const* parts, void* aux = 0) { b = false; } // 29
	virtual void shapes_copied (bool& b, sxsdk::scene_interface* scene, int n, sxsdk::shape_class*const* shapes, const sxsdk::mat4& t, void* aux = 0) { b = false; } // 30
	virtual int get_shade_version () const = 0; // 31
	virtual void name_changed (bool& b, const char* old_name, sxsdk::shape_class& shape, void* aux = 0) { b = false; } // 32
	virtual void shapes_being_deleted (bool& b, sxsdk::scene_interface* scene, int n, sxsdk::shape_class*const* shapes, void* aux = 0) { b = false; } // 33
	virtual void shapes_created (bool& b, sxsdk::scene_interface* scene, int n, sxsdk::shape_class*const* shapes, void* aux = 0) { b = false; } // 34
	virtual void idle_task (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 35
	virtual bool must_remember_properties ( void* aux =0 ) { return true; } // 36
	virtual bool has_reset_button () const { return false; } // Used internally // 37
	virtual bool has_default_button () const { return false; } // USed internally // 38
	virtual const bool* get_bool_default_value ( int index, void* aux =0 ) { return 0; } // 39
	virtual const int* get_int_default_value ( int index, void* aux =0 ) { return 0; } // 40
	virtual const float* get_float_default_value ( int index, void* aux =0 ) { return 0; } // 41
	virtual const sxsdk::vec3* get_vec3_default_value ( int index, void* aux =0 ) { return 0; } // 42
	virtual const sxsdk::rgb_class* get_rgb_default_value ( int index, void* aux =0 ) { return 0; } // 43
	virtual const unsigned* get_selection_default_value ( int index, void* aux =0 ) { return 0; } // 44
	virtual const char* get_string_default_value ( int index, void* aux =0 ) { return 0; } // 45
	virtual const double* get_double_default_value ( int index, void* aux =0 ) { return 0; } // 46
	virtual void mac_event_obsolete ( void* aux =0 ) { } // 47
	virtual bool accepts_sphere (void* aux = 0) const { return false; } // 48
	virtual bool accepts_disk (void* aux = 0) const { return false; } // 49
	virtual bool accepts_rectangle (void* aux = 0) const { return false; } // 50
	virtual bool accepts_translation (void* aux = 0) const { return false; } // 51
	virtual bool set_sphere (const sxsdk::vec3& center, float radius, int axis) { return true; } // 52
	virtual bool set_disk (const sxsdk::vec3& center, float radius, int axis, void* aux = 0) { return true; } // 53
	virtual bool set_rectangle (const sxsdk::vec3& p, const sxsdk::vec3& q, int axis, void* aux = 0) { return true; } // 54
	virtual bool set_translation (const sxsdk::mat4& t, const sxsdk::vec3& p, int axis) { return true; } // 55
	virtual bool select_control ( bool select = true, bool invalidate_flag = true ) { return false; } // 56
	virtual bool pre_create (sxsdk::scene_interface* scene, void* aux = 0) { return true; } // 57
	virtual void joint_matrix (bool& b, part_class& part, float weight, sxsdk::mat4 & t, void* aux = 0) { b = false; } // 58
	virtual void shapes_inserted (bool& b, sxsdk::scene_interface* scene, int n, sxsdk::shape_class*const* shapes, void* aux = 0) { b = false; } // 59
	virtual void current_joint_value_changing (bool& b, sxsdk::scene_interface* scene, int n, part_class*const* parts, void* aux = 0) { b = false; } // 60
	virtual void active_scene_changed (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 61
	virtual bool undoable (void* aux = 0) const { return false; } // 62
	virtual int plugin_interface_test_1 ( void* aux =0 ) { return 1; } // 63
	virtual void make_wireframe_obsolete ( sxsdk::shape_class &shape, const sxsdk::mat4 &mat, int view, void* aux =0 ) { } // 64
	virtual bool accepts_wireframe ( void* aux =0 ) { return false; } // 65
	virtual void append_preference_items ( dialog_interface *dialog, void* aux =0 ) { } // 66
	virtual void preference_ok ( dialog_interface *dialog, void* aux =0 ) { } // 67
	virtual void setup_preference_items ( dialog_interface *dialog, void* aux =0 ) { } // 68
	virtual bool accepts_prequickrendering ( void* aux =0 ) { return false; } // 69
	virtual void prequickrendering ( scene_interface *scene, int view, void* aux =0 ) { } // 70
	virtual void figure_scale_changed (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 71
	virtual void figure_unit_changed (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 72
	virtual void make_wireframe ( sxsdk::shape_class &shape, const sxsdk::mat4 &mat, int view, int flags, void* aux =0 ) { } // 73
	virtual void surface_changed ( bool &b, surface_interface *surface, void* aux =0 ) { b = false; } // 74
	virtual void diffuse_changed ( bool &b, sxsdk::shape_class &shape, void* aux =0 ) { b = false; } // 75
	virtual void surface_being_deleted ( bool &b, surface_interface *surface, void* aux =0 ) { b = false; } // 76
	virtual int get_property_plugin_id ( int index, void* aux =0 ) { return 0; } // 77
	virtual void delete_self ( void* aux =0 ) { } // 78
	virtual void create_line_mode_entered (bool& b, sxsdk::scene_interface* scene, int closed, void* aux = 0) { b = false; } // 79
	virtual void create_line_mode_exited (bool& b, sxsdk::scene_interface* scene, int closed, void* aux = 0) { b = false; } // 80
	virtual void creating_shape_changed (bool& b, sxsdk::shape_class& shape, void* aux = 0) { b = false; } // 81
	virtual const char* get_exception_string () const { return 0; } // 82
	virtual void context ( dll_interface *context, void * = 0 ) { } // 83
	virtual void scene_being_saved (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 84
	virtual void local_light_changed (bool& b, sxsdk::shape_class& shape, void* aux = 0) { b = false; } // 85
	virtual void distant_light_changed (bool& b, sxsdk::scene_interface* scene, int index, void* aux = 0) { b = false; } // 86
	virtual void current_distant_light_index_changed ( bool &b, int index, void * = 0 ) { b = false; } // 87
	virtual void current_mapping_index_changed ( bool &b, int index, void * = 0 ) { b = false; } // 88
	virtual int get_property_lines ( int index, void* aux =0 ) { return 0; } // 89
	virtual void get_rgba_property_value (int index, rgba_class& value, void* aux = 0) { } // 90
	virtual void set_rgba_property_value (int index, const rgba_class& value, void* aux = 0) { } // 91
	virtual void cleanup (void* aux = 0) { } // 92
	virtual void initialize_dialog (sxsdk::dialog_interface& dialog, void* aux = 0) { } // 93
	virtual bool respond (sxsdk::dialog_interface& dialog, dialog_item_class& item, int action, void* aux) { return false; } // 94
	virtual void load_dialog_data (sxsdk::dialog_interface& dialog, void* aux = 0) { } // 95
	virtual void save_dialog_data (sxsdk::dialog_interface& dialog, void* aux = 0) { } // 96
	virtual int terminate (sxsdk::dialog_interface& dialog, int result, void* aux = 0) { return result; } // 97
	virtual void shapes_modified (bool& b, sxsdk::scene_interface* scene, int n, sxsdk::shape_class*const* shapes, void* aux = 0) { b = false; } // 98
	virtual int get_property_flag ( int index, void* aux =0 ) { return 0; } // 99
	virtual void sequence_mode_changed (bool& b, sxsdk::scene_interface* scene, bool sequence_mode, void* aux = 0) { b = false; } // 100
	virtual sx::uuid_class get_uuid (void* aux = 0) { return sxsdk::uuid_from_pluginid(const_cast<plugin_interface &>(*this).get_id()); }  // 101
	virtual sx::uuid_class get_property_plugin_uuid ( int index, void* aux =0 ) { return sx::uuid_class(0u); } // 102
	virtual void browser_updated (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 103
	virtual void surface_updated (bool& b, sxsdk::scene_interface* scene, void* aux = 0) { b = false; } // 104
	virtual void get_list_property_value (int index, std::vector<sx::list_item_value_class>& value, void* aux = 0) { } // 105
	virtual void set_list_property_value (int index, const std::vector<sx::list_item_value_class>& value, void* aux = 0) { } // 106
	virtual void setup_rendering_view (bool& b, rendering_context_interface* rendering_context, void* aux = 0) { b = false; } // 107
	virtual void modify_joint_matrix (bool& b, const sxsdk::shape_class& shape, const sxsdk::joint_value_class & value, float weight, sxsdk::mat4 & t, void* aux = 0) { const part_class *const p = dynamic_cast<const part_class *>(&shape); if (p) joint_matrix(b, *const_cast<part_class *>(p), weight, t); } // 108
	virtual void sound_stopped (bool& b, void* aux = 0) { b = false; } // 109
	virtual void dialog_idle (sxsdk::dialog_interface& dialog, void* aux = 0) { } // 110
	virtual bool can_choose_directory ( int index, void* aux =0 ) { return false; } // 111
	virtual bool can_choose_file ( int index, void* aux =0 ) { return false; } // 112
	virtual bool allow_shading_display (bool& b, sxsdk::shape_class& shape, void* aux = 0) { b = false; return true; } // 113
	virtual const char* get_include_resource_name (const int index, void* aux = 0) { return 0; } // 114
	virtual void create_rendering_objects (bool& b, sxsdk::shape_class& shape, sxsdk::scene_interface& scene, void* aux = 0) { b = false; } // 115
	virtual void pre_rendering (bool& b, rendering_context_interface* rendering_context, void* aux = 0) { b = false; } // 116
	virtual void post_rendering (bool& b, rendering_context_interface* rendering_context) { b = false; } // 117
	virtual bool is_registration (void* aux = 0) { return false; }  // 118
	virtual void register_tags (void* aux = 0) { } // 119
	virtual const char* get_include_resource_from_memory (const int index, void* aux = 0) { return 0; } // 120
	virtual void get_vec2_property_value (int index, sxsdk::vec2& value, void* aux = 0) { } // 121
	virtual void set_vec2_property_value (int index, const sxsdk::vec2& value, void* aux = 0) { } // 122
	virtual const sxsdk::vec2* get_vec2_default_value ( int index, void* aux =0 ) { return 0; } // 123
	virtual int plugin_interface_dummy124(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 124
	virtual int plugin_interface_dummy125(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 125
	virtual int plugin_interface_dummy126(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 126
	virtual int plugin_interface_dummy127(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 127
	virtual int plugin_interface_dummy128(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 128
	virtual int plugin_interface_dummy129(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 129
	virtual int plugin_interface_dummy130(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 130
	virtual int plugin_interface_dummy131(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 131
	virtual int plugin_interface_dummy132(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 132
	virtual int plugin_interface_dummy133(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 133
	virtual int plugin_interface_dummy134(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 134
	virtual int plugin_interface_dummy135(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 135
	virtual int plugin_interface_dummy136(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 136
	virtual int plugin_interface_dummy137(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 137
	virtual int plugin_interface_dummy138(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 138
	virtual int plugin_interface_dummy139(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 139
	virtual int plugin_interface_dummy140(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 140
	virtual int plugin_interface_dummy141(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 141
	virtual int plugin_interface_dummy142(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 142
	virtual int plugin_interface_dummy143(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 143
	virtual int plugin_interface_dummy144(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 144
	virtual int plugin_interface_dummy145(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 145
	virtual int plugin_interface_dummy146(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 146
	virtual int plugin_interface_dummy147(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 147
	virtual int plugin_interface_dummy148(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 148
	virtual int plugin_interface_dummy149(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 149
	virtual int plugin_interface_dummy150(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 150
	virtual int plugin_interface_dummy151(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 151
	virtual int plugin_interface_dummy152(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 152
	virtual int plugin_interface_dummy153(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 153
	virtual int plugin_interface_dummy154(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 154
	virtual int plugin_interface_dummy155(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 155
	virtual int plugin_interface_dummy156(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 156
	virtual int plugin_interface_dummy157(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 157
	virtual int plugin_interface_dummy158(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 158
	virtual int plugin_interface_dummy159(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 159
	virtual int plugin_interface_dummy160(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 160
	virtual int plugin_interface_dummy161(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 161
	virtual int plugin_interface_dummy162(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 162
	virtual int plugin_interface_dummy163(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 163
	virtual int plugin_interface_dummy164(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 164
	virtual int plugin_interface_dummy165(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 165
	virtual int plugin_interface_dummy166(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 166
	virtual int plugin_interface_dummy167(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 167
	virtual int plugin_interface_dummy168(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 168
	virtual int plugin_interface_dummy169(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 169
	virtual int plugin_interface_dummy170(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 170
	virtual int plugin_interface_dummy171(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 171
	virtual int plugin_interface_dummy172(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 172
	virtual int plugin_interface_dummy173(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 173
	virtual int plugin_interface_dummy174(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 174
	virtual int plugin_interface_dummy175(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 175
	virtual int plugin_interface_dummy176(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 176
	virtual int plugin_interface_dummy177(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 177
	virtual int plugin_interface_dummy178(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 178
	virtual int plugin_interface_dummy179(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 179
	virtual int plugin_interface_dummy180(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 180
	virtual int plugin_interface_dummy181(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 181
	virtual int plugin_interface_dummy182(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 182
	virtual int plugin_interface_dummy183(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 183
	virtual int plugin_interface_dummy184(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 184
	virtual int plugin_interface_dummy185(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 185
	virtual int plugin_interface_dummy186(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 186
	virtual int plugin_interface_dummy187(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 187
	virtual int plugin_interface_dummy188(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 188
	virtual int plugin_interface_dummy189(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 189
	virtual int plugin_interface_dummy190(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 190
	virtual int plugin_interface_dummy191(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 191
	virtual int plugin_interface_dummy192(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 192
	virtual int plugin_interface_dummy193(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 193
	virtual int plugin_interface_dummy194(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 194
	virtual int plugin_interface_dummy195(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 195
	virtual int plugin_interface_dummy196(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 196
	virtual int plugin_interface_dummy197(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 197
	virtual int plugin_interface_dummy198(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 198
	virtual int plugin_interface_dummy199(void *) { assert(false); throw "invalid interface plugin_interface"; return 0; } // 199
int version () const { try { return get_shade_version(); } catch (int v) { return v; }; return 0; } 
sx::uuid_class uuid () { if (390398 <= version()) return const_cast<plugin_interface &>(*this).get_uuid(); return sxsdk::uuid_from_pluginid(const_cast<plugin_interface &>(*this).get_id()); } 
	};
}
