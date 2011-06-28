#pragma once
SXCORE
#include "sx/core/vectors.hpp"

#if SXSIMD
	#if __ARM_NEON__
		#include "arm_neon.h"
	#else // only NEON and SSE are supported now, and if not NEON, SSE is assumed.
		#include <xmmintrin.h>
		#if __GNUG__ || (1400 < _MSC_VER)
			#include <pmmintrin.h>
		#endif
	#endif
#endif

#if SXSIMD
	#if __ARM_NEON__
		typedef float32x4_t __m128;
	#endif
#else
	typedef std::array<float,4> __m128;
#endif

namespace sx {
	BOOST_STATIC_ASSERT(sizeof(float) == sizeof(int));
	// use union to avoid stritct aliasing violation
	union __m128_union {
		__m128					m;
		std::array<float,4>		f;
		std::array<int,4>		i;
		
	};
	typedef __m128 vectorx;
	typedef __m128 scalarx;
	typedef std::array<vectorx,4> matrixx;

	inline bool is_aligned (const void *const p) {
		#if SXSIMD && !__ARM_NEON__
			return (unsigned64(p) & 0x0000000f) == 0;
		#else
			return true;
		#endif
	}
	#if SXSIMD
		#if __ARM_NEON__
			inline const __m128 _mm_set_ps1 (const float f) {
				return vdupq_n_f32(f);
			}
			inline const __m128 _mm_setr_ps (const float x, const float y, const float z, const float w) {
				__m128 v;
				return vsetq_lane_f32(w, vsetq_lane_f32(z, vsetq_lane_f32(y, vsetq_lane_f32(x, v, 0), 1), 2), 3);
			}
			inline const __m128 _mm_set_ss (const float f) {
				return vsetq_lane_f32(f, vdupq_n_f32(0.0f), 0);
			}
			inline const __m128 _mm_loadu_ps (const float const *p) {
				return _mm_setr_ps(p[0], p[1], p[2], p[3]);
			}
			inline const __m128 _mm_mul_ps (const __m128 &a, const __m128 &b) {
				return vmulq_f32(a, b);
			}
			inline const __m128 _mm_mul_ss (const __m128 &a, const __m128 &b) {
				return vsetq_lane_f32(vgetq_lane_f32(a,0)*vgetq_lane_f32(b,0), a, 0);
			}
			inline const __m128 _mm_add_ps (const __m128 &a, const __m128 &b) {
				return vaddq_f32(a, b);
			}
			inline const __m128 _mm_add_ss (const __m128 &a, const __m128 &b) {
				return vsetq_lane_f32(vgetq_lane_f32(a,0)+vgetq_lane_f32(b,0), a, 0);
			}
			inline const __m128 _mm_sub_ps (const __m128 &a, const __m128 &b) {
				return vsubq_f32(a, b);
			}
			inline const __m128 _mm_sub_ss (const __m128 &a, const __m128 &b) {
				return vsetq_lane_f32(vgetq_lane_f32(a,0)-vgetq_lane_f32(b,0), a, 0);
			}
			const vectorx rsqrt (const vectorx &v);
			const vectorx rsqrts (const scalarx &v);
			const vectorx rcp (const vectorx &a);
			const vectorx rcps (const scalarx &a);
			inline const __m128 _mm_sqrt_ps (const __m128 &v_) {
				return rcp(rsqrt(v_));
			}
			inline const __m128 _mm_sqrt_ss (const __m128 &v_) {
				return rcps(rsqrts(v_));
			}
			inline const __m128 _mm_min_ps (const __m128 &a, const __m128 &b) {
				return vminq_f32(a, b);
			}
			inline const __m128 _mm_min_ss (const __m128 &a, const __m128 &b) {
				return (vgetq_lane_f32(a,0) < vgetq_lane_f32(b,0)) ? vsetq_lane_f32(vgetq_lane_f32(a,0), a, 0) : vsetq_lane_f32(vgetq_lane_f32(b,0), a, 0);
			}

			inline const __m128 _mm_max_ps (const __m128 &a, const __m128 &b) {
				return vmaxq_f32(a, b);
			}
			inline const __m128 _mm_max_ss (const __m128 &a, const __m128 &b) {
				return (vgetq_lane_f32(a,0) < vgetq_lane_f32(b,0)) ? vsetq_lane_f32(vgetq_lane_f32(b,0), a, 0) : vsetq_lane_f32(vgetq_lane_f32(a,0), a, 0);
			}

			inline const __m128 _mm_cmplt_ps (const __m128 &a, const __m128 &b) {
				return __m128(vcltq_f32(a, b));
			}
			inline const __m128 _mm_cmple_ps (const __m128 &a, const __m128 &b) {
				return __m128(vcleq_f32(a, b));
			}
			inline const __m128 _mm_cmpeq_ps (const __m128 &a, const __m128 &b) {
				return __m128(vceqq_f32(a, b));
			}
			inline const __m128 _mm_and_ps (const __m128 &a, const __m128 &b) {
				return __m128(vandq_u32(uint32x4_t(a), uint32x4_t(b)));
			}
			inline const __m128 _mm_or_ps (const __m128 &a, const __m128 &b) {
				return __m128(vorrq_u32(uint32x4_t(a), uint32x4_t(b)));
			}
			inline const __m128 _mm_andnot_ps (const __m128 &a, const __m128 &b) {
				return __m128(vandq_u32(vmvnq_u32(uint32x4_t(a)), uint32x4_t(b)));
			}
			inline const int _mm_movemask_ps (const __m128 &a) {
				return (((vgetq_lane_s32(int32x4_t(a),0) & 0x80000000) >> 31) | ((vgetq_lane_s32(int32x4_t(a),1) & 0x80000000) >> 30) | ((vgetq_lane_s32(int32x4_t(a),2) & 0x80000000) >> 29) | ((vgetq_lane_s32(int32x4_t(a),3) & 0x80000000) >> 28));
			}

			inline const __m128 _mm_cmplt_ss (const __m128 &a, const __m128 &b) {
				return __m128(vsetq_lane_u32((vgetq_lane_f32(a,0) < vgetq_lane_f32(b,0)) ? 0xffffffff : 0x00000000, int32x4_t(a), 0));
			}
			inline const __m128 _mm_cmple_ss (const __m128 &a, const __m128 &b) {
				return __m128(vsetq_lane_u32((vgetq_lane_f32(a,0) <= vgetq_lane_f32(b,0)) ? 0xffffffff : 0x00000000, int32x4_t(a), 0));
			}
			inline const __m128 _mm_cmpeq_ss (const __m128 &a, const __m128 &b) {
				return __m128(vsetq_lane_u32((vgetq_lane_f32(a,0) == vgetq_lane_f32(b,0)) ? 0xffffffff : 0x00000000, int32x4_t(a), 0));
			}
		#endif
	#else
		inline const __m128 _mm_set_ps1 (const float f) {
			vectorx v; v[0] = v[1] = v[2] = v[3] = f; return v;
		}
		inline const __m128 _mm_setr_ps (const float x, const float y, const float z, const float w) {
			vectorx v; v[0] = x; v[1] = y; v[2] = z; v[3] = w; return v;
		}
		inline const __m128 _mm_set_ss (const float f) {
			vectorx v; v[0] = f; v[1] = v[2] = v[3] = 0.0f; return v;
		}
		inline const __m128 _mm_loadu_ps (const float const *p) {
			vectorx v; v[0] = p[0]; v[1] = p[1]; v[2] = p[2]; v[3] = p[3]; return v;
		}
		inline const __m128 _mm_mul_ps (const __m128 &a, const __m128 &b) {
			vectorx v; for (int i = 0; i < 4; ++i) v[i] = a[i] * b[i]; return v;
		}
		inline const __m128 _mm_mul_ss (const __m128 &a, const __m128 &b) {
			scalarx v; v[0] = a[0] * b[0]; for (int i = 1; i < 4; ++i) v[i] = a[i]; return v;
		}
		inline const __m128 _mm_add_ps (const __m128 &a, const __m128 &b) {
			vectorx v; for (int i = 0; i < 4; ++i) v[i] = a[i] + b[i]; return v;
		}
		inline const __m128 _mm_add_ss (const __m128 &a, const __m128 &b) {
			scalarx v; v[0] = a[0] + b[0]; for (int i = 1; i < 4; ++i) v[i] = a[i]; return v;
		}
		inline const __m128 _mm_sub_ps (const __m128 &a, const __m128 &b) {
			vectorx v; for (int i = 0; i < 4; ++i) v[i] = a[i] - b[i]; return v;
		}
		inline const __m128 _mm_sub_ss (const __m128 &a, const __m128 &b) {
			scalarx v; v[0] = a[0] - b[0]; for (int i = 1; i < 4; ++i) v[i] = a[i]; return v;
		}
		inline const __m128 _mm_sqrt_ps (const __m128 &v) {
			vectorx u; for (int i = 0; i < 4; ++i) u[i] = std::sqrt(v[i]); return u;
		}
		inline const __m128 _mm_sqrt_ss (const __m128 &v) {
			vectorx u; u[0] = std::sqrt(v[0]); for (int i = 1; i < 4; ++i) u[i] = v[i]; return u;
		}
		inline const __m128 _mm_min_ps (const __m128 &a, const __m128 &b) {
			vectorx u; for (int i = 0; i < 4; ++i) u[i] = std::min(a[i], b[i]); return u;
		}
		inline const __m128 _mm_min_ss (const __m128 &a, const __m128 &b) {
			vectorx u; u[0] = std::min(a[0], b[0]); for (int i = 1; i < 4; ++i) u[i] = a[i]; return u;
		}

		inline const __m128 _mm_max_ps (const __m128 &a, const __m128 &b) {
			vectorx u; for (int i = 0; i < 4; ++i) u[i] = std::max(a[i], b[i]); return u;
		}
		inline const __m128 _mm_max_ss (const __m128 &a, const __m128 &b) {
			vectorx u; u[0] = std::max(a[0], b[0]); for (int i = 1; i < 4; ++i) u[i] = a[i]; return u;
		}

