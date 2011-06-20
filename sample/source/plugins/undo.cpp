#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_UNDO_ID("D351956D-549F-11D9-8D5E-000A95BACEB2");
}

namespace {
//  \en simple_undo shows you how to use sxsdk::shape_saver_interface to implement undo functionality. \enden  \ja simple_undoは sxsdk::shape_saver_interfaceを使ってアンドゥ機能を実装する例 \endja 
class simple_undo : public sxsdk::modifier_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void * = 0) { return SIMPLE_UNDO_ID; }
		virtual bool undoable (void * = 0) const { return true; } //  \en A plugin that support undo must return true. \enden  \ja アンドゥをサポートするプラグインは、trueを返す。 \endja 

		virtual bool modify (sxsdk::scene_interface *scene, void *); 
	};
}
bool simple_undo::modify (sxsdk::scene_interface *scene, void *) { //  \en This plugin multiplies geometry attributes with 0.5. This is not a good way to scale shape objects, but we do it this way to show how undo works. \enden  \ja このプラグインは、それぞれの形状の幾何属性に0.5を掛ける。形状を縮小する方法としては適切ではないが、アンドゥの機能をわかりやすくするために、このようにして幾何属性を変更する。 \endja 
	scene->reset_undo_obsolete(); //  \en Since we may register more than one undo action, call reset_undo() before registering any undo actions. \enden  \ja ここでは一個以上のアンドゥアクションを登録するので、登録するまえにreset_undo()を呼ぶ。 \endja 
	const int n = scene->get_active_shapes(0);
	if (0 < n) {
		std::vector<sxsdk::shape_class *> shapes(n);
		scene->get_active_shapes(&(shapes[0]));
		for (int i = 0; i < n; ++i) {
			sxsdk::shape_class &shape = *(shapes[i]);
			compointer<sxsdk::shape_saver_interface> shape_saver(shape.create_shape_saver_interface()); //  \en Create a sxsdk::shape_saver_interface object. This object holds original geometry attributes. \enden  \ja sxsdk::shape_saver_interfaceオブジェクトを生成する。このオブジェクトが元の形状の幾何属性を保持する。 \endja 

			//  \en Multilie geometry attributes with 0.5. \enden  \ja 幾何属性に0.5を掛ける \endja 
			switch (shape.get_type()) {
			case sxsdk::enums::polygon_mesh:
				{   sxsdk::polygon_mesh_class &p = sxsdk::polygon_mesh_class::cast(shape);
					const int n = p.get_number_of_points();
					for (int i = 0; i < n; ++i) {
						sxsdk::vertex_class &vertex = p.vertex(i);
						vertex.set_position(vertex.get_position() * 0.5f);
					}
				}
				break;
			case sxsdk::enums::line:
				{   sxsdk::line_class &p = sxsdk::line_class::cast(shape);
					const int n = p.get_number_of_points();
					for (int i = 0; i < n; ++i) {
						sxsdk::control_point_class &control_point = p.control_point(i);
						control_point.set_position(control_point.get_position() * 0.5f);
					}
				}
				break;
			case sxsdk::enums::part:
				{   sxsdk::part_class &p = sxsdk::part_class::cast(shape);
					for (sxsdk::shape_class::iterator s = p.begin(); s != p.end(); ++s) {
						sxsdk::line_class &line = sxsdk::line_class::cast(*s);
						const int n = line.get_number_of_control_points();
						for (int i = 0; i < n; ++i) {
							sxsdk::control_point_class &control_point = line.control_point(i);
							control_point.set_position(control_point.get_position() * 0.5f);
						}
					}
				}
				break;
			case sxsdk::enums::light:
				{   sxsdk::light_class &p = sxsdk::light_class::cast(shape);
					p.set_intensity(p.get_intensity() * 0.5f);
				}
				break;
			case sxsdk::enums::sphere:
				{   sxsdk::sphere_class &p = sxsdk::sphere_class::cast(shape);
					p.set_radius(p.get_radius() * 0.5f);
				}
				break;
			case sxsdk::enums::disk:
				{   sxsdk::disk_class &p = sxsdk::disk_class::cast(shape);
					p.set_radius(p.get_radius() * 0.5f);
				}
				break;
			}

			shape_saver->set_undo_action(); //  \en Register an undo action. \enden  \ja アンドゥアクションを登録する。 \endja 
		}
	}
	return true;
}

SXPLUGINNAMESPACEBEGIN(test_undo)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		simple_undo *u = new simple_undo;
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == modifier_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "simple undo";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		return SIMPLE_UNDO_ID;
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
