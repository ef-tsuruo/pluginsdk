#pragma once

namespace sxsdk {
	class shape_interface : public shade_interface {
	public:
		virtual bool is_same_as ( shade_interface* i , void* aux =0 ) ;
		virtual scene_interface* get_scene_interface ( void* aux =0 ) const ;

		virtual surface_interface* get_surface_interface ( void* aux =0 )  ; //
		virtual motion_interface* get_motion_interface ( void* aux =0 )  ; //
		virtual shape_interface* get_bro_interface ( void* aux =0 ) ;
		virtual shape_interface* get_sis_interface ( void* aux =0 ) ;
		virtual part_interface* get_dad_interface ( void* aux =0 ) ;
		virtual shape_interface* get_son_interface ( void* aux =0 ) ;
		virtual enums::shape_type get_type ( void* aux =0 ) ;
		virtual void* get_handle ( void* aux =0 )  ;
		virtual const char* get_shader_obsolete ( void* aux =0 )  ; // obsolete
		virtual bool has_color_obsolete ( void* aux =0 )  ; // obsolete
		virtual sx::rgb<float> get_color_obsolete ( void* aux =0 )  ; // obsolete
		virtual bool is_one_of_active_shapes ( void* aux =0 )  ;
		virtual shape_interface* begin ( void* aux =0 ) ;
		virtual bool is_end ( void* aux =0 ) ;
		virtual mat4 get_transformation ( void* aux =0 ) ;
		virtual int get_number_of_points ( void* aux =0 )  ;
		virtual sx::vec<float,3> get_point ( int i , void* aux =0 ) ;
		virtual void set_point ( int i , const sx::vec<float,3>& v , void* aux =0 ) ;
		virtual void set_name ( const char* s , void* aux =0 ) ;
		virtual const char* get_name ( void* aux =0 ) ;
		virtual void set_extrude ( const sx::vec<float,3>& v , void* aux =0 )  ; //
		virtual sx::vec<float,3> get_extrude ( void* aux =0 )  ;
		virtual void set_revolve_from ( float f , void* aux =0 )  ; //
		virtual float get_revolve_from ( void* aux =0 )  ;
		virtual void set_revolve_to ( float f , void* aux =0 )  ; //
		virtual float get_revolve_to ( void* aux =0 )  ;
		virtual bool get_has_surface_attributes ( void* aux =0 )  ; //
		virtual void set_has_surface_attributes ( bool b , void* aux =0 )  ;
		virtual void set_has_diffuse_color ( bool b , void* aux =0 )  ; void set_has_base_color ( bool b , void* aux =0 )  { set_has_diffuse_color(b , aux ) ; } //35003 name changed
		virtual bool get_has_diffuse_color ( void* aux =0 )  ; bool get_has_base_color ( void* aux =0 )  { return get_has_diffuse_color(aux ) ; } //35003 name changed
		virtual void set_base_color ( const sx::rgb<float>& color , void* aux =0 )  ; // 35003 predicated
		virtual sx::rgb<float> get_diffuse_color ( void* aux =0 )  ; sx::rgb<float> get_base_color ( void* aux =0 )  { return get_diffuse_color(aux ) ; } //35003 name changed
		virtual void set_master_surface ( void* master_surface_handle , void* aux =0 )  ; //
		virtual void* get_master_surface ( void* aux =0 )  ;
		virtual part_interface* get_part_interface ( void* aux =0 ) ;
		virtual line_interface* get_line_interface ( void* aux =0 ) ;
		virtual polygon_mesh_interface* get_polygon_mesh_interface ( void* aux =0 ) ;
		virtual disk_interface* get_disk_interface ( void* aux =0 ) ;
		virtual sphere_interface* get_sphere_interface ( void* aux =0 ) ;
		virtual light_interface* get_light_interface ( void* aux =0 ) ;
		virtual sx::vec<float,3> get_center_point ( void* aux =0 )  ;
		virtual mat4 get_local_to_world_matrix ( void* aux =0 ) ;
		virtual mat4 get_world_to_local_matrix ( void* aux =0 ) ;
		virtual void transform ( const mat4& matrix , void* aux =0 )  ;
		virtual bool has_surface ( void* aux =0 )  ; // 27034
		virtual bool has_motion ( void* aux =0 )  ; // 27034
		virtual bool has_bro ( void* aux =0 ) ; // 27034
		virtual bool has_sis ( void* aux =0 ) ; // 27034
		virtual bool has_dad ( void* aux =0 ) ; // 27034
		virtual bool has_son ( void* aux =0 ) ; // 27034
		virtual void remove ( void* aux =0 )  ; //27037
		virtual bool is_extruded ( void* aux =0 )  ; //27037
		virtual bool is_revolved ( void* aux =0 )  ; //27037
		virtual mat4 get_axis_matrix ( void* aux =0 )  ; //27038
		virtual void set_flip_face ( bool b , void* aux =0 )  ; // 27055
		virtual bool get_flip_face ( void* aux =0 )  ;
		virtual int get_total_number_of_control_points ( void* aux =0 ) ; // 27087
		virtual void cancel_transformation ( void* aux =0 )  ; // 27130
		virtual mesh_interface* convert_to_mesh_obsolete ( int m =0 , int n =0 , void* aux =0 )  ; // 27313 obsolete. use convert_to_meshes instead.
		virtual stream_interface* create_attribute_stream_interface ( int attribute_id , int wireframe_id =0 , int intersection_id =0 , void* aux =0 ) ; stream_interface* create_attribute_stream ( int attribute_id , int wireframe_id =0 , int intersection_id =0 , void* aux =0 )  { return create_attribute_stream_interface(attribute_id , wireframe_id , intersection_id , aux ) ; } //28003 33042:changed to create_attribute_stream_interface
		virtual stream_interface* get_attribute_stream_interface ( int attribute_id , void* aux =0 ) ; stream_interface* get_attribute_stream ( int attribute_id , void* aux =0 )  { return get_attribute_stream_interface(attribute_id , aux ) ; } //28003 33042:changed to get_attribute_stream_interface
		virtual void make_sphere_wireframe ( const mat4& mat , const mat4& trans , void* aux =0 ) ; //28003
		virtual void set_axis_matrix ( const mat4& m , void* aux =0 )  ; //28013
		virtual int get_ordinal ( void* aux =0 )  ; // 28022
		virtual void set_surface ( surface_interface* surface , void* aux =0 )  ; //28061
		virtual void make_line_wireframe ( const mat4& mat , int n , const sx::vec<float,3>* p , bool closed =false , void* aux =0 ) ; //28066
		virtual shape_class& get_shape (void* aux = 0);
		virtual void update ( void* aux =0 )  ; //28086
		virtual void begin_set_point ( void* aux =0 )  ; //28086
		virtual void end_set_point ( void* aux =0 )  ; //28086
		virtual void show ( void* aux =0 )  ; //29006
		virtual void hide ( void* aux =0 )  ; //29006
		virtual bool delete_attribute ( int attribute_id , void* aux =0 ) ; //29034
		virtual void place_parent ( int n , void* aux =0 )  ; //29107
		virtual void place_child ( int n , void* aux =0 )  ; //29107
		virtual void place_brother ( int n , void* aux =0 )  ; //29107
		virtual void place_sister ( int n , void* aux =0 )  ; //29107
		virtual void place ( shape_class& at , void* aux =0 )  ; //29107
		virtual void copy ( void* aux =0 )  ; //29113
		virtual void paste ( void* aux =0 )  ; //29113
		virtual shape_class& copy_object ( const mat4& t , void* aux =0 )  ; //29124
		virtual void move_object ( const mat4& t , void* aux =0 )  ; //29124
		virtual bool is_shown ( void* aux =0 )  ; //29134
		virtual float get_diffuse_value ( void* aux =0 )  ; //30046
		virtual void set_diffuse_value ( float f , void* aux =0 )  ; //30046
		virtual void solid_extrude ( const sx::vec<float,3>& v , void* aux =0 )  ; //31000
		virtual void solid_revolve ( const sx::vec<float,3>& v0 , const sx::vec<float,3>& v1 , void* aux =0 )  ; //31000
		virtual void solid_clear ( void* aux =0 )  ; //31000
		virtual void reset_transformation ( bool deep =false , void* aux =0 ) ; //31050
		virtual meshes_interface* create_converted_meshes_interface ( int level =2 , int texture =0 , void* aux =0 )  ; meshes_interface* convert_to_meshes ( int level =2 , int texture =0 , void* aux =0 )  { return create_converted_meshes_interface(level , texture , aux ) ; } //31050 33042:changed to create_converted_meshes_interface
		virtual polygon_mesh_interface* create_converted_polygon_mesh_interface ( int level =2 , int texture =0 , void* aux =0 )  ; polygon_mesh_interface* convert_to_polygon_mesh ( int level =2 , int texture =0 , void* aux =0 )  { return create_converted_polygon_mesh_interface(level , texture , aux ) ; } //31050 33042:changed to create_converted_polygon_mesh_interface
		virtual bool is_switched ( void* aux =0 )  ; //31050
		virtual void adjust_transformation ( void* aux =0 ) ; //31064
		virtual bool get_modifiable ( void* aux =0 )  ; //31068
		virtual void set_modifiable ( bool modifiable , void* aux =0 )  ; //31068
		virtual bool get_browsable ( void* aux =0 )  ; //31082
		virtual void set_browsable ( bool browsable , void* aux =0 )  ; //31082
		virtual int get_render ( void* aux =0 )  ; //32021
		virtual void set_render ( int render , void* aux =0 )  ; //32021
		virtual void set_active_control_point ( int i , bool active , void* aux =0 ) ; //32203 this obsoletes select_control_point( )
		virtual bool get_active_control_point ( int i , void* aux =0 ) ; //32203
		virtual void append_skin ( part_interface& part , float weight =1.0 , void* aux =0 ) ; //32288
		virtual void clear_skin ( void* aux =0 ) ; //32288
		virtual void select ( void* aux =0 )  ; //32288
		virtual void select_all_control_points ( bool select , void* aux =0 ) ; //32297
		virtual bool is_control_point_selected ( int i , void* aux =0 ) ; //32297
		virtual bool get_rendering_flag ( void* aux =0 ) ; //32318
		virtual void set_has_shadow_map_size ( bool has_shadow_map_size , void* aux =0 ) ; //32418
		virtual bool get_has_shadow_map_size ( void* aux =0 ) ; //32418
		virtual void set_shadow_map_size ( int shadow_map_size , void* aux =0 ) ; //32418
		virtual int get_shadow_map_size ( void* aux =0 ) ; //32418
		virtual void set_has_shadow_map_bias ( bool has_shadow_map_bias , void* aux =0 ) ; //32418
		virtual bool get_has_shadow_map_bias ( void* aux =0 ) ; //32418
		virtual void set_shadow_map_bias ( float shadow_map_bias , void* aux =0 ) ; //32418
		virtual float get_shadow_map_bias ( void* aux =0 ) ; //32418
		virtual void set_has_shadow_map_blur ( bool has_shadow_map_blur , void* aux =0 ) ; //32418
		virtual bool get_has_shadow_map_blur ( void* aux =0 ) ; //32418
		virtual void set_shadow_map_blur ( float shadow_map_blur , void* aux =0 ) ; //32418
		virtual float get_shadow_map_blur ( void* aux =0 ) ; //32418
		virtual void set_shadow_type ( enums::shadow_type shadow_type , void* aux =0 ) ; //32418
		virtual enums::shadow_type get_shadow_type ( void* aux =0 ) ; //32418
		virtual int get_active_control_points ( int *p , void* aux =0 ) ; //33044
			virtual int shape_interface_test_1 ( void* aux =0 )  { return 1; }
		virtual bool has_special_character ( char c , void* aux =0 ) ; //34011
		virtual void set_diffuse_color ( const sx::rgb<float>& color , void* aux =0 )  ; //35003
		virtual shape_class& link_object ( const mat4& t , void* aux =0 )  ; //35033
		virtual shape_saver_interface* create_shape_saver_interface ( void* aux =0 )  ;
		virtual texture_interface* create_texture_interface ( int self , const sx::vec<float,3>& point , const sx::vec<float,3>& shading_normal , const sx::vec<float,3>& geometric_normal , const sx::vec<float,3>& incident , const sx::vec<float,2>* uv , const sx::vec<float,3>* du , const sx::vec<float,3>* dv , void* aux =0 ) ; //35040
		virtual radiosity_attributes_interface* get_radiosity_attributes_interface ( void* aux =0 ) ; //35079
		virtual void move_links ( const mat4& t , void* aux =0 ) ; //36015
		virtual part_interface* get_linked_dad_interface ( void* aux =0 ) ; //36015
		virtual skin_class& get_skin ( int i , void* aux =0 ) ; //36032
		virtual int get_number_of_skin_points ( void* aux =0 ) ; //36034
		virtual bool has_symbol ( char symbol , void* aux =0 ) ; //36053
		virtual void set_bounding_box_size (const sxsdk::vec3 bounding_box_size, void* aux =0 ); //135 440444
		virtual sxsdk::vec3 get_bounding_box_size ( void* aux =0 )  ; //136 440444
		virtual void set_bounding_box_center (const sxsdk::vec3 center_position, void* aux =0 ); //137 440471
		virtual sxsdk::vec3 get_bounding_box_center ( void* aux =0 )  ; //138 440471
		virtual void set_active_vertex_indices (int n, int *indices, void *aux = 0); //139 + 60 431141
		virtual int get_active_vertex_indices (int *indices, void *aux = 0); //140 + 59 431141
		virtual void update_skin_bindings (void *aux = 0); //141 + 58 431141
		virtual int shape_interface_dummy0(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy1(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy2(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy3(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy4(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy5(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy6(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy7(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy8(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy9(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy10(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy11(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy12(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy13(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy14(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy15(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy16(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy17(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy18(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy19(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy20(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy21(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy22(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy23(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy24(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy25(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy26(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy27(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy28(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy29(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy30(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy31(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy32(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy33(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy34(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy35(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy36(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy37(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy38(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy39(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy40(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy41(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy42(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy43(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy44(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy45(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy46(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy47(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy48(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy49(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy50(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy51(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy52(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy53(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy54(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy55(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy56(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
		virtual int shape_interface_dummy57(void *) { SXASSERT(false); throw "invalid interface shape_interface"; return 0; }
	};

	class part_interface : public shape_interface {
	public:
		virtual void reset_transformation ( bool deep =false , void* aux =0 ) ; //31050
		virtual bool is_switched ( void* aux =0 )  ; //31050
		virtual void adjust_transformation ( void* aux =0 ) ; //31064
		virtual bool is_control_point_selected ( int i , void* aux =0 ) ;

		virtual enums::part_type get_part_type ( void* aux =0 ) ;
		virtual bool is_closed_surface_ ( void* aux =0 )  ; // obsolete 990621. was is_closed_surface
		virtual bool is_flipped_ ( void* aux =0 )  ; // obsolete 990621. was is_flipped
		virtual bool is_master_surface ( void* aux =0 )  ;
		virtual int get_number_of_sons ( void* aux =0 ) ;
		virtual bool has_skip_joint_obsolete ( void* aux =0 )  { return false; } //obsoleted 31165
		virtual bool is_pose_joint ( void* aux =0 )  ;
		virtual void set_transformation_matrix ( const mat4& m , void* aux =0 )  ; //
		virtual mat4 get_transformation_matrix ( void* aux =0 )  ;
		virtual void switch_ ( void* aux =0 )  ; // 27088
		virtual void set_anchor_point ( int i , const sx::vec<float,3>& p , const bool* world_coordinates )  ; // 27107
		virtual sx::vec<float,3> get_anchor_point ( int i , const bool* world_coordinates )  ; // 27107
		virtual void set_inhandle ( int i , const sx::vec<float,3>& v , const bool* world_coordinates )  ; // 27121
		virtual sx::vec<float,3> get_inhandle ( int i , const bool* world_coordinates )  ; //27121
		virtual void set_outhandle ( int i , const sx::vec<float,3>& v , const bool* world_coordinates )  ; // 27121
		virtual sx::vec<float,3> get_outhandle ( int i , const bool* world_coordinates )  ; //27121
		virtual void set_handle_linked ( int i , bool b , void* aux =0 )  ; // 27121
		virtual bool get_handle_linked ( int i , void* aux =0 )  ; //27121
		virtual void set_lateral_inhandle ( int i , const sx::vec<float,3>& v , const bool* world_coordinates )  ; // 27121
		virtual sx::vec<float,3> get_lateral_inhandle ( int i , const bool* world_coordinates )  ; //27121
		virtual void set_lateral_outhandle ( int i , const sx::vec<float,3>& v , const bool* world_coordinates )  ; // 27121
		virtual sx::vec<float,3> get_lateral_outhandle ( int i , const bool* world_coordinates )  ; //27121
		virtual void set_lateral_handle_linked ( int i , bool b , void* aux =0 )  ; // 27121
		virtual bool get_lateral_handle_linked ( int i , void* aux =0 )  ; //27121
		virtual void set_closed ( bool b , void* aux =0 )  ; // 27121
		virtual bool get_closed ( void* aux =0 )  ; //27121
		virtual int get_number_of_active_control_points ( void* aux =0 )  ;
		virtual int get_first_active_control_point ( void* aux =0 )  ; // 27121
		virtual int get_next_active_control_point ( void* aux =0 )  ; // 27121
		virtual void select_all_control_points_obsolete ( void* aux =0 )  ; // 27121 obsoleted 32297
		virtual void unselect_all_control_points_obsolete ( void* aux =0 )  ; // 27121 obsoleted 32297
		virtual void select_control_point_obsolete ( int i , void* aux =0 )  ; // 27121 obsoleted 32297
		virtual void remove_control_point ( int i , void* aux =0 )  ; // 27122
		virtual bool get_surface_closed ( void* aux =0 )  ; //28020
		virtual void set_surface_closed ( bool b , void* aux =0 )  ; //28020
		virtual bool get_surface_switched ( void* aux =0 )  ; //28020
		virtual void set_surface_switched ( bool b , void* aux =0 )  ; //28020
		virtual part_class& get_part (void* aux = 0);
		virtual mat4 get_joint_matrix ( void* aux =0 )  ; //29015
		virtual bool get_flat_joint ( void* aux =0 )  ; //29015
		virtual void set_flat_joint ( bool b , void* aux =0 )  ; //29015
		virtual void reverse ( void* aux =0 )  ; //29101
		virtual void iron ( int n =-1 , const int* i =0 , void* aux =0 )  ; //29101
		virtual void smooth ( int n =-1 , const int* i =0 , void* aux =0 )  ; //29101
		virtual void unsmooth ( int n =-1 , const int* i =0 , void* aux =0 )  ; // 29101
		virtual bool get_disclosed ( void* aux =0 )  ; //29124
		virtual void set_disclosed ( bool b , void* aux =0 )  ; //29124
		virtual void disclose_all ( void* aux =0 )  ; //30100
		virtual void undisclose_all ( void* aux =0 )  ; //30100
		virtual bool has_inhandle ( int i , void* aux =0 )  ; //31071
		virtual bool has_outhandle ( int i , void* aux =0 )  ; //31071
		virtual bool has_lateral_inhandle ( int i , void* aux =0 )  ; //31071
		virtual bool has_lateral_outhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_inhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_outhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_lateral_inhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_lateral_outhandle ( int i , void* aux =0 )  ; //31071
		virtual mesh_interface* create_control_mesh_interface ( void* aux =0 )  ; mesh_interface* get_control_mesh ( void* aux =0 )  { return create_control_mesh_interface(aux ) ; } //32054 33042:changed to create_control_mesh_interface
		virtual float get_joint_blend ( void* aux =0 )  ; //32212
		virtual void set_joint_blend ( float joint_blend , void* aux =0 )  ; //32212
		virtual void set_view ( void* aux =0 )  ; //32294
		virtual enums::anchor_type get_view_anchor ( void* aux =0 )  ; //32294
		virtual void set_view_anchor ( enums::anchor_type anchor , void* aux =0 )  ; //32294
		virtual void select_camera_joint ( void* aux =0 ) ; //32305
		virtual int part_interface_test_1 ( void* aux =0 )  { return 1; }
		virtual shape_interface* get_link_interface ( void* aux =0 ) ; //35033
		virtual void set_link_interface ( shape_interface* shape , void* aux =0 ) ; //36011
		
		virtual int part_interface_dummy0(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy1(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy2(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy3(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy4(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy5(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy6(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy7(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy8(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy9(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy10(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy11(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy12(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy13(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy14(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy15(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy16(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy17(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy18(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy19(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy20(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy21(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy22(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy23(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy24(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy25(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy26(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy27(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy28(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy29(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy30(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy31(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy32(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy33(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy34(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy35(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy36(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy37(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy38(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy39(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy40(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy41(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy42(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy43(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy44(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy45(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy46(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy47(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy48(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy49(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy50(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy51(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy52(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy53(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy54(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy55(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy56(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy57(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy58(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy59(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy60(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy61(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy62(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy63(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy64(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy65(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy66(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy67(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy68(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy69(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy70(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy71(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy72(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy73(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy74(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy75(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy76(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy77(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy78(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy79(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy80(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy81(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy82(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy83(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy84(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy85(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy86(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy87(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy88(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy89(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy90(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy91(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy92(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy93(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy94(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy95(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy96(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy97(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy98(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy99(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy100(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy101(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy102(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy103(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy104(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy105(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy106(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy107(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy108(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy109(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy110(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy111(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy112(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy113(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy114(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy115(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy116(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy117(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy118(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy119(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy120(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy121(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy122(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy123(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy124(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy125(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy126(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy127(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy128(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy129(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy130(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy131(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
		virtual int part_interface_dummy132(void *) { SXASSERT(false); throw "invalid interface part_interface"; return 0; }
	};

	class line_interface : public shape_interface {
	public:
		virtual void set_point ( int i , const sx::vec<float,3>& v , void* aux =0 ) ;
		virtual sx::vec<float,3> get_point ( int i , void* aux =0 ) ;
		virtual bool is_control_point_selected ( int i , void* aux =0 ) ;

		virtual int get_number_of_control_points ( void* aux =0 )  ;
		virtual void set_anchor_point ( int i , const sx::vec<float,3>& v , void* aux =0 )  ; //
		virtual sx::vec<float,3> get_anchor_point ( int i , void* aux =0 )  ;
		virtual void set_inhandle ( int i , const sx::vec<float,3>& v , void* aux =0 )  ; //
		virtual sx::vec<float,3> get_inhandle ( int i , void* aux =0 )  ;
		virtual void set_outhandle ( int i , const sx::vec<float,3>& v , void* aux =0 )  ; //
		virtual sx::vec<float,3> get_outhandle ( int i , void* aux =0 )  ;
		virtual void set_handle_linked ( int i , bool b , void* aux =0 )  ; //
		virtual bool get_handle_linked ( int i , void* aux =0 )  ;
		virtual void set_lateral_inhandle ( int i , const sx::vec<float,3>& v , void* aux =0 )  ; //
		virtual sx::vec<float,3> get_lateral_inhandle ( int i , void* aux =0 )  ;
		virtual void set_lateral_outhandle ( int i , const sx::vec<float,3>& v , void* aux =0 )  ; //
		virtual sx::vec<float,3> get_lateral_outhandle ( int i , void* aux =0 )  ;
		virtual void set_lateral_handle_linked ( int i , bool b , void* aux =0 )  ; //
		virtual bool get_lateral_handle_linked ( int i , void* aux =0 )  ;
		virtual void set_closed ( bool b , void* aux =0 )  ; //
		virtual bool get_closed ( void* aux =0 )  ;
		virtual void set_hole ( bool b , void* aux =0 )  ; //
		virtual bool get_hole ( void* aux =0 )  ;
		virtual int get_number_of_active_control_points ( void* aux =0 )  ;
		virtual int get_first_active_control_point ( void* aux =0 )  ; //
		virtual int get_next_active_control_point ( void* aux =0 )  ; //
		virtual void select_all_control_points_obsolete ( void* aux =0 )  ; // obsoleted 32297
		virtual void unselect_all_control_points_obsolete ( void* aux =0 )  ; // obsoleted 32297
		virtual void select_control_point_obsolete ( int i , void* aux =0 )  ; // obsoleted 32297
		virtual void set_skip_joint ( int skip_joint , void* aux =0 )  ;
		virtual int get_skip_joint_obsolete ( void* aux =0 )  { return 0; } //obsoleted 31165
		virtual void reverse ( void* aux =0 )  ; // 27088 ati]
		virtual void insert_control_point ( float t , void* aux =0 )  ; //27116
		virtual void remove_control_point ( int i , void* aux =0 )  ; // 27122
		virtual line_class& get_line (void* aux = 0);
		virtual void iron ( int n =-1 , const int* i =0 , void* aux =0 )  ; //29101
		virtual void smooth ( int n =-1 , const int* i =0 , void* aux =0 )  ; //29101
		virtual void unsmooth ( int n =-1 , const int* i =0 , void* aux =0 )  ; //29101
		virtual void round_edge ( float r , void* aux =0 )  ; //29101
		virtual void bevel_edge ( float r , void* aux =0 )  ; //29101
		virtual void degenerate ( void* aux =0 )  ; //29101
		virtual float get_light_intensity ( void* aux =0 )  ;
				float get_area_light_intensity ( void* aux =0 ) { return get_light_intensity(aux); }
		virtual void set_light_intensity ( float f , void* aux =0 )  ;
				void set_area_light_intensity ( float f , void* aux =0 ) { set_light_intensity(f, aux); }
		virtual float get_light_specular ( void* aux =0 )  ;
				float get_area_light_specular ( void* aux =0 ) { return get_light_specular(aux); }
		virtual void set_light_specular ( float f , void* aux =0 )  ;
				void set_area_light_specular ( float f , void* aux =0 ) { set_light_specular(f, aux); }
		virtual bool get_light_visible ( void* aux =0 )  ;
				bool get_area_light_visible ( void* aux =0 ) { return get_light_visible(aux); }
		virtual void set_light_visible ( bool b , void* aux =0 )  ;
				void set_area_light_visible ( bool b , void* aux =0 ) { set_light_visible(b, aux); }
		virtual bool has_inhandle ( int i , void* aux =0 )  ; //31071
		virtual bool has_outhandle ( int i , void* aux =0 )  ; //31071
		virtual bool has_lateral_inhandle ( int i , void* aux =0 )  ; //31071
		virtual bool has_lateral_outhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_inhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_outhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_lateral_inhandle ( int i , void* aux =0 )  ; //31071
		virtual void remove_lateral_outhandle ( int i , void* aux =0 )  ; //31071
		virtual int line_interface_test_1 ( void* aux =0 )  { return 1; }
		virtual void set_lumen ( bool b , void* aux =0 ) ;
		virtual bool get_lumen ( void* aux =0 )  const;
		virtual enums::light_type get_light_type ( void* aux =0 ) ; //36031
		virtual void set_light_type (enums::light_type i, void* aux =0 ) ;
		
		virtual int line_interface_dummy0(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy1(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy2(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy3(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy4(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy5(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy6(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy7(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy8(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy9(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy10(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy11(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy12(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy13(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy14(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy15(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy16(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy17(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy18(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy19(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy20(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy21(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy22(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy23(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy24(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy25(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy26(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy27(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy28(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy29(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy30(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy31(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy32(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy33(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy34(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy35(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy36(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy37(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy38(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy39(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy40(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy41(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy42(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy43(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy44(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy45(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy46(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy47(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy48(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy49(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy50(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy51(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy52(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy53(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy54(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy55(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy56(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy57(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy58(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy59(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy60(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy61(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy62(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy63(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy64(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy65(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy66(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy67(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy68(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy69(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy70(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy71(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy72(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy73(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy74(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy75(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy76(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy77(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy78(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy79(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy80(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy81(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy82(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy83(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy84(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy85(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy86(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy87(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy88(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy89(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy90(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy91(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy92(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy93(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy94(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy95(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy96(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy97(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy98(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy99(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy100(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy101(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy102(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy103(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy104(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy105(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy106(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy107(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy108(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy109(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy110(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy111(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy112(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy113(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy114(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy115(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy116(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy117(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy118(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy119(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy120(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy121(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy122(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy123(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy124(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy125(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy126(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy127(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy128(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy129(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy130(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy131(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy132(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy133(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy134(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy135(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy136(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy137(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy138(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy139(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy140(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy141(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy142(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
		virtual int line_interface_dummy143(void *) { SXASSERT(false); throw "invalid interface line_interface"; return 0; }
	};

	class polygon_mesh_interface : public shape_interface {
	public:
		virtual void set_point ( int i , const sx::vec<float,3>& v , void* aux =0 ) ;
		virtual sx::vec<float,3> get_point ( int i , void* aux =0 ) ;
		virtual bool is_control_point_selected ( int i , void* aux =0 ) ;

		virtual void set_threshold ( float f , void* aux =0 )  ; //
		virtual float get_threshold ( void* aux =0 )  ;
		virtual void append_point ( const sx::vec<float,3>& p , void* aux =0 )  ; //
		virtual void append_edge ( int i0 , int i1 , void* aux =0 )  ; //
		virtual void make_edges ( void* aux =0 )  ; // 2.70
		virtual void set_smooth_edges ( bool b , void* aux =0 )  ; //
		virtual bool get_smooth_edges ( void* aux =0 )  ;
		virtual int get_number_of_edges ( void* aux =0 ) ;
		virtual int get_number_of_faces ( void* aux =0 ) ;
		virtual void get_edge ( int i , int& v0 , int& v1 , void* aux =0 )  ; // 27034
		virtual void get_face ( int i , int& v0 , int& v1 , int& v2 , int& v3 , void* aux =0 )  ; // 27034
		virtual void set_anchor_point ( int i , const sx::vec<float,3>& p , void* aux =0 )  ; // 27107
		virtual sx::vec<float,3> get_anchor_point ( int i , void* aux =0 )  ; // 27107
		virtual int get_number_of_active_control_points ( void* aux =0 )  ; //27121
		virtual int get_first_active_control_point ( void* aux =0 )  ; // 27121
		virtual int get_next_active_control_point ( void* aux =0 )  ; // 27121
		virtual void select_all_control_points_obsolete ( void* aux =0 )  ; // 27121 obsoleted 32297
		virtual void unselect_all_control_points_obsolete ( void* aux =0 )  ; // 27121 obsoleted 32297
		virtual void select_control_point_obsolete ( int i , void* aux =0 )  ; // 27121 obsoleted 32297
		virtual void remove_control_point ( int i , void* aux =0 )  ; // 27122
		virtual void set_round ( float round , void* aux =0 )  ; //28009
		virtual float get_round ( void* aux =0 )  ; //28009
		virtual int get_face_n ( int i , int* v , sx::vec<float,3>* normals =0 )  ; // 28018
		virtual polygon_mesh_class& get_polygon_mesh (void* aux = 0);
		virtual void set_show_edges ( bool b , void* aux =0 )  ; //29100
		virtual bool get_show_edges ( void* aux =0 )  ; //29100
		virtual void append_face ( int n , const int* v , void* aux =0 )  ; //29119
		virtual void subdivide ( int level , void* aux =0 )  ; //29125
		virtual void unsubdivide ( void* aux =0 )  ; //29125
		virtual void remove_edge ( int i , void* aux =0 )  ; //31000
		virtual void remove_face ( int i , void* aux =0 )  ; //31000
		virtual int get_uv_n ( int i , sx::vec<float,2>* uv , void* aux =0 )  ; //31063
		virtual image_interface* get_texture_image_interface ( void* aux =0 )  ; image_interface* get_texture ( void* aux =0 )  { return get_texture_image_interface(aux ) ; } //31063 33042:changed to get_texture_image_interface
		virtual void set_uv ( int i , int j , const sx::vec<float,2>& uv , void* aux =0 )  ; //31102
		virtual sx::vec<float,2> get_uv ( int i , int j , void* aux =0 )  ; //31102
		virtual bool has_uv ( int i , void* aux =0 )  ; //31102
		virtual void clear_uv_obsolete ( int i , void* aux =0 ) { } //31102 37042 obsoleted
		virtual void make_edge ( int i0 , int i1 , void* aux =0 )  ; //32052
		virtual void unselect_control_point_obsolete ( int i , void* aux =0 )  ; //32052 obsolete 32297
		virtual void begin_removing_control_points ( void* aux =0 )  ; //32047
		virtual void end_removing_control_points ( void* aux =0 )  ; //32047
		virtual void begin_selecting_control_points ( void* aux =0 )  ; //32047
		virtual void end_selecting_control_points ( void* aux =0 )  ; //32047
		virtual void begin_removing_faces ( void* aux =0 )  ; //32047
		virtual void end_removing_faces ( void* aux =0 )  ; //32047
		virtual void begin_removing_edges ( void* aux =0 )  ; //32047
		virtual void end_removing_edges ( void* aux =0 )  ; //32047
		virtual bool is_control_point_selected_obsolete ( int i , void* aux =0 )  ; //32067 obsolete 32297
		virtual void setup_normal ( void* aux =0 )  ; //33023
		virtual void set_parameter_uv ( int i , int j , const sx::vec<float,2>& uv , void* aux =0 )  ; //33054
		virtual sx::vec<float,2> get_parameter_uv ( int i , int j , void* aux =0 )  ; //33054
		virtual void set_distance_uv ( int i , int j , const sx::vec<float,2>& uv , void* aux =0 )  ; //33054
		virtual sx::vec<float,2> get_distance_uv ( int i , int j , void* aux =0 )  ; //33054
		virtual int polygon_mesh_interface_test_1 ( void* aux =0 )  { return 1; }
		virtual bool adjust_face_direction ( void* aux =0 )  ; //35003
		virtual bool has_consistent_faces ( void* aux =0 )  ; //35003
		virtual vertex_attribute_interface* get_vertex_attribute_interface_obsolete ( int i , int j , void* aux =0 )  ; //35015
		virtual void set_vertex_attribute_obsolete ( int i , int j , vertex_attribute_interface* vertex_attribute , void* aux =0 )  ; //35015
		virtual void cleanup_redundant_vertices ( void* aux =0 ) ; //36049
		virtual void setup_winged_edge ( void* aux =0 ) ; //36076
		virtual void clean_winged_edge ( void* aux =0 ) ; //36076
		virtual int eccwfv ( int f , int v , bool check , void* aux =0 ) ; //36076
		virtual int ecwfv ( int f , int v , bool check , void* aux =0 ) ; //36076
		virtual int fccwev ( int e , int v , bool check , void* aux =0 ) ; //36076
		virtual int fcwev ( int e , int v , bool check , void* aux =0 ) ; //36076
		virtual void setup_plane_equation ( void* aux =0 ) ; //36076
		virtual sx::vec<float,4> get_plane_equation ( int f , void* aux =0 ) ; //36076
		
		virtual int get_number_of_uv_layers (void* aux = 0) const; // 450090
		virtual void clear_uv_layers (void* aux = 0); // 450090
		virtual int append_uv_layer (void* aux = 0); // 450090
		virtual void remove_uv_layer (const int uv_layer_index, void* aux  = 0); // 450090
		
		virtual void clear_face_group (void* aux = 0);  // 450090
		virtual int get_number_of_face_groups (void* aux = 0); // 450090 
		virtual bool set_face_group_index (const int face_index, const int face_group_index, void* aux = 0); // 450090
		virtual int get_face_group_index (const int face_index, void* aux = 0); // 450090
		virtual void *get_face_group (const int face_index, void* aux = 0); // 450090
		virtual void *get_face_group_surface (const int face_group_index, void* aux = 0); // 450090
 		virtual int append_face_group (void* aux = 0); // 450101
 		virtual bool set_face_group_surface (const int face_group_index, void *master_surface_param, void* aux = 0); // 450101
 		virtual bool remove_face_group (const int face_group_index, void* aux = 0); // 450101
 
		virtual int polygon_mesh_interface_dummy0(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy1(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy2(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy3(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy4(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy5(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy6(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy7(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy8(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy9(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy10(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy11(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy12(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy13(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy14(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy15(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy16(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy17(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy18(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy19(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy20(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy21(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy22(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy23(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy24(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy25(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy26(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy27(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy28(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy29(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy30(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy31(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy32(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy33(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy34(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy35(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy36(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy37(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy38(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy39(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy40(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy41(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy42(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy43(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy44(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy45(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy46(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy47(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy48(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy49(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy50(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy51(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy52(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy53(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy54(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy55(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy56(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy57(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy58(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy59(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy60(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy61(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy62(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy63(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy64(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy65(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy66(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy67(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy68(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy69(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy70(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy71(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy72(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy73(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy74(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy75(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy76(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy77(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy78(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy79(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy80(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy81(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy82(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy83(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy84(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy85(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy86(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy87(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy88(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy89(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy90(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy91(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy92(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy93(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy94(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy95(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy96(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy97(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy98(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy99(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy100(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy101(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy102(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy103(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy104(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy105(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy106(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy107(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy108(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy109(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy110(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy111(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy112(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy113(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy114(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy115(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy116(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy117(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy118(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
		virtual int polygon_mesh_interface_dummy119(void *) { SXASSERT(false); throw "invalid interface polygon_mesh_interface"; return 0; }
	};

	class disk_interface : public shape_interface {
	public:
		virtual bool is_control_point_selected ( int i , void* aux =0 ) ;

		virtual void set_fill ( bool b , void* aux =0 )  ;
		virtual bool get_fill ( void* aux =0 )  ;
		virtual void set_from ( float f , void* aux =0 )  ;
		virtual float get_from ( void* aux =0 )  ;
		virtual void set_to ( float f , void* aux =0 )  ;
		virtual float get_to ( void* aux =0 )  ;
		virtual void set_center ( const sx::vec<float,3>& v , void* aux =0 ) ;
		virtual sx::vec<float,3> get_center ( void* aux =0 )  ;
		virtual void set_radius ( const sx::vec<float,2>& v , void* aux =0 ) ;
		virtual sx::vec<float,2> get_radius ( void* aux =0 )  ;
		virtual mat4 get_matrix ( void* aux =0 ) ;
		virtual void set_matrix ( const mat4& t , void* aux =0 ) ;
		virtual disk_class& get_disk (void* aux = 0);
		virtual int disk_interface_test_1 ( void* aux =0 )  { return 1; }
		
		virtual int disk_interface_dummy0(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy1(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy2(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy3(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy4(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy5(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy6(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy7(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy8(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy9(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy10(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy11(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy12(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy13(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy14(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy15(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy16(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy17(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy18(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy19(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy20(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy21(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy22(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy23(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy24(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy25(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy26(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy27(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy28(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy29(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy30(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy31(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy32(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy33(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy34(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy35(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy36(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy37(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy38(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy39(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy40(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy41(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy42(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy43(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy44(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy45(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy46(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy47(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy48(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy49(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy50(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy51(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy52(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy53(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy54(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy55(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy56(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy57(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy58(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy59(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy60(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy61(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy62(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy63(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy64(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy65(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy66(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy67(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy68(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy69(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy70(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy71(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy72(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy73(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy74(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy75(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy76(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy77(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy78(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy79(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy80(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy81(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy82(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy83(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy84(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy85(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy86(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy87(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy88(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy89(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy90(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy91(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy92(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy93(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy94(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy95(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy96(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy97(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy98(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy99(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy100(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy101(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy102(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy103(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy104(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy105(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy106(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy107(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy108(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy109(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy110(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy111(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy112(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy113(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy114(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy115(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy116(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy117(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy118(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy119(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy120(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy121(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy122(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy123(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy124(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy125(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy126(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy127(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy128(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy129(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy130(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy131(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy132(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy133(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy134(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy135(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy136(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy137(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy138(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy139(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy140(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy141(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy142(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy143(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy144(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy145(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy146(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy147(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy148(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy149(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy150(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy151(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy152(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy153(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy154(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy155(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy156(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy157(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy158(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy159(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy160(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy161(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy162(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy163(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy164(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy165(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy166(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy167(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy168(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy169(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy170(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy171(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy172(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy173(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy174(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy175(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy176(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy177(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy178(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy179(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy180(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy181(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy182(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy183(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy184(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
		virtual int disk_interface_dummy185(void *) { SXASSERT(false); throw "invalid interface disk_interface"; return 0; }
	};

	class sphere_interface : public shape_interface {
	public:
		virtual bool is_control_point_selected ( int i , void* aux =0 ) ;

		virtual void set_center ( const sx::vec<float,3>& v , void* aux =0 ) ;
		virtual sx::vec<float,3> get_center ( void* aux =0 ) ;
		virtual void set_radius ( const sx::vec<float,3>& v , void* aux =0 ) ;
		virtual sx::vec<float,3> get_radius ( void* aux =0 ) ;
		virtual mat4 get_matrix ( void* aux =0 ) ;
		virtual void set_matrix ( const mat4& t , void* aux =0 ) ;
		virtual sphere_class& get_sphere (void* aux = 0);
		virtual int sphere_interface_test_1 ( void* aux =0 )  { return 1; }
		
		virtual int sphere_interface_dummy0(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy1(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy2(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy3(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy4(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy5(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy6(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy7(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy8(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy9(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy10(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy11(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy12(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy13(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy14(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy15(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy16(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy17(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy18(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy19(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy20(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy21(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy22(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy23(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy24(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy25(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy26(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy27(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy28(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy29(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy30(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy31(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy32(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy33(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy34(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy35(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy36(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy37(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy38(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy39(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy40(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy41(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy42(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy43(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy44(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy45(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy46(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy47(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy48(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy49(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy50(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy51(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy52(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy53(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy54(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy55(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy56(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy57(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy58(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy59(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy60(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy61(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy62(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy63(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy64(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy65(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy66(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy67(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy68(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy69(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy70(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy71(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy72(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy73(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy74(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy75(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy76(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy77(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy78(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy79(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy80(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy81(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy82(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy83(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy84(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy85(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy86(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy87(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy88(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy89(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy90(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy91(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy92(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy93(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy94(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy95(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy96(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy97(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy98(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy99(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy100(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy101(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy102(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy103(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy104(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy105(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy106(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy107(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy108(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy109(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy110(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy111(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy112(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy113(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy114(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy115(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy116(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy117(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy118(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy119(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy120(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy121(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy122(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy123(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy124(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy125(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy126(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy127(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy128(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy129(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy130(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy131(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy132(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy133(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy134(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy135(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy136(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy137(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy138(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy139(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy140(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy141(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy142(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy143(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy144(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy145(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy146(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy147(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy148(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy149(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy150(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy151(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy152(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy153(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy154(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy155(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy156(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy157(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy158(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy159(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy160(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy161(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy162(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy163(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy164(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy165(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy166(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy167(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy168(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy169(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy170(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy171(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy172(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy173(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy174(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy175(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy176(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy177(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy178(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy179(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy180(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy181(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy182(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy183(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy184(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy185(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy186(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy187(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy188(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy189(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy190(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
		virtual int sphere_interface_dummy191(void *) { SXASSERT(false); throw "invalid interface sphere_interface"; return 0; }
	};

	class light_interface : public shape_interface {
	public:
		virtual bool is_control_point_selected ( int i , void* aux =0 ) ;

		virtual void set_intensity ( float f , void* aux =0 )  ; //
		virtual float get_intensity ( void* aux =0 )  ;
		virtual void set_spotlight ( bool b , void* aux =0 )  ; //
		virtual bool get_spotlight ( void* aux =0 )  ;
		virtual void set_square ( bool b , void* aux =0 )  ; //
		virtual bool get_square ( void* aux =0 )  ;
		virtual void set_angle ( float f , void* aux =0 )  ; //
		virtual float get_angle ( void* aux =0 )  ;
		virtual void set_softness ( float f , void* aux =0 )  ; //
		virtual float get_softness ( void* aux =0 )  ;
		virtual void set_shadow ( float f , void* aux =0 )  ; //
		virtual float get_shadow ( void* aux =0 )  ;
		virtual void set_shadow_softness ( float f , void* aux =0 )  ; //
		virtual float get_shadow_softness ( void* aux =0 )  ;
		virtual void set_direction ( const sx::vec<float,3>& v , void* aux =0 )  ; //
		virtual sx::vec<float,3> get_direction ( void* aux =0 )  ;
		virtual void set_specular ( float f , void* aux =0 )  ; // 2.70
		virtual float get_specular ( void* aux =0 )  ; // 2.70
		virtual void set_diffuse ( float f , void* aux =0 )  ; // 2.70
		virtual float get_diffuse ( void* aux =0 )  ; // 2.70
		virtual void set_position ( const sx::vec<float,3>& v , void* aux =0 )  ; // 28013
		virtual sx::vec<float,3> get_position ( void* aux =0 )  ; // 28013
		virtual light_class& get_light (void* aux = 0);
		virtual int light_interface_test_1 ( void* aux =0 )  { return 1; }
		virtual void set_center ( const sx::vec<float,3>& v , void* aux =0 )  ;
		virtual sx::vec<float,3> get_center ( void* aux =0 )  ;
		virtual void set_lumen ( bool b , void* aux =0 )  ;	// 35038
		virtual bool get_lumen ( void* aux =0 )  ;			// 35038
		virtual void load_ies ( const char* path , void* aux =0 )  ; //36013
		
		virtual int light_interface_dummy0(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy1(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy2(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy3(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy4(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy5(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy6(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy7(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy8(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy9(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy10(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy11(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy12(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy13(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy14(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy15(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy16(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy17(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy18(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy19(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy20(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy21(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy22(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy23(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy24(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy25(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy26(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy27(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy28(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy29(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy30(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy31(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy32(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy33(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy34(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy35(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy36(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy37(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy38(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy39(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy40(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy41(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy42(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy43(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy44(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy45(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy46(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy47(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy48(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy49(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy50(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy51(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy52(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy53(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy54(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy55(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy56(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy57(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy58(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy59(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy60(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy61(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy62(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy63(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy64(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy65(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy66(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy67(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy68(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy69(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy70(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy71(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy72(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy73(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy74(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy75(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy76(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy77(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy78(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy79(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy80(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy81(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy82(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy83(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy84(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy85(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy86(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy87(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy88(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy89(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy90(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy91(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy92(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy93(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy94(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy95(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy96(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy97(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy98(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy99(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy100(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy101(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy102(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy103(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy104(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy105(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy106(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy107(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy108(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy109(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy110(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy111(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy112(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy113(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy114(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy115(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy116(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy117(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy118(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy119(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy120(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy121(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy122(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy123(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy124(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy125(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy126(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy127(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy128(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy129(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy130(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy131(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy132(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy133(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy134(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy135(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy136(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy137(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy138(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy139(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy140(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy141(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy142(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy143(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy144(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy145(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy146(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy147(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy148(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy149(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy150(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy151(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy152(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy153(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy154(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy155(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy156(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy157(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy158(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy159(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy160(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy161(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy162(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy163(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy164(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy165(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy166(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy167(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy168(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy169(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
		virtual int light_interface_dummy170(void *) { SXASSERT(false); throw "invalid interface light_interface"; return 0; }
	};
}