		inline const __m128 _mm_cmplt_ps (const __m128 &a, const __m128 &b) {
			__m128_union u;
			for (int i = 0; i < 4; ++i) u.i[i] = ((a[i]<b[i]) ? 0xffffffff : 0x0);
			return u.m;
		}
		inline const __m128 _mm_cmple_ps (const __m128 &a, const __m128 &b) {
			__m128_union u;
			for (int i = 0; i < 4; ++i) u.i[i] = ((a[i]<=b[i]) ? 0xffffffff : 0x0);
			return u.m;
		}
		inline const __m128 _mm_cmpeq_ps (const __m128 &a, const __m128 &b) {
			__m128_union u;
			for (int i = 0; i < 4; ++i) u.i[i] = ((a[i]==b[i]) ? 0xffffffff : 0x0);
			return u.m;
		}
		inline const __m128 _mm_and_ps (const __m128 &a_, const __m128 &b_) {
			__m128_union a; a.m = a_;
			__m128_union b; b.m = b_;
			__m128_union u;
			for (int i = 0; i < 4; ++i) u.i[i] = (a.i[i] & b.i[i]);
			return u.m;
		}
		inline const __m128 _mm_or_ps (const __m128 &a_, const __m128 &b_) {
			__m128_union a; a.m = a_;
			__m128_union b; b.m = b_;
			__m128_union u;
			for (int i = 0; i < 4; ++i) u.i[i] = (a.i[i] | b.i[i]);
			return u.m;
		}
		inline const __m128 _mm_andnot_ps (const __m128 &a_, const __m128 &b_) {
			__m128_union a; a.m = a_;
			__m128_union b; b.m = b_;
			__m128_union u;
			for (int i = 0; i < 4; ++i) u.i[i] = (~(a.i[i]) & b.i[i]);
			return u.m;
		}
		inline const int _mm_movemask_ps (const __m128 &a) {
			__m128_union u;
			u.m = a;
			return (((u.i[0] & 0x80000000) >> 31) | ((u.i[1] & 0x80000000) >> 30) | ((u.i[2] & 0x80000000) >> 29) | ((u.i[3] & 0x80000000) >> 28));
		}

		inline const __m128 _mm_cmplt_ss (const __m128 &a, const __m128 &b) {
			__m128_union u;
			u.m = a;
			u.i[0] = ((a[0]<b[0]) ? 0xffffffff : 0x0);
			return u.m;
		}
		inline const __m128 _mm_cmple_ss (const __m128 &a, const __m128 &b) {
			__m128_union u;
			u.m = a;
			u.i[0] = ((a[0]<=b[0]) ? 0xffffffff : 0x0);
			return u.m;
		}
		inline const __m128 _mm_cmpeq_ss (const __m128 &a, const __m128 &b) {
			__m128_union u;
			u.m = a;
			u.i[0] = ((a[0]==b[0]) ? 0xffffffff : 0x0);
			return u.m;
		}
	#endif


	inline float *const floatp (matrixx &m) {
		return reinterpret_cast<float *>(&m);
	}
	inline const float *const floatp (const matrixx &m) {
		return reinterpret_cast<const float *>(&m);
	}

	inline void check_invariant (const vectorx &v) { SXASSERT(is_aligned(&v)); }
	inline const bool check2 (const vectorx &v) { return (is_aligned(&v) && (((const float *)(&v))[2] == 0.0f) && (((const float *)(&v))[3] == 0.0f)); }
	inline const bool check3 (const vectorx &v) { return (is_aligned(&v) && ((const float *)(&v))[3] == 0.0f); }

	inline const vectorx vectorxt (const float f) {
		return _mm_set_ps1(f);
	}
	inline const vectorx vectorxt (const float x, const float y) {
		return _mm_setr_ps(x, y, 0.0f, 0.0f);
	}
	inline const vectorx vectorxt (const float x, const float y, const float z) {
		return _mm_setr_ps(x, y, z, 0.0f);
	}
	inline const vectorx vectorxt (const float x, const float y, const float z, const float w) {
		return _mm_setr_ps(x, y, z, w);
	}
	inline const vectorx vectorxt (const float *const p) {
		return _mm_loadu_ps(p);
	}

	inline const vectorx vectorxt (const vec<float,2> &v, const float z = 0.0f, const float w = 0.0f) {
		return _mm_setr_ps(v.x, v.y, z, w);
	}
	inline const vectorx vectorxt (const vec<float,2> &v0, const vec<float,2> &v1) {
		return _mm_setr_ps(v0.x, v0.y, v1.x, v1.y);
	}
	inline const vectorx vectorxt (const vec<float,3> &v, const float w = 0.0f) {
		return _mm_setr_ps(v.x, v.y, v.z, w);
	}
	inline const vectorx vectorxt (const vec<float,4> &v) {
		#if SXSIMD && __ARM_NEON__
			return vld1q_f32((const float32_t *)(&v));
		#else
			return _mm_setr_ps(v.x, v.y, v.z, v.w);
		#endif
	}
	inline const vectorx vectorxt (const rgb<float> &v, const float alpha = 0.0f) {
		return _mm_setr_ps(v.red, v.green, v.blue, alpha);
	}
	inline const vectorx vectorxt (const rgba<float> &v) {
		return _mm_setr_ps(v.red, v.green, v.blue, v.alpha);
	}

