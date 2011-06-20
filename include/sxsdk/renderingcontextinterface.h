#pragma once

namespace sxsdk {
	class rendering_context_interface : public shade_interface {
	public:
	virtual sxsdk::scene_interface* get_scene_interface (void * = 0) const = 0; // -1
	virtual float get_zoom (void * = 0) const = 0; // 0
	virtual sx::vec<int,2> get_whole_image_size (void * = 0) const = 0; // 1
	virtual sxsdk::image_interface* get_image_interface (void * = 0) const = 0; // 2
	virtual sxsdk::mat4 get_world_to_device_matrix (void * = 0) const = 0; // 3
	virtual sxsdk::mat4 get_world_to_view_matrix (void * = 0) const = 0; // 4
	virtual int get_number_of_lights (void * = 0) const = 0; // 5
	virtual rendering_light_class& get_light_compatible (int i, void* aux = 0) = 0; // 6
	virtual void convert (renderer_interface* renderer, void* aux = 0) = 0; // 7
	virtual plugin_exporter_interface& get_plugin_exporter_interface (void * = 0) const = 0; // 8
	virtual int rendering_context_interface_dummy9(void *) { assert(false); throw "invalid interface rendering_context_interface"; return 0; } // 9
	virtual sxsdk::shape_class** get_shapes_obsolete (void* aux = 0) = 0; // 10
	virtual sxsdk::mat4 get_world_to_perspective_matrix (void * = 0) const = 0; // 11
	virtual int get_current_frame (void * = 0) const = 0; // 12
	virtual void yield (void* aux = 0) = 0; // 13
	virtual void update_image (const sx::rectangle_class* area = 0) = 0; // 14
	virtual void begin_progress (const char* title, void* aux = 0) = 0; // 15
	virtual rendering_context_interface &set_progress (float progress_param, void * = 0) = 0; // 16
	virtual void end_progress (void* aux = 0) = 0; // 17
	virtual sxsdk::rgb_class correct (const sxsdk::rgb_class& color, void* aux = 0) = 0; // 18
	virtual bool is_animation (void * = 0) const = 0; // 19
	virtual void update_joint_values (void* aux = 0) = 0; // 20
	virtual shape_interface* get_current_shape_interface (void* aux = 0) = 0; // 21
	virtual sxsdk::shape_class& get_current_shape (void * = 0) const = 0; // 22
	virtual sxsdk::vec3 get_eye (void * = 0) const = 0; // 23
	virtual sxsdk::vec3 get_target (void * = 0) const = 0; // 24
	virtual bool get_sight (sxsdk::vec3& eye, sxsdk::vec3& direction, float x, float y, void* aux = 0) = 0; // 25
	virtual int get_total_blocks (void * = 0) const = 0; // 26
	virtual int rendering_context_interface_dummy27(void *) { assert(false); throw "invalid interface rendering_context_interface"; return 0; } // 27
	virtual sxsdk::mat4 get_camera_to_world_matrix (void * = 0) const = 0; // 28
	virtual bool is_partial_rendering (void * = 0) const = 0; // 29
	virtual rendering_light_class& get_light (int i, void* aux = 0) = 0; // 30
	virtual bool get_flip_face (void * = 0) const = 0; // 31
	virtual bool get_flip_face_shade (void * = 0) const = 0; // 32
	virtual sxsdk::rgb_class calculate_background_color ( const sxsdk::vec3& v, void* aux = 0) = 0; // 33
	virtual bool get_render (void * = 0) const = 0; // 34
	virtual int get_interlace (void * = 0) const = 0; // 35
	virtual proxy_shape_class& get_current_proxy_shape (void * = 0) const = 0; // 36
	virtual proxy_shape_class& get_root_proxy_shape (void * = 0) const = 0; // 37
	virtual bool get_rendering_flag ( const sxsdk::shape_class& shape, void* aux = 0) = 0; // 38
	virtual sxsdk::background_interface* get_background_interface (void * = 0) const = 0; // 39
	virtual sxsdk::camera_class& get_camera (void * = 0) const = 0; // 40
	virtual sxsdk::image_interface* get_image_layer_image_interface_obsolete (const sx::uuid_class& uuid, void* aux = 0) const = 0; // 41
	virtual sxsdk::image_layer_interface* get_image_layer_interface (const char* id_name, void* aux = 0) const = 0; // 42
	virtual sxsdk::image_layer_interface* get_custom_image_layer_interface (const sx::uuid_class& layer_uuid, const char* id_name, void* aux = 0) const = 0; // 43
	virtual int get_number_of_image_layers (int type = -1, void* aux = 0) const = 0; // 44
	virtual sxsdk::image_layer_interface* get_image_layer_interface_by_index (unsigned index, int type = -1, void* aux = 0) const = 0; // 45
	virtual bool get_active (void * = 0) const = 0; // 46
	};
}
