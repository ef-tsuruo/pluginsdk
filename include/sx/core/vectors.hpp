#pragma once
SXCORE
#include <cmath>
#include <limits>
#include "sx/core/debug.hpp"
#include "sx/core/error.hpp"
#include "sx/core/math.hpp"
#include "sx/core/endian.hpp"
#include "sx/core/minmax.hpp"

#include "boost/type_traits.hpp"

namespace sx {

	enum { RGB, BGR };
	enum { RGBA, BGRA, ARGB };

	template<typename T> class default_rgb_component_ordering {
	public:
		enum { ordering = RGB };
	};
	template<> class default_rgb_component_ordering<sx::unsigned8> {
	public:
		#if SXMACOSX
			enum { ordering = RGB };
		#elif SXWINDOWS
			enum { ordering = BGR };
		#else
			enum { ordering = RGB };
		#endif
	};
	template<typename T> class default_rgba_component_ordering {
	public:
		enum { ordering = RGBA };
	};
	template<> class default_rgba_component_ordering<sx::unsigned8> {
	public:
		#if SXMACOSX
			enum { ordering = ARGB };
		#elif SXWINDOWS
			enum { ordering = BGRA };
		#else
			enum { ordering = RGBA };
		#endif
	};

	template<typename T, int K = default_rgb_component_ordering<T>::ordering> class rgb;
	template<typename T, int K = default_rgba_component_ordering<T>::ordering> class rgba;
	
	namespace imp {
		template<typename T> T one ();
		template<> inline sx::unsigned8 one () { return 255; }
		template<> inline half one () { return 1.0f; }
		template<> inline float one () { return 1.0f; }
		template<> inline double one () { return 1.0; }
	}

	template<typename T> class rgb<T, RGB> {
	public:
		static const std::size_t N = 3;

		T red, green, blue;
		explicit rgb () { }
		explicit rgb (const T &red, const T &green, const T &blue) : red(red), green(green), blue(blue) { }
		explicit rgb (const T &f) : red(f), green(f), blue(f) { }
		explicit rgb (const float *v) : red(v[0]), green(v[1]), blue(v[2]) { }
		void check_invariant () const { sx::check_invariant(red); sx::check_invariant(green); sx::check_invariant(blue); }
	};
	template<typename T> class rgb<T, BGR> {
	public:
		static const std::size_t N = 3;

		T blue, green, red;
		explicit rgb () { }
		explicit rgb (const T &red, const T &green, const T &blue) : red(red), green(green), blue(blue) { }
		explicit rgb (const T &f) : red(f), green(f), blue(f) { }
		explicit rgb (const float *v) : red(v[0]), green(v[1]), blue(v[2]) { }
		void check_invariant () const { sx::check_invariant(red); sx::check_invariant(green); sx::check_invariant(blue); }
	};

	template<typename T> class rgba<T, RGBA> {
	public:
		static const std::size_t N = 4;

		T red, green, blue, alpha;
		explicit rgba () { }
		explicit rgba (const T &red, const T &green, const T &blue, const T &alpha = imp::one<T>()) : red(red), green(green), blue(blue), alpha(alpha) { }
		explicit rgba (const T &f) : red(f), green(f), blue(f), alpha(f) { }
		explicit rgba (const float *v) : red(v[0]), green(v[1]), blue(v[2]), alpha(v[3]) { }
		template<int L> explicit rgba (const rgb<T,L> &c) : red(c.red), green(c.green), blue(c.blue), alpha(sx::imp::one<T>()) { }
		template<int L> explicit rgba (const rgb<T,L> &c, const T &alpha) : red(c.red), green(c.green), blue(c.blue), alpha(alpha) { }
		template<int L> explicit rgba (const rgba<T,L> &c, const T &alpha) : red(c.red), green(c.green), blue(c.blue), alpha(alpha) { }
		operator const rgb<T,RGB> & () const { return *(const rgb<T,RGB> *)(this); }
		operator rgb<T,RGB> & () { return *(rgb<T,RGB> *)(this); }
		void check_invariant () const { sx::check_invariant(red); sx::check_invariant(green); sx::check_invariant(blue); sx::check_invariant(alpha); }
	};
	template<typename T> class rgba<T, BGRA> {
	public:
		static const std::size_t N = 4;

		T blue, green, red, alpha;
		explicit rgba () { }
		explicit rgba (const T &red, const T &green, const T &blue, const T &alpha = imp::one<T>()) : red(red), green(green), blue(blue), alpha(alpha) { }
		explicit rgba (const T f) : red(f), green(f), blue(f), alpha(f) { }
		explicit rgba (const float *v) : red(v[0]), green(v[1]), blue(v[2]), alpha(v[3]) { }
		template<int L> explicit rgba (const rgb<T,L> &c) : red(c.red), green(c.green), blue(c.blue), alpha(sx::imp::one<T>()) { }
		template<int L> explicit rgba (const rgb<T,L> &c, T alpha = imp::one<T>()) : red(c.red), green(c.green), blue(c.blue), alpha(alpha) { }
		template<int L> explicit rgba (const rgba<T,L> &c, T alpha) : red(c.red), green(c.green), blue(c.blue), alpha(alpha) { }
		operator const rgb<T,BGR> & () const { return (const rgb<T,BGR> &)(*this); }
		operator rgb<T,BGR> & () { return (rgb<T,BGR> &)(*this); }
		void check_invariant () const { sx::check_invariant(red); sx::check_invariant(green); sx::check_invariant(blue); sx::check_invariant(alpha); }
	};
	template<typename T> class rgba<T, ARGB> {
	public:
		static const std::size_t N = 4;

		T alpha, red, green, blue;
		explicit rgba () { }
		explicit rgba (const T &red, const T &green, const T &blue, const T &alpha) : red(red), green(green), blue(blue), alpha(alpha) { }
		explicit rgba (const T &f) : red(f), green(f), blue(f), alpha(f) { }
		explicit rgba (const float *v) : red(v[0]), green(v[1]), blue(v[2]), alpha(v[3]) { }
		template<int L> explicit rgba (const rgb<T,L> &c) : red(c.red), green(c.green), blue(c.blue), alpha(sx::imp::one<T>()) { }
		template<int L> explicit rgba (const rgb<T,L> &c, const T &alpha) : red(c.red), green(c.green), blue(c.blue), alpha(alpha) { }
		template<int L> explicit rgba (const rgba<T,L> &c, const T &alpha) : red(c.red), green(c.green), blue(c.blue), alpha(alpha) { }
		void check_invariant () const { sx::check_invariant(red); sx::check_invariant(green); sx::check_invariant(blue); sx::check_invariant(alpha); }
	};
}