	inline const vectorx vectorxt (const vec<int,2> &v0) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(float(v0.x), float(v0.y), 0.0f, 0.0f);
			#else
				#if (2 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_cvtepi32_ps(_mm_setr_epi32(v0.x, v0.y, 0, 0));
				#else
					const vectorx v = _mm_cvt_si2ss(_mm_setzero_ps(), v0.y);
					return _mm_cvt_si2ss(_mm_unpacklo_ps(v, v), v0.x);
				#endif
			#endif
		#else
			vectorx v; v[0] = float(v0.x); v[1] = float(v0.y); v[2] = 0.0f; v[3] = 0.0f; return v;
		#endif
	}
	inline const vectorx vectorxt (const vec<int,2> &v0, const vec<int,2> &v1) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(float(v0.x), float(v0.y), float(v1.x), float(v1.y));
			#else
				#if (2 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_cvtepi32_ps(_mm_setr_epi32(v0.x, v0.y, v1.x, v1.y));
				#else
					vectorx h;
					h = _mm_cvt_si2ss(h, v1.y);
					h = _mm_cvt_si2ss(_mm_unpacklo_ps(h, h), v1.x);
					vectorx l;
					l = _mm_cvt_si2ss(l, v0.y);
					return _mm_cvt_si2ss(_mm_movelh_ps(_mm_unpacklo_ps(l, l), h), v0.x);
				#endif
			#endif
		#else
			vectorx v; v[0] = float(v0.x); v[1] = float(v0.y); v[2] = float(v1.x); v[3] = float(v1.y); return v;
		#endif
		return _mm_setr_ps(v0.x, v0.y, v1.x, v1.y);
	}
	inline const vectorx vectorxt (const vec<int,3> &v0) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(float(v0.x), float(v0.y), float(v0.z), 0.0f);
			#else
				#if (2 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_cvtepi32_ps(_mm_setr_epi32(v0.x, v0.y, v0.z, 0));
				#else
					vectorx l;
					l = _mm_cvt_si2ss(l, v0.y);
					return _mm_cvt_si2ss(_mm_movelh_ps(_mm_unpacklo_ps(l, l), _mm_cvt_si2ss(_mm_setzero_ps(), v0.z)), v0.x);
				#endif
			#endif
		#else
			vectorx v; v[0] = float(v0.x); v[1] = float(v0.y); v[2] = float(v0.z); v[3] = 0.0f; return v;
		#endif
	}
	inline const vectorx vectorxt (const vec<int,4> &v0) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(float(v0.x), float(v0.y), float(v0.z), float(v0.w));
			#else
				#if (2 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_cvtepi32_ps(_mm_setr_epi32(v0.x, v0.y, v0.z, v0.w));
				#else
					vectorx h;
					h = _mm_cvt_si2ss(h, v0.w);
					h = _mm_cvt_si2ss(_mm_unpacklo_ps(h, h), v0.z);
					vectorx l;
					l = _mm_cvt_si2ss(l, v0.y);
					return _mm_cvt_si2ss(_mm_movelh_ps(_mm_unpacklo_ps(l, l), h), v0.x);
				#endif
			#endif
		#else
			vectorx v; v[0] = float(v0.x); v[1] = float(v0.y); v[2] = float(v0.z); v[3] = float(v0.w); return v;
		#endif
	}

	inline const scalarx scalarxt (const float f) {
		return _mm_set_ss(f);
	}

	static const vectorx vone = vectorxt(1.0f);
	static const vectorx vhalf = vectorxt(0.5f);
	static const vectorx vzero = vectorxt(0.0f);
	static const vectorx vepsilon = vectorxt(denormalized_min); // note that _mm_rsqrt_ps(scalarx(1e-38)) returns #INF.
	static const vectorx vmask1 = vectorxt(1.0f,0.0f,0.0f,0.0f);
	static const vectorx vmask2 = vectorxt(1.0f,1.0f,0.0f,0.0f);
	static const vectorx vmask3 = vectorxt(1.0f,1.0f,1.0f,0.0f);

	static const scalarx sone = scalarxt(1.0f);
	static const scalarx shalf = scalarxt(0.5f);
	static const scalarx szero = scalarxt(0.0f);
	static const scalarx sepsilon = scalarxt(denormalized_min); // note that _mm_rsqrt_ps(scalarx(1e-38)) returns #INF.

	inline float *const floatp (vectorx &v) {
		return reinterpret_cast<float *>(&v);
	}
	inline const float *const floatp (const vectorx &v) {
		return reinterpret_cast<const float *>(&v);
	}

	inline const int movemask (const vectorx &a) {
		return _mm_movemask_ps(a);
	}
	template<int i0, int i1, int i2, int i3> inline const vectorx shuffle (const vectorx &a) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(a,i0), vgetq_lane_f32(a,i1), vgetq_lane_f32(a,i2), vgetq_lane_f32(a,i3));
			#else
				return _mm_shuffle_ps(a, a, _MM_SHUFFLE(i3,i2,i1,i0));
			#endif
		#else
			vectorx v; v[0] = a[i0]; v[1] = a[i1]; v[2] = a[i2]; v[3] = a[i3]; return v;
		#endif
	}
	template<int i0, int i1, int i2, int i3> inline const vectorx shuffle (const vectorx &a, const vectorx &b) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(a,i0), vgetq_lane_f32(a,i1), vgetq_lane_f32(b,i2), vgetq_lane_f32(b,i3));
			#else
				return _mm_shuffle_ps(a, b, _MM_SHUFFLE(i3,i2,i1,i0));
			#endif
		#else
			vectorx v; v[0] = a[i0]; v[1] = a[i1]; v[2] = b[i2]; v[3] = b[i3]; return v;
		#endif
	}
	template<int i> inline const vectorx splat (const vectorx &a) {
		#if SXSIMD
			#if __ARM_NEON__
				return vdupq_n_f32(vgetq_lane_f32(a, i));
			#else
				return _mm_shuffle_ps(a, a, _MM_SHUFFLE(i,i,i,i));
			#endif
		#else
			vectorx v; v[0] = a[i]; v[1] = a[i]; v[2] = a[i]; v[3] = a[i]; return v;
		#endif
	}
	inline const vectorx unpacklo (const vectorx &a, const vectorx &b) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(a,0), vgetq_lane_f32(b,0), vgetq_lane_f32(a,1), vgetq_lane_f32(b,1));
			#else
				return _mm_unpacklo_ps(a, b);
			#endif
		#else
			vectorx v; v[0] = a[0]; v[1] = b[0]; v[2] = a[1]; v[3] = b[1]; return v;
		#endif
	}
	inline const vectorx unpackhi (const vectorx &a, const vectorx &b) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(a,2), vgetq_lane_f32(b,2), vgetq_lane_f32(a,3), vgetq_lane_f32(b,3));
			#else
				return _mm_unpackhi_ps(a, b);
			#endif
		#else
			vectorx v; v[0] = a[2]; v[1] = b[2]; v[2] = a[3]; v[3] = b[3]; return v;
		#endif
	}
	inline const vectorx move_ss (const vectorx &a, const scalarx &b) {
		#if SXSIMD
			#if __ARM_NEON__
				return vsetq_lane_f32(vgetq_lane_f32(b,0), a, 0);
			#else
				return _mm_move_ss(a, b);
			#endif
		#else
			vectorx v; v[0] = b[0]; v[1] = a[1]; v[2] = a[2]; v[3] = a[3]; return v;
		#endif
	}
	inline const scalarx muls (const scalarx &a, const scalarx &b) {
		return _mm_mul_ss(a, b);
	}
	inline const vectorx sqr (const vectorx &a) {
		return _mm_mul_ps(a, a);
	}
	inline const scalarx sqrs (const scalarx &a) {
		return _mm_mul_ss(a, a);
	}
	inline const scalarx adds (const scalarx &a, const scalarx &b) {
		return _mm_add_ss(a, b);
	}
	inline const scalarx subs (const scalarx &a, const scalarx &b) {
		return _mm_sub_ss(a, b);
	}
	inline const scalarx negs (const scalarx &a) {
		return _mm_sub_ss(szero, a);
	}

	inline const int lt (const vectorx &a, const vectorx &b) {
		#if SXSIMD
			return _mm_movemask_ps(_mm_cmplt_ps(a, b));
		#else
			return int(a[0]<b[0]) | (int(a[1]<b[1])<<1) | (int(a[2]<b[2])<<2) | (int(a[3]<b[3])<<3);
		#endif
	}
	inline const int le (const vectorx &a, const vectorx &b) {
		#if SXSIMD
			return _mm_movemask_ps(_mm_cmple_ps(a, b));
		#else
			return int(a[0]<=b[0]) | (int(a[1]<=b[1])<<1) | (int(a[2]<=b[2])<<2) | (int(a[3]<=b[3])<<3);
		#endif
	}
	inline const int eq (const vectorx &a, const vectorx &b) {
		#if SXSIMD
			return _mm_movemask_ps(_mm_cmpeq_ps(a, b));
		#else
			return int(a[0]==b[0]) | (int(a[1]==b[1])<<1) | (int(a[2]==b[2])<<2) | (int(a[3]==b[3])<<3);
		#endif
	}

	inline const bool lts (const scalarx &a, const scalarx &b) {
		#if SXSIMD
			#if __ARM_NEON__
				return (vgetq_lane_f32(a,0) < vgetq_lane_f32(b,0));
			#else
				return (_mm_movemask_ps(_mm_cmplt_ss(a, b)) & 0x01);
			#endif
		#else
			return (a[0]<b[0]);
		#endif
	}
	inline const bool les (const scalarx &a, const scalarx &b) {
		#if SXSIMD
			#if __ARM_NEON__
				return (vgetq_lane_f32(a,0) <= vgetq_lane_f32(b,0));
			#else
				return (_mm_movemask_ps(_mm_cmple_ss(a, b)) & 0x01);
			#endif
		#else
			return (a[0]<=b[0]);
		#endif
	}
	inline const bool eqs (const scalarx &a, const scalarx &b) {
		#if SXSIMD
			#if __ARM_NEON__
				return (vgetq_lane_f32(a,0) == vgetq_lane_f32(b,0));
			#else
				return (_mm_movemask_ps(_mm_cmpeq_ss(a, b)) & 0x01);
			#endif
		#else
			return (a[0]==b[0]);
		#endif
	}
	inline const bool zeros (const scalarx &a) {
		#if SXSIMD
			return (_mm_movemask_ps(_mm_and_ps(_mm_cmplt_ss(scalarxt(-epsilon), a), _mm_cmplt_ss(a, scalarxt(epsilon)))) & 0x01);
		#else
			return (-epsilon < a[0] && a[0] < epsilon);
		#endif
	}

	inline const vectorx ltx (const vectorx &a, const vectorx &b) {
		return _mm_cmplt_ps(a, b);
	}
	inline const vectorx lex (const vectorx &a, const vectorx &b) {
		return _mm_cmple_ps(a, b);
	}
	inline const vectorx eqx (const vectorx &a, const vectorx &b) {
		return _mm_cmpeq_ps(a, b);
	}
	inline const vectorx andx (const vectorx &a, const vectorx &b) {
		return _mm_and_ps(a, b);
	}
	inline const vectorx orx (const vectorx &a, const vectorx &b) {
		return _mm_or_ps(a, b);
	}
	inline const vectorx andnotx (const vectorx &a, const vectorx &b) {
		return _mm_andnot_ps(a, b);
	}
	inline const vectorx conditional (const vectorx &c, const vectorx &a, const vectorx &b) {
		return _mm_add_ps(sx::andx(c, a), sx::andnotx(c, b));
	}
	inline const vectorx conditionals (const scalarx &c, const scalarx &a, const scalarx &b) {
		return _mm_add_ss(_mm_and_ps(c, a), _mm_andnot_ps(c, b));
	}

	inline const vectorx zerox (const vectorx &v) {
		return andx(ltx(vectorxt(-epsilon), v), ltx(v, vectorxt(epsilon)));
	}
	inline const int zero (const vectorx &v) {
		return movemask(zerox(v));
	}

	inline const vectorx pack (const scalarx &t0, const scalarx &t1) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(t0,0), vgetq_lane_f32(t1,0), 0.0f, 0.0f);
			#else
				return _mm_unpacklo_ps(t0, t1);
			#endif
		#else
			vectorx v;
			v[0] = t0[0]; v[1] = t1[0]; v[2] = 0.0f; v[3] = 0.0f;
			return v;
		#endif
	}
	inline const vectorx pack (const scalarx &t0, const scalarx &t1, const scalarx &t2) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(t0,0), vgetq_lane_f32(t1,0), vgetq_lane_f32(t2,0), 0.0f);
			#else
				return _mm_movelh_ps(_mm_unpacklo_ps(t0, t1), t2);
			#endif
		#else
			vectorx v;
			v[0] = t0[0]; v[1] = t1[0]; v[2] = t2[0]; v[3] = 0.0f;
			return v;
		#endif
	}
	inline const vectorx pack (const scalarx &t0, const scalarx &t1, const scalarx &t2, const scalarx &t3) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(t0,0), vgetq_lane_f32(t1,0), vgetq_lane_f32(t2,0), vgetq_lane_f32(t3,0));
			#else
				return _mm_movelh_ps(_mm_unpacklo_ps(t0, t1), _mm_unpacklo_ps(t2, t3));
			#endif
		#else
			vectorx v;
			v[0] = t0[0]; v[1] = t1[0]; v[2] = t2[0]; v[3] = t3[0];
			return v;
		#endif
	}
	inline const vectorx packx (const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(t0,0), vgetq_lane_f32(t1,0), vgetq_lane_f32(t2,0), vgetq_lane_f32(t3,0));
			#else
				return _mm_movelh_ps(_mm_unpacklo_ps(t0, t1), _mm_unpacklo_ps(t2, t3));
			#endif
		#else
			vectorx v;
			v[0] = t0[0]; v[1] = t1[0]; v[2] = t2[0]; v[3] = t3[0];
			return v;
		#endif
	}
	inline const vectorx packy (const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(t0,1), vgetq_lane_f32(t1,1), vgetq_lane_f32(t2,1), vgetq_lane_f32(t3,1));
			#else
				return _mm_movehl_ps(_mm_unpacklo_ps(t2, t3), _mm_unpacklo_ps(t0, t1));
			#endif
		#else
			vectorx v;
			v[0] = t0[1]; v[1] = t1[1]; v[2] = t2[1]; v[3] = t3[1];
			return v;
		#endif
	}
	inline const vectorx packz (const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(t0,2), vgetq_lane_f32(t1,2), vgetq_lane_f32(t2,2), vgetq_lane_f32(t3,2));
			#else
				return _mm_movelh_ps(_mm_unpackhi_ps(t0, t1), _mm_unpackhi_ps(t2, t3));
			#endif
		#else
			vectorx v;
			v[0] = t0[2]; v[1] = t1[2]; v[2] = t2[2]; v[3] = t3[2];
			return v;
		#endif
	}
	inline const vectorx packw (const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(vgetq_lane_f32(t0,3), vgetq_lane_f32(t1,3), vgetq_lane_f32(t2,3), vgetq_lane_f32(t3,3));
			#else
				return _mm_movehl_ps(_mm_unpackhi_ps(t2, t3), _mm_unpackhi_ps(t0, t1));
			#endif
		#else
			vectorx v;
			v[0] = t0[3]; v[1] = t1[3]; v[2] = t2[3]; v[3] = t3[3];
			return v;
		#endif
	}

	template<> inline const vectorx sqrt (const vectorx &t) {
		return _mm_sqrt_ps(t);
	}
	inline const scalarx sqrts (const scalarx &v) {
		return _mm_sqrt_ss(v);
	}

	inline const vectorx rsqrt (const vectorx &v) {
		#if SXSIMD
			#if __ARM_NEON__
				const vectorx y0 = vrsqrteq_f32(v);
				const vectorx t0 = _mm_mul_ps(y0, y0);
				const vectorx t1 = _mm_mul_ps(y0, vhalf);
				return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(vone, _mm_mul_ps(v, t0)), t1), y0);
			#else
				const vectorx y0 = _mm_rsqrt_ps(v);
				const vectorx t0 = _mm_mul_ps(y0, y0);
				const vectorx t1 = _mm_mul_ps(y0, vhalf);
				return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(vone, _mm_mul_ps(v, t0)), t1), y0);
			#endif
		#else
			vectorx u;
			for (int i = 0; i < 4; ++i) u[i] = 1.0f / std::sqrt(v[i]);
			return u;
		#endif
	}
	inline const scalarx rsqrts (const scalarx &v) {
		#if SXSIMD
			#if __ARM_NEON__
				__m128_union v_; v_.m = v;
				__m128_union u;
				u.f[0] = 1.0f / std::sqrt(v_.f[0]);
				for (int i = 1; i < 4; ++i) u.f[i] = v_.f[i];
				return u.m;
			#else
				const scalarx y0 = _mm_rsqrt_ss(v);
				const scalarx t0 = muls(y0, y0);
				const scalarx t1 = muls(y0, shalf);
				return adds(muls(subs(sone, muls(v, t0)), t1), y0);
			#endif
		#else
			vectorx u;
			u[0] = 1.0f / std::sqrt(v[0]);
			for (int i = 1; i < 4; ++i) u[i] = v[i];
			return u;
		#endif
	}

	inline const vectorx rcp (const vectorx &a) {
		#if SXSIMD
			#if __ARM_NEON__
				const vectorx y0 = vrecpeq_f32(a);
				return _mm_add_ps(_mm_mul_ps(y0, _mm_sub_ps(vone, _mm_mul_ps(y0, a))), y0);
			#else
				const vectorx y0 = _mm_rcp_ps(a);
				return _mm_add_ps(_mm_mul_ps(y0, _mm_sub_ps(vone, _mm_mul_ps(y0, a))), y0);
			#endif
		#else
			vectorx u;
			for (int i = 0; i < 4; ++i) u[i] = 1.0f / a[i];
			return u;
		#endif
	}
	inline const scalarx rcps (const scalarx &a) {
		#if SXSIMD
			#if __ARM_NEON__
//				__m128_union u; u.m = a;
//				__m128_union v;
//				v.f[0] = 1.0f / u.f[0];
//				for (int i = 1; i < 4; ++i) v.f[i] = u.f[i];
//				return v.m;
				const vectorx y0 = vrecpeq_f32(a);
				return _mm_add_ps(_mm_mul_ps(y0, _mm_sub_ps(vone, _mm_mul_ps(y0, a))), y0);
			#else
				const scalarx y0 = _mm_rcp_ss(a);
				return adds(muls(y0, subs(sone, muls(y0, a))), y0);
			#endif
		#else
			vectorx u;
			u[0] = 1.0f / a[0];
			for (int i = 1; i < 4; ++i) u[i] = a[i];
			return u;
		#endif
	}
	inline const vectorx reciprocal (const vectorx &a) { return rcp(a); }

	inline const vectorx min (const vectorx &a, const vectorx &b) { // element-wise
		return _mm_min_ps(a, b);
	}
	inline const scalarx mins (const scalarx &a, const scalarx &b) {
		return _mm_min_ss(a, b);
	}

	inline const vectorx max (const vectorx &a, const vectorx &b) { // element-wise
		return _mm_max_ps(a, b);
	}
	inline const scalarx maxs (const scalarx &a, const scalarx &b) {
		return _mm_max_ss(a, b);
	}

	inline const vectorx abs (const vectorx &p) {
		return _mm_max_ps(p, _mm_sub_ps(vzero, p));
	}
	inline const scalarx abss (const scalarx &p) {
		return _mm_max_ss(p, _mm_sub_ss(szero, p));
	}

	inline const scalarx sum4 (const vectorx &p) {
		SXTEST(sx::check_invariant(p));
		#if SXSIMD
			#if __ARM_NEON__
				return vdupq_n_f32(vgetq_lane_f32(p,0) + vgetq_lane_f32(p,1) + vgetq_lane_f32(p,2) + vgetq_lane_f32(p,3));
			#else
				#if (3 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					const vectorx v = _mm_hadd_ps(p,p);
					return _mm_hadd_ps(v,v);
				#else
					const vectorx q = _mm_add_ps(p, _mm_movehl_ps(p, p));
					return adds(q, splat<1>(q));
				#endif
			#endif
		#else
			vectorx u;
			u[0] = p[0] + p[1] + p[2] + p[3];
			for (int i = 1; i < 4; ++i) u[i] = p[i];
			return u;
		#endif
	}
	inline const vectorx sum4 (const vectorx &p0, const vectorx &p1, const vectorx &p2, const vectorx &p3) {
		SXTEST((sx::check_invariant(p0), sx::check_invariant(p1), sx::check_invariant(p2), sx::check_invariant(p3)));
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(
					vgetq_lane_f32(p0,0) + vgetq_lane_f32(p0,1) + vgetq_lane_f32(p0,2) + vgetq_lane_f32(p0,3),
					vgetq_lane_f32(p1,0) + vgetq_lane_f32(p1,1) + vgetq_lane_f32(p1,2) + vgetq_lane_f32(p1,3),
					vgetq_lane_f32(p2,0) + vgetq_lane_f32(p2,1) + vgetq_lane_f32(p2,2) + vgetq_lane_f32(p2,3),
					vgetq_lane_f32(p3,0) + vgetq_lane_f32(p3,1) + vgetq_lane_f32(p3,2) + vgetq_lane_f32(p3,3)
				);
			#else
				#if (3 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_hadd_ps(_mm_hadd_ps(p0, p1), _mm_hadd_ps(p2, p3));
				#else
					const vectorx q01 = _mm_add_ps(_mm_unpacklo_ps(p0, p1), _mm_unpackhi_ps(p0, p1));
					const vectorx q23 = _mm_add_ps(_mm_unpacklo_ps(p2, p3), _mm_unpackhi_ps(p2, p3));
					return _mm_add_ps(_mm_movelh_ps(q01, q23), _mm_movehl_ps(q23, q01));
				#endif
			#endif
		#else
			vectorx u;
			u[0] = p0[0] + p0[1] + p0[2] + p0[3];
			u[1] = p1[0] + p1[1] + p1[2] + p1[3];
			u[2] = p2[0] + p2[1] + p2[2] + p2[3];
			u[3] = p3[0] + p3[1] + p3[2] + p3[3];
			return u;
		#endif
	}
	inline const scalarx sum3 (const vectorx &p) {
		SXTEST(sx::check_invariant(p));
		#if SXSIMD
			#if __ARM_NEON__
				return vdupq_n_f32(vgetq_lane_f32(p,0) + vgetq_lane_f32(p,1) + vgetq_lane_f32(p,2));
			#else
				#if (3 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return adds(_mm_hadd_ps(p,p), _mm_movehl_ps(p, p));
				#else
					return adds(adds(p, splat<1>(p)), _mm_movehl_ps(p, p));
				#endif
			#endif
		#else
			vectorx u;
			u[0] = p[0] + p[1] + p[2];
			for (int i = 1; i < 4; ++i) u[i] = p[i];
			return u;
		#endif
	}
	inline const vectorx sum3 (const vectorx &p0, const vectorx &p1, const vectorx &p2, const vectorx &p3) {
		SXTEST((sx::check_invariant(p0), sx::check_invariant(p1), sx::check_invariant(p2), sx::check_invariant(p3)));
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(
					vgetq_lane_f32(p0,0) + vgetq_lane_f32(p0,1) + vgetq_lane_f32(p0,2),
					vgetq_lane_f32(p1,0) + vgetq_lane_f32(p1,1) + vgetq_lane_f32(p1,2),
					vgetq_lane_f32(p2,0) + vgetq_lane_f32(p2,1) + vgetq_lane_f32(p2,2),
					vgetq_lane_f32(p3,0) + vgetq_lane_f32(p3,1) + vgetq_lane_f32(p3,2)
				);
			#else
				#if (3 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_add_ps(_mm_hadd_ps(_mm_movelh_ps(p0, p1), _mm_movelh_ps(p2, p3)), packz(p0, p1, p2, p3));
				#else
					const vectorx q01 = _mm_unpacklo_ps(p0, p1);
					const vectorx q23 = _mm_unpacklo_ps(p2, p3);
					return _mm_add_ps(_mm_add_ps(_mm_movelh_ps(q01, q23), _mm_movehl_ps(q23, q01)), packz(p0, p1, p2, p3));
				#endif
			#endif
		#else
			vectorx u;
			u[0] = p0[0] + p0[1] + p0[2];
			u[1] = p1[0] + p1[1] + p1[2];
			u[2] = p2[0] + p2[1] + p2[2];
			u[3] = p3[0] + p3[1] + p3[2];
			return u;
		#endif
	}
	inline const vectorx sum3 (const vectorx &p0, const vectorx &p1, const vectorx &p2) {
		SXTEST((sx::check_invariant(p0), sx::check_invariant(p1), sx::check_invariant(p2)));
		#if SXSIMD
			#if __ARM_NEON__
				return _mm_setr_ps(
					vgetq_lane_f32(p0,0) + vgetq_lane_f32(p0,1) + vgetq_lane_f32(p0,2),
					vgetq_lane_f32(p1,0) + vgetq_lane_f32(p1,1) + vgetq_lane_f32(p1,2),
					vgetq_lane_f32(p2,0) + vgetq_lane_f32(p2,1) + vgetq_lane_f32(p2,2),
					0.0f
				);
			#else
				#if (3 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_add_ps(_mm_hadd_ps(_mm_movelh_ps(p0, p1), p2), shuffle<0, 1, 2, 3>(_mm_unpackhi_ps(p0, p1), p2));
				#else
					const vectorx q01 = _mm_unpacklo_ps(p0, p1);
					return _mm_add_ps(_mm_add_ps(_mm_movelh_ps(q01, p2), shuffle<2, 3, 1, 0>(q01, p2)), shuffle<0, 1, 2, 3>(_mm_unpackhi_ps(p0, p1), p2));
				#endif
			#endif
		#else
			vectorx u;
			u[0] = p0[0] + p0[1] + p0[2];
			u[1] = p1[0] + p1[1] + p1[2];
			u[2] = p2[0] + p2[1] + p2[2];
			u[3] = 0.0f;
			return u;
		#endif
	}
	inline const scalarx sum2 (const vectorx &p) {
		//sxassert(check2(p));
		#if SXSIMD
			#if __ARM_NEON__
				return vdupq_n_f32(vgetq_lane_f32(p,0) + vgetq_lane_f32(p,1));
			#else
				#if (3 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_hadd_ps(p,p);
				#else
					return adds(p, splat<1>(p));
				#endif
			#endif
		#else
			vectorx u;
			u[0] = p[0] + p[1];
			for (int i = 1; i < 4; ++i) u[i] = p[i];
			return u;
		#endif
	}
	inline const scalarx inner_product4 (const vectorx &a, const vectorx &b) {
		return sum4(_mm_mul_ps(a, b));
	}
	inline const scalarx inner_product4 (const vectorx &a0, const vectorx &b0, const vectorx &a1, const vectorx &b1, const vectorx &a2, const vectorx &b2, const vectorx &a3, const vectorx &b3) {
		return sum4(_mm_mul_ps(a0, b0), _mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2), _mm_mul_ps(a3, b3));
	}
	inline const scalarx inner_product4 (const vectorx &a0, const vectorx &b0, const vectorx &a1, const vectorx &b1, const vectorx &a2, const vectorx &b2) {
		return sum4(_mm_mul_ps(a0, b0), _mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2), vzero);
	}
	inline const scalarx inner_product3 (const vectorx &a, const vectorx &b) {
		SXTEST((sx::check_invariant(a), check_invariant(b)));
		return sum3(_mm_mul_ps(a, b));
	}
	inline const scalarx inner_product3 (const vectorx &a0, const vectorx &b0, const vectorx &a1, const vectorx &b1, const vectorx &a2, const vectorx &b2, const vectorx &a3, const vectorx &b3) {
		return sum3(_mm_mul_ps(a0, b0), _mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2), _mm_mul_ps(a3, b3));
	}
	inline const scalarx inner_product3 (const vectorx &a0, const vectorx &b0, const vectorx &a1, const vectorx &b1, const vectorx &a2, const vectorx &b2) {
		return sum3(_mm_mul_ps(a0, b0), _mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2));
	}

	inline const vectorx product (const vectorx &a, const vectorx &b) {
		const vectorx ayzx = shuffle<1,2,0, 3>(a);
		const vectorx bzxy = shuffle<2,0,1, 3>(b);
		const vectorx azxy = shuffle<2,0,1, 3>(a);
		const vectorx byzx = shuffle<1,2,0, 3>(b);
		return _mm_sub_ps(_mm_mul_ps(ayzx, bzxy), _mm_mul_ps(azxy, byzx));
	}

	inline const vectorx normalize3 (const vectorx &p) {
		const scalarx a = inner_product3(p, p);
		#if SXSIMD
			return _mm_mul_ps(p, splat<0>(rsqrts(conditionals(_mm_cmplt_ss(sepsilon, a), a, sone))));
		#else
			return lts(sepsilon, a) ? _mm_mul_ps(p, splat<0>(rsqrts(a))) : p;
		#endif
	}
	inline const vectorx normalize4 (const vectorx &p) {
		const scalarx a = inner_product4(p, p);
		#if SXSIMD
			return _mm_mul_ps(p, splat<0>(rsqrts(conditionals(_mm_cmplt_ss(sepsilon, a), a, sone))));
		#else
			return lts(sepsilon, a) ? _mm_mul_ps(p, splat<0>(rsqrts(a))) : p;
		#endif
	}
	inline const scalarx normalize_self3 (vectorx &p) {
		const scalarx a = inner_product3(p, p);
		if (lts(sepsilon, a)) return a;
		#if SXSIMD
			const scalarx b = rsqrts(a);
			p = _mm_mul_ps(p, splat<0>(b));
			return rcps(b);
		#else
			const scalarx b = sqrts(a);
			p = _mm_mul_ps(p, splat<0>(rcps(b)));
			return b;
		#endif
	}
	inline const scalarx normalize_self4 (vectorx &p) {
		const scalarx a = inner_product4(p, p);
		if (lts(sepsilon, a)) return a;
		#if SXSIMD
			const scalarx b = rsqrts(a);
			p = _mm_mul_ps(p, splat<0>(b));
			return rcps(b);
		#else
			const scalarx b = sqrts(a);
			p = _mm_mul_ps(p, splat<0>(rcps(b)));
			return b;
		#endif
	}

	inline const scalarx sqrabsolute3 (const vectorx &p) {
		return inner_product3(p, p);
	}
	inline const scalarx sqrabsolute4 (const vectorx &p) {
		return inner_product4(p, p);
	}

	inline const scalarx absolute3 (const vectorx &p) {
		const scalarx a = inner_product3(p, p);
		#if SXSIMD
			return conditionals(_mm_cmplt_ss(sepsilon, a), sqrts(a), a);
		#else
			return lts(sepsilon, a) ? sqrts(a) : a;
		#endif
	}
	inline const scalarx absolute4 (const vectorx &p) {
		const scalarx a = inner_product4(p, p);
		#if SXSIMD
			return conditionals(_mm_cmplt_ss(sepsilon, a), sqrts(a), a);
		#else
			return lts(sepsilon, a) ? sqrts(a) : a;
		#endif
	}

	inline const vectorx transform44 (const vectorx &p, const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		return _mm_add_ps(_mm_mul_ps(splat<0>(p), t0), _mm_add_ps(_mm_mul_ps(splat<1>(p), t1), _mm_add_ps(_mm_mul_ps(splat<2>(p), t2), _mm_mul_ps(splat<3>(p), t3))));
	}
	inline const vectorx transform44 (const vectorx &p, const matrixx &t) {
		return transform44(p, t[0], t[1], t[2], t[3]);
	}
	inline const vectorx transform33 (const vectorx &p, const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		SXTEST((check_invariant(p), check_invariant(t0), check_invariant(t1), check_invariant(t2), check_invariant(t3)));
		const vectorx q = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(splat<0>(p), t0), _mm_add_ps(_mm_mul_ps(splat<1>(p), t1), _mm_add_ps(_mm_mul_ps(splat<2>(p), t2), t3))), vmask3);
		sxassert(check3(q));
		return q;
	}
	inline const vectorx transform33 (const vectorx &p, const matrixx &t) {
		return transform33(p, t[0], t[1], t[2], t[3]);
	}
	inline const vectorx transform22 (const vectorx &p, const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		sxassert(check2(p));
		const vectorx q = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(splat<0>(p), t0), _mm_add_ps(_mm_mul_ps(splat<1>(p), t1), t3)), vmask2);
		sxassert(check2(q));
		return q;
	}
	inline const vectorx transform22 (const vectorx &p, const matrixx &t) {
		return transform33(p, t[0], t[1], t[2], t[3]);
	}

	inline const vectorx transform_direction (const vectorx &p, const vectorx &t0, const vectorx &t1, const vectorx &t2) {
		SXTEST((check_invariant(p), check_invariant(t0), check_invariant(t1), check_invariant(t2)));
		const vectorx q = _mm_add_ps(_mm_mul_ps(splat<0>(p), t0), _mm_add_ps(_mm_mul_ps(splat<1>(p), t1), _mm_mul_ps(splat<2>(p), t2)));
		sxassert(check3(q));
		return q;
	}
	inline const vectorx transform_direction (const vectorx &p, const matrixx &t) {
		return transform_direction(p, t[0], t[1], t[2]);
	}

	inline const vectorx transform_normal (const matrixx &it, const vectorx &p) {
		sxassert(check3(p));
		const vectorx q = inner_product3(it[0], p, it[1], p, it[2], p);
		sxassert(check3(q));
		return q;
	}

	inline const matrixx transpose (const matrixx &t) {
		#if SXSIMD
			#if __ARM_NEON__
				matrixx m;
				m[0] = vectorxt(vgetq_lane_f32(t[0], 0), vgetq_lane_f32(t[1], 0), vgetq_lane_f32(t[2], 0), vgetq_lane_f32(t[3], 0));
				m[1] = vectorxt(vgetq_lane_f32(t[0], 1), vgetq_lane_f32(t[1], 1), vgetq_lane_f32(t[2], 1), vgetq_lane_f32(t[3], 1));
				m[2] = vectorxt(vgetq_lane_f32(t[0], 2), vgetq_lane_f32(t[1], 2), vgetq_lane_f32(t[2], 2), vgetq_lane_f32(t[3], 2));
				m[3] = vectorxt(vgetq_lane_f32(t[0], 3), vgetq_lane_f32(t[1], 3), vgetq_lane_f32(t[2], 3), vgetq_lane_f32(t[3], 3));
				return m;
			#else
				matrixx m(t);
				_MM_TRANSPOSE4_PS(m[0], m[1], m[2], m[3]);
				return m;
			#endif
		#else
			matrixx m;
			for (int i = 0; i < t.size(); ++i) m[i] = sx::vectorxt(t[0][i], t[1][i], t[2][i], t[3][i]);
			return m;
		#endif
	}
	inline const matrixx &transpose_self (matrixx &t) {
		#if SXSIMD
			#if __ARM_NEON__
				const vectorx v0 = t[0];
				const vectorx v1 = t[1];
				const vectorx v2 = t[2];
				const vectorx v3 = t[3];
				t[0] = vectorxt(vgetq_lane_f32(v0, 0), vgetq_lane_f32(v1, 0), vgetq_lane_f32(v2, 0), vgetq_lane_f32(v3, 0));
				t[1] = vectorxt(vgetq_lane_f32(v0, 1), vgetq_lane_f32(v1, 1), vgetq_lane_f32(v2, 1), vgetq_lane_f32(v3, 1));
				t[2] = vectorxt(vgetq_lane_f32(v0, 2), vgetq_lane_f32(v1, 2), vgetq_lane_f32(v2, 2), vgetq_lane_f32(v3, 2));
				t[3] = vectorxt(vgetq_lane_f32(v0, 3), vgetq_lane_f32(v1, 3), vgetq_lane_f32(v2, 3), vgetq_lane_f32(v3, 3));
			#else
				_MM_TRANSPOSE4_PS(t[0], t[1], t[2], t[3]);
			#endif
		#else
			matrixx m;
			for (int i = 0; i < t.size(); ++i) m[i] = sx::vectorxt(t[0][i], t[1][i], t[2][i], t[3][i]);
			t = m;
		#endif
		return t;
	}
	inline const scalarx det (const vectorx &t0, const vectorx &t1, const vectorx &t2, const vectorx &t3) {
		return sum3(_mm_mul_ps(t0, shuffle<1,2,0, 3>(_mm_sub_ps(_mm_mul_ps(t1, shuffle<1,2,0, 3>(t2)), _mm_mul_ps(shuffle<1,2,0, 3>(t1), t2)))));
		//return sum3(_mm_sub_ps(	_mm_mul_ps(_mm_mul_ps(t0, shuffle<1,2,0, 3>(t1)), shuffle<2,0,1, 3>(t2)),
		//							_mm_mul_ps(_mm_mul_ps(t0, shuffle<2,0,1, 3>(t1)), shuffle<1,2,0, 3>(t2))
		//			));
	}
	inline const scalarx det (const matrixx &t) {
		return det(t[0], t[1], t[2], t[3]);
	}
	const matrixx inv (const matrixx &t);
	const matrixx inverse (const matrixx &t);

	inline const scalarx divs (const scalarx &a, const scalarx &b) {
		return muls(a, rcps(b));
	}

	inline void cat (matrixx &t, const matrixx &a, const matrixx &b) { // concatinate
		t[0] = transform44(a[0], b);
		t[1] = transform44(a[1], b);
		t[2] = transform44(a[2], b);
		t[3] = transform44(a[3], b);
	}
	
	inline vectorx &revert_endian (vectorx &v) {
		float *const p = floatp(v);
		sx::revert_endian(p[0]);
		sx::revert_endian(p[1]);
		sx::revert_endian(p[2]);
		sx::revert_endian(p[3]);
		return v;
	}
	
	inline const vectorx lerp (const vectorx &a, const vectorx &b, const vectorx &t) {
		return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(b, a), t), a);
	}

	inline const vectorx trunc (const vectorx &v) {
		#if SXSIMD
			#if __ARM_NEON__
				__m128_union u; u.m = v;
				for (int i = 0; i < 4; ++i) u.f[i] = int(u.f[i]);
				return u.m;
			#else
				#if (2 <= SXSIMD) && (__GNUG__ || (1400 < _MSC_VER))
					return _mm_cvtepi32_ps(_mm_cvttps_epi32(v));
				#else
					vectorx t = sx::shuffle<1, 2, 3, 0>(_mm_cvt_si2ss(v, _mm_cvtt_ss2si(v)));
					for (int i = 1; i < 4; ++i) {
						t = sx::shuffle<1, 2, 3, 0>(_mm_cvt_si2ss(t, _mm_cvtt_ss2si(t)));
					}
					return t;
				#endif
			#endif
		#else
			vectorx t;
			for (int i = 0; i < 4; ++i) t[i] = int(v[i]);
			return t;
		#endif
	}
	inline const vectorx floor (const vectorx &v) {
		#if SXSIMD
			const vectorx vt(trunc(v));
			return _mm_sub_ps(vt, andx(ltx(v, vt), vectorxt(1.0f)));
		#else
			vectorx t;
			for (int i = 0; i < 4; ++i) t[i] = std::floor(v[i]);
			return t;
		#endif
	}
	inline const vectorx ceil (const vectorx &v) {
		#if SXSIMD
			const vectorx vt(trunc(v));
			return _mm_add_ps(vt, andx(ltx(vt, v), vectorxt(1.0f)));
		#else
			vectorx t;
			for (int i = 0; i < 4; ++i) t[i] = std::ceil(v[i]);
			return t;
		#endif
	}
