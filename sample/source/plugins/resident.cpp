#include "sxsdk.cxx"

#include "boost/format.hpp"

namespace {
	const sx::uuid_class SIMPLE_RESIDENT_ID("C7F3D78E-549E-11D9-A353-000A95BACEB2");

	class creator_component : public sxsdk::creator_interface {
	public:
		creator_component (sxsdk::shade_interface &shade) : shade(shade), count(0) { }
	private:
		sxsdk::shade_interface &shade;
		int count;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_RESIDENT_ID; }
		virtual bool create (sxsdk::scene_interface *scene, void *);
		virtual void surface_being_deleted (bool &, sxsdk::surface_interface *surface, void *);
		virtual void surface_changed (bool &, sxsdk::surface_interface *surface, void *);
		virtual void active_scene_changed (bool &, sxsdk::scene_interface *scene, void *);
		virtual void shapes_inserted (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *);
		virtual void shapes_modified (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *);
		virtual void shapes_moved (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, const sxsdk::mat4 &t, void *);
		virtual void shapes_being_deleted (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *);
		virtual void shapes_created (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *);
		virtual void active_shapes_changed (bool &, sxsdk::scene_interface *scene, int old_n, sxsdk::shape_class *const *old_shapes, int n, sxsdk::shape_class *const *shapes, void *);
		virtual void scene_opened (bool &, sxsdk::scene_interface *scene, void *);
		virtual void scene_closed (bool &, sxsdk::scene_interface *scene, void *);
		virtual void scene_being_saved (bool& b, sxsdk::scene_interface* scene, void*);
		virtual void current_joint_value_changing (bool &, sxsdk::scene_interface *scene, int n, sxsdk::part_class *const *parts, void *);
		virtual void current_joint_value_changed (bool &, sxsdk::scene_interface *scene, int n, sxsdk::part_class *const *parts, void *);
		virtual void sequence_changed (bool &, float sequence, sxsdk::scene_interface *scene, int n, sxsdk::part_class *const *parts, void *);
		virtual void sequence_mode_changed (bool &, sxsdk::scene_interface *scene, bool sequence_mode, void *);
		virtual void camera_changed (bool &, sxsdk::scene_interface *scene, void *);
		virtual void name_changed (bool &, const char *old_name, sxsdk::shape_class &shape, void *);
		virtual void local_light_changed (bool &b, sxsdk::shape_class &shape, void *);
		virtual void distant_light_changed (bool &b, sxsdk::scene_interface *scene, int index, void *);
		virtual void current_distant_light_index_changed ( bool &b, int index, void *);
		virtual void current_mapping_index_changed ( bool &b, int index, void *);
		//virtual bool accepts_prequickrendering ( void* aux =0 );
		//virtual void prequickrendering ( sxsdk::scene_interface *scene, int view, void* aux);
		virtual void figure_scale_changed (bool& b, sxsdk::scene_interface* scene, void*);
		virtual void figure_unit_changed (bool &b, sxsdk::scene_interface *scene, void *);
		virtual void create_line_mode_entered (bool& b, sxsdk::scene_interface* scene, int closed, void*);
		virtual void create_line_mode_exited (bool& b, sxsdk::scene_interface* scene, int closed, void*);
		virtual void creating_shape_changed (bool& b, sxsdk::shape_class& shape, void*);
		virtual void sound_stopped (bool& b, void* aux);
		virtual void pre_rendering (bool& b, sxsdk::rendering_context_interface* rendering_context, void*);
		virtual void post_rendering (bool& b, sxsdk::rendering_context_interface* rendering_context);
		virtual void preference_ok ( sxsdk::dialog_interface *dialog, void* aux);
		virtual void idle_task (bool &, sxsdk::scene_interface *scene, void *);
		virtual void browser_updated (bool &, sxsdk::scene_interface *scene, void *);
		virtual void surface_updated (bool& b, sxsdk::scene_interface* scene, void* aux);
		virtual void make_wireframe (sxsdk::shape_class &shape, const sxsdk::mat4 &mat, int view, int flags, void *);
		virtual bool accepts_wireframe (void *);
		virtual void append_preference_items (sxsdk::dialog_interface *dialog, void *);
	};
}
bool creator_component::create (sxsdk::scene_interface *scene, void *) {
	return true;
}
void creator_component::surface_being_deleted (bool &, sxsdk::surface_interface *surface, void *) {
	//shade.message(str(format("%1% surface_being_deleted") % count++));
}
void creator_component::surface_changed (bool &, sxsdk::surface_interface *surface, void *) {
	//shade.message(str(format("%1% surface_changed") % count++));
}
void creator_component::active_scene_changed (bool &, sxsdk::scene_interface *scene, void *) {
	//  \en This function is called when an active scene is changed. \enden  \ja アクティブなシーンが変わるとこの関数が呼ばれる。 \endja 
	//const char *name = scene ? scene->get_active_document() : "(empty scene)";
	//shade.message(str(format("%1% active_scene_changed: %2%") % count++ % name));
}
void creator_component::shapes_inserted (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *) {
	//  \en This function is called when a new shape objects are inserted. \enden  \ja 形状が挿入（ペースト／インポート）されたらこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% shapes_inserted: %2%") % count++ % n));
}
void creator_component::shapes_modified (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *) {
	//  \en This function is called when shape objects are modified. \enden  \ja 形状がモディファイされたらこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% shapes_modified: %2%") % count++ % n));
}
void creator_component::shapes_moved (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, const sxsdk::mat4 &t, void *) {
	//  \en This function is called when shape objects are moved. \enden  \ja 形状が移動されたらこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% shapes_moved: %2%") % count++ % n));
}
void creator_component::shapes_being_deleted (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *) {
	//  \en This function is called before shape objects are deleted. \enden  \ja 形状が削除される前にこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% shapes_being_deleted: %2%") % count++ % n));
}
void creator_component::shapes_created (bool &, sxsdk::scene_interface *scene, int n, sxsdk::shape_class *const *shapes, void *) {
	//  \en This function is called when new shape objects are created. \enden  \ja 形状が作成されたらこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% shapes_created: %2%") % count++ % n));
}
void creator_component::active_shapes_changed (bool &, sxsdk::scene_interface *scene, int old_n, sxsdk::shape_class *const *old_shapes, int n, sxsdk::shape_class *const *shapes, void *) {
	//  \en This function is called when selected shape objects are changed. \enden  \ja 現在選択されている形状が変わると、この関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% active_shapes_changed: %2% -> %3%") % count++ % old_n % n));
}
void creator_component::scene_opened (bool &, sxsdk::scene_interface *scene, void *) {
	//  \en This function is called when a new scene is opened. \enden  \ja シーンが開かれる際にこの関数が呼ばれる。 \endja 
	//const char *name = scene ? scene->get_active_document() : "(empty scene)";
	//shade.message(str(format("%1% scene_opened: %2%") % count++ % name));
}
void creator_component::scene_closed (bool &, sxsdk::scene_interface *scene, void *) {
	//  \en This function is called before a scene is closed. \enden  \ja シーンが閉じられる前にこの関数が呼ばれる。 \endja 
	//const char *name = scene ? scene->get_active_document() : "(empty scene)";
	//shade.message(str(format("%1% scene_closed: %2%") % count++ % name));
}
void creator_component::scene_being_saved (bool& b, sxsdk::scene_interface* scene, void*) {
	//  \en This function is called before a scene is saved. \enden  \ja シーンが保存される前にこの関数が呼ばれる。 \endja 
	//const char *name = scene ? scene->get_active_document() : "(empty scene)";
	//shade.message(str(format("%1% scene_being_saved: %2%") % count++ % name));
}
void creator_component::current_joint_value_changing (bool &, sxsdk::scene_interface *scene, int n, sxsdk::part_class *const *parts, void *) {
	//  \en This function is called while joint values are being changed. \enden  \ja ジョイントの設定値が変わっている最中にこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% current_joint_value_changing: %2%") % count++ % n));
}
void creator_component::current_joint_value_changed (bool &, sxsdk::scene_interface *scene, int n, sxsdk::part_class *const *parts, void *) {
	//  \en This function is called when joint value are changed. \enden  \ja ジョイントの設定値が変わるとこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% current_joint_value_changed: %2%") % count++ % n));
}
void creator_component::sequence_changed (bool &, float sequence, sxsdk::scene_interface *scene, int n, sxsdk::part_class *const *parts, void *) {
	//  \en This function is called when sequence value is changed. \enden  \ja フレームの設定値が変わるとこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% sequence_changed: %2%, moved joints(%3%)") % count++ % sequence % n));
}
void creator_component::sequence_mode_changed (bool &, sxsdk::scene_interface *scene, bool sequence_mode, void *) {
	//  \en This function is called when sequence mode is changed. \enden  \ja シーケンスモードが変わるとこの関数が呼ばれる。 \endja 
	//const char *mode = sequence_mode ? "true" : "false";
	//shade.message(str(format("%1% sequence_mode_changed: %2%") % count++ % mode));
}
void creator_component::camera_changed (bool &, sxsdk::scene_interface *scene, void *) {
	//  \en This function is called when camera settings are changed. \enden  \ja カメラの設定値が変わるとこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% camera_changed") % count++));
}
void creator_component::name_changed (bool &, const char *old_name, sxsdk::shape_class &shape, void *) {
	//  \en This function is called when names of shape objects are changed. \enden  \ja 形状の名前が変わるとこの関数が呼ばれる。 \endja 
	const std::string old_name_str((std::string(old_name) == std::string("")) ? "(default name)" : old_name);
	//shade.message(str(format("%1% name_changed: %2% -> %3%") % count++ % old_name_str % shape.get_name()));
}
void creator_component::local_light_changed (bool &b, sxsdk::shape_class &shape, void *) {
	//  \en This function is called when a light object is changed. \enden  \ja 光源形状が変わるとこの関数が呼ばる。 \endja 
	//shade.message(str(format("%1% local_light_changed: %2%") % count++ % shape.get_name()));
}
void creator_component::distant_light_changed (bool &b, sxsdk::scene_interface *scene, int index, void *) {
	//  \en This function is called when distant light is changed. \enden  \ja 無限遠光源が変わるとこの関数が呼ばる。 \endja 
	//shade.message(str(format("%1% distant_light_changed: %2%") % count++ % index));
}
void creator_component::current_distant_light_index_changed ( bool &b, int index, void *) {
	//  \en This function is called when current distant light index is changed. \enden  \ja アクティブな無限遠光源の番号が変わるとこの関数が呼ばる。 \endja 
	//shade.message(str(format("%1% current_distant_light_index_changed: %2%") % count++ % index));
}
void creator_component::current_mapping_index_changed ( bool &b, int index, void *) {
	//  \en This function is called when current mapping index is changed. \enden  \ja アクティブな表面材質のマッピングレイヤー番号が変わるとこの関数が呼ばる。 \endja 
	//shade.message(str(format("%1% current_mapping_index_changed: %2%") % count++ % index));
}
void creator_component::figure_scale_changed (bool& b, sxsdk::scene_interface* scene, void*) {
	//  \en This function is called when the scale of the figure window is changed. \enden  \ja 図形ウインドウの表示拡大率が変わるとこの関数が呼ばる。 \endja 
	//shade.message(str(format("%1% figure_scale_changed: %2%") % count++ % scene->get_pixel_size()));
}
void creator_component::figure_unit_changed (bool &b, sxsdk::scene_interface *scene, void *) {
	//  \en This function is called when the unit of the figure window is changed. \enden  \ja 図形ウインドウの単位が変わるとこの関数が呼ばる。 \endja 
	//shade.message(str(format("%1% figure_unit_changed: %2%") % count++ % scene->get_unit()));
}
void creator_component::create_line_mode_entered (bool& b, sxsdk::scene_interface* scene, int closed, void*) {
	//  \en blah \enden  \ja 線形状の作成が開始されるとこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% create_line_mode_entered: closed(%2%)") % count++ % closed));
}
void creator_component::create_line_mode_exited (bool& b, sxsdk::scene_interface* scene, int closed, void*) {
	//  \en blah \enden  \ja 線形状の作成が終了するとこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% create_line_mode_exited: closed(%2%)") % count++ % closed));
}
void creator_component::creating_shape_changed (bool& b, sxsdk::shape_class& shape, void*) {
	//  \en blah \enden  \ja 線形状の作成中、コントロールポイントの追加がされるたびにこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% creating_shape_changed") % count++));
}
void creator_component::sound_stopped (bool& b, void*) {
	//  \en blah \enden  \ja サウンドのプレビュー再生が停止するときにこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% sound_stopped") % count++));
}
void creator_component::pre_rendering (bool& b, sxsdk::rendering_context_interface* rendering_context, void*) {
	//  \en blah \enden  \ja レンダリングが開始されるときにこの関数が呼ばれる。 \endja 
	compointer<sxsdk::scene_interface> scene(rendering_context->get_scene_interface());
	//shade.message(str(format("%1% pre_rendering: %2%") % count++ % scene->get_active_document()));
}
void creator_component::post_rendering (bool& b, sxsdk::rendering_context_interface* rendering_context) {
	//  \en blah \enden  \ja レンダリングが終了したときにこの関数が呼ばれる。 \endja 
	compointer<sxsdk::scene_interface> scene(rendering_context->get_scene_interface());
	//shade.message(str(format("%1% post_rendering: %2%") % count++ % scene->get_active_document()));
}
void creator_component::preference_ok ( sxsdk::dialog_interface *dialog, void*) {
	//  \en blah \enden  \ja OKボタンを押して環境設定ウインドウを閉じたときに呼ばれる。 \endja 
	//shade.message(str(format("%1% preference_ok") % count++));
}
void creator_component::idle_task (bool &, sxsdk::scene_interface *scene, void *) {
	//  \en This function is called periodically. \enden  \ja アイドル時にこの関数が呼ばれる。 \endja 
}
void creator_component::browser_updated (bool &, sxsdk::scene_interface *scene, void *) {
	//  \en This function is called when the browser display is updated. \enden  \ja ブラウザ表示が更新される際にこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% browser_updated") % count++));
}
void creator_component::surface_updated (bool& b, sxsdk::scene_interface* scene, void*) {
	//  \en This function is called when the browser display is updated. \enden  \ja 表面材質ウインドウの表示が更新される際にこの関数が呼ばれる。 \endja 
	//shade.message(str(format("%1% surface_updated") % count++));
}
void creator_component::make_wireframe (sxsdk::shape_class &shape, const sxsdk::mat4 &mat, int view, int flags, void *) {
} 
bool creator_component::accepts_wireframe (void *) {
	return false;
}
void creator_component::append_preference_items (sxsdk::dialog_interface *dialog, void *) {
	//dialog->append_item(sxsdk::dialog_interface::rgb_type, "color");
}

SXPLUGINNAMESPACEBEGIN(test_resident)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		creator_component *u = new creator_component(*shade);
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == creator_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "Simple Resident";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		return SIMPLE_RESIDENT_ID;
	}
	SXPLUGINENTRY  const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		//  \en Returning true indicates that the dll stays in the memory once loaded and waits for various callbacks. \enden  \ja trueを返すとdllがメモリに常駐し、objects_movedなどの呼び出しを待ち受けます。 \endja 
		return true;
	}
SXPLUGINNAMESPACEEND
