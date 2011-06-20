#pragma once

namespace sxsdk {
	class dll_interface : public shade_interface {
	public:
	virtual void get_info (shade_plugin_info& info, shade_interface* shade, void * aux = 0) = 0; // 0
	virtual int get_text_encoding (shade_interface* shade, void * aux = 0) = 0; // 1
	virtual void load (void * aux = 0) = 0; // 2
	virtual void unload (void * aux = 0) = 0; // 3
	virtual void push (void * aux = 0) = 0; // 4
	virtual void pop (void * aux = 0) = 0; // 5
	virtual int has_interface (const IID& iid, shade_interface* shade) = 0; // 6
	virtual const char* get_name (const IID& iid, int i, shade_interface* shade, void * aux = 0) = 0; // 7
	virtual int get_interface_version (void * aux = 0) = 0; // 8
	virtual int get_id (const IID& iid, int i, void * aux = 0) = 0; // 9
	virtual bool is_resident (const IID& iid, int i, void * aux = 0) = 0; // 10
	virtual bool has_separate_interfaces (void * aux = 0) = 0; // 11
	virtual bool is_embedded (void * aux = 0) = 0; // 12
	virtual const char* get_file_name (void * aux = 0) = 0; // 13
	virtual bool is_entered (const IID& iid, int i, void * aux = 0) = 0; // 14
	virtual sx::uuid_class get_uuid (const IID& iid, int i, void * aux = 0) = 0; // 15
	};
}