//	template<int N> inline vec<float,N> &vect (vectorx &v) {
//		return (vec<float,N> &)(v);
//	}
	template<int N> inline const vec<float,N> &vectort (const vectorx &v) {
		return (const vec<float,N> &)(v);
	}
	template<int N> inline const vec<int,N> trunct (const vectorx &v) {
		vec<int,N> vi;
		#if SXSIMD
			#if __ARM_NEON__
				__m128_union u; u.m = v;
				for (int i = 0; i < N; ++i) vi[i] = int(u.f[i]);
			#else
				vi[0] = _mm_cvtt_ss2si(v);
				vectorx t = sx::shuffle<1, 2, 3, 0>(v);
				for (int i = 1; i < (N-1); ++i) {
					vi[i] = _mm_cvtt_ss2si(t);
					t = sx::shuffle<1, 2, 3, 0>(t);
				}
				vi[(N-1)] = _mm_cvtt_ss2si(t);
			#endif
		#else
			for (int i = 0; i < N; ++i) vi[i] = int(v[i]);
		#endif
		return vi;
	}
//	inline rgb<float> &rgbt (vectorx &v) {
//		return (rgb<float> &)(v);
//	}
	inline const rgb<float> rgbt (const vectorx &v) {
		return rgb<float>(floatp(v));
	}
