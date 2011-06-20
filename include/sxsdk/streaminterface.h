#pragma once

namespace sxsdk {
	class stream_interface : public shade_interface {
	public:
	virtual sxsdk::scene_interface* get_scene_interface (void * = 0) const = 0; // -1
	#if SXWINDOWS 
	virtual void set_swap_endian (bool b, void* aux = 0) = 0; // -1
	virtual bool get_swap_endian (void* aux = 0) = 0; // -1
	virtual stream_interface& read_float (float& f, void* aux = 0) = 0; // -1
	virtual stream_interface& read_int (int& i, void* aux = 0) = 0; // -1
	virtual stream_interface& read_short (short& i, void* aux = 0) = 0; // -1
	virtual stream_interface& read_char (char& c, void* aux = 0) = 0; // -1
	virtual stream_interface& read (int n, void* buff, void* aux = 0) = 0; // -1
	virtual stream_interface& skip (int n, void* aux = 0) = 0; // -1
	virtual stream_interface& write_float (const float& f, void* aux = 0) = 0; // -1
	virtual stream_interface& write_int (const int& i, void* aux = 0) = 0; // -1
	virtual stream_interface& write_char (const char& c, void* aux = 0) = 0; // -1
	virtual stream_interface& write_str (const char* s, void* aux = 0) = 0; // -1
	virtual stream_interface& write (int n, const void* buff, void* aux = 0) = 0; // -1
	virtual stream_interface& set_pointer (int n, void* aux = 0) = 0; // -1
	virtual stream_interface& set_size (int n, void* aux = 0) = 0; // -1
	virtual int get_pointer (void* aux = 0) const = 0; // -1
	virtual int get_size (void* aux = 0) const = 0; // -1
	virtual stream_interface& operator>> (char& c) = 0; // -1
	virtual stream_interface& operator>> (int& i) = 0; // -1
	virtual stream_interface& operator>> (float& f) = 0; // -1
	virtual stream_interface& operator<< (const char* s) = 0; // -1
	virtual stream_interface& operator<< (const char& c) = 0; // -1
	virtual stream_interface& operator<< (const int& i) = 0; // -1
	virtual stream_interface& operator<< (const float& f) = 0; // -1
	virtual const char* get_name ( 
				 ) = 0; // -1
	virtual bool eof ( 
				 ) = 0; // -1
	#else 
	virtual void set_swap_endian (bool b, void* aux = 0) = 0; // -1
	virtual bool get_swap_endian (void* aux = 0) = 0; // -1
	virtual stream_interface& read (int n, void* buff, void* aux = 0) = 0; // -1
	virtual stream_interface& skip (int n, void* aux = 0) = 0; // -1
	virtual stream_interface& write (int n, const void* buff, void* aux = 0) = 0; // -1
	virtual stream_interface& set_pointer (int n, void* aux = 0) = 0; // -1
	virtual stream_interface& set_size (int n, void* aux = 0) = 0; // -1
	virtual int get_pointer (void* aux = 0) const = 0; // -1
	virtual int get_size (void* aux = 0) const = 0; // -1
	virtual stream_interface& read_char (char& c, void* aux = 0) = 0; // -1
	virtual stream_interface& read_short (short& i, void* aux = 0) = 0; // -1
	virtual stream_interface& read_int (int& i, void* aux = 0) = 0; // -1
	virtual stream_interface& read_float (float& f, void* aux = 0) = 0; // -1
	virtual stream_interface& operator>> (char& c) = 0; // -1
	virtual stream_interface& operator>> (int& i) = 0; // -1
	virtual stream_interface& operator>> (float& f) = 0; // -1
	virtual stream_interface& write_str (const char* s, void* aux = 0) = 0; // -1
	virtual stream_interface& write_char (const char& c, void* aux = 0) = 0; // -1
	virtual stream_interface& write_int (const int& i, void* aux = 0) = 0; // -1
	virtual stream_interface& write_float (const float& f, void* aux = 0) = 0; // -1
	virtual stream_interface& operator<< (const char* s) = 0; // -1
	virtual stream_interface& operator<< (const char& c) = 0; // -1
	virtual stream_interface& operator<< (const int& i) = 0; // -1
	virtual stream_interface& operator<< (const float& f) = 0; // -1
	virtual const char* get_name () = 0; // -1
	virtual bool eof () = 0; // -1
	#endif 
	virtual const char* get_label (void * = 0) const = 0; // 0
	virtual stream_interface &set_label (const char* label_param, void * = 0) = 0; // 1
	virtual const char* get_file_path (void * = 0) const = 0; // 2
const char* get_file_spec (void* aux = 0) { return get_file_path(); }
	virtual int stream_interface_dummy3(void *) { assert(false); throw "invalid interface stream_interface"; return 0; } // 3
	virtual stream_interface& read_vec3 (sxsdk::vec3& v, void* aux = 0) = 0; // 4
	virtual stream_interface& write_vec3 ( const sxsdk::vec3& v, void* aux = 0) = 0; // 5
	virtual void enter_critical_section (void* aux = 0) = 0; // 6
	virtual void leave_critical_section (void* aux = 0) = 0; // 7
	virtual stream_interface& read_shape (sxsdk::scene_interface* scene, sxsdk::shape_class*& shape, void* aux = 0) = 0; // 8
	virtual stream_interface& write_shape (sxsdk::shape_class* shape, void* aux = 0) = 0; // 9
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 10
	virtual stream_interface& write_short (const short& i, void* aux = 0) = 0; // 11
stream_interface& read (char& i) { return read_char(i); }
stream_interface& read (short& i) { return read_short(i); }
stream_interface& read (int & i) { return read_int(i); }
stream_interface& read (float & f) { return read_float(f); }
stream_interface& write (const char* s) { return write_str(s); }
stream_interface& write (const char & c) { return write_char(c); }
stream_interface& write (const short & i) { return write_short(i); }
stream_interface& write (const int & i) { return write_int(i); }
stream_interface& write (const float & f) { return write_float(f); }
	};
}
