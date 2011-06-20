#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_WINDOW_INMEMORYSXUL_ID	("B0D14FCF-73D2-4522-8DCA-3A00FE8F84FB");
	const sx::uuid_class SIMPLE_WINDOW_SXUL_ID			("A12FA1BE-549F-11D9-8774-000A95BACEB2");
	const sx::uuid_class SIMPLE_WINDOW_STOCK_ID			("A689354A-549F-11D9-8FE3-000A95BACEB2");
	const sx::uuid_class SIMPLE_WINDOW_CUSTOM_ID		("B418C554-549F-11D9-ACD8-000A95BACEB2");
}

//  \en sxul_window reads control definitions from a SXUL file. \enden  \ja SXULファイルで定義されたコントロールを読み込むウインドウの例。 \endja 
namespace {
	class inmemorysxul_window : public sxsdk::window_interface {
	public:
		explicit inmemorysxul_window (sxsdk::shade_interface &shade) : sxsdk::window_interface(shade), shade(shade) { }
	private:
		sxsdk::shade_interface &shade;
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_WINDOW_SXUL_ID; }

		virtual void initialize (void *);
	};
	void inmemorysxul_window::initialize (void *) {
		static const char *sxul =
			"<?xml version='1.0' encoding='UTF-8'?>"
			"<palette xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xsi:noNamespaceSchemaLocation='../../sxul.palettes.xsd'>"
			"	<vbox>"
			//"		<push-button id='push-button' label='push-button'/>"
			"		<number id='number' label='number'/>"
			"		<checkbox id='enumerated-checkbox' label='checkbox'/>"
			//"		<vec4 id='vec4' label='vec4'/>"
			//"		<color-box id='color-box' label='color-box'/>"
			//"		<matrix id='enumerated-matrix' label='matrix'/>"
			"		<quaternion id='enumerated-quaternion' label='quaternion'/>"
			//"		<color-disk id='enumerated-color-disk' label='color-disk'/>"
			//"		<scale id='enumerated-scale' label='scale'/>"
			"	</vbox>"
			"</palette>"
			;

		set_trigger(sxsdk::enums::active_scene_changed);
		
		{	compointer<sxsdk::stream_interface> stream(shade.create_fixed_memory_stream_interface(const_cast<char *>(sxul), strlen(sxul)));
			load_sxul(*stream);
		}
		set_client_rectangle(get_layout_bounds());
	}

	class sxul_window : public sxsdk::window_interface {
	public:
		explicit sxul_window (sxsdk::shade_interface &shade) : sxsdk::window_interface(shade),tablep(0) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_WINDOW_SXUL_ID; }

		virtual void initialize (void *);

		table_control_class*	tablep;
		virtual void push_button_clicked (window_interface::push_button_class& push_button, void* aux = 0) {
			if (strcmp(push_button.get_control_idname(),"insert-row-button")==0) {
				int num = tablep->number_of_rows();
				tablep->insert_row();
				tablep->set_bool_value(num,0,true);
				tablep->set_int_value(num,1,num);
				tablep->set_float_value(num,2,(float)num/10.0);
				std::string	str("test");
				tablep->set_string_value(num,3,str.c_str());
				tablep->set_color_value(num,4,sxsdk::rgb_class(1.0,0.0,0.0));
				tablep->select(num);
				tablep->invalidate();
			}
		}
		virtual void popup_menu_value_changed (window_interface::popup_menu_class& popup_menu, void* aux = 0) {
			if (popup_menu.get_control_idname()=="table-selection-mode-popup-menu") {
			}
		}
		virtual void initialize_table (window_interface::table_control_class& table, void* aux = 0) {
			tablep = &table;
		}
		virtual void table_selection_changed (window_interface::table_control_class& table, int count, const int* indice, void* aux) {
			shade.message("table_select_changed");
		}
		virtual bool table_double_clicked (window_interface::table_control_class& table, int row_index, void* aux) {
			shade.message("double_clicked");
			return false; 
		}

		//  \en Override initialize_push_button to initialize the push button. \enden  \ja initialize_push_buttonをオーバライドしてプッシュボタンを初期化する。 \endja 
		//virtual void initialize_push_button (sxsdk::window_interface::push_button_class& push_button, void*) {
		//	do something...
		//}


		//  \en Override initialize_checkbox to initialize the checkbox. \enden  \ja initialize_checkboxをオーバライドしてチェックボックスを初期化する。 \endja 
		//virtual void initialize_checkbox (sxsdk::window_interface::checkbox_class& checkbox, void*) {
		//	do something...
		//}

		//  \en Override initialize_disclosure_button to initialize the disclosure button. \enden  \ja initialize_disclosure_buttonをオーバライドしてディスクロージャボタンを初期化する。 \endja 
		//virtual void initialize_disclosure_button (sxsdk::window_interface::disclosure_button_class& disclosure_button, void*) {
		//	do something...
		//}

		//  \en Override initialize_slider to initialize the slider. \enden  \ja initialize_sliderをオーバライドしてスライダを初期化する。 \endja 
		//virtual void initialize_slider (sxsdk::window_interface::slider_class& slider, void*) {
		//	do something...
		//}

		//  \en Override initialize_number to initialize the number. \enden  \ja initialize_numberをオーバライドしてナンバーを初期化する。 \endja 
		//virtual void initialize_number (sxsdk::window_interface::number_class& number, void*) {
		//	do something...
		//}

		//  \en Override initialize_popup_menu to initialize the popup menu. \enden  \ja initialize_popup_menuをオーバライドしてポップアップメニューを初期化する。 \endja 
		//virtual void initialize_popup_menu (sxsdk::window_interface::popup_menu_class& popup_menu, void*) {
		//	do something...
		//}

		//  \en Override initialize_color_disk to initialize the color disk. \enden  \ja initialize_color_diskをオーバライドしてカラーディスクを初期化する。 \endja 
		//virtual void initialize_color_disk (sxsdk::window_interface::color_disk_class& color_disk, void*) {
		//	do something...
		//}

		//  \en Override initialize_color_box to initialize the color box. \enden  \ja initialize_color_boxをオーバライドしてカラーボックスを初期化する。 \endja 
		//virtual void initialize_color_box (sxsdk::window_interface::color_box_class& color_box, void*) {
		//	do something...
		//}

		//  \en Override initialize_image_box to initialize the image box. \enden  \ja initialize_image_boxをオーバライドしてイメージボックスを初期化する。 \endja 
		//virtual void initialize_image_box (sxsdk::window_interface::image_box_class& image_box, void*) {
		//	do something...
		//}

		//  \en Override initialize_radio_button to initialize the radio button. \enden  \ja initialize_radio_buttonをオーバライドしてラジオボタンを初期化する。 \endja 
		//virtual void initialize_radio_button (sxsdk::window_interface::radio_button_class& radio_button, void*) {
		//	do something...
		//}

		//  \en Override initialize_vec2 to initialize the sx::vec<float,2> control. \enden  \ja initialize_vec2をオーバライドしてsx::vec<float,2>を初期化する。 \endja 
		//virtual void initialize_vec2 (sxsdk::window_interface::vec2_control_class& vec2_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_vec3 to initialize the sx::vec<float,3> control. \enden  \ja initialize_vec3をオーバライドしてsx::vec<float,3>を初期化する。 \endja 
		//virtual void initialize_vec3 (sxsdk::window_interface::vec3_control_class& vec3_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_vec4 to initialize the sx::vec<float,4> control. \enden  \ja initialize_vec4をオーバライドしてsx::vec<float,4>を初期化する。 \endja 
		//virtual void initialize_vec4 (sxsdk::window_interface::vec4_control_class& vec4_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_quaternion to initialize the quaternion control. \enden  \ja initialize_quaternionをオーバライドしてクオタニオンを初期化する。 \endja 
		//virtual void initialize_quaternion (sxsdk::window_interface::quaternion_control_class& quaternion_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_matrix to initialize the sx::mat<float,4> control. \enden  \ja initialize_matrixをオーバライドしてマトリクスを初期化する。 \endja 
		//virtual void initialize_matrix (sxsdk::window_interface::matrix_control_class& matrix_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_scale to initialize the scale control. \enden  \ja initialize_scaleをオーバライドしてスケールを初期化する。 \endja 
		//virtual void initialize_scale (sxsdk::window_interface::scale_control_class& scale_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_static_text to initialize the static text control. \enden  \ja initialize_static_textをオーバライドしてスタティックテキストを初期化する。 \endja 
		//virtual void initialize_static_text (sxsdk::window_interface::static_text_class& static_text, void*) {
		//	do something...
		//}

		//  \en Override initialize_flasher to initialize the flasher control. \enden  \ja initialize_flasherをオーバライドしてフラッシャーを初期化する。 \endja 
		//virtual void initialize_flasher (sxsdk::window_interface::flasher_class& flasher, void*) {
		//	do something...
		//}

		//  \en Override setup_push_button to set up the push button. \enden  \ja setup_push_buttonをオーバライドしてプッシュボタンを設定する。 \endja 
		//virtual bool setup_push_button (sxsdk::window_interface::push_button_class& push_button, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_checkbox to set up the checkbox. \enden  \ja setup_checkboxをオーバライドしてチェックボックスを設定する。 \endja 
		//virtual bool setup_checkbox (sxsdk::window_interface::checkbox_class& checkbox, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_disclosure_button to set up the disclosure button. \enden  \ja setup_disclosure_buttonをオーバライドしてディスクロージャボタンを設定する。 \endja 
		//virtual bool setup_disclosure_button (sxsdk::window_interface::disclosure_button_class& disclosure_button, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_slider to set up the slider. \enden  \ja setup_sliderをオーバライドしてスライダを設定する。 \endja 
		//virtual bool setup_slider (sxsdk::window_interface::slider_class& slider, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_number to set up the number. \enden  \ja setup_numberをオーバライドしてナンバーを設定する。 \endja 
		//virtual bool setup_number (sxsdk::window_interface::number_class& number, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_popup_menu to set up the popup menu. \enden  \ja setup_popup_menuをオーバライドしてポップアップメニューを設定する。 \endja 
		//virtual bool setup_popup_menu (sxsdk::window_interface::popup_menu_class& popup_menu, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_color_disk to set up the color disk. \enden  \ja setup_color_diskをオーバライドしてカラーディスクを設定する。 \endja 
		//virtual bool setup_color_disk (sxsdk::window_interface::color_disk_class& color_disk, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_color_box to set up the color box. \enden  \ja setup_color_boxをオーバライドしてカラーボックスを設定する。 \endja 
		//virtual bool setup_color_box (sxsdk::window_interface::color_box_class& color_box, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_image_box to set up the image box. \enden  \ja setup_image_boxをオーバライドしてイメージボックスを設定する。 \endja 
		//virtual bool setup_image_box (sxsdk::window_interface::image_box_class& image_box, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_radio_button to set up the radio button. \enden  \ja setup_radio_buttonをオーバライドしてラジオボタンを設定する。 \endja 
		//virtual bool setup_radio_button (sxsdk::window_interface::radio_button_class& radio_button, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_vec2 to set up the sx::vec<float,2> control. \enden  \ja setup_vec2をオーバライドしてsx::vec<float,2>を設定する。 \endja 
		//virtual bool setup_vec2 (sxsdk::window_interface::vec2_control_class& vec2_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_vec3 to set up the sx::vec<float,3> control. \enden  \ja setup_vec3をオーバライドしてsx::vec<float,3>を設定する。 \endja 
		//virtual bool setup_vec3 (sxsdk::window_interface::vec3_control_class& vec3_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_vec4 to set up the sx::vec<float,4> control. \enden  \ja setup_vec4をオーバライドしてsx::vec<float,4>を設定する。 \endja 
		//virtual bool setup_vec4 (sxsdk::window_interface::vec4_control_class& vec4_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_quaternion to set up the quaternion control. \enden  \ja setup_quaternionをオーバライドしてクオタニオンを設定する。 \endja 
		//virtual bool setup_quaternion (sxsdk::window_interface::quaternion_control_class& quaternion_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_matrix to set up the sx::mat<float,4> control. \enden  \ja setup_matrixをオーバライドしてマトリクスを設定する。 \endja 
		//virtual bool setup_matrix (sxsdk::window_interface::matrix_control_class& matrix_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_scale to set up the scale control. \enden  \ja setup_scaleをオーバライドしてスケールを設定する。 \endja 
		//virtual bool setup_scale (sxsdk::window_interface::scale_control_class& scale_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_static_text to set up the static text control. \enden  \ja setup_static_textをオーバライドしてスタティックテキストを設定する。 \endja 
		//virtual bool setup_static_text (sxsdk::window_interface::static_text_class& static_text, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_flasher to set up the flasher control. \enden  \ja setup_flasherをオーバライドしてフラッシャーを設定する。 \endja 
		//virtual bool setup_flasher (sxsdk::window_interface::flasher_class& flasher, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override push_button_clicked to respond to the push button having been clicked. \enden  \ja push_button_clickedをオーバライドしてプッシュボタンのクリックに対応する。 \endja 
		//virtual void push_button_clicked (sxsdk::window_interface::push_button_class& push_button, void *) {
		//	do something...
		//}

		//  \en Override checkbox_value_changed to respond to the checkbox value having been changed. \enden  \ja checkbox_value_changedをオーバライドしてチェックボックスの値の変更に対応する。 \endja 
		//virtual void checkbox_value_changed (sxsdk::window_interface::checkbox_class& checkbox, void*) {
		//	do something...
		//}

		//  \en Override disclosure_button_value_changed to respond to the disclosure button value having been changed. \enden  \ja disclosure_button_value_changedをオーバライドしてディスクロージャボタンの値の変更に対応する。 \endja 
		//virtual void disclosure_button_value_changed (sxsdk::window_interface::disclosure_button_class& disclosure_button, void*) {
		//	do something...
		//}

		//  \en Override slider_value_changed to respond to the slider value having been changed. \enden  \ja slider_value_changedをオーバライドしてスライダの値の変更に対応する。 \endja 
		//virtual void slider_value_changed (sxsdk::window_interface::slider_class& slider, void*) {
		//	do something...
		//}

		//  \en Override number_value_changed to respond to the number value having been changed. \enden  \ja number_value_changedをオーバライドしてナンバーの値の変更に対応する。 \endja 
		//virtual void number_value_changed (sxsdk::window_interface::number_class& number, void*) {
		//	do something...
		//}

		//  \en Override popup_menu_value_changed to respond to the popup menu value having been changed. \enden  \ja popup_menu_value_changedをオーバライドしてポップアップメニューの値の変更に対応する。 \endja 
		//virtual void popup_menu_value_changed (sxsdk::window_interface::popup_menu_class& popup_menu, void*) {
		//	do something...
		//}

		//  \en Override color_disk_value_changed to respond to the color disk value having been changed. \enden  \ja color_disk_value_changedをオーバライドしてカラーディスクの値の変更に対応する。 \endja 
		//virtual void color_disk_value_changed (sxsdk::window_interface::color_disk_class& color_disk, void*) {
		//	do something...
		//}

		//  \en Override color_box_value_changed to respond to the color box value having been changed. \enden  \ja color_box_value_changedをオーバライドしてカラーボックスの値の変更に対応する。 \endja 
		//virtual void color_box_value_changed (sxsdk::window_interface::color_box_class& color_box, void*) {
		//	do something...
		//}

		//  \en Override image_box_image_changed to respond to the image having been changed. \enden  \ja image_box_image_changedをオーバライドしてイメージボックスのイメージの変更に対応する。 \endja 
		//virtual void image_box_image_changed (sxsdk::window_interface::image_box_class& image_box, void*) {
		//	do something...
		//}

		//  \en Override radio_button_value_changed to respond to the radio button value having been changed. \enden  \ja radio_button_value_changedをオーバライドしてラジオボタンの値の変更に対応する。 \endja 
		//virtual void radio_button_value_changed (sxsdk::window_interface::radio_button_class& radio_button, void*) {
		//	do something...
		//}

		//  \en Override tab_value_changed to respond to the tab value having been changed. \enden  \ja tab_value_changedをオーバライドしてタブの値の変更に対応する。 \endja 
		//virtual void tab_value_changed (sxsdk::window_interface::tab_class& tab, void*) {
		//	do something...
		//}

		//  \en Override vec2_value_changed to respond to the sx::vec<float,2> control value having been changed. \enden  \ja vec2_value_changedをオーバライドしてsx::vec<float,2>の値の変更に対応する。 \endja 
		//virtual void vec2_value_changed (sxsdk::window_interface::vec2_control_class& vec2_control, void*) {
		//	do something...
		//}

		//  \en Override vec3_value_changed to respond to the sx::vec<float,3> control value having been changed. \enden  \ja vec3_value_changedをオーバライドしてsx::vec<float,3>の値の変更に対応する。 \endja 
		//virtual void vec3_value_changed (sxsdk::window_interface::vec3_control_class& vec3_control, void*) {
		//	do something...
		//}

		//  \en Override vec4_value_changed to respond to the sx::vec<float,4> control value having been changed. \enden  \ja vec4_value_changedをオーバライドしてsx::vec<float,4>の値の変更に対応する。 \endja 
		//virtual void vec4_value_changed (sxsdk::window_interface::vec4_control_class& vec4_control, void*) {
		//	do something...
		//}

		//  \en Override quaternion_value_changed to respond to the quaternion control value having been changed. \enden  \ja quaternion_value_changedをオーバライドしてクオタニオンの値の変更に対応する。 \endja 
		//virtual void quaternion_value_changed (sxsdk::window_interface::quaternion_control_class& quaternion_control, void*) {
		//	do something...
		//}

		//  \en Override matrix_value_changed to respond to the sx::mat<float,4> control value having been changed. \enden  \ja matrix_value_changedをオーバライドしてマトリクスの値の変更に対応する。 \endja 
		//virtual void matrix_value_changed (sxsdk::window_interface::matrix_control_class& matrix_control, void*) {
		//	do something...
		//}

		//  \en Override scale_value_changed to respond to the scale control value having been changed. \enden  \ja scale_value_changedをオーバライドしてスケールの値の変更に対応する。 \endja 
		//virtual void scale_value_changed (sxsdk::window_interface::scale_control_class& scale_control, void*) {
		//	do something...
		//}
	};
}
//  \en This function gets called when the window is being initialized. \enden  \ja ウインドウの初期化時にこの関数が呼ばれる。 \endja 
void sxul_window::initialize (void *) {
	set_trigger(sxsdk::enums::active_scene_changed); //  \en Sets the event trigger so that controls are set up every time active scene changes. \enden  \ja アクティブシーンが変わるとコントロールが設定しなおされるように指定する。 \endja 
	load_sxul("simple_window"); //  \en Reads control definition from the resouce. \enden  \ja simple_window.sxulリソースファイルからコントロールの定義を読み込む。 \endja 
	set_client_rectangle(get_layout_bounds()); //  \en Adjusts window size to match the layout bounds set by load_sxu() call. \enden  \ja load_sxulの自動レイアウトで設定された境界矩形にウインドウサイズをあわせる。 \endja 
}

