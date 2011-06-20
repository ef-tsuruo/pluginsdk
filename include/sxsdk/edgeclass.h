#pragma once

namespace sxsdk {
	class edge_class {
	public:
		virtual ~edge_class () { }
		VTABLE_PADDING
	virtual int get_v0 (void * = 0) const = 0; // 0
	virtual edge_class &set_v0 (int v0_param, void * = 0) = 0; // 1
	virtual int get_v1 (void * = 0) const = 0; // 2
	virtual edge_class &set_v1 (int v1_param, void * = 0) = 0; // 3
	virtual void remove (void* aux = 0) = 0; // 4
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 5
	virtual edge_class &set_active (bool active_param, void * = 0) = 0; // 6
	virtual bool get_active (void * = 0) const = 0; // 7
	virtual edge_class &set_active_order (int active_order_param, void * = 0) = 0; // 8
	virtual int get_active_order (void * = 0) const = 0; // 9
	};
}
