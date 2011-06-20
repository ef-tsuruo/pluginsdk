#pragma once

#ifndef DEFINE_DYNAMIC_CAST
	#define DEFINE_DYNAMIC_CAST(class_name, base_name, shape_type) static class_name &cast (base_name &s) { if (s.get_type() != shape_type) throw std::bad_cast(); return static_cast<class_name &>(s); } static const class_name &cast (const base_name &s) { if (s.get_type() != shape_type) throw std::bad_cast(); return static_cast<const class_name &>(s); } static class_name *cast (base_name *s) { if (s && s->get_type() != shape_type) return 0; return static_cast<class_name *>(s); } static const class_name *cast (const base_name *s) { if (s && s->get_type() != shape_type) return 0; return static_cast<const class_name *>(s); }
#endif

namespace sxsdk {
	class shape_class {
	public:
		virtual ~shape_class () { }
		VTABLE_PADDING
 
	class const_iterator; 
	class const_reverse_iterator; 
 
	class iterator {  
	public:  
		typedef std::bidirectional_iterator_tag iterator_category;  
		typedef shape_class value_type; 
		typedef std::size_t difference_type; 
		typedef shape_class *pointer; 
		typedef shape_class &reference; 
		explicit iterator (shape_class *p) : p(p) { }  
		operator shape_class * () const { return p; }  
		iterator operator++ () { p = p->get_bro(); return *this; }  
		iterator operator++ (int) { iterator q = *this; p = p->get_bro(); return q; }  
		iterator operator-- () { p = p->get_sis(); return *this; }  
		iterator operator-- (int) { iterator q = *this; p = p->get_sis(); return q; }  
		shape_class &operator* () const { return *p; }  
		shape_class *operator-> () const { return p; }  
		friend class const_iterator;  
	private:  
		shape_class *p;  
	};  
 
	class const_iterator {  
	public:  
		typedef std::bidirectional_iterator_tag iterator_category;  
		typedef const shape_class value_type; 
		typedef std::size_t difference_type; 
		typedef const shape_class *pointer; 
		typedef const shape_class &reference; 
		explicit const_iterator (const shape_class *p) : p(p) { }  
		const_iterator (const iterator &i) : p(i.p) { }  
		operator const shape_class * () const { return p; }  
		const_iterator operator++ () { p = p->get_bro(); return *this; }  
		const_iterator operator++ (int) { const_iterator q = *this; p = p->get_bro(); return q; }  
		const_iterator operator-- () { p = p->get_sis(); return *this; }  
		const_iterator operator-- (int) { const_iterator q = *this; p = p->get_sis(); return q; }  
		const shape_class &operator* () const { return *p; }  
		const shape_class *operator-> () const { return p; }  
	private:  
		const shape_class *p;  
	};  
 
	class reverse_iterator {  
	public:  
		typedef std::bidirectional_iterator_tag iterator_category;  
		typedef shape_class value_type; 
		typedef std::size_t difference_type; 
		typedef shape_class *pointer; 
		typedef shape_class &reference; 
		explicit reverse_iterator (shape_class *p) : p(p) { }  
		operator shape_class * () const { return p; }  
		reverse_iterator operator++ () { p = p->get_sis(); return *this; }  
		reverse_iterator operator++ (int) { reverse_iterator q = *this; p = p->get_sis(); return q; }  
		reverse_iterator operator-- () { p = p->get_bro(); return *this; }  
		reverse_iterator operator-- (int) { reverse_iterator q = *this; p = p->get_bro(); return q; } 
		shape_class &operator* () const { return *p; }  
		shape_class *operator-> () const { return p; }  
		friend class const_reverse_iterator;  
	private:  
		shape_class *p;  
	};  
 
	class const_reverse_iterator {  
	public:  
		typedef std::bidirectional_iterator_tag iterator_category;  
		typedef const shape_class value_type; 
		typedef std::size_t difference_type; 
		typedef const shape_class *pointer; 
		typedef const shape_class &reference; 
		explicit const_reverse_iterator (const shape_class *p) : p(p) { } 
		const_reverse_iterator (const reverse_iterator &i) : p(i.p) { } 
		operator const shape_class * () const { return p; } 
		const_reverse_iterator operator++ () { p = p->get_sis(); return *this; }  
		const_reverse_iterator operator++ (int) { const_reverse_iterator q = *this; p = p->get_sis(); return q; }  
		const_reverse_iterator operator-- () { p = p->get_bro(); return *this; } 
		const_reverse_iterator operator-- (int) { const_reverse_iterator q = *this; p = p->get_bro(); return q; } 
		const shape_class &operator* () const { return *p; } 
		const shape_class *operator-> () const { return p; } 
	private: 
		const shape_class *p; 
	}; 
 
