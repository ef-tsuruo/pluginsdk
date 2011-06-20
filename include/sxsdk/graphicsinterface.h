#pragma once

namespace sxsdk {
	class graphics_interface : public plugin_interface {
	public:
	virtual void line (const sx::vec<float,3>& p0, const sx::vec<float,3>& p1, void* aux = 0) { } // -1
	};
}
