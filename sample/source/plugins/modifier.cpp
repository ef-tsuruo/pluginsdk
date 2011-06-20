#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_MODIFIER_ID("6B560178-549E-11D9-A8A6-000A95BACEB2");

	class modifier_component : public sxsdk::modifier_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_MODIFIER_ID; }
		virtual bool undoable (void *) const { return true; }
		virtual bool accepts_sphere (void *) const { return true; }
		virtual bool modify (sxsdk::scene_interface *scene, void *);
	};
}
bool modifier_component::modify (sxsdk::scene_interface *scene, void *) {
	try {
		scene->message("simple modifier...");
		/*
		scene->reset_undo();
		{	polygon_mesh_class &p(polygon_mesh_class::cast(scene->active_shape(0)));
			compointer<shape_saver_interface> ps(p.create_shape_saver_interface());
			p.set_point(0, sx::vec<float,3>(0,0,0));
			ps->set_undo_action();
			ps->release();
		}
		{	polygon_mesh_class &p(polygon_mesh_class::cast(scene->active_shape(1)));
			compointer<shape_saver_interface> ps(p.create_shape_saver_interface());
			p.set_point(0, sx::vec<float,3>(0,0,0));
			ps->set_undo_action();
			ps->release();
		}
		*/
		/*
		scene->save_control_points(1, &(&s), false, true);
		s.set_point(0, sx::vec<float,3>(0,0,0));
		scene->undo_modify_control_points(1, &(&s), false, true);
		scene->clear_saved_control_points();
		*/
	} catch (...) { return false; }
	return true;
}

SXPLUGINNAMESPACEBEGIN(test_modifier)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		modifier_component *u = new modifier_component;
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == modifier_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "simple_modifier";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		return SIMPLE_MODIFIER_ID;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