template<typename T, int K> inline const sx::rgb<T,K> operator* (const sx::rgb<T,K> &a, const T &b)							{ return sx::rgb<T,K>(a.red*b, a.green*b, a.blue*b); }
template<typename T, int K> inline const sx::rgba<T,K> operator* (const sx::rgba<T,K> &a, const T &b)						{ return sx::rgba<T,K>(a.red*b, a.green*b, a.blue*b, a.alpha*b); }
template<typename T, int K> inline sx::rgb<T,K> &operator*= (sx::rgb<T,K> &a, const T &b)									{ a.red *= b; a.green *= b; a.blue *= b; return a; }
template<typename T, int K> inline sx::rgba<T,K> &operator*= (sx::rgba<T,K> &a, const T &b)									{ a.red *= b; a.green *= b; a.blue *= b; a.alpha *= b; return a; }
template<typename T, int K, int L> inline const sx::rgb<T,K> operator* (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)		{ return sx::rgb<T,K>(a.red*b.red, a.green*b.green, a.blue*b.blue); }
template<typename T, int K, int L> inline const sx::rgb<T,K> operator* (const sx::rgb<T,K> &a, const sx::rgba<T,L> &b)		{ return sx::rgb<T,K>(a.red*b.red, a.green*b.green, a.blue*b.blue); }
template<typename T, int K, int L> inline const sx::rgba<T,K> operator* (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)	{ return sx::rgba<T,K>(a.red*b.red, a.green*b.green, a.blue*b.blue, a.alpha*b.alpha); }
template<typename T, int K, int L> inline sx::rgb<T,K> &operator*= (sx::rgb<T,K> &a, const sx::rgb<T,L> &b)					{ a.red *= b.red; a.green *= b.green; a.blue *= b.blue; return a; }
template<typename T, int K, int L> inline sx::rgb<T,K> &operator*= (sx::rgb<T,K> &a, const sx::rgba<T,L> &b)				{ a.red *= b.red; a.green *= b.green; a.blue *= b.blue; return a; }
template<typename T, int K, int L> inline sx::rgba<T,K> &operator*= (sx::rgba<T,K> &a, const sx::rgba<T,L> &b)				{ a.red *= b.red; a.green *= b.green; a.blue *= b.blue; a.alpha *= b.alpha; return a; }
template<typename T, int K, int L> inline const sx::rgb<T,K> operator/ (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)		{ return sx::rgb<T,K>(a.red/b.red, a.green/b.green, a.blue/b.blue); }
template<typename T, int K, int L> inline const sx::rgba<T,K> operator/ (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)	{ return sx::rgba<T,K>(a.red/b.red, a.green/b.green, a.blue/b.blue, a.alpha/b.alpha); }
template<typename T, int K> inline const sx::rgb<T,K> operator/ (const sx::rgb<T,K> &a, const T &b)							{ return sx::rgb<T,K>(a.red/b, a.green/b, a.blue/b); }
template<typename T, int K> inline const sx::rgba<T,K> operator/ (const sx::rgba<T,K> &a, const T &b)						{ return sx::rgba<T,K>(a.red/b, a.green/b, a.blue/b, a.alpha/b); }
template<typename T, int K> inline sx::rgb<T,K> &operator/= (sx::rgb<T,K> &a, const T &b)									{ a.red /= b; a.green /= b; a.blue /= b; return a; }
template<typename T, int K> inline sx::rgba<T,K> &operator/= (sx::rgba<T,K> &a, const T &b)									{ a.red /= b; a.green /= b; a.blue /= b; a.alpha /= b; return a; }
template<typename T, int K, int L> inline const sx::rgb<T,K> operator+ (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)		{ return sx::rgb<T,K>(a.red+b.red, a.green+b.green, a.blue+b.blue); }
template<typename T, int K, int L> inline const sx::rgb<T,K> operator+ (const sx::rgb<T,K> &a, const sx::rgba<T,L> &b)		{ return sx::rgb<T,K>(a.red+b.red, a.green+b.green, a.blue+b.blue); }
template<typename T, int K, int L> inline const sx::rgba<T,K> operator+ (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)	{ return sx::rgba<T,K>(a.red+b.red, a.green+b.green, a.blue+b.blue, a.alpha+b.alpha); }
template<typename T, int K, int L> inline sx::rgb<T,K> &operator+= (sx::rgb<T,K> &a, const sx::rgb<T,L> &b)					{ a.red += b.red; a.green += b.green; a.blue += b.blue; return a; }
template<typename T, int K, int L> inline sx::rgb<T,K> &operator+= (sx::rgb<T,K> &a, const sx::rgba<T,L> &b)				{ a.red += b.red; a.green += b.green; a.blue += b.blue; return a; }
template<typename T, int K, int L> inline sx::rgba<T,K> &operator+= (sx::rgba<T,K> &a, const sx::rgba<T,L> &b)				{ a.red += b.red; a.green += b.green; a.blue += b.blue; a.alpha += b.alpha; return a; }
template<typename T, int K, int L> inline const sx::rgb<T,K> operator- (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)		{ return sx::rgb<T,K>(a.red-b.red, a.green-b.green, a.blue-b.blue); }
template<typename T, int K, int L> inline const sx::rgb<T,K> operator- (const sx::rgb<T,K> &a, const sx::rgba<T,L> &b)		{ return sx::rgb<T,K>(a.red-b.red, a.green-b.green, a.blue-b.blue); }
template<typename T, int K, int L> inline const sx::rgba<T,K> operator- (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)	{ return sx::rgba<T,K>(a.red-b.red, a.green-b.green, a.blue-b.blue, a.alpha-b.alpha); }
template<typename T, int K, int L> inline sx::rgb<T,K> &operator-= (sx::rgb<T,K> &a, const sx::rgb<T,L> &b)					{ a.red -= b.red; a.green -= b.green; a.blue -= b.blue; return a; }
template<typename T, int K, int L> inline sx::rgb<T,K> &operator-= (sx::rgb<T,K> &a, const sx::rgba<T,L> &b)				{ a.red -= b.red; a.green -= b.green; a.blue -= b.blue; return a; }
template<typename T, int K, int L> inline sx::rgba<T,K> &operator-= (sx::rgba<T,K> &a, const sx::rgba<T,L> &b)				{ a.red -= b.red; a.green -= b.green; a.blue -= b.blue; a.alpha -= b.alpha; return a; }
template<typename T, int K, int L> inline const bool operator== (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)				{ return a.red==b.red && a.green==b.green && a.blue==b.blue; }
template<typename T, int K, int L> inline const bool operator== (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)			{ return a.red==b.red && a.green==b.green && a.blue==b.blue && a.alpha==b.alpha; }
template<typename T, int K, int L> inline const bool operator!= (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)				{ return !(a == b); }
template<typename T, int K, int L> inline const bool operator!= (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)			{ return !(a == b); }
template<typename T, int K, int L> inline const bool operator<= (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)				{ return a.red<=b.red && a.green<=b.green && a.blue<=b.blue; }
template<typename T, int K, int L> inline const bool operator<= (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)			{ return a.red<=b.red && a.green<=b.green && a.blue<=b.blue && a.alpha<=b.alpha; }
template<typename T, int K, int L> inline const bool operator< (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)				{ return a.red<b.red && a.green<b.green && a.blue<b.blue; }
template<typename T, int K, int L> inline const bool operator< (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)				{ return a.red<b.red && a.green<b.green && a.blue<b.blue && a.alpha<b.alpha; }
template<typename T, int K> inline const sx::rgb<T,K> operator-  (const sx::rgb<T,K> &c)									{ return sx::rgb<T,K>(-c.red, -c.green, -c.blue); }
template<typename T, int K> inline const sx::rgba<T,K> operator-  (const sx::rgba<T,K> &c)									{ return sx::rgba<T,K>(-c.red, -c.green, -c.blue, -c.alpha); }
namespace sx {
	template<typename T, int K> inline const sx::rgb<T,K> abs (const sx::rgb<T,K> &c)										{ return sx::rgb<T,K>(std::abs(c.red), std::abs(c.green), std::abs(c.blue)); }
	template<typename T, int K> inline const sx::rgba<T,K> abs (const sx::rgba<T,K> &c)										{ return sx::rgba<T,K>(std::abs(c.red), std::abs(c.green), std::abs(c.blue), std::abs(c.alpha)); }
	template<typename T, int K, int L> inline const sx::rgb<T,K> min (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)			{ return sx::rgb<T,K>(std::min(a.red,b.red), std::min(a.green,b.green), std::min(a.blue,b.blue)); }
	template<typename T, int K, int L> inline const sx::rgba<T,K> min (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)		{ return sx::rgba<T,K>(std::min(a.red,b.red), std::min(a.green,b.green), std::min(a.blue,b.blue), std::min(a.alpha,b.alpha)); }
	template<typename T, int K, int L> inline const sx::rgb<T,K> max (const sx::rgb<T,K> &a, const sx::rgb<T,L> &b)			{ return sx::rgb<T,K>(std::max(a.red,b.red), std::max(a.green,b.green), std::max(a.blue,b.blue)); }
	template<typename T, int K, int L> inline const sx::rgba<T,K> max (const sx::rgba<T,K> &a, const sx::rgba<T,L> &b)		{ return sx::rgba<T,K>(std::max(a.red,b.red), std::max(a.green,b.green), std::max(a.blue,b.blue), std::max(a.alpha,b.alpha)); }
	template<typename T, int K> inline const rgb<T,K> &revert_endian (rgb<T,K> &c)											{ sx::revert_endian(c.red); sx::revert_endian(c.green); sx::revert_endian(c.blue); return c; }
	template<typename T, int K> inline const rgba<T,K> &revert_endian (rgba<T,K> &c)										{ sx::revert_endian(c.red); sx::revert_endian(c.green); sx::revert_endian(c.blue); sx::revert_endian(c.alpha); return c; }
	template<int K> inline float luminance (const sx::rgb<float,K> &c)														{ return (c.red * 0.299f + c.green * 0.587f + c.blue * 0.114f); }
	template<int K> inline float luminance (const sx::rgba<float,K> &c)														{ return (c.red * 0.299f + c.green * 0.587f + c.blue * 0.114f); }
	template<int K> inline float average (const sx::rgb<float,K> &c)														{ return (c.red + c.green + c.blue) * (1.0f / 3.0f); }
	template<int K> inline float average (const sx::rgba<float,K> &c)														{ return (c.red + c.green + c.blue) * (1.0f / 3.0f); }
	template<int K> inline bool zero (const sx::rgb<float,K> &c)															{ return -epsilon<c.red && c.red<epsilon && -epsilon<c.green && c.green<epsilon && -epsilon<c.blue && c.blue<epsilon; }
	template<int K> inline bool zero (const sx::rgba<float,K> &c)															{ return -epsilon<c.red && c.red<epsilon && -epsilon<c.green && c.green<epsilon && -epsilon<c.blue && c.blue<epsilon && -epsilon<c.alpha && c.alpha<epsilon; }
	template<typename T, int K> inline const rgb<T,K> sqr (const rgb<T,K> &c)												{ return rgb<T,K>(c.red*c.red, c.green*c.green, c.blue*c.blue); }
	template<typename T, int K> inline const rgba<T,K> sqr (const rgba<T,K> &c)												{ return rgba<T,K>(c.red*c.red, c.green*c.green, c.blue*c.blue, c.alpha*c.alpha); }
	template<typename T, int K> inline const rgb<T,K> sqrt (const rgb<T,K> &c)												{ return rgb<T,K>(std::sqrt(c.red), std::sqrt(c.green), std::sqrt(c.blue)); }
	template<typename T, int K> inline const rgba<T,K> sqrt (const rgba<T,K> &c)											{ return rgba<T,K>(std::sqrt(c.red), std::sqrt(c.green), std::sqrt(c.blue), std::sqrt(c.alpha)); }
	template<typename T, int K> inline const T minimum3 (const rgb<T,K> &c)													{ return std::min(std::min(c.red, c.green), c.blue); }
	template<typename T, int K> inline const T minimum3  (const rgba<T,K> &c)												{ return std::min(std::min(c.red, c.green), c.blue); }
	template<typename T, int K> inline const T maximum3 (const rgb<T,K> &c)													{ return std::max(std::max(c.red, c.green), c.blue); }
	template<typename T, int K> inline const T maximum3 (const rgba<T,K> &c)												{ return std::max(std::max(c.red, c.green), c.blue); }
	template<typename T, int K> inline const rgb<T,K> normalize  (const rgb<T,K> &c)										{ const T t = std::sqrt(c.red*c.red + c.green*c.green + c.blue*c.blue); return sx::rgb<T,K>(c.red/t, c.green/t, c.blue/t); }
	template<int K> inline const rgb<float,K> clamp (const rgb<float,K> &c)													{ return sx::max(sx::min(c, rgb<float,K>(1.0f)), rgb<float,K>(0.0f)); }
	template<int K> inline const rgba<float,K> clamp (const rgba<float,K> &c)												{ return sx::max(sx::min(c, rgba<float,K>(1.0f)), rgba<float,K>(0.0f)); }
	template<int K> inline const bool isnan (const rgb<float,K> &c)															{ return (sx::isnan(c.red) && sx::isnan(c.green) && sx::isnan(c.blue)); }
	template<int K> inline const bool isnan (const rgba<float,K> &c)														{ return (sx::isnan(c.red) && sx::isnan(c.green) && sx::isnan(c.blue) && sx::isnan(c.alpha)); }
	template<int K> inline const bool isnormal (const rgb<float,K> &c)														{ return (sx::isnormal(c.red) && sx::isnormal(c.green) && sx::isnormal(c.blue)); }
	template<int K> inline const bool isnormal (const rgba<float,K> &c)														{ return (sx::isnormal(c.red) && sx::isnormal(c.green) && sx::isnormal(c.blue) && sx::isnormal(c.alpha)); }
	template<int K> inline const rgb<float,K> undenormal (const rgb<float,K> &c)											{ return rgb<float,K>(sx::isnormal(c.red) ? c.red : 0.0f, sx::isnormal(c.green) ? c.green : 0.0f, sx::isnormal(c.blue) ? c.blue : 0.0f); }
	template<int K> inline const rgba<float,K> undenormal (const rgba<float,K> &c)											{ return rgba<float,K>(sx::isnormal(c.red) ? c.red : 0.0f, sx::isnormal(c.green) ? c.green : 0.0f, sx::isnormal(c.blue) ? c.blue : 0.0f, sx::isnormal(c.alpha) ? c.alpha : 0.0f); }