//
//	inline rgba<float> &rgbat (vectorx &v) {
//		return (rgba<float> &)(v);
//	}
	inline const rgba<float> rgbat (const vectorx &v) {
		return rgba<float>(floatp(v));
	}
//	
//	inline mat<float,4> &matt (matrixx &t) {
//		return (mat<float,4> &)(t);
//	}
//	inline const mat<float,4> &matt (const matrixx &t) {
//		return (const mat<float,4> &)(t);
//	}
//	
	inline const float floatt (const vectorx &v) {
		#if SXSIMD && __ARM_NEON__
			return vgetq_lane_f32(v, 0);
		#else
			return *(float *)(&v);
		#endif
	}
	inline const matrixx matrixxt (float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p) {
		matrixx u;
		u[0] = vectorxt(a, b, c, d);
		u[1] = vectorxt(e, f, g, h);
		u[2] = vectorxt(i, j, k, l);
		u[3] = vectorxt(m, n, o, p);
		return u;
	}
	inline const matrixx matrixxt (const sx::mat<float,4> &t) {
		matrixx u; u[0] = sx::vectorxt(t[0]); u[1] = sx::vectorxt(t[1]); u[2] = sx::vectorxt(t[2]); u[3] = sx::vectorxt(t[3]);
		return u;
	}
	inline const bool eq (const matrixx &a, const matrixx &b) {
		return ((eq(a[0], b[0]) == 0x0f) && (eq(a[1], b[1]) == 0x0f) && (eq(a[2], b[2]) == 0x0f) && (eq(a[3], b[3]) == 0x0f));
	}

	inline const vectorx clamp (const vectorx &v, const vectorx &min = vectorxt(0.0f), const vectorx &max = vectorxt(1.0f)) {
		return sx::max(sx::min(v, max), min);
	}
	inline const scalarx clamps (const scalarx &v, const scalarx &min = scalarxt(0.0f), const scalarx &max = scalarxt(1.0f)) {
		return sx::maxs(sx::mins(v, max), min);
	}

