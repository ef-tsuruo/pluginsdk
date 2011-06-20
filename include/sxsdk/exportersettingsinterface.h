#pragma once

namespace sxsdk {
	class exporter_settings_interface : public unknown_interface {
	public:
		enum eol_enum { Mac, DOS, Unix, eol_last };
		enum subdivision_enum { no_subdivision, coarse, regular, fine, very_fine, subdivision_last };
		
		const sx::uuid_class exporter_id;
		eol_enum eol;
		subdivision_enum subdivision_level;
		bool export_all_objects;
		bool export_binary;
		bool export_surface_attributes;

	virtual int get_shadeversion (void * = 0) const = 0; // 0
	virtual sx::uuid_class get_uuid (void * = 0) const = 0; // 1
	virtual exporter_settings_interface &set_eol (int eol_param, void * = 0) = 0; // 2
	virtual int get_eol (void * = 0) const = 0; // 3
	virtual exporter_settings_interface &set_export_all_objects (bool export_all_objects_param, void * = 0) = 0; // 4
	virtual bool get_export_all_objects (void * = 0) const = 0; // 5
	virtual exporter_settings_interface &set_subdivision_level (int subdivision_level_param, void * = 0) = 0; // 6
	virtual int get_subdivision_level (void * = 0) const = 0; // 7
	virtual exporter_settings_interface &set_export_binary (bool export_binary_param, void * = 0) = 0; // 8
	virtual bool get_export_binary (void * = 0) const = 0; // 9
	virtual exporter_settings_interface &set_export_surface_attributes (bool export_surface_attributes_param, void * = 0) = 0; // 10
	virtual bool get_export_surface_attributes (void * = 0) const = 0; // 11
	virtual int exporter_settings_interface_dummy12(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 12
	virtual int exporter_settings_interface_dummy13(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 13
	virtual int exporter_settings_interface_dummy14(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 14
	virtual int exporter_settings_interface_dummy15(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 15
	virtual int exporter_settings_interface_dummy16(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 16
	virtual int exporter_settings_interface_dummy17(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 17
	virtual int exporter_settings_interface_dummy18(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 18
	virtual int exporter_settings_interface_dummy19(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 19
	virtual int exporter_settings_interface_dummy20(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 20
	virtual int exporter_settings_interface_dummy21(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 21
	virtual int exporter_settings_interface_dummy22(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 22
	virtual int exporter_settings_interface_dummy23(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 23
	virtual int exporter_settings_interface_dummy24(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 24
	virtual int exporter_settings_interface_dummy25(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 25
	virtual int exporter_settings_interface_dummy26(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 26
	virtual int exporter_settings_interface_dummy27(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 27
	virtual int exporter_settings_interface_dummy28(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 28
	virtual int exporter_settings_interface_dummy29(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 29
	virtual int exporter_settings_interface_dummy30(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 30
	virtual int exporter_settings_interface_dummy31(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 31
	virtual int exporter_settings_interface_dummy32(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 32
	virtual int exporter_settings_interface_dummy33(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 33
	virtual int exporter_settings_interface_dummy34(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 34
	virtual int exporter_settings_interface_dummy35(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 35
	virtual int exporter_settings_interface_dummy36(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 36
	virtual int exporter_settings_interface_dummy37(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 37
	virtual int exporter_settings_interface_dummy38(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 38
	virtual int exporter_settings_interface_dummy39(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 39
	virtual int exporter_settings_interface_dummy40(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 40
	virtual int exporter_settings_interface_dummy41(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 41
	virtual int exporter_settings_interface_dummy42(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 42
	virtual int exporter_settings_interface_dummy43(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 43
	virtual int exporter_settings_interface_dummy44(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 44
	virtual int exporter_settings_interface_dummy45(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 45
	virtual int exporter_settings_interface_dummy46(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 46
	virtual int exporter_settings_interface_dummy47(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 47
	virtual int exporter_settings_interface_dummy48(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 48
	virtual int exporter_settings_interface_dummy49(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 49
	virtual int exporter_settings_interface_dummy50(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 50
	virtual int exporter_settings_interface_dummy51(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 51
	virtual int exporter_settings_interface_dummy52(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 52
	virtual int exporter_settings_interface_dummy53(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 53
	virtual int exporter_settings_interface_dummy54(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 54
	virtual int exporter_settings_interface_dummy55(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 55
	virtual int exporter_settings_interface_dummy56(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 56
	virtual int exporter_settings_interface_dummy57(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 57
	virtual int exporter_settings_interface_dummy58(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 58
	virtual int exporter_settings_interface_dummy59(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 59
	virtual int exporter_settings_interface_dummy60(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 60
	virtual int exporter_settings_interface_dummy61(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 61
	virtual int exporter_settings_interface_dummy62(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 62
	virtual int exporter_settings_interface_dummy63(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 63
	virtual int exporter_settings_interface_dummy64(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 64
	virtual int exporter_settings_interface_dummy65(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 65
	virtual int exporter_settings_interface_dummy66(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 66
	virtual int exporter_settings_interface_dummy67(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 67
	virtual int exporter_settings_interface_dummy68(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 68
	virtual int exporter_settings_interface_dummy69(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 69
	virtual int exporter_settings_interface_dummy70(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 70
	virtual int exporter_settings_interface_dummy71(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 71
	virtual int exporter_settings_interface_dummy72(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 72
	virtual int exporter_settings_interface_dummy73(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 73
	virtual int exporter_settings_interface_dummy74(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 74
	virtual int exporter_settings_interface_dummy75(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 75
	virtual int exporter_settings_interface_dummy76(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 76
	virtual int exporter_settings_interface_dummy77(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 77
	virtual int exporter_settings_interface_dummy78(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 78
	virtual int exporter_settings_interface_dummy79(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 79
	virtual int exporter_settings_interface_dummy80(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 80
	virtual int exporter_settings_interface_dummy81(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 81
	virtual int exporter_settings_interface_dummy82(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 82
	virtual int exporter_settings_interface_dummy83(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 83
	virtual int exporter_settings_interface_dummy84(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 84
	virtual int exporter_settings_interface_dummy85(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 85
	virtual int exporter_settings_interface_dummy86(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 86
	virtual int exporter_settings_interface_dummy87(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 87
	virtual int exporter_settings_interface_dummy88(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 88
	virtual int exporter_settings_interface_dummy89(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 89
	virtual int exporter_settings_interface_dummy90(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 90
	virtual int exporter_settings_interface_dummy91(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 91
	virtual int exporter_settings_interface_dummy92(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 92
	virtual int exporter_settings_interface_dummy93(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 93
	virtual int exporter_settings_interface_dummy94(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 94
	virtual int exporter_settings_interface_dummy95(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 95
	virtual int exporter_settings_interface_dummy96(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 96
	virtual int exporter_settings_interface_dummy97(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 97
	virtual int exporter_settings_interface_dummy98(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 98
	virtual int exporter_settings_interface_dummy99(void *) { assert(false); throw "invalid interface exporter_settings_interface"; return 0; } // 99
	};

	class _3ds_exporter_settings_interface : public exporter_settings_interface {
	public:
		enum image_type_enum { type_bmp, type_pict, image_type_last };
		enum method_enum { object_name, material_name, index, method_last };
		
		image_type_enum image_filetype;
		method_enum groupname_method;
		bool export_material;
		bool export_camera;
		bool export_light;
		bool short_name;
		std::string groupname_prefix;

	virtual _3ds_exporter_settings_interface &set_export_material (bool export_material_param, void * = 0) = 0; // 0
	virtual bool get_export_material (void * = 0) const = 0; // 1
	virtual _3ds_exporter_settings_interface &set_image_filetype (int image_filetype_param, void * = 0) = 0; // 2
	virtual int get_image_filetype (void * = 0) const = 0; // 3
	virtual _3ds_exporter_settings_interface &set_export_camera (bool export_camera_param, void * = 0) = 0; // 4
	virtual bool get_export_camera (void * = 0) const = 0; // 5
	virtual _3ds_exporter_settings_interface &set_export_light (bool export_light_param, void * = 0) = 0; // 6
	virtual bool get_export_light (void * = 0) const = 0; // 7
	virtual _3ds_exporter_settings_interface &set_groupname_method (int groupname_method_param, void * = 0) = 0; // 8
	virtual int get_groupname_method (void * = 0) const = 0; // 9
	virtual _3ds_exporter_settings_interface &set_groupname_prefix (const char* groupname_prefix_param, void * = 0) = 0; // 10
	virtual const char* get_groupname_prefix (void * = 0) const = 0; // 11
	virtual _3ds_exporter_settings_interface &set_short_name (bool short_name_param, void * = 0) = 0; // 12
	virtual bool get_short_name (void * = 0) const = 0; // 13