//  \en stock_window uses stock control classes. \enden  \ja 各種コントロールクラスのオブジェクトをそのまま使ったウインドウの例。 \endja 
namespace {
	class stock_window : public sxsdk::window_interface {
	public:
		explicit stock_window (sxsdk::shade_interface &shade) : sxsdk::window_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_WINDOW_SXUL_ID; }

		virtual void initialize (void *);

		//  \en Override initialize_push_button to initialize the push button. \enden  \ja initialize_push_buttonをオーバライドしてプッシュボタンを初期化する。 \endja 
		//virtual void initialize_push_button (sxsdk::window_interface::push_button_class& push_button, void*) {
		//	do something...
		//}


		//  \en Override initialize_checkbox to initialize the checkbox. \enden  \ja initialize_checkboxをオーバライドしてチェックボックスを初期化する。 \endja 
		//virtual void initialize_checkbox (sxsdk::window_interface::checkbox_class& checkbox, void*) {
		//	do something...
		//}

		//  \en Override initialize_disclosure_button to initialize the disclosure button. \enden  \ja initialize_disclosure_buttonをオーバライドしてディスクロージャボタンを初期化する。 \endja 
		//virtual void initialize_disclosure_button (sxsdk::window_interface::disclosure_button_class& disclosure_button, void*) {
		//	do something...
		//}

