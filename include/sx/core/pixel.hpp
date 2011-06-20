#pragma once
SXCORE
#include "sx/core/vectors.hpp"
#include "Half/half.h"

namespace sx {

	#if SXWINDOWS
		inline const sx::rgb<float> vector3t (COLORREF colorref) {
			return sx::rgb<float>(GetRValue(colorref) * (1.0f/255.0f), GetGValue(colorref) * (1.0f/255.0f), GetBValue(colorref) * (1.0f/255.0f));
		}
		inline const sx::rgba<float> vector4t (COLORREF colorref) {
			return sx::rgba<float>(GetRValue(colorref) * (1.0f/255.0f), GetGValue(colorref) * (1.0f/255.0f), GetBValue(colorref) * (1.0f/255.0f), 1.0f);
		}
		inline const COLORREF RGB_ (const sx::rgb<float> &v) {
			const sx::rgb<float> c = sx::clamp(v);
			return RGB(BYTE(c.red*255.0f+0.5f), BYTE(c.green*255.0f+0.5f), BYTE(c.blue*255.0f+0.5f));
		}
	#endif

	typedef sx::rgb<sx::unsigned8> pixel24;
	typedef sx::rgba<sx::unsigned8> pixel32;
	typedef sx::rgba<sx::unsigned8,RGBA> rgba8_class;

	namespace pixel {
		// pixel operations
		inline sx::rgba<float> multiply_alpha (const sx::rgba<float> &c) {
			return sx::rgba<float>(c * c.alpha, c.alpha);
		}
		inline sx::rgba<float> alpha_blend (const sx::rgba<float> &d, const sx::rgba<float> &s) {
			return sx::rgba<float>(d + (s * (1.0f-d.alpha)), d.alpha);
		}
		inline sx::rgba<float> add (const sx::rgba<float> &d, const sx::rgba<float> &s) {
			return sx::rgba<float>(d + s, d.alpha);
		}
		inline sx::rgba<float> sub (const sx::rgba<float> &d, const sx::rgba<float> &s) {
			return sx::rgba<float>(d - s, d.alpha);
		}
		inline sx::rgba<float> mul (const sx::rgba<float> &d, const sx::rgba<float> &s) {
			return sx::rgba<float>(d * s, d.alpha);
		}
		inline sx::rgba<float> min (const sx::rgba<float> &d, const sx::rgba<float> &s) {
			return sx::rgba<float>(sx::min(d, s), d.alpha);
		}
		inline sx::rgba<float> max (const sx::rgba<float> &d, const sx::rgba<float> &s) {
			return sx::rgba<float>(sx::max(d, s), d.alpha);
		}
		inline sx::rgba<float> blend (const sx::rgba<float> &d, const sx::rgba<float> &s, float weight) {
			return sx::rgba<float>((d * (std::max((1.0f-weight), 0.0f))) + (s * weight), d.alpha);
		}

		namespace imp {
			template<typename T, typename U> inline T convert (U u);
			template<typename T, typename U> inline T convert (U u, U v, U w);

			template<> inline sx::unsigned8 convert (sx::unsigned8 u) { return u; }
			template<> inline sx::unsigned8 convert (sx::unsigned16 u) { return sx::unsigned8(u >> 8); }
			template<> inline sx::unsigned8 convert (sx::unsigned32 u) { return sx::unsigned8(u >> 24); }
			template<> inline sx::unsigned8 convert (half u) { return sx::unsigned8(sx::clamp(float(u)) * float(std::numeric_limits<sx::unsigned8>::max()) + 0.5f); }
			template<> inline sx::unsigned8 convert (float u) { return sx::unsigned8(sx::clamp(u) * float(std::numeric_limits<sx::unsigned8>::max()) + 0.5f); }

