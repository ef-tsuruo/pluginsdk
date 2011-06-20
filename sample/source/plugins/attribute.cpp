#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_ATTRIBUTE_ID("85F18D69-549D-11D9-A90D-000A95BACEB2");

	// \en This plugin appends a floating point value to a shape object as an attribute.\enden \ja 形状にカスタム属性として浮動小数点数１個を追加するプラグイン。 \endja 
	// \en When the shape is a sphere object, use this value as the ratio of its radius and draw another sphere with the new radius.\enden \ja 対象となる形状が球の場合、この属性の値を半径の比率とみなして、ワイヤフレームで球を２重に表示する。 \endja 
	class attribute_component : public sxsdk::attribute_interface {
	public:
		attribute_component (sxsdk::shade_interface *shade) : shade(shade) { }
	private:
		sxsdk::shade_interface *const shade;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_ATTRIBUTE_ID; }
		virtual bool ask_shape (sxsdk::shape_class &shape, void *);
		virtual bool ask_distant_light (sxsdk::distant_light_interface *light, int i, void *);
		virtual bool ask_camera (sxsdk::camera_interface *camera, int i, void *);
		virtual bool ask_surface (sxsdk::surface_interface *surface, void *);
		virtual bool ask_mapping (sxsdk::mapping_layer_class &mapping_layer, void *);
		
		// \en The name of this plugin is added to the Custom Info menu if this function sets accept to true.\enden \ja acceptにtrueを設定すると、Shadeのカスタム属性メニューにアイテムが表示される。 \endja 
		virtual void accepts_shape (bool &accept, void *) { accept = true; }
		
		// \en The name of this plugin is added to the Distant Light Info menu if this function sets accept to true.\enden \ja acceptにtrueを設定すると、無限遠光源の情報メニューにアイテムが表示される。 \endja 
		virtual void accepts_distant_light (bool &b, void *) { b = true; }

		// \en The name of this plugin is added to the Camera Info menu if this function sets accept to true.\enden \ja acceptにtrueを設定すると、カメラの情報メニューにアイテムが表示される。 \endja 
		virtual void accepts_camera (bool &b, void *) { b = true; }

		// \en make_wireframe is called when Shade needs to draw wireframe.\enden \ja Shadeがワイヤフレームを表示する際に、make_wireframeが呼ばれる。 \endja 
		virtual void make_wireframe (sxsdk::shape_class &shape, const sxsdk::mat4 &mat, int view, int flags, void *);

		// \en The name of this plugin is added to the Surface Attributes Info menu if this function sets accept to true.\enden \ja acceptにtrueを設定すると、表面材質の情報メニューにアイテムが表示される。 \endja 
		virtual void accepts_surface (bool &b, void *) { b = true; }

		// \en The name of this plugin is added to the Mapping Attributes Info menu if this function sets accept to true.\enden \ja acceptにtrueを設定すると、マッピングの情報メニューにアイテムが表示される。 \endja 
		virtual void accepts_mapping (bool &b, void *) { b = true; }

		virtual int get_max_intersections (sxsdk::shape_class &shape, int i, void *);
		virtual int get_max_shapes (sxsdk::shape_class &shape, int i, void *);
		virtual sxsdk::custom_element_info_base_class *new_custom_element_info (sxsdk::shape_class &shape, const sxsdk::mat4 &lw, const sxsdk::mat4 &wl, int i);
		virtual sxsdk::custom_element_info_base_class *new_per_thread_info (sxsdk::shape_class &shape, int i, int j);
		virtual sxsdk::box3_class get_bounding_box (const sxsdk::custom_element_info_base_class *, sxsdk::shape_class &shape, const sxsdk::mat4 &lw, const sxsdk::mat4 &wl, int i, void *);
		virtual int ray_intersection (const sxsdk::custom_element_info_base_class *, sxsdk::shape_class &shape, const sxsdk::mat4 &lw, const sxsdk::mat4 &wl, int i, const sx::vec<float,3> &o, const sx::vec<float,3> &d, sxsdk::intersection_class intersections[], sxsdk::custom_element_info_base_class *, void *);
	};
}
// \en ask_shape function is called when the Custom Info menu is selected.\enden \ja Shadeの特別メニューのカスタム属性が選択されたらask_shape関数が呼ばれる。 \endja 
bool attribute_component::ask_shape (sxsdk::shape_class &shape, void *) {
	sx::vec<float,3> a;
	sxsdk::mat4 b;
	a * b;

	// \en Create a dialog box inquirering a numerical value.\enden \ja 数値を1個だけ入力するダイアログボックスを作成する。 \endja 
	compointer<sxsdk::dialog_interface> dialog(shade->create_dialog_interface());
	dialog->set_title("Dialog");
	dialog->append_item(sxsdk::dialog_interface::float_type, "FLOAT");
	
	// \en Get a stream for accessing custom attributes of the shape.\enden \ja 形状のカスタム属性にアクセスするためのストリームを取得する。 \endja 
	compointer<sxsdk::stream_interface> stream(shape.get_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID));

	if (stream) {
		// \en If the custom attributes exists, read a floating point value from the attribute stream and set it to the dialog box.\enden \ja カスタム属性が存在する場合、そこから浮動小数点数１個を読み込み、ダイアログボックスにその値を設定する。 \endja 
		float s;
		stream->set_pointer(0);
		stream->read_float(s);
		dialog->set_float_property_value(0, s);
	}
	if (dialog->ask()) { // \en Display the dialog box.\enden \ja ダイアログボックスを表示する。 \endja 

		// \en Write the new value to the stream.\enden \ja ユーザが入力した数値を読み取り、それをカスタム属性ストリームに書き込む。 \endja 
		// \en If there already is custum attributes, jacreate_attribute_stream deletes it and creates a new one.\enden \ja create_attribute_streamは、既存のカスタム属性があればそれを削除して、新規に属性を作成する。 \endja 
		float s;
		dialog->get_float_property_value(0, s);
		
		// \en The second argument is a plugin-id for make_wireframe fucntion.\enden \ja 第２引数で、make_wireframeのplugin-idを指定する。 \endja 
		// \en The third argument is a plugin-id for ray_intersection function.\enden \ja 第３引数で、ray_intersectionのplugin-idを指定する。 \endja 
		compointer<sxsdk::stream_interface> stream(shape.create_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID, SIMPLE_ATTRIBUTE_ID, SIMPLE_ATTRIBUTE_ID));
		stream->write_float(s);
		stream->set_label("custom sphere");
		return true;
	}
	return false;
}
// \en ask_distant_light is called when the Info menu of the distant lights is selected.\enden \ja 無限遠光源の情報ポップアップメニューが選択されたらask_distant_light関数が呼ばれる。 \endja 
bool attribute_component::ask_distant_light (sxsdk::distant_light_interface *light, int i, void *) {

	// \en Create a dialog box inquirering a numerical value.\enden \ja 数値を1個だけ入力するダイアログボックスを作成する。 \endja 
	compointer<sxsdk::dialog_interface> dialog(shade->create_dialog_interface());
	dialog->set_title("Dialog");
	dialog->append_item(sxsdk::dialog_interface::float_type, "FLOAT");

	// \en Get a stream for accessing custom attributes of the light.\enden \ja 光源のカスタム属性にアクセスするためのストリームを取得する。 \endja 
	sxsdk::distant_light_item_class &d = light->distant_light_item(i);
	compointer<sxsdk::stream_interface> stream(d.get_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID));
	if (stream) {
		// \en If the custom attributes exists, read a floating point value from the attribute stream and set it to the dialog box.\enden \ja カスタム属性が存在する場合、そこから浮動小数点数１個を読み込み、ダイアログボックスにその値を設定する。 \endja 
		float s;
		stream->set_pointer(0);
		stream->read_float(s);
		dialog->set_float_property_value(0, s);
	}
	if (dialog->ask()) { // \en Display the dialog box.\enden \ja ダイアログボックスを表示する。 \endja 
		// \en Write the new value to the stream.\enden \ja ユーザが入力した数値を読み取り、それをカスタム属性ストリームに書き込む。 \endja 
		// \en If there already is custum attributes, jacreate_attribute_stream deletes it and creates a new one.\enden \ja create_attribute_streamは、既存のカスタム属性があればそれを削除して、新規に属性を作成する。 \endja 
		float s;
		dialog->get_float_property_value(0, s);
		compointer<sxsdk::stream_interface> stream(d.create_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID));
		stream->write_float(s);
		return true;
	}
	return false;
}
// \en ask_camera is called when the Info menu of the camera is selected.\enden \ja カメラの情報ポップアップメニューが選択されたらask_distant_light関数が呼ばれる。 \endja 
bool attribute_component::ask_camera (sxsdk::camera_interface *camera, int i, void *) {

//		// \en Create a dialog box inquirering a numerical value.\enden \ja 数値を1個だけ入力するダイアログボックスを作成する。 \endja 
//		compointer<dialog_interface> dialog(shade->create_dialog_interface());
//		dialog->set_title("Dialog");
//		dialog->append_item(dialog_interface::float_type, "FLOAT");
//
//		// \en Get a stream for accessing custom attributes of the camera.\enden \ja カメラのカスタム属性にアクセスするためのストリームを取得する。 \endja 
//		compointer<stream_interface> stream(camera->get_attribute_stream_interface_with_uuid(i, SIMPLE_ATTRIBUTE_ID));
//		if (stream) {
//			// \en If the custom attributes exists, read a floating point value from the attribute stream and set it to the dialog box.\enden \ja カスタム属性が存在する場合、そこから浮動小数点数１個を読み込み、ダイアログボックスにその値を設定する。 \endja 
//			float s;
//			stream->set_pointer(0);
//			stream->read_float(s);
//			dialog->set_float_property_value(0, s);
//		}
//		if (dialog->ask()) { // \en Display the dialog box.\enden \ja ダイアログボックスを表示する。 \endja 
//			// \en Write the new value to the stream.\enden \ja ユーザが入力した数値を読み取り、それをカスタム属性ストリームに書き込む。 \endja 
//			// \en If there already is custum attributes, jacreate_attribute_stream deletes it and creates a new one.\enden \ja create_attribute_streamは、既存のカスタム属性があればそれを削除して、新規に属性を作成する。 \endja 
//			float s;
//			dialog->get_float_property_value(0, s);
//			compointer<stream_interface> stream(camera->create_attribute_stream_interface_with_uuid(i, SIMPLE_ATTRIBUTE_ID));
//			stream->write_float(s);
//			return true;
//		}
	return false;
}
// \en ask_surface is called when the Info menu of the surface attributes is selected.\enden \ja 表面材質の情報ポップアップメニューが選択されたらask_surface関数が呼ばれる。 \endja 
bool attribute_component::ask_surface (sxsdk::surface_interface *surface, void *) {

	// \en Create a dialog box inquirering a numerical value.\enden \ja 数値を1個だけ入力するダイアログボックスを作成する。 \endja 
	compointer<sxsdk::dialog_interface> dialog(shade->create_dialog_interface());
	dialog->set_title("Dialog");
	dialog->append_item(sxsdk::dialog_interface::float_type, "FLOAT");

	// \en Get a stream for accessing custom attributes of the surface attributes.\enden \ja 表面材質のカスタム属性にアクセスするためのストリームを取得する。 \endja 
	compointer<sxsdk::stream_interface> stream(surface->get_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID));
	if (stream) {
		// \en If the custom attributes exists, read a floating point value from the attribute stream and set it to the dialog box.\enden \ja カスタム属性が存在する場合、そこから浮動小数点数１個を読み込み、ダイアログボックスにその値を設定する。 \endja 
		float s;
		stream->set_pointer(0);
		stream->read_float(s);
		dialog->set_float_property_value(0, s);
	}
	if (dialog->ask()) { // \en Display the dialog box.\enden \ja ダイアログボックスを表示する。 \endja 
		// \en Write the new value to the stream.\enden \ja ユーザが入力した数値を読み取り、それをカスタム属性ストリームに書き込む。 \endja 
		// \en If there already is custum attributes, jacreate_attribute_stream deletes it and creates a new one.\enden \ja create_attribute_streamは、既存のカスタム属性があればそれを削除して、新規に属性を作成する。 \endja 
		float s;
		dialog->get_float_property_value(0, s);
		compointer<sxsdk::stream_interface> stream(surface->create_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID));
		stream->write_float(s);
		return true;
	}
	return false;
}
bool attribute_component::ask_mapping (sxsdk::mapping_layer_class &mapping_layer, void *) {
	compointer<sxsdk::dialog_interface> dialog(shade->get_dialog_interface());
	dialog->set_title("mapping") ;

	int param1_index = dialog->append_item(sxsdk::dialog_interface::int_type, "param1") ;
	dialog->set_int_property_value(param1_index, 123) ;

	try {
		int mapping_type = mapping_layer.get_type() ;
		int pattern_type = mapping_layer.get_pattern() ;
		std::stringstream buff;
		buff << "mapping_type:" << mapping_type << "; pattern_type:" << pattern_type;
		shade->message(buff.str().c_str()) ;
	} catch(...) { shade->message("AAA") ; }

	if(!dialog->ask())
		return false ;

	return true ;
}
void attribute_component::make_wireframe (sxsdk::shape_class &shape, const sxsdk::mat4 &mat, int view, int flags, void *) {
	try {
		sxsdk::sphere_class &sphere = shape.get_sphere();
		compointer<sxsdk::stream_interface> stream(shape.get_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID));
		if (stream) {
			// \en Read a floating point value from the custom attribute stream.\enden \ja カスタム属性ストリームから浮動小数点数を１個読み込む。 \endja 
			float s;
			stream->set_pointer(0);
			stream->read_float(s);

			// \en Create wireframe of a sphere with specified radius.\enden \ja 読み込んだ値によって球の半径を変化させたワイヤーフレームを作成する。 \endja 
			sxsdk::mat4 t = sphere.get_matrix();
			for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) t[i][j] *= s;
			shape.make_sphere_wireframe(mat, t);
		}
	}
	catch (...) {
		sxsdk::mat4 t(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		t[0][0] = t[1][1] = t[2][2] = 500.0f;
		shape.make_sphere_wireframe(mat, t);
	}
}
// \en Returns the maximum number of intersections per ray for this object.\enden \ja 一本のレイと交差する可能性のある点の最大数を返す。 \endja 
int attribute_component::get_max_intersections (sxsdk::shape_class &shape, int i, void *) {
	return 2;
}
// \en Returns the maximum number of objects that may merge.\enden \ja 融合する可能性のある形状の最大数を返す。 \endja 
int attribute_component::get_max_shapes (sxsdk::shape_class &shape, int i, void *) {
	return 3;
}