		//  \en Override initialize_slider to initialize the slider. \enden  \ja initialize_sliderをオーバライドしてスライダを初期化する。 \endja 
		//virtual void initialize_slider (sxsdk::window_interface::slider_class& slider, void*) {
		//	do something...
		//}

		//  \en Override initialize_number to initialize the number. \enden  \ja initialize_numberをオーバライドしてナンバーを初期化する。 \endja 
		//virtual void initialize_number (sxsdk::window_interface::number_class& number, void*) {
		//	do something...
		//}

		//  \en Override initialize_popup_menu to initialize the popup menu. \enden  \ja initialize_popup_menuをオーバライドしてポップアップメニューを初期化する。 \endja 
		//virtual void initialize_popup_menu (sxsdk::window_interface::popup_menu_class& popup_menu, void*) {
		//	do something...
		//}

		//  \en Override initialize_color_disk to initialize the color disk. \enden  \ja initialize_color_diskをオーバライドしてカラーディスクを初期化する。 \endja 
		//virtual void initialize_color_disk (sxsdk::window_interface::color_disk_class& color_disk, void*) {
		//	do something...
		//}

		//  \en Override initialize_color_box to initialize the color box. \enden  \ja initialize_color_boxをオーバライドしてカラーボックスを初期化する。 \endja 
		//virtual void initialize_color_box (sxsdk::window_interface::color_box_class& color_box, void*) {
		//	do something...
		//}