			template<> inline sx::unsigned16 convert (sx::unsigned8 u) { return (sx::unsigned16(u) << 8) + sx::unsigned16(u); }
			template<> inline sx::unsigned16 convert (sx::unsigned16 u) { return u; }
			template<> inline sx::unsigned16 convert (sx::unsigned32 u) { return sx::unsigned16(u >> 16); }
			template<> inline sx::unsigned16 convert (half u) { return sx::unsigned16(sx::clamp(float(u)) * float(std::numeric_limits<sx::unsigned16>::max()) + 0.5f); }
			template<> inline sx::unsigned16 convert (float u) { return sx::unsigned16(sx::clamp(u) * float(std::numeric_limits<sx::unsigned16>::max()) + 0.5f); }

			template<> inline sx::unsigned32 convert (sx::unsigned8 u) { return (sx::unsigned32(u) << 24) + (sx::unsigned32(u) << 16) + (sx::unsigned32(u) << 8) + sx::unsigned32(u); }
			template<> inline sx::unsigned32 convert (sx::unsigned16 u) { return (sx::unsigned32(u) << 16) + sx::unsigned32(u); }
			template<> inline sx::unsigned32 convert (sx::unsigned32 u) { return u; }
			template<> inline sx::unsigned32 convert (half u) { return sx::unsigned32(sx::clamp(float(u)) * float(std::numeric_limits<sx::unsigned32>::max()) + 0.5f); }
			template<> inline sx::unsigned32 convert (float u) { return sx::unsigned32(sx::clamp(u) * float(std::numeric_limits<sx::unsigned32>::max()) + 0.5f); }

			template<> inline half convert (sx::unsigned8 u) { return half(float(u) / float(std::numeric_limits<sx::unsigned8>::max())); }
			template<> inline half convert (sx::unsigned16 u) { return half(float(u) / float(std::numeric_limits<sx::unsigned16>::max())); }
			template<> inline half convert (sx::unsigned32 u) { return half(float(u) / float(std::numeric_limits<sx::unsigned32>::max())); }
			template<> inline half convert (half u) { return u; }
			template<> inline half convert (float u) { return half(u); }

			template<> inline float convert (sx::unsigned8 u) { return (u / float(std::numeric_limits<sx::unsigned8>::max())); }
			template<> inline float convert (sx::unsigned16 u) { return (u / float(std::numeric_limits<sx::unsigned16>::max())); }
			template<> inline float convert (sx::unsigned32 u) { return (u / float(std::numeric_limits<sx::unsigned32>::max())); }
			template<> inline float convert (half u) { return float(u); }
			template<> inline float convert (float u) { return u; }

			template<> inline sx::unsigned8 convert (sx::unsigned8 u, sx::unsigned8 v, sx::unsigned8 w) { return sx::unsigned8((unsigned(u) + unsigned(v) + unsigned(w) + 2) / 3); }
			template<> inline sx::unsigned8 convert (sx::unsigned16 u, sx::unsigned16 v, sx::unsigned16 w) { return imp::convert<sx::unsigned8>(sx::unsigned16((unsigned(u) + unsigned(v) + unsigned(w) + 2) / 3)); }
			template<> inline sx::unsigned8 convert (sx::unsigned32 u, sx::unsigned32 v, sx::unsigned32 w) { return imp::convert<sx::unsigned8>(sx::unsigned32((sx::unsigned64(u) + sx::unsigned64(v) + sx::unsigned64(w) + 2) / 3)); }
			template<> inline sx::unsigned8 convert (half u, half v, half w) { return imp::convert<sx::unsigned8>((float(u) + float(v) + float(w)) * (1.0f/3.0f)); }
			template<> inline sx::unsigned8 convert (float u, float v, float w) { return imp::convert<sx::unsigned8>((u + v + w) * (1.0f/3.0f)); }

