#pragma once

namespace sxsdk {
	class quaternion_class;
}

namespace sxsdk {
	/// \brief \en blah \enden \ja ２次元のベクトル、または座標を表す構造体 \endja
	typedef sx::vec<float,2> vec2;
	/// \brief \en blah \enden \ja ３次元のベクトル、または座標を表す構造体 \endja
	typedef sx::vec<float,3> vec3;
	/// \brief \en blah \enden \ja ４次元のベクトル、または座標を表す構造体 \endja
	typedef sx::vec<float,4> vec4;
}

namespace sxsdk {
	/// \en blah \enden \ja 色深度 32bits/チャンネルの色を表す構造体 \endja
	typedef sx::rgb<float> rgb_class;
	typedef sx::rgba<float> rgba_class;
}

namespace sxsdk {
	namespace color3 {
		extern const sx::vec<float,3> white;
		extern const sx::vec<float,3> black;
		extern const sx::vec<float,3> red;
		extern const sx::vec<float,3> yellow;
		extern const sx::vec<float,3> green;
		extern const sx::vec<float,3> cyan;
		extern const sx::vec<float,3> blue;
		extern const sx::vec<float,3> magenta;
		extern const sx::vec<float,3> gray;
		extern const sx::vec<float,3> dark_gray;
		extern const sx::vec<float,3> light_gray;
	}
	namespace color4 {
		extern const sx::vec<float,4> white;
		extern const sx::vec<float,4> black;
		extern const sx::vec<float,4> red;
		extern const sx::vec<float,4> yellow;
		extern const sx::vec<float,4> green;
		extern const sx::vec<float,4> cyan;
		extern const sx::vec<float,4> blue;
		extern const sx::vec<float,4> magenta;
		extern const sx::vec<float,4> gray;
		extern const sx::vec<float,4> dark_gray;
		extern const sx::vec<float,4> light_gray;
	}
}

namespace sxsdk {
	/// \brief \en blah \enden \ja ４＊４の行列を表す構造体 \endja
	class mat4 {
	public:
		sx::vec<float,4> x, y, z, w;

		explicit mat4 ();
		explicit mat4 (float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13, float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33 );
		explicit mat4 (const sx::vec<float,4> &a, const sx::vec<float,4> &b, const sx::vec<float,4> &c, const sx::vec<float,4> &d);
		explicit mat4 (float s);
		explicit mat4 (const sx::vec<float,3> &v);
		explicit mat4 (const quaternion_class &q);
		sx::vec<float,4> &operator[] (int i);
		const sx::vec<float,4> &operator[] (int i) const;
		bool operator== (const mat4 &t) const;
		bool operator!= (const mat4 &t) const;
		bool is_identity () const;
		mat4 operator* (float f) const;
		mat4 &operator*= (float f);
		mat4 operator+ (const mat4 &m) const;
		mat4 &operator+= (const mat4 &m);
		mat4 operator- (const mat4 &m) const;
		mat4 &operator-= (const mat4 &m);
		mat4 operator* (const mat4 &m) const;
		mat4 &operator*= (const mat4 &m);
		mat4 inv () const;
		mat4 &normalize ();
		int unmatrix (sx::vec<float,3> &scale, sx::vec<float,3> &shear, sx::vec<float,3> &rotate, sx::vec<float,3> &translate) const;
		static mat4 translate (const sx::vec<float,3> &v);
		static mat4 scale (float s);
		static mat4 scale (const sx::vec<float,3> &s);
		static mat4 scale (const sx::vec<float,3> &o, const sx::vec<float,3> &s);
		static mat4 scale (const sx::vec<float,3> &o, const sx::vec<float,3> &d, float s);
		static mat4 shear (const sx::vec<float,3> &r);
		static mat4 rotate (const sx::vec<float,3> &r);
		static mat4 rotate (const sx::vec<float,3> &d, float r);
		static mat4 rotate (const sx::vec<float,3> &o, const sx::vec<float,3> &d, float r);
		static mat4 rotate (const sx::vec<float,3> &d, float c, float s);
		static mat4 rotate (const sx::vec<float,3> &o, const sx::vec<float,3> &d, float c, float s);
		static mat4 rotate (const sx::vec<float,3> &o, const quaternion_class &q);
		static mat4 rotate (const sx::vec<float,3> &a, const sx::vec<float,3> &b); // rotates the direction vector a to b
		static mat4 rotate (const sx::vec<float,3> &o, const sx::vec<float,3> &a, const sx::vec<float,3> &b); // rotates the direction vector a to b
		static mat4 xmat (const sx::vec<float,3> &v);
		static mat4 ymat (const sx::vec<float,3> &v);
		static mat4 zmat (const sx::vec<float,3> &v);
		static mat4 invalid ();

		static const mat4 identity;
		static const mat4 zero;

		explicit mat4 (const sx::mat<float,4> &m) {
			(*this)[0] = sx::vec<float,4>(m[0]);
			(*this)[1] = sx::vec<float,4>(m[1]);
			(*this)[2] = sx::vec<float,4>(m[2]);
			(*this)[3] = sx::vec<float,4>(m[3]);
		}
	};
	inline static sx::mat<float,4> matrixt (const mat4 &m) { return sx::mat<float,4>(sx::vec<float,4>(m[0]), sx::vec<float,4>(m[1]), sx::vec<float,4>(m[2]), sx::vec<float,4>(m[3])); }
}

namespace sxsdk {
	/// \brief \en blah \enden \ja UVベクトルを表す構造体 \endja
	class uv_vector_class {
	public:
		sx::vec<float,3> du, dv;

		explicit uv_vector_class () { }
		explicit uv_vector_class (const sx::vec<float,3> &du, const sx::vec<float,3> &dv) : du(du), dv(dv) { }
	};
}

namespace sxsdk {
	/// \brief \en blah \enden \ja 四元数を表す構造体 \endja
	class quaternion_class {
	public:
		float w, x, y, z;

