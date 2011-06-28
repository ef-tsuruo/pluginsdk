#if SXIOS
	#include <OpenGLES/ES1/gl.h>
	#include <OpenGLES/ES1/glext.h>
	#include <OpenGLES/ES2/gl.h>
	#include <OpenGLES/ES2/glext.h>
	#include <OpenGLES/EAGL.h>
	#include <OpenGLES/EAGLDrawable.h>
	#include <QuartzCore/QuartzCore.h>
#elif SXMACOSX
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <OpenGL/glext.h>
	#include <OpenGL/OpenGL.h>
	#include <OpenGL/CGLRenderers.h>
#elif SXWINDOWS
	#define GL_GLEXT_PROTOTYPES 1
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glext.h>
	#include <GL/wglext.h>
#elif SXDARWIN
	#include <gl.h>
#else						
	#include <GL/gl.h>
#endif

#if GL_VERSION_ES_CM_1_0
	#define SXOPENGLSE 1
#else
	#define SXOPENGLSE 0
#endif

#ifndef GL_FRAMEBUFFER
	#define GL_FRAMEBUFFER GL_FRAMEBUFFER_EXT
#endif
#ifndef GL_FRAMEBUFFER_COMPLETE
	#define GL_FRAMEBUFFER_COMPLETE GL_FRAMEBUFFER_COMPLETE_EXT
#endif
#ifndef GL_RENDERBUFFER
	#define GL_RENDERBUFFER GL_RENDERBUFFER_EXT
#endif
#ifndef GL_COLOR_ATTACHMENT0
	#define GL_COLOR_ATTACHMENT0 GL_COLOR_ATTACHMENT0_EXT
#endif
#ifndef GL_COLOR_ATTACHMENT1
	#define GL_COLOR_ATTACHMENT1 GL_COLOR_ATTACHMENT1_EXT
#endif
#ifndef GL_DEPTH_ATTACHMENT
	#define GL_DEPTH_ATTACHMENT GL_DEPTH_ATTACHMENT_EXT
#endif
#ifndef GL_READ_FRAMEBUFFER
	#define GL_READ_FRAMEBUFFER GL_READ_FRAMEBUFFER_EXT
#endif
#ifndef GL_DRAW_FRAMEBUFFER
	#define GL_DRAW_FRAMEBUFFER GL_DRAW_FRAMEBUFFER_EXT
#endif
#ifndef GL_DRAW_FRAMEBUFFER_BINDING
	#define GL_DRAW_FRAMEBUFFER_BINDING GL_DRAW_FRAMEBUFFER_BINDING_EXT
#endif
#ifndef GL_DRAW_FRAMEBUFFER_BINDING
	#define GL_DRAW_FRAMEBUFFER_BINDING GL_DRAW_FRAMEBUFFER_BINDING_EXT
#endif