			template<> inline sx::unsigned16 convert (sx::unsigned8 u, sx::unsigned8 v, sx::unsigned8 w) { return imp::convert<sx::unsigned16>(sx::unsigned8((unsigned(u) + unsigned(v) + unsigned(w) + 2) / 3)); }
			template<> inline sx::unsigned16 convert (sx::unsigned16 u, sx::unsigned16 v, sx::unsigned16 w) { return sx::unsigned16((unsigned(u) + unsigned(v) + unsigned(w) + 2) / 3); }
			template<> inline sx::unsigned16 convert (sx::unsigned32 u, sx::unsigned32 v, sx::unsigned32 w) { return imp::convert<sx::unsigned16>(sx::unsigned32((sx::unsigned64(u) + sx::unsigned64(v) + sx::unsigned64(w) + 2) / 3)); }
			template<> inline sx::unsigned16 convert (half u, half v, half w) { return imp::convert<sx::unsigned16>((float(u) + float(v) + float(w)) * (1.0f/3.0f)); }
			template<> inline sx::unsigned16 convert (float u, float v, float w) { return imp::convert<sx::unsigned16>((u + v + w) * (1.0f/3.0f)); }

			template<> inline sx::unsigned32 convert (sx::unsigned8 u, sx::unsigned8 v, sx::unsigned8 w) { return imp::convert<sx::unsigned32>(sx::unsigned8((unsigned(u) + unsigned(v) + unsigned(w) + 2) / 3)); }
			template<> inline sx::unsigned32 convert (sx::unsigned16 u, sx::unsigned16 v, sx::unsigned16 w) { return imp::convert<sx::unsigned32>(sx::unsigned16((unsigned(u) + unsigned(v) + unsigned(w) + 2) / 3)); }
			template<> inline sx::unsigned32 convert (sx::unsigned32 u, sx::unsigned32 v, sx::unsigned32 w) { return sx::unsigned32((sx::unsigned64(u) + sx::unsigned64(v) + sx::unsigned64(w) + 2) / 3); }
			template<> inline sx::unsigned32 convert (half u, half v, half w) { return imp::convert<sx::unsigned32>((float(u) + float(v) + float(w)) * (1.0f/3.0f)); }
			template<> inline sx::unsigned32 convert (float u, float v, float w) { return imp::convert<sx::unsigned32>((u + v + w) * (1.0f/3.0f)); }

			template<> inline half convert (sx::unsigned8 u, sx::unsigned8 v, sx::unsigned8 w) { return half((float(u) + float(v) + float(w)) / (float(std::numeric_limits<sx::unsigned8>::max()) * 3.0f)); }
			template<> inline half convert (sx::unsigned16 u, sx::unsigned16 v, sx::unsigned16 w) { return half((float(u) + float(v) + float(w)) / (float(std::numeric_limits<sx::unsigned16>::max()) * 3.0f)); }
			template<> inline half convert (sx::unsigned32 u, sx::unsigned32 v, sx::unsigned32 w) { return half((float(u) + float(v) + float(w)) / (float(std::numeric_limits<sx::unsigned32>::max()) * 3.0f)); }
			template<> inline half convert (half u, half v, half w) { return half((float(u) + float(v) + float(w)) / 3.0f); }
			template<> inline half convert (float u, float v, float w) { return half((u + v + w) / 3.0f); }

			template<> inline float convert (sx::unsigned8 u, sx::unsigned8 v, sx::unsigned8 w) { return ((float(u) + float(v) + float(w)) / (float(std::numeric_limits<sx::unsigned8>::max()) * 3.0f)); }
			template<> inline float convert (sx::unsigned16 u, sx::unsigned16 v, sx::unsigned16 w) { return ((float(u) + float(v) + float(w)) / (float(std::numeric_limits<sx::unsigned16>::max()) * 3.0f)); }
			template<> inline float convert (sx::unsigned32 u, sx::unsigned32 v, sx::unsigned32 w) { return ((float(u) + float(v) + float(w)) / (float(std::numeric_limits<sx::unsigned32>::max()) * 3.0f)); }
			template<> inline float convert (half u, half v, half w) { return ((float(u) + float(v) + float(w)) / 3.0f); }
			template<> inline float convert (float u, float v, float w) { return ((u + v + w) / 3.0f); }
			