//	template<typename T> T cast (vectorx v);
//	template<> vec<float,2> cast<vec<float,2> > (vectorx v) { return vec<float,2>((const float *)(&v)); }
//	template<> vec<float,3> cast<vec<float,3> > (vectorx v) { return vec<float,3>((const float *)(&v)); }
//	template<> vec<float,4> cast<vec<float,4> > (vectorx v) { return vec<float,4>((const float *)(&v)); }
//	template<> rgb<float> cast<rgb<float> > (vectorx v) { return rgb<float>((const float *)(&v)); }
//	template<> rgba<float> cast<rgba<float> > (vectorx v) { return rgba<float>((const float *)(&v)); }
//	template<> float cast<float > (vectorx v) { return *((const float *)(&v)); }
//
//	template<typename T> T cast (vectorx &v);
//	template<> vec<float,2> &cast<vec<float,2> &> (vectorx &v) { return (vec<float,2> &)(v); }
//	template<> vec<float,3> &cast<vec<float,3> &> (vectorx &v) { return (vec<float,3> &)(v); }
//	template<> vec<float,4> &cast<vec<float,4> &> (vectorx &v) { return (vec<float,4> &)(v); }
//	template<> rgb<float> &cast<rgb<float> &> (vectorx &v) { return (rgb<float> &)(v); }
//	template<> rgba<float> &cast<rgba<float> &> (vectorx &v) { return (rgba<float> &)(v); }
//	template<> float &cast<float &> (vectorx &v) { return (float &)(v); }
//
//	template<typename T> T cast (const vectorx &v);
//	template<> const vec<float,2> &cast<const vec<float,2> &> (const vectorx &v) { return (const vec<float,2> &)(v); }
//	template<> const vec<float,3> &cast<const vec<float,3> &> (const vectorx &v) { return (const vec<float,3> &)(v); }
//	template<> const vec<float,4> &cast<const vec<float,4> &> (const vectorx &v) { return (const vec<float,4> &)(v); }
//	template<> const rgb<float> &cast<const rgb<float> &> (const vectorx &v) { return (const rgb<float> &)(v); }
//	template<> const rgba<float> &cast<const rgba<float> &> (const vectorx &v) { return (const rgba<float> &)(v); }
//	template<> const float &cast<const float &> (const vectorx &v) { return (const float &)(v); }
//
//	template<typename T> T cast (const matrixx &m);
//	template<> mat<float,4> cast<mat<float,4> > (const matrixx &m) { return mat<float,4>(vec<float,4>(floatp(m[0])), vec<float,4>(floatp(m[1])), vec<float,4>(floatp(m[2])), vec<float,4>(floatp(m[3]))); }
}
namespace boost {
	template <> struct has_trivial_constructor<sx::vectorx> : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vectorx> : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vectorx> : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vectorx> : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vectorx> : public boost::true_type { };
}
namespace std {
	template<> class numeric_limits<sx::vectorx> {
	public:
		static sx::vectorx min () { return sx::vectorxt(-sx::denormalized_max); }	// note that _mm_cmple_ps(std::numeric_limits<float>::min(), v) returns 0. (std::numeric_limits<float>::min() == -1e+38)
		static sx::vectorx max () { return sx::vectorxt(sx::denormalized_max); }
	};
}
namespace sx {
	inline const vectorx is_finitex (const vectorx &v) {
		return andx(lex(std::numeric_limits<sx::vectorx>::min(), v), lex(v, std::numeric_limits<sx::vectorx>::max()));
	}
	inline const bool is_finite (const vectorx &v) {
		return (_mm_movemask_ps(is_finitex(v)) == 0xf);
	}
}

#if !(__GNUG__ && SXSIMD)
	inline const sx::vectorx operator+ (const sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return _mm_add_ps(a, b);
	}
	inline sx::vectorx &operator+= (sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return (a = _mm_add_ps(a, b));
	}
	inline const sx::vectorx operator- (const sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return _mm_sub_ps(a, b);
	}
	inline sx::vectorx &operator-= (sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return (a = _mm_sub_ps(a, b));
	}
	inline const sx::vectorx operator- (const sx::vectorx &a) {
		using namespace sx;
		return _mm_sub_ps(sx::vzero, a);
	}
	inline const sx::vectorx operator* (const sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return _mm_mul_ps(a, b);
	}
	inline sx::vectorx &operator*= (sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return (a = _mm_mul_ps(a, b));
	}
	inline const sx::vectorx operator/ (const sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return (a * sx::rcp(b));
	}
	inline sx::vectorx &operator/= (sx::vectorx &a, const sx::vectorx &b) {
		using namespace sx;
		return (a = (a * sx::rcp(b)));
	}
