#pragma once


namespace sxsdk {
	
	class expression_interface : public unknown_interface {
	public:
enum expression_value_types_enum {	///< \en blah \enden \ja 値の種類 \endja 
	type_unknown		= 0,	///< \en  \enden \ja 未定義 \endja 
	type_real		= 1,	///< \en  \enden \ja 実数値 \endja 
	type_string		= 2,	///< \en  \enden \ja 文字列 \endja 
}; 
	virtual int execute (const char* scripts, void* aux = 0) = 0; // 0
	virtual int get_number_of_lines (void* aux = 0) = 0; // 1
	virtual const char * get_expression (int line, void* aux = 0) = 0; // 2
	virtual const char * json_type_result (void* aux = 0) = 0; // 3
	virtual const char * json_type_value (void* aux = 0) = 0; // 4
	virtual int get_result (int line, void* aux = 0) = 0; // 5
	virtual bool has_variable (const char* variable, void* aux = 0) = 0; // 6
	virtual int get_type (const char* variable, void* aux = 0) = 0; // 7
	virtual float get_realnumber (const char* variable, void* aux = 0) = 0; // 8
	virtual const char* get_string (const char* variable, void* aux = 0) = 0; // 9
	virtual int get_number_of_variable (void* aux = 0) = 0; // 10
	virtual const char* get_variable (int number, void* aux = 0) = 0; // 11
	};
}