	template <typename T, int N> class vec;

	template <typename T> class vec<T,2> {
	public:
		typedef T value_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *iterator;
		T x, y;

		explicit vec ();
		explicit vec (const T v[]) : x(v[0]), y(v[1]) { }
		explicit vec (const T &f) : x(f), y(f) { }
		explicit vec (const T &x, const T &y) : x(x), y(y) { }
		explicit vec (const vec<T,3> &);
		explicit vec (const vec<T,4> &);
		template<typename U> vec (const vec<U,2> &v) : x(T(v.x)), y(T(v.y)) { } // allow implicit conversion
		#if SXIOS || SXMACOSX
			explicit vec (const CGPoint &p) : x(p.x), y(p.y) { }
			explicit vec (const CGSize &p) : x(p.width), y(p.height) { }
		#endif
		#if SXMACOSX && !(__LP64__)
			explicit vec (const NSPoint &p) : x(p.x), y(p.y) { }
			explicit vec (const NSSize &s) : x(s.width), y(s.height) { }
		#endif
		#if SXWINDOWS
			explicit vec (const POINT &p) : x(p.x), y(p.y) { }
			explicit vec (const SIZE &p) : x(p.cx), y(p.cy) { }
		#endif
		const T &operator[] (int i) const { SXASSERT((0<=i) && (i<2)); return (&x)[i]; }
		T &operator[] (int i) { SXASSERT((0<=i) && (i<2)); return (&x)[i]; }
		int size () const { return 2; }
		void check_invariant () const { sx::check_invariant(x); sx::check_invariant(y); }
	};
	
	template <typename T> class vec<T,3> {
	public:
		typedef T value_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *iterator;
		T x, y, z;

		explicit vec ();
		explicit vec (const T v[]) : x(v[0]), y(v[1]), z(v[2]) { }
		explicit vec (const T &f) : x(f), y(f), z(f) { }
		explicit vec (const T &x, const T &y, const T &z) : x(x), y(y), z(z) { }
		explicit vec (const rgb<T> &c) : x(c.red), y(c.green), z(c.blue) { }
		explicit vec (const vec<T,2> &v, const T &z) : x(v.x), y(v.y), z(z) { }
		explicit vec (const vec<T,4> &v);
		template<typename U> vec (const vec<U,3> &v) : x(T(v.x)), y(T(v.y)), z(T(v.z)) { } // allow implicit conversion
		const T &operator[] (int i) const { SXASSERT((0<=i) && (i<3)); return (&x)[i]; }
		T &operator[] (int i) { SXASSERT((0<=i) && (i<3)); return (&x)[i]; }
		int size () const { return 3; }
		void check_invariant () const { sx::check_invariant(x); sx::check_invariant(y); sx::check_invariant(z); }
	};

