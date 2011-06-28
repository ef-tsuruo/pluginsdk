#pragma once

namespace sxsdk {
	class window_interface;

	class dialog_item_class : public sx::signature<0x22777F09> {
	public:
		virtual ~dialog_item_class () { }
		VTABLE_PADDING
	virtual bool get_bool (void * = 0) const = 0; // 0
	virtual dialog_item_class &set_bool (bool bool_param, void * = 0) = 0; // 1
	virtual bool get_bool_default (void * = 0) const = 0; // 2
	virtual dialog_item_class &set_bool_default (bool bool_default_param, void * = 0) = 0; // 3
	virtual unsigned get_selection (void * = 0) const = 0; // 4
	virtual dialog_item_class &set_selection (unsigned selection_param, void * = 0) = 0; // 5
	virtual unsigned get_selection_default (void * = 0) const = 0; // 6
	virtual dialog_item_class &set_selection_default (unsigned selection_default_param, void * = 0) = 0; // 7
	virtual sxsdk::rgb_class get_rgb (void * = 0) const = 0; // 8
	virtual dialog_item_class &set_rgb (const sxsdk::rgb_class &rgb_param, void * = 0) = 0; // 9
	virtual sxsdk::rgb_class get_rgb_default (void * = 0) const = 0; // 10
	virtual dialog_item_class &set_rgb_default (const sxsdk::rgb_class &rgb_default_param, void * = 0) = 0; // 11
	virtual const char* get_string (void * = 0) const = 0; // 12
	virtual dialog_item_class &set_string (const char* string_param, void * = 0) = 0; // 13
	virtual const char* get_string_default (void * = 0) const = 0; // 14
	virtual dialog_item_class &set_string_default (const char* string_default_param, void * = 0) = 0; // 15
	virtual int get_int (void * = 0) const = 0; // 16
	virtual dialog_item_class &set_int (int int_param, void * = 0) = 0; // 17
	virtual int get_int_default (void * = 0) const = 0; // 18
	virtual dialog_item_class &set_int_default (int int_default_param, void * = 0) = 0; // 19
	virtual float get_float (void * = 0) const = 0; // 20
	virtual dialog_item_class &set_float (float float_param, void * = 0) = 0; // 21
	virtual float get_float_default (void * = 0) const = 0; // 22
	virtual dialog_item_class &set_float_default (float float_default_param, void * = 0) = 0; // 23
	virtual double get_double (void * = 0) const = 0; // 24
	virtual dialog_item_class &set_double (double double_param, void * = 0) = 0; // 25
	virtual double get_double_default (void * = 0) const = 0; // 26
	virtual dialog_item_class &set_double_default (double double_default_param, void * = 0) = 0; // 27
	virtual sxsdk::vec3 get_vec3 (void * = 0) const = 0; // 28
	virtual dialog_item_class &set_vec3 (const sxsdk::vec3 &vec3_param, void * = 0) = 0; // 29
	virtual sxsdk::vec3 get_vec3_default (void * = 0) const = 0; // 30
	virtual dialog_item_class &set_vec3_default (const sxsdk::vec3 &vec3_default_param, void * = 0) = 0; // 31
	virtual const char* get_text (void * = 0) const = 0; // 32
	virtual dialog_item_class &set_text (const char* text_param, void * = 0) = 0; // 33
dialog_item_class& set_text (const std::string& s) { return set_text(s.c_str()); }
	virtual const char* get_text_default (void * = 0) const = 0; // 34
	virtual dialog_item_class &set_text_default (const char* text_default_param, void * = 0) = 0; // 35
	virtual dialog_item_class &set_range (const sxsdk::vec2 &range_param, void * = 0) = 0; // 36
	virtual dialog_item_class &set_window (sxsdk::window_interface* window_param, void * = 0) = 0; // 37
	virtual bool get_enabled (void * = 0) const = 0; // 38
	virtual dialog_item_class &set_enabled (bool enabled_param, void * = 0) = 0; // 39
	virtual int get_id (void * = 0) const = 0; // 40
	virtual dialog_item_class &set_tooltip (const char* tooltip_param, void * = 0) = 0; // 41
	virtual dialog_item_class &set_progress (float progress_param, void * = 0) = 0; // 42
	virtual dialog_item_class& append_listbox_item (const char* label, bool check, void* aux = 0) = 0; // 43
dialog_item_class& append_listbox_item (const std::string& label, bool check) { return append_listbox_item(label.c_str(), check); }
	virtual bool get_listbox_check (int i, void* aux = 0) const = 0; // 44
	virtual dialog_item_class& set_listbox_check (int i, bool check, void* aux = 0) = 0; // 45
	virtual const char* get_listbox_label (int i, void* aux = 0) const = 0; // 46
	virtual dialog_item_class& set_listbox_label (int i, const char* label, void* aux = 0) = 0; // 47
	virtual int get_number_of_listbox_items (void * = 0) const = 0; // 48
	virtual dialog_item_class& clear_listbox (void* aux = 0) = 0; // 49
	virtual dialog_item_class& insert_listbox_item (int i, const char* label, bool check, void* aux = 0) = 0; // 50
	virtual dialog_item_class& remove_listbox_item (int i, void* aux = 0) = 0; // 51
	virtual sxsdk::vec2 get_vec2 (void * = 0) const = 0; // 52
	virtual dialog_item_class &set_vec2 (const sxsdk::vec2 &vec2_param, void * = 0) = 0; // 53
	virtual sxsdk::vec2 get_vec2_default (void * = 0) const = 0; // 54
	virtual dialog_item_class &set_vec2_default (const sxsdk::vec2 &vec2_default_param, void * = 0) = 0; // 55
dialog_item_class& set_listbox_label (const std::string& label) { return set_listbox_label(label.c_str()); }
	};

