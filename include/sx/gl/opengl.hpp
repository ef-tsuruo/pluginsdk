#pragma once
#include "sx/opengl.h"
#include "sx/core/setting.hpp"
#include "sx/core/bounds.hpp"
#include "sx/core/cocoa.hpp"
#include "sx/core/vectors.hpp"
#include "sx/core/pixel.hpp"

#define glDrawRangeElements 0
#define glPushMatrix 0
#define glPopMatrix 0
#define glMultMatrix 0
#define glLoadIdentity 0
#define glOrtho 0
#define glMatrixMode 0
#define glLoadMatrix 0
#define glTranslate 0
#define glRotate 0
#define glScale 0
#define glDrawElements 0
#define glDrawArrays 0
#define glEnableClientState 0
#define glDisableClientState 0
#define glVertexPointer 0
#define glInterleavedArrays 0
//#define glBegin 0
//#define glEnd 0
//#define glPointSize 0
//#define glMultTransposeMatrixf 0
//#define glClearColor 0
//#define glClear 0
#define glLineWidth 0 // use sx::gl::linewidth
//#define glRasterPos 0
//#define glRect 0
//#define glDeleteTextures

// OpenGL => OpenGL ES
//glLightModeli => glLightModelf
//glTexCoord2f => Using texture coord arrays.
//glBegin => glEnableClientState
//glGenLists => No replacement yet.
//glEnd => glDisableClientState
//glPolygonMode => No replacement yet.
//glVertex3f => Using vertex arrays.
//glCallList => No replacement yet.
//glGetTexLevelParameteriv => No replacement yet.
//glTexGeni => No replacement yet.
//glColor4fv => Using color arrays.
//glEndList => No replacement yet.
//glOrtho => glOrthof
//glFogi => glFogf
//glTexGenfv => No replacement yet.
//glNewList => No replacement yet.
//glGetDoublev => glGetFloatv

namespace sx {
	namespace gl {
		class context_class;
		
		void check_blacklist (sx::gl::context_class &context);

		// default and supposedly most efficient pixel format and pixel type
		#if SXIOS // bandaid
			static const int PIXEL_FORMAT =				GL_BGRA;
			static const int PIXEL_TYPE =				GL_UNSIGNED_BYTE;
		#elif SXMACOSX
			static const int PIXEL_FORMAT =				GL_BGRA;
			static const int NSBITMAP_PIXEL_FORMAT =	GL_RGBA;
			static const int PIXEL_TYPE =			GL_UNSIGNED_INT_8_8_8_8;
			static const int NSBITMAP_PIXEL_TYPE =	GL_UNSIGNED_INT_8_8_8_8_REV;
		#elif SXWINDOWS
			static const int PIXEL_FORMAT =				GL_BGRA;
			static const int PIXEL_TYPE =				GL_UNSIGNED_BYTE;
		#endif

		template<unsigned FORMAT=PIXEL_FORMAT, unsigned TYPE=PIXEL_TYPE> class pixel;
		#if defined(GL_BGRA) && defined(GL_UNSIGNED_BYTE)
			template<> class pixel<GL_BGRA,GL_UNSIGNED_BYTE> {
			public:
				typedef sx::rgba<sx::unsigned8,BGRA> type;
			};
		#endif
		#if defined(GL_BGRA) && defined(GL_UNSIGNED_INT_8_8_8_8)
			template<> class pixel<GL_BGRA,GL_UNSIGNED_INT_8_8_8_8> {
			public:
				typedef sx::rgba<sx::unsigned8,ARGB> type;
			};
		#endif
		#if defined(GL_BGRA) && defined(GL_UNSIGNED_INT_8_8_8_8_REV)
			template<> class pixel<GL_BGRA,GL_UNSIGNED_INT_8_8_8_8_REV> {
			public:
				typedef sx::rgba<sx::unsigned8,BGRA> type;
			};
		#endif

		template<typename T> class pixelformat;
		template<> class pixelformat<sx::rgba<sx::unsigned8,ARGB> > {
		public:
			static const GLenum id = GL_BGRA;
		};
		template<> class pixelformat<sx::rgba<sx::unsigned8,BGRA> > {
		public:
			static const GLenum id = GL_BGRA;
		};

		template<typename T> class pixeltype;
		template<> class pixeltype<sx::rgba<sx::unsigned8,ARGB> > {
		public:
			static const GLenum id = GL_UNSIGNED_INT_8_8_8_8_REV;
		};
		template<> class pixeltype<sx::rgba<sx::unsigned8,BGRA> > {
		public:
			#if SXMACOSX
				static const GLenum id = GL_UNSIGNED_INT_8_8_8_8;
			#else
				static const GLenum id = GL_UNSIGNED_BYTE;
			#endif
		};

