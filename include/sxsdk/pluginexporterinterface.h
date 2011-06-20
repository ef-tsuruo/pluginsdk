#pragma once

namespace sxsdk {
	class plugin_exporter_interface : public shade_interface {
	public:
	virtual sxsdk::scene_interface* get_scene_interface (void * = 0) const = 0; // -1
	virtual void do_export (void* aux = 0) = 0; // 0
	virtual sxsdk::stream_interface* get_stream_interface (void* aux = 0) = 0; // 1
	virtual text_stream_interface* get_text_stream_interface (void* aux = 0) = 0; // 2
	virtual shape_interface* get_current_shape_interface (void* aux = 0) = 0; // 3
	virtual sxsdk::mat4 get_transformation (void* aux = 0) = 0; // 4
	virtual bool get_all_objects (void* aux = 0) = 0; // 5
	virtual shade_interface* get_shade_interface (void* aux = 0) = 0; // 6
	virtual void yield (void* aux = 0) = 0; // 7
	virtual bool get_flip_face_shade (void* aux = 0) = 0; // 8
	virtual int get_fnum (void* aux = 0) = 0; // 9
	virtual bool get_binary (void* aux = 0) = 0; // 10
	virtual const char* get_file_spec_obsolete (void* aux = 0) = 0; // 11
	virtual void delete_file (void* aux = 0) = 0; // 12
	virtual sxsdk::shape_class* get_current_shape (void* aux = 0) = 0; // 13
	virtual bool get_flip_face (void* aux = 0) = 0; // 14
	virtual int get_subdivision_level (void* aux = 0) = 0; // 15
	virtual int plugin_exporter_interface_dummy16(void *) { assert(false); throw "invalid interface plugin_exporter_interface"; return 0; } // 16
	virtual bool get_render (void* aux = 0) = 0; // 17
	virtual proxy_shape_class* get_current_proxy_shape (void* aux = 0) = 0; // 18
	virtual proxy_shape_class* get_root_proxy_shape (void* aux = 0) = 0; // 19
	virtual const char* get_file_path (void* aux = 0) = 0; // 20
	virtual bool get_active (void * = 0) const = 0; // 21
	virtual int get_rendering_flag (void * = 0) const = 0; // 22
	};
}
