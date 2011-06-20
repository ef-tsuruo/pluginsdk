#pragma once

namespace model {
	class face_class;
}

namespace sxsdk {
	class face_class  {
	public:
		virtual ~face_class () { }
		VTABLE_PADDING
	virtual int get_number_of_vertices (void * = 0) const = 0; // 0
	virtual vertex_class& vertex (int i, void* aux = 0) = 0; // 1
	virtual int get_vertex_indices (int list[], void * = 0) const = 0; // 2
	virtual face_class &set_vertex_indices (int n, int list[], void * = 0) = 0; // 3
	virtual bool has_uv (void * = 0) const = 0; // 4
	virtual int get_parameter_uv (sxsdk::vec2 list[], void * = 0) const = 0; // 5
	virtual face_class &set_parameter_uv (int n, sxsdk::vec2 list[], void * = 0) = 0; // 6
	virtual int get_distance_uv (sxsdk::vec2 list[], void * = 0) const = 0; // 7
	virtual face_class &set_distance_uv (int n, sxsdk::vec2 list[], void * = 0) = 0; // 8
	virtual void remove (void* aux = 0) = 0; // 9
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 10
	virtual int get_normals (sxsdk::vec3 list[], void * = 0) const = 0; // 11
	virtual face_class &set_normals (int n, sxsdk::vec3 list[], void * = 0) = 0; // 12
	virtual int get_sub_surface_index (void * = 0) const = 0; // 13
	virtual face_class &set_sub_surface_index (int sub_surface_index_param, void * = 0) = 0; // 14
	virtual face_class &set_active (bool active_param, void * = 0) = 0; // 15
	virtual bool get_active (void * = 0) const = 0; // 16
	virtual face_class &set_active_order (int active_order_param, void * = 0) = 0; // 17
	virtual int get_active_order (void * = 0) const = 0; // 18
	virtual sxsdk::vec2 get_face_uv (int uv_layer_index, int v_index, void* aux = 0) = 0; // 19
	virtual void set_face_uv (int uv_layer_index, int v_index, sxsdk::vec2 uv, void* aux = 0) = 0; // 20
	};
}
