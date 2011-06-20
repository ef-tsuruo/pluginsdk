#pragma once

namespace sxsdk {
	class meshes_interface : public shade_interface {
	public:
		class submesh_class { //31070
		public:
			const int m, n;

			explicit submesh_class (meshes_interface &meshes, int i, int j) : m(meshes(i, j).i), n(meshes(i, j).j), i(i), j(j), meshes(meshes) { }
			const meshes_element_class &operator() (int i, int j, void* aux =0) const { return meshes(this->i+i, this->j+j); }
			meshes_element_class &operator() (int i, int j, void* aux =0) { return meshes(this->i+i, this->j+j); }
			sx::vec<float,2> get_uv (int i, int j, void* aux =0) const { return meshes.get_uv(this->i+i, this->j+j); }
			bool is_interpolated () const { return meshes.is_interpolated(i, j); }
		private:
			const int i, j;
			meshes_interface &meshes;
		};
	virtual int get_m_number (void * = 0) const = 0; // -1
	virtual int get_n_number (void * = 0) const = 0; // -1
	virtual bool get_m_closed (void * = 0) const = 0; // -1
	virtual bool get_n_closed (void * = 0) const = 0; // -1
	virtual bool get_must_triangulate (void * = 0) const = 0; // -1
	virtual bool has_normal_deprecated (void * = 0) const = 0; // -1
	virtual bool is_normal_reversed (void * = 0) const = 0; // -1
	virtual meshes_element_class& operator() (int i, int j, void* aux = 0) = 0; // -1
	virtual meshes_interface* create_compact_meshes_interface (void* aux = 0) = 0; // -1
		meshes_interface* compact (void* aux = 0) { return create_compact_meshes_interface(); }
	virtual const meshes_element_class& operator() (int i, int j, void* aux = 0) const = 0; // -1
	virtual meshes_element_class& operator[] (int i) = 0; // -1
	virtual const meshes_element_class& operator[] (int i) const = 0; // -1
	virtual bool has_uv_coordinates (void * = 0) const = 0; // -1
	virtual sxsdk::vec2 get_uv_coordinates (int i, int j, void* aux = 0) = 0; // -1
	virtual bool has_uv_vectors (void * = 0) const = 0; // -1
	virtual uv_vector_class get_uv_vectors (int i, int j, void* aux = 0) = 0; // -1
	virtual sxsdk::image_interface* get_texture_image_interface (void * = 0) const = 0; // 0
	virtual sxsdk::vec2 get_uv (int i, int j, void* aux = 0) = 0; // 1
	virtual bool is_submesh (int i, int j, void* aux = 0) = 0; // 2
	virtual meshes_interface& transform (const sxsdk::mat4& t, void* aux = 0) = 0; // 3
	virtual int meshes_interface_dummy4(void *) { assert(false); throw "invalid interface meshes_interface"; return 0; } // 4
	virtual sxsdk::vec2 get_uv_distances (int i, int j, void* aux = 0) = 0; // 5
	virtual bool is_interpolated (int i, int j, void* aux = 0) = 0; // 6
	};
}
