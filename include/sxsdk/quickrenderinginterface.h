#pragma once

namespace sxsdk {
	class quickrendering_interface : public shade_interface {
	public:
	virtual quickrendering_interface &set_show_side_view (bool show_side_view_param, void * = 0) = 0; // 0
	virtual bool get_show_side_view (void * = 0) const = 0; // 1
	virtual quickrendering_interface &set_show_top_view (bool show_top_view_param, void * = 0) = 0; // 2
	virtual bool get_show_top_view (void * = 0) const = 0; // 3
	virtual quickrendering_interface &set_show_front_view (bool show_front_view_param, void * = 0) = 0; // 4
	virtual bool get_show_front_view (void * = 0) const = 0; // 5
	virtual quickrendering_interface &set_show_pers_view (bool show_pers_view_param, void * = 0) = 0; // 6
	virtual bool get_show_pers_view (void * = 0) const = 0; // 7
	virtual quickrendering_interface &set_wireframe (bool wireframe_param, void * = 0) = 0; // 8
	virtual bool get_wireframe (void * = 0) const = 0; // 9
	virtual quickrendering_interface &set_smooth_shading (bool smooth_shading_param, void * = 0) = 0; // 10
	virtual bool get_smooth_shading (void * = 0) const = 0; // 11
	virtual quickrendering_interface &set_singlesided (bool singlesided_param, void * = 0) = 0; // 12
	virtual bool get_singlesided (void * = 0) const = 0; // 13
	virtual void update_texture (void* aux = 0) = 0; // 14
	virtual void clear_texture (void* aux = 0) = 0; // 15
	virtual quickrendering_interface &set_abort (float abort_param, void * = 0) = 0; // 16
	virtual float get_abort (void * = 0) const = 0; // 17
	virtual quickrendering_interface &set_random_texture (bool random_texture_param, void * = 0) = 0; // 18
	virtual bool get_random_texture (void * = 0) const = 0; // 19
	virtual int get_total_texture_size (void * = 0) const = 0; // 20
	virtual int quickrendering_interface_test_1 ( void* aux =0 ) { return 1; } // 21
	virtual void clear_cache (void* aux = 0) = 0; // 22
	virtual quickrendering_interface &set_all_lights (bool all_lights_param, void * = 0) = 0; // 23
	virtual bool get_all_lights (void * = 0) const = 0; // 24
	virtual quickrendering_interface &set_texture_size (int texture_size_param, void * = 0) = 0; // 25
	virtual int get_texture_size (void * = 0) const = 0; // 26
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 27
	};
}