	virtual sxsdk::scene_interface* get_scene_interface (void * = 0) const = 0; // 0
	virtual surface_interface* get_surface_interface (void * = 0) const = 0; // 1
	virtual sxsdk::motion_interface* get_motion_interface (void * = 0) const = 0; // 2
	virtual sxsdk::shape_class* get_bro (void * = 0) const = 0; // 3
	virtual sxsdk::shape_class* get_sis (void * = 0) const = 0; // 4
	virtual part_class* get_dad (void * = 0) const = 0; // 5
	virtual sxsdk::shape_class* get_son (void * = 0) const = 0; // 6
	virtual enums::shape_type get_type (void * = 0) const = 0; // 7
	virtual void* get_handle (void * = 0) const = 0; // 8
	virtual sxsdk::rgb_class get_color_obsolete (void* aux = 0) = 0; // 9
	virtual bool is_one_of_active_shapes (void * = 0) const = 0; // 10
	virtual iterator begin (void* aux = 0) const = 0; // 11
	virtual iterator end (void* aux = 0) const = 0; // 12
	virtual sxsdk::mat4 get_transformation (void * = 0) const = 0; // 13
	virtual int get_number_of_points (void * = 0) const = 0; // 14
	virtual sxsdk::vec3 get_point (int i, void* aux = 0) = 0; // 15
	virtual void set_point (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 16
	virtual shape_class &set_name (const char* name_param, void * = 0) = 0; // 17
	virtual const char* get_name (void * = 0) const = 0; // 18
	virtual shape_class &set_extrude (const sxsdk::vec3 &extrude_param, void * = 0) = 0; // 19
	virtual sxsdk::vec3 get_extrude (void * = 0) const = 0; // 20
	virtual shape_class &set_revolve_from (float revolve_from_param, void * = 0) = 0; // 21
	virtual float get_revolve_from (void * = 0) const = 0; // 22
	virtual shape_class &set_revolve_to (float revolve_to_param, void * = 0) = 0; // 23
	virtual float get_revolve_to (void * = 0) const = 0; // 24
	virtual bool get_has_surface_attributes (void * = 0) const = 0; // 25
	virtual shape_class &set_has_surface_attributes (bool has_surface_attributes_param, void * = 0) = 0; // 26
	virtual shape_class &set_has_diffuse_color_deprecated (bool has_diffuse_color_deprecated_param, void * = 0) = 0; // 27
	virtual bool get_has_diffuse_color_deprecated (void * = 0) const = 0; // 28
	virtual void set_base_color_deprecated (const sxsdk::rgb_class& color, void* aux = 0) = 0; // 29
	virtual sxsdk::rgb_class get_diffuse_color_deprecated (void * = 0) const = 0; // 30
	virtual shape_class &set_master_surface (sxsdk::master_surface_class* master_surface_param, void * = 0) = 0; // 31
	virtual sxsdk::master_surface_class* get_master_surface (void * = 0) const = 0; // 32
	virtual const part_class& get_part (void* aux = 0) const = 0; // 33
	virtual part_class& get_part (void* aux = 0) = 0; // 34
	virtual const line_class& get_line (void* aux = 0) const = 0; // 35
	virtual line_class& get_line (void* aux = 0) = 0; // 36
	virtual const polygon_mesh_class& get_polygon_mesh (void* aux = 0) const = 0; // 37
	virtual polygon_mesh_class& get_polygon_mesh (void* aux = 0) = 0; // 38
	virtual const disk_class& get_disk (void* aux = 0) const = 0; // 39
	virtual disk_class& get_disk (void* aux = 0) = 0; // 40
	virtual const sphere_class& get_sphere (void* aux = 0) const = 0; // 41
	virtual sphere_class& get_sphere (void* aux = 0) = 0; // 42
	virtual const light_class& get_light (void* aux = 0) const = 0; // 43
	virtual light_class& get_light (void* aux = 0) = 0; // 44
	virtual sxsdk::vec3 get_center_point (void * = 0) const = 0; // 45
	virtual sxsdk::mat4 get_local_to_world_matrix (void * = 0) const = 0; // 46
	virtual sxsdk::mat4 get_world_to_local_matrix (void * = 0) const = 0; // 47
	virtual void transform (const sxsdk::mat4& matrix, void* aux = 0) = 0; // 48
	virtual bool has_surface (void* aux = 0) = 0; // 49
	virtual bool has_motion (void * = 0) const = 0; // 50
	virtual bool has_bro (void * = 0) const = 0; // 51
	virtual bool has_sis (void * = 0) const = 0; // 52
	virtual bool has_dad (void * = 0) const = 0; // 53
	virtual bool has_son (void * = 0) const = 0; // 54
	virtual void remove (void* aux = 0) = 0; // 55
	virtual bool is_extruded (void * = 0) const = 0; // 56
	virtual bool is_revolved (void * = 0) const = 0; // 57
	virtual sxsdk::mat4 get_axis_matrix (void * = 0) const = 0; // 58
	virtual shape_class &set_flip_face (bool flip_face_param, void * = 0) = 0; // 59
	virtual bool get_flip_face (void * = 0) const = 0; // 60
	virtual int get_total_number_of_control_points (void * = 0) const = 0; // 61
	virtual void cancel_transformation (void* aux = 0) = 0; // 62
	virtual mesh_interface* convert_to_mesh_obsolete (int m = 0, int n = 0, void* aux = 0) = 0; // 63
	virtual sxsdk::stream_interface* create_attribute_stream_interface (int stream_id, int wireframe_id = 0, int intersection_id = 0, void* aux = 0) = 0; // 64
		sxsdk::stream_interface* create_attribute_stream (int stream_id, int wireframe_id = 0, int intersection_id = 0, void* aux = 0) { return create_attribute_stream_interface(stream_id, wireframe_id, intersection_id); }
	virtual sxsdk::stream_interface* get_attribute_stream_interface (int stream_id, void* aux = 0) = 0; // 65
		sxsdk::stream_interface* get_attribute_stream (int stream_id, void* aux = 0) { return get_attribute_stream_interface(stream_id); }
	virtual void make_sphere_wireframe (const sxsdk::mat4& mat, const sxsdk::mat4& trans, void* aux = 0) = 0; // 66
	virtual void set_axis_matrix (const sxsdk::mat4& to, void* aux = 0) = 0; // 67
	virtual int get_ordinal (void * = 0) const = 0; // 68
	virtual void set_surface (surface_interface* surface, void* aux = 0) = 0; // 69
	virtual void make_line_wireframe (const sxsdk::mat4& mat, int n, const sxsdk::vec3* p, bool closed = false, void* aux = 0) = 0; // 70
	virtual void update (void* aux = 0) = 0; // 71
	virtual void begin_set_point (void* aux = 0) = 0; // 72
	virtual void end_set_point (void* aux = 0) = 0; // 73
	virtual void show (void* aux = 0) = 0; // 74
	virtual void hide (void* aux = 0) = 0; // 75
	virtual bool delete_attribute (int id, void* aux = 0) = 0; // 76
	virtual void place_parent (int n, void* aux = 0) = 0; // 77
	virtual void place_child (int n, void* aux = 0) = 0; // 78
	virtual void place_brother (int n, void* aux = 0) = 0; // 79
	virtual void place_sister (int n, void* aux = 0) = 0; // 80
	virtual void place (sxsdk::shape_class& at, void* aux = 0) = 0; // 81
	virtual shape_interface* get_shape_interface (void* aux = 0) = 0; // 82
	virtual void copy (void* aux = 0) = 0; // 83
	virtual void paste (void* aux = 0) = 0; // 84
	virtual bool is_switched (void * = 0) const = 0; // 85
	virtual sxsdk::shape_class& copy_object (const sxsdk::mat4& t, void* aux = 0) = 0; // 86
	virtual void move_object (const sxsdk::mat4& t, void* aux = 0) = 0; // 87
	virtual bool is_shown (void * = 0) const = 0; // 88
	virtual float get_diffuse_value_deprecated (void * = 0) const = 0; // 89
	virtual shape_class &set_diffuse_value_deprecated (float diffuse_value_deprecated_param, void * = 0) = 0; // 90
	virtual void solid_extrude (const sxsdk::vec3& by, void* aux = 0) = 0; // 91
	virtual void solid_revolve (const sxsdk::vec3& v0, const sxsdk::vec3& v1, void* aux = 0) = 0; // 92
	virtual void solid_clear (void* aux = 0) = 0; // 93
	virtual void reset_transformation (bool deep = false, void* aux = 0) = 0; // 94
	virtual meshes_interface* create_converted_meshes_interface (int level = 2, int texture = 0, void* aux = 0) = 0; // 95
	virtual polygon_mesh_interface* create_converted_polygon_mesh_interface (int level = 2, int texture = 0, void* aux = 0) = 0; // 96
	virtual void adjust_transformation (void* aux = 0) = 0; // 97
	virtual bool get_modifiable (void * = 0) const = 0; // 98
	virtual shape_class &set_modifiable (bool modifiable_param, void * = 0) = 0; // 99
	virtual bool get_browsable (void * = 0) const = 0; // 100
	virtual shape_class &set_browsable (bool browsable_param, void * = 0) = 0; // 101
	virtual int get_render_flag (void * = 0) const = 0; // 102
	virtual shape_class &set_render_flag (int render_flag_param, void * = 0) = 0; // 103
	virtual void set_active_control_point (int at, bool select, void* aux = 0) = 0; // 104
	virtual bool get_active_control_point (int at, void* aux = 0) = 0; // 105
	virtual void append_skin (part_class& part, float weight = 1.0, void* aux = 0) = 0; // 106
	virtual void clear_skin (void* aux = 0) = 0; // 107
	virtual void select (void* aux = 0) = 0; // 108
void activate (void* aux = 0) { select(); }
	virtual void select_all_control_points (bool select, void* aux = 0) = 0; // 109
	virtual bool is_control_point_selected (int i, void* aux = 0) = 0; // 110
	virtual bool get_rendering_flag_obsolete (void* aux = 0) {return true;} // 111
	virtual shape_class &set_has_shadow_map_size (bool has_shadow_map_size_param, void * = 0) = 0; // 112
	virtual bool get_has_shadow_map_size (void * = 0) const = 0; // 113
	virtual shape_class &set_shadow_map_size (int shadow_map_size_param, void * = 0) = 0; // 114
	virtual int get_shadow_map_size (void * = 0) const = 0; // 115
	virtual shape_class &set_has_shadow_map_bias (bool has_shadow_map_bias_param, void * = 0) = 0; // 116
	virtual bool get_has_shadow_map_bias (void * = 0) const = 0; // 117
	virtual shape_class &set_shadow_map_bias (float shadow_map_bias_param, void * = 0) = 0; // 118
	virtual float get_shadow_map_bias (void * = 0) const = 0; // 119
	virtual shape_class &set_has_shadow_map_blur (bool has_shadow_map_blur_param, void * = 0) = 0; // 120
	virtual bool get_has_shadow_map_blur (void * = 0) const = 0; // 121
	virtual shape_class &set_shadow_map_blur (float shadow_map_blur_param, void * = 0) = 0; // 122
	virtual float get_shadow_map_blur (void * = 0) const = 0; // 123
	virtual shape_class &set_shadow_type (sxsdk::enums::shadow_type shadow_type_param, void * = 0) = 0; // 124
	virtual sxsdk::enums::shadow_type get_shadow_type (void * = 0) const = 0; // 125
	virtual const char* get_error_string (void* aux = 0) = 0; // 126
	virtual int get_active_control_points (int* p, void* aux = 0) = 0; // 127
	virtual int get_error_code (void* aux = 0) = 0; // 128
	virtual bool has_special_character (char c, void* aux = 0) = 0; // 129
	virtual void set_diffuse_color (const sxsdk::rgb_class& color, void* aux = 0) = 0; // 130
	virtual part_class& link_object (const sxsdk::mat4& t, void* aux = 0) = 0; // 131
	virtual shape_saver_interface* create_shape_saver_interface (void* aux = 0) = 0; // 132
	virtual sxsdk::texture_interface* create_texture_interface (int self = 0, const sxsdk::vec3& point = sxsdk::vec3(0.0f,0.0f,0.0f), const sxsdk::vec3& shading_normal = sxsdk::vec3(0.0f,1.0f,0.0f), const sxsdk::vec3& geometric_normal = sxsdk::vec3(0.0f,1.0f,0.0f), const sxsdk::vec3& incident = sxsdk::vec3(0.0f,0.0f,-1.0f), const sxsdk::vec2* uv = 0, const sxsdk::vec3* du = 0, const sxsdk::vec3* dv = 0, const sxsdk::vec4* uvs = 0) = 0; // 133
	virtual sxsdk::radiosity_attributes_interface* get_radiosity_attributes_interface (void * = 0) const = 0; // 134
	virtual int get_links (part_class* list[], void * = 0) const = 0; // 135
	virtual void move_links (const sxsdk::mat4& t, void* aux = 0) = 0; // 136
	virtual part_class* get_linked_dad (void * = 0) const = 0; // 137
	virtual const char* get_exception_string () const { return 0; } // 138
	virtual skin_class& get_skin_deprecated (int i, void* aux = 0) = 0; // 139
	virtual int get_number_of_skin_points (void * = 0) const = 0; // 140
	virtual bool has_symbol (char symbol, void* aux = 0) = 0; // 141
	virtual bool is_container (void * = 0) const = 0; // 142
	virtual sxsdk::control_point_class& control_point (int i, void* aux = 0) = 0; // 143
	virtual bool is_rotator_joint (void * = 0) const = 0; // 144
	virtual bool is_slider_joint (void * = 0) const = 0; // 145
	virtual bool is_scale_joint (void * = 0) const = 0; // 146
	virtual bool is_uniscale_joint (void * = 0) const = 0; // 147
	virtual bool is_light_effector (void * = 0) const = 0; // 148
	virtual bool is_path_joint (void * = 0) const = 0; // 149
	virtual bool is_morph_effector (void * = 0) const = 0; // 150
	virtual bool is_ball_joint (void * = 0) const = 0; // 151
	virtual bool is_custom_joint (void * = 0) const = 0; // 152
	virtual sxsdk::rotator_joint_interface* get_rotator_joint_interface (void * = 0) const = 0; // 153
	virtual sxsdk::slider_joint_interface* get_slider_joint_interface (void * = 0) const = 0; // 154
	virtual sxsdk::scale_joint_interface* get_scale_joint_interface (void * = 0) const = 0; // 155
	virtual sxsdk::uniscale_joint_interface* get_uniscale_joint_interface (void * = 0) const = 0; // 156
	virtual sxsdk::light_effector_interface* get_light_effector_interface (void * = 0) const = 0; // 157
	virtual sxsdk::path_joint_interface* get_path_joint_interface (void * = 0) const = 0; // 158
	virtual sxsdk::morph_effector_interface* get_morph_effector_interface (void * = 0) const = 0; // 159
	virtual sxsdk::ball_joint_interface* get_ball_joint_interface (void * = 0) const = 0; // 160
	virtual sxsdk::custom_joint_interface* get_custom_joint_interface (void * = 0) const = 0; // 161
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 162
	virtual skin_class& get_skin (void * = 0) const = 0; // 163
	virtual surface_interface* get_nonnil_surface_interface (void * = 0) const = 0; // 164
	virtual void inactivate (void* aux = 0) = 0; // 165
	virtual sxsdk::stream_interface* create_attribute_stream_interface_with_uuid (const sx::uuid_class& stream_id, const sx::uuid_class& wireframe_id = sxsdk::uuid_from_pluginid(0), const sx::uuid_class& intersection_id = sxsdk::uuid_from_pluginid(0), const sx::uuid_class& renderingobject_id = sxsdk::uuid_from_pluginid(0), void* aux = 0) = 0; // 166
	virtual sxsdk::stream_interface* get_attribute_stream_interface_with_uuid (const sx::uuid_class& stream_id, void* aux = 0) const = 0; // 167
	virtual bool delete_attribute_with_uuid (const sx::uuid_class& stream_id, void* aux = 0) = 0; // 168
	virtual const proxy_shape_class& get_proxy_shape (void* aux = 0) const = 0; // 169
	virtual proxy_shape_class& get_proxy_shape (void* aux = 0) = 0; // 170
	virtual surface_class* get_surface (void * = 0) const = 0; // 171
	virtual sxsdk::shape_class* get_parent (void * = 0) const = 0; // 172
	virtual sxsdk::shape_class* get_linked_parent (void * = 0) const = 0; // 173
	virtual void push_transformation_matrix (void* aux = 0) = 0; // 174
	virtual void pop_transformation_matrix (void* aux = 0) = 0; // 175
	virtual shape_class &set_rendering (int rendering_param, void * = 0) = 0; // 176
	virtual int get_rendering (void * = 0) const = 0; // 177
	virtual void convert_to_polygon_mesh_with_subdivision_level (int level, void* aux = 0) = 0; // 178
	virtual void convert_to_polygon_mesh_with_divisions (int lateral_division, int longitudinal_division, void* aux = 0) = 0; // 179
	virtual void convert_to_polygon_mesh_with (int level = -1, int lateral = -1, int longitudinal = -1, void* aux = 0) = 0; // 180
	virtual int get_shadow_catcher (void * = 0) const = 0; // 181
	virtual shape_class &set_shadow_catcher (int shadow_catcher_param, void * = 0) = 0; // 182
	virtual void invalidate_vertex_array (void* aux = 0) = 0; // 183
	virtual sxsdk::sound_track_interface* get_sound_track_interface (void * = 0) const = 0; // 184
	virtual bool is_sound_track (void * = 0) const = 0; // 185
	virtual reverse_iterator rbegin (void* aux = 0) const = 0; // 186
	virtual reverse_iterator rend (void* aux = 0) const = 0; // 187
	virtual const master_image_class& get_master_image (void* aux = 0) const = 0; // 188
	virtual master_image_class& get_master_image (void* aux = 0) = 0; // 189
	virtual void set_related_shape (const sx::uuid_class& relation_id, sxsdk::shape_class* shape, void* aux = 0) = 0; // 190
	virtual int get_related_shapes (const sx::uuid_class& relation_id, sxsdk::shape_class** shapes = 0, void* aux = 0) = 0; // 191
	virtual void delete_relation (const sx::uuid_class& relation_id, sxsdk::shape_class* shape = 0, void* aux = 0) = 0; // 192
	virtual bool is_switch_effector (void * = 0) const = 0; // 193
	virtual sxsdk::switch_effector_interface* get_switch_effector_interface (void * = 0) const = 0; // 194
	virtual implementation_interface& get_implementation (void * = 0) const = 0; // 195
	virtual int shape_class_dummy196(void *) { assert(false); throw "invalid interface shape_class"; return 0; } // 196
	virtual int shape_class_dummy197(void *) { assert(false); throw "invalid interface shape_class"; return 0; } // 197
	virtual int shape_class_dummy198(void *) { assert(false); throw "invalid interface shape_class"; return 0; } // 198
	virtual int shape_class_dummy199(void *) { assert(false); throw "invalid interface shape_class"; return 0; } // 199
int get_tag_intValue (const char* tagName, void* aux = 0) { return get_implementation().get_tag_intValue(*this,tagName); }
double get_tag_doubleValue (const char* tagName, void* aux = 0) { return get_implementation().get_tag_doubleValue(*this,tagName); }
float get_tag_floatValue (const char* tagName, void* aux = 0) { return get_implementation().get_tag_floatValue(*this,tagName); }
const char* get_tag_stringValue (const char* tagName, void* aux = 0) { return get_implementation().get_tag_stringValue(*this,tagName); }
bool get_tag_boolValue (const char* tagName, void* aux = 0) { return get_implementation().get_tag_boolValue(*this,tagName); }
void set_tag_intValue (const char* tagName, int value, void* aux = 0) { get_implementation().set_tag_intValue(*this,tagName,value); }
void set_tag_doubleValue (const char* tagName, double value, void* aux = 0) { get_implementation().set_tag_doubleValue(*this,tagName,value); }
void set_tag_floatValue (const char* tagName, float value, void* aux = 0) { get_implementation().set_tag_floatValue(*this,tagName,value); }
void set_tag_stringValue (const char* tagName, const char* value, void* aux = 0) { get_implementation().set_tag_stringValue(*this,tagName,value); }
void set_tag_boolValue (const char* tagName, bool value, void* aux = 0) { get_implementation().set_tag_boolValue(*this,tagName,value); }
int tag_value_type (const char* tagName, void* aux = 0) { return get_implementation().tag_value_type(*this,tagName); }
std::vector<const char*> tags (void* aux = 0) { return get_implementation().tags(*this); }
bool has_tag (const char* tagName, void* aux = 0) { return get_implementation().has_tag(*this,tagName); }
void remove_tag (const char* tagName, void* aux = 0) { get_implementation().remove_tag(*this,tagName); }
sx::uuid_class get_uuid (void * = 0) const { return get_implementation().uuid(*this); }
polygon_mesh_interface * create_converted_polygon_mesh_interface (int level, int texture, bool triangulate, bool divide, void* aux = 0) { return get_implementation().create_converted_polygon_mesh_interface(*this, level, texture, triangulate, divide); }
sxsdk::mat4 get_sequence_transformation (float sequence_value, void* aux = 0) const { return get_implementation().get_sequence_transformation(*this, sequence_value); }
sxsdk::mat4 get_sequence_joint_matrix (float sequence_value, void* aux = 0) const { return get_implementation().get_sequence_joint_matrix(*this, sequence_value); }
sxsdk::points_interface* create_converted_polyline_points_interface (int level = 2, void* aux = 0) { return get_implementation().create_converted_polyline_points_interface(*this, level); }
sxsdk::mat4 get_sequence_local_to_world_matrix (float sequence_value, void* aux = 0) const { return get_implementation().get_sequence_local_to_world_matrix(*this, sequence_value); }
sxsdk::mat4 get_sequence_world_to_local_matrix (float sequence_value, void* aux = 0) const { return get_implementation().get_sequence_world_to_local_matrix(*this, sequence_value); }
bool is_path_replicator (void * = 0) const { return get_implementation().is_path_replicator(*this); }
sxsdk::path_replicator_interface* get_path_replicator_interface (void * = 0) const { return get_implementation().get_path_replicator_interface(*this); }
shape_class &set_bounding_box_size (sxsdk::vec3 bounding_box_size_param, void * = 0) { get_implementation().set_bounding_box_size(*this, bounding_box_size_param); return *this; }
sxsdk::vec3 get_bounding_box_size (void * = 0) const { return get_implementation().get_bounding_box_size(*this); }
surface_class& get_surface_reference (void * = 0) const { return get_implementation().get_surface_reference(*this); }
shape_class &set_bounding_box_center (sxsdk::vec3 bounding_box_center_param, void * = 0) { get_implementation().set_bounding_box_center(*this, bounding_box_center_param); return *this; }
sxsdk::vec3 get_bounding_box_center (void * = 0) const { return get_implementation().get_bounding_box_center(*this); }
shape_class &set_active_vertex_indices (int n, int list[], void * = 0) { get_implementation().set_active_vertex_indices(*this, n, list); return *this; }
int get_active_vertex_indices (int list[], void * = 0) const { return get_implementation().get_active_vertex_indices(*this, list); }
void update_skin_bindings () { get_implementation().update_skin_bindings(*this); }
sxsdk::texture_interface* create_texture_interface2 (int self = 0, const sxsdk::vec3& point = sxsdk::vec3(0.0f,0.0f,0.0f), const sxsdk::vec3& shading_normal = sxsdk::vec3(0.0f,1.0f,0.0f), const sxsdk::vec3& geometric_normal = sxsdk::vec3(0.0f,1.0f,0.0f), const sxsdk::vec3& incident = sxsdk::vec3(0.0f,0.0f,-1.0f), const sxsdk::vec2* uv = 0, const sxsdk::vec3* du = 0, const sxsdk::vec3* dv = 0, int n_uvs = 0, const sxsdk::vec2* uvs = 0, sxsdk::master_surface_class* master_surface = 0) { return get_implementation().create_texture_interface2(*this, self, point, shading_normal, geometric_normal, incident, uv, du, dv, n_uvs, uvs, master_surface); }
	};

	class sentinel_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(sentinel_class , shape_class , enums::sentinel)	
	};