	template <typename T> class vec<T,4> {
	public:
		typedef T value_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *iterator;
		T x, y, z, w;

		explicit vec ();
		explicit vec (const T v[]) : x(v[0]), y(v[1]), z(v[2]), w(v[3]) { }
		explicit vec (const T &f) : x(f), y(f), z(f), w(f) { }
		explicit vec (const T &x, const T &y, const T &z, const T &w) : x(x), y(y), z(z), w(w) { }
		explicit vec (const rgba<T> &c) : x(c.red), y(c.green), z(c.blue), w(c.alpha) { }
		explicit vec (const vec<T,3> &v) : x(v.x), y(v.y), z(v.z), w(1.0f) { }
		explicit vec (const vec<T,3> &v, const T &w) : x(v.x), y(v.y), z(v.z), w(w) { }
		explicit vec (const vec<T,2> &v, const T &z, const T &w) : x(v.x), y(v.y), z(z), w(w) { }
		template<typename U> vec (const vec<U,4> &v) : x(T(v.x)), y(T(v.y)), z(T(v.z)), w(T(v.w)) { } // allow implicit conversion
		const T &operator[] (int i) const { SXASSERT((0<=i) && (i<4)); return (&x)[i]; }
		T &operator[] (int i) { SXASSERT((0<=i) && (i<4)); return (&x)[i]; }
		int size () const { return 4; }
		void check_invariant () const { sx::check_invariant(x); sx::check_invariant(y); sx::check_invariant(z); sx::check_invariant(w); }
	};

	template<typename T, int N> inline void initialize (sx::vec<T,N> &v) { }
	template<int N> inline void initialize (sx::vec<int,N> &v) {
		for (int i = 0; i < N; ++i) v[i] = 0;
	}
	template<typename T> inline sx::vec<T,2>::vec () { initialize(*this); }
	template<typename T> inline sx::vec<T,3>::vec () { initialize(*this); }
	template<typename T> inline sx::vec<T,4>::vec () { initialize(*this); }

	template<typename T> inline vec<T,2>::vec (const vec<T,3> &v) : x(v.x), y(v.y) { }
	template<typename T> inline vec<T,2>::vec (const vec<T,4> &v) : x(v.x), y(v.y) { }
	template<typename T> inline vec<T,3>::vec (const vec<T,4> &v) : x(v.x), y(v.y), z(v.z) { }
	
	template<int i0, int i1, int i2, int i3, typename T, int N> inline vec<T,4> shuffle (const vec<T,N> &v) {
		return vec<T,4>(v[i0], v[i1], v[i2], v[i3]);
	}
	template<int i0, int i1, typename T> inline vec<T,2> shuffle2 (const vec<T,2> &v) {
		return vec<T,2>(v[i0], v[i1]);
	}
	template<int i0, int i1, int i2, typename T> inline vec<T,3> shuffle3 (const vec<T,3> &v) {
		return vec<T,3>(v[i0], v[i1], v[i2]);
	}
	template<int i0, int i1, int i2, int i3, typename T> inline vec<T,4> shuffle4 (const vec<T,4> &v) {
		return vec<T,4>(v[i0], v[i1], v[i2], v[i3]);
	}

	template<typename T, int N> inline bool isnan (const sx::vec<T,N> &v) {
		for (int i = 0; i < N; ++i) if (sx::isnan(v[i])) return true;
		return false;
	}
	
	inline bool zero (float t) { return (-epsilon <= t) && (t <= epsilon); }
	inline bool zero (double t) { return (-epsilon <= t) && (t <= epsilon); }
	inline bool zero (int t) { return (t == 0); }

	template<typename T, int N> inline bool zero (const vec<T,N> &v) {
		for (int i = 0; i < N; ++i) {
			if (!sx::zero(v[i])) return false;
		}
		return true;
	}

	template<typename T, int N> class mat : public std::array<sx::vec<T,N>, N> {
	public:
		explicit mat () { }
		explicit mat (const T &a);
		explicit mat (const sx::vec<T,N> &a, const sx::vec<T,N> &b, const sx::vec<T,N> &c, const sx::vec<T,N> &d);
		explicit mat (const T &a0, const T &a1, const T &a2, const T &a3, const T &b0, const T &b1, const T &b2, const T &b3, const T &c0, const T &c1, const T &c2, const T &c3, const T &d0, const T &d1, const T &d2, const T &d3);
		explicit mat (const T *);
		mat &normalize ();
		void check_invariant () const { for (int i = 0; i < N; ++i) sx::check_invariant((*this)[i]); }
	};
	template<typename T, int N> bool isnan (const mat<T,N> &a) {
		for (int i = 0; i < N; ++i) if (isnan(a[i])) return true;
		return false;
	}

	inline const float sqr (const float &t) { return t*t; }
	inline const double sqr (const double &t) { return t*t; }
	inline const int sqr (const int &t) { return t*t; }
	template<typename T, int N> inline sx::vec<T,N> sqr (const sx::vec<T,N> &a) {
		vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = a[i] * a[i];
		return v;
	}

	template<typename T> const T sqrt (const T &); // should be removed. also, cyclic dependency between vectors.hpp and sse.hpp should be broken.
	inline const float sqrt (const float &t) { return std::sqrt(t); }
	inline const double sqrt (const double &t) { return std::sqrt(t); }
	template<typename T, int N> inline const sx::vec<T,N> sqrt (const sx::vec<T,N> &v) {
		vec<T,N> q;
		for (int i = 0; i < N; ++i) q[i] = sx::sqrt(v[i]);
		return q;
	}

	inline const float rsqrt (const float &t) { return 1.0f / std::sqrt(t); }
	inline const double rsqrt (const double &t) { return 1.0f / std::sqrt(t); }
	template<typename T, int N> inline const sx::vec<T,N> rsqrt (const sx::vec<T,N> &v) {
		vec<T,N> q;
		for (int i = 0; i < N; ++i) q[i] = sx::rsqrt(v[i]);
		return q;
	}

	inline const float reciprocal (const float &t) { return 1.0f / t; }
	inline const double reciprocal (const double &t) { return 1.0 / t; }
	template<typename T, int N> inline sx::vec<T,N> reciprocal (const sx::vec<T,N> &v) {
		sx::vec<T,N> u;
		for (int i = 0; i < N; ++i) u[i] = sx::reciprocal(v[i]);
		return u;
	}

	inline const float abs (const float &t) { return std::abs(t); }
	inline const double abs (const double &t) { return std::abs(t); }
	inline const int abs (const int &t) { return std::abs(t); }
	template<typename T, int N> inline const sx::vec<T,N> abs (const sx::vec<T,N> &p) {
		vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = sx::abs(p[i]);
		return v;
	}
	
	template<typename T> inline T sum (const sx::vec<T,2> &p) { return p.x + p.y; }
	template<typename T> inline T sum (const sx::vec<T,3> &p) { return p.x + p.y + p.z; }
	template<typename T> inline T sum (const sx::vec<T,4> &p) { return p.x + p.y + p.z + p.w; }

	template<typename T, int N> inline T sum2 (const sx::vec<T,N> &p) { return p.x + p.y; }
	template<typename T, int N> inline T sum3 (const sx::vec<T,N> &p) { return p.x + p.y + p.z; }
	template<typename T> inline T sum4 (const sx::vec<T,4> &p) { return p.x + p.y + p.z + p.w; }

	template<typename T> inline T inner_product (const sx::vec<T,4> &a, const sx::vec<T,4> &b) {
		return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
	}
	template<typename T> inline T inner_product (const sx::vec<T,3> &a, const sx::vec<T,3> &b) {
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}
	template<typename T> inline T inner_product (const sx::vec<T,2> &a, const sx::vec<T,2> &b) {
		return a.x*b.x + a.y*b.y;
	}
	template<typename T, int N> inline static T inner_product4 (const sx::vec<T,N> &a, const sx::vec<T,N> &b) {
		return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
	}
	template<typename T, int N, int M> inline T inner_product3 (const sx::vec<T,N> &a, const sx::vec<T,M> &b) {
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}
	template<typename T, int N, int M> inline T inner_product2 (const sx::vec<T,2> &a, const sx::vec<T,2> &b) {
		return a.x*b.x + a.y*b.y;
	}