// \en Information for calculating intersections.\enden \ja 交点計算に必要な独自の情報 \endja 
class custom_size_class : public sxsdk::custom_element_info_base_class {
public:
	const float size;
	custom_size_class (float size) : size(size) { }
};

// \en Creates an info. block for calculating intersections. The pointer for this object is passed back to this plugin as a parameter of get_bounding_box and ray_intersection functions.\enden \ja 交点計算に必要な独自の情報を生成する。ここで生成したオプジェクトのポインタは、get_bounding_boxおよびray_intersectionの引数としてわたされる。 \endja 
// \en The info. object created here will be automatically deleted when no longer needed.\enden \ja レンダリング終了時に自動的にdeleteされる。 \endja 
// \en In this example, we simply store the value of relative radius value.\enden \ja この例では、単に、相対半径の属性をそのまま格納する。 \endja 
// \en If you do not need to use an info. block, you don't have to override the new_custom_element_info function and it returns 0.\enden \ja 必要なければ、new_custom_element_infoをオーバーライドする必要はなく、また、その場合は0が返される。 \endja 
sxsdk::custom_element_info_base_class *attribute_component::new_custom_element_info (sxsdk::shape_class &shape, const sxsdk::mat4 &lw, const sxsdk::mat4 &wl, int i) {
	//sphere_class &sphere = shape.get_sphere();
	compointer<sxsdk::stream_interface> stream(shape.get_attribute_stream_interface_with_uuid(SIMPLE_ATTRIBUTE_ID));
	if (stream) {
		float s;
		stream->set_pointer(0);
		stream->read_float(s);
		return new custom_size_class(s);
	}
	throw "error";
	return 0;
}