		//  \en Override initialize_image_box to initialize the image box. \enden  \ja initialize_image_boxをオーバライドしてイメージボックスを初期化する。 \endja 
		//virtual void initialize_image_box (sxsdk::window_interface::image_box_class& image_box, void*) {
		//	do something...
		//}

		//  \en Override initialize_radio_button to initialize the radio button. \enden  \ja initialize_radio_buttonをオーバライドしてラジオボタンを初期化する。 \endja 
		//virtual void initialize_radio_button (sxsdk::window_interface::radio_button_class& radio_button, void*) {
		//	do something...
		//}

		//  \en Override initialize_vec2 to initialize the sx::vec<float,2> control. \enden  \ja initialize_vec2をオーバライドしてsx::vec<float,2>を初期化する。 \endja 
		//virtual void initialize_vec2 (sxsdk::window_interface::vec2_control_class& vec2_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_vec3 to initialize the sx::vec<float,3> control. \enden  \ja initialize_vec3をオーバライドしてsx::vec<float,3>を初期化する。 \endja 
		//virtual void initialize_vec3 (sxsdk::window_interface::vec3_control_class& vec3_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_vec4 to initialize the sx::vec<float,4> control. \enden  \ja initialize_vec4をオーバライドしてsx::vec<float,4>を初期化する。 \endja 
		//virtual void initialize_vec4 (sxsdk::window_interface::vec4_control_class& vec4_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_quaternion to initialize the quaternion control. \enden  \ja initialize_quaternionをオーバライドしてクオタニオンを初期化する。 \endja 
		//virtual void initialize_quaternion (sxsdk::window_interface::quaternion_control_class& quaternion_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_matrix to initialize the sx::mat<float,4> control. \enden  \ja initialize_matrixをオーバライドしてマトリクスを初期化する。 \endja 
		//virtual void initialize_matrix (sxsdk::window_interface::matrix_control_class& matrix_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_scale to initialize the scale control. \enden  \ja initialize_scaleをオーバライドしてスケールを初期化する。 \endja 
		//virtual void initialize_scale (sxsdk::window_interface::scale_control_class& scale_control, void*) {
		//	do something...
		//}

		//  \en Override initialize_static_text to initialize the static text control. \enden  \ja initialize_static_textをオーバライドしてスタティックテキストを初期化する。 \endja 
		//virtual void initialize_static_text (sxsdk::window_interface::static_text_class& static_text, void*) {
		//	do something...
		//}

		//  \en Override initialize_flasher to initialize the flasher control. \enden  \ja initialize_flasherをオーバライドしてフラッシャーを初期化する。 \endja 
		//virtual void initialize_flasher (sxsdk::window_interface::flasher_class& flasher, void*) {
		//	do something...
		//}