	template<typename T, int M> inline vec<T,3> product (const vec<T,3> &a, const vec<T,M> &b) {
		return vec<T,3>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}
	template<typename T, int M> inline vec<T,4> product (const vec<T,4> &a, const vec<T,M> &b) {
		return vec<T,4>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 1.0f);
	}

	template<typename T, int N> inline T absolute2 (const sx::vec<T,N> &p) {
		return sx::sqrt(p.x*p.x + p.y*p.y);
	}
	template<typename T, int N> inline T sqrabsolute2 (const sx::vec<T,N> &p) {
		return (p.x*p.x + p.y*p.y);
	}
	template<typename T, int N> inline T absolute3 (const sx::vec<T,N> &p) {
		return sx::sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
	}
	template<typename T, int N> inline T sqrabsolute3 (const sx::vec<T,N> &p) {
		return (p.x*p.x + p.y*p.y + p.z*p.z);
	}
	template<typename T, int N> inline T absolute4 (const sx::vec<T,N> &p) {
		return sx::sqrt(p.x*p.x + p.y*p.y + p.z*p.z + p.w*p.w);
	}
	
	template<typename T> inline T sqrabsolute4 (const sx::vec<T,4> &p) {
		return (p.x*p.x + p.y*p.y + p.z*p.z + p.w*p.w);
	}

	template<typename T, int N> inline const sx::vec<T,N> normalize (const sx::vec<T,N> &p) {
		T d = sqrabsolute3(p);
		if (denormalized_min < d) {
			return (p / sx::sqrt(d));
		}
		return p;
	}

	template<typename T> inline const T normalize_self (vec<T,2> &p) {
		T d = sqrabsolute2(p);
		if (denormalized_min < d) {
			d = sx::sqrt(d);
			const T r = 1.0f / d;
			p.x *= r;
			p.y *= r;
		}
		return d;
	}

	template<typename T, int N> inline sx::vec<T,N> round (const sx::vec<T,N> &p) {
		vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = std::floor(p[i]+0.5f);
		return v;
	}
	template<typename T, int N> inline sx::vec<T,N> trunc (const sx::vec<T,N> &p) {
		vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = float(int(p[i]));
		return v;
	}
	template<typename T, int N> inline sx::vec<T,N> ceil (const sx::vec<T,N> &p) {
		vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = std::ceil(p[i]);
		return v;
	}
	template<typename T, int N> inline sx::vec<T,N> floor (const sx::vec<T,N> &p) {
		vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = std::floor(p[i]);
		return v;
	}
}
namespace sx {
	template<typename T, int N> inline sx::vec<T,N> min (const sx::vec<T,N> &a, const sx::vec<T,N> &b) {
		sx::vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = sx::min(a[i], b[i]);
		return v;
	}
	template<typename T, int N> inline sx::vec<T,N> max (const sx::vec<T,N> &a, const sx::vec<T,N> &b) {
		sx::vec<T,N> v;
		for (int i = 0; i < N; ++i) v[i] = sx::max(a[i], b[i]);
		return v;
	}

	template<typename T, int N> inline T minimum2 (const sx::vec<T,N> &v) { return sx::min(v.x, v.y); }
	template<typename T, int N> inline T minimum3 (const sx::vec<T,N> &v) { return sx::min(sx::min(v.x, v.y), v.z); }
	template<typename T, int N> inline T minimum4 (const sx::vec<T,N> &v) { return sx::min(sx::min(sx::min(v.x, v.y), v.z), v.w); }

	template<typename T, int N> inline T maximum2 (const sx::vec<T,N> &v) { return sx::max(v.x, v.y); }
	template<typename T, int N> inline T maximum3 (const sx::vec<T,N> &v) { return sx::max(sx::max(v.x, v.y), v.z); }
	template<typename T, int N> inline T maximum4 (const sx::vec<T,N> &v) { return sx::max(sx::max(sx::max(v.x, v.y), v.z), v.w); }

	template<typename T> inline vec<T,3> transform_direction (const vec<T,3> &p, const sx::mat<T,4> &t) {
		return vec<T,3>(
			p[0] * t[0][0] + p[1] * t[1][0] + p[2] * t[2][0],
			p[0] * t[0][1] + p[1] * t[1][1] + p[2] * t[2][1],
			p[0] * t[0][2] + p[1] * t[1][2] + p[2] * t[2][2]
		);
	}

	template<typename T> inline vec<T,3> transform_normal (const mat<T,4> &it, const vec<T,3> &p) {
		return vec<T,3>(
			it[0][0] * p[0] + it[0][1] * p[1] + it[0][2] * p[2],
			it[1][0] * p[0] + it[1][1] * p[1] + it[1][2] * p[2],
			it[2][0] * p[0] + it[2][1] * p[1] + it[2][2] * p[2]
		);
	}

	template<typename T> inline T det (const sx::mat<T,4> &a, int i1, int i2, int i3, int j1, int j2, int j3) {
		SXTEST(sx::check_invariant(a));
		return (	(a[i1][j1]*a[i2][j2]*a[i3][j3])
				+	(a[i1][j2]*a[i2][j3]*a[i3][j1])
				+	(a[i1][j3]*a[i2][j1]*a[i3][j2])
				-	(a[i1][j1]*a[i2][j3]*a[i3][j2])
				-	(a[i1][j2]*a[i2][j1]*a[i3][j3])
				-	(a[i1][j3]*a[i2][j2]*a[i3][j1]));
	}
	template<typename T> inline T det (const mat<T,4> &a) {
		SXTEST(sx::check_invariant(a));
		enum { X, Y, Z, W };
		return (		(a[0][X]*a[1][Y]*a[2][Z])
					+	(a[0][Y]*a[1][Z]*a[2][X])
					+	(a[0][Z]*a[1][X]*a[2][Y])
					-	(a[0][X]*a[1][Z]*a[2][Y])
					-	(a[0][Y]*a[1][X]*a[2][Z])
					-	(a[0][Z]*a[1][Y]*a[2][X])
			);
	}

	const mat<float,4> inv (const mat<float,4> &t);
	const mat<float,4> inverse (const mat<float,4> &t);
	
	template<typename T, int N> sx::vec<T,N> &revert_endian (vec<T,N> &v) {
		for (int i = 0; i < N; ++i) revert_endian(v[i]);
		return v;
	}

	template<typename T, int N> sx::mat<T,N> &revert_endian (mat<T,N> &m) {
		for (int i = 0; i < N; ++i) revert_endian(m[i]);
		return m;
	}

	template<typename T, int N> inline mat<T,N>::mat (const T &a) {
		BOOST_STATIC_ASSERT(N == 4);
		(*this)[0] = sx::vec<T,N>(a);
		(*this)[1] = sx::vec<T,N>(a);
		(*this)[2] = sx::vec<T,N>(a);
		(*this)[3] = sx::vec<T,N>(a);
	}
	template<typename T, int N> inline mat<T,N>::mat (const sx::vec<T,N> &a, const sx::vec<T,N> &b, const sx::vec<T,N> &c, const sx::vec<T,N> &d) {
		BOOST_STATIC_ASSERT(N == 4);
		(*this)[0] = a;
		(*this)[1] = b;
		(*this)[2] = c;
		(*this)[3] = d;
	}
	template<typename T, int N> inline sx::mat<T,N>::mat (const T &a0, const T &a1, const T &a2, const T &a3, const T &b0, const T &b1, const T &b2, const T &b3, const T &c0, const T &c1, const T &c2, const T &c3, const T &d0, const T &d1, const T &d2, const T &d3) {
		BOOST_STATIC_ASSERT(N == 4);
		(*this)[0] = sx::vec<T,4>(a0, a1, a2, a3);
		(*this)[1] = sx::vec<T,4>(b0, b1, b2, b3);
		(*this)[2] = sx::vec<T,4>(c0, c1, c2, c3);
		(*this)[3] = sx::vec<T,4>(d0, d1, d2, d3);
	}
	template<typename T, int N> inline sx::mat<T,N>::mat (const T *p) {
		BOOST_STATIC_ASSERT(N == 4);
		(*this)[0] = sx::vec<T,4>(p);
		(*this)[1] = sx::vec<T,4>(p+4);
		(*this)[2] = sx::vec<T,4>(p+8);
		(*this)[3] = sx::vec<T,4>(p+12);
	}

