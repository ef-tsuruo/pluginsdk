#pragma once

namespace sxsdk {
	class renderer_interface : public exporter_interface {
	public:
	virtual void begin_rendering (rendering_context_interface* rendering_context, stream_interface* stream, void* aux = 0) { }  // 0
	virtual void ask (stream_interface* stream, void* aux = 0) { }  // 1
	virtual void render ( void* aux =0 ) { }  // 2
	virtual void end_rendering ( void* aux =0 ) { }  // 3
	virtual bool accepts_walkthrough ( void* aux =0 ) { return false; }  // 4
	virtual void walkthrough (sxsdk::scene_interface* scene, camera_interface* camera, sxsdk::image_interface* image, rendering_context_interface* rc, stream_interface* stream, void* aux = 0) { }  // 5
	virtual bool uses_surface_division_level ( void* aux =0 ) { return false; }  // 6
	virtual bool uses_shading_type ( void* aux =0 ) { return false; }  // 7
	virtual bool uses_antialiasing ( void* aux =0 ) { return false; }  // 8
	virtual bool uses_show_background ( void* aux =0 ) { return false; }  // 9
	virtual bool uses_reflect_background ( void* aux =0 ) { return false; }  // 10
	virtual bool uses_show_shadow ( void* aux =0 ) { return false; }  // 11
	virtual bool uses_sideways ( void* aux =0 ) { return false; }  // 12
	virtual bool uses_panorama ( void* aux =0 ) { return false; }  // 13
	virtual bool uses_radiosity ( void* aux =0 ) { return false; }  // 14
	virtual bool uses_premultiplied_pixel ( void* aux =0 ) { return false; }  // 15
	virtual bool uses_number_of_threads ( void* aux =0 ) { return false; }  // 16
	virtual bool uses_transparency_affects_alpha ( void* aux =0 ) { return false; }  // 17
	virtual bool uses_render_transparency ( void* aux =0 ) { return false; }  // 18
	virtual bool uses_single_sided_face ( void* aux =0 ) { return false; }  // 19
	virtual bool uses_z ( void* aux =0 ) { return false; }  // 20
	virtual bool uses_real_color ( void* aux =0 ) { return false; }  // 21
	virtual bool uses_rendering_servers ( void* aux =0 ) { return false; }  // 22
	virtual bool uses_over_sampling ( void* aux =0 ) { return false; }  // 23
	virtual bool uses_ray_cast_level ( void* aux =0 ) { return false; }  // 24
	virtual bool uses_ray_tracing_quality ( void* aux =0 ) { return false; }  // 25
	virtual bool uses_ray_tracing_delta ( void* aux =0 ) { return false; }  // 26
	virtual bool uses_fisheye_distortion ( void* aux =0 ) { return false; }  // 27
	virtual bool uses_shadow_type ( void* aux =0 ) { return false; }  // 28
	virtual bool uses_correction ( void* aux =0 ) { return false; }  // 29
	virtual bool uses_shadowmap ( void* aux =0 ) { return false; }  // 30
	virtual bool needs_z ( void* aux =0 ) { return false; }  // 31
	virtual bool needs_real_color ( void* aux =0 ) { return false; }  // 32
	virtual bool can_ask ( void* aux =0 ) { return false; }  // 33
	virtual bool uses_motion_blur ( void* aux =0 ) { return false; }  // 34
	virtual bool uses_global_illumination ( void* aux =0 ) { return false; }  // 35
	virtual bool must_clear_image ( void* aux =0 ) { return true; }  // 36
	virtual bool uses_ray_offset ( void* aux =0 ) { return false; }  // 37
	virtual bool uses_multipass_rendering ( void* aux =0 ) { return false; }  // 38
	virtual bool uses_multipass_layer_obsoleted (scene_interface& scene, const sx::uuid_class& layer_uuid, void* aux = 0) { return false; }  // 39
	virtual bool get_multipass_layer_obsoleted (int index, sx::uuid_class& layer_uuid, image_layer_interface& layer, void* aux = 0) { return false; }  // 40
	virtual bool uses_multipass_layer (scene_interface& scene, const char* id_name, void* aux = 0) { return false; }  // 41
	virtual bool uses_multipass_custom_layer (scene_interface& scene, const sx::uuid_class& layer_uuid, const char* id_name, void* aux = 0) { return false; }  // 42
	virtual bool get_multipass_layer (int index, sx::uuid_class& layer_uuid, image_layer_interface& layer, void* aux = 0) { return false; }  // 43
	virtual bool uses_maximum_distance ( void* aux =0 ) { return false; }  // 44
	virtual bool uses_no_antialiasing_data_paths ( void* aux =0 ) { return false; }  // 45
	virtual int renderer_interface_dummy46(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 46
	virtual int renderer_interface_dummy47(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 47
	virtual int renderer_interface_dummy48(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 48
	virtual int renderer_interface_dummy49(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 49
	virtual int renderer_interface_dummy50(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 50
	virtual int renderer_interface_dummy51(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 51
	virtual int renderer_interface_dummy52(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 52
	virtual int renderer_interface_dummy53(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 53
	virtual int renderer_interface_dummy54(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 54
	virtual int renderer_interface_dummy55(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 55
	virtual int renderer_interface_dummy56(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 56
	virtual int renderer_interface_dummy57(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 57
	virtual int renderer_interface_dummy58(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 58
	virtual int renderer_interface_dummy59(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 59
	virtual int renderer_interface_dummy60(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 60
	virtual int renderer_interface_dummy61(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 61
	virtual int renderer_interface_dummy62(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 62
	virtual int renderer_interface_dummy63(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 63
	virtual int renderer_interface_dummy64(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 64
	virtual int renderer_interface_dummy65(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 65
	virtual int renderer_interface_dummy66(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 66
	virtual int renderer_interface_dummy67(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 67
	virtual int renderer_interface_dummy68(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 68
	virtual int renderer_interface_dummy69(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 69
	virtual int renderer_interface_dummy70(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 70
	virtual int renderer_interface_dummy71(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 71
	virtual int renderer_interface_dummy72(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 72
	virtual int renderer_interface_dummy73(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 73
	virtual int renderer_interface_dummy74(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 74
	virtual int renderer_interface_dummy75(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 75
	virtual int renderer_interface_dummy76(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 76
	virtual int renderer_interface_dummy77(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 77
	virtual int renderer_interface_dummy78(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 78
	virtual int renderer_interface_dummy79(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 79
	virtual int renderer_interface_dummy80(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 80
	virtual int renderer_interface_dummy81(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 81
	virtual int renderer_interface_dummy82(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 82
	virtual int renderer_interface_dummy83(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 83
	virtual int renderer_interface_dummy84(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 84
	virtual int renderer_interface_dummy85(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 85
	virtual int renderer_interface_dummy86(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 86
	virtual int renderer_interface_dummy87(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 87
	virtual int renderer_interface_dummy88(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 88
	virtual int renderer_interface_dummy89(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 89
	virtual int renderer_interface_dummy90(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 90
	virtual int renderer_interface_dummy91(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 91
	virtual int renderer_interface_dummy92(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 92
	virtual int renderer_interface_dummy93(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 93
	virtual int renderer_interface_dummy94(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 94
	virtual int renderer_interface_dummy95(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 95
	virtual int renderer_interface_dummy96(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 96
	virtual int renderer_interface_dummy97(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 97
	virtual int renderer_interface_dummy98(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 98
	virtual int renderer_interface_dummy99(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 99
	virtual int renderer_interface_dummy100(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 100
	virtual int renderer_interface_dummy101(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 101
	virtual int renderer_interface_dummy102(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 102
	virtual int renderer_interface_dummy103(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 103
	virtual int renderer_interface_dummy104(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 104
	virtual int renderer_interface_dummy105(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 105
	virtual int renderer_interface_dummy106(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 106
	virtual int renderer_interface_dummy107(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 107
	virtual int renderer_interface_dummy108(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 108
	virtual int renderer_interface_dummy109(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 109
	virtual int renderer_interface_dummy110(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 110
	virtual int renderer_interface_dummy111(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 111
	virtual int renderer_interface_dummy112(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 112
	virtual int renderer_interface_dummy113(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 113
	virtual int renderer_interface_dummy114(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 114
	virtual int renderer_interface_dummy115(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 115
	virtual int renderer_interface_dummy116(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 116
	virtual int renderer_interface_dummy117(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 117
	virtual int renderer_interface_dummy118(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 118
	virtual int renderer_interface_dummy119(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 119
	virtual int renderer_interface_dummy120(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 120
	virtual int renderer_interface_dummy121(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 121
	virtual int renderer_interface_dummy122(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 122
	virtual int renderer_interface_dummy123(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 123
	virtual int renderer_interface_dummy124(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 124
	virtual int renderer_interface_dummy125(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 125
	virtual int renderer_interface_dummy126(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 126
	virtual int renderer_interface_dummy127(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 127
	virtual int renderer_interface_dummy128(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 128
	virtual int renderer_interface_dummy129(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 129
	virtual int renderer_interface_dummy130(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 130
	virtual int renderer_interface_dummy131(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 131
	virtual int renderer_interface_dummy132(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 132
	virtual int renderer_interface_dummy133(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 133
	virtual int renderer_interface_dummy134(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 134
	virtual int renderer_interface_dummy135(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 135
	virtual int renderer_interface_dummy136(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 136
	virtual int renderer_interface_dummy137(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 137
	virtual int renderer_interface_dummy138(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 138
	virtual int renderer_interface_dummy139(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 139
	virtual int renderer_interface_dummy140(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 140
	virtual int renderer_interface_dummy141(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 141
	virtual int renderer_interface_dummy142(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 142
	virtual int renderer_interface_dummy143(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 143
	virtual int renderer_interface_dummy144(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 144
	virtual int renderer_interface_dummy145(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 145
	virtual int renderer_interface_dummy146(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 146
	virtual int renderer_interface_dummy147(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 147
	virtual int renderer_interface_dummy148(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 148
	virtual int renderer_interface_dummy149(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 149
	virtual int renderer_interface_dummy150(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 150
	virtual int renderer_interface_dummy151(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 151
	virtual int renderer_interface_dummy152(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 152
	virtual int renderer_interface_dummy153(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 153
	virtual int renderer_interface_dummy154(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 154
	virtual int renderer_interface_dummy155(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 155
	virtual int renderer_interface_dummy156(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 156
	virtual int renderer_interface_dummy157(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 157
	virtual int renderer_interface_dummy158(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 158
	virtual int renderer_interface_dummy159(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 159
	virtual int renderer_interface_dummy160(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 160
	virtual int renderer_interface_dummy161(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 161
	virtual int renderer_interface_dummy162(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 162
	virtual int renderer_interface_dummy163(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 163
	virtual int renderer_interface_dummy164(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 164
	virtual int renderer_interface_dummy165(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 165
	virtual int renderer_interface_dummy166(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 166
	virtual int renderer_interface_dummy167(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 167
	virtual int renderer_interface_dummy168(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 168
	virtual int renderer_interface_dummy169(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 169
	virtual int renderer_interface_dummy170(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 170
	virtual int renderer_interface_dummy171(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 171
	virtual int renderer_interface_dummy172(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 172
	virtual int renderer_interface_dummy173(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 173
	virtual int renderer_interface_dummy174(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 174
	virtual int renderer_interface_dummy175(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 175
	virtual int renderer_interface_dummy176(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 176
	virtual int renderer_interface_dummy177(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 177
	virtual int renderer_interface_dummy178(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 178
	virtual int renderer_interface_dummy179(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 179
	virtual int renderer_interface_dummy180(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 180
	virtual int renderer_interface_dummy181(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 181
	virtual int renderer_interface_dummy182(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 182
	virtual int renderer_interface_dummy183(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 183
	virtual int renderer_interface_dummy184(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 184
	virtual int renderer_interface_dummy185(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 185
	virtual int renderer_interface_dummy186(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 186
	virtual int renderer_interface_dummy187(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 187
	virtual int renderer_interface_dummy188(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 188
	virtual int renderer_interface_dummy189(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 189
	virtual int renderer_interface_dummy190(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 190
	virtual int renderer_interface_dummy191(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 191
	virtual int renderer_interface_dummy192(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 192
	virtual int renderer_interface_dummy193(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 193
	virtual int renderer_interface_dummy194(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 194
	virtual int renderer_interface_dummy195(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 195
	virtual int renderer_interface_dummy196(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 196
	virtual int renderer_interface_dummy197(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 197
	virtual int renderer_interface_dummy198(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 198
	virtual int renderer_interface_dummy199(void *) { assert(false); throw "invalid interface renderer_interface"; return 0; } // 199
	};
}
