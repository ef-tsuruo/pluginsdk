#pragma once
SXCORE
#include "sx/core/memory.hpp"
#include "sx/core/simd.hpp"
#include "sx/core/vectors.hpp"
#include "sx/core/debug.hpp"
#include "sx/core/minmax.hpp"
#include "sx/core/endian.hpp"

namespace sx {

	template<typename T> class bounds {
	public: // properties
		const T origin () const {
			return min;
		}
		void origin (const T &origin) {
			const T s = max - min;
			min = origin;
			max = origin + s;
		}
		const T size () const {
			return (max - min);
		}
		void size (const T &size) {
			max = min + size;
		}
		const T center () const {
			return (max + min) / T(2);
		}
		bool empty () const {
			return !(min <= max);
		}
	public:
		T min;
		T max;

		explicit bounds () : min(std::numeric_limits<T>::max()), max(-std::numeric_limits<T>::max()) { }
		template<typename U> bounds (const bounds<U> &c) : min(c.empty() ? std::numeric_limits<T>::max() : T(c.min)), max(c.empty() ? -std::numeric_limits<T>::max() : T(c.max)) { }
		explicit bounds (const T &min, const T &max) : min(min), max(max) {
			SXTEST(sx::check_invariant(*this));
		}
		explicit bounds (const T &max) : min(0), max(max) {
			SXTEST(sx::check_invariant(*this));
		}
		template<typename U> explicit bounds (U minx, U miny, U maxx, U maxy) : min(minx, miny), max(maxx, maxy) {
			SXTEST(sx::check_invariant(*this));
		}
		#if SXIOS || SXMACOSX
			explicit bounds (const CGRect &r) : min(r.origin.x, r.origin.y), max(r.origin.x+r.size.width, r.origin.y+r.size.height) {
			SXTEST(sx::check_invariant(*this));
			}
		#endif
		#if SXMACOSX && !(__LP64__)
			explicit bounds (const NSRect &r) : min(r.origin.x, r.origin.y), max(r.origin.x+r.size.width, r.origin.y+r.size.height) {
			SXTEST(sx::check_invariant(*this));
			}
		#endif
		#if	SXWINDOWS
			explicit bounds (const RECT &r) : min(r.left, r.top), max(r.right, r.bottom) {
			SXTEST(sx::check_invariant(*this));
			}
		#endif
		bounds &operator|= (const T &b) {
			if (!empty()) {
				this->min = sx::min(this->min, b);
				this->max = sx::max(this->max, b);
			}
			else {
				min = max = b;
			}
			return *this;
		}
		bounds &operator|= (const bounds &b) {
			if (!b.empty()) {
				if (!empty()) {
					this->min = sx::min(this->min, b.min);
					this->max = sx::max(this->max, b.max);
				}
				else {
					*this = b;
				}
			}
			return *this;
		}
		void inset (const T &d) {
			min += d;
			max -= d;
		}
		const T &operator[] (bool i) const	{ return (i ? max : min); }
		T &operator[] (bool i)				{ return (i ? max : min); }
		void check_invariant () const {
			sx::check_invariant(min);
			sx::check_invariant(max);
		}

		static bounds empty_bounds () { return bounds(); }
		static bounds max_bounds () { return bounds(-std::numeric_limits<T>::max(), std::numeric_limits<T>::max()); }
	};