		explicit quaternion_class ();
		explicit quaternion_class (float w, float x, float y, float z);
		explicit quaternion_class (const sx::vec<float,4> &v);
		explicit quaternion_class (float w, const sx::vec<float,3> &v);
		explicit quaternion_class (const sx::vec<float,3> &euler);
		explicit quaternion_class (const sx::vec<float,3> &a, const sx::vec<float,3> &b);
		explicit quaternion_class (sx::vec<float,3> a, sx::vec<float,3> b, const sx::vec<float,3> &axis, bool use_axis = false);
		explicit quaternion_class (const sxsdk::mat4 &t);
		explicit quaternion_class (float w);
		quaternion_class operator* (float w) const;
		quaternion_class &operator*= (float w);
		quaternion_class operator/ (float w) const;
		quaternion_class &operator/= (float w);
		quaternion_class operator+ (const quaternion_class &q) const;
		quaternion_class &operator+= (const quaternion_class &q);
		quaternion_class operator- (const quaternion_class &q) const;
		quaternion_class &operator-= (const quaternion_class &q);
		quaternion_class operator* (const quaternion_class &q) const;
		quaternion_class &operator*= (const quaternion_class &q);
		quaternion_class operator/ (const quaternion_class &q) const;
		quaternion_class &operator/= (const quaternion_class &q);
		quaternion_class operator- () const;
		quaternion_class inv () const;
		bool operator== (const quaternion_class &q) const;
		bool operator!= (const quaternion_class &q) const;
		void get_euler (sx::vec<float,3> &e) const;
		sx::vec<float,3> get_v () const;
		sx::vec<float,3> v () const;
		sx::vec<float,3> direction (float distance) const;
		quaternion_class &operator*= (const sxsdk::mat4 &t);
		static const quaternion_class identity;
		static const quaternion_class zero;
	};
}

namespace sxsdk {
	/// \brief \en blah \enden \ja ３次元のバウンディングボックスを現す構造体 \endja
	class box3_class {
	public:
		sx::vec<float,4> min;
		sx::vec<float,4> max;
		bool empty;

		explicit box3_class () : empty(true) { }
		explicit box3_class (float minx, float miny, float minz, float maxx, float maxy, float maxz) : min(minx, miny, minz, 0.0f), max(maxx, maxy, maxz, 0.0f), empty(false) { }
		box3_class &operator<< (const sx::vec<float,3> &v);
		box3_class &operator<< (const box3_class &v);
		float get_size () const { const sx::vec<float,4> size(max - min); return size.x + size.y + size.z; }
	};
}