class custom_element_info__class : public sxsdk::custom_element_info_base_class {
public:
	int data[100];
};

sxsdk::custom_element_info_base_class *attribute_component::new_per_thread_info (sxsdk::shape_class &shape, int i, int j) {
	return new custom_element_info__class;
}

// \en Returns the bounding box for the shape object.\enden \ja バウンディングボックスを返す。 \endja 
// \en lw: transformation sx::mat<float,4> from the local coordinates to the world coordinates.\enden \ja lwはlocal->worldの変換マトリクス。 \endja 
// \en wl: transformation matrixx from the world coordinates to the local coordinates.\enden \ja wlはworld->localの変換マトリクス。 \endja 
sxsdk::box3_class attribute_component::get_bounding_box (const sxsdk::custom_element_info_base_class *info, sxsdk::shape_class &shape, const sxsdk::mat4 &lw, const sxsdk::mat4 &wl, int i, void *) {
	sxsdk::sphere_class &sphere = shape.get_sphere();
	if (info) {
		// \en Fetch the data created in the new_custom_element_info function.\enden \ja new_custom_element_infoで作成したデータを取得する。 \endja 
		const float size = dynamic_cast<const custom_size_class &>(*info).size;
		sxsdk::mat4 t = sphere.get_matrix();
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) t[i][j] *= size;
		t *= lw;
		// \en Apply the transformation t to the unit box and return it.\enden \ja 単位ボックスに変換tを施した結果のバウンディングボックスを返す。 \endja 
		return sxsdk::box3_class(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f) * t;
	}
	throw "error";
}

