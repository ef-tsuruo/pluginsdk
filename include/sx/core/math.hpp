#pragma once
SXCORE
#include "sx/core/unittest.hpp"
#include <limits>
#include <exception>

namespace sx {
	static const float pi = 3.14159265358979323846f;
	static const float epsilon = 0.0002f;
	static const float denormalized_min = 1e-37f;	// note that _mm_rsqrt_ps(scalarx(1e-38)) returns #INF.
	static const float denormalized_max = 1e+37f;	// note that _mm_cmple_ps(std::numeric_limits<float>::min(), v) returns 0. (std::numeric_limits<float>::min() == -1e+38)
	inline int iround (float x) {
		return (0.0f <= x) ? int(x+0.5f) : int(x-0.5f);
	}
	inline double pow (double a, double b) { // approximation. see http://martin.ankerl.com/2007/10/04/optimized-pow-approximation-for-java-and-c-c/
//		int tmp = (*(1 + (int *)&a));
//		int tmp2 = (int)(b * (tmp - 1072632447) + 1072632447);
//		double p = 0.0;
//		*(1 + (int * )&p) = tmp2;
//		return p; 

		// use union to avoid strict aliasing violation
		BOOST_STATIC_ASSERT(sizeof(double) == sizeof(sx::unsigned64));
		union {
			double			d;
			sx::unsigned64	i;
		} u;
		u.d = a;
		const int x = int(u.i >> 32);
		const int y = int(b * (x - 1072632447) + 1072632447);
		u.i = (long long)(y) << 32;
		return u.d;
	}

	/// operation with overflow check.
	template<typename T, typename EXCEPTION = std::exception> class safe_math_template {
		T a;
	public:
		explicit safe_math_template (const T &a) : a(a) { }

		const bool is_positive () const	{ return !(std::numeric_limits<T>::is_signed && a < T(0)); }
		const bool less_one () const	{ return (!std::numeric_limits<T>::is_integer && (!std::numeric_limits<T>::is_signed || T(-1) < a) && a < T(1)); }

		const T &get () const	{ return a; }
		const T abs () const	{ return (is_positive() ? a : (T(0) - a)); }

		const safe_math_template operator+ (const safe_math_template &t) const {
			const T &b = t.get();
			if ((t.is_positive() && std::numeric_limits<T>::max() - b < a) || (!t.is_positive() && a < std::numeric_limits<T>::min() - b)) throw EXCEPTION();
			return safe_math_template(a + b);
		}
		const safe_math_template operator- (const safe_math_template &t) const {
			const T &b = t.get();
			if ((t.is_positive() && a < std::numeric_limits<T>::min() + b) || (!t.is_positive() && std::numeric_limits<T>::max() + b < a)) throw EXCEPTION();
			return safe_math_template(a - b);
		}
		const safe_math_template operator* (const safe_math_template &t) const {
			if (!t.less_one() && (std::numeric_limits<T>::max() / t.abs() < abs())) throw EXCEPTION();
			return safe_math_template(a * t.get());
		}
		const safe_math_template operator/ (const safe_math_template &t) const {
			if (t.less_one() && (std::numeric_limits<T>::max() * t.abs() < abs())) throw EXCEPTION();
			return safe_math_template(a / t.get());
		}
	};
	
	// std::isnan on ARM seems to be broken. VC++ doesn't even have std::isnan. comparing to itself may not work when IEEE adherence is relaxed.
	inline bool isnan (const float &f) {
		BOOST_STATIC_ASSERT(sizeof(float) == sizeof(unsigned));
		return (0x7f800000 < (*(unsigned *)(&f) & 0x7fffffff));
	}
	inline bool isnan (const double &d) {
		BOOST_STATIC_ASSERT(sizeof(double) == sizeof(long long unsigned));
		return (0x7ff0000000000000uLL < (*(unsigned long long *)(&d) & 0x7fffffffffffffffuLL));
	}
	template<typename T> bool is_finite (const T &t) {
		const T max(std::numeric_limits<T>::max());
		return ((-max <= t) && (t <= max));
	}
	inline bool isnormal (const float &f) {
		return (f < -denormalized_min || denormalized_min < f || f == 0.0f);
	}
	inline bool isnormal (const double &d) {
		return (d < -DBL_MIN || DBL_MIN < d || d == 0.0);
	}
}

namespace sx {
	namespace core {
		namespace unittest {
			inline void test_math () {
				SXUNITTEST(sx::isnan(std::numeric_limits<float>::signaling_NaN()));
				SXUNITTEST(sx::isnan(std::numeric_limits<float>::quiet_NaN()));
				SXUNITTEST(sx::isnan(std::numeric_limits<double>::signaling_NaN()));
				SXUNITTEST(sx::isnan(std::numeric_limits<double>::quiet_NaN()));

				SXUNITTEST(sx::isnormal(sx::epsilon));
				SXUNITTEST(!sx::isnormal(std::numeric_limits<float>::denorm_min()));
				SXUNITTEST(sx::isnormal(double(sx::denormalized_min)));
				SXUNITTEST(sx::isnormal(double(std::numeric_limits<float>::denorm_min())));
				SXUNITTEST(!sx::isnormal(std::numeric_limits<double>::denorm_min()));
			}
		}
	}
}