		//  \en Override setup_push_button to set up the push button. \enden  \ja setup_push_buttonをオーバライドしてプッシュボタンを設定する。 \endja 
		//virtual bool setup_push_button (sxsdk::window_interface::push_button_class& push_button, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_checkbox to set up the checkbox. \enden  \ja setup_checkboxをオーバライドしてチェックボックスを設定する。 \endja 
		//virtual bool setup_checkbox (sxsdk::window_interface::checkbox_class& checkbox, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_disclosure_button to set up the disclosure button. \enden  \ja setup_disclosure_buttonをオーバライドしてディスクロージャボタンを設定する。 \endja 
		//virtual bool setup_disclosure_button (sxsdk::window_interface::disclosure_button_class& disclosure_button, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_slider to set up the slider. \enden  \ja setup_sliderをオーバライドしてスライダを設定する。 \endja 
		//virtual bool setup_slider (sxsdk::window_interface::slider_class& slider, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_number to set up the number. \enden  \ja setup_numberをオーバライドしてナンバーを設定する。 \endja 
		//virtual bool setup_number (sxsdk::window_interface::number_class& number, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_popup_menu to set up the popup menu. \enden  \ja setup_popup_menuをオーバライドしてポップアップメニューを設定する。 \endja 
		//virtual bool setup_popup_menu (sxsdk::window_interface::popup_menu_class& popup_menu, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_color_disk to set up the color disk. \enden  \ja setup_color_diskをオーバライドしてカラーディスクを設定する。 \endja 
		//virtual bool setup_color_disk (sxsdk::window_interface::color_disk_class& color_disk, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_color_box to set up the color box. \enden  \ja setup_color_boxをオーバライドしてカラーボックスを設定する。 \endja 
		//virtual bool setup_color_box (sxsdk::window_interface::color_box_class& color_box, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_image_box to set up the image box. \enden  \ja setup_image_boxをオーバライドしてイメージボックスを設定する。 \endja 
		//virtual bool setup_image_box (sxsdk::window_interface::image_box_class& image_box, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_radio_button to set up the radio button. \enden  \ja setup_radio_buttonをオーバライドしてラジオボタンを設定する。 \endja 
		//virtual bool setup_radio_button (sxsdk::window_interface::radio_button_class& radio_button, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_vec2 to set up the sx::vec<float,2> control. \enden  \ja setup_vec2をオーバライドしてsx::vec<float,2>を設定する。 \endja 
		//virtual bool setup_vec2 (sxsdk::window_interface::vec2_control_class& vec2_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_vec3 to set up the sx::vec<float,3> control. \enden  \ja setup_vec3をオーバライドしてsx::vec<float,3>を設定する。 \endja 
		//virtual bool setup_vec3 (sxsdk::window_interface::vec3_control_class& vec3_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_vec4 to set up the sx::vec<float,4> control. \enden  \ja setup_vec4をオーバライドしてsx::vec<float,4>を設定する。 \endja 
		//virtual bool setup_vec4 (sxsdk::window_interface::vec4_control_class& vec4_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_quaternion to set up the quaternion control. \enden  \ja setup_quaternionをオーバライドしてクオタニオンを設定する。 \endja 
		//virtual bool setup_quaternion (sxsdk::window_interface::quaternion_control_class& quaternion_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_matrix to set up the sx::mat<float,4> control. \enden  \ja setup_matrixをオーバライドしてマトリクスを設定する。 \endja 
		//virtual bool setup_matrix (sxsdk::window_interface::matrix_control_class& matrix_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_scale to set up the scale control. \enden  \ja setup_scaleをオーバライドしてスケールを設定する。 \endja 
		//virtual bool setup_scale (sxsdk::window_interface::scale_control_class& scale_control, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_static_text to set up the static text control. \enden  \ja setup_static_textをオーバライドしてスタティックテキストを設定する。 \endja 
		//virtual bool setup_static_text (sxsdk::window_interface::static_text_class& static_text, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override setup_flasher to set up the flasher control. \enden  \ja setup_flasherをオーバライドしてフラッシャーを設定する。 \endja 
		//virtual bool setup_flasher (sxsdk::window_interface::flasher_class& flasher, void*) {
		//	do something...
		//	return true;
		//}

		//  \en Override push_button_clicked to respond to the push button having been clicked. \enden  \ja push_button_clickedをオーバライドしてプッシュボタンのクリックに対応する。 \endja 
		//virtual void push_button_clicked (sxsdk::window_interface::push_button_class& push_button, void *) {
		//	do something...
		//}

		//  \en Override checkbox_value_changed to respond to the checkbox value having been changed. \enden  \ja checkbox_value_changedをオーバライドしてチェックボックスの値の変更に対応する。 \endja 
		//virtual void checkbox_value_changed (sxsdk::window_interface::checkbox_class& checkbox, void*) {
		//	do something...
		//}

		//  \en Override disclosure_button_value_changed to respond to the disclosure button value having been changed. \enden  \ja disclosure_button_value_changedをオーバライドしてディスクロージャボタンの値の変更に対応する。 \endja 
		//virtual void disclosure_button_value_changed (sxsdk::window_interface::disclosure_button_class& disclosure_button, void*) {
		//	do something...
		//}

		//  \en Override slider_value_changed to respond to the slider value having been changed. \enden  \ja slider_value_changedをオーバライドしてスライダの値の変更に対応する。 \endja 
		//virtual void slider_value_changed (sxsdk::window_interface::slider_class& slider, void*) {
		//	do something...
		//}

		//  \en Override number_value_changed to respond to the number value having been changed. \enden  \ja number_value_changedをオーバライドしてナンバーの値の変更に対応する。 \endja 
		//virtual void number_value_changed (sxsdk::window_interface::number_class& number, void*) {
		//	do something...
		//}

		//  \en Override popup_menu_value_changed to respond to the popup menu value having been changed. \enden  \ja popup_menu_value_changedをオーバライドしてポップアップメニューの値の変更に対応する。 \endja 
		//virtual void popup_menu_value_changed (sxsdk::window_interface::popup_menu_class& popup_menu, void*) {
		//	do something...
		//}

		//  \en Override color_disk_value_changed to respond to the color disk value having been changed. \enden  \ja color_disk_value_changedをオーバライドしてカラーディスクの値の変更に対応する。 \endja 
		//virtual void color_disk_value_changed (sxsdk::window_interface::color_disk_class& color_disk, void*) {
		//	do something...
		//}

		//  \en Override color_box_value_changed to respond to the color box value having been changed. \enden  \ja color_box_value_changedをオーバライドしてカラーボックスの値の変更に対応する。 \endja 
		//virtual void color_box_value_changed (sxsdk::window_interface::color_box_class& color_box, void*) {
		//	do something...
		//}