// \en Calculates intersections. Stores intersection info to intersections and returns the number of intersections.\enden \ja 交点計算を行う。交点の情報はintersectionsに格納し、交点の数を返す。 \endja 
// \en The ray is defined as the starting point o and the normalized direction vector d as in o + td, 0.0 <= t.\enden \ja レイは始点位置ベクトルo、単位方向ベクトルdから成る、o + td, 0.0 <= t として指定される。 \endja 
int attribute_component::ray_intersection (const sxsdk::custom_element_info_base_class *info, sxsdk::shape_class &shape, const sxsdk::mat4 &lw, const sxsdk::mat4 &wl, int i, const sx::vec<float,3> &o, const sx::vec<float,3> &d, sxsdk::intersection_class intersections[], sxsdk::custom_element_info_base_class *per_thread, void *) {
	{	custom_element_info__class *info = dynamic_cast<custom_element_info__class *>(per_thread);
		if (info) {
			for (int i = 0; i < 100; i++) info->data[i] = i;
		}
	}
	int n = 0;
	sxsdk::sphere_class &sphere = shape.get_sphere();
	if (info) {

		// \en Fetch the data created in the new_custom_element_info function.\enden \ja new_custom_element_infoで作成したデータを取得する。 \endja 
		const float size = dynamic_cast<const custom_size_class &>(*info).size;

		sxsdk::mat4 t = sphere.get_matrix();
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) t[i][j] *= size;
		t *= lw;
		sxsdk::mat4 itrans = inv(t);
		sx::vec<float,3> p2 = o * itrans; // \en Transform the starting point of the ray to the sphere primitive coordinates.\enden \ja レイの始点位置ベクトルを球プリミティブ座標系に変換する。 \endja 
		sx::vec<float,3> d2 = transform_direction(d, itrans); // \en Transform the normalized direction vector of the ray to the sphere primitive coordinates.\enden \ja レイの単位方向ベクトルを球プリミティブ座標系に変換する。 \endja 
		
		// \en Calculate the intersections between the sphere and the ray.\enden \ja 球とレイの交点計算。 \endja 
		float a = d2.x * d2.x + d2.y * d2.y + d2.z * d2.z;
		float b = p2.x * d2.x + p2.y * d2.y + p2.z * d2.z;
		float c = p2.x * p2.x + p2.y * p2.y + p2.z * p2.z - 1.0f;
		float k = b*b - a*c;
		if (k <= 0.0f) ;
		else {
			k = sqrt(k);
			float t1 = (-b + k) / a;
			float t0 = (-b - k) / a;
			//sxassert(t0 <= t1);
			if (0.0f <= t0) {
				intersections[n].t = t0;
				sx::vec<float,3> normal = p2 + d2 * t0;
				intersections[n].normal = normalize(transform_normal(itrans, normal));
				intersections[n].point = o + d * t0;
				
				// \en Merge Info.\enden \ja 融合情報 \endja 
				if (shape.has_sis()) {
					intersections[n].number_of_shapes = 2;
					//sxassert(intersections[n].shape_mixes);
					intersections[n].shape_mixes[1] = sxsdk::shape_mix_class(0.5f, shape.get_sis());
					intersections[n].shape_mixes[0] = sxsdk::shape_mix_class(0.5f, &shape);
				}
				n++;
			}
			if (0.0f <= t1) {
				intersections[n].t = t1;
				sx::vec<float,3> normal = p2 + d2 * t1;
				intersections[n].normal = normalize(transform_normal(itrans, normal));
				intersections[n].point = o + d * t1;
				
				// \en Merge Info.\enden \ja 融合情報 \endja 
				if (shape.has_sis()) {
					intersections[n].number_of_shapes = 2;
					//sxassert(intersections[n].shape_mixes);
					intersections[n].shape_mixes[1] = sxsdk::shape_mix_class(0.5f, shape.get_sis());
					intersections[n].shape_mixes[0] = sxsdk::shape_mix_class(0.5f, &shape);
				}
				n++;
			}
		}
	}
	return n;
}

SXPLUGINNAMESPACEBEGIN(test_attribute)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		attribute_component *u = new attribute_component(shade);
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == attribute_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "Simple Attribute";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		return SIMPLE_ATTRIBUTE_ID;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return true;
	}
SXPLUGINNAMESPACEEND
