#pragma once

namespace sxsdk {
	class fog_interface : public shade_interface {
	public:
	virtual fog_interface &set_thickness (float thickness_param, void * = 0); fog_interface &set_fog (float thickness_param) { return set_thickness(thickness_param); }  // 0
	virtual float get_thickness (void * = 0) const; float get_fog() const { return get_thickness(); }  // 1
	virtual fog_interface &set_color (const sxsdk::rgb_class &color_param, void * = 0); fog_interface &set_fog_color (const sxsdk::rgb_class &color_param) { return set_color(color_param); }  // 2
	virtual sxsdk::rgb_class get_color (void * = 0) const; sxsdk::rgb_class get_fog_color() const { return get_color(); }  // 3
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 4
	};
}