	class insert_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(insert_class , shape_class , enums::dxf_insert)	
	};

	class part_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(part_class , shape_class , enums::part)	
	virtual shape_saver_interface* create_shape_saver_interface (void* aux = 0) = 0; // -1
	virtual enums::part_type get_part_type (void * = 0) const = 0; // 0
	virtual bool is_master_surface (void * = 0) const = 0; // 1
	virtual int get_number_of_sons (void * = 0) const = 0; // 2
	virtual bool has_skip_joint_obsolete (void* aux = 0) { return false; } // 3
	virtual bool is_pose_joint (void * = 0) const = 0; // 4
	virtual part_class &set_transformation_matrix (const sxsdk::mat4 &transformation_matrix_param, void * = 0) = 0; // 5
	virtual sxsdk::mat4 get_transformation_matrix (void * = 0) const = 0; // 6
	virtual void switch_ (void* aux = 0) = 0; // 7
	virtual void set_anchor_point_deprecated (int i, const sxsdk::vec3& p, const bool* world_coordinates) = 0; // 8
	virtual sxsdk::vec3 get_anchor_point_deprecated (int i, const bool* world_coordinates) = 0; // 9
	virtual void set_inhandle_deprecated (int i, const sxsdk::vec3& v, const bool* world_coordinates) = 0; // 10
	virtual sxsdk::vec3 get_inhandle_deprecated (int i, const bool* world_coordinates) = 0; // 11
	virtual void set_outhandle_deprecated (int i, const sxsdk::vec3& v, const bool* world_coordinates) = 0; // 12
	virtual sxsdk::vec3 get_outhandle_deprecated (int i, const bool* world_coordinates) = 0; // 13
	virtual void set_handle_linked_deprecated (int i, bool b, void* aux = 0) = 0; // 14
	virtual bool get_handle_linked_deprecated (int i, void* aux = 0) = 0; // 15
	virtual void set_lateral_inhandle_deprecated (int i, const sxsdk::vec3& v, const bool* world_coordinates) = 0; // 16
	virtual sxsdk::vec3 get_lateral_inhandle_deprecated (int i, const bool* world_coordinates) = 0; // 17
	virtual void set_lateral_outhandle_deprecated (int i, const sxsdk::vec3& v, const bool* world_coordinates) = 0; // 18
	virtual sxsdk::vec3 get_lateral_outhandle_deprecated (int i, const bool* world_coordinates) = 0; // 19
	virtual void set_lateral_handle_linked_deprecated (int i, bool b, void* aux = 0) = 0; // 20
	virtual bool get_lateral_handle_linked_deprecated (int i, void* aux = 0) = 0; // 21
	virtual part_class &set_closed (bool closed_param, void * = 0) = 0; // 22
	virtual bool get_closed (void * = 0) const = 0; // 23
	virtual int get_number_of_active_control_points (void * = 0) const = 0; // 24
	virtual int get_first_active_control_point_deprecated (void * = 0) const = 0; // 25
	virtual int get_next_active_control_point_deprecated (void * = 0) const = 0; // 26
	virtual void select_all_control_points_obsolete (void* aux = 0) = 0; // 27
	virtual void unselect_all_control_points_obsolete (void* aux = 0) = 0; // 28
	virtual void select_control_point_obsolete (int i, void* aux = 0) = 0; // 29
	virtual void remove_control_point (int i, void* aux = 0) = 0; // 30
	virtual bool get_surface_closed (void * = 0) const = 0; // 31
	virtual part_class &set_surface_closed (bool surface_closed_param, void * = 0) = 0; // 32
	virtual bool get_surface_switched (void * = 0) const = 0; // 33
	virtual part_class &set_surface_switched (bool surface_switched_param, void * = 0) = 0; // 34
	virtual sxsdk::mat4 get_joint_matrix (void * = 0) const = 0; // 35
	virtual bool get_flat_joint (void * = 0) const = 0; // 36
	virtual part_class &set_flat_joint (bool flat_joint_param, void * = 0) = 0; // 37
	virtual void reverse (void* aux = 0) = 0; // 38
	virtual void iron (int n = -1, const int* i = 0, void* aux = 0) = 0; // 39
	virtual void smooth (int n = -1, const int* i = 0, void* aux = 0) = 0; // 40
	virtual void unsmooth (int n = -1, const int* i = 0, void* aux = 0) = 0; // 41
	virtual part_interface* get_part_interface (void* aux = 0) = 0; // 42
	virtual bool get_disclosed (void * = 0) const = 0; // 43
	virtual part_class &set_disclosed (bool disclosed_param, void * = 0) = 0; // 44
	virtual surface_saver_class* get_surface_saver (void* aux = 0) = 0; // 45
	virtual void disclose_all (void* aux = 0) = 0; // 46
	virtual void undisclose_all (void* aux = 0) = 0; // 47
	virtual bool has_inhandle_deprecated (int i, void* aux = 0) = 0; // 48
	virtual bool has_outhandle_deprecated (int i, void* aux = 0) = 0; // 49
	virtual bool has_lateral_inhandle_deprecated (int i, void* aux = 0) = 0; // 50
	virtual bool has_lateral_outhandle_deprecated (int i, void* aux = 0) = 0; // 51
	virtual void remove_inhandle_deprecated (int i, void* aux = 0) = 0; // 52
	virtual void remove_outhandle_deprecated (int i, void* aux = 0) = 0; // 53
	virtual void remove_lateral_inhandle_deprecated (int i, void* aux = 0) = 0; // 54
	virtual void remove_lateral_outhandle_deprecated (int i, void* aux = 0) = 0; // 55
	virtual mesh_interface* create_control_mesh_interface (void* aux = 0) = 0; // 56
		mesh_interface* get_control_mesh (void* aux = 0) { return create_control_mesh_interface(); }
	virtual float get_joint_blend (void * = 0) const = 0; // 57
	virtual part_class &set_joint_blend (float joint_blend_param, void * = 0) = 0; // 58
	virtual void set_view (void* aux = 0) = 0; // 59
	virtual sxsdk::enums::anchor_type get_view_anchor (void * = 0) const = 0; // 60
	virtual part_class &set_view_anchor (sxsdk::enums::anchor_type view_anchor_param, void * = 0) = 0; // 61
	virtual void select_camera_joint (void* aux = 0) = 0; // 62
	virtual sxsdk::shape_class* get_link_master (void * = 0) const = 0; // 63
	virtual part_class &set_link_master (sxsdk::shape_class* link_master_param, void * = 0) = 0; // 64
	virtual part_class &set_group (bool group_param, void * = 0) = 0; // 65
	virtual bool get_group (void * = 0) const = 0; // 66
	virtual bool is_master_image (void * = 0) const = 0; // 67
	virtual bool is_master_shape (void * = 0) const = 0; // 68
	virtual const master_shape_class& get_master_shape (void* aux = 0) const = 0; // 69
	virtual master_shape_class& get_master_shape (void* aux = 0) = 0; // 70
	virtual void setup_surface_part_polygonmesh (int level = 2, void* aux = 0) = 0; // 71
	virtual void clean_surface_part_polygonmesh (void* aux = 0) = 0; // 72
	virtual int get_number_of_vertices (void * = 0) const = 0; // 73
	virtual int get_number_of_edges (void * = 0) const = 0; // 74
	virtual int get_number_of_faces (void * = 0) const = 0; // 75
	virtual void setup_plane_equation (void* aux = 0) = 0; // 76
	virtual sxsdk::vec4 get_plane_equation (int f, void* aux = 0) = 0; // 77
	virtual vertex_class& vertex (int i, void* aux = 0) = 0; // 78
	virtual edge_class& edge (int i, void* aux = 0) = 0; // 79
	virtual face_class& face (int i, void* aux = 0) = 0; // 80
	virtual int part_class_dummy81(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 81
	virtual int part_class_dummy82(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 82
	virtual int part_class_dummy83(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 83
	virtual int part_class_dummy84(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 84
	virtual int part_class_dummy85(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 85
	virtual int part_class_dummy86(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 86
	virtual int part_class_dummy87(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 87
	virtual int part_class_dummy88(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 88
	virtual int part_class_dummy89(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 89
	virtual int part_class_dummy90(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 90
	virtual int part_class_dummy91(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 91
	virtual int part_class_dummy92(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 92
	virtual int part_class_dummy93(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 93
	virtual int part_class_dummy94(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 94
	virtual int part_class_dummy95(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 95
	virtual int part_class_dummy96(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 96
	virtual int part_class_dummy97(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 97
	virtual int part_class_dummy98(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 98
	virtual int part_class_dummy99(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 99
	virtual int part_class_dummy100(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 100
	virtual int part_class_dummy101(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 101
	virtual int part_class_dummy102(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 102
	virtual int part_class_dummy103(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 103
	virtual int part_class_dummy104(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 104
	virtual int part_class_dummy105(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 105
	virtual int part_class_dummy106(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 106
	virtual int part_class_dummy107(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 107
	virtual int part_class_dummy108(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 108
	virtual int part_class_dummy109(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 109
	virtual int part_class_dummy110(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 110
	virtual int part_class_dummy111(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 111
	virtual int part_class_dummy112(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 112
	virtual int part_class_dummy113(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 113
	virtual int part_class_dummy114(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 114
	virtual int part_class_dummy115(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 115
	virtual int part_class_dummy116(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 116
	virtual int part_class_dummy117(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 117
	virtual int part_class_dummy118(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 118
	virtual int part_class_dummy119(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 119
	virtual int part_class_dummy120(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 120
	virtual int part_class_dummy121(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 121
	virtual int part_class_dummy122(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 122
	virtual int part_class_dummy123(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 123
	virtual int part_class_dummy124(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 124
	virtual int part_class_dummy125(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 125
	virtual int part_class_dummy126(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 126
	virtual int part_class_dummy127(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 127
	virtual int part_class_dummy128(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 128
	virtual int part_class_dummy129(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 129
	virtual int part_class_dummy130(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 130
	virtual int part_class_dummy131(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 131
	virtual int part_class_dummy132(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 132
	virtual int part_class_dummy133(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 133
	virtual int part_class_dummy134(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 134
	virtual int part_class_dummy135(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 135
	virtual int part_class_dummy136(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 136
	virtual int part_class_dummy137(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 137
	virtual int part_class_dummy138(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 138
	virtual int part_class_dummy139(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 139
	virtual int part_class_dummy140(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 140
	virtual int part_class_dummy141(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 141
	virtual int part_class_dummy142(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 142
	virtual int part_class_dummy143(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 143
	virtual int part_class_dummy144(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 144
	virtual int part_class_dummy145(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 145
	virtual int part_class_dummy146(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 146
	virtual int part_class_dummy147(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 147
	virtual int part_class_dummy148(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 148
	virtual int part_class_dummy149(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 149
	virtual int part_class_dummy150(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 150
	virtual int part_class_dummy151(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 151
	virtual int part_class_dummy152(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 152
	virtual int part_class_dummy153(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 153
	virtual int part_class_dummy154(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 154
	virtual int part_class_dummy155(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 155
	virtual int part_class_dummy156(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 156
	virtual int part_class_dummy157(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 157
	virtual int part_class_dummy158(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 158
	virtual int part_class_dummy159(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 159
	virtual int part_class_dummy160(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 160
	virtual int part_class_dummy161(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 161
	virtual int part_class_dummy162(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 162
	virtual int part_class_dummy163(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 163
	virtual int part_class_dummy164(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 164
	virtual int part_class_dummy165(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 165
	virtual int part_class_dummy166(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 166
	virtual int part_class_dummy167(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 167
	virtual int part_class_dummy168(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 168
	virtual int part_class_dummy169(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 169
	virtual int part_class_dummy170(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 170
	virtual int part_class_dummy171(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 171
	virtual int part_class_dummy172(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 172
	virtual int part_class_dummy173(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 173
	virtual int part_class_dummy174(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 174
	virtual int part_class_dummy175(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 175
	virtual int part_class_dummy176(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 176
	virtual int part_class_dummy177(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 177
	virtual int part_class_dummy178(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 178
	virtual int part_class_dummy179(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 179
	virtual int part_class_dummy180(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 180
	virtual int part_class_dummy181(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 181
	virtual int part_class_dummy182(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 182
	virtual int part_class_dummy183(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 183
	virtual int part_class_dummy184(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 184
	virtual int part_class_dummy185(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 185
	virtual int part_class_dummy186(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 186
	virtual int part_class_dummy187(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 187
	virtual int part_class_dummy188(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 188
	virtual int part_class_dummy189(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 189
	virtual int part_class_dummy190(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 190
	virtual int part_class_dummy191(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 191
	virtual int part_class_dummy192(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 192
	virtual int part_class_dummy193(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 193
	virtual int part_class_dummy194(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 194
	virtual int part_class_dummy195(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 195
	virtual int part_class_dummy196(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 196
	virtual int part_class_dummy197(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 197
	virtual int part_class_dummy198(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 198
	virtual int part_class_dummy199(void *) { assert(false); throw "invalid interface part_class"; return 0; } // 199
	};

	class plugin_filereference_class {
	public:
		enum { not_found, failed_to_load, recursive };
		enum { shape_type, surface_type, image_type };
		virtual ~plugin_filereference_class () { }
		virtual char* ask (const char* path, const char* name, int type, int number_of_extensions, char** extensions) { return 0; }
		virtual bool alert (int error_type, const char* path, const char* name, int file_type, int number_of_extensions, char** extensions) { return true; }
	};

	class master_shape_class : public part_class {
	public:
		DEFINE_DYNAMIC_CAST(master_shape_class , part_class , enums::part)	
	virtual master_shape_class &set_path (const char* path_param, void * = 0) = 0; // 0
	virtual const char* get_path (void * = 0) const = 0; // 1
	virtual bool update_external_reference (bool ask = true, void* aux = 0) = 0; // 2
	virtual bool update_external_reference (plugin_filereference_class& resolver, void* aux = 0) = 0; // 3
	virtual void unlink_external_reference (bool ask, bool unlink_all = false, void* aux = 0) = 0; // 4
	virtual bool file_exists (void* aux = 0) = 0; // 5
	virtual bool has_external_reference (void* aux = 0) = 0; // 6
	virtual int master_shape_class_dummy7(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 7
	virtual int master_shape_class_dummy8(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 8
	virtual int master_shape_class_dummy9(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 9
	virtual int master_shape_class_dummy10(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 10
	virtual int master_shape_class_dummy11(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 11
	virtual int master_shape_class_dummy12(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 12
	virtual int master_shape_class_dummy13(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 13
	virtual int master_shape_class_dummy14(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 14
	virtual int master_shape_class_dummy15(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 15
	virtual int master_shape_class_dummy16(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 16
	virtual int master_shape_class_dummy17(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 17
	virtual int master_shape_class_dummy18(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 18
	virtual int master_shape_class_dummy19(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 19
	virtual int master_shape_class_dummy20(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 20
	virtual int master_shape_class_dummy21(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 21
	virtual int master_shape_class_dummy22(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 22
	virtual int master_shape_class_dummy23(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 23
	virtual int master_shape_class_dummy24(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 24
	virtual int master_shape_class_dummy25(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 25
	virtual int master_shape_class_dummy26(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 26
	virtual int master_shape_class_dummy27(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 27
	virtual int master_shape_class_dummy28(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 28
	virtual int master_shape_class_dummy29(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 29
	virtual int master_shape_class_dummy30(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 30
	virtual int master_shape_class_dummy31(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 31
	virtual int master_shape_class_dummy32(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 32
	virtual int master_shape_class_dummy33(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 33
	virtual int master_shape_class_dummy34(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 34
	virtual int master_shape_class_dummy35(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 35
	virtual int master_shape_class_dummy36(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 36
	virtual int master_shape_class_dummy37(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 37
	virtual int master_shape_class_dummy38(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 38
	virtual int master_shape_class_dummy39(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 39
	virtual int master_shape_class_dummy40(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 40
	virtual int master_shape_class_dummy41(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 41
	virtual int master_shape_class_dummy42(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 42
	virtual int master_shape_class_dummy43(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 43
	virtual int master_shape_class_dummy44(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 44
	virtual int master_shape_class_dummy45(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 45
	virtual int master_shape_class_dummy46(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 46
	virtual int master_shape_class_dummy47(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 47
	virtual int master_shape_class_dummy48(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 48
	virtual int master_shape_class_dummy49(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 49
	virtual int master_shape_class_dummy50(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 50
	virtual int master_shape_class_dummy51(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 51
	virtual int master_shape_class_dummy52(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 52
	virtual int master_shape_class_dummy53(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 53
	virtual int master_shape_class_dummy54(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 54
	virtual int master_shape_class_dummy55(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 55
	virtual int master_shape_class_dummy56(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 56
	virtual int master_shape_class_dummy57(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 57
	virtual int master_shape_class_dummy58(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 58
	virtual int master_shape_class_dummy59(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 59
	virtual int master_shape_class_dummy60(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 60
	virtual int master_shape_class_dummy61(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 61
	virtual int master_shape_class_dummy62(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 62
	virtual int master_shape_class_dummy63(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 63
	virtual int master_shape_class_dummy64(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 64
	virtual int master_shape_class_dummy65(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 65
	virtual int master_shape_class_dummy66(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 66
	virtual int master_shape_class_dummy67(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 67
	virtual int master_shape_class_dummy68(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 68
	virtual int master_shape_class_dummy69(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 69
	virtual int master_shape_class_dummy70(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 70
	virtual int master_shape_class_dummy71(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 71
	virtual int master_shape_class_dummy72(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 72
	virtual int master_shape_class_dummy73(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 73
	virtual int master_shape_class_dummy74(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 74
	virtual int master_shape_class_dummy75(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 75
	virtual int master_shape_class_dummy76(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 76
	virtual int master_shape_class_dummy77(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 77
	virtual int master_shape_class_dummy78(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 78
	virtual int master_shape_class_dummy79(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 79
	virtual int master_shape_class_dummy80(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 80
	virtual int master_shape_class_dummy81(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 81
	virtual int master_shape_class_dummy82(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 82
	virtual int master_shape_class_dummy83(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 83
	virtual int master_shape_class_dummy84(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 84
	virtual int master_shape_class_dummy85(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 85
	virtual int master_shape_class_dummy86(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 86
	virtual int master_shape_class_dummy87(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 87
	virtual int master_shape_class_dummy88(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 88
	virtual int master_shape_class_dummy89(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 89
	virtual int master_shape_class_dummy90(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 90
	virtual int master_shape_class_dummy91(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 91
	virtual int master_shape_class_dummy92(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 92
	virtual int master_shape_class_dummy93(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 93
	virtual int master_shape_class_dummy94(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 94
	virtual int master_shape_class_dummy95(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 95
	virtual int master_shape_class_dummy96(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 96
	virtual int master_shape_class_dummy97(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 97
	virtual int master_shape_class_dummy98(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 98
	virtual int master_shape_class_dummy99(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 99
	virtual int master_shape_class_dummy100(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 100
	virtual int master_shape_class_dummy101(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 101
	virtual int master_shape_class_dummy102(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 102
	virtual int master_shape_class_dummy103(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 103
	virtual int master_shape_class_dummy104(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 104
	virtual int master_shape_class_dummy105(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 105
	virtual int master_shape_class_dummy106(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 106
	virtual int master_shape_class_dummy107(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 107
	virtual int master_shape_class_dummy108(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 108
	virtual int master_shape_class_dummy109(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 109
	virtual int master_shape_class_dummy110(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 110
	virtual int master_shape_class_dummy111(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 111
	virtual int master_shape_class_dummy112(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 112
	virtual int master_shape_class_dummy113(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 113
	virtual int master_shape_class_dummy114(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 114
	virtual int master_shape_class_dummy115(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 115
	virtual int master_shape_class_dummy116(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 116
	virtual int master_shape_class_dummy117(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 117
	virtual int master_shape_class_dummy118(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 118
	virtual int master_shape_class_dummy119(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 119
	virtual int master_shape_class_dummy120(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 120
	virtual int master_shape_class_dummy121(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 121
	virtual int master_shape_class_dummy122(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 122
	virtual int master_shape_class_dummy123(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 123
	virtual int master_shape_class_dummy124(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 124
	virtual int master_shape_class_dummy125(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 125
	virtual int master_shape_class_dummy126(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 126
	virtual int master_shape_class_dummy127(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 127
	virtual int master_shape_class_dummy128(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 128
	virtual int master_shape_class_dummy129(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 129
	virtual int master_shape_class_dummy130(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 130
	virtual int master_shape_class_dummy131(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 131
	virtual int master_shape_class_dummy132(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 132
	virtual int master_shape_class_dummy133(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 133
	virtual int master_shape_class_dummy134(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 134
	virtual int master_shape_class_dummy135(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 135
	virtual int master_shape_class_dummy136(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 136
	virtual int master_shape_class_dummy137(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 137
	virtual int master_shape_class_dummy138(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 138
	virtual int master_shape_class_dummy139(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 139
	virtual int master_shape_class_dummy140(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 140
	virtual int master_shape_class_dummy141(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 141
	virtual int master_shape_class_dummy142(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 142
	virtual int master_shape_class_dummy143(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 143
	virtual int master_shape_class_dummy144(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 144
	virtual int master_shape_class_dummy145(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 145
	virtual int master_shape_class_dummy146(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 146
	virtual int master_shape_class_dummy147(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 147
	virtual int master_shape_class_dummy148(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 148
	virtual int master_shape_class_dummy149(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 149
	virtual int master_shape_class_dummy150(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 150
	virtual int master_shape_class_dummy151(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 151
	virtual int master_shape_class_dummy152(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 152
	virtual int master_shape_class_dummy153(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 153
	virtual int master_shape_class_dummy154(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 154
	virtual int master_shape_class_dummy155(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 155
	virtual int master_shape_class_dummy156(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 156
	virtual int master_shape_class_dummy157(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 157
	virtual int master_shape_class_dummy158(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 158
	virtual int master_shape_class_dummy159(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 159
	virtual int master_shape_class_dummy160(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 160
	virtual int master_shape_class_dummy161(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 161
	virtual int master_shape_class_dummy162(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 162
	virtual int master_shape_class_dummy163(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 163
	virtual int master_shape_class_dummy164(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 164
	virtual int master_shape_class_dummy165(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 165
	virtual int master_shape_class_dummy166(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 166
	virtual int master_shape_class_dummy167(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 167
	virtual int master_shape_class_dummy168(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 168
	virtual int master_shape_class_dummy169(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 169
	virtual int master_shape_class_dummy170(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 170
	virtual int master_shape_class_dummy171(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 171
	virtual int master_shape_class_dummy172(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 172
	virtual int master_shape_class_dummy173(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 173
	virtual int master_shape_class_dummy174(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 174
	virtual int master_shape_class_dummy175(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 175
	virtual int master_shape_class_dummy176(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 176
	virtual int master_shape_class_dummy177(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 177
	virtual int master_shape_class_dummy178(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 178
	virtual int master_shape_class_dummy179(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 179
	virtual int master_shape_class_dummy180(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 180
	virtual int master_shape_class_dummy181(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 181
	virtual int master_shape_class_dummy182(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 182
	virtual int master_shape_class_dummy183(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 183
	virtual int master_shape_class_dummy184(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 184
	virtual int master_shape_class_dummy185(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 185
	virtual int master_shape_class_dummy186(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 186
	virtual int master_shape_class_dummy187(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 187
	virtual int master_shape_class_dummy188(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 188
	virtual int master_shape_class_dummy189(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 189
	virtual int master_shape_class_dummy190(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 190
	virtual int master_shape_class_dummy191(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 191
	virtual int master_shape_class_dummy192(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 192
	virtual int master_shape_class_dummy193(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 193
	virtual int master_shape_class_dummy194(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 194
	virtual int master_shape_class_dummy195(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 195
	virtual int master_shape_class_dummy196(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 196
	virtual int master_shape_class_dummy197(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 197
	virtual int master_shape_class_dummy198(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 198
	virtual int master_shape_class_dummy199(void *) { assert(false); throw "invalid interface master_shape_class"; return 0; } // 199
	};

	class master_surface_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(master_surface_class , shape_class , enums::master_surface)	
	virtual master_surface_class &set_path (const char* path_param, void * = 0) = 0; // 0
	virtual const char* get_path (void * = 0) const = 0; // 1
	virtual bool update_external_reference (bool ask = true, void* aux = 0) = 0; // 2
	virtual bool update_external_reference (plugin_filereference_class& resolver, void* aux = 0) = 0; // 3
	virtual void unlink_external_reference (bool ask, bool unlink_all = false, void* aux = 0) = 0; // 4
	virtual bool file_exists (void* aux = 0) = 0; // 5
	virtual bool get_external_reference (void * = 0) const = 0; // 6
	virtual master_surface_class &set_external_reference (bool external_reference_param, void * = 0) = 0; // 7
	virtual bool has_external_reference (void* aux = 0) = 0; // 8
	virtual int master_surface_class_dummy9(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 9
	virtual int master_surface_class_dummy10(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 10
	virtual int master_surface_class_dummy11(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 11
	virtual int master_surface_class_dummy12(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 12
	virtual int master_surface_class_dummy13(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 13
	virtual int master_surface_class_dummy14(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 14
	virtual int master_surface_class_dummy15(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 15
	virtual int master_surface_class_dummy16(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 16
	virtual int master_surface_class_dummy17(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 17
	virtual int master_surface_class_dummy18(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 18
	virtual int master_surface_class_dummy19(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 19
	virtual int master_surface_class_dummy20(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 20
	virtual int master_surface_class_dummy21(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 21
	virtual int master_surface_class_dummy22(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 22
	virtual int master_surface_class_dummy23(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 23
	virtual int master_surface_class_dummy24(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 24
	virtual int master_surface_class_dummy25(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 25
	virtual int master_surface_class_dummy26(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 26
	virtual int master_surface_class_dummy27(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 27
	virtual int master_surface_class_dummy28(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 28
	virtual int master_surface_class_dummy29(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 29
	virtual int master_surface_class_dummy30(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 30
	virtual int master_surface_class_dummy31(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 31
	virtual int master_surface_class_dummy32(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 32
	virtual int master_surface_class_dummy33(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 33
	virtual int master_surface_class_dummy34(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 34
	virtual int master_surface_class_dummy35(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 35
	virtual int master_surface_class_dummy36(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 36
	virtual int master_surface_class_dummy37(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 37
	virtual int master_surface_class_dummy38(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 38
	virtual int master_surface_class_dummy39(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 39
	virtual int master_surface_class_dummy40(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 40
	virtual int master_surface_class_dummy41(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 41
	virtual int master_surface_class_dummy42(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 42
	virtual int master_surface_class_dummy43(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 43
	virtual int master_surface_class_dummy44(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 44
	virtual int master_surface_class_dummy45(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 45
	virtual int master_surface_class_dummy46(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 46
	virtual int master_surface_class_dummy47(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 47
	virtual int master_surface_class_dummy48(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 48
	virtual int master_surface_class_dummy49(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 49
	virtual int master_surface_class_dummy50(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 50
	virtual int master_surface_class_dummy51(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 51
	virtual int master_surface_class_dummy52(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 52
	virtual int master_surface_class_dummy53(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 53
	virtual int master_surface_class_dummy54(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 54
	virtual int master_surface_class_dummy55(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 55
	virtual int master_surface_class_dummy56(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 56
	virtual int master_surface_class_dummy57(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 57
	virtual int master_surface_class_dummy58(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 58
	virtual int master_surface_class_dummy59(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 59
	virtual int master_surface_class_dummy60(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 60
	virtual int master_surface_class_dummy61(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 61
	virtual int master_surface_class_dummy62(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 62
	virtual int master_surface_class_dummy63(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 63
	virtual int master_surface_class_dummy64(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 64
	virtual int master_surface_class_dummy65(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 65
	virtual int master_surface_class_dummy66(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 66
	virtual int master_surface_class_dummy67(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 67
	virtual int master_surface_class_dummy68(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 68
	virtual int master_surface_class_dummy69(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 69
	virtual int master_surface_class_dummy70(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 70
	virtual int master_surface_class_dummy71(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 71
	virtual int master_surface_class_dummy72(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 72
	virtual int master_surface_class_dummy73(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 73
	virtual int master_surface_class_dummy74(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 74
	virtual int master_surface_class_dummy75(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 75
	virtual int master_surface_class_dummy76(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 76
	virtual int master_surface_class_dummy77(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 77
	virtual int master_surface_class_dummy78(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 78
	virtual int master_surface_class_dummy79(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 79
	virtual int master_surface_class_dummy80(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 80
	virtual int master_surface_class_dummy81(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 81
	virtual int master_surface_class_dummy82(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 82
	virtual int master_surface_class_dummy83(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 83
	virtual int master_surface_class_dummy84(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 84
	virtual int master_surface_class_dummy85(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 85
	virtual int master_surface_class_dummy86(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 86
	virtual int master_surface_class_dummy87(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 87
	virtual int master_surface_class_dummy88(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 88
	virtual int master_surface_class_dummy89(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 89
	virtual int master_surface_class_dummy90(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 90
	virtual int master_surface_class_dummy91(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 91
	virtual int master_surface_class_dummy92(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 92
	virtual int master_surface_class_dummy93(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 93
	virtual int master_surface_class_dummy94(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 94
	virtual int master_surface_class_dummy95(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 95
	virtual int master_surface_class_dummy96(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 96
	virtual int master_surface_class_dummy97(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 97
	virtual int master_surface_class_dummy98(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 98
	virtual int master_surface_class_dummy99(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 99
	virtual int master_surface_class_dummy100(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 100
	virtual int master_surface_class_dummy101(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 101
	virtual int master_surface_class_dummy102(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 102
	virtual int master_surface_class_dummy103(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 103
	virtual int master_surface_class_dummy104(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 104
	virtual int master_surface_class_dummy105(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 105
	virtual int master_surface_class_dummy106(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 106
	virtual int master_surface_class_dummy107(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 107
	virtual int master_surface_class_dummy108(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 108
	virtual int master_surface_class_dummy109(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 109
	virtual int master_surface_class_dummy110(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 110
	virtual int master_surface_class_dummy111(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 111
	virtual int master_surface_class_dummy112(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 112
	virtual int master_surface_class_dummy113(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 113
	virtual int master_surface_class_dummy114(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 114
	virtual int master_surface_class_dummy115(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 115
	virtual int master_surface_class_dummy116(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 116
	virtual int master_surface_class_dummy117(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 117
	virtual int master_surface_class_dummy118(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 118
	virtual int master_surface_class_dummy119(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 119
	virtual int master_surface_class_dummy120(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 120
	virtual int master_surface_class_dummy121(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 121
	virtual int master_surface_class_dummy122(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 122
	virtual int master_surface_class_dummy123(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 123
	virtual int master_surface_class_dummy124(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 124
	virtual int master_surface_class_dummy125(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 125
	virtual int master_surface_class_dummy126(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 126
	virtual int master_surface_class_dummy127(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 127
	virtual int master_surface_class_dummy128(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 128
	virtual int master_surface_class_dummy129(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 129
	virtual int master_surface_class_dummy130(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 130
	virtual int master_surface_class_dummy131(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 131
	virtual int master_surface_class_dummy132(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 132
	virtual int master_surface_class_dummy133(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 133
	virtual int master_surface_class_dummy134(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 134
	virtual int master_surface_class_dummy135(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 135
	virtual int master_surface_class_dummy136(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 136
	virtual int master_surface_class_dummy137(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 137
	virtual int master_surface_class_dummy138(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 138
	virtual int master_surface_class_dummy139(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 139
	virtual int master_surface_class_dummy140(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 140
	virtual int master_surface_class_dummy141(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 141
	virtual int master_surface_class_dummy142(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 142
	virtual int master_surface_class_dummy143(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 143
	virtual int master_surface_class_dummy144(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 144
	virtual int master_surface_class_dummy145(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 145
	virtual int master_surface_class_dummy146(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 146
	virtual int master_surface_class_dummy147(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 147
	virtual int master_surface_class_dummy148(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 148
	virtual int master_surface_class_dummy149(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 149
	virtual int master_surface_class_dummy150(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 150
	virtual int master_surface_class_dummy151(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 151
	virtual int master_surface_class_dummy152(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 152
	virtual int master_surface_class_dummy153(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 153
	virtual int master_surface_class_dummy154(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 154
	virtual int master_surface_class_dummy155(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 155
	virtual int master_surface_class_dummy156(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 156
	virtual int master_surface_class_dummy157(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 157
	virtual int master_surface_class_dummy158(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 158
	virtual int master_surface_class_dummy159(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 159
	virtual int master_surface_class_dummy160(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 160
	virtual int master_surface_class_dummy161(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 161
	virtual int master_surface_class_dummy162(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 162
	virtual int master_surface_class_dummy163(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 163
	virtual int master_surface_class_dummy164(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 164
	virtual int master_surface_class_dummy165(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 165
	virtual int master_surface_class_dummy166(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 166
	virtual int master_surface_class_dummy167(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 167
	virtual int master_surface_class_dummy168(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 168
	virtual int master_surface_class_dummy169(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 169
	virtual int master_surface_class_dummy170(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 170
	virtual int master_surface_class_dummy171(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 171
	virtual int master_surface_class_dummy172(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 172
	virtual int master_surface_class_dummy173(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 173
	virtual int master_surface_class_dummy174(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 174
	virtual int master_surface_class_dummy175(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 175
	virtual int master_surface_class_dummy176(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 176
	virtual int master_surface_class_dummy177(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 177
	virtual int master_surface_class_dummy178(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 178
	virtual int master_surface_class_dummy179(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 179
	virtual int master_surface_class_dummy180(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 180
	virtual int master_surface_class_dummy181(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 181
	virtual int master_surface_class_dummy182(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 182
	virtual int master_surface_class_dummy183(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 183
	virtual int master_surface_class_dummy184(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 184
	virtual int master_surface_class_dummy185(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 185
	virtual int master_surface_class_dummy186(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 186
	virtual int master_surface_class_dummy187(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 187
	virtual int master_surface_class_dummy188(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 188
	virtual int master_surface_class_dummy189(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 189
	virtual int master_surface_class_dummy190(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 190
	virtual int master_surface_class_dummy191(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 191
	virtual int master_surface_class_dummy192(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 192
	virtual int master_surface_class_dummy193(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 193
	virtual int master_surface_class_dummy194(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 194
	virtual int master_surface_class_dummy195(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 195
	virtual int master_surface_class_dummy196(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 196
	virtual int master_surface_class_dummy197(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 197
	virtual int master_surface_class_dummy198(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 198
	virtual int master_surface_class_dummy199(void *) { assert(false); throw "invalid interface master_surface_class"; return 0; } // 199
	};

	class master_image_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(master_image_class , shape_class , enums::master_image)	
	virtual master_image_class &set_image (sxsdk::image_interface* image_param, void * = 0) = 0; // 0
	virtual sxsdk::image_interface* get_image (void * = 0) const = 0; // 1
	virtual void load_image (const char* from, void* aux = 0) = 0; // 2
	virtual void save_image (const char* to, void* aux = 0) = 0; // 3
	virtual bool is_master_image_being_used (void* aux = 0) = 0; // 4
	virtual int master_image_class_dummy5(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 5
	virtual int master_image_class_dummy6(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 6
	virtual int master_image_class_dummy7(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 7
	virtual int master_image_class_dummy8(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 8
	virtual int master_image_class_dummy9(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 9
	virtual int master_image_class_dummy10(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 10
	virtual int master_image_class_dummy11(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 11
	virtual int master_image_class_dummy12(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 12
	virtual int master_image_class_dummy13(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 13
	virtual int master_image_class_dummy14(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 14
	virtual int master_image_class_dummy15(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 15
	virtual int master_image_class_dummy16(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 16
	virtual int master_image_class_dummy17(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 17
	virtual int master_image_class_dummy18(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 18
	virtual int master_image_class_dummy19(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 19
	virtual int master_image_class_dummy20(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 20
	virtual int master_image_class_dummy21(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 21
	virtual int master_image_class_dummy22(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 22
	virtual int master_image_class_dummy23(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 23
	virtual int master_image_class_dummy24(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 24
	virtual int master_image_class_dummy25(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 25
	virtual int master_image_class_dummy26(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 26
	virtual int master_image_class_dummy27(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 27
	virtual int master_image_class_dummy28(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 28
	virtual int master_image_class_dummy29(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 29
	virtual int master_image_class_dummy30(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 30
	virtual int master_image_class_dummy31(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 31
	virtual int master_image_class_dummy32(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 32
	virtual int master_image_class_dummy33(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 33
	virtual int master_image_class_dummy34(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 34
	virtual int master_image_class_dummy35(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 35
	virtual int master_image_class_dummy36(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 36
	virtual int master_image_class_dummy37(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 37
	virtual int master_image_class_dummy38(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 38
	virtual int master_image_class_dummy39(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 39
	virtual int master_image_class_dummy40(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 40
	virtual int master_image_class_dummy41(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 41
	virtual int master_image_class_dummy42(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 42
	virtual int master_image_class_dummy43(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 43
	virtual int master_image_class_dummy44(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 44
	virtual int master_image_class_dummy45(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 45
	virtual int master_image_class_dummy46(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 46
	virtual int master_image_class_dummy47(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 47
	virtual int master_image_class_dummy48(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 48
	virtual int master_image_class_dummy49(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 49
	virtual int master_image_class_dummy50(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 50
	virtual int master_image_class_dummy51(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 51
	virtual int master_image_class_dummy52(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 52
	virtual int master_image_class_dummy53(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 53
	virtual int master_image_class_dummy54(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 54
	virtual int master_image_class_dummy55(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 55
	virtual int master_image_class_dummy56(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 56
	virtual int master_image_class_dummy57(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 57
	virtual int master_image_class_dummy58(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 58
	virtual int master_image_class_dummy59(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 59
	virtual int master_image_class_dummy60(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 60
	virtual int master_image_class_dummy61(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 61
	virtual int master_image_class_dummy62(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 62
	virtual int master_image_class_dummy63(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 63
	virtual int master_image_class_dummy64(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 64
	virtual int master_image_class_dummy65(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 65
	virtual int master_image_class_dummy66(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 66
	virtual int master_image_class_dummy67(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 67
	virtual int master_image_class_dummy68(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 68
	virtual int master_image_class_dummy69(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 69
	virtual int master_image_class_dummy70(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 70
	virtual int master_image_class_dummy71(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 71
	virtual int master_image_class_dummy72(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 72
	virtual int master_image_class_dummy73(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 73
	virtual int master_image_class_dummy74(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 74
	virtual int master_image_class_dummy75(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 75
	virtual int master_image_class_dummy76(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 76
	virtual int master_image_class_dummy77(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 77
	virtual int master_image_class_dummy78(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 78
	virtual int master_image_class_dummy79(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 79
	virtual int master_image_class_dummy80(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 80
	virtual int master_image_class_dummy81(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 81
	virtual int master_image_class_dummy82(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 82
	virtual int master_image_class_dummy83(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 83
	virtual int master_image_class_dummy84(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 84
	virtual int master_image_class_dummy85(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 85
	virtual int master_image_class_dummy86(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 86
	virtual int master_image_class_dummy87(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 87
	virtual int master_image_class_dummy88(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 88
	virtual int master_image_class_dummy89(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 89
	virtual int master_image_class_dummy90(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 90
	virtual int master_image_class_dummy91(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 91
	virtual int master_image_class_dummy92(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 92
	virtual int master_image_class_dummy93(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 93
	virtual int master_image_class_dummy94(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 94
	virtual int master_image_class_dummy95(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 95
	virtual int master_image_class_dummy96(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 96
	virtual int master_image_class_dummy97(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 97
	virtual int master_image_class_dummy98(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 98
	virtual int master_image_class_dummy99(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 99
	virtual int master_image_class_dummy100(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 100
	virtual int master_image_class_dummy101(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 101
	virtual int master_image_class_dummy102(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 102
	virtual int master_image_class_dummy103(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 103
	virtual int master_image_class_dummy104(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 104
	virtual int master_image_class_dummy105(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 105
	virtual int master_image_class_dummy106(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 106
	virtual int master_image_class_dummy107(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 107
	virtual int master_image_class_dummy108(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 108
	virtual int master_image_class_dummy109(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 109
	virtual int master_image_class_dummy110(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 110
	virtual int master_image_class_dummy111(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 111
	virtual int master_image_class_dummy112(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 112
	virtual int master_image_class_dummy113(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 113
	virtual int master_image_class_dummy114(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 114
	virtual int master_image_class_dummy115(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 115
	virtual int master_image_class_dummy116(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 116
	virtual int master_image_class_dummy117(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 117
	virtual int master_image_class_dummy118(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 118
	virtual int master_image_class_dummy119(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 119
	virtual int master_image_class_dummy120(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 120
	virtual int master_image_class_dummy121(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 121
	virtual int master_image_class_dummy122(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 122
	virtual int master_image_class_dummy123(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 123
	virtual int master_image_class_dummy124(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 124
	virtual int master_image_class_dummy125(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 125
	virtual int master_image_class_dummy126(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 126
	virtual int master_image_class_dummy127(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 127
	virtual int master_image_class_dummy128(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 128
	virtual int master_image_class_dummy129(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 129
	virtual int master_image_class_dummy130(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 130
	virtual int master_image_class_dummy131(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 131
	virtual int master_image_class_dummy132(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 132
	virtual int master_image_class_dummy133(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 133
	virtual int master_image_class_dummy134(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 134
	virtual int master_image_class_dummy135(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 135
	virtual int master_image_class_dummy136(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 136
	virtual int master_image_class_dummy137(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 137
	virtual int master_image_class_dummy138(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 138
	virtual int master_image_class_dummy139(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 139
	virtual int master_image_class_dummy140(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 140
	virtual int master_image_class_dummy141(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 141
	virtual int master_image_class_dummy142(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 142
	virtual int master_image_class_dummy143(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 143
	virtual int master_image_class_dummy144(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 144
	virtual int master_image_class_dummy145(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 145
	virtual int master_image_class_dummy146(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 146
	virtual int master_image_class_dummy147(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 147
	virtual int master_image_class_dummy148(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 148
	virtual int master_image_class_dummy149(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 149
	virtual int master_image_class_dummy150(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 150
	virtual int master_image_class_dummy151(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 151
	virtual int master_image_class_dummy152(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 152
	virtual int master_image_class_dummy153(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 153
	virtual int master_image_class_dummy154(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 154
	virtual int master_image_class_dummy155(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 155
	virtual int master_image_class_dummy156(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 156
	virtual int master_image_class_dummy157(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 157
	virtual int master_image_class_dummy158(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 158
	virtual int master_image_class_dummy159(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 159
	virtual int master_image_class_dummy160(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 160
	virtual int master_image_class_dummy161(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 161
	virtual int master_image_class_dummy162(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 162
	virtual int master_image_class_dummy163(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 163
	virtual int master_image_class_dummy164(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 164
	virtual int master_image_class_dummy165(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 165
	virtual int master_image_class_dummy166(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 166
	virtual int master_image_class_dummy167(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 167
	virtual int master_image_class_dummy168(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 168
	virtual int master_image_class_dummy169(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 169
	virtual int master_image_class_dummy170(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 170
	virtual int master_image_class_dummy171(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 171
	virtual int master_image_class_dummy172(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 172
	virtual int master_image_class_dummy173(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 173
	virtual int master_image_class_dummy174(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 174
	virtual int master_image_class_dummy175(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 175
	virtual int master_image_class_dummy176(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 176
	virtual int master_image_class_dummy177(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 177
	virtual int master_image_class_dummy178(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 178
	virtual int master_image_class_dummy179(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 179
	virtual int master_image_class_dummy180(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 180
	virtual int master_image_class_dummy181(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 181
	virtual int master_image_class_dummy182(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 182
	virtual int master_image_class_dummy183(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 183
	virtual int master_image_class_dummy184(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 184
	virtual int master_image_class_dummy185(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 185
	virtual int master_image_class_dummy186(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 186
	virtual int master_image_class_dummy187(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 187
	virtual int master_image_class_dummy188(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 188
	virtual int master_image_class_dummy189(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 189
	virtual int master_image_class_dummy190(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 190
	virtual int master_image_class_dummy191(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 191
	virtual int master_image_class_dummy192(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 192
	virtual int master_image_class_dummy193(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 193
	virtual int master_image_class_dummy194(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 194
	virtual int master_image_class_dummy195(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 195
	virtual int master_image_class_dummy196(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 196
	virtual int master_image_class_dummy197(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 197
	virtual int master_image_class_dummy198(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 198
	virtual int master_image_class_dummy199(void *) { assert(false); throw "invalid interface master_image_class"; return 0; } // 199
	};

	class light_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(light_class , shape_class , enums::light)	
	virtual shape_saver_interface* create_shape_saver_interface (void* aux = 0) = 0; // -1
	virtual light_class &set_center (const sxsdk::vec3 &center_param, void * = 0) = 0; // 0
	virtual sxsdk::vec3 get_center (void * = 0) const = 0; // 1
	virtual light_class &set_intensity (float intensity_param, void * = 0) = 0; // 2
	virtual float get_intensity (void * = 0) const = 0; // 3
	virtual light_class &set_spotlight (bool spotlight_param, void * = 0) = 0; // 4
	virtual bool get_spotlight (void * = 0) const = 0; // 5
	virtual light_class &set_attenuation (int attenuation_param, void * = 0) = 0; // 6
	virtual int get_attenuation (void * = 0) const = 0; // 7
	virtual light_class &set_angle (float angle_param, void * = 0) = 0; // 8
	virtual float get_angle (void * = 0) const = 0; // 9
	virtual light_class &set_softness (float softness_param, void * = 0) = 0; // 10
	virtual float get_softness (void * = 0) const = 0; // 11
	virtual light_class &set_shadow (float shadow_param, void * = 0) = 0; // 12
	virtual float get_shadow (void * = 0) const = 0; // 13
	virtual light_class &set_shadow_softness (float shadow_softness_param, void * = 0) = 0; // 14
	virtual float get_shadow_softness (void * = 0) const = 0; // 15
	virtual light_class &set_direction (const sxsdk::vec3 &direction_param, void * = 0) = 0; // 16
	virtual sxsdk::vec3 get_direction (void * = 0) const = 0; // 17
	virtual light_class &set_specular (float specular_param, void * = 0) = 0; // 18
	virtual float get_specular (void * = 0) const = 0; // 19
	virtual light_class &set_diffuse (float diffuse_param, void * = 0) = 0; // 20
	virtual float get_diffuse (void * = 0) const = 0; // 21
	virtual light_class &set_position (const sxsdk::vec3 &position_param, void * = 0) = 0; // 22
	virtual sxsdk::vec3 get_position (void * = 0) const = 0; // 23
	virtual light_interface* get_light_interface (void* aux = 0) = 0; // 24
	virtual light_class &set_lumen (bool lumen_param, void * = 0) = 0; // 25
	virtual bool get_lumen (void * = 0) const = 0; // 26
	virtual void load_ies (const char* from, void* aux = 0) = 0; // 27
	virtual light_class &set_distribution_type (int distribution_type_param, void * = 0) = 0; // 28
	virtual int get_distribution_type (void * = 0) const = 0; // 29
	virtual light_class &set_volume_light (bool volume_light_param, void * = 0) = 0; // 30
	virtual bool get_volume_light (void * = 0) const = 0; // 31
	virtual light_class &set_volume_light_intensity (float volume_light_intensity_param, void * = 0) = 0; // 32
	virtual float get_volume_light_intensity (void * = 0) const = 0; // 33
	virtual light_class &set_volume_light_auto_radius (bool volume_light_auto_radius_param, void * = 0) = 0; // 34
	virtual bool get_volume_light_auto_radius (void * = 0) const = 0; // 35
	virtual light_class &set_volume_light_radius (float volume_light_radius_param, void * = 0) = 0; // 36
	virtual float get_volume_light_radius (void * = 0) const = 0; // 37
	virtual sxsdk::enums::castshadow_type get_volume_light_castshadow_type (void * = 0) const = 0; // 38
	virtual light_class &set_volume_light_castshadow_type (sxsdk::enums::castshadow_type volume_light_castshadow_type_param, void * = 0) = 0; // 39
	virtual light_class &set_volume_light_quality (int volume_light_quality_param, void * = 0) = 0; // 40
	virtual int get_volume_light_quality (void * = 0) const = 0; // 41
	virtual void save_ies (const char* to, void* aux = 0) = 0; // 42
	virtual void clear_ies (void* aux = 0) = 0; // 43
	virtual int light_class_dummy44(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 44
	virtual int light_class_dummy45(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 45
	virtual int light_class_dummy46(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 46
	virtual int light_class_dummy47(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 47
	virtual int light_class_dummy48(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 48
	virtual int light_class_dummy49(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 49
	virtual int light_class_dummy50(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 50
	virtual int light_class_dummy51(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 51
	virtual int light_class_dummy52(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 52
	virtual int light_class_dummy53(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 53
	virtual int light_class_dummy54(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 54
	virtual int light_class_dummy55(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 55
	virtual int light_class_dummy56(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 56
	virtual int light_class_dummy57(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 57
	virtual int light_class_dummy58(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 58
	virtual int light_class_dummy59(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 59
	virtual int light_class_dummy60(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 60
	virtual int light_class_dummy61(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 61
	virtual int light_class_dummy62(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 62
	virtual int light_class_dummy63(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 63
	virtual int light_class_dummy64(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 64
	virtual int light_class_dummy65(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 65
	virtual int light_class_dummy66(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 66
	virtual int light_class_dummy67(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 67
	virtual int light_class_dummy68(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 68
	virtual int light_class_dummy69(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 69
	virtual int light_class_dummy70(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 70
	virtual int light_class_dummy71(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 71
	virtual int light_class_dummy72(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 72
	virtual int light_class_dummy73(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 73
	virtual int light_class_dummy74(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 74
	virtual int light_class_dummy75(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 75
	virtual int light_class_dummy76(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 76
	virtual int light_class_dummy77(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 77
	virtual int light_class_dummy78(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 78
	virtual int light_class_dummy79(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 79
	virtual int light_class_dummy80(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 80
	virtual int light_class_dummy81(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 81
	virtual int light_class_dummy82(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 82
	virtual int light_class_dummy83(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 83
	virtual int light_class_dummy84(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 84
	virtual int light_class_dummy85(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 85
	virtual int light_class_dummy86(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 86
	virtual int light_class_dummy87(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 87
	virtual int light_class_dummy88(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 88
	virtual int light_class_dummy89(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 89
	virtual int light_class_dummy90(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 90
	virtual int light_class_dummy91(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 91
	virtual int light_class_dummy92(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 92
	virtual int light_class_dummy93(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 93
	virtual int light_class_dummy94(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 94
	virtual int light_class_dummy95(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 95
	virtual int light_class_dummy96(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 96
	virtual int light_class_dummy97(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 97
	virtual int light_class_dummy98(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 98
	virtual int light_class_dummy99(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 99
	virtual int light_class_dummy100(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 100
	virtual int light_class_dummy101(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 101
	virtual int light_class_dummy102(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 102
	virtual int light_class_dummy103(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 103
	virtual int light_class_dummy104(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 104
	virtual int light_class_dummy105(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 105
	virtual int light_class_dummy106(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 106
	virtual int light_class_dummy107(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 107
	virtual int light_class_dummy108(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 108
	virtual int light_class_dummy109(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 109
	virtual int light_class_dummy110(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 110
	virtual int light_class_dummy111(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 111
	virtual int light_class_dummy112(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 112
	virtual int light_class_dummy113(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 113
	virtual int light_class_dummy114(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 114
	virtual int light_class_dummy115(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 115
	virtual int light_class_dummy116(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 116
	virtual int light_class_dummy117(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 117
	virtual int light_class_dummy118(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 118
	virtual int light_class_dummy119(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 119
	virtual int light_class_dummy120(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 120
	virtual int light_class_dummy121(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 121
	virtual int light_class_dummy122(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 122
	virtual int light_class_dummy123(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 123
	virtual int light_class_dummy124(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 124
	virtual int light_class_dummy125(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 125
	virtual int light_class_dummy126(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 126
	virtual int light_class_dummy127(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 127
	virtual int light_class_dummy128(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 128
	virtual int light_class_dummy129(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 129
	virtual int light_class_dummy130(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 130
	virtual int light_class_dummy131(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 131
	virtual int light_class_dummy132(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 132
	virtual int light_class_dummy133(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 133
	virtual int light_class_dummy134(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 134
	virtual int light_class_dummy135(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 135
	virtual int light_class_dummy136(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 136
	virtual int light_class_dummy137(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 137
	virtual int light_class_dummy138(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 138
	virtual int light_class_dummy139(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 139
	virtual int light_class_dummy140(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 140
	virtual int light_class_dummy141(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 141
	virtual int light_class_dummy142(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 142
	virtual int light_class_dummy143(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 143
	virtual int light_class_dummy144(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 144
	virtual int light_class_dummy145(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 145
	virtual int light_class_dummy146(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 146
	virtual int light_class_dummy147(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 147
	virtual int light_class_dummy148(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 148
	virtual int light_class_dummy149(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 149
	virtual int light_class_dummy150(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 150
	virtual int light_class_dummy151(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 151
	virtual int light_class_dummy152(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 152
	virtual int light_class_dummy153(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 153
	virtual int light_class_dummy154(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 154
	virtual int light_class_dummy155(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 155
	virtual int light_class_dummy156(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 156
	virtual int light_class_dummy157(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 157
	virtual int light_class_dummy158(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 158
	virtual int light_class_dummy159(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 159
	virtual int light_class_dummy160(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 160
	virtual int light_class_dummy161(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 161
	virtual int light_class_dummy162(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 162
	virtual int light_class_dummy163(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 163
	virtual int light_class_dummy164(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 164
	virtual int light_class_dummy165(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 165
	virtual int light_class_dummy166(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 166
	virtual int light_class_dummy167(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 167
	virtual int light_class_dummy168(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 168
	virtual int light_class_dummy169(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 169
	virtual int light_class_dummy170(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 170
	virtual int light_class_dummy171(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 171
	virtual int light_class_dummy172(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 172
	virtual int light_class_dummy173(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 173
	virtual int light_class_dummy174(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 174
	virtual int light_class_dummy175(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 175
	virtual int light_class_dummy176(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 176
	virtual int light_class_dummy177(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 177
	virtual int light_class_dummy178(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 178
	virtual int light_class_dummy179(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 179
	virtual int light_class_dummy180(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 180
	virtual int light_class_dummy181(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 181
	virtual int light_class_dummy182(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 182
	virtual int light_class_dummy183(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 183
	virtual int light_class_dummy184(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 184
	virtual int light_class_dummy185(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 185
	virtual int light_class_dummy186(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 186
	virtual int light_class_dummy187(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 187
	virtual int light_class_dummy188(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 188
	virtual int light_class_dummy189(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 189
	virtual int light_class_dummy190(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 190
	virtual int light_class_dummy191(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 191
	virtual int light_class_dummy192(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 192
	virtual int light_class_dummy193(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 193
	virtual int light_class_dummy194(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 194
	virtual int light_class_dummy195(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 195
	virtual int light_class_dummy196(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 196
	virtual int light_class_dummy197(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 197
	virtual int light_class_dummy198(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 198
	virtual int light_class_dummy199(void *) { assert(false); throw "invalid interface light_class"; return 0; } // 199
	};

	class line_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(line_class , shape_class , enums::line)	
	virtual shape_saver_interface* create_shape_saver_interface (void* aux = 0) = 0; // -1
	virtual int get_number_of_control_points (void * = 0) const = 0; // 0
	virtual void set_anchor_point_deprecated (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 1
	virtual sxsdk::vec3 get_anchor_point_deprecated (int i, void* aux = 0) = 0; // 2
	virtual void set_inhandle_deprecated (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 3
	virtual sxsdk::vec3 get_inhandle_deprecated (int i, void* aux = 0) = 0; // 4
	virtual void set_outhandle_deprecated (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 5
	virtual sxsdk::vec3 get_outhandle_deprecated (int i, void* aux = 0) = 0; // 6
	virtual void set_handle_linked_deprecated (int i, bool b, void* aux = 0) = 0; // 7
	virtual bool get_handle_linked_deprecated (int i, void* aux = 0) = 0; // 8
	virtual void set_lateral_inhandle_deprecated (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 9
	virtual sxsdk::vec3 get_lateral_inhandle_deprecated (int i, void* aux = 0) = 0; // 10
	virtual void set_lateral_outhandle_deprecated (int i, const sxsdk::vec3& v, void* aux = 0) = 0; // 11
	virtual sxsdk::vec3 get_lateral_outhandle_deprecated (int i, void* aux = 0) = 0; // 12
	virtual void set_lateral_handle_linked_deprecated (int i, bool b, void* aux = 0) = 0; // 13
	virtual bool get_lateral_handle_linked_deprecated (int i, void* aux = 0) = 0; // 14
	virtual line_class &set_closed (bool closed_param, void * = 0) = 0; // 15
	virtual bool get_closed (void * = 0) const = 0; // 16
	virtual line_class &set_hole (bool hole_param, void * = 0) = 0; // 17
	virtual bool get_hole (void * = 0) const = 0; // 18
	virtual int get_number_of_active_control_points (void * = 0) const = 0; // 19
	virtual int get_first_active_control_point_deprecated (void * = 0) const = 0; // 20
	virtual int get_next_active_control_point_deprecated (void * = 0) const = 0; // 21
	virtual void select_all_control_points_obsolete (void* aux = 0) = 0; // 22
	virtual void unselect_all_control_points_obsolete (void* aux = 0) = 0; // 23
	virtual void select_control_point_obsolete (int i, void* aux = 0) = 0; // 24
	virtual void set_skip_joint_obsolete (int skip_joint, void* aux = 0) = 0; // 25
	virtual int get_skip_joint_obsolete (void* aux = 0) { return 0; } // 26
	virtual void reverse (void* aux = 0) = 0; // 27
	virtual void insert_control_point (float at, void* aux = 0) = 0; // 28
	virtual void remove_control_point (int at, void* aux = 0) = 0; // 29
	virtual void iron (int n = -1, const int* i = 0, void* aux = 0) = 0; // 30
	virtual void smooth (int n = -1, const int* i = 0, void* aux = 0) = 0; // 31
	virtual void unsmooth (int n = -1, const int* i = 0, void* aux = 0) = 0; // 32
	virtual void round_edge (float by, void* aux = 0) = 0; // 33
	virtual void bevel_edge (float by, void* aux = 0) = 0; // 34
	virtual void degenerate (void* aux = 0) = 0; // 35
	virtual line_interface* get_line_interface (void* aux = 0) = 0; // 36
	virtual line_saver_class* get_line_saver (void* aux = 0) = 0; // 37
	virtual float get_light_intensity (void * = 0) const = 0; // 38
	virtual line_class &set_light_intensity (float light_intensity_param, void * = 0) = 0; // 39
	virtual float get_light_specular_deprecated (void * = 0) const = 0; // 40
	virtual line_class &set_light_specular_deprecated (float light_specular_deprecated_param, void * = 0) = 0; // 41
	virtual bool get_light_visible (void * = 0) const = 0; // 42
	virtual line_class &set_light_visible (bool light_visible_param, void * = 0) = 0; // 43
	virtual bool has_inhandle_deprecated (int i, void* aux = 0) = 0; // 44
	virtual bool has_outhandle_deprecated (int i, void* aux = 0) = 0; // 45
	virtual bool has_lateral_inhandle_deprecated (int i, void* aux = 0) = 0; // 46
	virtual bool has_lateral_outhandle_deprecated (int i, void* aux = 0) = 0; // 47
	virtual void remove_inhandle_deprecated (int i, void* aux = 0) = 0; // 48
	virtual void remove_outhandle_deprecated (int i, void* aux = 0) = 0; // 49
	virtual void remove_lateral_inhandle_deprecated (int i, void* aux = 0) = 0; // 50
	virtual void remove_lateral_outhandle_deprecated (int i, void* aux = 0) = 0; // 51
	virtual line_class &set_lumen (bool lumen_param, void * = 0) = 0; // 52
	virtual bool get_lumen (void * = 0) const = 0; // 53
	virtual sxsdk::enums::light_type get_light_type (void * = 0) const = 0; // 54
	virtual line_class &set_light_type (sxsdk::enums::light_type light_type_param, void * = 0) = 0; // 55
	virtual line_class &set_shadow (float shadow_param, void * = 0) = 0; // 56
	virtual float get_shadow (void * = 0) const = 0; // 57
	virtual line_class &set_specular (float specular_param, void * = 0) = 0; // 58
	virtual float get_specular (void * = 0) const = 0; // 59
	virtual line_class &set_diffuse (float diffuse_param, void * = 0) = 0; // 60
	virtual float get_diffuse (void * = 0) const = 0; // 61
	virtual float calculate_parameter (float distance, void* aux = 0) = 0; // 62
	virtual line_class &set_volume_light (bool volume_light_param, void * = 0) = 0; // 63
	virtual bool get_volume_light (void * = 0) const = 0; // 64
	virtual line_class &set_volume_light_intensity (float volume_light_intensity_param, void * = 0) = 0; // 65
	virtual float get_volume_light_intensity (void * = 0) const = 0; // 66
	virtual line_class &set_volume_light_auto_radius (bool volume_light_auto_radius_param, void * = 0) = 0; // 67
	virtual bool get_volume_light_auto_radius (void * = 0) const = 0; // 68
	virtual line_class &set_volume_light_radius (float volume_light_radius_param, void * = 0) = 0; // 69
	virtual float get_volume_light_radius (void * = 0) const = 0; // 70
	virtual sxsdk::enums::castshadow_type get_volume_light_castshadow_type (void * = 0) const = 0; // 71
	virtual line_class &set_volume_light_castshadow_type (sxsdk::enums::castshadow_type volume_light_castshadow_type_param, void * = 0) = 0; // 72
	virtual line_class &set_volume_light_quality (int volume_light_quality_param, void * = 0) = 0; // 73
	virtual int get_volume_light_quality (void * = 0) const = 0; // 74
	virtual int line_class_dummy75(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 75
	virtual int line_class_dummy76(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 76
	virtual int line_class_dummy77(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 77
	virtual int line_class_dummy78(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 78
	virtual int line_class_dummy79(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 79
	virtual int line_class_dummy80(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 80
	virtual int line_class_dummy81(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 81
	virtual int line_class_dummy82(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 82
	virtual int line_class_dummy83(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 83
	virtual int line_class_dummy84(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 84
	virtual int line_class_dummy85(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 85
	virtual int line_class_dummy86(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 86
	virtual int line_class_dummy87(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 87
	virtual int line_class_dummy88(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 88
	virtual int line_class_dummy89(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 89
	virtual int line_class_dummy90(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 90
	virtual int line_class_dummy91(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 91
	virtual int line_class_dummy92(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 92
	virtual int line_class_dummy93(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 93
	virtual int line_class_dummy94(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 94
	virtual int line_class_dummy95(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 95
	virtual int line_class_dummy96(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 96
	virtual int line_class_dummy97(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 97
	virtual int line_class_dummy98(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 98
	virtual int line_class_dummy99(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 99
	virtual int line_class_dummy100(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 100
	virtual int line_class_dummy101(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 101
	virtual int line_class_dummy102(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 102
	virtual int line_class_dummy103(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 103
	virtual int line_class_dummy104(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 104
	virtual int line_class_dummy105(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 105
	virtual int line_class_dummy106(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 106
	virtual int line_class_dummy107(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 107
	virtual int line_class_dummy108(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 108
	virtual int line_class_dummy109(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 109
	virtual int line_class_dummy110(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 110
	virtual int line_class_dummy111(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 111
	virtual int line_class_dummy112(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 112
	virtual int line_class_dummy113(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 113
	virtual int line_class_dummy114(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 114
	virtual int line_class_dummy115(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 115
	virtual int line_class_dummy116(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 116
	virtual int line_class_dummy117(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 117
	virtual int line_class_dummy118(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 118
	virtual int line_class_dummy119(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 119
	virtual int line_class_dummy120(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 120
	virtual int line_class_dummy121(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 121
	virtual int line_class_dummy122(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 122
	virtual int line_class_dummy123(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 123
	virtual int line_class_dummy124(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 124
	virtual int line_class_dummy125(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 125
	virtual int line_class_dummy126(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 126
	virtual int line_class_dummy127(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 127
	virtual int line_class_dummy128(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 128
	virtual int line_class_dummy129(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 129
	virtual int line_class_dummy130(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 130
	virtual int line_class_dummy131(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 131
	virtual int line_class_dummy132(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 132
	virtual int line_class_dummy133(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 133
	virtual int line_class_dummy134(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 134
	virtual int line_class_dummy135(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 135
	virtual int line_class_dummy136(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 136
	virtual int line_class_dummy137(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 137
	virtual int line_class_dummy138(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 138
	virtual int line_class_dummy139(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 139
	virtual int line_class_dummy140(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 140
	virtual int line_class_dummy141(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 141
	virtual int line_class_dummy142(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 142
	virtual int line_class_dummy143(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 143
	virtual int line_class_dummy144(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 144
	virtual int line_class_dummy145(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 145
	virtual int line_class_dummy146(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 146
	virtual int line_class_dummy147(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 147
	virtual int line_class_dummy148(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 148
	virtual int line_class_dummy149(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 149
	virtual int line_class_dummy150(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 150
	virtual int line_class_dummy151(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 151
	virtual int line_class_dummy152(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 152
	virtual int line_class_dummy153(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 153
	virtual int line_class_dummy154(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 154
	virtual int line_class_dummy155(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 155
	virtual int line_class_dummy156(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 156
	virtual int line_class_dummy157(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 157
	virtual int line_class_dummy158(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 158
	virtual int line_class_dummy159(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 159
	virtual int line_class_dummy160(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 160
	virtual int line_class_dummy161(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 161
	virtual int line_class_dummy162(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 162
	virtual int line_class_dummy163(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 163
	virtual int line_class_dummy164(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 164
	virtual int line_class_dummy165(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 165
	virtual int line_class_dummy166(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 166
	virtual int line_class_dummy167(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 167
	virtual int line_class_dummy168(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 168
	virtual int line_class_dummy169(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 169
	virtual int line_class_dummy170(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 170
	virtual int line_class_dummy171(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 171
	virtual int line_class_dummy172(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 172
	virtual int line_class_dummy173(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 173
	virtual int line_class_dummy174(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 174
	virtual int line_class_dummy175(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 175
	virtual int line_class_dummy176(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 176
	virtual int line_class_dummy177(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 177
	virtual int line_class_dummy178(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 178
	virtual int line_class_dummy179(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 179
	virtual int line_class_dummy180(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 180
	virtual int line_class_dummy181(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 181
	virtual int line_class_dummy182(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 182
	virtual int line_class_dummy183(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 183
	virtual int line_class_dummy184(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 184
	virtual int line_class_dummy185(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 185
	virtual int line_class_dummy186(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 186
	virtual int line_class_dummy187(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 187
	virtual int line_class_dummy188(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 188
	virtual int line_class_dummy189(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 189
	virtual int line_class_dummy190(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 190
	virtual int line_class_dummy191(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 191
	virtual int line_class_dummy192(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 192
	virtual int line_class_dummy193(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 193
	virtual int line_class_dummy194(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 194
	virtual int line_class_dummy195(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 195
	virtual int line_class_dummy196(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 196
	virtual int line_class_dummy197(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 197
	virtual int line_class_dummy198(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 198
	virtual int line_class_dummy199(void *) { assert(false); throw "invalid interface line_class"; return 0; } // 199
	};

	class polygon_mesh_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(polygon_mesh_class , shape_class , enums::polygon_mesh)	
	virtual shape_saver_interface* create_shape_saver_interface (void* aux = 0) = 0; // -1
	virtual polygon_mesh_class &set_threshold (float threshold_param, void * = 0) = 0; // 0
	virtual float get_threshold (void * = 0) const = 0; // 1
	virtual void append_point (const sxsdk::vec3& at, void* aux = 0) = 0; // 2
	virtual void append_edge (int i0, int i1, void* aux = 0) = 0; // 3
	virtual void make_edges (void* aux = 0) = 0; // 4
	virtual polygon_mesh_class &set_smooth_edges (bool smooth_edges_param, void * = 0) = 0; // 5
	virtual bool get_smooth_edges (void * = 0) const = 0; // 6
	virtual int get_number_of_edges (void * = 0) const = 0; // 7
	virtual int get_number_of_faces (void * = 0) const = 0; // 8
	virtual void get_edge_deprecated (int i, int& v0, int& v1, void* aux = 0) = 0; // 9
	virtual void get_face_deprecated (int i, int& v0, int& v1, int& v2, int& v3, void* aux = 0) = 0; // 10
	virtual void set_anchor_point_deprecated (int i, const sxsdk::vec3& p, void* aux = 0) = 0; // 11
	virtual sxsdk::vec3 get_anchor_point_deprecated (int i, void* aux = 0) = 0; // 12
	virtual int get_number_of_active_control_points (void * = 0) const = 0; // 13
	virtual int get_first_active_control_point_deprecated (void * = 0) const = 0; // 14
	virtual int get_next_active_control_point_deprecated (void * = 0) const = 0; // 15
	virtual void select_all_control_points_obsolete (void* aux = 0) = 0; // 16
	virtual void unselect_all_control_points_obsolete (void* aux = 0) = 0; // 17
	virtual void select_control_point_obsolete (int i, void* aux = 0) = 0; // 18
	virtual void remove_control_point (int i, void* aux = 0) = 0; // 19
	virtual polygon_mesh_class &set_round (float round_param, void * = 0) = 0; // 20
	virtual float get_round (void * = 0) const = 0; // 21
	virtual int get_face_n_deprecated (int i, int* v, sxsdk::vec3* normals = 0) = 0; // 22
	virtual polygon_mesh_class &set_show_edges (bool show_edges_param, void * = 0) = 0; // 23
	virtual bool get_show_edges (void * = 0) const = 0; // 24
	virtual polygon_mesh_interface* get_polygon_mesh_interface (void* aux = 0) = 0; // 25
	virtual void append_face (int n_v, const int v[], void* aux = 0) = 0; // 26
	virtual void subdivide (int level, void* aux = 0) = 0; // 27
	virtual void unsubdivide (void* aux = 0) = 0; // 28
	virtual polygon_mesh_saver_class* get_polygon_mesh_saver (void* aux = 0) = 0; // 29
	virtual void remove_edge (int at, void* aux = 0) = 0; // 30
	virtual void remove_face (int at, void* aux = 0) = 0; // 31
	virtual int get_uv_n_deprecated (int i, sxsdk::vec2* uv, void* aux = 0) = 0; // 32
	virtual sxsdk::image_interface* get_texture_image_interface (void * = 0) const = 0; // 33
	virtual void set_uv_deprecated (int i, int j, const sxsdk::vec2& uv, void* aux = 0) = 0; // 34
	virtual sxsdk::vec2 get_uv_deprecated (int i, int j, void* aux = 0) = 0; // 35
	virtual bool has_uv_deprecated (int i, void* aux = 0) = 0; // 36
	virtual void clear_uv_obsolete (int i, void* aux = 0) = 0; // 37
	virtual void make_edge (int i0, int i1, void* aux = 0) = 0; // 38
	virtual void unselect_control_point_obsolete (int i, void* aux = 0) = 0; // 39
	virtual void begin_removing_control_points (void* aux = 0) = 0; // 40
	virtual void end_removing_control_points (void* aux = 0) = 0; // 41
	virtual void begin_selecting_control_points (void* aux = 0) = 0; // 42
	virtual void end_selecting_control_points (void* aux = 0) = 0; // 43
	virtual void begin_removing_faces (void* aux = 0) = 0; // 44
	virtual void end_removing_faces (void* aux = 0) = 0; // 45
	virtual void begin_removing_edges (void* aux = 0) = 0; // 46
	virtual void end_removing_edges (void* aux = 0) = 0; // 47
	virtual bool is_control_point_selected_obsolete (int i, void* aux = 0) = 0; // 48
	virtual void setup_normal (void* aux = 0) = 0; // 49
	virtual void set_parameter_uv_deprecated (int i, int j, const sxsdk::vec2& uv, void* aux = 0) = 0; // 50
	virtual sxsdk::vec2 get_parameter_uv_deprecated (int i, int j, void* aux = 0) = 0; // 51
	virtual void set_distance_uv_deprecated (int i, int j, const sxsdk::vec2& uv, void* aux = 0) = 0; // 52
	virtual sxsdk::vec2 get_distance_uv_deprecated (int i, int j, void* aux = 0) = 0; // 53
	virtual bool adjust_face_direction (void* aux = 0) = 0; // 54
	virtual bool has_consistent_faces (void * = 0) const = 0; // 55
	virtual vertex_attribute_interface* get_vertex_attribute_interface_obsolete (int i, int j, void* aux = 0) = 0; // 56
	virtual void set_vertex_attribute_obsolete (int i, int j, vertex_attribute_interface* vertex_attribute, void* aux = 0) = 0; // 57
	virtual void cleanup_redundant_vertices (void* aux = 0) = 0; // 58
	virtual void setup_winged_edge (void* aux = 0) = 0; // 59
	virtual void clean_winged_edge (void* aux = 0) = 0; // 60
	virtual int eccwfv (int f, int v, bool check, void* aux = 0) = 0; // 61
	virtual int ecwfv (int f, int v, bool check, void* aux = 0) = 0; // 62
	virtual int fccwev (int e, int v, bool check, void* aux = 0) = 0; // 63
	virtual int fcwev (int e, int v, bool check, void* aux = 0) = 0; // 64
	virtual void setup_plane_equation (void* aux = 0) = 0; // 65
	virtual sxsdk::vec4 get_plane_equation (int f, void* aux = 0) = 0; // 66
	virtual vertex_class& vertex (int i, void* aux = 0) = 0; // 67
	virtual edge_class& edge (int i, void* aux = 0) = 0; // 68
	virtual face_class& face (int i, void* aux = 0) = 0; // 69
	virtual polygon_mesh_class &set_roundness_type (int roundness_type_param, void * = 0) = 0; // 70
	virtual int get_roundness_type (void * = 0) const = 0; // 71
	virtual polygon_mesh_class &set_active_edge_indices (int n, int list[], void * = 0) = 0; // 72
	virtual int get_active_edge_indices (int list[], void * = 0) const = 0; // 73
	virtual polygon_mesh_class &set_active_face_indices (int n, int list[], void * = 0) = 0; // 74
	virtual int get_active_face_indices (int list[], void * = 0) const = 0; // 75
	virtual int get_number_of_uv_layers (void* aux = 0) = 0; // 76
	virtual void clear_uv_layers (void* aux = 0) = 0; // 77
	virtual int append_uv_layer (void* aux = 0) = 0; // 78
	virtual void remove_uv_layer (int uv_layer_index, void* aux = 0) = 0; // 79
	virtual void clear_face_group (void* aux = 0) = 0; // 80
	virtual int get_number_of_face_groups (void* aux = 0) = 0; // 81
	virtual bool set_face_group_index (int face_index, int face_group_index, void* aux = 0) = 0; // 82
	virtual int get_face_group_index (int face_index, void* aux = 0) = 0; // 83
	virtual sxsdk::master_surface_class* get_face_group (int face_index, void* aux = 0) = 0; // 84
	virtual sxsdk::master_surface_class* get_face_group_surface (int face_group_index, void* aux = 0) = 0; // 85
	virtual int append_face_group (void* aux = 0) = 0; // 86
	virtual bool set_face_group_surface (int face_group_index, sxsdk::master_surface_class* master_surface_param, void* aux = 0) = 0; // 87
	virtual bool remove_face_group (int face_group_index, void* aux = 0) = 0; // 88
	};

	class sphere_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(sphere_class , shape_class , enums::sphere)
	virtual shape_saver_interface* create_shape_saver_interface (void* aux = 0) = 0; // -1
	virtual sphere_class &set_center (const sxsdk::vec3 &center_param, void * = 0) = 0; // 0
	virtual sxsdk::vec3 get_center (void * = 0) const = 0; // 1
	virtual sphere_class &set_radius (const sxsdk::vec3 &radius_param, void * = 0) = 0; // 2
	virtual sxsdk::vec3 get_radius (void * = 0) const = 0; // 3
	virtual sxsdk::mat4 get_matrix (void * = 0) const = 0; // 4
	virtual sphere_class &set_matrix (const sxsdk::mat4 &matrix_param, void * = 0) = 0; // 5
	virtual sphere_interface* get_sphere_interface (void* aux = 0) = 0; // 6
	virtual sphere_saver_class* get_sphere_saver (void* aux = 0) = 0; // 7
	};

	class disk_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(disk_class , shape_class , enums::disk)	
	virtual shape_saver_interface* create_shape_saver_interface (void* aux = 0) = 0; // -1
	virtual disk_class &set_fill (bool fill_param, void * = 0) = 0; // 0
	virtual bool get_fill (void * = 0) const = 0; // 1
	virtual disk_class &set_starting_angle (float starting_angle_param, void * = 0) = 0; // 2
	virtual float get_starting_angle (void * = 0) const = 0; // 3
	virtual disk_class &set_ending_angle (float ending_angle_param, void * = 0) = 0; // 4
	virtual float get_ending_angle (void * = 0) const = 0; // 5
	virtual disk_class &set_center (const sxsdk::vec3 &center_param, void * = 0) = 0; // 6
	virtual sxsdk::vec3 get_center (void * = 0) const = 0; // 7
	virtual disk_class &set_radius (const sxsdk::vec2 &radius_param, void * = 0) = 0; // 8
	virtual sxsdk::vec2 get_radius (void * = 0) const = 0; // 9
	virtual sxsdk::mat4 get_matrix (void * = 0) const = 0; // 10
	virtual disk_class &set_matrix (const sxsdk::mat4 &matrix_param, void * = 0) = 0; // 11
	virtual disk_interface* get_disk_interface (void* aux = 0) = 0; // 12
	virtual disk_saver_class* get_disk_saver (void* aux = 0) = 0; // 13
	};

	class proxy_shape_class : public shape_class {
	public:
		DEFINE_DYNAMIC_CAST(proxy_shape_class , shape_class , enums::proxy_shape)	
		~proxy_shape_class ();
	virtual proxy_shape_class* get_bro (void * = 0) const = 0; // -1
	virtual proxy_shape_class* get_sis (void * = 0) const = 0; // -1
	virtual proxy_shape_class* get_parent (void * = 0) const = 0; // -1
	virtual proxy_shape_class* get_linked_parent (void * = 0) const = 0; // -1
	virtual sxsdk::shape_class& get_shape (void * = 0) const = 0; // 0
	virtual sxsdk::texture_interface& texture (int thread = 0, void* aux = 0) = 0; // 1
	virtual proxy_shape_class &set_object_id_color (const sxsdk::vec3 &object_id_color_param, void * = 0) = 0; // 2
	virtual sxsdk::vec3 get_object_id_color (void * = 0) const = 0; // 3
	virtual proxy_shape_class &set_surface_id_color (const sxsdk::vec3 &surface_id_color_param, void * = 0) = 0; // 4
	virtual sxsdk::vec3 get_surface_id_color (void * = 0) const = 0; // 5
	virtual proxy_shape_class &set_marker_index (int marker_index_param, void * = 0) = 0; // 6
	virtual int get_marker_index (void * = 0) const = 0; // 7
	virtual proxy_shape_class &set_object_mask_index (int object_mask_index_param, void * = 0) = 0; // 8
	virtual int get_object_mask_index (void * = 0) const = 0; // 9
	virtual proxy_shape_class &set_surface_mask_index (int surface_mask_index_param, void * = 0) = 0; // 10
	virtual int get_surface_mask_index (void * = 0) const = 0; // 11
	};

	class rotator_joint_interface : public unknown_interface {
	public:
	virtual rotator_joint_interface &set_pivot (const sxsdk::vec3 &pivot_param, void * = 0) = 0; // 0
	virtual sxsdk::vec3 get_pivot (void * = 0) const = 0; // 1
	virtual rotator_joint_interface &set_direction (const sxsdk::vec3 &direction_param, void * = 0) = 0; // 2
	virtual sxsdk::vec3 get_direction (void * = 0) const = 0; // 3
	virtual rotator_joint_interface &set_rotation (float rotation_param, void * = 0) = 0; // 4
	virtual float get_rotation (void * = 0) const = 0; // 5
	virtual rotator_joint_interface &set_range (bool range_param, void * = 0) = 0; // 6
	virtual bool get_range (void * = 0) const = 0; // 7
	virtual rotator_joint_interface &set_blend (float blend_param, void * = 0) = 0; // 8
	virtual float get_blend (void * = 0) const = 0; // 9
	virtual rotator_joint_interface &set_flat (bool flat_param, void * = 0) = 0; // 10
	virtual bool get_flat (void * = 0) const = 0; // 11
	virtual rotator_joint_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 12
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 13
	};

	class slider_joint_interface : public unknown_interface {
	public:
	virtual slider_joint_interface &set_starting_position (const sxsdk::vec3 &starting_position_param, void * = 0) = 0; // 0
	virtual sxsdk::vec3 get_starting_position (void * = 0) const = 0; // 1
	virtual slider_joint_interface &set_ending_position (const sxsdk::vec3 &ending_position_param, void * = 0) = 0; // 2
	virtual sxsdk::vec3 get_ending_position (void * = 0) const = 0; // 3
	virtual slider_joint_interface &set_slide (float slide_param, void * = 0) = 0; // 4
	virtual float get_slide (void * = 0) const = 0; // 5
	virtual slider_joint_interface &set_range (bool range_param, void * = 0) = 0; // 6
	virtual bool get_range (void * = 0) const = 0; // 7
	virtual slider_joint_interface &set_blend (float blend_param, void * = 0) = 0; // 8
	virtual float get_blend (void * = 0) const = 0; // 9
	virtual slider_joint_interface &set_flat (bool flat_param, void * = 0) = 0; // 10
	virtual bool get_flat (void * = 0) const = 0; // 11
	virtual slider_joint_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 12
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 13
	};

	class scale_joint_interface : public unknown_interface {
	public:
	virtual scale_joint_interface &set_pivot (const sxsdk::vec3 &pivot_param, void * = 0) = 0; // 0
	virtual sxsdk::vec3 get_pivot (void * = 0) const = 0; // 1
	virtual scale_joint_interface &set_direction (const sxsdk::vec3 &direction_param, void * = 0) = 0; // 2
	virtual sxsdk::vec3 get_direction (void * = 0) const = 0; // 3
	virtual scale_joint_interface &set_scale (float scale_param, void * = 0) = 0; // 4
	virtual float get_scale (void * = 0) const = 0; // 5
	virtual scale_joint_interface &set_range (bool range_param, void * = 0) = 0; // 6
	virtual bool get_range (void * = 0) const = 0; // 7
	virtual scale_joint_interface &set_flat (bool flat_param, void * = 0) = 0; // 8
	virtual bool get_flat (void * = 0) const = 0; // 9
	virtual scale_joint_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 10
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 11
	};

	class uniscale_joint_interface : public unknown_interface {
	public:
	virtual uniscale_joint_interface &set_pivot (const sxsdk::vec3 &pivot_param, void * = 0) = 0; // 0
	virtual sxsdk::vec3 get_pivot (void * = 0) const = 0; // 1
	virtual uniscale_joint_interface &set_scale (float scale_param, void * = 0) = 0; // 2
	virtual float get_scale (void * = 0) const = 0; // 3
	virtual uniscale_joint_interface &set_range (bool range_param, void * = 0) = 0; // 4
	virtual bool get_range (void * = 0) const = 0; // 5
	virtual uniscale_joint_interface &set_flat (bool flat_param, void * = 0) = 0; // 6
	virtual bool get_flat (void * = 0) const = 0; // 7
	virtual uniscale_joint_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 8
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 9
	};

	class light_effector_interface : public unknown_interface {
	public:
	virtual light_effector_interface &set_value (float value_param, void * = 0) = 0; // 0
	virtual float get_value (void * = 0) const = 0; // 1
	virtual light_effector_interface &set_range (bool range_param, void * = 0) = 0; // 2
	virtual bool get_range (void * = 0) const = 0; // 3
	virtual light_effector_interface &set_flat (bool flat_param, void * = 0) = 0; // 4
	virtual bool get_flat (void * = 0) const = 0; // 5
	virtual light_effector_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 6
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 7
	};

	class path_joint_interface : public unknown_interface {
	public:
	virtual path_joint_interface &set_path_position (float path_position_param, void * = 0) = 0; // 0
	virtual float get_path_position (void * = 0) const = 0; // 1
	virtual path_joint_interface &set_range (bool range_param, void * = 0) = 0; // 2
	virtual bool get_range (void * = 0) const = 0; // 3
	virtual path_joint_interface &set_flat (bool flat_param, void * = 0) = 0; // 4
	virtual bool get_flat (void * = 0) const = 0; // 5
	virtual path_joint_interface &set_correction (int correction_param, void * = 0) = 0; // 6
	virtual int get_correction (void * = 0) const = 0; // 7
	virtual path_joint_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 8
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 9
	};

	class morph_effector_interface : public unknown_interface {
	public:
	virtual morph_effector_interface &set_morph (float morph_param, void * = 0) = 0; // 0
	virtual float get_morph (void * = 0) const = 0; // 1
	virtual morph_effector_interface &set_range (bool range_param, void * = 0) = 0; // 2
	virtual bool get_range (void * = 0) const = 0; // 3
	virtual morph_effector_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 4
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 5
	};

	class ball_joint_interface : public unknown_interface {
	public:
	virtual ball_joint_interface &set_rotation (const sxsdk::quaternion_class &rotation_param, void * = 0) = 0; // 0
	virtual sxsdk::quaternion_class get_rotation (void * = 0) const = 0; // 1
	virtual ball_joint_interface &set_offset (const sxsdk::vec3 &offset_param, void * = 0) = 0; // 2
	virtual sxsdk::vec3 get_offset (void * = 0) const = 0; // 3
	virtual ball_joint_interface &set_blend (float blend_param, void * = 0) = 0; // 4
	virtual float get_blend (void * = 0) const = 0; // 5
	virtual ball_joint_interface &set_flat (bool flat_param, void * = 0) = 0; // 6
	virtual bool get_flat (void * = 0) const = 0; // 7
	virtual ball_joint_interface &set_position (const sxsdk::vec3 &position_param, void * = 0) = 0; // 8
	virtual sxsdk::vec3 get_position (void * = 0) const = 0; // 9
	virtual ball_joint_interface &set_size (float size_param, void * = 0) = 0; // 10
	virtual float get_size (void * = 0) const = 0; // 11
	};

	class custom_joint_interface : public unknown_interface {
	public:
	virtual custom_joint_interface &set_value (float value_param, void * = 0) = 0; // 0
	virtual float get_value (void * = 0) const = 0; // 1
	virtual custom_joint_interface &set_range (bool range_param, void * = 0) = 0; // 2
	virtual bool get_range (void * = 0) const = 0; // 3
	virtual custom_joint_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 4
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 5
	};

	class sound_track_interface : public unknown_interface {
	public:
	virtual sound_track_interface &set_value (float value_param, void * = 0) = 0; // 0
	virtual float get_value (void * = 0) const = 0; // 1
	virtual sound_track_interface &set_range (bool range_param, void * = 0) = 0; // 2
	virtual bool get_range (void * = 0) const = 0; // 3
	virtual sound_track_interface &set_repetition (int repetition_param, void * = 0); sound_track_interface &set_repeat (int repetition_param) { return set_repetition(repetition_param); }  // 4
	virtual int get_repetition (void * = 0) const; int get_repeat() const { return get_repetition(); }  // 5
	virtual sound_track_interface &set_sound3d (bool sound3d_param, void * = 0) = 0; // 6
	virtual bool get_sound3d (void * = 0) const = 0; // 7
	virtual void play (int repeat = 0, void* aux = 0) = 0; // 8
	virtual void stop (void* aux = 0) = 0; // 9
	virtual bool is_playing (void* aux = 0) = 0; // 10
	};

	class switch_effector_interface : public unknown_interface {
	public:
	virtual switch_effector_interface &set_selection (int selection_param, void * = 0) = 0; // 0
	virtual int get_selection (void * = 0) const = 0; // 1
	virtual switch_effector_interface &set_range (bool range_param, void * = 0) = 0; // 2
	virtual bool get_range (void * = 0) const = 0; // 3
	virtual switch_effector_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 4
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 5
	};

	class path_replicator_interface : public unknown_interface {
	public:
	virtual path_replicator_interface &set_replication (float replication_param, void * = 0) = 0; // 0
	virtual float get_replication (void * = 0) const = 0; // 1
	virtual path_replicator_interface &set_range (bool range_param, void * = 0) = 0; // 2
	virtual bool get_range (void * = 0) const = 0; // 3
	virtual path_replicator_interface &set_mode (int mode_param, void * = 0) = 0; // 4
	virtual int get_mode (void * = 0) const = 0; // 5
	virtual path_replicator_interface &set_alignment_type (int alignment_type_param, void * = 0) = 0; // 6
	virtual int get_alignment_type (void * = 0) const = 0; // 7
	virtual path_replicator_interface &set_step_rounding_type (int step_rounding_type_param, void * = 0) = 0; // 8
	virtual int get_step_rounding_type (void * = 0) const = 0; // 9
	virtual path_replicator_interface &set_skip_head (bool skip_head_param, void * = 0) = 0; // 10
	virtual bool get_skip_head (void * = 0) const = 0; // 11
	virtual path_replicator_interface &set_skip_tail (bool skip_tail_param, void * = 0) = 0; // 12
	virtual bool get_skip_tail (void * = 0) const = 0; // 13
	virtual path_replicator_interface &set_count (int count_param, void * = 0) = 0; // 14
	virtual int get_count (void * = 0) const = 0; // 15
	virtual path_replicator_interface &set_step (float step_param, void * = 0) = 0; // 16
	virtual float get_step (void * = 0) const = 0; // 17
	virtual path_replicator_interface &set_limit (const sxsdk::vec2 &limit_param, void * = 0) = 0; // 18
	virtual sxsdk::vec2 get_limit (void * = 0) const = 0; // 19
	};
}