			#if SXMACOSX && __OBJC__
				static sx::rgba<float> convert (NSColor *nscolor) {
					NSColor *const color = [nscolor colorUsingColorSpaceName:@"NSDeviceRGBColorSpace"];
					#if CGFLOAT_DEFINED
						CGFloat r, g, b, a;
					#else
						float r, g, b, a;
					#endif
					[color getRed:&r green:&g blue:&b alpha:&a];
					return sx::rgba<float>(r, g, b, a);
				}
			#endif
		}

		//template<typename T> inline void convert (T &t, const T &u) { t = u; }
		template<typename T, typename U> inline T convert (U u);
		
		// target: sx::unsigned8
		inline void convert (sx::unsigned8 &t, sx::unsigned8 u) {
			t = imp::convert<sx::unsigned8>(u);
		}
		inline void convert (sx::unsigned8 &t, sx::unsigned16 u) {
			t = imp::convert<sx::unsigned8>(u);
		}
		inline void convert (sx::unsigned8 &t, sx::unsigned32 u) {
			t = imp::convert<sx::unsigned8>(u);
		}
		inline void convert (sx::unsigned8 &t, half u) {
			t = imp::convert<sx::unsigned8>(u);
		}
		inline void convert (sx::unsigned8 &t, float u) {
			t = imp::convert<sx::unsigned8>(u);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgb<sx::unsigned8,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgba<sx::unsigned8,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgb<sx::unsigned32,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgba<sx::unsigned32,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgb<half,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgba<half,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgb<float,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned8 &t, const sx::rgba<float,K> &u) {
			t = imp::convert<sx::unsigned8>(u.red, u.green, u.blue);
		}

		// target: sx::unsigned16
		inline void convert (sx::unsigned16 &t, sx::unsigned8 u) {
			t = imp::convert<sx::unsigned16>(u);
		}
		inline void convert (sx::unsigned16 &t, sx::unsigned16 u) {
			t = imp::convert<sx::unsigned16>(u);
		}
		inline void convert (sx::unsigned16 &t, sx::unsigned32 u) {
			t = imp::convert<sx::unsigned16>(u);
		}
		inline void convert (sx::unsigned16 &t, half u) {
			t = imp::convert<sx::unsigned16>(u);
		}
		inline void convert (sx::unsigned16 &t, float u) {
			t = imp::convert<sx::unsigned16>(u);
		}
		template<int K> inline void convert (sx::unsigned16 &t, const sx::rgb<sx::unsigned8,K> &u) {
			t = imp::convert<sx::unsigned16>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned16 &t, const sx::rgba<sx::unsigned8,K> &u) {
			t = imp::convert<sx::unsigned16>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned16 &t, const sx::rgb<half,K> &u) {
			t = imp::convert<sx::unsigned16>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned16 &t, const sx::rgba<half,K> &u) {
			t = imp::convert<sx::unsigned16>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned16 &t, const sx::rgb<float,K> &u) {
			t = imp::convert<sx::unsigned16>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned16 &t, const sx::rgba<float,K> &u) {
			t = imp::convert<sx::unsigned16>(u.red, u.green, u.blue);
		}