		//  \en Override image_box_image_changed to respond to the image having been changed. \enden  \ja image_box_image_changedをオーバライドしてイメージボックスのイメージの変更に対応する。 \endja 
		//virtual void image_box_image_changed (sxsdk::window_interface::image_box_class& image_box, void*) {
		//	do something...
		//}

		//  \en Override radio_button_value_changed to respond to the radio button value having been changed. \enden  \ja radio_button_value_changedをオーバライドしてラジオボタンの値の変更に対応する。 \endja 
		//virtual void radio_button_value_changed (sxsdk::window_interface::radio_button_class& radio_button, void*) {
		//	do something...
		//}

		//  \en Override tab_value_changed to respond to the tab value having been changed. \enden  \ja tab_value_changedをオーバライドしてタブの値の変更に対応する。 \endja 
		//virtual void tab_value_changed (sxsdk::window_interface::tab_class& tab, void*) {
		//	do something...
		//}

		//  \en Override vec2_value_changed to respond to the sx::vec<float,2> control value having been changed. \enden  \ja vec2_value_changedをオーバライドしてsx::vec<float,2>の値の変更に対応する。 \endja 
		//virtual void vec2_value_changed (sxsdk::window_interface::vec2_control_class& vec2_control, void*) {
		//	do something...
		//}

		//  \en Override vec3_value_changed to respond to the sx::vec<float,3> control value having been changed. \enden  \ja vec3_value_changedをオーバライドしてsx::vec<float,3>の値の変更に対応する。 \endja 
		//virtual void vec3_value_changed (sxsdk::window_interface::vec3_control_class& vec3_control, void*) {
		//	do something...
		//}

		//  \en Override vec4_value_changed to respond to the sx::vec<float,4> control value having been changed. \enden  \ja vec4_value_changedをオーバライドしてsx::vec<float,4>の値の変更に対応する。 \endja 
		//virtual void vec4_value_changed (sxsdk::window_interface::vec4_control_class& vec4_control, void*) {
		//	do something...
		//}

		//  \en Override quaternion_value_changed to respond to the quaternion control value having been changed. \enden  \ja quaternion_value_changedをオーバライドしてクオタニオンの値の変更に対応する。 \endja 
		//virtual void quaternion_value_changed (sxsdk::window_interface::quaternion_control_class& quaternion_control, void*) {
		//	do something...
		//}

		//  \en Override matrix_value_changed to respond to the sx::mat<float,4> control value having been changed. \enden  \ja matrix_value_changedをオーバライドしてマトリクスの値の変更に対応する。 \endja 
		//virtual void matrix_value_changed (sxsdk::window_interface::matrix_control_class& matrix_control, void*) {
		//	do something...
		//}

		//  \en Override scale_value_changed to respond to the scale control value having been changed. \enden  \ja scale_value_changedをオーバライドしてスケールの値の変更に対応する。 \endja 
		//virtual void scale_value_changed (sxsdk::window_interface::scale_control_class& scale_control, void*) {
		//	do something...
		//}
	};
}
//  \en This function gets called when the window is being initialized. \enden  \ja ウインドウの初期化時にこの関数が呼ばれる。 \endja 
void stock_window::initialize (void *) {
	set_client_size(sx::vec<int,2>(600, 600));
	set_trigger(sxsdk::enums::active_scene_changed); //  \en Sets the event trigger so that controls are set up every time active scene changes. \enden  \ja アクティブシーンが変わるとコントロールが設定しなおされるように指定する。 \endja 
	new push_button_class(*this, 0, 0, 0, 0, 0, "Push button");
	{	compointer<sxsdk::image_interface> image(shade.create_image_interface("simple_window_image"));
		(new push_button_class(*this, 0, 0, sxsdk::window_interface::next, 32, 32, ""))->set_image(*image);
	}
	new image_box_class(*this, 0, 0, sxsdk::window_interface::next, 32, 32);
	new checkbox_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0, "Checkbox");
	new radio_button_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0, "Radio 0|Radio 1|Radio 2");
	new popup_menu_class(*this, 0, 100, sxsdk::window_interface::next, "Popup", 60, "Menu 0|Menu 1|Menu 2");
	new popup_menu_class(*this, 0, 100, sxsdk::window_interface::next, "Popup with stepper", 60, "Menu 0|Menu 1|Menu 2");
	new static_text_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0, "Static text");
	(new number_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Number (integer)"))->set_integer();
	new number_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Number (real)");
	new slider_class(*this, 0, 100, sxsdk::window_interface::next, 100, false, "Slider", false);
	new scale_control_class(*this, 0, 100, sxsdk::window_interface::next, "Scale");
	new color_box_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0);
	new color_disk_class(*this, 0, 0, sxsdk::window_interface::next);
	new vec2_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Vec2");
	new vec3_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Vec3");
	new vec4_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Vec4");
	new quaternion_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Quaternion");
	new matrix_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Matrix");
	new disclosure_button_class(*this, 0, 0, sxsdk::window_interface::next);
	new flasher_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0);
	table_control_class *table = new table_control_class(*this, 0, 0, sxsdk::window_interface::next, 400, 100);
	if (table) {
		table->insert_column(table_bool_type_flag, 30, "bool");
		table->insert_column(table_int_type_flag, 50, "int");
		table->insert_column(table_float_type_flag, 100, "float");
		table->insert_column(table_string_type_flag, 100, "string");
		table->insert_column(table_color_type_flag, 50, "color");
		table->insert_row();
		table->insert_row();
		table->insert_row();
		table->set_bool_value(0, 0, true);
		table->set_bool_value(1, 0, false);
		table->set_bool_value(2, 0, true);
		table->set_int_value(0, 1, -1234);
		table->set_int_value(1, 1, 0);
		table->set_int_value(2, 1, 1234);
		table->set_float_value(0, 2, -1.234);
		table->set_float_value(1, 2, 0.0);
		table->set_float_value(2, 2, 1.210034);
		table->set_string_value(0, 3, "string0");
		table->set_string_value(1, 3, "string1");
		table->set_string_value(2, 3, "string2");
		table->set_color_value(0, 4, sx::rgb<float>(1.0, 0.0, 0.0));
		table->set_color_value(1, 4, sx::rgb<float>(0.0, 1.0, 0.0));
		table->set_color_value(2, 4, sx::rgb<float>(0.0, 0.0, 1.0));
	}
}