#endif

namespace sx {
	template <> class vec<vectorx,2> : public sx::memory::object {
	public:
		typedef vectorx value_type;
		typedef vectorx &reference;
		typedef const vectorx &const_reference;
		typedef vectorx *iterator;
		vectorx x, y;

		explicit vec () { }
		explicit vec (float f) : x(vectorxt(f)), y(vectorxt(f)) { }
		explicit vec (const vectorx &v) : x(splat<0>(v)), y(splat<1>(v)) { }
		explicit vec (const vectorx &x, const vectorx &y) : x(x), y(y) { }
		template<typename U> explicit vec (const vec<U,2> &v) : x(vectorxt(v.x)), y(vectorxt(v.y)) { }
		template<typename U> explicit vec (const vec<U,2> &a, const vec<U,2> &b, const vec<U,2> &c, const vec<U,2> &d) : x(vectorxt(a.x, b.x, c.x, d.x)), y(vectorxt(a.y, b.y, c.y, d.y)) { }
		const vectorx & operator[] (int i) const { sxassert(0<=i&&i<2); return (&x)[i]; }
		vectorx &operator[] (int i) { sxassert(0<=i&&i<2); return (&x)[i]; }
		void set (int i, const vectorx &v) { sx::floatp(x)[i] = sx::floatp(v)[0]; sx::floatp(y)[i] = sx::floatp(v)[1]; }
		template<typename U> void set (int i, const vec<U,2> &v) { sx::floatp(x)[i] = v.x; sx::floatp(y)[i] = v.y; }
		int size () const { return 2; }
		void check_invariant () const { sx::check_invariant(x); sx::check_invariant(y); }
	};

	template <> class vec<vectorx,3> : public sx::memory::object {
	public:
		typedef vectorx value_type;
		typedef vectorx &reference;
		typedef const vectorx &const_reference;
		typedef vectorx *iterator;
		vectorx x, y, z;

		explicit vec () { }
		explicit vec (float f) : x(vectorxt(f)), y(vectorxt(f)), z(vectorxt(f)) { }
		explicit vec (const vectorx &v) : x(splat<0>(v)), y(splat<1>(v)), z(splat<2>(v)) { }
		explicit vec (const vectorx &x, const vectorx &y, const vectorx &z) : x(x), y(y), z(z) { }
		template<typename U> explicit vec (const vec<U,2> &v, float z) : x(vectorxt(v.x)), y(vectorxt(v.y)), z(vectorxt(z)) { }
		template<typename U> explicit vec (const vec<U,3> &v) : x(vectorxt(v.x)), y(vectorxt(v.y)), z(vectorxt(v.z)) { }
		template<typename U> explicit vec (const vec<U,3> &a, const vec<U,3> &b, const vec<U,3> &c, const vec<U,3> &d) : x(vectorxt(a.x, b.x, c.x, d.x)), y(vectorxt(a.y, b.y, c.y, d.y)), z(vectorxt(a.z, b.z, c.z, d.z)) { }
		template<typename U> explicit vec (const rgb<U> &c) : x(vectorxt(c.red)), y(vectorxt(c.green)), z(vectorxt(c.blue)) { }
		template<typename U> explicit vec (const rgb<U> &a, const rgb<U> &b, const rgb<U> &c, const rgb<U> &d) : x(vectorxt(a.red, b.red, c.red, d.red)), y(vectorxt(a.green, b.green, c.green, d.green)), z(vectorxt(a.blue, b.blue, c.blue, d.blue)) { }
		const vectorx & operator[] (int i) const { sxassert((0<=i)&&(i<3)); return (&x)[i]; }
		vectorx &operator[] (int i) { sxassert(0<=i&&i<3); return (&x)[i]; }
		void set (int i, const vectorx &v) { sx::floatp(x)[i] = sx::floatp(v)[0]; sx::floatp(y)[i] = sx::floatp(v)[1]; sx::floatp(z)[i] = sx::floatp(v)[2]; }
		template<typename U> void set (int i, const vec<U,3> &v) { sx::floatp(x)[i] = v.x; sx::floatp(y)[i] = v.y; sx::floatp(z)[i] = v.z; }
		template<typename U> void set (int i, const rgb<U> &c) { sx::floatp(x)[i] = c.red; sx::floatp(y)[i] = c.green; sx::floatp(z)[i] = c.blue; }
		int size () const { return 3; }
		void check_invariant () const { sx::check_invariant(x); sx::check_invariant(y); sx::check_invariant(z); }

		void transpose () {
			#if SXSIMD
				#if __ARM_NEON__
					__m128_union u0; u0.m = x;
					__m128_union u1; u1.m = y;
					__m128_union u2; u2.m = z;
					x = sx::vectorxt(u0.f[0], u1.f[0], u2.f[0], 0.0f);
					y = sx::vectorxt(u0.f[1], u1.f[1], u2.f[1], 0.0f);
					z = sx::vectorxt(u0.f[2], u1.f[2], u2.f[2], 0.0f);
				#else
					const vectorx tmp_xy(_mm_unpacklo_ps(x, y));
					const vectorx tmp_z(_mm_unpackhi_ps(x, y));
					x = _mm_movelh_ps(tmp_xy, z);
					y = _mm_movehl_ps(_mm_unpacklo_ps(z, z), tmp_xy);
					z = _mm_movelh_ps(tmp_z, _mm_unpackhi_ps(z, z));
				#endif
			#else
				const vec<vectorx,3> t(*this);
				x = sx::vectorxt(t.x[0], t.y[0], t.z[0], 0.0f);
				y = sx::vectorxt(t.x[1], t.y[1], t.z[1], 0.0f);
				z = sx::vectorxt(t.x[2], t.y[2], t.z[2], 0.0f);
			#endif
		}
	};

	template <> class vec<vectorx,4> : public sx::memory::object {
	public:
		typedef vectorx value_type;
		typedef vectorx &reference;
		typedef const vectorx &const_reference;
		typedef vectorx *iterator;
		vectorx x, y, z, w;

		explicit vec () { }
		explicit vec (float f) : x(vectorxt(f)), y(vectorxt(f)), z(vectorxt(f)), w(vectorxt(f)) { }
		explicit vec (const vectorx &v) : x(splat<0>(v)), y(splat<1>(v)), z(splat<2>(v)), w(splat<3>(v)) { }
		explicit vec (const vectorx &x, const vectorx &y, const vectorx &z, const vectorx &w) : x(x), y(y), z(z), w(w) { }
		template<typename U> explicit vec (const vec<U,2> &v, float z, float w) : x(vectorxt(v.x)), y(vectorxt(v.y)), z(vectorxt(z)), w(vectorxt(w)) { }
		template<typename U> explicit vec (const vec<U,3> &v, float w) : x(vectorxt(v.x)), y(vectorxt(v.y)), z(vectorxt(v.z)), w(vectorxt(w)) { }
		template<typename U> explicit vec (const vec<U,4> &v) : x(vectorxt(v.x)), y(vectorxt(v.y)), z(vectorxt(v.z)), w(vectorxt(v.w)) { }
		template<typename U> explicit vec (const vec<U,4> &a, const vec<U,4> &b, const vec<U,4> &c, const vec<U,4> &d) : x(vectorxt(a.x, b.x, c.x, d.x)), y(vectorxt(a.y, b.y, c.y, d.y)), z(vectorxt(a.z, b.z, c.z, d.z)), w(vectorxt(a.w, b.w, c.w, d.w)) { }
		template<typename U> explicit vec (const rgba<U> &c) : x(vectorxt(c.red)), y(vectorxt(c.green)), z(vectorxt(c.blue)), w(vectorxt(c.alpha)) { }
		template<typename U> explicit vec (const rgba<U> &a, const rgba<U> &b, const rgba<U> &c, const rgba<U> &d) : x(vectorxt(a.red, b.red, c.red, d.red)), y(vectorxt(a.green, b.green, c.green, d.green)), z(vectorxt(a.blue, b.blue, c.blue, d.blue)), w(vectorxt(a.alpha, b.alpha, c.alpha, d.alpha)) { }
		const vectorx & operator[] (int i) const { sxassert(0<=i&&i<4); return (&x)[i]; }
		vectorx &operator[] (int i) { sxassert(0<=i&&i<4); return (&x)[i]; }
		void set (int i, const vectorx &v) { sx::floatp(x)[i] = sx::floatp(v)[0]; sx::floatp(y)[i] = sx::floatp(v)[1]; sx::floatp(z)[i] = sx::floatp(v)[2]; sx::floatp(w)[i] = sx::floatp(v)[3]; }
		template<typename U> void set (int i, const vec<U,4> &v) { sx::floatp(x)[i] = v.x; sx::floatp(y)[i] = v.y; sx::floatp(z)[i] = v.z; sx::floatp(w)[i] = v.w; }
		template<typename U> void set (int i, const rgba<U> &c) { sx::floatp(x)[i] = c.red; sx::floatp(y)[i] = c.green; sx::floatp(z)[i] = c.blue; sx::floatp(w)[i] = c.alpha; }
		int size () const { return 4; }
		void check_invariant () const { sx::check_invariant(x); sx::check_invariant(y); sx::check_invariant(z); sx::check_invariant(w); }

		void transpose () {
			#if SXSIMD
				#if __ARM_NEON__
					__m128_union u0; u0.m = x;
					__m128_union u1; u1.m = y;
					__m128_union u2; u2.m = z;
					__m128_union u3; u3.m = w;
					x = sx::vectorxt(u0.f[0], u1.f[0], u2.f[0], u3.f[0]);
					y = sx::vectorxt(u0.f[1], u1.f[1], u2.f[1], u3.f[1]);
					z = sx::vectorxt(u0.f[2], u1.f[2], u2.f[2], u3.f[2]);
					w = sx::vectorxt(u0.f[3], u1.f[3], u2.f[3], u3.f[3]);
				#else
					_MM_TRANSPOSE4_PS(x, y, z, w);
				#endif
			#else
				const vec<vectorx,4> t(*this);
				x = sx::vectorxt(t.x[0], t.y[0], t.z[0], t.w[0]);
				y = sx::vectorxt(t.x[1], t.y[1], t.z[1], t.w[1]);
				z = sx::vectorxt(t.x[2], t.y[2], t.z[2], t.w[2]);
				w = sx::vectorxt(t.x[3], t.y[3], t.z[3], t.w[3]);
			#endif
		}
	};

