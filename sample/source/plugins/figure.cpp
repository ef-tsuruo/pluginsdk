#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_FIGURE_ID("01840366-549E-11D9-AEB3-000A95BACEB2");

	class figure_component : public sxsdk::figure_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_FIGURE_ID; }
		virtual bool do_figure (sxsdk::scene_interface *scene, void *);
	};
}
bool figure_component::do_figure (sxsdk::scene_interface *scene, void *) {
	scene->message("simple_fugure called");
	return true;
}

SXPLUGINNAMESPACEBEGIN(test_figure)
	SXPLUGINENTRY  void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		figure_component *u = new figure_component;
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY  int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == figure_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY  const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "Simple Figure";
	}
	SXPLUGINENTRY  sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		return SIMPLE_FIGURE_ID;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
