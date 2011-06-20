#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_PLUGIN_ID("9255A624-549E-11D9-8D8E-000A95BACEB2");

	class simple_plugin_interface : public sxsdk::plugin_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_PLUGIN_ID; }
		virtual void do_it (sxsdk::shade_interface *shade, sxsdk::scene_interface *scene, void *);
	};
}
void simple_plugin_interface::do_it (sxsdk::shade_interface *shade, sxsdk::scene_interface *scene, void *) {
	std::cerr << "simple_plugin_interface::do_it\n";
	//shape_class &shape = scene->active_shape();
	//std::cout << shape.get_part().get_transformation_matrix() << std::endl;
	/*
	shade->message("ABC"); return;
	shade->beep();
	compointer<image_interface> image(shade->get_new_image_interface(sx::vec<int,2>(300, 300)));
	shape_class &shape = scene->active_shape();
	compointer<texture_interface> texture(shape.create_texture_interface(0, sx::vec<float,3>(0,0,0), sx::vec<float,3>(0,1,0), sx::vec<float,3>(0,1,0), sx::vec<float,3>(0,0,-1), 0, 0, 0));
	for (int x = 0; x < 300; ++x) {
		for (int y = 0; y < 300; ++y) {
			texture->set_position(sx::vec<float,3>(x*5.0,y*5.0,0));
			image->set_pixel(x, y, texture->get_diffuse_color());
		}
	}
	image->create_window_interface("texture");
	*/
}

SXPLUGINNAMESPACEBEGIN(test_plugin)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		unknown_interface *u = new simple_plugin_interface;
		u->AddRef();
		*p = (void *)u;
	}
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == plugin_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		if (iid == plugin_iid) return "simple_plugin";
		return 0;
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		if (iid == plugin_iid) return SIMPLE_PLUGIN_ID;
		return sx::uuid_class(0u);
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		if (iid == creator_iid)			return "multicreator";
		else if (iid == importer_iid)	return "multiimporter";
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
