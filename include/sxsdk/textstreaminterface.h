#pragma once

namespace sxsdk {
	class text_stream_interface : public shade_interface {
	public:
		typedef text_stream_interface& (*func_type ) (text_stream_interface&);
	virtual text_stream_interface& read_line (const char*& s, void* aux = 0) = 0; // -1
	virtual text_stream_interface& skip_line (void* aux = 0) = 0; // -1
	virtual text_stream_interface& write_eol (void* aux = 0) = 0; // -1
	virtual text_stream_interface& write_indent (void* aux = 0) = 0; // -1
	virtual text_stream_interface& write_line (const char* s, void* aux = 0) = 0; // -1
	virtual text_stream_interface& write_text (const char* s, void* aux = 0) = 0; // -1
	virtual text_stream_interface& operator<< (const char* s) = 0; // -1
	virtual text_stream_interface& operator<< (const float& f) = 0; // -1
	virtual text_stream_interface& operator<< (const int& i) = 0; // -1
	virtual text_stream_interface& operator<< (const char& c) = 0; // -1
	virtual text_stream_interface& operator<< ( const sxsdk::vec3& v) = 0; // -1
	virtual text_stream_interface& operator<< (func_type func) = 0; // -1
	virtual void increment_indent (void* aux = 0) = 0; // -1
	virtual void decrement_indent (void* aux = 0) = 0; // -1
	virtual char get_char (void* aux = 0) = 0; // -1
	virtual void put_back_char (void* aux = 0) = 0; // -1
	virtual bool is_eof_obsolete (void* aux = 0) = 0; // -1
	virtual void read (int n, void * data, void* aux = 0) = 0; // -1
	virtual void set_pointer (int n, void* aux = 0) = 0; // -1
	virtual const char* get_name ( 
				 ) = 0; // -1
	virtual bool eof ( 
				 ) = 0; // -1
	virtual const char* read_token (const char*& s, void* aux = 0) = 0; // 0
	virtual int get_indents (void * = 0) const = 0; // 1
	virtual text_stream_interface &set_indents (int indents_param, void * = 0) = 0; // 2
	virtual const char* get_indent_string (void * = 0) const = 0; // 3
	virtual text_stream_interface &set_indent_string (const char* indent_string_param, void * = 0) = 0; // 4
	virtual int text_stream_interface_dummy5(void *) { assert(false); throw "invalid interface text_stream_interface"; return 0; } // 5
	virtual bool get_convert_encoding (void * = 0) const = 0; // 6
	virtual text_stream_interface &set_convert_encoding (bool convert_encoding_param, void * = 0) = 0; // 7
text_stream_interface& operator<< (const std::string& s) { return operator<<(s.c_str()); }
	};
}

inline static sxsdk::text_stream_interface &end_line (sxsdk::text_stream_interface &stream) {
	return stream.write_eol();
}

inline static sxsdk::text_stream_interface &indent (sxsdk::text_stream_interface &stream) {
	return stream.write_indent();
}
