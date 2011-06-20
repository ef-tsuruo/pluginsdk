#pragma once

namespace sxsdk {
    class shader_info_base_class {
		public:
		virtual ~shader_info_base_class () { }
    };
	class shader_interface : public plugin_interface {
	public:
	virtual int get_default_map_mode ( void* aux =0 ) { return 3; }  // 0
	virtual float evaluate (const sxsdk::vec3& p, void* aux = 0) { return 0.0; }  // 1
	virtual bool supports_evaluate ( void* aux =0 ) { return false; }  // 2
	virtual void shade ( void* aux =0 ) { }  // 3
	virtual bool supports_shade ( void* aux =0 ) { return false; }  // 4
	virtual void bump ( void* aux =0 ) { }  // 5
	virtual bool supports_bump ( void* aux =0 ) { return false; }  // 6
	virtual bool ask (stream_interface* stream, void* aux = 0) { return false; }  // 7
	virtual shader_info_base_class *new_shader_info (stream_interface* stream, void* aux = 0) { return 0; }  // 8
	virtual bool needs_uv ( void* aux =0 ) { return false; }  // 9
	virtual bool needs_tangents ( void* aux =0 ) { return false; }  // 10
	virtual bool needs_turbulence ( void* aux =0 ) { return false; }  // 11
	virtual bool needs_softness ( void* aux =0 ) { return false; }  // 12
	virtual bool needs_to_sample_image ( void* aux =0 ) { return false; }  // 13
	virtual bool needs_to_sample_bump ( void* aux =0 ) { return false; }  // 14
	virtual bool needs_projection ( void* aux =0 ) { return false; }  // 15
	virtual bool visible ( void* aux =0 ) { return true; }  // 16
	virtual int shader_interface_dummy17(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 17
	virtual int shader_interface_dummy18(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 18
	virtual int shader_interface_dummy19(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 19
	virtual int shader_interface_dummy20(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 20
	virtual int shader_interface_dummy21(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 21
	virtual int shader_interface_dummy22(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 22
	virtual int shader_interface_dummy23(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 23
	virtual int shader_interface_dummy24(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 24
	virtual int shader_interface_dummy25(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 25
	virtual int shader_interface_dummy26(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 26
	virtual int shader_interface_dummy27(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 27
	virtual int shader_interface_dummy28(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 28
	virtual int shader_interface_dummy29(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 29
	virtual int shader_interface_dummy30(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 30
	virtual int shader_interface_dummy31(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 31
	virtual int shader_interface_dummy32(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 32
	virtual int shader_interface_dummy33(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 33
	virtual int shader_interface_dummy34(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 34
	virtual int shader_interface_dummy35(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 35
	virtual int shader_interface_dummy36(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 36
	virtual int shader_interface_dummy37(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 37
	virtual int shader_interface_dummy38(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 38
	virtual int shader_interface_dummy39(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 39
	virtual int shader_interface_dummy40(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 40
	virtual int shader_interface_dummy41(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 41
	virtual int shader_interface_dummy42(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 42
	virtual int shader_interface_dummy43(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 43
	virtual int shader_interface_dummy44(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 44
	virtual int shader_interface_dummy45(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 45
	virtual int shader_interface_dummy46(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 46
	virtual int shader_interface_dummy47(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 47
	virtual int shader_interface_dummy48(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 48
	virtual int shader_interface_dummy49(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 49
	virtual int shader_interface_dummy50(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 50
	virtual int shader_interface_dummy51(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 51
	virtual int shader_interface_dummy52(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 52
	virtual int shader_interface_dummy53(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 53
	virtual int shader_interface_dummy54(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 54
	virtual int shader_interface_dummy55(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 55
	virtual int shader_interface_dummy56(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 56
	virtual int shader_interface_dummy57(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 57
	virtual int shader_interface_dummy58(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 58
	virtual int shader_interface_dummy59(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 59
	virtual int shader_interface_dummy60(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 60
	virtual int shader_interface_dummy61(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 61
	virtual int shader_interface_dummy62(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 62
	virtual int shader_interface_dummy63(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 63
	virtual int shader_interface_dummy64(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 64
	virtual int shader_interface_dummy65(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 65
	virtual int shader_interface_dummy66(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 66
	virtual int shader_interface_dummy67(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 67
	virtual int shader_interface_dummy68(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 68
	virtual int shader_interface_dummy69(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 69
	virtual int shader_interface_dummy70(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 70
	virtual int shader_interface_dummy71(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 71
	virtual int shader_interface_dummy72(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 72
	virtual int shader_interface_dummy73(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 73
	virtual int shader_interface_dummy74(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 74
	virtual int shader_interface_dummy75(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 75
	virtual int shader_interface_dummy76(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 76
	virtual int shader_interface_dummy77(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 77
	virtual int shader_interface_dummy78(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 78
	virtual int shader_interface_dummy79(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 79
	virtual int shader_interface_dummy80(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 80
	virtual int shader_interface_dummy81(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 81
	virtual int shader_interface_dummy82(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 82
	virtual int shader_interface_dummy83(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 83
	virtual int shader_interface_dummy84(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 84
	virtual int shader_interface_dummy85(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 85
	virtual int shader_interface_dummy86(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 86
	virtual int shader_interface_dummy87(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 87
	virtual int shader_interface_dummy88(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 88
	virtual int shader_interface_dummy89(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 89
	virtual int shader_interface_dummy90(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 90
	virtual int shader_interface_dummy91(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 91
	virtual int shader_interface_dummy92(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 92
	virtual int shader_interface_dummy93(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 93
	virtual int shader_interface_dummy94(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 94
	virtual int shader_interface_dummy95(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 95
	virtual int shader_interface_dummy96(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 96
	virtual int shader_interface_dummy97(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 97
	virtual int shader_interface_dummy98(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 98
	virtual int shader_interface_dummy99(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 99
	virtual int shader_interface_dummy100(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 100
	virtual int shader_interface_dummy101(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 101
	virtual int shader_interface_dummy102(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 102
	virtual int shader_interface_dummy103(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 103
	virtual int shader_interface_dummy104(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 104
	virtual int shader_interface_dummy105(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 105
	virtual int shader_interface_dummy106(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 106
	virtual int shader_interface_dummy107(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 107
	virtual int shader_interface_dummy108(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 108
	virtual int shader_interface_dummy109(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 109
	virtual int shader_interface_dummy110(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 110
	virtual int shader_interface_dummy111(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 111
	virtual int shader_interface_dummy112(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 112
	virtual int shader_interface_dummy113(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 113
	virtual int shader_interface_dummy114(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 114
	virtual int shader_interface_dummy115(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 115
	virtual int shader_interface_dummy116(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 116
	virtual int shader_interface_dummy117(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 117
	virtual int shader_interface_dummy118(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 118
	virtual int shader_interface_dummy119(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 119
	virtual int shader_interface_dummy120(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 120
	virtual int shader_interface_dummy121(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 121
	virtual int shader_interface_dummy122(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 122
	virtual int shader_interface_dummy123(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 123
	virtual int shader_interface_dummy124(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 124
	virtual int shader_interface_dummy125(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 125
	virtual int shader_interface_dummy126(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 126
	virtual int shader_interface_dummy127(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 127
	virtual int shader_interface_dummy128(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 128
	virtual int shader_interface_dummy129(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 129
	virtual int shader_interface_dummy130(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 130
	virtual int shader_interface_dummy131(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 131
	virtual int shader_interface_dummy132(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 132
	virtual int shader_interface_dummy133(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 133
	virtual int shader_interface_dummy134(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 134
	virtual int shader_interface_dummy135(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 135
	virtual int shader_interface_dummy136(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 136
	virtual int shader_interface_dummy137(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 137
	virtual int shader_interface_dummy138(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 138
	virtual int shader_interface_dummy139(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 139
	virtual int shader_interface_dummy140(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 140
	virtual int shader_interface_dummy141(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 141
	virtual int shader_interface_dummy142(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 142
	virtual int shader_interface_dummy143(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 143
	virtual int shader_interface_dummy144(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 144
	virtual int shader_interface_dummy145(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 145
	virtual int shader_interface_dummy146(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 146
	virtual int shader_interface_dummy147(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 147
	virtual int shader_interface_dummy148(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 148
	virtual int shader_interface_dummy149(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 149
	virtual int shader_interface_dummy150(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 150
	virtual int shader_interface_dummy151(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 151
	virtual int shader_interface_dummy152(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 152
	virtual int shader_interface_dummy153(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 153
	virtual int shader_interface_dummy154(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 154
	virtual int shader_interface_dummy155(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 155
	virtual int shader_interface_dummy156(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 156
	virtual int shader_interface_dummy157(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 157
	virtual int shader_interface_dummy158(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 158
	virtual int shader_interface_dummy159(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 159
	virtual int shader_interface_dummy160(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 160
	virtual int shader_interface_dummy161(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 161
	virtual int shader_interface_dummy162(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 162
	virtual int shader_interface_dummy163(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 163
	virtual int shader_interface_dummy164(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 164
	virtual int shader_interface_dummy165(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 165
	virtual int shader_interface_dummy166(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 166
	virtual int shader_interface_dummy167(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 167
	virtual int shader_interface_dummy168(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 168
	virtual int shader_interface_dummy169(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 169
	virtual int shader_interface_dummy170(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 170
	virtual int shader_interface_dummy171(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 171
	virtual int shader_interface_dummy172(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 172
	virtual int shader_interface_dummy173(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 173
	virtual int shader_interface_dummy174(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 174
	virtual int shader_interface_dummy175(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 175
	virtual int shader_interface_dummy176(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 176
	virtual int shader_interface_dummy177(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 177
	virtual int shader_interface_dummy178(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 178
	virtual int shader_interface_dummy179(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 179
	virtual int shader_interface_dummy180(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 180
	virtual int shader_interface_dummy181(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 181
	virtual int shader_interface_dummy182(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 182
	virtual int shader_interface_dummy183(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 183
	virtual int shader_interface_dummy184(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 184
	virtual int shader_interface_dummy185(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 185
	virtual int shader_interface_dummy186(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 186
	virtual int shader_interface_dummy187(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 187
	virtual int shader_interface_dummy188(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 188
	virtual int shader_interface_dummy189(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 189
	virtual int shader_interface_dummy190(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 190
	virtual int shader_interface_dummy191(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 191
	virtual int shader_interface_dummy192(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 192
	virtual int shader_interface_dummy193(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 193
	virtual int shader_interface_dummy194(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 194
	virtual int shader_interface_dummy195(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 195
	virtual int shader_interface_dummy196(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 196
	virtual int shader_interface_dummy197(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 197
	virtual int shader_interface_dummy198(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 198
	virtual int shader_interface_dummy199(void *) { assert(false); throw "invalid interface shader_interface"; return 0; } // 199
shader_info_base_class* get_shader_info (void * = 0) const { return i.implementation().shader_get_shader_info(); }
const custom_element_info_base_class* get_custom_element_info (void * = 0) const { return i.implementation().shader_get_custom_element_info(); }
custom_element_info_base_class* get_custom_element_per_thread_info (void * = 0) const { return i.implementation().shader_get_custom_element_per_thread_info(); }
int get_intersection_number (void * = 0) const { return i.implementation().shader_get_intersection_number(); }
stream_interface* get_stream_interface (void * = 0) const { return i.implementation().shader_get_stream_interface(); }
float get_mapping (void * = 0) const { return i.implementation().shader_get_mapping(); }
sxsdk::rgb_class get_mapping_color (void * = 0) const { return i.implementation().shader_get_mapping_color(); }
float get_turbulence (void * = 0) const { return i.implementation().shader_get_turbulence(); }
float get_softness (void * = 0) const { return i.implementation().shader_get_softness(); }
int get_projection (void * = 0) const { return i.implementation().shader_get_projection(); }
rgba_class sample_image ( float u, float v ) { return i.implementation().shader_sample_image(u, v); }
sxsdk::vec2 sample_bump ( float u, float v ) { return i.implementation().shader_sample_bump(u, v); }
sxsdk::vec3 get_P (void * = 0) const { return i.implementation().shader_get_P(); }
shader_interface &set_P (const sxsdk::vec3 &P_param, void * = 0) { i.implementation().shader_set_P(P_param); return *this; }
sxsdk::vec3 get_N (void * = 0) const { return i.implementation().shader_get_N(); }
shader_interface &set_N (const sxsdk::vec3 &N_param, void * = 0) { i.implementation().shader_set_N(N_param); return *this; }
sxsdk::vec3 get_Ng (void * = 0) const { return i.implementation().shader_get_Ng(); }
sxsdk::vec3 get_I (void * = 0) const { return i.implementation().shader_get_I(); }
sxsdk::rgb_class get_Cs (void * = 0) const { return i.implementation().shader_get_Cs(); }
sxsdk::rgb_class get_Os (void * = 0) const { return i.implementation().shader_get_Os(); }
float get_u (void * = 0) const { return i.implementation().shader_get_u(); }
float get_v (void * = 0) const { return i.implementation().shader_get_v(); }
float get_s (void * = 0) const { return i.implementation().shader_get_s(); }
float get_t (void * = 0) const { return i.implementation().shader_get_t(); }
sxsdk::vec3 get_dPdu (void * = 0) const { return i.implementation().shader_get_dPdu(); }
sxsdk::vec3 get_dPdv (void * = 0) const { return i.implementation().shader_get_dPdv(); }
bool has_uv (void * = 0) const { return i.implementation().shader_has_uv(); }
bool has_st (void * = 0) const { return i.implementation().shader_has_st(); }
bool has_tangents (void * = 0) const { return i.implementation().shader_has_tangents(); }
float get_time (void * = 0) const { return i.implementation().shader_get_time(); }
float get_du (void * = 0) const { return i.implementation().shader_get_du(); }
float get_dv (void * = 0) const { return i.implementation().shader_get_dv(); }
sxsdk::vec3 get_L (void * = 0) const { return i.implementation().shader_get_L(); }
sxsdk::rgb_class get_Cl (void * = 0) const { return i.implementation().shader_get_Cl(); }
sxsdk::rgb_class get_Ci (void * = 0) const { return i.implementation().shader_get_Ci(); }
shader_interface &set_Ci (const sxsdk::rgb_class &Ci_param, void * = 0) { i.implementation().shader_set_Ci(Ci_param); return *this; }
sxsdk::rgb_class get_Oi (void * = 0) const { return i.implementation().shader_get_Oi(); }
shader_interface &set_Oi (const sxsdk::rgb_class &Oi_param, void * = 0) { i.implementation().shader_set_Oi(Oi_param); return *this; }
void* get_vertexdata (int index) { return i.implementation().shader_get_vertexdata(index); }
sxsdk::vec3 normalize ( const sxsdk::vec3&v ) { return i.implementation().shader_normalize(v); }
float mod ( float x, float p ) { return i.implementation().shader_mod(x, p); }
float step ( float edge, float x ) { return i.implementation().shader_step(edge, x); }
float smoothstep ( float edge0, float edge1, float x ) { return i.implementation().shader_smoothstep(edge0, edge1, x); }
float noise1 ( float x ) { return i.implementation().shader_noise11(x); }
float noise1 ( const sxsdk::vec2 &p ) { return i.implementation().shader_noise12(p); } float noise1 (float x, float y) { return noise1(sxsdk::vec2(x, y)); }
float noise1 ( const sxsdk::vec3&p ) { return i.implementation().shader_noise13(p); }
float noise1 ( const sxsdk::vec2 &p, float z ) { return noise1(sxsdk::vec3(p.x, p.y, z)); }
float noise1 ( float x, float y, float z ) { return noise1(sxsdk::vec3(x, y, z)); }
float noise1 ( const sxsdk::vec4 &p ) { return i.implementation().shader_noise14(p); }
float noise1 ( const sxsdk::vec3&p, float t ) { return noise1(sxsdk::vec4(p.x, p.y, p.z, t)); }
float noise1 ( const sxsdk::vec2 &p, float z, float t ) { return noise1(sxsdk::vec4(p.x, p.y, z, t)); }
float noise1 ( float x, float y, float z, float t ) { return noise1(sxsdk::vec4(x, y, z, t)); }
sxsdk::vec2 noise2 ( float x ) { return i.implementation().shader_noise21(x); }
sxsdk::vec2 noise2 ( const sxsdk::vec2 &p ) { return i.implementation().shader_noise22(p); }
sxsdk::vec2 noise2 ( float x, float y ) { return noise2(sxsdk::vec2(x, y)); }
sxsdk::vec2 noise2 ( const sxsdk::vec3&p ) { return i.implementation().shader_noise23(p); }
sxsdk::vec2 noise2 ( const sxsdk::vec2 &p, float z ) { return noise2(sxsdk::vec3(p.x, p.y, z)); }
sxsdk::vec2 noise2 ( float x, float y, float z ) { return noise2(sxsdk::vec3(x, y, z)); }
sxsdk::vec2 noise2 ( const sxsdk::vec4 &p ) { return i.implementation().shader_noise24(p); }
sxsdk::vec2 noise2 ( const sxsdk::vec3&p, float t ) { return noise2(sxsdk::vec4(p.x, p.y, p.z, t)); }
sxsdk::vec2 noise2 ( const sxsdk::vec2 &p, float z, float t ) { return noise2(sxsdk::vec4(p.x, p.y, z, t)); }
sxsdk::vec2 noise2 ( float x, float y, float z, float t ) { return noise2(sxsdk::vec4(x, y, z, t)); }
sxsdk::vec3 noise3 ( float x ) { return i.implementation().shader_noise31(x); }
sxsdk::vec3 noise3 ( const sxsdk::vec2 &p ) { return i.implementation().shader_noise32(p); }
sxsdk::vec3 noise3 ( float x, float y ) { return noise3(sxsdk::vec2(x, y)); }
sxsdk::vec3 noise3 ( const sxsdk::vec3&p ) { return i.implementation().shader_noise33(p); }
sxsdk::vec3 noise3 ( const sxsdk::vec2 &p, float z ) { return noise3(sxsdk::vec3(p.x, p.y, z)); }
sxsdk::vec3 noise3 ( float x, float y, float z ) { return noise3(sxsdk::vec3(x, y, z)); }
sxsdk::vec3 noise3 ( const sxsdk::vec4 &p ) { return i.implementation().shader_noise34(p); }
sxsdk::vec3 noise3 ( const sxsdk::vec3&p, float t ) { return noise3(sxsdk::vec4(p.x, p.y, p.z, t)); }
sxsdk::vec3 noise3 ( const sxsdk::vec2 &p, float z, float t ) { return noise3(sxsdk::vec4(p.x, p.y, z, t)); }
sxsdk::vec3 noise3 ( float x, float y, float z, float t ) { return noise3(sxsdk::vec4(x, y, z, t)); }
sxsdk::vec4 noise4 ( float x ) { return i.implementation().shader_noise41(x); }
sxsdk::vec4 noise4 ( const sxsdk::vec2 &p ) { return i.implementation().shader_noise42(p); }
sxsdk::vec4 noise4 ( float x, float y ) { return noise4(sxsdk::vec2(x, y)); }
sxsdk::vec4 noise4 ( const sxsdk::vec3&p ) { return i.implementation().shader_noise43(p); }
sxsdk::vec4 noise4 ( const sxsdk::vec2 &p, float z ) { return noise4(sxsdk::vec3(p.x, p.y, z)); }
sxsdk::vec4 noise4 ( float x, float y, float z ) { return noise4(sxsdk::vec3(x, y, z)); }
sxsdk::vec4 noise4 ( const sxsdk::vec4 &p ) { return i.implementation().shader_noise44(p); }
sxsdk::vec4 noise4 ( const sxsdk::vec3&p, float t ) { return noise4(sxsdk::vec4(p.x, p.y, p.z, t)); }
sxsdk::vec4 noise4 ( const sxsdk::vec2 &p, float z, float t ) { return noise4(sxsdk::vec4(p.x, p.y, z, t)); }
sxsdk::vec4 noise4 ( float x, float y, float z, float t ) { return noise4(x, y, z, t); }
float cellnoise1 ( float x ) { return i.implementation().shader_cellnoise11(x); }
float cellnoise1 ( const sxsdk::vec2 &p ) { return i.implementation().shader_cellnoise12(p); }
float cellnoise1 ( float x, float y ) { return cellnoise1(sxsdk::vec2(x, y)); }
float cellnoise1 ( const sxsdk::vec3&p ) { return i.implementation().shader_cellnoise13(p); }
float cellnoise1 ( const sxsdk::vec2 &p, float z ) { return cellnoise1(sxsdk::vec3(p.x, p.y, z)); }
float cellnoise1 ( float x, float y, float z ) { return cellnoise1(sxsdk::vec3(x, y, z)); }
float cellnoise1 ( const sxsdk::vec4 &p ) { return i.implementation().shader_cellnoise14(p); }
float cellnoise1 ( const sxsdk::vec3&p, float t ) { return cellnoise1(sxsdk::vec4(p.x, p.y, p.z, t)); }
float cellnoise1 ( const sxsdk::vec2 &p, float z, float t ) { return cellnoise1(sxsdk::vec4(p.x, p.y, z, t)); }
float cellnoise1 ( float x, float y, float z, float t ) { return cellnoise1(sxsdk::vec4(x, y, z, t)); }
sxsdk::vec2 cellnoise2 ( float x ) { return i.implementation().shader_cellnoise21(x); }
sxsdk::vec2 cellnoise2 ( const sxsdk::vec2 &p ) { return i.implementation().shader_cellnoise22(p); }
sxsdk::vec2 cellnoise2 ( float x, float y ) { return cellnoise2(sxsdk::vec2(x, y)); }
sxsdk::vec2 cellnoise2 ( const sxsdk::vec3&p ) { return i.implementation().shader_cellnoise23(p); }
sxsdk::vec2 cellnoise2 ( const sxsdk::vec2 &p, float z ) { return cellnoise2(sxsdk::vec3(p.x, p.y, z)); }
sxsdk::vec2 cellnoise2 ( float x, float y, float z ) { return cellnoise2(sxsdk::vec3(x, y, z)); }
sxsdk::vec2 cellnoise2 ( const sxsdk::vec4 &p ) { return i.implementation().shader_cellnoise24(p); }
sxsdk::vec2 cellnoise2 ( const sxsdk::vec3&p, float t ) { return cellnoise2(sxsdk::vec4(p.x, p.y, p.z, t)); }
sxsdk::vec2 cellnoise2 ( const sxsdk::vec2 &p, float z, float t ) { return cellnoise2(sxsdk::vec4(p.x, p.y, z, t)); }
sxsdk::vec2 cellnoise2 ( float x, float y, float z, float t ) { return cellnoise2(sxsdk::vec4(x, y, z, t)); }
sxsdk::vec3 cellnoise3 ( float x ) { return i.implementation().shader_cellnoise31(x); }
sxsdk::vec3 cellnoise3 ( const sxsdk::vec2 &p ) { return i.implementation().shader_cellnoise32(p); }
sxsdk::vec3 cellnoise3 ( float x, float y ) { return cellnoise3(sxsdk::vec2(x, y)); }
sxsdk::vec3 cellnoise3 ( const sxsdk::vec3&p ) { return i.implementation().shader_cellnoise33(p); }
sxsdk::vec3 cellnoise3 ( const sxsdk::vec2 &p, float z ) { return cellnoise3(sxsdk::vec3(p.x, p.y, z)); }
sxsdk::vec3 cellnoise3 ( float x, float y, float z ) { return cellnoise3(sxsdk::vec3(x, y, z)); }
sxsdk::vec3 cellnoise3 ( const sxsdk::vec4 &p ) { return i.implementation().shader_cellnoise34(p); }
sxsdk::vec3 cellnoise3 ( const sxsdk::vec3&p, float t ) { return cellnoise3(sxsdk::vec4(p.x, p.y, p.z, t)); }
sxsdk::vec3 cellnoise3 ( const sxsdk::vec2 &p, float z, float t ) { return cellnoise3(sxsdk::vec4(p.x, p.y, z, t)); }
sxsdk::vec4 cellnoise4 ( float x ) { return i.implementation().shader_cellnoise41(x); }
sxsdk::vec4 cellnoise4 ( const sxsdk::vec2 &p ) { return i.implementation().shader_cellnoise42(p); }
sxsdk::vec4 cellnoise4 ( float x, float y ) { return cellnoise4(sxsdk::vec2(x, y)); }
sxsdk::vec4 cellnoise4 ( const sxsdk::vec3&p ) { return i.implementation().shader_cellnoise43(p); }
sxsdk::vec4 cellnoise4 ( const sxsdk::vec2 &p, float z ) { return cellnoise4(sxsdk::vec3(p.x, p.y, z)); }
sxsdk::vec4 cellnoise4 ( float x, float y, float z ) { return cellnoise4(sxsdk::vec3(x, y, z)); }
sxsdk::vec4 cellnoise4 ( const sxsdk::vec4 &p ) { return i.implementation().shader_cellnoise44(p); }
sxsdk::vec4 cellnoise4 ( const sxsdk::vec3&p, float t ) { return cellnoise4(sxsdk::vec4(p.x, p.y, p.z, t)); }
sxsdk::vec4 cellnoise4 ( const sxsdk::vec2 &p, float z, float t ) { return cellnoise4(sxsdk::vec4(p.x, p.y, z, t)); }
sxsdk::vec4 cellnoise4 ( float x, float y, float z, float t ) { return cellnoise4(sxsdk::vec4(x, y, z, t)); }
float pnoise1 ( float x, float period ) { return i.implementation().shader_pnoise11(x, period); }
float pnoise1 ( const sxsdk::vec2 &p, const sxsdk::vec2 &period ) { return i.implementation().shader_pnoise12(p, period); }
float pnoise1 ( float x, float y, const sxsdk::vec2 &period ) { return pnoise1(sxsdk::vec2(x, y), period); }
float pnoise1 ( const sxsdk::vec3&p,	const sxsdk::vec3&period ) { return i.implementation().shader_pnoise13(p, period); }
float pnoise1 ( const sxsdk::vec2 &p, float z,	const sxsdk::vec3&period ) { return pnoise1(sxsdk::vec3(p.x, p.y, z), period); }
float pnoise1 ( float x, float y, float z, const sxsdk::vec3&period ) { return pnoise1(sxsdk::vec3(x, y, z), period); }
float pnoise1 ( const sxsdk::vec4 &p, const sxsdk::vec4 &period ) { return i.implementation().shader_pnoise14(p, period); }
float pnoise1 ( const sxsdk::vec3&p, float t, const sxsdk::vec4 &period ) { return pnoise1(sxsdk::vec4(p.x, p.y, p.z, t), period); }
float pnoise1 ( const sxsdk::vec2 &p, float z, float t, const sxsdk::vec4 &period ) { return pnoise1(sxsdk::vec4(p.x, p.y, z, t), period); }
float pnoise1 ( float x, float y, float z, float t, const sxsdk::vec4 &period ) { return pnoise1(sxsdk::vec4(x, y, z, t), period); }
sxsdk::vec2 pnoise2 ( float x, float period ) { return i.implementation().shader_pnoise21(x, period); }
sxsdk::vec2 pnoise2 ( const sxsdk::vec2 &p, const sxsdk::vec2 &period ) { return i.implementation().shader_pnoise22(p, period); }
sxsdk::vec2 pnoise2 ( float x, float y, const sxsdk::vec2 &period ) { return pnoise2(sxsdk::vec2(x, y), period); }
sxsdk::vec2 pnoise2 ( const sxsdk::vec3&p,	const sxsdk::vec3&period ) { return i.implementation().shader_pnoise23(p, period); }
sxsdk::vec2 pnoise2 ( const sxsdk::vec2 &p, float z,	const sxsdk::vec3&period ) { return pnoise2(sxsdk::vec3(p.x, p.y, z), period); }
sxsdk::vec2 pnoise2 ( float x, float y, float z, const sxsdk::vec3&period ) { return pnoise2(sxsdk::vec3(x, y, z), period); }
sxsdk::vec2 pnoise2 ( const sxsdk::vec4 &p, const sxsdk::vec4 &period ) { return i.implementation().shader_pnoise24(p, period); }
sxsdk::vec2 pnoise2 ( const sxsdk::vec3&p, float t, const sxsdk::vec4 &period ) { return pnoise2(sxsdk::vec4(p.x, p.y, p.z, t), period); }
sxsdk::vec2 pnoise2 ( const sxsdk::vec2 &p, float z, float t, const sxsdk::vec4 &period ) { return pnoise2(sxsdk::vec4(p.x, p.y, z, t), period); }
sxsdk::vec2 pnoise2 ( float x, float y, float z, float t, const sxsdk::vec4 &period ) { return pnoise2(sxsdk::vec4(x, y, z, t), period); }
sxsdk::vec3 pnoise3 ( float x, float period ) { return i.implementation().shader_pnoise31(x, period); }
sxsdk::vec3 pnoise3 ( const sxsdk::vec2 &p, const sxsdk::vec2 &period ) { return i.implementation().shader_pnoise32(p, period); }
sxsdk::vec3 pnoise3 ( float x, float y, const sxsdk::vec2 &period ) { return pnoise3(sxsdk::vec2(x, y), period); }
sxsdk::vec3 pnoise3 ( const sxsdk::vec3&p,	const sxsdk::vec3&period ) { return i.implementation().shader_pnoise33(p, period); }
sxsdk::vec3 pnoise3 ( const sxsdk::vec2 &p, float z,	const sxsdk::vec3&period ) { return pnoise3(sxsdk::vec3(p.x, p.y, z), period); }
sxsdk::vec3 pnoise3 ( float x, float y, float z, const sxsdk::vec3&period ) { return pnoise3(sxsdk::vec3(x, y, z), period); }
sxsdk::vec3 pnoise3 ( const sxsdk::vec4 &p, const sxsdk::vec4 &period ) { return i.implementation().shader_pnoise34(p, period); }
sxsdk::vec3 pnoise3 ( const sxsdk::vec3&p, float t, const sxsdk::vec4 &period ) { return pnoise3(sxsdk::vec4(p.x, p.y, p.z, t), period); }
sxsdk::vec3 pnoise3 ( const sxsdk::vec2 &p, float z, float t, const sxsdk::vec4 &period ) { return pnoise3(sxsdk::vec4(p.x, p.y, z, t), period); }
sxsdk::vec3 pnoise3 ( float x, float y, float z, float t, const sxsdk::vec4 &period ) { return pnoise3(sxsdk::vec4(x, y, z, t), period); }
sxsdk::vec4 pnoise4 ( float x, float period ) { return i.implementation().shader_pnoise41(x, period); }
sxsdk::vec4 pnoise4 ( const sxsdk::vec2 &p, const sxsdk::vec2 &period ) { return i.implementation().shader_pnoise42(p, period); }
sxsdk::vec4 pnoise4 ( float x, float y, const sxsdk::vec2 &period ) { return pnoise4(sxsdk::vec2(x, y), period); }
sxsdk::vec4 pnoise4 ( const sxsdk::vec3&p,	const sxsdk::vec3&period ) { return i.implementation().shader_pnoise43(p, period); }
sxsdk::vec4 pnoise4 ( const sxsdk::vec2 &p, float z,	const sxsdk::vec3&period ) { return pnoise4(sxsdk::vec3(p.x, p.y, z), period); }
sxsdk::vec4 pnoise4 ( float x, float y, float z, const sxsdk::vec3&period ) { return pnoise4(sxsdk::vec3(x, y, z), period); }
sxsdk::vec4 pnoise4 ( const sxsdk::vec4 &p, const sxsdk::vec4 &period ) { return i.implementation().shader_pnoise44(p, period); }
sxsdk::vec4 pnoise4 ( const sxsdk::vec3&p, float t, const sxsdk::vec4 &period ) { return pnoise4(sxsdk::vec4(p.x, p.y, p.z, t), period); }
sxsdk::vec4 pnoise4 ( const sxsdk::vec2 &p, float z, float t, const sxsdk::vec4 &period ) { return pnoise4(sxsdk::vec4(p.x, p.y, z, t), period); }
sxsdk::vec4 pnoise4 ( float x, float y, float z, float t, const sxsdk::vec4 &period ) { return pnoise4(sxsdk::vec4(x, y, z, t), period); }
float turbulence1 ( sxsdk::vec3 p, int m ) { return i.implementation().shader_turbulence1(p, m ); }
sxsdk::vec3 turbulence3 ( sxsdk::vec3 p, int m ) { return i.implementation().shader_turbulence3(p, m ); } 

		shade_interface &i;
		explicit shader_interface (shade_interface &shade) : i(shade) { }
	};
}
