#include "sxsdk.cxx"
#include "sx/gl/opengl.hpp"

namespace {
	const sx::uuid_class OPENGL_RENDERER_ID("B20C39CA-549E-11D9-8E2C-000A95BACEB2");
	const sx::uuid_class TEXTURE_RENDERER_ID("C40F7859-A14F-11D9-B9A8-000A95BACEB2");

	class opengl_renderer : public sxsdk::renderer_interface {
	private:
		void render (sxsdk::image_interface &image, const sxsdk::mat4 &world_to_perspective, sxsdk::rendering_context_interface &rc);
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return OPENGL_RENDERER_ID; }
		virtual bool uses_over_sampling (void *) { return true; }
		virtual bool can_accept_texture (void *) { return true; }
		virtual bool can_ask (void *) { return true; } 
		virtual void ask ( sxsdk::stream_interface *stream, void *);
		virtual void begin_rendering (::sxsdk::rendering_context_interface *rendering_context, ::sxsdk::stream_interface *stream, void *);
		virtual void render (void *);
		virtual void set_transformation (const sxsdk::mat4 &t, void *);
		virtual void clear_transformation (void *);
		virtual bool can_accept_polygon (void *);
		virtual void do_polygon (int n, sxsdk::points_interface **c, void *);
		virtual void do_meshes (sxsdk::meshes_interface *m_, void *);
		virtual bool can_accept_polymesh (void *);
		virtual void begin_polymesh (void *);
		virtual void begin_polymesh_vertex (int n, void *);
		virtual void polymesh_vertex (int i, const sx::vec<float,3> &v, void *);
		virtual void end_polymesh_vertex (void *);
		virtual void begin_polymesh_face (int n, void *);
		virtual void polymesh_face (int n, const int list[], const sx::vec<float,3> *normals, const sx::vec<float,4> *plane_equation, void *);
		virtual void end_polymesh_face (void *);
		virtual void end_polymesh (void *);
		virtual void begin (void *);
		virtual void end (void *);
		virtual bool accepts_walkthrough (void *);
		virtual void walkthrough (sxsdk::scene_interface *scene, sxsdk::camera_interface *camera, sxsdk::image_interface *image, sxsdk::rendering_context_interface *rc, sxsdk::stream_interface *stream, void *);
	private:
		sxsdk::rendering_context_interface *rendering_context;
		GLuint tex_name;
		sxsdk::mat4 t;
		std::vector<sx::vec<float,3> > vertices;
	};
}
void opengl_renderer::ask ( sxsdk::stream_interface *stream, void *) {
	//::SysBeep(0);
} 
void opengl_renderer::render (sxsdk::image_interface &image, const sxsdk::mat4 &world_to_perspective, sxsdk::rendering_context_interface &rc) {
	//rc.convert(this); return;
//	t = sxsdk::mat4::identity;
//	image.begin_opengl();
//	glViewport(0, 0, image.get_size().x, image.get_size().y);
//	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glFlush();
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	
//	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, -1.0f);
//	glMultMatrixf((GLfloat *)(&world_to_perspective));
//
//	GLfloat light_direction[4] = { 0.7f, 0.7f, 0.2f, 0.0f };
//	{	int n = rc.get_number_of_lights();
//		if (0 < n) {
//			sxsdk::rendering_light_class &light = rc.get_light(0);
//			if (light.is_distant_light()) {
//				const sx::vec<float,4> d = light.get_position();
//				light_direction[0] = d[0];
//				light_direction[1] = d[1];
//				light_direction[2] = d[2];
//			}
//		}
//	}
//	glLightfv(GL_LIGHT0, GL_POSITION, light_direction);
//	glEnable(GL_LIGHT0);
//	glDepthFunc(GL_LEQUAL);
//	glEnable(GL_DEPTH_TEST);
//	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_NORMALIZE);
//	glShadeModel(GL_FLAT);
//	glEnable(GL_CULL_FACE);
//	
//	glEnable(GL_TEXTURE_2D);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	
//	rc.convert(this);
//
//	image.end_opengl();
	//image.begin_opengl();
	//for (int i = 0; i < 1000; i++) {
	//	sx::thread::sleep(10);
	//	image.end_opengl();
		//::Sleep(0);
	//	rc.yield();
	//	image.begin_opengl();
	//}
	//image.end_opengl();
}
void opengl_renderer::begin_rendering (::sxsdk::rendering_context_interface *rendering_context, ::sxsdk::stream_interface *stream, void *) {
	this->rendering_context = rendering_context;
}
void opengl_renderer::render (void *) {
	sxassert(rendering_context);
	sxsdk::rendering_context_interface &rc = *rendering_context;
	
	compointer<sxsdk::image_interface> image(rc.get_image_interface());
	render(*image, rc.get_world_to_perspective_matrix(), rc);
}

