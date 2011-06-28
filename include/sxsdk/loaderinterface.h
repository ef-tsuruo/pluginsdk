#pragma once

namespace sxsdk {
	class loader_info_interface;

	class loader_interface : public unknown_interface {
	public:
	virtual void do_load (sxsdk::loader_info_interface* loader_info, void* aux = 0) { }  // 0
	virtual bool skip_load_objects ( void* aux =0 ) { return false; }  // 1
	virtual void start ( void* aux =0 ) { }  // 2
	virtual void finish ( void* aux =0 ) { }  // 3
	virtual void begin ( void* aux =0 ) { }  // 4
	virtual void end ( void* aux =0 ) { }  // 5
	virtual void head ( void* aux =0 ) { }  // 6
	virtual void tail ( void* aux =0 ) { }  // 7
	virtual bool must_skip ( void* aux =0 ) { return false; }  // 8
	virtual void set_transformation (const sx::mat<float,4>& t, void* aux = 0) { }  // 9
	virtual void clear_transformation ( void* aux =0 ) { }  // 10
	virtual bool can_accept_polyline ( void* aux =0 ) { return false; }  // 11
	virtual bool can_accept_polygon ( void* aux =0 ) { return false; }  // 12
	virtual bool can_accept_sphere ( void* aux =0 ) { return false; }  // 13
	virtual bool can_accept_bezier_surface ( void* aux =0 ) { return false; }  // 14
	virtual bool can_accept_polymesh ( void* aux =0 ) { return false; }  // 15
	virtual bool can_accept_disk ( void* aux =0 ) { return false; }  // 16
	virtual bool can_accept_closed_mesh ( void* aux =0 ) { return false; }  // 17
	virtual bool can_accept_meshes ( void* aux =0 ) { return true; }  // 18
	virtual bool can_accept_link ( void* aux =0 ) { return false; }  // 19
	virtual bool can_accept_linear_light ( void* aux =0 ) { return false; }  // 20
	virtual bool can_accept_area_light ( void* aux =0 ) { return false; }  // 21
	virtual bool can_accept_light ( void* aux =0 ) { return false; }  // 22
	virtual bool can_accept_replicator ( void* aux =0 ) { return false; }  // 23
	virtual bool can_accept_switch ( void* aux =0 ) { return false; }  // 24
	virtual bool must_triangulate_polymesh ( void* aux =0 ) { return false; }  // 25
	virtual bool must_divide_polymesh ( void* aux =0 ) { return false; }  // 26
	virtual int get_max_vertices_per_face ( void* aux =0 ) { return -1; }  // 27
	virtual void do_polyline (sxsdk::points_interface* points, void* aux = 0) { }  // 28
	virtual void do_polygon (int n, sxsdk::points_interface** c, void* aux = 0) { }  // 29
	virtual void do_meshes (sxsdk::meshes_interface* m, void* aux = 0) { }  // 30
	virtual void do_sphere (const sx::mat<float,4>& t, void* aux = 0) { }  // 31
	virtual void do_disk (const sx::mat<float,4>& t, float t0, float t1, bool filled, void* aux = 0) { }  // 32
	virtual void do_bezier_surface (sxsdk::mesh_interface* m, void* aux = 0) { }  // 33
	virtual void begin_polymesh ( void* aux =0 ) { }  // 34
	virtual void begin_polymesh_vertex (int n, void* aux = 0) { }  // 35
	virtual void polymesh_vertex (int i, const sxsdk::vec3& v, void* aux = 0) { }  // 36
	virtual void end_polymesh_vertex ( void* aux =0 ) { }  // 37
	virtual void begin_polymesh_face (int n, void* aux = 0) { }  // 38
	virtual void polymesh_face (int n_list, const int list[], const sxsdk::vec3* normals, const sxsdk::vec4* plane_equation, const sxsdk::vec4* uvs, void* aux = 0) { }  // 39
	virtual void end_polymesh_face ( void* aux =0 ) { }  // 40
	virtual void end_polymesh ( void* aux =0 ) { }  // 41
	virtual void do_link (sxsdk::part_class& link, void* aux = 0) { }  // 42
	virtual void do_linear_light (sxsdk::points_interface* points, bool closed, void* aux = 0) { }  // 43
	virtual void do_area_light (sxsdk::points_interface* points, float area, void* aux = 0) { }  // 44
	virtual void do_light (sxsdk::enums::light_distribution_type points, const sxsdk::vec3* color, const sxsdk::vec3* position, const sxsdk::vec3* direction, float angle, float softness, void* aux = 0) { }  // 45
	virtual void do_replicator (sxsdk::part_class& replicator, sxsdk::shape_class& shape, const sxsdk::mat4* trans, void* aux = 0) { }  // 46
	virtual void do_switch (sxsdk::part_class& switch_joint, void* aux = 0) { }  // 47
	virtual bool can_accept_mirror ( void* aux =0 ) { return false; }  // 48
	virtual void do_mirror (sxsdk::shape_class& shape, void* aux = 0) { }  // 49
	};
}

