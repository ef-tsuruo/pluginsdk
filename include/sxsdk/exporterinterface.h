#pragma once

namespace sxsdk {
	class exporter_interface : public plugin_interface {
	public:
	virtual int get_number_of_passes ( void* aux =0 ) { return 1; }  // 0
	virtual int get_file_type ( void* aux =0 ) { return 0; }  // 1
	virtual const char* get_file_extension ( void* aux =0 ) { return 0; }  // 2
	virtual const char* get_file_description ( void* aux =0 ) { return 0; }  // 3
	virtual void do_export (plugin_exporter_interface* plugin_exporter, void* aux = 0) { }  // 4
	virtual void start ( void* aux =0 ) { }  // 5
	virtual void finish ( void* aux =0 ) { }  // 6
	virtual void begin ( void* aux =0 ) { }  // 7
	virtual void end ( void* aux =0 ) { }  // 8
	virtual void head ( void* aux =0 ) { }  // 9
	virtual void tail ( void* aux =0 ) { }  // 10
	virtual void set_transformation (const sxsdk::mat4 & t, void* aux = 0) { }  // 11
	virtual void clear_transformation ( void* aux =0 ) { }  // 12
	virtual void do_polyline (points_interface* points, void* aux = 0) { }  // 13
	virtual void do_polygon (int n, points_interface** c, void* aux = 0) { }  // 14
	virtual void do_meshes (meshes_interface* m, void* aux = 0) { }  // 15
	virtual void do_sphere (const sxsdk::mat4& t, void* aux = 0) { }  // 16
	virtual void do_bezier_surface (mesh_interface* m, void* aux = 0) { }  // 17
	virtual void begin_polymesh ( void* aux =0 ) { }  // 18
	virtual void begin_polymesh_vertex (int n, void* aux = 0) { }  // 19
	virtual void polymesh_vertex (int i, const sxsdk::vec3& v, void* aux = 0) { }  // 20
	virtual void end_polymesh_vertex ( void* aux =0 ) { }  // 21
	virtual void begin_polymesh_face (int n, void* aux = 0) { }  // 22
	virtual void polymesh_face (int n_list, const int list[], const sxsdk::vec3* normals, const sxsdk::vec4* plane_equation, void* aux = 0) { }  // 23
	virtual void end_polymesh_face ( void* aux =0 ) { }  // 24
	virtual void end_polymesh ( void* aux =0 ) { }  // 25
	virtual bool can_accept_polyline ( void* aux =0 ) { return false; }  // 26
	virtual bool can_accept_polygon ( void* aux =0 ) { return false; }  // 27
	virtual bool can_accept_sphere ( void* aux =0 ) { return false; }  // 28
	virtual bool can_accept_bezier_surface ( void* aux =0 ) { return false; }  // 29
	virtual bool can_accept_polymesh ( void* aux =0 ) { return false; }  // 30
	virtual bool must_triangulate_polymesh ( void* aux =0 ) { return false; }  // 31
	virtual bool can_accept_disk ( void* aux =0 ) { return false; }  // 32
	virtual void do_disk (const sxsdk::mat4& t, float t0, float t1, bool filled, void* aux = 0) { }  // 33
	virtual int get_file_creator ( void* aux =0 ) { return ' '; }  // 34
	virtual bool cannot_select_eol ( void* aux =0 ) { return false; }  // 35
	virtual bool can_export_binary ( void* aux =0 ) { return false; }  // 36
	virtual bool can_export_text ( void* aux =0 ) { return false; }  // 37
	virtual bool can_export_to_stream (bool& uses_filesavedialog) { return true; }  // 38
	virtual bool uses_temporary_file ( void* aux =0 ) { return false; }  // 39
	virtual void clean_up ( void* aux =0 ) { }  // 40
	virtual bool skips_dialog ( void* aux =0 ) { return false; }  // 41
	virtual int get_max_vertices_per_face ( void* aux =0 ) { return -1; }  // 42
	virtual bool can_accept_texture ( void* aux =0 ) { return false; }  // 43
	virtual void polymesh_face_uv (int n_list, const int list[], const sxsdk::vec3* normals, const sxsdk::vec4* plane_equation, const sxsdk::vec2* uvs, void* aux = 0) { }  // 44
	virtual bool can_accept_closed_mesh ( void* aux =0 ) { return false; }  // 45
	virtual bool can_select_surface_attributes ( void* aux =0 ) { return false; }  // 46
	virtual void polymesh_face_uvuv (int n_list, const int list[], const sxsdk::vec3* normals, const sxsdk::vec4* plane_equation, const sxsdk::vec4* uvs, void* aux = 0) { }  // 47
	virtual bool can_accept_link ( void* aux =0 ) { return false; }  // 48
	virtual void do_link (part_class& link, void* aux = 0) { }  // 49
	virtual bool do_custom ( void* aux =0 ) { return false; }  // 50
	virtual bool can_accept_meshes ( void* aux =0 ) { return true; }  // 51
	virtual bool must_divide_polymesh ( void* aux =0 ) { return false; }  // 52
	virtual bool can_accept_exporter_settings ( void* aux =0 ) { return false; }  // 53
	virtual void do_export_with_settings (sxsdk::plugin_exporter_interface* plugin_exporter, const sxsdk::exporter_settings_interface* settings) { }  // 54
	virtual void polymesh_face_uvs (int n_list, const int list[], const sxsdk::vec3* normals, const sxsdk::vec4* plane_equation, const int n_uvs, const sxsdk::vec2* uvs, void* aux = 0) { }  // 55
	virtual void begin_polymesh_face2 (int n, int number_of_face_groups, void* aux = 0) { }  // 56
	virtual void end_polymesh_face2 ( void* aux =0 ) { }  // 57
	virtual void begin_polymesh_face_group (int face_group_index, void* aux = 0) { }  // 58
	virtual void end_polymesh_face_group ( void* aux =0 ) { }  // 59
	virtual int exporter_interface_dummy60(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 60
	virtual int exporter_interface_dummy61(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 61
	virtual int exporter_interface_dummy62(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 62
	virtual int exporter_interface_dummy63(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 63
	virtual int exporter_interface_dummy64(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 64
	virtual int exporter_interface_dummy65(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 65
	virtual int exporter_interface_dummy66(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 66
	virtual int exporter_interface_dummy67(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 67
	virtual int exporter_interface_dummy68(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 68
	virtual int exporter_interface_dummy69(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 69
	virtual int exporter_interface_dummy70(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 70
	virtual int exporter_interface_dummy71(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 71
	virtual int exporter_interface_dummy72(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 72
	virtual int exporter_interface_dummy73(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 73
	virtual int exporter_interface_dummy74(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 74
	virtual int exporter_interface_dummy75(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 75
	virtual int exporter_interface_dummy76(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 76
	virtual int exporter_interface_dummy77(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 77
	virtual int exporter_interface_dummy78(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 78
	virtual int exporter_interface_dummy79(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 79
	virtual int exporter_interface_dummy80(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 80
	virtual int exporter_interface_dummy81(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 81
	virtual int exporter_interface_dummy82(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 82
	virtual int exporter_interface_dummy83(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 83
	virtual int exporter_interface_dummy84(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 84
	virtual int exporter_interface_dummy85(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 85
	virtual int exporter_interface_dummy86(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 86
	virtual int exporter_interface_dummy87(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 87
	virtual int exporter_interface_dummy88(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 88
	virtual int exporter_interface_dummy89(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 89
	virtual int exporter_interface_dummy90(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 90
	virtual int exporter_interface_dummy91(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 91
	virtual int exporter_interface_dummy92(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 92
	virtual int exporter_interface_dummy93(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 93
	virtual int exporter_interface_dummy94(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 94
	virtual int exporter_interface_dummy95(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 95
	virtual int exporter_interface_dummy96(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 96
	virtual int exporter_interface_dummy97(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 97
	virtual int exporter_interface_dummy98(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 98
	virtual int exporter_interface_dummy99(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 99
	virtual int exporter_interface_dummy100(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 100
	virtual int exporter_interface_dummy101(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 101
	virtual int exporter_interface_dummy102(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 102
	virtual int exporter_interface_dummy103(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 103
	virtual int exporter_interface_dummy104(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 104
	virtual int exporter_interface_dummy105(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 105
	virtual int exporter_interface_dummy106(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 106
	virtual int exporter_interface_dummy107(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 107
	virtual int exporter_interface_dummy108(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 108
	virtual int exporter_interface_dummy109(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 109
	virtual int exporter_interface_dummy110(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 110
	virtual int exporter_interface_dummy111(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 111
	virtual int exporter_interface_dummy112(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 112
	virtual int exporter_interface_dummy113(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 113
	virtual int exporter_interface_dummy114(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 114
	virtual int exporter_interface_dummy115(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 115
	virtual int exporter_interface_dummy116(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 116
	virtual int exporter_interface_dummy117(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 117
	virtual int exporter_interface_dummy118(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 118
	virtual int exporter_interface_dummy119(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 119
	virtual int exporter_interface_dummy120(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 120
	virtual int exporter_interface_dummy121(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 121
	virtual int exporter_interface_dummy122(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 122
	virtual int exporter_interface_dummy123(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 123
	virtual int exporter_interface_dummy124(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 124
	virtual int exporter_interface_dummy125(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 125
	virtual int exporter_interface_dummy126(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 126
	virtual int exporter_interface_dummy127(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 127
	virtual int exporter_interface_dummy128(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 128
	virtual int exporter_interface_dummy129(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 129
	virtual int exporter_interface_dummy130(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 130
	virtual int exporter_interface_dummy131(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 131
	virtual int exporter_interface_dummy132(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 132
	virtual int exporter_interface_dummy133(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 133
	virtual int exporter_interface_dummy134(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 134
	virtual int exporter_interface_dummy135(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 135
	virtual int exporter_interface_dummy136(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 136
	virtual int exporter_interface_dummy137(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 137
	virtual int exporter_interface_dummy138(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 138
	virtual int exporter_interface_dummy139(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 139
	virtual int exporter_interface_dummy140(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 140
	virtual int exporter_interface_dummy141(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 141
	virtual int exporter_interface_dummy142(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 142
	virtual int exporter_interface_dummy143(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 143
	virtual int exporter_interface_dummy144(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 144
	virtual int exporter_interface_dummy145(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 145
	virtual int exporter_interface_dummy146(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 146
	virtual int exporter_interface_dummy147(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 147
	virtual int exporter_interface_dummy148(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 148
	virtual int exporter_interface_dummy149(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 149
	virtual int exporter_interface_dummy150(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 150
	virtual int exporter_interface_dummy151(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 151
	virtual int exporter_interface_dummy152(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 152
	virtual int exporter_interface_dummy153(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 153
	virtual int exporter_interface_dummy154(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 154
	virtual int exporter_interface_dummy155(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 155
	virtual int exporter_interface_dummy156(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 156
	virtual int exporter_interface_dummy157(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 157
	virtual int exporter_interface_dummy158(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 158
	virtual int exporter_interface_dummy159(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 159
	virtual int exporter_interface_dummy160(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 160
	virtual int exporter_interface_dummy161(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 161
	virtual int exporter_interface_dummy162(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 162
	virtual int exporter_interface_dummy163(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 163
	virtual int exporter_interface_dummy164(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 164
	virtual int exporter_interface_dummy165(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 165
	virtual int exporter_interface_dummy166(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 166
	virtual int exporter_interface_dummy167(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 167
	virtual int exporter_interface_dummy168(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 168
	virtual int exporter_interface_dummy169(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 169
	virtual int exporter_interface_dummy170(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 170
	virtual int exporter_interface_dummy171(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 171
	virtual int exporter_interface_dummy172(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 172
	virtual int exporter_interface_dummy173(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 173
	virtual int exporter_interface_dummy174(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 174
	virtual int exporter_interface_dummy175(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 175
	virtual int exporter_interface_dummy176(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 176
	virtual int exporter_interface_dummy177(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 177
	virtual int exporter_interface_dummy178(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 178
	virtual int exporter_interface_dummy179(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 179
	virtual int exporter_interface_dummy180(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 180
	virtual int exporter_interface_dummy181(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 181
	virtual int exporter_interface_dummy182(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 182
	virtual int exporter_interface_dummy183(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 183
	virtual int exporter_interface_dummy184(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 184
	virtual int exporter_interface_dummy185(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 185
	virtual int exporter_interface_dummy186(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 186
	virtual int exporter_interface_dummy187(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 187
	virtual int exporter_interface_dummy188(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 188
	virtual int exporter_interface_dummy189(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 189
	virtual int exporter_interface_dummy190(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 190
	virtual int exporter_interface_dummy191(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 191
	virtual int exporter_interface_dummy192(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 192
	virtual int exporter_interface_dummy193(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 193
	virtual int exporter_interface_dummy194(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 194
	virtual int exporter_interface_dummy195(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 195
	virtual int exporter_interface_dummy196(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 196
	virtual int exporter_interface_dummy197(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 197
	virtual int exporter_interface_dummy198(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 198
	virtual int exporter_interface_dummy199(void *) { assert(false); throw "invalid interface exporter_interface"; return 0; } // 199
	};
}