	inline const vectorx zerox (const vec<vectorx,2> &v) {
		return andx(zerox(v.x), zerox(v.y));
	}
	inline const vectorx zerox (const vec<vectorx,3> &v) {
		return andx(andx(zerox(v.x), zerox(v.y)), zerox(v.z));
	}
	inline const vectorx zerox (const vec<vectorx,4> &v) {
		return andx(andx(andx(zerox(v.x), zerox(v.y)), zerox(v.z)), zerox(v.w));
	}
	inline const vectorx ltx (const vec<vectorx,2> &v, const vectorx &b) {
		return andx(ltx(v.x, b), ltx(v.y, b));
	}
	inline const vectorx ltx (const vec<vectorx,3> &v, const vectorx &b) {
		return andx(andx(ltx(v.x, b), ltx(v.y, b)), ltx(v.z, b));
	}
	inline const vectorx ltx (const vec<vectorx,4> &v, const vectorx &b) {
		return andx(andx(andx(ltx(v.x, b), ltx(v.y, b)), ltx(v.z, b)), ltx(v.w, b));
	}
	inline const vectorx lex (const vec<vectorx,2> &v, const vectorx &b) {
		return andx(lex(v.x, b), lex(v.y, b));
	}
	inline const vectorx lex (const vec<vectorx,3> &v, const vectorx &b) {
		return andx(andx(lex(v.x, b), lex(v.y, b)), lex(v.z, b));
	}
	inline const vectorx lex (const vec<vectorx,4> &v, const vectorx &b) {
		return andx(andx(andx(lex(v.x, b), lex(v.y, b)), lex(v.z, b)), lex(v.w, b));
	}
	inline const vectorx ltx (const vectorx &a, const vec<vectorx,2> &v) {
		return andx(ltx(a, v.x), ltx(a, v.y));
	}
	inline const vectorx ltx (const vectorx &a, const vec<vectorx,3> &v) {
		return andx(andx(ltx(a, v.x), ltx(a, v.y)), ltx(a, v.z));
	}
	inline const vectorx ltx (const vectorx &a, const vec<vectorx,4> &v) {
		return andx(andx(andx(ltx(a, v.x), ltx(a, v.y)), ltx(a, v.z)), ltx(a, v.w));
	}
	inline const vectorx lex (const vectorx &a, const vec<vectorx,2> &v) {
		return andx(lex(a, v.x), lex(a, v.y));
	}
	inline const vectorx lex (const vectorx &a, const vec<vectorx,3> &v) {
		return andx(andx(lex(a, v.x), lex(a, v.y)), lex(a, v.z));
	}
	inline const vectorx lex (const vectorx &a, const vec<vectorx,4> &v) {
		return andx(andx(andx(lex(a, v.x), lex(a, v.y)), lex(a, v.z)), lex(a, v.w));
	}
	inline const vectorx ltx (const vec<vectorx,2> &a, const vec<vectorx,2> &b) {
		return andx(ltx(a.x, b.x), ltx(a.y, b.y));
	}
	inline const vectorx ltx (const vec<vectorx,3> &a, const vec<vectorx,3> &b) {
		return andx(andx(ltx(a.x, b.x), ltx(a.y, b.y)), ltx(a.z, b.z));
	}
	inline const vectorx ltx (const vec<vectorx,4> &a, const vec<vectorx,4> &b) {
		return andx(andx(andx(ltx(a.x, b.x), ltx(a.y, b.y)), ltx(a.z, b.z)), ltx(a.w, b.w));
	}
	inline const vectorx lex (const vec<vectorx,2> &a, const vec<vectorx,2> &b) {
		return andx(lex(a.x, b.x), lex(a.y, b.y));
	}
	inline const vectorx lex (const vec<vectorx,3> &a, const vec<vectorx,3> &b) {
		return andx(andx(lex(a.x, b.x), lex(a.y, b.y)), lex(a.z, b.z));
	}
	inline const vectorx lex (const vec<vectorx,4> &a, const vec<vectorx,4> &b) {
		return andx(andx(andx(lex(a.x, b.x), lex(a.y, b.y)), lex(a.z, b.z)), lex(a.w, b.w));
	}

	inline const vec<float,2> vectort (const vec<vectorx,2> &v, int i) {
		return vec<float,2>(floatp(v.x)[i], floatp(v.y)[i]);
	}
	inline const vec<float,3> vectort (const vec<vectorx,3> &v, int i) {
		return vec<float,3>(floatp(v.x)[i], floatp(v.y)[i], floatp(v.z)[i]);
	}
	inline const vec<float,4> vectort (const vec<vectorx,4> &v, int i) {
		return vec<float,4>(floatp(v.x)[i], floatp(v.y)[i], floatp(v.z)[i], floatp(v.w)[i]);
	}
	inline const rgb<float> rgbt (const vec<vectorx,3> &v, int i) {
		return rgb<float>(floatp(v.x)[i], floatp(v.y)[i], floatp(v.z)[i]);
	}
	inline const rgba<float> rgbat (const vec<vectorx,4> &v, int i) {
		return rgba<float>(floatp(v.x)[i], floatp(v.y)[i], floatp(v.z)[i], floatp(v.w)[i]);
	}

	inline const sx::vec<vectorx,2> normalize (const sx::vec<vectorx,2> &p) {
		const vectorx d(sqrabsolute2(p));
		return p * rsqrt(conditional(ltx(vepsilon, d), d, vone));
	}
	inline const sx::vec<vectorx,3> normalize (const sx::vec<vectorx,3> &p) {
		const vectorx d(sqrabsolute3(p));
		return p * rsqrt(conditional(ltx(vepsilon, d), d, vone));
	}
	inline const sx::vec<vectorx,4> normalize (const sx::vec<vectorx,4> &p) {
		const vectorx d(sqrabsolute4(p));
		return p * rsqrt(conditional(ltx(vepsilon, d), d, vone));
	}
	inline const vectorx normalize_self (sx::vec<vectorx,2> &p) {
		const vectorx e(sqrabsolute2(p));
		const vectorx b(ltx(vepsilon, e));
		const vectorx d(rsqrt(conditional(b, e, vone)));
		p *= d;
		return conditional(b, rcp(d), e);
	}
	inline const vectorx normalize_self (sx::vec<vectorx,3> &p) {
		const vectorx e(sqrabsolute3(p));
		const vectorx b(ltx(vepsilon, e));
		const vectorx d(rsqrt(conditional(b, e, vone)));
		p *= d;
		return conditional(b, rcp(d), e);
	}


	template<int i> inline const vectorx transformi (const sx::vec<vectorx,3> &p, const matrixx &t) {
		return p.x * splat<i>(t[0]) + p.y * splat<i>(t[1]) + p.z * splat<i>(t[2]) + splat<i>(t[3]);
	}
	inline const sx::vec<vectorx,3> transform33 (const sx::vec<vectorx,3> &p, const matrixx &t) {
		return sx::vec<vectorx,3>(transformi<0>(p, t), transformi<1>(p, t), transformi<2>(p, t));
	}
	template<int i> inline const vectorx transformi (const sx::vec<vectorx,4> &p, const matrixx &t) {
		return p.x * splat<i>(t[0]) + p.y * splat<i>(t[1]) + p.z * splat<i>(t[2]) + p.w * splat<i>(t[3]);
	}
	inline const sx::vec<vectorx,4> transform44 (const sx::vec<vectorx,4> &p, const matrixx &t) {
		return sx::vec<vectorx,4>(transformi<0>(p, t), transformi<1>(p, t), transformi<2>(p, t), transformi<3>(p, t));
	}
}
template<int N> inline bool operator< (const sx::vec<sx::vectorx,N> &a, const sx::vec<sx::vectorx,N> &b) {
	for (int i = 0; i < N; ++i) if (!sx::lt(a[i], b[i])) return false;
	return true;
}
template<int N> inline bool operator<= (const sx::vec<sx::vectorx,N> &a, const sx::vec<sx::vectorx,N> &b) {
	for (int i = 0; i < N; ++i) if (!sx::le(a[i], b[i])) return false;
	return true;
}
template<int N> inline bool operator== (const sx::vec<sx::vectorx,N> &a, const sx::vec<sx::vectorx,N> &b) {
	for (int i = 0; i < N; ++i) if (!sx::eq(a[i], b[i])) return false;
	return true;
}
template<int N> inline bool operator!= (const sx::vec<sx::vectorx,N> &a, const sx::vec<sx::vectorx,N> &b) {
	return !(a == b);
}

namespace boost {
	template <> struct has_trivial_constructor<sx::vec<sx::vectorx,2> > : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vec<sx::vectorx,2> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<sx::vectorx,2> > : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vec<sx::vectorx,2> > : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vec<sx::vectorx,2> > : public boost::true_type { };

	template <> struct has_trivial_constructor<sx::vec<sx::vectorx,3> > : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vec<sx::vectorx,3> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<sx::vectorx,3> > : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vec<sx::vectorx,3> > : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vec<sx::vectorx,3> > : public boost::true_type { };

	template <> struct has_trivial_constructor<sx::vec<sx::vectorx,4> > : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vec<sx::vectorx,4> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<sx::vectorx,4> > : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vec<sx::vectorx,4> > : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vec<sx::vectorx,4> > : public boost::true_type { };
}
namespace std {
	template<> class numeric_limits<sx::vec<sx::vectorx,2> > {
	public:
		static sx::vec<sx::vectorx,2> max () { return sx::vec<sx::vectorx,2>(std::numeric_limits<sx::vectorx>::max()); }
	};

	template<> class numeric_limits<sx::vec<sx::vectorx,3> > {
	public:
		static sx::vec<sx::vectorx,3> max () { return sx::vec<sx::vectorx,3>(std::numeric_limits<sx::vectorx>::max()); }
	};

	template<> class numeric_limits<sx::vec<sx::vectorx,4> > {
	public:
		static sx::vec<sx::vectorx,4> max () { return sx::vec<sx::vectorx,4>(std::numeric_limits<sx::vectorx>::max()); }
	};
}

std::ostream &operator<< (std::ostream &stream, sx::vectorx v);

namespace sx {
	namespace core {
		namespace unittest {
			void test_simd ();
		}
	}
}