	template<> class bounds<sx::vectorx> : public sx::memory::object {
	public: // properties
		sx::vectorx origin () const {
			return min;
		}
		void origin (const sx::vectorx &origin) {
			const sx::vectorx s = (max - min);
			min = origin;
			max = origin + s;
		}
		sx::vectorx size () const {
			return (max - min);
		}
		void size (const sx::vectorx &size) {
			max = min + size;
		}
		sx::vectorx center () const {
			return (max + min) * sx::vectorxt(0.5f);
		}
		bool empty () const {
			return !(sx::le(min, max) == 0x0f);
		}
	public:
		 sx::vectorx min;
		 sx::vectorx max;

		explicit bounds () : min(std::numeric_limits<sx::vectorx>::max()), max(-std::numeric_limits<sx::vectorx>::max()) { }
		template<typename U> bounds (const bounds<U> &c) : min(c.min), max(c.max) { }
		explicit bounds (const sx::vectorx &min, const sx::vectorx &max) : min(min), max(max) {
			SXTEST(sx::check_invariant(*this));
		}
		explicit bounds (const sx::vectorx &max) : min(sx::vzero), max(max) {
			SXTEST(sx::check_invariant(*this));
		}
		bounds &operator|= (const sx::vectorx &b) {
			if (!empty()) {
				this->min = sx::min(this->min, b);
				this->max = sx::max(this->max, b);
			}
			else {
				min = max = b;
			}
			return *this;
		}
		bounds &operator|= (const bounds &b) {
			if (!b.empty()) {
				if (!empty()) {
					this->min = sx::min(this->min, b.min);
					this->max = sx::max(this->max, b.max);
				}
				else {
					*this = b;
				}
			}
			return *this;
		}
		void inset (const sx::vectorx &d) {
			min = (min + d);
			max = (max - d);
		}
		void check_invariant () const {
			sx::check_invariant(min);
			sx::check_invariant(max);
		}

		static bounds empty_bounds () { return bounds(); }
		static bounds max_bounds () { return bounds(-std::numeric_limits<sx::vectorx>::max(), std::numeric_limits<sx::vectorx>::max()); }
	};

	template<> class bounds<sx::vec<sx::vectorx,3> > : public sx::memory::object {
	public: // properties
		const sx::vec<sx::vectorx,3> &origin () const {
			return min;
		}
		void origin (const sx::vec<sx::vectorx,3> &origin) {
			const sx::vec<sx::vectorx,3> s = max - min;
			min = origin;
			max = origin + s;
		}
		sx::vec<sx::vectorx,3> size () const {
			return (max - min);
		}
		void size (const sx::vec<sx::vectorx,3> &size) {
			max = min + size;
		}
		sx::vec<sx::vectorx,3> center () const {
			return (max + min) * sx::vec<sx::vectorx,3>(0.5f);
		}
		bool empty () const {
			return !(min <= max);
		}
	public:
		 sx::vec<sx::vectorx,3> min;
		 sx::vec<sx::vectorx,3> max;

		explicit bounds () : min(std::numeric_limits<sx::vec<sx::vectorx,3> >::max()), max(-std::numeric_limits<sx::vec<sx::vectorx,3> >::max()) { }
		template<typename U> bounds (const bounds<U> &c) : min(c.min), max(c.max) { }
		explicit bounds (const sx::vec<sx::vectorx,3> &min, const sx::vec<sx::vectorx,3> &max) : min(min), max(max) {
			SXTEST(sx::check_invariant(*this));
		}
		explicit bounds (const sx::vec<sx::vectorx,3> &max) : min(0), max(max) {
			SXTEST(sx::check_invariant(*this));
		}
		template<typename U> explicit bounds (U minx, U miny, U maxx, U maxy) : min(minx, miny), max(maxx, maxy) {
			SXTEST(sx::check_invariant(*this));
		}
		bounds &operator|= (const sx::vec<sx::vectorx,3> &b) {
			if (!empty()) {
				this->min.x = sx::min(this->min.x, b.x);
				this->min.y = sx::min(this->min.y, b.y);
				this->min.z = sx::min(this->min.z, b.z);
				this->max.x = sx::max(this->max.x, b.x);
				this->max.y = sx::max(this->max.y, b.y);
				this->max.z = sx::max(this->max.z, b.z);
			}
			else {
				min = max = b;
			}
			return *this;
		}
		bounds &operator|= (const bounds &b) {
			if (!b.empty()) {
				if (!empty()) {
					this->min.x = sx::min(this->min.x, b.min.x);
					this->min.y = sx::min(this->min.y, b.min.y);
					this->min.z = sx::min(this->min.z, b.min.z);
					this->max.x = sx::max(this->max.x, b.max.x);
					this->max.y = sx::max(this->max.y, b.max.y);
					this->max.z = sx::max(this->max.z, b.max.z);
				}
				else {
					*this = b;
				}
			}
			return *this;
		}
		void inset (const sx::vec<sx::vectorx,3> &d) {
			min += d;
			max -= d;
		}
		const sx::vec<sx::vectorx,3> &operator[] (bool i) const	{ return (i ? max : min); }
		sx::vec<sx::vectorx,3> &operator[] (bool i)				{ return (i ? max : min); }
		void check_invariant () const {
			sx::check_invariant(min);
			sx::check_invariant(max);
		}

		static bounds empty_bounds () { return bounds(); }
		static bounds max_bounds () { return bounds(-std::numeric_limits<sx::vec<sx::vectorx,3> >::max(), std::numeric_limits<sx::vec<sx::vectorx,3> >::max()); }
	};
}

