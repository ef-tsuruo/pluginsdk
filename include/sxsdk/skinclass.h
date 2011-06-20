#pragma once

namespace sxsdk {
	class skin_bind_class {
	public:
		virtual ~skin_bind_class ();
		VTABLE_PADDING
	virtual sxsdk::shape_class* get_shape (void * = 0) const = 0; // 0
	virtual skin_bind_class &set_shape (sxsdk::shape_class* shape_param, void * = 0) = 0; // 1
	virtual float get_weight (void * = 0) const = 0; // 2
	virtual skin_bind_class &set_weight (float weight_param, void * = 0) = 0; // 3
	};

	class skin_class {
	public:
		virtual ~skin_class ();
		VTABLE_PADDING
	virtual sxsdk::mat4 get_skin_world_matrix (void * = 0) const = 0; // 0
	virtual int get_number_of_binds (void * = 0) const = 0; // 1
	virtual skin_bind_class& get_bind (int i, void* aux = 0) = 0; // 2
	virtual const skin_bind_class& get_bind (int i, void* aux = 0) const = 0; // 3
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 4
	virtual void append_bind (void* aux = 0) = 0; // 5
	virtual void remove_bind (int i, void* aux = 0) = 0; // 6
	virtual sxsdk::mat4 get_sequence_skin_world_matrix (float sequence_value, void* aux = 0) const = 0; // 7
	};
}