/// \relates sxsdk::mat4
inline static sxsdk::mat4 &operator<< (sxsdk::mat4 &p, const sxsdk::mat4 &q) {
	return p *= q;
}
/// \relates sxsdk::mat4
inline static sxsdk::mat4 &operator>> (const sxsdk::mat4 &p, sxsdk::mat4 &q) {
	q = p * q;
	return q;
}
/// \relates sx::vec<float,2>
inline static sx::vec<float,2> operator* (const sx::vec<float,2> &p, const sxsdk::mat4 &t) {
	sx::vec<float,2> q;
	q[0] = p[0]*t[0][0] + p[1]*t[1][0] + t[3][0];
	q[1] = p[0]*t[0][1] + p[1]*t[1][1] + t[3][1];
	if (t[3][3] != 1.0) q /= t[3][3];
	return q;
}
namespace sxsdk {
	/// \relates sx::vec<float,3>
	inline static sx::vec<float,3> transform_direction (const sx::vec<float,3> &p, const sxsdk::mat4 &t) {
		return sx::vec<float,3>(p[0]*t[0][0]+p[1]*t[1][0]+p[2]*t[2][0], p[0]*t[0][1]+p[1]*t[1][1]+p[2]*t[2][1], p[0]*t[0][2]+p[1]*t[1][2]+p[2]*t[2][2]);
	}
	/// \relates sx::vec<float,3>
	inline static sx::vec<float,3> transform_normal (const sxsdk::mat4 &it, const sx::vec<float,3> &p) {
		return sx::vec<float,3>(it[0][0]*p[0] + it[0][1]*p[1] + it[0][2]*p[2], it[1][0]*p[0] + it[1][1]*p[1] + it[1][2]*p[2], it[2][0]*p[0] + it[2][1]*p[1] + it[2][2]*p[2]);
	}
	// \relates sx::vec<float,2>
	inline static sx::vec<float,2> polar_to_cartesian (const sx::vec<float,2> &p) {	// 0 <= p.x <= 2pi, 0 <= p.y <= 1
		return sx::vec<float,2>(cos(p[0]) * p[1], sin(p[0]) * p[1]);
	}
	/// \relates sx::vec<float,3>
	//inline static sx::vec<float,3> product (const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
	//	return a * b;
	//}
	/// \relates sxsdk::quaternion_class
	inline static sxsdk::quaternion_class slerp (const sxsdk::quaternion_class &a, const sxsdk::quaternion_class &b, float t) {
		float to1[4];
		double omega, cosom, sinom, scale0, scale1;
		cosom = a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
		if (cosom < 0.0) {
			cosom = -cosom;
			to1[0] = -b.x;
			to1[1] = -b.y;
			to1[2] = -b.z;
			to1[3] = -b.w;
		}
		else {
			to1[0] = b.x;
			to1[1] = b.y;
			to1[2] = b.z;
			to1[3] = b.w;
		}
		if ((1.0-cosom) > sx::epsilon) {
			omega = acos(cosom);
			sinom = sin(omega);
			scale0 = sin((1.0-t)*omega) / sinom;
			scale1 = sin(t*omega) / sinom;
		}
		else {
			scale0 = 1.0 - t;
			scale1 = t;
		}
		return a*scale0 + b*scale1;
	}
	/// \relates sxsdk::quaternion_class
	inline static sxsdk::quaternion_class normalize (const sxsdk::quaternion_class &q) {
		return q*(1.0/sqrt(q.w*q.w+q.x*q.x+q.y*q.y+q.z*q.z));
	}
	/// \relates sx::vec<float,2>
	inline static float absolute (const sx::vec<float,2> &v) {
		return sqrt(v[0] * v[0] + v[1] * v[1]);
	}
	/// \relates sx::vec<float,3>
	inline static float absolute (const sx::vec<float,3> &v) {
		return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}
	/// \relates sx::vec<float,4>
	inline static float absolute (const sx::vec<float,4> &v) {
		return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}
}
/// \relates sx::vec<float,3>
inline static sx::vec<float,3> operator* (const sx::vec<float,3> &p, const sxsdk::mat4 &t) {
	sx::vec<float,3> q;
	q[0] = p[0]*t[0][0] + p[1]*t[1][0] + p[2]*t[2][0] + t[3][0];
	q[1] = p[0]*t[0][1] + p[1]*t[1][1] + p[2]*t[2][1] + t[3][1];
	q[2] = p[0]*t[0][2] + p[1]*t[1][2] + p[2]*t[2][2] + t[3][2];
	if (t[3][3] != 1.0) q /= t[3][3];
	return q;
}
/// \relates sx::vec<float,4>
inline static sx::vec<float,4> operator* (const sx::vec<float,4> &p, const sxsdk::mat4 &t) {
	sx::vec<float,4> q;
	for (int i=0; i<4; i++) q[i] = p[0]*t[0][i] + p[1]*t[1][i] + p[2]*t[2][i] + p[3]*t[3][i];
	return q;
}
namespace sxsdk {
//	/// \relates sx::vec<float,2>
//	inline static float inner_product (const sx::vec<float,2> &a, const sx::vec<float,2> &b) {
//		return a[0] * b[0] + a[1] * b[1];
//	}

//	/// \relates sx::vec<float,3>
//	inline static float inner_product (const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
//		return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
//	}

//	/// \relates sx::vec<float,4>
//	inline static float inner_product (const sx::vec<float,4> &a, const sx::vec<float,4> &b) {
//		return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
//	}
	/// \relates sx::vec<float,4>
	inline static sx::vec<float,3> multiply_alpha (const sx::vec<float,4> &c) {
		return sx::vec<float,3>(c) * c[3];
	}
	/// \relates sx::vec<float,3>
	inline static sx::vec<float,3> mul (const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
		return sx::vec<float,3>(a[0] * b[0], a[1] * b[1], a[2] * b[2]);
	}
	/// \relates sx::vec<float,4>
	inline static sx::vec<float,4> mul (const sx::vec<float,4> &a, const sx::vec<float,4> &b) {
		return sx::vec<float,4>(a[0] * b[0], a[1] * b[1], a[2] * b[2], a[3] * b[3]);
	}
	/// \relates sx::vec<float,2>
	inline static float abs2 (const sx::vec<float,2> &v) {
		return v[0] * v[0] + v[1] * v[1];
	}
	/// \relates sx::vec<float,3>
	inline static float abs2 (const sx::vec<float,3> &v) {
		return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	}
	inline static float vabs (float x) {
		return (0.0 <= x) ? x : -x;
	}
	/// \relates sx::vec<float,2>
	inline static sx::vec<float,2> vabs (const sx::vec<float,2> &v) {
		return sx::vec<float,2>(vabs(v[0]), vabs(v[1]));
	}
	/// \relates sx::vec<float,3>
	inline static sx::vec<float,3> vabs (const sx::vec<float,3> &v) {
		return sx::vec<float,3>(vabs(v[0]), vabs(v[1]), vabs(v[2]));
	}
	/// \relates sx::vec<float,4>
	inline static sx::vec<float,4> vabs (const sx::vec<float,4> &v) {
		return sx::vec<float,4>(vabs(v[0]), vabs(v[1]), vabs(v[2]), vabs(v[3]));
	}
}
/// \relates sxsdk::mat4
inline static sxsdk::mat4 operator* (float a, const sxsdk::mat4 &b) {
	return b * a;
}
namespace sxsdk {
	/// \relates sx::vec<float,2>
	inline static float distance2 (const sx::vec<float,2> &a, const sx::vec<float,2> &b) {
		return absolute(a-b);
	}
	/// \relates sx::vec<float,3>
	inline static float distance2 (const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
		return absolute(sx::vec<float,2>(a) - sx::vec<float,2>(b));
	}
	/// \relates sx::vec<float,3>
	inline static float distance3 (const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
		return absolute(a-b);
	}
	/// \relates sx::vec<float,3>
	inline static bool normalized (const sx::vec<float,3> &v) {
		float d = absolute(v);
		return 0.99 < d && d < 1.01;
	}
	/// \relates sx::vec<float,4>
	inline static bool normalized (const sx::vec<float,4> &v) {
		float d = absolute(v);
		return 0.99 < d && d < 1.01;
	}
	// \relates sx::vec<float,2>
	inline static sx::vec<float,2> cartesian_to_polar (const sx::vec<float,2> &c) {
		const float Pi = 3.14159265358979323846f;
		sx::vec<float,2> p;
		p[1] = absolute(c);
		if (p[1] <= 0.0) return sx::vec<float,2>(0.0, 0.0);
		if (std::abs(c[0]) < fabs(c[1])) {
			p[0] = acos(c[0] / p[1]);
			if (c[1] < 0.0) p[0] = (2.0*Pi) - p[0];
		}
		else {
			p[0] = asin(c[1] / p[1]);
			if (c[0] < 0.0) p[0] = Pi - p[0];
			if (p[0] < 0.0) p[0] += (2.0*Pi);
		}
		return p;
	}
}
/// \relates sx::vec<float,2>
inline static sx::vec<float,2> operator* (float t, const sx::vec<float,2> &v) {
	return v * t;
}
/// \relates sx::vec<float,3>
inline static sx::vec<float,3> operator* (float t, const sx::vec<float,3> &v) {
	return v * t;
}
/// \relates sx::vec<float,4>
inline static sx::vec<float,4> operator* (float t, const sx::vec<float,4> &v) {
	return v * t;
}
/// \relates sx::vec<float,2>
inline static sx::vec<float,2> &operator*= (sx::vec<float,2> &a, const sxsdk::mat4 &b) {
	return (a = a * b);
}
/// \relates sx::vec<float,3>
inline static sx::vec<float,3> &operator*= (sx::vec<float,3> &a, const sxsdk::mat4 &b) {
	return (a = a * b);
}
/// \relates sx::vec<float,3>
inline static sx::vec<float,3> madd (const sx::vec<float,3> &a, const sx::vec<float,3> &b, const sx::vec<float,3> &c) {
	return sx::vec<float,3>(a[0]*b[0]+c[0], a[1]*b[1]+c[1], a[2]*b[2]+c[2]);
}
/// \relates sx::vec<float,3>
inline static sx::vec<float,3> abs (const sx::vec<float,3> &v) {
	return sx::vec<float,3>(fabs(v[0]), fabs(v[1]), fabs(v[2]));
}
/// \relates sx::vec<float,3>
//inline static sx::vec<float,3> lerp (const sx::vec<float,3> &a, const sx::vec<float,3> &b, float t) {
//	return sx::vec<float,3>((b[0] - a[0]) * t + a[0], (b[1] - a[1]) * t + a[1], (b[2] - a[2]) * t + a[2]);
//}
/// \relates sx::vec<float,3>
//inline static bool is_finite (const sx::vec<float,3> &v) {
//	const float max = std::numeric_limits<float>::max();
//	return -max <= v[0] && v[0] <= max && -max <= v[1] && v[1] <= max && -max <= v[2] && v[2] <= max;
//}
/// \relates sxsdk::rgb_class
inline static float luminance (const sxsdk::rgb_class &c) {
	return c.red * 0.299 + c.green * 0.587 + c.blue * 0.114;
}
/// \relates rgba_class
inline static float luminance (const sxsdk::rgba_class &c) {
	return c.red * 0.299 + c.green * 0.587 + c.blue * 0.114;
}
/// \relates sxsdk::mat4
inline static sxsdk::mat4 inv (const sxsdk::mat4 &t) { return t.inv(); }
class Minor {
	const sxsdk::mat4& m;
	int j, k;
public:
	Minor(const sxsdk::mat4& _m, int _j, int _k):m(_m),j(_j),k(_k){};
	float det() const {
		return (
			(*this)(0,0) * ((*this)(1,1) * (*this)(2,2) - (*this)(1,2) * (*this)(2,1)) +
			(*this)(1,0) * ((*this)(0,2) * (*this)(2,1) - (*this)(0,1) * (*this)(2,2)) +
			(*this)(2,0) * ((*this)(0,1) * (*this)(1,2) - (*this)(0,2) * (*this)(1,1))
		);
	}
	