		template<typename T> class type;
		template<> class type<GLubyte> {
		public:
			static const GLenum id = GL_UNSIGNED_BYTE;
		};
		template<> class type<GLbyte> {
		public:
			static const GLenum id = GL_BYTE;
		};
		template<> class type<GLushort> {
		public:
			static const GLenum id = GL_UNSIGNED_SHORT;
		};
		template<> class type<GLshort> {
		public:
			static const GLenum id = GL_SHORT;
		};
		template<> class type<GLuint> {
		public:
			static const GLenum id = GL_UNSIGNED_INT;
		};
		template<> class type<GLint> {
		public:
			static const GLenum id = GL_INT;
		};
		template<> class type<GLfloat> {
		public:
			static const GLenum id = GL_FLOAT;
		};
		#if GL_VERSION_1_1
			template<> class type<GLdouble> {
			public:
				static const GLenum id = GL_DOUBLE;
			};
		#endif
		template<unsigned T> class gltype;
		template<> class gltype<GL_UNSIGNED_BYTE> {
		public:
			typedef GLubyte type;
		};
		template<> class gltype<GL_BYTE> {
		public:
			typedef GLbyte type;
		};
		template<> class gltype<GL_UNSIGNED_SHORT> {
		public:
			typedef GLushort type;
		};
		template<> class gltype<GL_SHORT> {
		public:
			typedef GLshort type;
		};
		template<> class gltype<GL_UNSIGNED_INT> {
		public:
			typedef GLuint type;
		};
		template<> class gltype<GL_INT> {
		public:
			typedef GLint type;
		};
		template<> class gltype<GL_FLOAT> {
		public:
			typedef GLfloat type;
		};
		#if GL_VERSION_1_1
			template<> class gltype<GL_DOUBLE> {
			public:
				typedef GLdouble type;
			};
		#endif
		
		#if SXOPENGLES
			typedef GLushort	index_type;
		#else
			typedef GLuint		index_type;
		#endif
		
		void setup2d (sx::gl::context_class &context, const sx::bounds<sx::vec<int,2> > &bounds);
	}
}

#if SXOPENGLES
	#define GL_QUADS 0
	#define GL_READ_ONLY_ARB 0
	#define GL_READ_WRITE_ARB 0
	#define GL_POLYGON 0
	#define GL_V3F 1
	#define GL_T2F_N3F_V3F 2
	#define GL_POLYGON_OFFSET_LINE 0
	#define GL_POLYGON_OFFSET_POINT 0
	#define GL_POLYGON_SMOOTH 0
#endif

inline GLint glGetInteger (GLenum i) {
	GLint j; glGetIntegerv(i, &j);
	return j;
}
inline void glGetFloat (long i, sx::vec<float,4> &t) {
	::glGetFloatv(i, (float *)&t);
}
inline void glGetFloat (long i, sx::mat<float,4> &t) {
	::glGetFloatv(i, (float *)&t);
}
inline void glLight (long i, long j, const sx::rgb<float> &v) {
	const sx::rgba<float> p(v, 1.0f);
	glLightfv(i, j, (float *)&p);
}
inline void glLight (long i, long j, const sx::rgba<float> &v) {
	glLightfv(i, j, (float *)&v);
}
inline void glLight (long i, long j, const sx::vec<float,3> &v) {
	const sx::vec<float,4> p(v, 1.0f);
	glLightfv(i, j, (float *)&p);
}
inline void glLight (long i, long j, const sx::vec<float,4> &v) {
	glLightfv(i, j, (float *)&v);
}
inline void glLight (long i, long j, float f) {
	glLightf(i, j, f);
}
inline void glClearColor (const sx::rgb<float> &c) {
	glClearColor(c.red, c.green, c.blue, 1.0f);
}
inline void glClearColor (const sx::rgba<float> &c) {
	glClearColor(c.red, c.green, c.blue, c.alpha);
}
#if !SXOPENGLES
	inline void glLightModel (GLenum n, int i) {
		glLightModeli(n, i);
	}
