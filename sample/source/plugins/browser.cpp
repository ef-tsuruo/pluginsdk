#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_BROWSER_ID("9C743D1C-549D-11D9-9B65-000A95BACEB2");

	class browser_component : public sxsdk::browser_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_BROWSER_ID; }
		virtual bool do_browser (sxsdk::scene_interface *scene, void *);
	};
}
bool browser_component::do_browser (sxsdk::scene_interface *scene, void *) {
	scene->message("simple_browser called");
	return true;
}

SXPLUGINNAMESPACEBEGIN(test_browser)
	SXPLUGINENTRY void __stdcall create_interface (const IID &, int, void **p, sxsdk::shade_interface *, void *) {
		browser_component *u = new browser_component;
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *) {
		if (iid == browser_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &, int, sxsdk::shade_interface *, void *) {
		return "Simple Browser";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &, int, void *) {
		return SIMPLE_BROWSER_ID;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