	float operator() (int _j, int _k) const {
		if ( _j >= j ) ++_j;
		if ( _k >= k ) ++_k;
		
		return m[_j][_k];
	}
};
/// \relates sxsdk::mat4
inline sxsdk::mat4 inverse (const sxsdk::mat4 &a) {
	const float detA = (
		a[0][0] * (
			a[1][1] * (a[2][2] * a[3][3] - a[2][3] * a[3][2]) +
			a[2][1] * (a[1][3] * a[3][2] - a[1][2] * a[3][3]) +
			a[3][1] * (a[1][2] * a[2][3] - a[1][3] * a[2][2])
		) -
		a[1][0] * (
			a[0][1] * (a[2][2] * a[3][3] - a[2][3] * a[3][2]) +
			a[2][1] * (a[0][3] * a[3][2] - a[0][2] * a[3][3]) +
			a[3][1] * (a[0][2] * a[2][3] - a[0][3] * a[2][2])
		) +
		a[2][0] * (
			a[0][1] * (a[1][2] * a[3][3] - a[1][3] * a[3][2]) +
			a[1][1] * (a[0][3] * a[3][2] - a[0][2] * a[3][3]) +
			a[3][1] * (a[0][2] * a[1][3] - a[0][3] * a[1][2])
		) -
		a[3][0] * (
			a[0][1] * (a[1][2] * a[2][3] - a[1][3] * a[2][2]) +
			a[1][1] * (a[0][3] * a[2][2] - a[0][2] * a[2][3]) +
			a[2][1] * (a[0][2] * a[1][3] - a[0][3] * a[1][2])
		)
	);
	if (detA == 0.0) return sxsdk::mat4::identity;
	sxsdk::mat4 r;
	for ( int j = 0; j < 4; ++j ) {
		for ( int k = 0; k < 4; ++k ) {
			Minor m(a, j, k);
			r[k][j] = (((j + k) % 2) == 0 ? 1 : -1) * m.det();
		}
	}
	r *= (1.0 / detA);
	return r;
}
/// \relates box3_class
inline static sxsdk::box3_class operator* (const sxsdk::box3_class &b, const sxsdk::mat4 &t) {
	sxsdk::box3_class b2;
	if (!b.empty) {
		b2 << sx::vec<float,3>(b.min[0], b.min[1], b.min[2]) * t;
		b2 << sx::vec<float,3>(b.min[0], b.min[1], b.max[2]) * t;
		b2 << sx::vec<float,3>(b.min[0], b.max[1], b.min[2]) * t;
		b2 << sx::vec<float,3>(b.min[0], b.max[1], b.max[2]) * t;
		b2 << sx::vec<float,3>(b.max[0], b.min[1], b.min[2]) * t;
		b2 << sx::vec<float,3>(b.max[0], b.min[1], b.max[2]) * t;
		b2 << sx::vec<float,3>(b.max[0], b.max[1], b.min[2]) * t;
		b2 << sx::vec<float,3>(b.max[0], b.max[1], b.max[2]) * t;
	}
	return b2;
}
/// \relates box3_class
inline static sxsdk::box3_class operator*= (sxsdk::box3_class &b, const sxsdk::mat4 &t) {
	if (!b.empty) b = b * t;
	return b;
}

/// \relates sx::vec<float,4>
inline static sx::vec<float,4> min (const sx::vec<float,4> &a, const sx::vec<float,4> &b) {
	sx::vec<float,4> c;
	c[0] = (a[0] < b[0]) ? a[0] : b[0];
	c[1] = (a[1] < b[1]) ? a[1] : b[1];
	c[2] = (a[2] < b[2]) ? a[2] : b[2];
	c[3] = (a[3] < b[3]) ? a[3] : b[3];
	return c;
}
/// \relates sx::vec<float,4>
inline static sx::vec<float,4> max (const sx::vec<float,4> &a, const sx::vec<float,4> &b) {
	sx::vec<float,4> c;
	c[0] = (a[0] < b[0]) ? b[0] : a[0];
	c[1] = (a[1] < b[1]) ? b[1] : a[1];
	c[2] = (a[2] < b[2]) ? b[2] : a[2];
	c[3] = (a[3] < b[3]) ? b[3] : a[3];
	return c;
}

#if SXWINDOWS
	template<int K> COLORREF RGB_ (const sx::rgb<sx::unsigned8,K> &c) {
		return RGB(c.red, c.green, c.blue);
	}
	template<int K> COLORREF RGB_ (const sx::rgba<sx::unsigned8,K> &c) {
		return RGB(c.red, c.green, c.blue);
	}
#endif