#endif
inline void glLightModel (GLenum n, float f) {
	glLightModelf(n, f);
}
inline void glColor (unsigned i) {
	#if SXOPENGLES
		glColor4f(((i&0x00ff0000) >> 16) * (1/255.0f), ((i&0x0000ff00) >> 8) * (1/255.0f), ((i&0x000000ff)) * (1/255.0f), 1.0f);
	#else
		glColor3ub((i&0x00ff0000) >> 16, (i&0x0000ff00) >> 8, (i&0x000000ff));
	#endif
}
inline void glColor4 (unsigned i) {
	#if SXOPENGLES
		glColor4f(((i&0x00ff0000) >> 16) * (1/255.0f), ((i&0x0000ff00) >> 8) * (1/255.0f), ((i&0x000000ff)) * (1/255.0f), ((i&0xff000000) >> 24) * (1/255.0f));
	#else
		glColor4ub((i&0x00ff0000) >> 16, (i&0x0000ff00) >> 8, (i&0x000000ff), (i&0xff000000) >> 24);
	#endif
}
inline void glColor (const sx::rgb<float> &v) {
	#if SXOPENGLES
		glColor4f(v.red, v.green, v.blue, 1.0f);
	#else
		glColor3fv((float *)&v);
	#endif
}
inline void glColor (const sx::rgba<float> &v) {
	#if SXOPENGLES
		glColor4f(v.red, v.green, v.blue, v.alpha);
	#else
		glColor4fv((float *)&v);
	#endif
}
inline void glNormal (float x, float y, float z) {
	glNormal3f(x, y, z);
}
inline void glNormal (const sx::vec<float,3> &v) {
	#if SXOPENGLES
		glNormal3f(v.x, v.y, v.z);
	#else
		glNormal3fv((float *)&v);
	#endif
}
inline void glVertex (float x, float y) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex2f(x, y);
	#endif
}
inline void glVertex (float x, float y, float z) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex3f(x, y, z);
	#endif
}
inline void glVertex (float x, float y, float z, float w) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex4f(x, y, z, w);
	#endif
}
inline void glVertex (const sx::vec<int,2> &p) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex2i(p.x, p.y);
	#endif
}
inline void glVertex (const sx::vec<float,2> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex2fv((float *)&v);
	#endif
}
inline void glVertex (const sx::vec<float,3> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex3fv((float *)&v);
	#endif
}
inline void glVertex (const sx::vec<float,4> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex4fv((float *)&v);
	#endif
}
inline void glVertex (const sx::vec<double,2> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex2dv((double *)&v);
	#endif
}
inline void glVertex (const sx::vec<double,3> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex3dv((double *)&v);
	#endif
}
inline void glVertex (const sx::vec<double,4> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glVertex4dv((double *)&v);
	#endif
}
inline void glRasterPos (float x, float y) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRasterPos2f(x, y);
	#endif
}
inline void glRasterPos (float x, float y, float z) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRasterPos3f(x, y, z);
	#endif
}
inline void glRasterPos (float x, float y, float z, float w) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRasterPos4f(x, y, z, w);
	#endif
}
inline void glRasterPos (const sx::vec<float,2> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRasterPos2fv((float *)&v);
	#endif
}
inline void glRasterPos (const sx::vec<float,3> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRasterPos3fv((float *)&v);
	#endif
}
inline void glRasterPos (const sx::vec<float,4> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRasterPos4fv((float *)&v);
	#endif
}
inline void glRect (float x0, float y0, float x1, float y1) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRectf(x0, y0, x1, y1);
	#endif
}
inline void glRect (const sx::bounds<sx::vec<int,2> > &r) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glRecti(r.min.x, r.min.y, r.max.x, r.max.y);
	#endif
}
inline void glTexCoord (float u, float v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glTexCoord2f(u, v);
	#endif
}
inline void glTexCoord (const sx::vec<float,2> &v) {
	#if SXOPENGLES
		SXUNIMPLEMENTED
	#else
		glTexCoord2fv((float *)&v);
	#endif
}
inline void glMaterial (GLenum face, GLenum pname, const sx::rgba<float> &v) {
	const float c[4] = { v.red, v.green, v.blue, v.alpha };
	glMaterialfv(face, pname, c);
}
inline void glMaterial (GLenum face, GLenum pname, float f) {
	glMaterialf(face, pname, f);
}
//inline void glVertexPointer (const sx::vector<sx::vec<float,2> > &v) {
//	glVertexPointer(2, GL_FLOAT, 0, sx::get(v));
//}
//inline void glVertexPointer (const sx::vector<sx::vec<float,3> > &v) {
//	glVertexPointer(3, GL_FLOAT, 0, sx::get(v));
//}

namespace sx {
	namespace gl {

		class enable {
		public:
			explicit enable (GLenum cap, bool doit = true);
			~enable ();
		private:
			bool doit;
			const GLenum cap;
		};

		class disable {
		public:
			explicit disable (GLenum cap, bool doit = true);
			~disable ();
		private:
			const bool doit;
			const GLenum cap;
		};

		class attrib_class {
		public:
			explicit attrib_class (GLbitfield mask);
			~attrib_class ();
		};

		class client_attrib_class {
		public:
			explicit client_attrib_class (GLbitfield mask);
			~client_attrib_class ();
		};

		class color_mask_class {
		public:
			color_mask_class ();
			explicit color_mask_class (bool m, bool doit = true);
			explicit color_mask_class (bool rm, bool gm, bool bm, bool am, bool doit = true);
			~color_mask_class ();
		private:
			GLboolean masks[4];
			const bool doit;
		};

		class depth_mask_class {
		public:
			depth_mask_class ();
			explicit depth_mask_class (bool m, bool do_it = true);
			~depth_mask_class ();
		private:
			GLboolean mask;
			const bool do_it;
		};

		class depth_func_class {
		public:
			explicit depth_func_class (GLenum func, bool do_it = true);
			~depth_func_class ();
		private:
			const sx::gl::enable depth_test;
			const bool do_it;
		};

		//class bind_framebuffer_class {
		//public:
		//	explicit bind_framebuffer_class (GLenum target, GLuint i);
		//	~bind_framebuffer_class ();
		//private:
		//	const GLenum target;
		//};

		class bind_texture_class {
		public:
			explicit bind_texture_class (GLenum target, GLuint i);
			~bind_texture_class ();
		private:
			const GLuint texname;
			const GLenum target;
		};

		//class bind_renderbuffer_class {
		//public:
		//	explicit bind_renderbuffer_class (GLenum target, GLuint i);
		//	~bind_renderbuffer_class ();
		//private:
		//	const GLenum target;
		//};

	}
}