template<typename T> inline bool operator== (const sx::bounds<T> &a, const sx::bounds<T> &b) {
	//if (a.empty() || b.empty()) return false;
	if (a.empty() && b.empty()) return true;
	return (a.min == b.min) && (a.max == b.max);
}
template<typename T> inline bool operator!= (const sx::bounds<T> &a, const sx::bounds<T> &b) {
	return !(a == b);
}
template<typename T> inline sx::bounds<T> operator& (const sx::bounds<T> &a, const sx::bounds<T> &b) {
	if (a.empty() || b.empty()) return sx::bounds<T>::empty_bounds();
	return sx::bounds<T>(sx::max(a.min, b.min), sx::min(a.max, b.max));
}
template<typename T> inline sx::bounds<T> &operator&= (sx::bounds<T> &a, const sx::bounds<T> &b) {
	a = a & b;
	return a;
}
template<typename T> inline sx::bounds<T> operator| (const sx::bounds<T> &a, const sx::bounds<T> &b) {
	if (a.empty()) return b;
	if (b.empty()) return a;
	return sx::bounds<T>(sx::min(a.min, b.min), sx::max(a.max, b.max));
}
template<typename T> inline sx::bounds<T> &operator|= (sx::bounds<T> &a, const sx::bounds<T> &b) {
	a = a | b;
	return a;
}
template<typename T> sx::bounds<sx::vec<T,3> > operator* (const sx::bounds<sx::vec<T,3> > &b, const sx::mat<float,4> &t) {
	sx::bounds<sx::vec<T,3> > b2;
	if (!b.empty()) {
		b2 |= (sx::vec<T,3>(b.min.x, b.min.y, b.min.z) * t);
		b2 |= (sx::vec<T,3>(b.min.x, b.min.y, b.max.z) * t);
		b2 |= (sx::vec<T,3>(b.min.x, b.max.y, b.min.z) * t);
		b2 |= (sx::vec<T,3>(b.min.x, b.max.y, b.max.z) * t);
		b2 |= (sx::vec<T,3>(b.max.x, b.min.y, b.min.z) * t);
		b2 |= (sx::vec<T,3>(b.max.x, b.min.y, b.max.z) * t);
		b2 |= (sx::vec<T,3>(b.max.x, b.max.y, b.min.z) * t);
		b2 |= (sx::vec<T,3>(b.max.x, b.max.y, b.max.z) * t);
	}
	return b2;
}
template<typename T> sx::bounds<sx::vec<T,2> > operator* (const sx::bounds<sx::vec<T,2> > &b, const sx::mat<float,4> &t) {
	if (!b.empty()) {
		return sx::bounds<sx::vec<T,2> >(sx::vec<T,2>(sx::vec<float,2>(b.min) * t), sx::vec<T,2>(sx::vec<float,2>(b.max) * t));
	}
	return b;
}
template<typename T> inline sx::bounds<T> &operator*= (sx::bounds<T> &b, const sx::mat<float,4> &t) {
	b = b * t;
	return b;
}
template<typename T> sx::bounds<T> operator* (const sx::bounds<T> &b, const T &t) {
	return sx::bounds<T>(b.min * t, b.max * t);
}
template<typename T> inline sx::bounds<T> &operator*= (sx::bounds<T> &b, const T &t) {
	b = b * t;
	return b;
}
template<typename T> sx::bounds<T> operator+ (const sx::bounds<T> &b, const T &t) {
	return sx::bounds<T>(b.min + t, b.max + t);
}
template<typename T> inline sx::bounds<T> &operator+= (sx::bounds<T> &b, const T &t) {
	b.min += t;
	b.max += t;
	return b;
}
template<typename T> sx::bounds<T> operator- (const sx::bounds<T> &b, const T &t) {
	return sx::bounds<T>(b.min - t, b.max - t);
}
template<typename T> inline sx::bounds<T> &operator-= (sx::bounds<T> &b, const T &t) {
	b.min -= t;
	b.max -= t;
	return b;
}