	template<typename T> inline T clamp (const T &x, const T &min = T(0.0f), const T &max = T(1.0f)) {
		if (x < min) return min;
		if (max < x) return max;
		return x;
	}
	template<typename T, int N> inline sx::vec<T,N> clamp (const sx::vec<T,N> &v, const sx::vec<T,N> &min = sx::vec<T,N>(0.0f), const sx::vec<T,N> &max = sx::vec<T,N>(1.0f)) {
		return sx::min(sx::max(v, min), max);
	}

	inline static sx::vec<float,4> homogeneous (const sx::vec<float,3> &p) {
		return sx::vec<float,4>(p, 1.0f);
	}

	inline static vec<float,3> cartesian (const vec<float,4> &p) {
		return vec<float,3>(p.x/p.w, p.y/p.w, p.z/p.w);
	}

	namespace unittest {
		bool nearlyequal (const sx::vec<float,2> &a, const sx::vec<float,2> &b);
		bool nearlyequal (const sx::vec<float,3> &a, const sx::vec<float,3> &b);
		bool nearlyequal (const sx::vec<float,4> &a, const sx::vec<float,4> &b);
		bool nearlyequal (const mat<float,4> &a, const mat<float,4> &b);
		template<int K, int L> bool nearlyequal (const sx::rgb<float,K> &a, const sx::rgb<float,L> &b) { return nearlyequal(a.red,b.red) && nearlyequal(a.green,b.green) && nearlyequal(a.blue,b.blue); }
		template<int K, int L> bool nearlyequal (const sx::rgba<float,K> &a, const sx::rgba<float,L> &b) { return nearlyequal(a.red,b.red) && nearlyequal(a.green,b.green) && nearlyequal(a.blue,b.blue) && nearlyequal(a.alpha,b.alpha); }
	}
}

template<typename S, typename T, int N> inline bool operator< (const sx::vec<S,N> &a, const sx::vec<T,N> &b) {
	for (int i = 0; i < N; ++i) if (!(a[i] < b[i])) return false;
	return true;
}

template<typename S, typename T, int N> inline bool operator<= (const sx::vec<S,N> &a, const sx::vec<T,N> &b) {
	for (int i = 0; i < N; ++i) if (!(a[i] <= b[i])) return false;
	return true;
}

template<typename S, typename T, int N> inline bool operator== (const sx::vec<S,N> &a, const sx::vec<T,N> &b) {
	for (int i = 0; i < N; ++i) if (!(a[i] == b[i])) return false;
	return true;
}

template<typename S, typename T, int N> inline bool operator!= (const sx::vec<S,N> &a, const sx::vec<T,N> &b) {
	return !(a == b);
}

template<typename T> inline sx::vec<T,4> operator* (const sx::mat<T,4> &it, const sx::vec<T,4> &p) {
	sx::vec<T,4> q;
	for (int i = 0; i < 4; ++i) {
		q[i] = 0.0f;
		for (int j = 0; j < 4; ++j) {
			q[i] += it[i][j] * p[j];
		}
	}
	return q;
}
template<typename T, typename U> inline sx::vec<T,4> operator* (const sx::vec<T,4> &p, const sx::mat<U,4> &t) {
	return sx::vec<T,4>(
		p[0] * t[0][0] + p[1] * t[1][0] + p[2] * t[2][0] + p[3] * t[3][0],
		p[0] * t[0][1] + p[1] * t[1][1] + p[2] * t[2][1] + p[3] * t[3][1],
		p[0] * t[0][2] + p[1] * t[1][2] + p[2] * t[2][2] + p[3] * t[3][2],
		p[0] * t[0][3] + p[1] * t[1][3] + p[2] * t[2][3] + p[3] * t[3][3]
	);
}

template<typename T, typename U> inline sx::vec<T,3> operator* (const sx::vec<T,3> &p, const sx::mat<U,4> &t) {
	return sx::vec<T,3>(
		p[0] * t[0][0] + p[1] * t[1][0] + p[2] * t[2][0] + t[3][0],
		p[0] * t[0][1] + p[1] * t[1][1] + p[2] * t[2][1] + t[3][1],
		p[0] * t[0][2] + p[1] * t[1][2] + p[2] * t[2][2] + t[3][2]
	);
}

template<typename T, typename U> inline sx::vec<T,2> operator* (const sx::vec<T,2> &p, const sx::mat<U,4> &t) {
	return sx::vec<T,2>(
		p[0] * t[0][0] + p[1] * t[1][0] + t[3][0],
		p[0] * t[0][1] + p[1] * t[1][1] + t[3][1]
	);
}

template<typename T> inline sx::vec<T,2> &operator*= (sx::vec<T,2> &p, const sx::mat<T,4> &t) {
	p = p * t;
	return p;
}
template<typename T> inline sx::vec<T,3> &operator*= (sx::vec<T,3> &p, const sx::mat<T,4> &t) {
	p = p * t;
	return p;
}
template<typename T> inline sx::vec<T,4> &operator*= (sx::vec<T,4> &p, const sx::mat<T,4> &t) {
	p = p * t;
	return p;
}

template<typename T, int N, int M> inline sx::vec<T,N> operator- (const sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] - b[i];
	return v;
}

template<typename T, int N> inline sx::vec<T,N> operator- (const sx::vec<T,N> &a, const T &b) {
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] - b;
	return v;
}

template<typename T, int N, int M> inline sx::vec<T,N> &operator-= (sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	for (int i = 0; i < N; ++i) a[i] -= b[i];
	return a;
}

template<typename T, int N> inline sx::vec<T,N> &operator-= (sx::vec<T,N> &a, const T &b) {
	for (int i = 0; i < N; ++i) a[i] -= b;
	return a;
}

template<typename T, int N, int M> inline sx::vec<T,N> operator* (const sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] * b[i];
	return v;
}
template<typename T, int N, int M> inline sx::vec<T,N> &operator*= (sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	for (int i = 0; i < N; ++i) a[i] *= b[i];
	return a;
}

template<typename T, int N, int M> inline sx::vec<T,N> operator+ (const sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] + b[i];
	return v;
}

template<typename T, int N> inline sx::vec<T,N> operator+ (const sx::vec<T,N> &a, const T &b) {
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] + b;
	return v;
}

template<typename T, int N, int M> inline sx::vec<T,N> &operator+= (sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	for (int i = 0; i < N; ++i) a[i] += b[i];
	return a;
}

template<typename T, int N> inline sx::vec<T,N> &operator+= (sx::vec<T,N> &a, const T &b) {
	for (int i = 0; i < N; ++i) a[i] += b;
	return a;
}

template<typename T, int N> inline sx::vec<T,N> operator* (const sx::vec<T,N> &a, const T &b) {
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] * b;
	return v;
}

template<typename T, int N> inline sx::vec<T,N> &operator*= (sx::vec<T,N> &a, const T &b) {
	for (int i = 0; i < N; ++i) a[i] *= b;
	return a;
}

template<typename T, int N> inline sx::vec<T,N> operator* (const T &a, const sx::vec<T,N> &b) {
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a * b[i];
	return v;
}

template<typename T, int N, int M> inline sx::vec<T,N> operator/ (const sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] / b[i];
	return v;
}

template<typename T, int N, int M> inline sx::vec<T,N> &operator/= (sx::vec<T,N> &a, const sx::vec<T,M> &b) {
	BOOST_STATIC_ASSERT(N <= M);
	for (int i = 0; i < N; ++i) a[i] /= b[i];
	return a;
}

