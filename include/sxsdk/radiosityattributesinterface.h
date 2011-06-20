#pragma once

namespace sxsdk {
	class radiosity_attributes_interface : public unknown_interface {
	public:
	virtual int get_shooter (void * = 0) const = 0; // 0
	virtual radiosity_attributes_interface &set_shooter (int shooter_param, void * = 0) = 0; // 1
	virtual int get_receiver (void * = 0) const = 0; // 2
	virtual radiosity_attributes_interface &set_receiver (int receiver_param, void * = 0) = 0; // 3
	virtual int get_cast_shadow (void * = 0) const = 0; // 4
	virtual radiosity_attributes_interface &set_cast_shadow (int cast_shadow_param, void * = 0) = 0; // 5
	virtual int get_doublesided (void * = 0) const = 0; // 6
	virtual radiosity_attributes_interface &set_doublesided (int doublesided_param, void * = 0) = 0; // 7
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 8
	};
}