//  \ja エクスポートプラグインと同じ要領で、can_accept_polygon、do_polygon、do_meshesなどをオーバライドする。 \endja 
//  \ja sxsdk::rendering_context_interface::convert()を呼ぶと、レンダリングの対象となる形状が、必要に応じてポリゴン分割されて、オーバライドされたdo_XXX関数を介してわたされる。 \endja 
void opengl_renderer::set_transformation (const sxsdk::mat4 &t, void *) {
	this->t = t;
}
void opengl_renderer::clear_transformation (void *) {
	t = sxsdk::mat4::identity;
}
bool opengl_renderer::can_accept_polygon (void *) {
	return true;
}
void opengl_renderer::do_polygon (int n, sxsdk::points_interface **c, void *) {
	//{	compointer<sxsdk::image_interface> image(rendering_context->get_image_interface());
	//	for (int y = 0; y < 100; y++) for (int x = 0; x < 100; x++) {
	//		compointer<sxsdk::texture_interface> t(rendering_context->get_current_shape().create_texture_interface(0, sx::vec<float,3>(0,0,0), sx::vec<float,3>(0,0,0), sx::vec<float,3>(0,0,0), sx::vec<float,3>(0,0,0), &sx::vec<float,2>(x*0.01, y*0.01), 0, 0));
	//		image->set_pixel(x, y, t->calculate_diffuse_color());
	//	}
	//}
	//return;
	const bool flip = rendering_context->get_flip_face() ^ rendering_context->get_flip_face_shade();
	const int k = c[0]->get_n();
	if (0 < k) {
		std::vector<sx::vec<float,3> > p(k);
		for (int i = 0; i < k; i++) p[i] = (*(c[0]))[k-i-1] * (sxsdk::mat4 &)t; //  \ja ポリゴンの頂点座標値を配列に格納する。 \endja 
		sx::vec<float,4> eq;
		rendering_context->plane_equation(k, &(p[0]), eq); //  \ja ポリゴンの法線ベクトルを求める。 \endja 
		if (flip) eq = -eq;

//		glBegin(GL_POLYGON);
//		glNormal((const sx::vec<float,3> &)(eq));
//		if (flip) {
//			for (int i = 0; i < k; i++) glVertex(p[k-i-1]);
//		}
//		else {
//			for (int i = 0; i < k; i++) glVertex(p[i]);
//		}
//		glEnd();
	}
}
void opengl_renderer::do_meshes (sxsdk::meshes_interface *m_, void *) {
	compointer<sxsdk::image_interface> texture(m_->get_texture_image_interface());
	std::vector<sx::rgba<sx::unsigned8,sx::RGBA> > image;
	if (texture) {
		const sx::vec<int,2> size = texture->get_size();
		const int n = size.x * size.y;
		if (0 < n) {
			image.resize(n);
			texture->get_pixels_rgba(0, 0, size.x, size.y, &(image[0]));
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(image[0]));
		}
	}
	const bool flip = rendering_context->get_flip_face() ^ rendering_context->get_flip_face_shade();