namespace sx {
	template<int N> inline bool intersect (const sx::bounds<sx::vec<float,N> > &a, const sx::bounds<sx::vec<float,N> > &b) {
		if (a.empty() || b.empty()) return false;
		for (int i = 0; i < N; ++i) {
			if (a.max[i] < b.min[i]) return false;
			if (b.max[i] < a.min[i]) return false;
		}
		return true;
	}
	template<typename T, int N> inline bool intersect (const sx::bounds<sx::vec<float,N> > &a, const sx::vec<T,N> &b) {
		if (a.empty()) return false;
		return (a.min <= b) && (b <= a.max);
	}
	template<typename T, int N> inline bool intersect (const sx::bounds<sx::vec<int,N> > &a, const sx::vec<T,N> &b) {
		if (a.empty()) return false;
		return (a.min <= b) && (b < (a.max));
	}
	template<typename T> inline bool is_in (const sx::bounds<T> &a, const sx::bounds<T> &b) {
		if (a.empty()) return true;
		if (b.empty()) return false;
		return ((a.min <= b.min) && (b.max <= a.max));
	}

	template<int N> inline bool intersect (const sx::bounds<sx::vec<int,N> > &a, const sx::bounds<sx::vec<int,N> > &b) {
		if (a.empty() || b.empty()) return false;
		for (int i = 0; i < N; ++i) {
			if (a.max[i] <= b.min[i]) return false;
			if (b.max[i] <= a.min[i]) return false;
		}
		return true;
	}
	#if SXIOS || SXMACOSX
		template<typename T> CGRect cgrect (const sx::bounds<sx::vec<T,2> > &b) {
			return CGRectMake(b.min.x, b.min.y, b.size().x, b.size().y);
		}
	#endif
	#if SXMACOSX
		template<typename T> NSRect nsrect (const sx::bounds<sx::vec<T,2> > &b) {
			return NSMakeRect(b.min.x, b.min.y, b.size().x, b.size().y);
		}
	#endif
	#if SXWINDOWS
		template<typename T> RECT msrect (const sx::bounds<sx::vec<T,2> > &b) {
			RECT r; r.left = b.min.x; r.top = b.min.y; r.right = b.max.x; r.bottom = b.max.y;
			return r;
		}
	#endif
	template<typename T> const sx::bounds<T> inset (const sx::bounds<T> &b, const T &d) {
		return sx::bounds<T>(b.min + d, b.max - d);
	}
	
	typedef sx::bounds<sx::vec<int,2> > rectangle_class;

	template<typename T> sx::bounds<T> &revert_endian (bounds<T> &b) {
		sx::revert_endian(b.min);
		sx::revert_endian(b.max);
		return b;
	}
	
	template<typename T> bool isnan (const bounds<T> &b) {
		return (sx::isnan(b.min) || sx::isnan(b.max));
	}
	template<typename T> bool is_finite (const bounds<T> &b) {
		return (sx::is_finite(b.min) && sx::is_finite(b.max));
	}
}
template<typename T> std::istream &operator> (std::istream &stream, sx::bounds<T> &b) {
	stream > b.min > b.max;
	return stream;
}
template<typename T> std::ostream &operator< (std::ostream &stream, const sx::bounds<T> &b) {
	stream < b.min < b.max;
	return stream;
}
template<typename T> std::ostream &operator<< (std::ostream &stream, const sx::bounds<T> &b) {
	if (!b.empty())	stream << "min:" << b.min << " " << "max:" << b.max;
	else			stream << "void";
	return stream;
}

namespace sx {
	namespace core {
		namespace unittest {
			void test_bounds ();
		}
	}
}