		// target: sx::unsigned32
		inline void convert (sx::unsigned32 &t, sx::unsigned8 u) {
			t = imp::convert<sx::unsigned32>(u);
		}
		inline void convert (sx::unsigned32 &t, sx::unsigned16 u) {
			t = imp::convert<sx::unsigned32>(u);
		}
		inline void convert (sx::unsigned32 &t, sx::unsigned32 u) {
			t = imp::convert<sx::unsigned32>(u);
		}
		inline void convert (sx::unsigned32 &t, half u) {
			t = imp::convert<sx::unsigned32>(u);
		}
		inline void convert (sx::unsigned32 &t, float u) {
			t = imp::convert<sx::unsigned32>(u);
		}
		template<int K> inline void convert (sx::unsigned32 &t, const sx::rgb<sx::unsigned8,K> &u) {
			t = imp::convert<sx::unsigned32>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned32 &t, const sx::rgba<sx::unsigned8,K> &u) {
			t = imp::convert<sx::unsigned32>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned32 &t, const sx::rgb<half,K> &u) {
			t = imp::convert<sx::unsigned32>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned32 &t, const sx::rgba<half,K> &u) {
			t = imp::convert<sx::unsigned32>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned32 &t, const sx::rgb<float,K> &u) {
			t = imp::convert<sx::unsigned32>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (sx::unsigned32 &t, const sx::rgba<float,K> &u) {
			t = imp::convert<sx::unsigned32>(u.red, u.green, u.blue);
		}

		// target: half
		inline void convert (half &t, sx::unsigned8 u) {
			t = imp::convert<half>(u);
		}
		inline void convert (half &t, sx::unsigned16 u) {
			t = imp::convert<half>(u);
		}
		inline void convert (half &t, sx::unsigned32 u) {
			t = imp::convert<half>(u);
		}
		inline void convert (half &t, half u) {
			t = imp::convert<half>(u);
		}
		inline void convert (half &t, float u) {
			t = imp::convert<half>(u);
		}
		template<int K> inline void convert (half &t, const sx::rgb<sx::unsigned8,K> &u) {
			t = imp::convert<half>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (half &t, const sx::rgba<sx::unsigned8,K> &u) {
			t = imp::convert<half>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (half &t, const sx::rgb<half,K> &u) {
			t = imp::convert<half>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (half &t, const sx::rgba<half,K> &u) {
			t = imp::convert<half>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (half &t, const sx::rgb<float,K> &u) {
			t = imp::convert<half>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (half &t, const sx::rgba<float,K> &u) {
			t = imp::convert<half>(u.red, u.green, u.blue);
		}

		// target: float
		inline void convert (float &t, sx::unsigned8 u) {
			t = imp::convert<float>(u);
		}
		inline void convert (float &t, sx::unsigned16 u) {
			t = imp::convert<float>(u);
		}
		inline void convert (float &t, sx::unsigned32 u) {
			t = imp::convert<float>(u);
		}
		inline void convert (float &t, half u) {
			t = imp::convert<float>(u);
		}
		inline void convert (float &t, float u) {
			t = imp::convert<float>(u);
		}
		template<int K> inline void convert (float &t, const sx::rgb<sx::unsigned8,K> &u) {
			t = imp::convert<float>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (float &t, const sx::rgba<sx::unsigned8,K> &u) {
			t = imp::convert<float>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (float &t, const sx::rgb<half,K> &u) {
			t = imp::convert<float>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (float &t, const sx::rgba<half,K> &u) {
			t = imp::convert<float>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (float &t, const sx::rgb<float,K> &u) {
			t = imp::convert<float>(u.red, u.green, u.blue);
		}
		template<int K> inline void convert (float &t, const sx::rgba<float,K> &u) {
			t = imp::convert<float>(u.red, u.green, u.blue);
		}

		// target: sx::rgb<sx::unsigned8,K>
		template<int K> inline void convert (sx::rgb<sx::unsigned8,K> &t, sx::unsigned8 u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<sx::unsigned8,K> &t, sx::unsigned16 u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<sx::unsigned8,K> &t, sx::unsigned32 u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<sx::unsigned8,K> &t, half u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<sx::unsigned8,K> &t, float u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K, int L> inline void convert (sx::rgb<sx::unsigned8,K> &t, const sx::rgb<sx::unsigned8,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<sx::unsigned8,K> &t, const sx::rgba<sx::unsigned8,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<sx::unsigned8,K> &t, const sx::rgb<half,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<sx::unsigned8,K> &t, const sx::rgba<half,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<sx::unsigned8,K> &t, const sx::rgb<float,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<sx::unsigned8,K> &t, const sx::rgba<float,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue);
		}
		
		// target: sx::rgba<sx::unsigned8,K>
		template<int K> inline void convert (sx::rgba<sx::unsigned8,K> &t, sx::unsigned8 u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned8,K> &t, sx::unsigned16 u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned8,K> &t, sx::unsigned32 u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned8,K> &t, half u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned8,K> &t, float u) {
			const sx::unsigned8 k = imp::convert<sx::unsigned8>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgba<sx::unsigned16,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = imp::convert<sx::unsigned8>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgb<sx::unsigned8,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgba<sx::unsigned8,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = imp::convert<sx::unsigned8>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgb<sx::unsigned32,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgba<sx::unsigned32,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = imp::convert<sx::unsigned8>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgb<half,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgba<half,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = imp::convert<sx::unsigned8>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgb<float,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = std::numeric_limits<sx::unsigned8>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned8,K> &t, const sx::rgba<float,L> &u) {
			t.red = imp::convert<sx::unsigned8>(u.red); t.green = imp::convert<sx::unsigned8>(u.green); t.blue = imp::convert<sx::unsigned8>(u.blue); t.alpha = imp::convert<sx::unsigned8>(u.alpha);
		}

		// target: sx::rgba<sx::unsigned32,K>
		template<int K> inline void convert (sx::rgba<sx::unsigned32,K> &t, sx::unsigned8 u) {
			const sx::unsigned32 k = imp::convert<sx::unsigned32>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned32,K> &t, sx::unsigned16 u) {
			const sx::unsigned32 k = imp::convert<sx::unsigned32>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned32,K> &t, sx::unsigned32 u) {
			const sx::unsigned32 k = imp::convert<sx::unsigned32>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned32,K> &t, half u) {
			const sx::unsigned32 k = imp::convert<sx::unsigned32>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned32,K> &t, float u) {
			const sx::unsigned32 k = imp::convert<sx::unsigned32>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgb<sx::unsigned8,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgba<sx::unsigned8,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = imp::convert<sx::unsigned32>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgb<sx::unsigned32,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgba<sx::unsigned32,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = imp::convert<sx::unsigned32>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgb<half,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgba<half,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = imp::convert<sx::unsigned32>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgb<float,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = std::numeric_limits<sx::unsigned32>::max();
		}
		template<int K, int L> inline void convert (sx::rgba<sx::unsigned32,K> &t, const sx::rgba<float,L> &u) {
			t.red = imp::convert<sx::unsigned32>(u.red); t.green = imp::convert<sx::unsigned32>(u.green); t.blue = imp::convert<sx::unsigned32>(u.blue); t.alpha = imp::convert<sx::unsigned32>(u.alpha);
		}

		// target: sx::rgb<half,K>
		template<int K> inline void convert (sx::rgb<half,K> &t, sx::unsigned8 u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<half,K> &t, sx::unsigned16 u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<half,K> &t, sx::unsigned32 u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K, int L> inline void convert (sx::rgb<half,K> &t, const sx::rgb<sx::unsigned8,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<half,K> &t, const sx::rgba<sx::unsigned8,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<half,K> &t, const sx::rgb<half,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<half,K> &t, const sx::rgba<half,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<half,K> &t, const sx::rgb<float,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<half,K> &t, const sx::rgba<float,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue);
		}
		
		// target: sx::rgba<half,K>
		template<int K> inline void convert (sx::rgba<half,K> &t, sx::unsigned8 u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = half(1.0f);
		}
		template<int K> inline void convert (sx::rgba<half,K> &t, sx::unsigned16 u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = half(1.0f);
		}
		template<int K> inline void convert (sx::rgba<half,K> &t, sx::unsigned32 u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = half(1.0f);
		}
		template<int K> inline void convert (sx::rgba<half,K> &t, half u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = half(1.0f);
		}
		template<int K> inline void convert (sx::rgba<half,K> &t, float u) {
			const half k = imp::convert<half>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = half(1.0f);
		}
		template<int K, int L> inline void convert (sx::rgba<half,K> &t, const sx::rgb<sx::unsigned8,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue); t.alpha = half(1.0f);
		}
		template<int K, int L> inline void convert (sx::rgba<half,K> &t, const sx::rgba<sx::unsigned8,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue); t.alpha = imp::convert<half>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<half,K> &t, const sx::rgba<sx::unsigned16,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue); t.alpha = imp::convert<half>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<half,K> &t, const sx::rgb<half,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue); t.alpha = half(1.0f);
		}
		template<int K, int L> inline void convert (sx::rgba<half,K> &t, const sx::rgba<half,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue); t.alpha = imp::convert<half>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<half,K> &t, const sx::rgb<float,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue); t.alpha = half(1.0f);
		}
		template<int K, int L> inline void convert (sx::rgba<half,K> &t, const sx::rgba<float,L> &u) {
			t.red = imp::convert<half>(u.red); t.green = imp::convert<half>(u.green); t.blue = imp::convert<half>(u.blue); t.alpha = imp::convert<half>(u.alpha);
		}

		// target: sx::rgb<float,K>
		template<int K> inline void convert (sx::rgb<float,K> &t, sx::unsigned8 u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<float,K> &t, sx::unsigned16 u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<float,K> &t, sx::unsigned32 u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<float,K> &t, half u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k;
		}
		template<int K> inline void convert (sx::rgb<float,K> &t, float u) {
			t.red = u; t.green = u; t.blue = u;
		}
		template<int K, int L> inline void convert (sx::rgb<float,K> &t, const sx::rgb<sx::unsigned8,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<float,K> &t, const sx::rgba<sx::unsigned8,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<float,K> &t, const sx::rgb<half,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<float,K> &t, const sx::rgba<half,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<float,K> &t, const sx::rgb<float,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue);
		}
		template<int K, int L> inline void convert (sx::rgb<float,K> &t, const sx::rgba<float,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue);
		}

		// target: sx::rgba<float,K>
		template<int K> inline void convert (sx::rgba<float,K> &t, sx::unsigned8 u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = 1.0f;
		}
		template<int K> inline void convert (sx::rgba<float,K> &t, sx::unsigned16 u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = 1.0f;
		}
		template<int K> inline void convert (sx::rgba<float,K> &t, sx::unsigned32 u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = 1.0f;
		}
		template<int K> inline void convert (sx::rgba<float,K> &t, half u) {
			const float k = imp::convert<float>(u);
			t.red = k; t.green = k; t.blue = k; t.alpha = 1.0f;
		}
		template<int K> inline void convert (sx::rgba<float,K> &t, float u) {
			t.red = u; t.green = u; t.blue = u; t.alpha = 1.0f;
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgb<sx::unsigned8,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = 1.0f;
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgba<sx::unsigned8,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = imp::convert<float>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgb<sx::unsigned16,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = 1.0f;
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgba<sx::unsigned16,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = imp::convert<float>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgb<half,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = 1.0f;
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgba<half,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = imp::convert<float>(u.alpha);
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgb<float,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = 1.0f;
		}
		template<int K, int L> inline void convert (sx::rgba<float,K> &t, const sx::rgba<float,L> &u) {
			t.red = imp::convert<float>(u.red); t.green = imp::convert<float>(u.green); t.blue = imp::convert<float>(u.blue); t.alpha = imp::convert<float>(u.alpha);
		}
		
		#if SXMACOSX && __OBJC__
			template<typename T> inline void convert (NSColor *&t, const T &u) {
				const sx::rgba<float> c = convert<sx::rgba<float> >(u);
				t = [NSColor colorWithDeviceRed:c.red green:c.green blue:c.blue alpha:c.alpha];
			}
			template<typename T> inline void convert (T &t, NSColor *u) {
				convert(t, imp::convert(u));
			}
		#endif

		template<typename T> inline void convert (T &t, sx::int32 u) {
			SXASSERT(false);
		}
		template<int K> inline void convert (sx::rgb<sx::unsigned8,K> &t, sx::int32 u) {
			t = sx::rgba<sx::unsigned8,K>((u & 0x00ff0000) >> 16, (u & 0x0000ff00) >> 8, (u & 0x000000ff));
		}
		template<int K> inline void convert (sx::rgba<sx::unsigned8,K> &t, sx::int32 u) {
			t = sx::rgba<sx::unsigned8,K>((u & 0x00ff0000) >> 16, (u & 0x0000ff00) >> 8, (u & 0x000000ff), 0);
		}
		template<typename U> inline void convert (sx::int32 &t, const U &u) {
			SXASSERT(false);
		}
		template<int K> inline void convert (sx::int32 &t, const sx::rgb<sx::unsigned8,K> &u) {
			t = (sx::unsigned32(u.red) << 16) | (sx::unsigned32(u.green) << 8) | (sx::unsigned32(u.blue));
		}
		template<int K> inline void convert (sx::int32 &t, const sx::rgba<sx::unsigned8,K> &u) {
			t = (sx::unsigned32(u.red) << 16) | (sx::unsigned32(u.green) << 8) | (sx::unsigned32(u.blue));
		}

		template<typename T, typename U> inline T convert (U u) { T t; convert(t, u); return t; }
	}

	class pixelop_interface {
	public:
		void operator() (sx::rgba<sx::unsigned8> *dst, const sx::rgba<float> *src, int n) const { pixelop_imp(dst, src, n); } // should be removed and cleaned up
		void operator() (sx::rgba<float> *dst, const sx::rgba<float> *src, int n) const { pixelopfloat_imp(dst, src, n); }
		virtual ~pixelop_interface () { }
	private:
		virtual void pixelop_imp (sx::rgba<sx::unsigned8> *dst, const sx::rgba<float> *src, int n) const { SXASSERT(false); } // should be removed and cleaned up
		virtual void pixelopfloat_imp (sx::rgba<float> *dst, const sx::rgba<float> *src, int n) const { SXASSERT(false); }
	};

	class opacity_pixelop_class : public pixelop_interface {
	public:
		explicit opacity_pixelop_class (float opacity) : opacity(opacity) { }
	private:
		const float opacity;
		virtual void pixelop_imp (sx::rgba<sx::unsigned8> *dst, const sx::rgba<float> *src, int n) const {
			for (int i = 0; i < n; ++i)  pixel::convert(dst[i], src[i] * opacity);
		}
	};
	extern opacity_pixelop_class opacity_pixelop;

}

inline const sx::rgba<sx::unsigned8> operator* (const sx::rgba<sx::unsigned8> &c, unsigned k) {
	return sx::rgba<sx::unsigned8>((c.red*k), (c.green*k), (c.blue*k), (c.alpha*k));
}

inline std::istream &operator> (std::istream &stream, sx::rgba<sx::unsigned8> &t) { stream.read((char *)(&t), sizeof(t)); return stream; }
inline std::istream &operator> (std::istream &stream, sx::rgba<half> &t) { stream.read((char *)(&t), sizeof(t)); return stream; }
inline std::ostream &operator< (std::ostream &stream, const sx::rgba<sx::unsigned8> &t) { stream.write((const char *)(&t), sizeof(sx::rgba<sx::unsigned8>)); return stream; }
inline std::ostream &operator< (std::ostream &stream, const sx::rgba<half> &t) { stream.write((const char *)(&t), sizeof(sx::rgba<half>)); return stream; }

namespace sx {
	namespace core {
		namespace unittest {
			void test_pixel ();
		}
	}
}