//	glBegin(GL_QUADS);
//	sxsdk::meshes_interface &mesh = *m_;
//	for (int i = 0; i < mesh.get_m_number(); i++) for (int j = 0; j < mesh.get_n_number(); j++) {
//		if (mesh.is_submesh(i, j)) {
//			sxsdk::meshes_interface::submesh_class submesh(mesh, i, j);
//			for (int i = 0; i < submesh.m-1; i++) for (int j = 0; j < submesh.n-1; j++) {
//				std::array<sx::vec<float,3>, 4> p;
//				p[0] = submesh(i,   j  ).p;
//				p[1] = submesh(i,   j+1).p;
//				p[2] = submesh(i+1, j+1).p;
//				p[3] = submesh(i+1, j  ).p;
//				sx::vec<float,4> eq;
//				try { rendering_context->plane_equation(4, &p[0], eq); } catch (...) { continue; }//  \ja 法線ベクトルを求める。 \endja 
//				if (flip) eq = -eq;
//				sx::vec<float,2> uv;
//				glNormal3fv(&eq.x);
//				
//				if (flip) {
//					uv = submesh.get_uv(i+1, j);
//					glTexCoord(uv);
//					glVertex(p[3]);
//
//					uv = submesh.get_uv(i+1, j+1);
//					glTexCoord(uv);
//					glVertex(p[2]);
//
//					uv = submesh.get_uv(i, j+1);
//					glTexCoord(uv);
//					glVertex(p[1]);
//
//					uv = submesh.get_uv(i, j);
//					glTexCoord(uv);
//					glVertex(p[0]);
//				}
//				else {
//					uv = submesh.get_uv(i, j);
//					glTexCoord(uv);
//					glVertex(p[0]);
//					
//					uv = submesh.get_uv(i, j+1);
//					glTexCoord(uv);
//					glVertex(p[1]);
//					
//					uv = submesh.get_uv(i+1, j+1);
//					glTexCoord(uv);
//					glVertex(p[2]);
//		
//					uv = submesh.get_uv(i+1, j);
//					glTexCoord(uv);
//					glVertex(p[3]);
//				}
//			}
//		}
//	}
//	glEnd();
}
bool opengl_renderer::can_accept_polymesh (void *) {
	return true;
}
void opengl_renderer::begin_polymesh (void *) {
	vertices.clear();
}
void opengl_renderer::begin_polymesh_vertex (int n, void *) {
	vertices.resize(n);
}
void opengl_renderer::polymesh_vertex (int i, const sx::vec<float,3> &v, void *) {
	vertices[i] = v;
}
void opengl_renderer::end_polymesh_vertex (void *) {
}
void opengl_renderer::begin_polymesh_face (int n, void *) {
}
void opengl_renderer::polymesh_face (int n, const int list[], const sx::vec<float,3> *normals, const sx::vec<float,4> *plane_equation, void *) {
	const bool flip = rendering_context->get_flip_face() ^ rendering_context->get_flip_face_shade();
//	glBegin(GL_POLYGON);
//	if (flip) {
//		for (int i = n-1; 0 <= i; --i) {
//			if (normals) { sx::vec<float,3> n(-normals[i]); glNormal(n); }
//			glVertex(vertices[list[i]]);
//		}
//	}
//	else {
//		for (int i = 0; i < n; ++i) {
//			if (normals) glNormal(normals[i]);
//			glVertex(vertices[list[i]]);
//		}
//	}
//	glEnd();
}
void opengl_renderer::end_polymesh_face (void *) {
}
void opengl_renderer::end_polymesh (void *) {
	vertices.clear();
}
void opengl_renderer::begin (void *) {
//	rendering_context->yield();
//	rendering_context->update_image();
//	glPushMatrix();
//	glMultMatrixf(&(rendering_context->get_current_shape().get_transformation())[0][0]); //  \ja 変換マトリクスを設定する。 \endja 
}
void opengl_renderer::end (void *) {
//	glPopMatrix(); //  \ja 変換マトリクスを元に戻す。 \endja 
}