inline sxsdk::mat4::mat4 () { }
inline sxsdk::mat4::mat4 (float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13, float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33 ) {
	(*this)[0][0] = a00; (*this)[0][1] = a01; (*this)[0][2] = a02; (*this)[0][3] = a03;
	(*this).y[0] = a10; (*this).y[1] = a11; (*this).y[2] = a12; (*this).y[3] = a13;
	(*this).z[0] = a20; (*this).z[1] = a21; (*this).z[2] = a22; (*this).z[3] = a23;
	(*this).w[0] = a30; (*this).w[1] = a31; (*this).w[2] = a32; (*this).w[3] = a33;
}
inline sxsdk::mat4::mat4 (const sx::vec<float,4> &a, const sx::vec<float,4> &b, const sx::vec<float,4> &c, const sx::vec<float,4> &d) {
	(*this)[0] = a; (*this).y = b; (*this).z = c; (*this).w = d;
}
inline sxsdk::mat4::mat4 (float s) {
	(*this)[0][0] = s; (*this)[0][1] = 0; (*this)[0][2] = 0; (*this).x[3] = 0;
	(*this).y[0] = 0; (*this).y[1] = s; (*this).y[2] = 0; (*this).y[3] = 0;
	(*this).z[0] = 0; (*this).z[1] = 0; (*this).z[2] = s; (*this).z[3] = 0;
	(*this).w[0] = 0; (*this).w[1] = 0; (*this).w[2] = 0; (*this).w[3] = 1;
}
inline sxsdk::mat4::mat4 (const sx::vec<float,3> &v) {
	(*this)[0][0] = 1; (*this)[0][1] = 0; (*this)[0][2] = 0; (*this)[0][3] = 0;
	(*this).y[0] = 0; (*this).y[1] = 1; (*this).y[2] = 0; (*this).y[3] = 0;
	(*this).z[0] = 0; (*this).z[1] = 0; (*this).z[2] = 1; (*this).z[3] = 0;
	(*this).w[0] = v[0]; (*this).w[1] = v[1]; (*this).w[2] = v[2]; (*this).w[3] = 1;
}
inline sxsdk::mat4::mat4 (const sxsdk::quaternion_class &q) {
	(*this)[0][0] = q.w*q.w+q.x*q.x-q.y*q.y-q.z*q.z; (*this)[0][1] = 2*q.x*q.y-2*q.w*q.z; (*this)[0][2] = 2*q.x*q.z+2*q.w*q.y; (*this)[0][3] = 0.0;
	(*this).y[0] = 2*q.x*q.y+2*q.w*q.z; (*this).y[1] = q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z; (*this).y[2] = 2*q.y*q.z-2*q.w*q.x; (*this).y[3] = 0.0;
	(*this).z[0] = 2*q.x*q.z-2*q.w*q.y; (*this).z[1] = 2*q.y*q.z+2*q.w*q.x; (*this).z[2] = q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z; (*this).z[3] = 0.0;
	(*this).w[0] = 0.0; (*this).w[1] = 0.0; (*this).w[2] = 0.0; (*this).w[3] = q.w*q.w+q.x*q.x+q.y*q.y+q.z*q.z;
	const float k = (*this).w[3];
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) (*this)[i][j] /= k;
	(*this).w[3] = 1.0;
}
inline sx::vec<float,4> &sxsdk::mat4::operator[] (int i) {
	return (&x)[i];
}
inline const sx::vec<float,4> &sxsdk::mat4::operator[] (int i) const {
	return (&x)[i];
}
inline bool sxsdk::mat4::operator== (const sxsdk::mat4 &t) const {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		if ((*this)[i][j] != t[i][j]) return false; }
	return true;
}
inline bool sxsdk::mat4::operator!= (const sxsdk::mat4 &t) const { return !(*this == t); }
inline bool sxsdk::mat4::is_identity () const {
	return (*this) == identity;
}
inline sxsdk::mat4 sxsdk::mat4::operator* (float b) const {
	sxsdk::mat4 c;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		c[i][j] = (*this)[i][j] * b;
	}
	return c;
}
inline sxsdk::mat4 &sxsdk::mat4::operator*= (float b) {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		(*this)[i][j] *= b;
	}
	return *this;
}
inline sxsdk::mat4 sxsdk::mat4::operator+ (const sxsdk::mat4 &b) const {
	sxsdk::mat4 c;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		c[i][j] = (*this)[i][j] + b[i][j];
	}
	return c;
}
inline sxsdk::mat4 &sxsdk::mat4::operator+= (const sxsdk::mat4 &b) {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		(*this)[i][j] += b[i][j];
	}
	return *this;
}
inline sxsdk::mat4 sxsdk::mat4::operator- (const sxsdk::mat4 &b) const {
	sxsdk::mat4 c;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		c[i][j] = (*this)[i][j] - b[i][j];
	}
	return c;
}
inline sxsdk::mat4 &sxsdk::mat4::operator-= (const sxsdk::mat4 &b) {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		(*this)[i][j] -= b[i][j];
	}
	return *this;
}
inline sxsdk::mat4 sxsdk::mat4::operator* (const sxsdk::mat4 &q) const {
	sxsdk::mat4 t;
	t[0] = (*this).x * q;
	t[1] = (*this).y * q;
	t[2] = (*this).z * q;
	t[3] = (*this).w * q;
	return t;
}
inline sxsdk::mat4 &sxsdk::mat4::operator*= (const sxsdk::mat4 &q) {
	return (*this = *this * q);
}
inline static float det (const sxsdk::mat4 &a, int i1, int i2, int i3, int j1, int j2, int j3) {
	return (
				(a[i1][j1]*a[i2][j2]*a[i3][j3])
			+	(a[i1][j2]*a[i2][j3]*a[i3][j1])
			+	(a[i1][j3]*a[i2][j1]*a[i3][j2])
			-	(a[i1][j1]*a[i2][j3]*a[i3][j2])
			-	(a[i1][j2]*a[i2][j1]*a[i3][j3])
			-	(a[i1][j3]*a[i2][j2]*a[i3][j1]));
}
inline sxsdk::mat4 sxsdk::mat4::inv () const {
	sxsdk::mat4 m;
	float d = det(*this,0,1,2,0,1,2);
	if (0.0 < d || d < -0.0) {
		d =  1.0 / d;
		m[0][0] =  det(*this,1,2,3,1,2,3)*d;
		m[0][1] = -det(*this,0,2,3,1,2,3)*d;
		m[0][2] =  det(*this,0,1,3,1,2,3)*d;
		m[0][3] = -det(*this,0,1,2,1,2,3)*d;
		m[1][0] = -det(*this,1,2,3,0,2,3)*d;
		m[1][1] =  det(*this,0,2,3,0,2,3)*d;
		m[1][2] = -det(*this,0,1,3,0,2,3)*d;
		m[1][3] =  det(*this,0,1,2,0,2,3)*d;
		m[2][0] =  det(*this,1,2,3,0,1,3)*d;
		m[2][1] = -det(*this,0,2,3,0,1,3)*d;
		m[2][2] =  det(*this,0,1,3,0,1,3)*d;
		m[2][3] = -det(*this,0,1,2,0,1,3)*d;
		m[3][0] = -det(*this,1,2,3,0,1,2)*d;
		m[3][1] =  det(*this,0,2,3,0,1,2)*d;
		m[3][2] = -det(*this,0,1,3,0,1,2)*d;
		m[3][3] = 1.0;
	}
	else m = *this;
	return m;
}
inline sxsdk::mat4 &sxsdk::mat4::normalize () {
	sxsdk::mat4 &m = *this;
	const float k = 1.0 / m[3][3];
	m[0][0] *= k;
	m[0][1] *= k;
	m[0][2] *= k;
	m[0][3] *= k;
	m[1][0] *= k;
	m[1][1] *= k;
	m[1][2] *= k;
	m[1][3] *= k;
	m[2][0] *= k;
	m[2][1] *= k;
	m[2][2] *= k;
	m[2][3] *= k;
	m[3][0] *= k;
	m[3][1] *= k;
	m[3][2] *= k;
	return *this;
}
inline int sxsdk::mat4::unmatrix (sx::vec<float,3> &scale, sx::vec<float,3> &shear, sx::vec<float,3> &rotate, sx::vec<float,3> &translate) const {
	const sxsdk::mat4 &mat = *this;
	sxsdk::mat4 locmat;
	sxsdk::mat4 pmat;
	sx::vec<float,3> row[3], p;
	double a;

	locmat = mat;

	// Normalize the matrix
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			locmat[i][j] /= locmat[3][3];
		}
	}

	// pmat is used to solve the perspective, but it also provides
	// an easy way to test for sigularity of the upper 3x3 component.
	pmat = locmat;
	{	for (int i = 0; i < 3; i++) {
			pmat[i][3] = 0.0; }
	}
	//pmat[4][3] = 1.0;
	pmat[3][3] = 1.0;

	//...

	// Take care of translation.
	for (int i = 0; i < 3; i++) {
		translate[i] = locmat[3][i];
		locmat[3][i] = 0.0;
	}
	// Now get scale and shear.
	for (int i = 0; i < 3; i++) {
		row[i][0] = locmat[i][0];
		row[i][1] = locmat[i][1];
		row[i][2] = locmat[i][2];
	}
	// Compute X scale factor and normalize first row.
	scale.x = normalize_self(row[0]);

	// Compute XY shear factor and make 2nd row orthogonal to 1st
	shear.z = inner_product(row[0], row[1]);
	row[1][0] -= row[0][0] * shear.z;
	row[1][1] -= row[0][1] * shear.z;
	row[1][2] -= row[0][2] * shear.z;

	// Now, compute Y scale and normalize 2nd row.
	scale.y = normalize_self(row[1]);
	shear.z /= scale.y;

	// Compute XY and YZ shears, orthogonalize 3rd row.
	shear.y = inner_product(row[0], row[2]);
	row[2][0] -= row[0][0] * shear.y;
	row[2][1] -= row[0][1] * shear.y;
	row[2][2] -= row[0][2] * shear.y;
	shear.x = inner_product(row[1], row[2]);
	row[2][0] -= row[1][0] * shear.x;
	row[2][1] -= row[1][1] * shear.x;
	row[2][2] -= row[1][2] * shear.x;

	// Next, get Z scale and normalize 3rd row.
	scale.z = normalize_self(row[2]);
	shear.y /= scale.z;
	shear.x /= scale.z;

	// At this point, the matrix (in rows[]) is orthonormal.
	// Check for a coordinate system flip. If the determinant
	// is -1, the negate the matrix and scaling factors.
	p = product(row[1], row[2]);
	if (inner_product(row[0], p) < 0.0) {
		for (int i = 0; i < 3; i++) {
			scale[i] *= -1.0;
			row[i][0] *= -1.0;
			row[i][1] *= -1.0;
			row[i][2] *= -1.0;
		}
	}
	// Now, get the rotations out, as described in the gem.
	rotate.y = asin(-row[0][2]);
	a = cos(rotate.y);
	if ((a < -sx::epsilon) || (sx::epsilon < a)) {
		rotate.x = atan2(row[1][2], row[2][2]);
		rotate.z = atan2(row[0][1], row[0][0]);
	}
	else {
		//rotate.x = atan2(row[1][0], row[1][1]);
		if (0 < rotate.y)	rotate.x = atan2(row[1][0], row[1][1]);
		else				rotate.x = -atan2(row[1][0], row[1][1]);
		rotate.z = 0.0;
	}
	return 1;
}
inline sxsdk::mat4 sxsdk::mat4::translate (const sx::vec<float,3> &v) {
	sxsdk::mat4 t = sxsdk::mat4::identity;
	t[3][0] = v.x;
	t[3][1] = v.y;
	t[3][2] = v.z;
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::scale (float s) {
	sxsdk::mat4 t = sxsdk::mat4::identity;
	t[0][0] = s;
	t[1][1] = s;
	t[2][2] = s;
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::scale (const sx::vec<float,3> &s) {
	sxsdk::mat4 t = sxsdk::mat4::identity;
	t[0][0] = s.x;
	t[1][1] = s.y;
	t[2][2] = s.z;
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::scale (const sx::vec<float,3> &o, const sx::vec<float,3> &s) {
	return translate(-o) * scale(s) * translate(o);
}
inline sxsdk::mat4 sxsdk::mat4::scale (const sx::vec<float,3> &o, const sx::vec<float,3> &d, float s) {
	const sxsdk::mat4 t = zmat(d);
	return sxsdk::mat4::translate(-o) * t * scale(sx::vec<float,3>(1,1,s)) * t.inv() * sxsdk::mat4::translate(o);
}
inline sxsdk::mat4 sxsdk::mat4::shear (const sx::vec<float,3> &s) {
	sxsdk::mat4 t(identity);
	t.z.y = s.x;
	t.z.x = s.y;
	t.y.x = s.z;
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &r) {
	float s = sin(r.x), c = cos(r.x);
	const sxsdk::mat4 rx(1,0,0,0,0,c,s,0,0,-s,c,0,0,0,0,1);
	s = sin(r.y); c = cos(r.y);
	const sxsdk::mat4 ry(c,0,-s,0,0,1,0,0,s,0,c,0,0,0,0,1);
	s = sin(r.z); c = cos(r.z);
	const sxsdk::mat4 rz(c,s,0,0,-s,c,0,0,0,0,1,0,0,0,0,1);
	return rx*ry*rz;
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &d, float r) {
	return rotate(d, cos(r), sin(r));
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &o, const sx::vec<float,3> &d, float r) {
	return translate(-o) * rotate(d, cos(r), sin(r)) * translate(o);
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &d, float c, float s) {
	sxsdk::mat4 t = zero;
	float l, m, n, l2, m2, n2 ;
	sx::vec<float,3> dd = sx::normalize(d);
	l = dd.x;
	m = dd.y;
	n = dd.z;
	l2 = l * l;
	m2 = m * m;
	n2 = n * n;
	t[0][0] = l2 + (1.0 - l2) * c;
	t[0][1] = l * m * (1.0 - c) + n * s;
	t[0][2] = l * n * (1.0 - c) - m * s;
	t[1][0] = l * m * (1.0 - c) - n * s;
	t[1][1] = m2 + (1.0 - m2) * c;
	t[1][2] = m * n * (1.0 - c) + l * s;
	t[2][0] = l * n * (1.0 - c) + m * s;
	t[2][1] = m * n * (1.0 - c) - l * s;
	t[2][2] = n2 + (1.0 - n2) * c;
	t[3][3] = 1.0;
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &o, const sx::vec<float,3> &d, float c, float s) {
	return translate(-o) * rotate(d, c, s) * translate(o);
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &o, const sxsdk::quaternion_class &q) {
	return translate(-o) * sxsdk::mat4(q) * translate(o);
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
	return sxsdk::mat4(sxsdk::quaternion_class(a, b));
}
inline sxsdk::mat4 sxsdk::mat4::rotate (const sx::vec<float,3> &o, const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
	return rotate(o, sxsdk::quaternion_class(a, b));
}
inline sxsdk::mat4 sxsdk::mat4::xmat (const sx::vec<float,3> &v) {
	sx::vec<float,3> u = v;
	if (normalize_self(u) <= 0) { return sxsdk::mat4::identity; }
	sx::vec<float,3> p = product(u, sx::vec<float,3>(1,0,0));
	float c = inner_product(sx::vec<float,3>(1,0,0), u);
	sxsdk::mat4 t;
	if (absolute(p) <= 0) {
		if (c < 0)
			t = sxsdk::mat4::rotate(sx::vec<float,3>(0,1,0), 3.14159265358979323846f);
		else
			t = sxsdk::mat4::identity;
	}
	else {
		float s = sqrt(1-c*c);
		float r = sxsdk::cartesian_to_polar(sx::vec<float,2>(c, s)).x;
		t = sxsdk::mat4::rotate(p, r);
	}
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::ymat (const sx::vec<float,3> &v) {
	sx::vec<float,3> u = v;
	if (normalize_self(u) <= 0) { return sxsdk::mat4::identity; }
	sx::vec<float,3> p = product(u, sx::vec<float,3>(0,1,0));
	float c = inner_product(sx::vec<float,3>(0,1,0), u);
	sxsdk::mat4 t;
	if (absolute(p) <= 0) {
		if (c < 0)
			t = sxsdk::mat4::rotate(sx::vec<float,3>(0,0,1), 3.14159265358979323846f);
		else
			t = sxsdk::mat4::identity;
	}
	else {
		float s = sqrt(1-c*c);
		float r = sxsdk::cartesian_to_polar(sx::vec<float,2>(c, s)).x;
		t = sxsdk::mat4::rotate(p, r);
	}
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::zmat (const sx::vec<float,3> &v) {
	sx::vec<float,3> u = v;
	if (normalize_self(u) <= 0) { return sxsdk::mat4::identity; }
	sx::vec<float,3> p = product(u, sx::vec<float,3>(0.0, 0.0, 1.0));
	float c = inner_product(sx::vec<float,3>(0.0, 0.0, 1.0), u);
	sxsdk::mat4 t;
	if (absolute(p) <= 0) {
		if (c < 0)
			t = sxsdk::mat4::rotate(sx::vec<float,3>(1,0,0), 3.14159265358979323846f);
		else
			t = sxsdk::mat4::identity;
	}
	else {
		float s = sqrt(1-c*c);
		float r = sxsdk::cartesian_to_polar(sx::vec<float,2>(c, s)).x;
		t = sxsdk::mat4::rotate(p, r);
	}
	return t;
}
inline sxsdk::mat4 sxsdk::mat4::invalid () {
	return sxsdk::mat4(
		std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(),
		std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(),
		std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(),
		std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN(), std::numeric_limits<float>::signaling_NaN());
}

inline sxsdk::quaternion_class::quaternion_class () : w(0.0), x(0.0), y(0.0), z(0.0) { }
inline sxsdk::quaternion_class::quaternion_class (float w, float x, float y, float z) : w(w), x(x), y(y), z(z) { }
inline sxsdk::quaternion_class::quaternion_class (const sx::vec<float,4> &v) : w(v[3]), x(v[0]), y(v[1]), z(v[2]) { }
inline sxsdk::quaternion_class::quaternion_class (float w, const sx::vec<float,3> &v) : w(w), x(v[0]), y(v[1]), z(v[2]) { }
inline sxsdk::quaternion_class::quaternion_class (const sx::vec<float,3> &euler) {
	(*this) = sxsdk::quaternion_class(cos(euler.x/2), sx::vec<float,3>(sin(-euler.x/2), 0, 0))
					* sxsdk::quaternion_class(cos(euler.y/2), sx::vec<float,3>(0, sin(-euler.y/2), 0))
					* sxsdk::quaternion_class(cos(euler.z/2), sx::vec<float,3>(0, 0, sin(-euler.z/2)));
}
static inline void setup_quaternion_by_vectors (sxsdk::quaternion_class& q, sx::vec<float,3> a, sx::vec<float,3> b) {
	normalize_self(a);
	normalize_self(b);

	sx::vec<float,3> c(product(b, a));
	const float d = -normalize_self(c);
	const float ip = float(sx::inner_product(a, b));
	if (-sx::epsilon < d || 1.0f < ip) {
		if (ip < (sx::epsilon - 1.0)) {
			const sx::vec<float,3> c(normalize(product(sx::vec<float,3>(-a.y, a.z, a.x), a)));
			q.w = 0.0;
			q.x = c.x;;
			q.y = c.y;
			q.z = c.z;
		}
		else {
			q = sxsdk::quaternion_class::identity;
		}
	}
	else {
		const sx::vec<float,3> e(c * std::sqrt(0.5f * (1.0f - ip)));
		q.w = sqrt(0.5f * (1.0f + ip));
		q.x = e.x;
		q.y = e.y;
		q.z = e.z;
	}
}
inline sxsdk::quaternion_class::quaternion_class (const sx::vec<float,3> &a, const sx::vec<float,3> &b) {
	setup_quaternion_by_vectors(*this, a, b);
}
inline sxsdk::quaternion_class::quaternion_class (sx::vec<float,3> a, sx::vec<float,3> b, const sx::vec<float,3> &axis, bool use_axis) {
	if (use_axis) {
		a = normalize(a - axis * inner_product(a, axis));
		b = normalize(b - axis * inner_product(b, axis));
		sx::vec<float,3> c(product(b, a));
		const float d = -absolute(c);
		const float ip = float(inner_product(a, b));
		if (-sx::epsilon < d || 1.0f < ip) {
			if (ip < (sx::epsilon - 1.0)) {
				w = 0.0;
				x = axis.x;
				y = axis.y;
				z = axis.z;
			}
			else {
				w = 1.0;
				x = 0.0;
				y = 0.0;
				z = 0.0;
			}
		}
		else {
			sx::vec<float,3> e(axis * std::sqrt(0.5f * (1.0f - ip)));
			if (0.0 <= inner_product(e, axis)) e *= -1.0f;
			w = sqrt(0.5f * (1.0f + ip));
			x = e.x;
			y = e.y;
			z = e.z;
		}
	}
	else {
		setup_quaternion_by_vectors(*this, a, b);
	}
}
inline sxsdk::quaternion_class::quaternion_class (const sxsdk::mat4 &t) {
	sx::vec<float,3> scale, shear, rotate, translate;
	t.unmatrix(scale, shear, rotate, translate);
	(*this) = sxsdk::quaternion_class(cos(rotate.x/2), sx::vec<float,3>(sin(-rotate.x/2), 0, 0))
					* sxsdk::quaternion_class(cos(rotate.y/2), sx::vec<float,3>(0, sin(-rotate.y/2), 0))
					* sxsdk::quaternion_class(cos(rotate.z/2), sx::vec<float,3>(0, 0, sin(-rotate.z/2)));
}
inline sxsdk::quaternion_class::quaternion_class (float w) : w(w), x(0.0), y(0.0), z(0.0) { }
inline sxsdk::quaternion_class sxsdk::quaternion_class::operator* (float w) const {
	return sxsdk::quaternion_class(this->w * w, x * w, y * w, z * w);
}
inline sxsdk::quaternion_class &sxsdk::quaternion_class::operator*= (float w) {
	*this = *this * w;
	return *this;
}
inline sxsdk::quaternion_class sxsdk::quaternion_class::operator/ (float w) const {
	return sxsdk::quaternion_class(this->w / w, x / w, y / w, z / w);
}
inline sxsdk::quaternion_class &sxsdk::quaternion_class::operator/= (float w) {
	*this = *this / w;
	return *this;
}
inline sxsdk::quaternion_class sxsdk::quaternion_class::operator+ (const sxsdk::quaternion_class &q) const {
	return sxsdk::quaternion_class(w + q.w, x + q.x, y + q.y, z + q.z);
}
inline sxsdk::quaternion_class &sxsdk::quaternion_class::operator+= (const sxsdk::quaternion_class &q) {
	*this = *this + q;
	return *this;
}
inline sxsdk::quaternion_class sxsdk::quaternion_class::operator- (const sxsdk::quaternion_class &q) const {
	return sxsdk::quaternion_class(w - q.w, x - q.x, y - q.y, z - q.z);
}
inline sxsdk::quaternion_class &sxsdk::quaternion_class::operator-= (const sxsdk::quaternion_class &q) {
	*this = *this - q; return *this;
}
inline sxsdk::quaternion_class sxsdk::quaternion_class::operator* (const sxsdk::quaternion_class &q) const {
	const sx::vec<float,3> u(x, y, z), v(q.x, q.y, q.z);
	return normalize(sxsdk::quaternion_class(w*q.w - inner_product(u, v), v*w + u*q.w + product(u,v)));
}
inline sxsdk::quaternion_class &sxsdk::quaternion_class::operator*= (const sxsdk::quaternion_class &q) {
	*this = *this * q;
	return *this;
}
inline sxsdk::quaternion_class sxsdk::quaternion_class::operator/ (const sxsdk::quaternion_class &q) const {
	return normalize(*this * q.inv());
}
inline sxsdk::quaternion_class &sxsdk::quaternion_class::operator/= (const sxsdk::quaternion_class &q) {
	*this = *this / q;
	return *this;
}
inline sxsdk::quaternion_class sxsdk::quaternion_class::operator- () const {
	return *this * -1.0;
}
inline sxsdk::quaternion_class sxsdk::quaternion_class::inv () const {
	const sx::vec<float,3> v(x, y, z);
	return sxsdk::quaternion_class(w/(w*w+inner_product(v,v)), -v/(w*w+inner_product(v,v)));
}
inline bool sxsdk::quaternion_class::operator== (const sxsdk::quaternion_class &q) const {
	return w == q.w && x == q.x && y == q.y && z == q.z;
}
inline bool sxsdk::quaternion_class::operator!= (const sxsdk::quaternion_class &q) const {
	return !(*this == q);
}
inline void sxsdk::quaternion_class::get_euler (sx::vec<float,3> &e) const {
	const sxsdk::mat4 t(*this);
	sx::vec<float,3> scale, shear, translate;
	t.unmatrix(scale, shear, e, translate);
}
inline sx::vec<float,3> sxsdk::quaternion_class::get_v () const {
	return sx::vec<float,3>(x, y, z);
}
inline sx::vec<float,3> sxsdk::quaternion_class::v () const {
	return get_v();
}
inline sx::vec<float,3> sxsdk::quaternion_class::direction (float distance) const {
	return sx::vec<float,3>(0.0, 0.0, -distance) * sxsdk::mat4(*this);
}
inline sxsdk::quaternion_class &sxsdk::quaternion_class::operator*= (const sxsdk::mat4 &t) {
	sxsdk::mat4 s = sxsdk::mat4(*this) * t;
	s[0] = sx::vec<float,4>(product(sx::vec<float,3>(s[1]), normalize(sx::vec<float,3>(s[2]))), s[0].w);
	s[1] = sx::vec<float,4>(product(sx::vec<float,3>(s[2]), normalize(sx::vec<float,3>(s[0]))), s[1].w);
	*this = sxsdk::quaternion_class(s);
	return *this;
}

inline sxsdk::box3_class &sxsdk::box3_class::operator<< (const sx::vec<float,3> &v) {
	if (empty) {
		min = max = sx::vec<float,4>(v, 0.0f);
		empty = false;
	}
	else {
		for (int i = 0; i < 3; ++i) {
			if (v[i] < min[i]) min[i] = v[i];
			if (max[i] < v[i]) max[i] = v[i];
		}
	}
	return *this;
}
inline sxsdk::box3_class &sxsdk::box3_class::operator<< (const box3_class &b) {
	if (!b.empty) {
		if (empty) {
			*this = b;
		}
		else {
			min = ::min(min, b.min);
			max = ::max(max, b.max);
		}
	}
	return *this;
}

inline static bool isnan (const sx::vec<float,2> &v) { return (sx::isnan(v.x) || sx::isnan(v.y)); }
inline static bool isnan (const sx::vec<float,3> &v) { return (sx::isnan(v.x) || sx::isnan(v.y) || sx::isnan(v.z)); }
inline static bool isnan (const sx::vec<float,4> &v) { return (sx::isnan(v.x) || sx::isnan(v.y) || sx::isnan(v.z) || sx::isnan(v.w)); }
inline static bool isnan (const sxsdk::quaternion_class &v) { return (sx::isnan(v.x) || sx::isnan(v.y) || sx::isnan(v.z) || sx::isnan(v.w)); }
//inline static bool isnan (const sxsdk::mat4 &m) { return (isnan(m.x) || isnan(m.y) || isnan(m.z) || isnan(m.w)); }

namespace sxsdk {
	class meshes_element_class {
	public:
		sx::vec<float,3> p;
		sx::vec<float,3> n;
		unsigned int i:15, j:15;
		bool interpolate:1;

		explicit meshes_element_class () : n(sx::vec<float,3>(0,0,0)), i(0), j(0) { }
		void check_invariant () const { }
	};
}
