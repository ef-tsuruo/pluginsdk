#pragma once

namespace sxsdk {
	class correction_interface : public shade_interface {
	public:
	virtual void save (const char*const& in, void * aux = 0) = 0; // 0
	virtual void load (const char*const& from, void * aux = 0) = 0; // 1
	virtual correction_interface &set_gain (float gain_param, void * = 0) = 0; // 2
	virtual float get_gain (void * = 0) const = 0; // 3
	virtual correction_interface &set_gamma (float gamma_param, void * = 0) = 0; // 4
	virtual float get_gamma (void * = 0) const = 0; // 5
	virtual correction_interface &set_contrast (float contrast_param, void * = 0) = 0; // 6
	virtual float get_contrast (void * = 0) const = 0; // 7
	virtual correction_interface &set_highlight_hue (float highlight_hue_param, void * = 0) = 0; // 8
	virtual float get_highlight_hue (void * = 0) const = 0; // 9
	virtual correction_interface &set_highlight_saturation (float highlight_saturation_param, void * = 0) = 0; // 10
	virtual float get_highlight_saturation (void * = 0) const = 0; // 11
	virtual correction_interface &set_mid_hue (float mid_hue_param, void * = 0) = 0; // 12
	virtual float get_mid_hue (void * = 0) const = 0; // 13
	virtual correction_interface &set_mid_saturation (float mid_saturation_param, void * = 0) = 0; // 14
	virtual float get_mid_saturation (void * = 0) const = 0; // 15
	virtual correction_interface &set_shadow_hue (float shadow_hue_param, void * = 0) = 0; // 16
	virtual float get_shadow_hue (void * = 0) const = 0; // 17
	virtual correction_interface &set_shadow_saturation (float shadow_saturation_param, void * = 0) = 0; // 18
	virtual float get_shadow_saturation (void * = 0) const = 0; // 19
	virtual correction_interface &set_color_shift (float color_shift_param, void * = 0) = 0; // 20
	virtual float get_color_shift (void * = 0) const = 0; // 21
	virtual correction_interface &set_bias (float bias_param, void * = 0) = 0; // 22
	virtual float get_bias (void * = 0) const = 0; // 23
	virtual sxsdk::rgb_class correct (const sxsdk::rgb_class& color, void * aux = 0) = 0; // 24
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 25
	};
}