//  \ja accepts_walkthroughがtrueを返すと、視野が変わった時にwalkthroughが呼ばれる。 \endja 
//  \ja 実際にレンダリング中ではないので、walkthroughの引数のsxsdk::rendering_context_interfaceは一部機能しないことに要注意。 \endja 
bool opengl_renderer::accepts_walkthrough (void *) { return false; }
void opengl_renderer::walkthrough (sxsdk::scene_interface *scene, sxsdk::camera_interface *camera, sxsdk::image_interface *image, sxsdk::rendering_context_interface *rc, sxsdk::stream_interface *stream, void *) {
	rendering_context = rc;
	render(*image, camera->get_world_to_perspective_matrix(0), *rc);
}

//  \en This renderer renders a X-Z plane using surface attributes assigned to the root shape object. \enden  \ja ルート形状に設定された表面材質を使って、X-Z平面をレンダリングする例。 \endja 
//  \en Shade calculates the surface texture via sxsdk::texture_interface so that a plugin does not have to implement it. \enden  \ja 表面材質の計算はsxsdk::texture_interfaceを介してShade本体が行うので、プラグインで独自に実装する必要はない。 \endja 
class texture_renderer : public sxsdk::renderer_interface {
private:
	sxsdk::rendering_context_interface *rendering_context;

	virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
	virtual sx::uuid_class get_uuid (void *) { return TEXTURE_RENDERER_ID; }
	virtual void begin_rendering (::sxsdk::rendering_context_interface *rendering_context, ::sxsdk::stream_interface *stream, void *);
	virtual void render (void *);
};
void texture_renderer::begin_rendering (::sxsdk::rendering_context_interface *rendering_context, ::sxsdk::stream_interface *stream, void *) {
	this->rendering_context = rendering_context;
}
void texture_renderer::render (void *) {
	sxsdk::rendering_context_interface &rc = *rendering_context;
	compointer<sxsdk::image_interface> imagep(rc.get_image_interface());
	sxsdk::image_interface &image = *imagep;
	rc.convert(this); //  \en We do not use any call-backs from convert() function, but call it anyway because we need proxy shapes that convert() creates. \enden  \ja ここではconvertのコールバック関数は何も利用しないが、convert()を呼ぶことによってproxy形状が生成される。 \endja 
	sxsdk::texture_interface &t = rc.get_root_proxy_shape().texture(); //  \en Aquire a reference to the sxsdk::texture_interface for the root proxy shape. \enden  \ja ルートのproxy形状からsxsdk::texture_interfaceの参照を取得する。 \endja 
	const sx::bounds<sx::vec<int,2> > bounds = image.get_bounds();
	for (int y = bounds.min.y; y < bounds.max.y; ++y) {
		for (int x = bounds.min.x; x < bounds.max.x; ++x) {
			sx::vec<float,3> eye, direction; rc.get_sight(eye, direction, x, y);
			if (direction.y < 0.0f) {
				const float d = -(eye.y / direction.y);
				const sx::vec<float,3> p(direction.x*d, 0.0f, direction.z*d); //  \en A point on the X-Z plane. \enden  \ja X-Z平面状の点を求める。 \endja 
				image.set_pixel(x, y, t.set_position(p).update().get_diffuse());
			}
		}
	}
}

SXPLUGINNAMESPACEBEGIN(test_renderer)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		sxsdk::renderer_interface *u = 0;
		switch (i) {
		case 0:	u = new opengl_renderer; break;
		case 1:	u = new texture_renderer; break;
		}
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == renderer_iid) return 2;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *p) {
		switch (i) {
		case 0:	return "Simple OpenGL";
		case 1:	return "Simple Texture";
		}
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		switch (i) {
		case 0:	return OPENGL_RENDERER_ID;
		case 1:	return TEXTURE_RENDERER_ID;
		}
		return sx::uuid_class();
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