	class dialog_interface : public plugin_interface {
	public:
	virtual int get_shade_version () const = 0; // -1
	virtual int get_id (void* aux = 0) = 0; // -1
	virtual const char* get_dialog_title (shade_interface* shade, void* aux = 0) = 0; // -1
	virtual unknown_interface::property_type_enum get_property_type (int index, void* aux = 0) = 0; // -1
	virtual int get_property_id (int index, void* aux = 0) = 0; // -1
	virtual const char* get_property_name (shade_interface* shade, int index, void* aux = 0) = 0; // -1
	virtual void get_bool_property_value (int index, bool& value, void* aux = 0) = 0; // -1
	virtual void set_bool_property_value (int index, bool value, void* aux = 0) = 0; // -1
	virtual void get_int_property_value (int index, int& value, void* aux = 0) = 0; // -1
	virtual void set_int_property_value (int index, int value, void* aux = 0) = 0; // -1
	virtual void get_float_property_value (int index, float& value, void* aux = 0) = 0; // -1
	virtual void set_float_property_value (int index, float value, void* aux = 0) = 0; // -1
	virtual void get_vec3_property_value (int index, sxsdk::vec3& value, void* aux = 0) = 0; // -1
	virtual void set_vec2_property_value (int index, const sxsdk::vec2& value, void* aux = 0) = 0; // -1
	virtual void set_vec3_property_value (int index, const sxsdk::vec3& value, void* aux = 0) = 0; // -1
	virtual void get_rgb_property_value (int index, sxsdk::rgb_class& value, void* aux = 0) = 0; // -1
	virtual void set_rgb_property_value (int index, const sxsdk::rgb_class& value, void* aux = 0) = 0; // -1
	virtual void get_selection_property_value (int index, unsigned& value, void* aux = 0) = 0; // -1
	virtual void set_selection_property_value (int index, unsigned value, void* aux = 0) = 0; // -1
	virtual void get_string_property_value (int index, const char*& value, void* aux = 0) = 0; // -1
	virtual void set_string_property_value (int index, const char* value, void* aux = 0) = 0; // -1
	virtual void get_double_property_value (int index, double& value, void* aux = 0) = 0; // -1
	virtual void set_double_property_value (int index, double value, void* aux = 0) = 0; // -1
	virtual const char* get_property_unit (shade_interface* shade, int index, void* aux = 0) = 0; // -1
	virtual void get_list_property_value (int index, std::vector<sx::list_item_value_class>& value, void* aux = 0) = 0; // -1
	virtual void set_list_property_value (int index, const std::vector<sx::list_item_value_class>& value, void* aux = 0) = 0; // -1
	virtual bool has_reset_button () const = 0; // -1
	virtual bool has_default_button () const = 0; // -1
	virtual const bool* get_bool_default_value (int index, void* aux = 0) = 0; // -1
	virtual const int* get_int_default_value (int index, void* aux = 0) = 0; // -1
	virtual const float* get_float_default_value (int index, void* aux = 0) = 0; // -1
	virtual void get_vec2_property_value (int index, sxsdk::vec2& value, void* aux = 0) = 0; // -1
	virtual const sxsdk::vec2* get_vec2_default_value (int index, void* aux = 0) = 0; // -1
	virtual const sxsdk::vec3* get_vec3_default_value (int index, void* aux = 0) = 0; // -1
	virtual const sxsdk::rgb_class* get_rgb_default_value (int index, void* aux = 0) = 0; // -1
	virtual const unsigned* get_selection_default_value (int index, void* aux = 0) = 0; // -1
	virtual const char* get_string_default_value (int index, void* aux = 0) = 0; // -1
	virtual const double* get_double_default_value (int index, void* aux = 0) = 0; // -1
	virtual int get_property_plugin_id (int index, void* aux = 0) = 0; // -1
	virtual int get_property_lines (int index, void* aux = 0) = 0; // -1
	virtual int get_property_flag ( int index, void* aux =0 ) = 0; // -1
	virtual sx::uuid_class get_property_plugin_uuid (int index, void* aux = 0) = 0; // -1
	virtual bool can_choose_directory ( int index, void* aux =0 ) = 0; // -1
	virtual bool can_choose_file ( int index, void* aux =0 ) = 0; // -1
	virtual bool ask (const char* s = 0, void* aux = 0) = 0; // 0
	virtual int append_item (unknown_interface::property_type_enum type, const char* name, int item_id = -1, const char* unit = 0) = 0; // 1
	virtual void set_title (const char* title, void* aux = 0) = 0; // 2
	virtual bool do_not_ask (void* aux = 0) = 0; // 3
	virtual dialog_interface &set_separator (char separator_param, void * = 0) = 0; // 4
	virtual void append_reset_button (void* aux = 0) = 0; // 5
	virtual void append_default_button (void* aux = 0) = 0; // 6
	virtual void set_bool_default_value (int index, bool value, void* aux = 0) = 0; // 7
	virtual void set_int_default_value (int index, int value, void* aux = 0) = 0; // 8
	virtual void set_float_default_value (int index, float value, void* aux = 0) = 0; // 9
	virtual void set_vec3_default_value (int index, const sxsdk::vec3& value, void* aux = 0) = 0; // 10
	virtual void set_rgb_default_value (int index, const sxsdk::rgb_class& value, void* aux = 0) = 0; // 11
	virtual void set_selection_default_value (int index, unsigned value, void* aux = 0) = 0; // 12
	virtual void set_string_default_value (int index, const char* value, void* aux = 0) = 0; // 13
	virtual void set_double_default_value (int index, double value, void* aux = 0) = 0; // 14
	virtual int dialog_interface_dummy15(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 15
	virtual void internalize (void* aux = 0) = 0; // 16
	virtual void externalize (void* aux = 0) = 0; // 17
	virtual int append_bool_deprecated (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 18
	virtual int append_selection_deprecated (const char* name, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 19
	virtual int append_int_deprecated (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 20
	virtual int append_float_deprecated (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 21
	virtual int append_vec3 (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 22
	virtual int append_rgb (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 23
	virtual int append_string_deprecated (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 24
	virtual int append_double_deprecated (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 25
	virtual int begin_group_deprecated (const char* name = 0, void* aux = 0) = 0; // 26
	virtual int end_group (void* aux = 0) = 0; // 27
	virtual int append_short_string (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 28
	virtual int append_text_deprecated (const char* name = 0, int lines = 5, sxsdk::plugin_interface* responder = 0) = 0; // 29
	virtual int begin_tab_group (const char* name, void* aux = 0) = 0; // 30
	virtual int end_tab_group (void* aux = 0) = 0; // 31
	virtual PyObject* get_value (int index, void* aux = 0) = 0; // 32
	virtual void set_value (int index, PyObject* value, void* aux = 0) = 0; // 33
	virtual void set_default_value (int index, PyObject* value, void* aux = 0) = 0; // 34
	virtual int get_dialog_id (void * = 0) const = 0; // 35
	virtual const char* get_title (void * = 0) const = 0; // 36
	virtual int begin_box (bool vertical = true, void* aux = 0) = 0; // 37
	virtual int end_box (void* aux = 0) = 0; // 38
	virtual void get_rgba_property_value (int index, rgba_class& value, void* aux = 0) = 0; // 39
	virtual void set_rgba_property_value (int index, const rgba_class& value, void* aux = 0) = 0; // 40
	virtual dialog_interface &set_responder (sxsdk::plugin_interface* responder_param, void * = 0) = 0; // 41
	virtual dialog_interface &set_resource_name (const char* resource_name_param, void * = 0) = 0; // 42
	virtual dialog_item_class& get_dialog_item (int with_id, void* aux = 0) = 0; // 43
	virtual int append_custom (sx::vec<int,2> size, sxsdk::plugin_interface* responder = 0) = 0; // 44
	virtual sx::uuid_class get_dialog_uuid (void * = 0) const = 0; // 45
	virtual int append_listbox_deprecated (int rows = 5, sxsdk::plugin_interface* responder = 0) = 0; // 46
	virtual int append_push_button_deprecated (const char* name, sxsdk::plugin_interface* responder = 0) = 0; // 47
	virtual void initialize (void* aux = 0) { } // 48
	virtual void copy_to_interface (int index, void* aux = 0) = 0; // 49
	virtual int append_secure_string (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 50
	virtual int append_secure_short_string (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 51
	virtual int append_path (const char* name = 0, bool can_choose_directory = true, bool can_choose_file = true, sxsdk::plugin_interface* responder = 0) = 0; // 52
	virtual dialog_interface &set_focus (int focus_param, void * = 0) = 0; // 53
	virtual int get_focus (void * = 0) const = 0; // 54
	virtual int append_push_button (const char* name, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 55
	virtual int append_bool (const char* name = 0, const char* unit = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 56
	virtual int append_selection (const char* name, const char* unit = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 57
	virtual int append_int (const char* name = 0, const char* unit = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 58
	virtual int append_float (const char* name = 0, const char* unit = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 59
	virtual int append_string (const char* name = 0, const char* unit = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 60
	virtual int append_double (const char* name = 0, const char* unit = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 61
	virtual int begin_group (const char* name = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 62
	virtual int append_text (const char* name = 0, int lines = 5, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 63
	virtual int append_listbox (int rows = 5, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 64
	virtual int append_radio_button (const char* name = 0, int flags = 0, sxsdk::plugin_interface* responder = 0, void* aux = 0) = 0; // 65
	virtual const char* ask_path (bool open = true, const char* extensions = 0) = 0; // 66
	virtual void set_vec2_default_value (int index, const sxsdk::vec2& value, void* aux = 0) = 0; // 67
	virtual int append_vec2 (const char* name = 0, const char* unit = 0, sxsdk::plugin_interface* responder = 0) = 0; // 68
	virtual void do_reset (void* aux = 0) { } // 69
	virtual void do_default (void* aux = 0) { } // 70
	virtual int dialog_interface_dummy71(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 71
	virtual int dialog_interface_dummy72(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 72
	virtual int dialog_interface_dummy73(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 73
	virtual int dialog_interface_dummy74(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 74
	virtual int dialog_interface_dummy75(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 75
	virtual int dialog_interface_dummy76(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 76
	virtual int dialog_interface_dummy77(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 77
	virtual int dialog_interface_dummy78(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 78
	virtual int dialog_interface_dummy79(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 79
	virtual int dialog_interface_dummy80(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 80
	virtual int dialog_interface_dummy81(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 81
	virtual int dialog_interface_dummy82(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 82
	virtual int dialog_interface_dummy83(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 83
	virtual int dialog_interface_dummy84(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 84
	virtual int dialog_interface_dummy85(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 85
	virtual int dialog_interface_dummy86(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 86
	virtual int dialog_interface_dummy87(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 87
	virtual int dialog_interface_dummy88(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 88
	virtual int dialog_interface_dummy89(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 89
	virtual int dialog_interface_dummy90(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 90
	virtual int dialog_interface_dummy91(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 91
	virtual int dialog_interface_dummy92(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 92
	virtual int dialog_interface_dummy93(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 93
	virtual int dialog_interface_dummy94(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 94
	virtual int dialog_interface_dummy95(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 95
	virtual int dialog_interface_dummy96(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 96
	virtual int dialog_interface_dummy97(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 97
	virtual int dialog_interface_dummy98(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 98
	virtual int dialog_interface_dummy99(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 99
	virtual int dialog_interface_dummy100(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 100
	virtual int dialog_interface_dummy101(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 101
	virtual int dialog_interface_dummy102(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 102
	virtual int dialog_interface_dummy103(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 103
	virtual int dialog_interface_dummy104(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 104
	virtual int dialog_interface_dummy105(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 105
	virtual int dialog_interface_dummy106(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 106
	virtual int dialog_interface_dummy107(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 107
	virtual int dialog_interface_dummy108(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 108
	virtual int dialog_interface_dummy109(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 109
	virtual int dialog_interface_dummy110(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 110
	virtual int dialog_interface_dummy111(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 111
	virtual int dialog_interface_dummy112(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 112
	virtual int dialog_interface_dummy113(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 113
	virtual int dialog_interface_dummy114(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 114
	virtual int dialog_interface_dummy115(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 115
	virtual int dialog_interface_dummy116(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 116
	virtual int dialog_interface_dummy117(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 117
	virtual int dialog_interface_dummy118(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 118
	virtual int dialog_interface_dummy119(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 119
	virtual int dialog_interface_dummy120(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 120
	virtual int dialog_interface_dummy121(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 121
	virtual int dialog_interface_dummy122(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 122
	virtual int dialog_interface_dummy123(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 123
	virtual int dialog_interface_dummy124(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 124
	virtual int dialog_interface_dummy125(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 125
	virtual int dialog_interface_dummy126(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 126
	virtual int dialog_interface_dummy127(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 127
	virtual int dialog_interface_dummy128(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 128
	virtual int dialog_interface_dummy129(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 129
	virtual int dialog_interface_dummy130(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 130
	virtual int dialog_interface_dummy131(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 131
	virtual int dialog_interface_dummy132(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 132
	virtual int dialog_interface_dummy133(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 133
	virtual int dialog_interface_dummy134(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 134
	virtual int dialog_interface_dummy135(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 135
	virtual int dialog_interface_dummy136(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 136
	virtual int dialog_interface_dummy137(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 137
	virtual int dialog_interface_dummy138(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 138
	virtual int dialog_interface_dummy139(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 139
	virtual int dialog_interface_dummy140(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 140
	virtual int dialog_interface_dummy141(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 141
	virtual int dialog_interface_dummy142(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 142
	virtual int dialog_interface_dummy143(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 143
	virtual int dialog_interface_dummy144(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 144
	virtual int dialog_interface_dummy145(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 145
	virtual int dialog_interface_dummy146(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 146
	virtual int dialog_interface_dummy147(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 147
	virtual int dialog_interface_dummy148(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 148
	virtual int dialog_interface_dummy149(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 149
	virtual int dialog_interface_dummy150(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 150
	virtual int dialog_interface_dummy151(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 151
	virtual int dialog_interface_dummy152(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 152
	virtual int dialog_interface_dummy153(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 153
	virtual int dialog_interface_dummy154(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 154
	virtual int dialog_interface_dummy155(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 155
	virtual int dialog_interface_dummy156(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 156
	virtual int dialog_interface_dummy157(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 157
	virtual int dialog_interface_dummy158(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 158
	virtual int dialog_interface_dummy159(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 159
	virtual int dialog_interface_dummy160(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 160
	virtual int dialog_interface_dummy161(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 161
	virtual int dialog_interface_dummy162(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 162
	virtual int dialog_interface_dummy163(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 163
	virtual int dialog_interface_dummy164(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 164
	virtual int dialog_interface_dummy165(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 165
	virtual int dialog_interface_dummy166(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 166
	virtual int dialog_interface_dummy167(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 167
	virtual int dialog_interface_dummy168(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 168
	virtual int dialog_interface_dummy169(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 169
	virtual int dialog_interface_dummy170(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 170
	virtual int dialog_interface_dummy171(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 171
	virtual int dialog_interface_dummy172(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 172
	virtual int dialog_interface_dummy173(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 173
	virtual int dialog_interface_dummy174(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 174
	virtual int dialog_interface_dummy175(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 175
	virtual int dialog_interface_dummy176(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 176
	virtual int dialog_interface_dummy177(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 177
	virtual int dialog_interface_dummy178(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 178
	virtual int dialog_interface_dummy179(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 179
	virtual int dialog_interface_dummy180(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 180
	virtual int dialog_interface_dummy181(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 181
	virtual int dialog_interface_dummy182(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 182
	virtual int dialog_interface_dummy183(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 183
	virtual int dialog_interface_dummy184(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 184
	virtual int dialog_interface_dummy185(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 185
	virtual int dialog_interface_dummy186(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 186
	virtual int dialog_interface_dummy187(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 187
	virtual int dialog_interface_dummy188(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 188
	virtual int dialog_interface_dummy189(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 189
	virtual int dialog_interface_dummy190(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 190
	virtual int dialog_interface_dummy191(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 191
	virtual int dialog_interface_dummy192(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 192
	virtual int dialog_interface_dummy193(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 193
	virtual int dialog_interface_dummy194(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 194
	virtual int dialog_interface_dummy195(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 195
	virtual int dialog_interface_dummy196(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 196
	virtual int dialog_interface_dummy197(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 197
	virtual int dialog_interface_dummy198(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 198
	virtual int dialog_interface_dummy199(void *) { assert(false); throw "invalid interface dialog_interface"; return 0; } // 199

		bool get_bool_property_value ( int index) { bool v; get_bool_property_value(index , v); return v; }
		int get_int_property_value ( int index) { int v; get_int_property_value(index , v); return v; }
		float get_float_property_value ( int index) { float v; get_float_property_value(index , v); return v; }
		sx::vec<float,3> get_vec3_property_value ( int index) { sx::vec<float,3> v; get_vec3_property_value(index , v); return v; }
		sx::rgb<float> get_rgb_property_value ( int index) { sx::rgb<float> v; get_rgb_property_value(index , v); return v; }
		unsigned get_selection_property_value ( int index) { unsigned v; get_selection_property_value(index , v); return v; }
		const char* get_string_property_value ( int index) { const char* v; get_string_property_value(index , v); return v; }
		double get_double_property_value ( int index) { double v; get_double_property_value(index , v); return v; }
		void set_bool_property_value ( int index , bool value , bool default_value) { set_bool_property_value(index , value); set_bool_default_value(index , default_value); }
		void set_int_property_value ( int index , int value , int default_value) { set_int_property_value(index , value); set_int_default_value(index , default_value); }
		void set_float_property_value ( int index , float value , float default_value) { set_float_property_value(index , value); set_float_default_value(index , default_value); }
		void set_double_property_value ( int index , double value , double default_value) { set_double_property_value(index , value); set_double_default_value(index , default_value); }
		void set_selection_property_value ( int index , unsigned value , unsigned default_value) { set_selection_property_value(index , value); set_selection_default_value(index , default_value); }
		void set_vec3_property_value ( int index , sx::vec<float,3> value , sx::vec<float,3> default_value) { set_vec3_property_value(index , value); set_vec3_default_value(index , default_value); }
		void set_rgb_property_value ( int index , sx::rgb<float> value , sx::rgb<float> default_value) { set_rgb_property_value(index , value); set_rgb_default_value(index , default_value); }
		void set_string_property_value ( int index , const char* value , const char* default_value) { set_string_property_value(index , value); set_string_default_value(index , default_value); }
		sx::vec<float,3> get_vector3_property_value ( int index) { sx::vec<float,3> v(1.0f, 1.0f, 1.0f); get_vec3_property_value(index , v); return sx::vec<float,3>(v); }
		sx::rgb<float> get_vectorrgb_property_value ( int index) { sx::rgb<float> v(1.0f, 1.0f, 1.0f); get_rgb_property_value(index , v); return sx::rgb<float>(v); }
		void set_vector3_property_value ( int index , const sx::vec<float,3> &value , const sx::vec<float,3> &default_value) { set_vec3_property_value(index , sx::vec<float,3>(value)); set_vec3_default_value(index , sx::vec<float,3>(default_value)); }
		void set_vectorrgb_property_value ( int index , const sx::rgb<float> &value , const sx::rgb<float> &default_value) { set_rgb_property_value(index , sx::rgb<float>(value)); set_rgb_default_value(index , sx::rgb<float>(default_value)); }
	};

	class property_list_interface : public dialog_interface {
	public:
	virtual void finalize (void* aux = 0) { } // 0
	virtual void unfinalize (void* aux = 0) { } // 1
	virtual int property_list_interface_dummy2(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 2
	virtual int property_list_interface_dummy3(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 3
	virtual int property_list_interface_dummy4(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 4
	virtual int property_list_interface_dummy5(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 5
	virtual int property_list_interface_dummy6(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 6
	virtual int property_list_interface_dummy7(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 7
	virtual int property_list_interface_dummy8(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 8
	virtual int property_list_interface_dummy9(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 9
	virtual int property_list_interface_dummy10(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 10
	virtual int property_list_interface_dummy11(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 11
	virtual int property_list_interface_dummy12(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 12
	virtual int property_list_interface_dummy13(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 13
	virtual int property_list_interface_dummy14(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 14
	virtual int property_list_interface_dummy15(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 15
	virtual int property_list_interface_dummy16(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 16
	virtual int property_list_interface_dummy17(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 17
	virtual int property_list_interface_dummy18(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 18
	virtual int property_list_interface_dummy19(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 19
	virtual int property_list_interface_dummy20(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 20
	virtual int property_list_interface_dummy21(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 21
	virtual int property_list_interface_dummy22(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 22
	virtual int property_list_interface_dummy23(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 23
	virtual int property_list_interface_dummy24(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 24
	virtual int property_list_interface_dummy25(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 25
	virtual int property_list_interface_dummy26(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 26
	virtual int property_list_interface_dummy27(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 27
	virtual int property_list_interface_dummy28(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 28
	virtual int property_list_interface_dummy29(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 29
	virtual int property_list_interface_dummy30(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 30
	virtual int property_list_interface_dummy31(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 31
	virtual int property_list_interface_dummy32(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 32
	virtual int property_list_interface_dummy33(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 33
	virtual int property_list_interface_dummy34(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 34
	virtual int property_list_interface_dummy35(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 35
	virtual int property_list_interface_dummy36(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 36
	virtual int property_list_interface_dummy37(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 37
	virtual int property_list_interface_dummy38(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 38
	virtual int property_list_interface_dummy39(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 39
	virtual int property_list_interface_dummy40(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 40
	virtual int property_list_interface_dummy41(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 41
	virtual int property_list_interface_dummy42(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 42
	virtual int property_list_interface_dummy43(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 43
	virtual int property_list_interface_dummy44(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 44
	virtual int property_list_interface_dummy45(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 45
	virtual int property_list_interface_dummy46(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 46
	virtual int property_list_interface_dummy47(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 47
	virtual int property_list_interface_dummy48(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 48
	virtual int property_list_interface_dummy49(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 49
	virtual int property_list_interface_dummy50(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 50
	virtual int property_list_interface_dummy51(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 51
	virtual int property_list_interface_dummy52(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 52
	virtual int property_list_interface_dummy53(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 53
	virtual int property_list_interface_dummy54(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 54
	virtual int property_list_interface_dummy55(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 55
	virtual int property_list_interface_dummy56(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 56
	virtual int property_list_interface_dummy57(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 57
	virtual int property_list_interface_dummy58(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 58
	virtual int property_list_interface_dummy59(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 59
	virtual int property_list_interface_dummy60(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 60
	virtual int property_list_interface_dummy61(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 61
	virtual int property_list_interface_dummy62(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 62
	virtual int property_list_interface_dummy63(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 63
	virtual int property_list_interface_dummy64(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 64
	virtual int property_list_interface_dummy65(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 65
	virtual int property_list_interface_dummy66(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 66
	virtual int property_list_interface_dummy67(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 67
	virtual int property_list_interface_dummy68(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 68
	virtual int property_list_interface_dummy69(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 69
	virtual int property_list_interface_dummy70(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 70
	virtual int property_list_interface_dummy71(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 71
	virtual int property_list_interface_dummy72(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 72
	virtual int property_list_interface_dummy73(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 73
	virtual int property_list_interface_dummy74(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 74
	virtual int property_list_interface_dummy75(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 75
	virtual int property_list_interface_dummy76(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 76
	virtual int property_list_interface_dummy77(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 77
	virtual int property_list_interface_dummy78(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 78
	virtual int property_list_interface_dummy79(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 79
	virtual int property_list_interface_dummy80(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 80
	virtual int property_list_interface_dummy81(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 81
	virtual int property_list_interface_dummy82(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 82
	virtual int property_list_interface_dummy83(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 83
	virtual int property_list_interface_dummy84(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 84
	virtual int property_list_interface_dummy85(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 85
	virtual int property_list_interface_dummy86(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 86
	virtual int property_list_interface_dummy87(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 87
	virtual int property_list_interface_dummy88(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 88
	virtual int property_list_interface_dummy89(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 89
	virtual int property_list_interface_dummy90(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 90
	virtual int property_list_interface_dummy91(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 91
	virtual int property_list_interface_dummy92(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 92
	virtual int property_list_interface_dummy93(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 93
	virtual int property_list_interface_dummy94(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 94
	virtual int property_list_interface_dummy95(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 95
	virtual int property_list_interface_dummy96(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 96
	virtual int property_list_interface_dummy97(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 97
	virtual int property_list_interface_dummy98(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 98
	virtual int property_list_interface_dummy99(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 99
	virtual int property_list_interface_dummy100(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 100
	virtual int property_list_interface_dummy101(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 101
	virtual int property_list_interface_dummy102(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 102
	virtual int property_list_interface_dummy103(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 103
	virtual int property_list_interface_dummy104(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 104
	virtual int property_list_interface_dummy105(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 105
	virtual int property_list_interface_dummy106(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 106
	virtual int property_list_interface_dummy107(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 107
	virtual int property_list_interface_dummy108(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 108
	virtual int property_list_interface_dummy109(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 109
	virtual int property_list_interface_dummy110(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 110
	virtual int property_list_interface_dummy111(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 111
	virtual int property_list_interface_dummy112(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 112
	virtual int property_list_interface_dummy113(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 113
	virtual int property_list_interface_dummy114(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 114
	virtual int property_list_interface_dummy115(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 115
	virtual int property_list_interface_dummy116(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 116
	virtual int property_list_interface_dummy117(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 117
	virtual int property_list_interface_dummy118(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 118
	virtual int property_list_interface_dummy119(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 119
	virtual int property_list_interface_dummy120(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 120
	virtual int property_list_interface_dummy121(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 121
	virtual int property_list_interface_dummy122(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 122
	virtual int property_list_interface_dummy123(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 123
	virtual int property_list_interface_dummy124(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 124
	virtual int property_list_interface_dummy125(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 125
	virtual int property_list_interface_dummy126(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 126
	virtual int property_list_interface_dummy127(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 127
	virtual int property_list_interface_dummy128(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 128
	virtual int property_list_interface_dummy129(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 129
	virtual int property_list_interface_dummy130(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 130
	virtual int property_list_interface_dummy131(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 131
	virtual int property_list_interface_dummy132(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 132
	virtual int property_list_interface_dummy133(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 133
	virtual int property_list_interface_dummy134(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 134
	virtual int property_list_interface_dummy135(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 135
	virtual int property_list_interface_dummy136(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 136
	virtual int property_list_interface_dummy137(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 137
	virtual int property_list_interface_dummy138(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 138
	virtual int property_list_interface_dummy139(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 139
	virtual int property_list_interface_dummy140(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 140
	virtual int property_list_interface_dummy141(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 141
	virtual int property_list_interface_dummy142(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 142
	virtual int property_list_interface_dummy143(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 143
	virtual int property_list_interface_dummy144(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 144
	virtual int property_list_interface_dummy145(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 145
	virtual int property_list_interface_dummy146(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 146
	virtual int property_list_interface_dummy147(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 147
	virtual int property_list_interface_dummy148(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 148
	virtual int property_list_interface_dummy149(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 149
	virtual int property_list_interface_dummy150(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 150
	virtual int property_list_interface_dummy151(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 151
	virtual int property_list_interface_dummy152(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 152
	virtual int property_list_interface_dummy153(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 153
	virtual int property_list_interface_dummy154(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 154
	virtual int property_list_interface_dummy155(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 155
	virtual int property_list_interface_dummy156(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 156
	virtual int property_list_interface_dummy157(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 157
	virtual int property_list_interface_dummy158(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 158
	virtual int property_list_interface_dummy159(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 159
	virtual int property_list_interface_dummy160(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 160
	virtual int property_list_interface_dummy161(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 161
	virtual int property_list_interface_dummy162(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 162
	virtual int property_list_interface_dummy163(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 163
	virtual int property_list_interface_dummy164(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 164
	virtual int property_list_interface_dummy165(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 165
	virtual int property_list_interface_dummy166(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 166
	virtual int property_list_interface_dummy167(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 167
	virtual int property_list_interface_dummy168(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 168
	virtual int property_list_interface_dummy169(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 169
	virtual int property_list_interface_dummy170(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 170
	virtual int property_list_interface_dummy171(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 171
	virtual int property_list_interface_dummy172(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 172
	virtual int property_list_interface_dummy173(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 173
	virtual int property_list_interface_dummy174(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 174
	virtual int property_list_interface_dummy175(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 175
	virtual int property_list_interface_dummy176(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 176
	virtual int property_list_interface_dummy177(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 177
	virtual int property_list_interface_dummy178(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 178
	virtual int property_list_interface_dummy179(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 179
	virtual int property_list_interface_dummy180(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 180
	virtual int property_list_interface_dummy181(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 181
	virtual int property_list_interface_dummy182(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 182
	virtual int property_list_interface_dummy183(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 183
	virtual int property_list_interface_dummy184(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 184
	virtual int property_list_interface_dummy185(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 185
	virtual int property_list_interface_dummy186(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 186
	virtual int property_list_interface_dummy187(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 187
	virtual int property_list_interface_dummy188(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 188
	virtual int property_list_interface_dummy189(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 189
	virtual int property_list_interface_dummy190(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 190
	virtual int property_list_interface_dummy191(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 191
	virtual int property_list_interface_dummy192(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 192
	virtual int property_list_interface_dummy193(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 193
	virtual int property_list_interface_dummy194(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 194
	virtual int property_list_interface_dummy195(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 195
	virtual int property_list_interface_dummy196(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 196
	virtual int property_list_interface_dummy197(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 197
	virtual int property_list_interface_dummy198(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 198
	virtual int property_list_interface_dummy199(void *) { assert(false); throw "invalid interface property_list_interface"; return 0; } // 199
	};
}
