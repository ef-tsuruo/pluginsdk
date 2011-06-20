#pragma once

namespace sxsdk {
	class points_interface : public shade_interface {
	public:
	virtual int get_n (void * = 0) const = 0; // 0
	virtual sxsdk::vec3& operator[] (int i) = 0; // 1
	};
}