template<typename T, int N> inline sx::vec<T,N> operator- (const sx::vec<T,N> &p) {
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = -p[i];
	return v;
}

template<typename T, int N> inline sx::vec<T,N> operator/ (const sx::vec<T,N> &a, const T &b) {
	sx::vec<T,N> v;
	for (int i = 0; i < N; ++i) v[i] = a[i] / b;
	return v;
}

template<typename T, int N> inline sx::vec<T,N> &operator/= (sx::vec<T,N> &a, const T &b) {
	for (int i = 0; i < N; ++i) a[i] /= b;
	return a;
}

namespace sx {
	template<typename T> inline const T normalize_self (vec<T,3> &p) {
		T d = sqrabsolute3(p);
		if (denormalized_min < d) {
			d = sx::sqrt(d);
			p /= d;
		}
		return d;
	}
}

template<typename T> inline sx::mat<T,4> operator* (const sx::mat<T,4> &a, const T &f) {
	return sx::mat<T,4>(a[0] * f, a[1] * f, a[2] * f, a[3] * f);
}

template<typename T> inline sx::mat<T,4> &operator*= (sx::mat<T,4> &a, const T &f) {
	a[0] *= f;
	a[1] *= f;
	a[2] *= f;
	a[3] *= f;
	return a;
}

template<typename T, int N> inline sx::mat<T,N> operator+ (const sx::mat<T,N> &a, const sx::mat<T,N> &b) {
	sx::mat<T,N> t;
	for (int i = 0; i < N; ++i) t[i] = a[i] + b[i];
	return t;
}
template<typename T, int N> inline sx::mat<T,N> operator- (const sx::mat<T,N> &a, const sx::mat<T,N> &b) {
	sx::mat<T,N> t;
	for (int i = 0; i < N; ++i) t[i] = a[i] - b[i];
	return t;
}

template<typename T, int N> inline sx::mat<T,N> operator* (const sx::mat<T,N> &a, const sx::mat<T,N> &b) {
	sx::mat<T,N> t;
	for (int i = 0; i < N; ++i) t[i] = a[i] * b;
	return t;
}
template<typename T, int N> inline sx::mat<T,N> &operator*= (sx::mat<T,N> &a, const sx::mat<T,N> &b) {
	SXTEST((sx::check_invariant(a), sx::check_invariant(b)));
	for (int i = 0; i < N; ++i) a[i] *= b;
	return a;
}
template<typename T, int N> inline sx::mat<T,N> &operator>> (const sx::mat<T,N> &a, sx::mat<T,N> &b) {
	b = a * b;
	return b;
}

template<typename T, int N> bool operator== (const sx::mat<T,N> &a, const sx::mat<T,N> &b) {
	SXTEST((sx::check_invariant(a), sx::check_invariant(b)));
	for (int i = 0; i < N; ++i) if (a[i] != b[i]) return false;
	return true;
}
template<typename T, int N> bool operator!= (const sx::mat<T,N> &a, const sx::mat<T,N> &b) {
	return !(a == b);
}

namespace sx {
	template<typename T> inline bool zero (const mat<T,4> &m) {
		SXTEST(sx::check_invariant(m));
		const sx::vec<T,3> z(T(0));
		return ((sx::vec<T,3> &)m[0] == z) && ((sx::vec<T,3> &)m[1] == z) && ((sx::vec<T,3> &)m[2] == z); 
	}
	template<typename T, int N> inline mat<T,N> &mat<T,N>::normalize () {
		BOOST_STATIC_ASSERT(N == 4);
		const T k = reciprocal((*this)[3].w);
		(*this)[0] = (*this)[0] * k;
		(*this)[1] = (*this)[1] * k;
		(*this)[2] = (*this)[2] * k;
		(*this)[3] = (*this)[3] * k;
		return *this;
	}

	template<typename T, int N> bool is_finite (const vec<T,N> &v) {
		SXTEST(sx::check_invariant(v));
		const vec<T,N> max(std::numeric_limits<T>::max());
		return (-max <= v) && (v <= max);
	}

	template<typename T, int N> bool isnormal (const vec<T,N> &v) {
		SXTEST(sx::check_invariant(v));
		if (!std::numeric_limits<T>::has_denorm) return true;
		for (int i = 0; i < N; ++i) if (!sx::isnormal(v[i])) return false;
		return true;
	}
	template<typename T, int N> inline const vec<T,N> undenormal (const vec<T,N> &v) {
		SXTEST(sx::check_invariant(v));
		if (!std::numeric_limits<T>::has_denorm) return v;
		vec<T,N> w;
		for (int i = 0; i < N; ++i) w[i] = sx::isnormal(v[i]) ? v[i] : 0.0f;
		return w;
	}
}

namespace sx {
	namespace matrix {
		extern const sx::mat<float,4> identity;
		extern const sx::mat<float,4> zero;
	}
}

namespace sx {
	template<typename T> class uv {
	public:
		T u, v;
		explicit uv () { }
		explicit uv (T u, T v) : u(u), v(v) { }
		explicit uv (T f) : u(f), v(f) { }
		explicit uv (const sx::vec<T,2> &v) : u(v.x), v(v.y) { }
		operator const sx::vec<T,2> & () const { return *(const sx::vec<T,2> *)(this); }
		operator sx::vec<T,2> & () { return *(sx::vec<T,2> *)(this); }
		void check_invariant () const { sx::check_invariant(u); sx::check_invariant(v); }
	};
}
template<typename T> inline const sx::uv<T> operator* (const sx::uv<T> &a, const sx::mat<T,4> &b) {
//	return sx::uv<T>(a.u*b[0][0] + a.v*b[1][0], a.u*b[0][1] + a.v*b[1][1]);
	return sx::uv<T>(
					a.u * b[0][0] + a.v * b[1][0] + b[3][0],
					a.u * b[0][1] + a.v * b[1][1] + b[3][1]
					);
}
template<typename T>inline const sx::uv<T> operator* (const sx::uv<T> &a, const T &b) {
	return sx::uv<T>(a.u*b, a.v*b);
}
template<typename T>inline const sx::uv<T> operator* (const sx::uv<T> &a, const sx::uv<T> &b) {
	return sx::uv<T>(a.u*b.u, a.v*b.v);
}
template<typename T>inline const sx::uv<T> &operator*= (sx::uv<T> &a, const sx::uv<T> &b) {
	a.u *= b.u;
	a.v *= b.v;
	return a;
}
template<typename T>inline const sx::uv<T> &operator*= (sx::uv<T> &a, const T &b) {
	a.u *= b;
	a.v *= b;
	return a;
}
template<typename T>inline const sx::uv<T> operator/ (const sx::uv<T> &a, const T &b) {
	return sx::uv<T>(a.u/b, a.v/b);
}
template<typename T>inline const sx::uv<T> &operator/= (sx::uv<T> &a, const T &b) {
	a.u /= b;
	a.v /= b;
	return a;
}
template<typename T>inline const sx::uv<T> operator+ (const sx::uv<T> &a, const sx::uv<T> &b) {
	return sx::uv<T>(a.u+b.u, a.v+b.v);
}
template<typename T>inline const sx::uv<T> &operator+= (sx::uv<T> &a, const sx::uv<T> &b) {
	a.u += b.u;
	a.v += b.v;
	return a;
}
template<typename T>inline const sx::uv<T> operator- (const sx::uv<T> &a) {
	return sx::uv<T>(-a.u, -a.v);
}
template<typename T>inline const sx::uv<T> operator- (const sx::uv<T> &a, const sx::uv<T> &b) {
	return sx::uv<T>(a.u-b.u, a.v-b.v);
}
template<typename T>inline const sx::uv<T> &operator-= (sx::uv<T> &a, const sx::uv<T> &b) {
	a.u -= b.u;
	a.v -= b.v;
	return a;
}
template<typename T>inline const bool operator< (const sx::uv<T> &a, const sx::uv<T> &b) {
	return (a.u < b.u) && (a.v < b.v);
}
template<typename T>inline const bool operator<= (const sx::uv<T> &a, const sx::uv<T> &b) {
	return (a.u <= b.u) && (a.v <= b.v);
}
namespace sx {
	template<typename T> inline bool zero (const sx::uv<T> &a) {
		return (sx::zero(a.u) && sx::zero(a.v));
	}
	template<typename T>inline const sx::uv<T> min (const sx::uv<T> &a, const sx::uv<T> &b) {
		return sx::uv<T>(std::min(a.u,b.u), std::min(a.v,b.v));
	}
	template<typename T>inline const sx::uv<T> max (const sx::uv<T> &a, const sx::uv<T> &b) {
		return sx::uv<T>(std::max(a.u,b.u), std::max(a.v,b.v));
	}
}

