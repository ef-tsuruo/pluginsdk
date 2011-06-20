#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_CREATOR_ID("B3B1B72C-549D-11D9-A8BA-000A95BACEB2");

	class creator_component : public sxsdk::creator_interface {
	private:
		virtual bool undoable (void *) const { return true; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_CREATOR_ID; }
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		//virtual bool accepts_sphere (void *) const { return true; }
		virtual bool accepts_disk (void *) const { return true; }
		//virtual bool accepts_rectangle (void *) const { return true; }
		//virtual bool accepts_translation (void *) const { return true; }
		//virtual bool set_sphere (const sx::vec<float,3> &center, float radius, int axis) { return true; }
		//virtual bool set_translation (const mat4 &t, const sx::vec<float,3> &p, int axis) { return true; }
		//virtual bool set_disk (const sx::vec<float,3> &center, float radius, int axis, void *) { return true; }
		//virtual bool set_rectangle (const sx::vec<float,3> &p, const sx::vec<float,3> &q, int axis, void *aux = 0) { return true; } 
		
		virtual bool create (sxsdk::scene_interface *scene, void *);
	};
	bool creator_component::create (sxsdk::scene_interface *scene, void *) {
		scene->begin_creating();
		(scene->create_disk("disk", sx::vec<float,3>(0,0,0), 500, 1)).set_extrude(sx::vec<float,3>(0,200,0));
		scene->end_creating();

		//compointer<dialog_interface>	dialog(scene->get_dialog_interface());
		//dialog->set_title("Test");
		//dialog->append_item(dialog_interface::group_begin_type, "test");
		//dialog->append_item(dialog_interface::string_type, "test1");
		//dialog->append_item(dialog_interface::bool_type, "test2");
		//dialog->append_item(dialog_interface::group_end_type, 0);
		//dialog->ask();
		return true;
	}
}

SXPLUGINNAMESPACEBEGIN(test_creator)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		creator_component *u = new creator_component;
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == creator_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "Simple Creator";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		return SIMPLE_CREATOR_ID;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