//  \en custom_window uses customized control classes. \enden  \ja 各種コントロールクラスをカスタマイズしたオブジェクトを使ったウインドウの例。 \endja 
namespace {
	class custom_window : public sxsdk::window_interface {
	public:
		explicit custom_window (sxsdk::shade_interface &shade) : sxsdk::window_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_WINDOW_SXUL_ID; }

		virtual void initialize (void *);
	};
}
//  \en This function gets called when the window is being initialized. \enden  \ja ウインドウの初期化時にこの関数が呼ばれる。 \endja 
void custom_window::initialize (void *) {
	set_client_size(sx::vec<int,2>(600, 600));
	set_trigger(sxsdk::enums::active_scene_changed); //  \en Sets the event trigger so that controls are set up every time active scene changes. \enden  \ja アクティブシーンが変わるとコントロールが設定しなおされるように指定する。 \endja 
	
	class custom_push_button_class : public push_button_class {
	public:
		custom_push_button_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : push_button_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the push button. \enden  \ja setupをオーバライドしてプッシュボタンを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override clicked to respond to the push button having been clicked. \enden  \ja clickedをオーバライドしてプッシュボタンのクリックに対応する。 \endja 
		//virtual void clicked ( int key_flags, void*) {
		//	do something...
		//}
	};
	
	class custom_image_box_class : public image_box_class {
	public:
		custom_image_box_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy) : image_box_class(w, control_id, x, y, dx, dy) { }
	private:
		//  \en Override setup to set up the image box. \enden  \ja setupをオーバライドしてイメージボックスを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}
	};
	
	class custom_checkbox_class : public checkbox_class {
	public:
		custom_checkbox_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : checkbox_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the checkbox. \enden  \ja setupをオーバライドしてチェックボックスを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the checkbox value having been changed. \enden  \ja value_changedをオーバライドしてチェックボックスの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_radio_button_class : public radio_button_class {
	public:
		custom_radio_button_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : radio_button_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the radio button. \enden  \ja setupをオーバライドしてラジオボタンを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the radio button value having been changed. \enden  \ja value_changedをオーバライドしてラジオボタンの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_popup_menu_class : public popup_menu_class {
	public:
		custom_popup_menu_class (sxsdk::window_interface &w, int control_id, int x, int y, const char *title, int width, const char*items) : popup_menu_class(w, control_id, x, y, title, width, items) { }
	private:
		//  \en Override setup to set up the popup menu. \enden  \ja setupをオーバライドしてポップアップメニューを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the popup menu value having been changed. \enden  \ja value_changedをオーバライドしてポップアップメニューの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	

	class custom_editable_text_class : public editable_text_class {
	public:
		custom_editable_text_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : editable_text_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the editable text. \enden  \ja setupをオーバライドしてテキストコントロールを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}
	};

	class custom_static_text_class : public static_text_class {
	public:
		custom_static_text_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : static_text_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the static text. \enden  \ja setupをオーバライドしてスタティックテキストを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}
	};
	
	class custom_number_class : public number_class {
	public:
		custom_number_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : number_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the number control. \enden  \ja setupをオーバライドしてナンバーを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the number control value having been changed. \enden  \ja value_changedをオーバライドしてナンバーの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_slider_class : public slider_class {
	public:
		custom_slider_class (sxsdk::window_interface &w, int control_id, int x, int y, int size, bool vertical, const char *title, bool show_marks) : slider_class(w, control_id, x, y, size, vertical, title, show_marks) { }
	private:
		//  \en Override setup to set up the slider. \enden  \ja setupをオーバライドしてスライダを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the slider value having been changed. \enden  \ja value_changedをオーバライドしてスライダの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_scale_control_class : public scale_control_class {
	public:
		custom_scale_control_class (sxsdk::window_interface &w, int control_id, int x, int y, const char *title) : scale_control_class(w, control_id, x, y, title) { }
	private:
		//  \en Override setup to set up the scale control. \enden  \ja setupをオーバライドしてスケールを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the scale control value having been changed. \enden  \ja value_changedをオーバライドしてスケールの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_color_box_class : public color_box_class {
	public:
		custom_color_box_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy) : color_box_class(w, control_id, x, y, dx, dy) { }
	private:
		//  \en Override setup to set up the color box. \enden  \ja setupをオーバライドしてカラーボックスを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the color box value having been changed. \enden  \ja value_changedをオーバライドしてカラーボックスの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_color_disk_class : public color_disk_class {
	public:
		custom_color_disk_class (sxsdk::window_interface &w, int control_id, int x, int y) : color_disk_class(w, control_id, x, y) { }
	private:
		//  \en Override setup to set up the color disk. \enden  \ja setupをオーバライドしてカラーディスクを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the color disk value having been changed. \enden  \ja value_changedをオーバライドしてカラーディスクの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_vec2_control_class : public vec2_control_class {
	public:
		custom_vec2_control_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : vec2_control_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the sx::vec<float,2> control. \enden  \ja setupをオーバライドしてsx::vec<float,2>を設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the sx::vec<float,2> control value having been changed. \enden  \ja value_changedをオーバライドしてチェックボックスの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_vec3_control_class : public vec3_control_class {
	public:
		custom_vec3_control_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : vec3_control_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the sx::vec<float,3> control. \enden  \ja setupをオーバライドしてsx::vec<float,3>を設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the sx::vec<float,3> control value having been changed. \enden  \ja value_changedをオーバライドしてsx::vec<float,3>の値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_vec4_control_class : public vec4_control_class {
	public:
		custom_vec4_control_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : vec4_control_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the sx::vec<float,4> control. \enden  \ja setupをオーバライドしてsx::vec<float,4>を設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the sx::vec<float,4> control value having been changed. \enden  \ja value_changedをオーバライドしてsx::vec<float,4>の値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_quaternion_control_class : public quaternion_control_class {
	public:
		custom_quaternion_control_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : quaternion_control_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the quaternion control. \enden  \ja setupをオーバライドしてクオタニオンを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the quaternion control value having been changed. \enden  \ja value_changedをオーバライドしてクオタニオンの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_matrix_control_class : public matrix_control_class {
	public:
		custom_matrix_control_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title) : matrix_control_class(w, control_id, x, y, dx, dy, title) { }
	private:
		//  \en Override setup to set up the sx::mat<float,4> control. \enden  \ja setupをオーバライドしてマトリクスを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the sx::mat<float,4> control value having been changed. \enden  \ja value_changedをオーバライドしてマトリクスの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_disclosure_button_class : public disclosure_button_class {
	public:
		custom_disclosure_button_class (sxsdk::window_interface &w, int control_id, int x, int y, bool reversed = false) : disclosure_button_class(w, control_id, x, y, reversed) { }
	private:
		//  \en Override setup to set up the disclosure button. \enden  \ja setupをオーバライドしてディスクロージャボタンを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}

		//  \en Override value_changed to respond to the disclosure button value having been changed. \enden  \ja value_changedをオーバライドしててディスクロージャボタンの値の変更に対応する。 \endja 
		//virtual void value_changed (int key_flags, void *) {
		//	do something...
		//}
	};
	
	class custom_flasher_class : public flasher_class {
	public:
		custom_flasher_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy) : flasher_class(w, control_id, x, y, dx, dy) { }
	private:
		//  \en Override setup to set up the flasher. \enden  \ja setupをオーバライドしてフラッシャーを設定する。 \endja 
		//virtual bool setup (void *) {
		//	do something...
		//	return true;
		//}
	};

	class custom_table_control_class : public table_control_class {
	public:
		explicit custom_table_control_class (sxsdk::window_interface &w, int control_id, int x, int y, int dx, int dy) : table_control_class(w, control_id, x, y, dx, dy) { }
		virtual bool setup (void *) {
			std::cout << "testwindowtable_control " << get_control_id() << " " << "setup" << std::endl;
			return false;
		}
	};

	new custom_push_button_class(*this, 0, 0, 0, 0, 0, "Push button");
	{	compointer<sxsdk::image_interface> image(shade.create_image_interface("simple_window_image"));
		(new custom_push_button_class(*this, 0, 0, sxsdk::window_interface::next, 32, 32, ""))->set_image(*image);
	}
	new custom_image_box_class(*this, 0, 0, sxsdk::window_interface::next, 32, 32);
	new custom_checkbox_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0, "Checkbox");
	new custom_radio_button_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0, "Radio 0|Radio 1|Radio 2");
	new custom_popup_menu_class(*this, 0, 100, sxsdk::window_interface::next, "Popup", 60, "Menu 0|Menu 1|Menu 2");
	new custom_popup_menu_class(*this, 0, 100, sxsdk::window_interface::next, "Popup with stepper", 60, "Menu 0|Menu 1|Menu 2");
	new custom_static_text_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0, "Static text");
	(new custom_number_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Number (integer)"))->set_integer();
	new custom_number_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Number (real)");
	new custom_slider_class(*this, 0, 100, sxsdk::window_interface::next, 100, false, "Slider", false);
	new custom_scale_control_class(*this, 0, 100, sxsdk::window_interface::next, "Scale");
	new custom_color_box_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0);
	new custom_color_disk_class(*this, 0, 0, sxsdk::window_interface::next);
	new custom_vec2_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Vec2");
	new custom_vec3_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Vec3");
	new custom_vec4_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Vec4");
	new custom_quaternion_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Quaternion");
	new custom_matrix_control_class(*this, 0, 100, sxsdk::window_interface::next, 0, 0, "Matrix");
	new custom_disclosure_button_class(*this, 0, 0, sxsdk::window_interface::next);
	new custom_flasher_class(*this, 0, 0, sxsdk::window_interface::next, 0, 0);
	custom_table_control_class *table = new custom_table_control_class(*this, 0, 0, sxsdk::window_interface::next, 100, 50);
	if (table) {
		table->insert_column(table_none_type_flag, 100, "Column0");
		table->insert_column(table_none_type_flag, 100, "Column1");
		table->insert_column(table_none_type_flag, 100, "Column2");
		table->insert_row();
		table->insert_row();
	}
	new custom_editable_text_class(*this, 0, 100, 0, 100, 0, "Editable text");

	class subwindow_class : public sxsdk::window_interface {
	public:
		explicit subwindow_class (sxsdk::window_interface &parent) : sxsdk::window_interface(parent, sx::hv_scroll_bar) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual bool mouse_down (int button, sx::vec<int,2> p, int key_down, int time, bool double_click, void *) {
			shade.message("mouse_down");
			return true;
		}
		virtual void paint (sxsdk::graphic_context_interface &gc, const sx::bounds<sx::vec<int,2> > *visible_rectangle, void *) {
			clear(gc);
			gc.begin_path();
			gc.move_to(0.5f, 0.5f); gc.line_to(399.5f, 399.5f);
			gc.move_to(200.5f, 0.5f); gc.line_to(599.5f, 399.5f);
			gc.move_to(399.5f, 0.5f); gc.line_to(0.5f, 399.5f);
			gc.move_to(599.5f, 0.5f); gc.line_to(200.5f, 399.5f);
			gc.end_path();

		}
		virtual void scrolled (sx::vec<int,2> offset, void *) {
			shade.message("scrolled");
		}
	};
	subwindow_class *subwindow = new subwindow_class(*this);
	subwindow->set_frame_rectangle(sx::bounds<sx::vec<int,2> >(240,40,440,240));
	subwindow->set_canvas_size(sx::vec<int,2>(400, 400));
	subwindow->set_horizontal_line_scroll(100);
}

SXPLUGINNAMESPACEBEGIN(test_window)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		sxsdk::window_interface *u = 0;
		switch (i) {
		case 0:	u = new inmemorysxul_window(*shade); break;
		case 1:	u = new sxul_window(*shade); break;
		case 2:	u = new stock_window(*shade); break;
		case 3:	u = new custom_window(*shade); break;
		}
		if (u) {
			u->AddRef();
			*p = (void *)u;
		}
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == window_iid) return 4;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		switch (i) {
		case 0:	return "window (inmemorysxul)";
		case 1:	return "window (sxul)";
		case 2:	return "window (stock)";
		case 3:	return "window (custom)";
		}
		return 0;
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		switch (i) {
		case 0:	return SIMPLE_WINDOW_INMEMORYSXUL_ID;
		case 1:	return SIMPLE_WINDOW_SXUL_ID;
		case 2:	return SIMPLE_WINDOW_STOCK_ID;
		case 3:	return SIMPLE_WINDOW_CUSTOM_ID;
		}
		return sx::uuid_class(0u);
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &, int, void *) {
		return true;
	}
SXPLUGINNAMESPACEEND