template<typename T, int K> inline std::istream &operator> (std::istream &stream, sx::rgb<T,K> &t) {
	stream.read((char *)(&t.red), sizeof(t.red));
	stream.read((char *)(&t.green), sizeof(t.green));
	stream.read((char *)(&t.blue), sizeof(t.blue));
	return stream;
}
template<typename T, int K> inline std::istream &operator> (std::istream &stream, sx::rgba<T,K> &t) {
	stream.read((char *)(&t.red), sizeof(t.red));
	stream.read((char *)(&t.green), sizeof(t.green));
	stream.read((char *)(&t.blue), sizeof(t.blue));
	stream.read((char *)(&t.alpha), sizeof(t.alpha));
	return stream;
}
template<typename T, int K> inline std::ostream &operator< (std::ostream &stream, const sx::rgb<T,K> &t) {
	stream.write((const char *)(&t.red), sizeof(t.red));
	stream.write((const char *)(&t.green), sizeof(t.green));
	stream.write((const char *)(&t.blue), sizeof(t.blue));
	return stream;
}
template<typename T, int K> inline std::ostream &operator< (std::ostream &stream, const sx::rgba<T,K> &t) {
	stream.write((const char *)(&t.red), sizeof(t.red));
	stream.write((const char *)(&t.green), sizeof(t.green));
	stream.write((const char *)(&t.blue), sizeof(t.blue));
	stream.write((const char *)(&t.alpha), sizeof(t.alpha));
	return stream;
}

template<typename T, int N> inline std::istream &operator> (std::istream &stream, sx::vec<T,N> &t) { stream.read((char *)(&t), sizeof(t)); return stream; }
template<typename T, int N> inline std::istream &operator> (std::istream &stream, sx::mat<T,N> &t) { stream.read((char *)(&t), sizeof(t)); return stream; }
	
template<typename T, int N> inline std::ostream &operator< (std::ostream &stream, const sx::vec<T,N> &t) { stream.write((const char *)(&t), sizeof(t)); return stream; }
template<typename T, int N> inline std::ostream &operator< (std::ostream &stream, const sx::mat<T,N> &t) { stream.write((const char *)(&t), sizeof(t)); return stream; }

template<typename T> std::ostream &operator<< (std::ostream &s, const sx::uv<T> &uv) {
	s << uv.u << " " << uv.v;
	return s;
}
template<int K> std::ostream& operator<< (std::ostream &s, const sx::rgb<sx::unsigned8,K> &c) {
	s << int(c.red) << " " << int(c.green) << " " << int(c.blue);
	return s;
}
template<typename T, int K> std::ostream& operator<< (std::ostream &s, const sx::rgb<T,K> &c) {
	s << c.red << " " << c.green << " " << c.blue;
	return s;
}
template<int K> std::ostream& operator<< (std::ostream &s, const sx::rgba<sx::unsigned8,K> &c) {
	s << int(c.red) << " " << int(c.green) << " " << int(c.blue) << " " << int(c.alpha);
	return s;
}
template<typename T, int K> std::ostream& operator<< (std::ostream &s, const sx::rgba<T,K> &c) {
	s << c.red << " " << c.green << " " << c.blue << " " << c.alpha;
	return s;
}
template<typename T, int N> std::ostream& operator<< (std::ostream &s, const sx::vec<T,N> &v) {
	for (int i = 0; i < N; ++i) s << v[i] << " ";
	return s;
}
template<typename T, int N> std::ostream& operator<< (std::ostream &s, const sx::mat<T,N> &m) {
	for (int i = 0; i < N; ++i) s << m[i] << " ";
	return s;
}
namespace std {
	template<typename T> class numeric_limits<sx::uv<T> > {
	public:
		static sx::uv<T> max () { return sx::uv<T>(std::numeric_limits<T>::max()); }
	};
	template<typename T, int N> class numeric_limits<sx::vec<T,N> > {
	public:
		static sx::vec<T,N> max () { return sx::vec<T,N>(std::numeric_limits<T>::max()); }
	};
	template<typename T, int K> class numeric_limits<sx::rgb<T,K> > {
	public:
		static sx::rgb<T,K> max () { return sx::rgb<T,K>(std::numeric_limits<T>::max()); }
	};
	template<typename T, int K> class numeric_limits<sx::rgba<T,K> > {
	public:
		static sx::rgba<T,K> max () { return sx::rgba<T,K>(std::numeric_limits<T>::max()); }
	};
}

namespace boost {
	template <> struct has_trivial_constructor<sx::vec<float,2> > : public boost::true_type { };
	template <> struct has_trivial_constructor<sx::vec<float,3> > : public boost::true_type { };
	template <> struct has_trivial_constructor<sx::vec<float,4> > : public boost::true_type { };

	template <> struct has_trivial_copy<sx::vec<float,2> > : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vec<float,3> > : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vec<float,4> > : public boost::true_type { };

	template <> struct has_trivial_destructor<sx::vec<float,1> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<float,2> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<float,3> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<float,4> > : public boost::true_type { };

	template <> struct has_trivial_assign<sx::vec<float,2> > : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vec<float,3> > : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vec<float,4> > : public boost::true_type { };

	template <> struct has_nothrow_assign<sx::vec<float,2> > : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vec<float,3> > : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vec<float,4> > : public boost::true_type { };

	template <> struct has_trivial_constructor<sx::vec<int,2> > : public boost::true_type { };
	template <> struct has_trivial_constructor<sx::vec<int,3> > : public boost::true_type { };
	template <> struct has_trivial_constructor<sx::vec<int,4> > : public boost::true_type { };

	template <> struct has_trivial_copy<sx::vec<int,2> > : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vec<int,3> > : public boost::true_type { };
	template <> struct has_trivial_copy<sx::vec<int,4> > : public boost::true_type { };

	template <> struct has_trivial_destructor<sx::vec<int,1> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<int,2> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<int,3> > : public boost::true_type { };
	template <> struct has_trivial_destructor<sx::vec<int,4> > : public boost::true_type { };

	template <> struct has_trivial_assign<sx::vec<int,2> > : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vec<int,3> > : public boost::true_type { };
	template <> struct has_trivial_assign<sx::vec<int,4> > : public boost::true_type { };

	template <> struct has_nothrow_assign<sx::vec<int,2> > : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vec<int,3> > : public boost::true_type { };
	template <> struct has_nothrow_assign<sx::vec<int,4> > : public boost::true_type { };
}

namespace sx {
	#if SXIOS || SXMACOSX
		template<typename T> inline CGPoint cgpoint (const sx::vec<T,2> &v) {
			return CGPointMake(float(v.x), float(v.y));
		}
		template<typename T> inline CGSize cgsize (const sx::vec<T,2> &v) {
			return CGSizeMake(float(v.x), float(v.y));
		}
	#endif
	#if SXMACOSX
		template<typename T> inline NSPoint nspoint (const sx::vec<T,2> &v) {
			return NSMakePoint(float(v.x), float(v.y));
		}
		template<typename T> inline NSSize nssize (const sx::vec<T,2> &v) {
			return NSMakeSize(float(v.x), float(v.y));
		}
	#endif
}

namespace sx {
	typedef sx::vec<float,2> vector2;
	typedef sx::vec<float,3> vector3;
	typedef sx::vec<float,4> vector4;
}
namespace sx {
	namespace core {
		namespace unittest {
			void test_vectors ();
		}
	}
}

