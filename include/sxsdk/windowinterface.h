#pragma once


#if _MSC_VER
	#pragma warning(push)
	#pragma warning(disable:4355)
#endif

// error C2653: 'toolboxview' : is not a class or namespace name windowinterface.hpp 395
namespace toolboxview {
	class view_class;
}

namespace sxsdk {
	class window_interface : public plugin_interface {
	public:
		/// \en Constant values used for positioning controls.\enden \ja コントロールの位置を設定する定数。\endja 
		enum positioning_enum { same = 0x10000000, next = 0x20000000 }; 
		/// \en Constant values for specifying how the window should be invoked or where it should be embedded.\enden \ja ウインドウを表示するメニューアイテムをどこに設定するか、およびウインドウをどこに埋め込むかを指定するフラグ。\endja 
		enum placement_enum { 
		/// \en The window should be invoked from the View menu.\enden \ja 表示メニューからウインドウを表示する。\endja 
			view_menu_placement_flag = 0x01, 
		/// \en The window should be invoked from the Browser context menu.\enden \ja ブラウザコンテクストメニューからウインドウを表示する。\endja 
			browser_placement_flag = 0x02, 
		/// \en The window should be invoked from the Image popup menu.\enden \ja イメージコンテクストメニューからウインドウを表示する。\endja 
			image_placement_flag = 0x04, 
		/// \en The window should be invoked from the Motion popup menu.\enden \ja モーション設定コンテクストメニューからウインドウを表示する。\endja 
			motion_placement_flag = 0x08, 
		/// \en The window should be embedded in the browser window.\enden \ja ウインドウをブラウザウインドウに埋め込む。\endja 
			browser_embedment_flag = 0x010000, 
		/// \en The window should be embedded in the image window.\enden \ja ウインドウをイメージウインドウに埋め込む。\endja 
			image_embedment_flag = 0x020000, 
		/// \en The window should be embedded in the motion window.\enden \ja ウインドウをモーション設定ウインドウに埋め込む。\endja 
			motion_embedment_flag = 0x040000, 
		/// \en The window should be embedded in the controlbar window. \enden \ja ウインドウをコントロールバーに埋め込む。\endja 
			controlbar_embedment_flag = 0x080000, 
		}; 
		/// \en Flags used for set down part of window control. \enden \ja ウインドウコントロールの配色を取得する際のパートを指定するフラグ。\endja 
		enum window_theme_enum { 
		/// \en The background of windows.\enden \ja ウインドウ背景。\endja 
			theme_background_flag, 
		/// \en The top of control faces.\enden \ja コントロールのグラデーション上部。\endja 
			theme_face_top_flag, 
		/// \en The bottom of control faces.\enden \ja コントロールのグラデーション下部。\endja 
			theme_face_bottom_flag, 
		/// \en The highlight of controls.\enden \ja コントロールのハイライト。\endja 
			theme_highlight_flag, 
		/// \en The shadow of controls.\enden \ja コントロールの影。\endja 
			theme_shadow_flag, 
		/// \en The white space of radio button and checkbox.\enden \ja ラジオボタンとチェックボックスの空白部分。\endja 
			theme_white_space_flag, 
		/// \en The active text.\enden \ja アクティブテキスト。\endja 
			theme_active_text_flag, 
		/// \en The inactive text. \enden \ja 非アクティブテキスト。\endja 
			theme_inactive_text_flag, 
		/// \en The selected text. \enden \ja 選択されたテキスト。\endja 
			theme_selected_text_flag, 
		/// \en The number box.\enden \ja 数値入力ボックス。\endja 
			theme_number_box_flag, 
		/// \en The mouseover.\enden \ja マウスオーバー。\endja 
			theme_mouseover_flag, 
		/// \en The selected controls. \enden \ja 選択されたコントロール。\endja 
			theme_selected_flag, 
		/// \en The background of dialog. \enden \ja ダイアログの背景色。\endja 
			theme_dialog_background_flag, 
		}; 
		/// \en Flags used for set down cell type of table control. \enden \ja テーブルコントロールのセルのタイプを指定するフラグ。\endja 
		enum table_cell_type_enum { 
		/// \en The none type.\enden \ja 空白タイプ。\endja 
			table_none_type_flag = 0, 
		/// \en The check box type.\enden \ja チェックボックスタイプ。\endja 
			table_bool_type_flag = 1, 
		/// \en The integer box type.\enden \ja 整数値タイプ。\endja 
			table_int_type_flag = 2, 
		/// \en The float type.\enden \ja 浮動小数点値タイプ。\endja 
			table_float_type_flag = 3, 
		/// \en The string type.\enden \ja 文字列タイプ。\endja 
			table_string_type_flag = 4, 
		/// \en The color type.\enden \ja カラータイプ。\endja 
			table_color_type_flag = 5, 
		/// \en The path type.\enden \ja パスタイプ（文字列タイプだが表示する際にパスからファイル名を抜き出して表示する）。\endja 
			table_path_type_flag = 6, 
		/// \en The time type.\enden \ja 時間タイプ（整数値タイプだが表示する際にHH:MM:SS形式にして表示する）。\endja 
			table_time_type_flag = 7, 
		}; 
		/// \en Flags used for set down cell type of table style flags. \enden \ja テーブルコントロールのスタイルを指定するフラグ。\endja 
		enum table_style_enum { 
		/// \en The flag of drawing row border.\enden \ja 横罫線表示のフラグ。\endja 
			table_style_row_border_flag = 0x0001, 
		/// \en The flag of drawing column border.\enden \ja 縦罫線表示のフラグ。\endja 
			table_style_column_border_flag = 0x0002, 
		/// \en The flag of header row visibility.\enden \ja ヘッダー非表示のフラグ。\endja 
			table_style_header_hidden = 0x0004,
		/// \en The flag of single row selection.\enden \ja 単一行選択のフラグ。\endja 
			table_style_single_row_selection = 0x0008,
		}; 
		/// \en Flags used for editting of table style flags. \enden \ja テーブルコントロールのスタイルの指定方法。\endja 
		enum table_style_set_enum {
		/// \en Clear the flags of the input.\enden \ja 指定の値のフラグをクリアする。\endja 
			table_style_off = 0,
		/// \en Set the flags of the input.\enden \ja 指定の値のフラグをセットする。\endja 
			table_style_on  = 1,
		/// \en Replace all flags with the input.\enden \ja フラグ全体を指定値に置き換える。\endja 
			table_style_replace = 2,
		/// \en Toggle flags of the input.\enden \ja 指定の値のフラグをトグルする。\endja 
			tabel_style_toggle = 3,
		};
			class mouse_tracker_class : public unknown_interface {
		public:
			window_interface &w;
			sx::mouse_tracker_class &mouse_tracker;

			virtual ~mouse_tracker_class () { }
	mouse_tracker_class ( window_interface &w, const sx::vec<int,2> &where ) : w(w), mouse_tracker(w.create_mouse_tracker(this, where)) { w.set_handler(mouse_tracker, *this); } // -1
	virtual void mouse_move ( sx::vec<int,2> p ) { } // -1
	virtual void idle () { } // -1
	virtual void mouse_release () { } // -1
		};

		class control_base_class : public handler_interface {
		public:
			window_interface *w;
			xshade::control::control_class &c;

			explicit control_base_class (window_interface &w, xshade::control::control_class &c) : w(&w), c(c) { w.set_handler(c, *this); }
	virtual void delete_self ( void * = 0 ) { w->delete_control(c); } // -1
	int get_shade_version () const { return get_shade_build_number(); } // -1
	int get_control_id () const { return w->get_control_id(c); } // -1
	const char* get_control_idname () const { return w->get_control_idname(c); } // -1
	void set_image ( image_interface &image ) { w->set_image(c, image); } // -1
	void set_popup_menu ( image_interface &image ) { w->set_image(c, image); } // deprecated. replaced by set_items. // -1
	void set_help_tag ( const char *s ) { w->set_tooltip(c, s); } // -1
	void set_tooltip ( const char *s ) { w->set_tooltip(c, s); } // -1
	void set_active ( bool active ) { w->set_active(c, active); } // -1
	bool get_active () const { return w->get_active(c); } // -1
	void invalidate () { w->invalidate_control(c); } // -1
	void show () { w->show_control(c); } // -1
	void hide () { w->hide_control(c); } // -1
	sx::vec<int,2> get_position () const { return w->get_position(c); } // -1
	void set_position ( const sx::vec<int,2> &position ) { w->set_position(c, position); } // -1
	sx::vec<int,2> get_size () const { return w->get_size(c); } // -1
	void set_size ( const sx::vec<int,2> &size ) { w->set_size(c, size); } // -1
	const char* get_title () const { return w->get_title(c); } // -1
	void set_title ( const char *title ) { w->set_title(c, title); } // -1
	void set_items ( const char *items ) { w->set_items(c, items); } // -1
	void set_bounds ( const sx::rectangle_class &bounds ) { w->set_bounds(c, bounds); } // -1
	sx::rectangle_class get_bounds () const { return w->get_bounds(c); } // -1
	sx::rectangle_class get_bounding_rectangle () const { return w->get_bounds(c); } // -1
	int get_title_width () const { return w->get_title_width(c); } // -1
	bool select_control ( bool select = true, bool invalidate_flag = true ) { return w->select(c, select, invalidate_flag); } // -1
	int get_focused () const { return w->get_focused(c); } // -1
		};

		class push_button_class : public control_base_class {
		public:
			plugin_push_button_class &c;

	push_button_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char*title ) : control_base_class(w, (xshade::control::control_class &)w.create_button(*this, control_id, x, y, dx, dy, title)), c((plugin_push_button_class &)control_base_class::c) { } // -1
	int get_value () const { return w->get_button_int_value(c); } // -1
		};

		class checkbox_class : public control_base_class {
		public:
			plugin_checkbox_class &c;

	checkbox_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char*title ) : control_base_class(w, (xshade::control::control_class &)w.create_check_box(*this, control_id, x, y, dx, dy, title)), c((plugin_checkbox_class &)control_base_class::c) { } // -1
	checkbox_class& set_value ( int i ) { w->set_check_box_int_value(c, i); return *this; } // -1
	int get_value () const { return w->get_check_box_int_value(c); } // -1
		};

		class disclosure_button_class : public control_base_class {
		public:
			plugin_disclosure_button_class &c;

	disclosure_button_class ( window_interface &w, int control_id, int x, int y, bool reversed = false ) : control_base_class(w, (xshade::control::control_class &)w.create_disclosure_button(*this, control_id, x, y, reversed)), c((plugin_disclosure_button_class &)control_base_class::c) { } // -1
	disclosure_button_class& set_value ( int i ) { w->set_disclosure_button_int_value(c, i); return *this; } // -1
	int get_value () const { return w->get_disclosure_button_int_value(c); } // -1
		};

		class flasher_class : public control_base_class {
		public:
			plugin_flasher_class &c;

	flasher_class ( window_interface &w, int control_id, int x, int y, int dx, int dy ) : control_base_class(w, (xshade::control::control_class &)w.create_flasher(*this, control_id, x, y, dx, dy)), c((plugin_flasher_class &)control_base_class::c) { } // -1
		};

		class slider_class : public control_base_class {
		public:
			plugin_slider_class &c;

	slider_class ( window_interface &w, int control_id, int x, int y, int size, bool vertical, const char*title, bool show_marks ) : control_base_class(w, (xshade::control::control_class &)w.create_slider(*this, control_id, x, y, size, vertical, title, show_marks)), c((plugin_slider_class &)control_base_class::c) { } // -1
	slider_class& set_value ( float f ) { w->set_slider_float_value(c, f); return *this; } // -1
	float get_value () const { return w->get_slider_float_value(c); } // -1
	slider_class& set_range ( float min, float max ) { w->set_slider_range(c, min, max); return *this; } // -1
	slider_class& set_integer () { w->set_slider_integer(c); return *this; } // -1
	slider_class& set_columns ( int columns ) { w->set_slider_columns(c, columns); return *this; } // -1
		};

		class number_class : public control_base_class {
		public:
			plugin_number_class &c;

	number_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char*title ) : control_base_class(w, (xshade::control::control_class &)w.create_number(*this, control_id, x, y, dx, dy, title)), c((plugin_number_class &)control_base_class::c) { } // -1
	number_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char*title, const char*unit ) : control_base_class(w, (xshade::control::control_class &)w.create_number_with_unit(*this, control_id, x, y, dx, dy, title, unit)), c((plugin_number_class &)control_base_class::c) { } // -1
	number_class& set_value ( float f ) { w->set_number_float_value(c, f); return *this; } // -1
	number_class& set_double_value ( double d ) { w->set_number_double_value(c, d); return *this; } // -1
	float get_value () const { return w->get_number_float_value(c); } // -1
	double get_double_value () const { return w->get_number_double_value(c); } // -1
	number_class& set_integer () { w->set_number_integer(c); return *this; } // -1
	number_class& set_columns ( int columns ) { w->set_number_columns(c, columns); return *this; } // -1
	number_class& set_fraction ( int fraction ) { w->set_number_fraction(c, fraction); return *this; } // -1
	number_class& set_min ( double min ) { w->set_number_min(c, min); return *this; } // -1
	number_class& set_max ( double max ) { w->set_number_max(c, max); return *this; } // -1
		};

		class popup_menu_class : public control_base_class {
		public:
			plugin_popup_menu_class &c;

	popup_menu_class ( window_interface &w, int control_id, int x, int y, const char*title, int width, const char*items ) : control_base_class(w, (xshade::control::control_class &)w.create_popup(*this, control_id, x, y, title, width, items)), c((plugin_popup_menu_class &)control_base_class::c) { } // -1
	popup_menu_class& set_value ( int i ) { w->set_popup_int_value(c, i); return *this; } // -1
	int get_value () const { return w->get_popup_int_value(c); } // -1
		};

		class color_disk_class : public control_base_class {
		public:
			plugin_color_disk_class &c;

	color_disk_class ( window_interface &w, int control_id, int x, int y ) : control_base_class(w, (xshade::control::control_class &)w.create_color_disk(*this, control_id, x, y)), c((plugin_color_disk_class &)control_base_class::c) { } // -1
	color_disk_class& set_value ( const sxsdk::vec2 &v ) { w->set_color_disk_vec2_value(c, v); return *this; } // -1
	sxsdk::vec2 get_value () const { return w->get_color_disk_vec2_value(c); } // -1
		};

		class color_box_class : public control_base_class {
		public:
			plugin_color_box_class &c;

	color_box_class ( window_interface &w, int control_id, int x, int y, int dx, int dy ) : control_base_class(w, (xshade::control::control_class &)w.create_color_box(*this, control_id, x, y, dx, dy)), c((plugin_color_box_class &)control_base_class::c) { } // -1
	color_box_class& set_value ( const sxsdk::rgb_class&r ) { w->set_color_box_rgb_value(c, r); return *this; } // -1
	sxsdk::rgb_class get_value () const { return w->get_color_box_rgb_value(c); } // -1
		};

		class image_box_class : public control_base_class {
		public:
			plugin_image_box_class &c;

	image_box_class ( window_interface &w, int control_id, int x, int y, int dx, int dy ) : control_base_class(w, (xshade::control::control_class &)w.create_image_box(*this, control_id, x, y, dx, dy)), c((plugin_image_box_class &)control_base_class::c) { } // -1
	image_box_class& set_value ( image_interface *i ) { w->set_image_box_image_value(c, i); return *this; } // -1
	sxsdk::image_interface* get_value () const { return w->get_image_box_image_value(c); } // -1
		};

		class editable_text_class : public control_base_class {
		public:
			plugin_editable_text_class &c;

	editable_text_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_editable_text(*this, control_id, x, y, dx, dy, title)), c((plugin_editable_text_class &)control_base_class::c) { } // -1
	editable_text_class& set_value ( const char *s ) { w->set_editable_text_string_value(c, s); return *this; } // -1
	const char * get_value () const { return w->get_editable_text_string_value(c); } // -1
		};

		class static_text_class : public control_base_class {
		public:
			plugin_static_text_class &c;

	static_text_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_static_text(*this, control_id, x, y, dx, dy, title)), c((plugin_static_text_class &)control_base_class::c) { } // -1
		};

		class radio_button_class : public control_base_class {
		public:
			plugin_radio_button_class &c;

	radio_button_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_radio_button(*this, control_id, x, y, dx, dy, title)), c((plugin_radio_button_class &)control_base_class::c) { } // -1
	radio_button_class& set_value ( int i ) { w->set_radio_button_int_value(c, i); return *this; } // -1
	int get_value () const { return w->get_radio_button_int_value(c); } // -1
		};

		class tab_class : public control_base_class {
		public:
			plugin_tab_class &c;

	tab_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_tab(*this, control_id, x, y, dx, dy, title)), c((plugin_tab_class &)control_base_class::c) { } // -1
	tab_class& set_value ( int i ) { w->set_tab_int_value(c, i); return *this; } // -1
	int get_value () const { return w->get_tab_int_value(c); } // -1
	tab_class& set_lazy ( bool lazy ) { w->set_tab_lazy(c, lazy); return *this; } // -1
	bool get_lazy () const { return w->get_tab_lazy(c); } // -1
		};

		class vec2_control_class : public control_base_class {
		public:
			plugin_vec2_control_class &c;

	vec2_control_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_vec2_control(*this, control_id, x, y, dx, dy, title)), c((plugin_vec2_control_class &)control_base_class::c) { } // -1
	vec2_control_class& set_value (const sxsdk::vec2& v) { w->set_vec2_control_value(c, v); return *this; } // -1
	sxsdk::vec2 get_value () const { return w->get_vec2_control_value(c); } // -1
		};

		class vec3_control_class : public control_base_class {
		public:
			plugin_vec3_control_class &c;

	vec3_control_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_vec3_control(*this, control_id, x, y, dx, dy, title)), c((plugin_vec3_control_class &)control_base_class::c) { } // -1
	vec3_control_class& set_value (const sxsdk::vec3& v) { w->set_vec3_control_value(c, v); return *this; } // -1
	sxsdk::vec3 get_value () const { return w->get_vec3_control_value(c); } // -1
		};

		class vec4_control_class : public control_base_class {
		public:
			plugin_vec4_control_class &c;

	vec4_control_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_vec4_control(*this, control_id, x, y, dx, dy, title)), c((plugin_vec4_control_class &)control_base_class::c) { } // -1
	vec4_control_class& set_value (const sxsdk::vec4& v) { w->set_vec4_control_value(c, v); return *this; } // -1
	sxsdk::vec4 get_value () const { return w->get_vec4_control_value(c); } // -1
		};

		class quaternion_control_class : public control_base_class {
		public:
			plugin_quaternion_control_class &c;

	quaternion_control_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_quaternion_control(*this, control_id, x, y, dx, dy, title)), c((plugin_quaternion_control_class &)control_base_class::c) { } // -1
	quaternion_control_class& set_value (const sxsdk::quaternion_class& v) { w->set_quaternion_value(c, v); return *this; } // -1
	sxsdk::quaternion_class get_value () const { return w->get_quaternion_value(c); } // -1
		};

		class matrix_control_class : public control_base_class {
		public:
			plugin_matrix_control_class &c;

	matrix_control_class ( window_interface &w, int control_id, int x, int y, int dx, int dy, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_matrix_control(*this, control_id, x, y, dx, dy, title)), c((plugin_matrix_control_class &)control_base_class::c) { } // -1
	matrix_control_class& set_value (const sxsdk::mat4& v) { w->set_matrix_control_value(c, v); return *this; } // -1
	sxsdk::mat4 get_value () const { return w->get_matrix_control_value(c); } // -1
		};

		class scale_control_class : public control_base_class {
		public:
			plugin_scale_control_class &c;

	scale_control_class ( window_interface &w, int control_id, int x, int y, const char *title ) : control_base_class(w, (xshade::control::control_class &)w.create_scale_control(*this, control_id, x, y, title)), c((plugin_scale_control_class &)control_base_class::c) { } // -1
	scale_control_class& set_value (int s) { w->set_scale_control_value(c, s); return *this; } // -1
	int get_value () const { return w->get_scale_control_value(c); } // -1
		};

		class table_control_class : public control_base_class {
		public:
			plugin_table_control_class &c;

	table_control_class ( window_interface &w, int control_id, int x, int y, int dx, int dy ) : control_base_class(w, (xshade::control::control_class &)w.create_table_control(*this, control_id, x, y, dx, dy)), c((plugin_table_control_class &)control_base_class::c) { } // -1
	table_control_class& insert_column (table_cell_type_enum type, int width, const char *label, int col = -1) { w->insert_table_column(c, type, width, label, col); return *this; } // -1
	table_control_class& remove_column (int col = -1) { w->remove_table_column(c, col); return *this; } // -1
	table_control_class& insert_row (int row = -1) { w->insert_table_row(c, row); return *this; } // -1
	table_control_class& remove_row (int row = -1) { w->remove_table_row(c, row); return *this; } // -1
	table_control_class& clear_table () { w->clear_table(c); return *this; } // -1
	table_control_class& set_bool_value (int row, int col, bool value) { w->set_bool_value(c, row, col, value); return *this; } // -1
	table_control_class& set_int_value (int row, int col, int value) { w->set_int_value(c, row, col, value); return *this; } // -1
	table_control_class& set_float_value (int row, int col, int value) { w->set_float_value(c, row, col, value); return *this; } // -1
	table_control_class& set_string_value_deprecated (int row, int col, const std::string &value) { w->set_string_value_deprecated(c, row, col, value); return *this; } // -1
	table_control_class& set_string_value (int row, int col, const char* value) { w->set_string_value(c, row, col, value); return *this; } // -1
	table_control_class& set_color_value (int row, int col, const sxsdk::rgb_class &value) { w->set_color_value(c, row, col, value); return *this; } // -1
	bool get_bool_value (int row, int col) { return w->get_bool_value(c, row, col); } // -1
	int get_int_value (int row, int col) { return w->get_int_value(c, row, col); } // -1
	float get_float_value (int row, int col) { return w->get_float_value(c, row, col); } // -1
	std::string get_string_value_deprecated (int row, int col) { return w->get_string_value_deprecated(c, row, col); } // -1
	const char* get_string_value (int row, int col) { return w->get_string_value(c, row, col); } // -1
	sxsdk::rgb_class get_color_value (int row, int col) { return w->get_color_value(c, row, col); } // -1
	table_control_class& set_table_style (int mode) { w->set_table_style(c, mode); return *this; } // -1
	int get_table_style () { return w->get_table_style(c); } // -1
	table_control_class& select (int row) { w->select(c, row); return *this; } // -1
	table_control_class& select_all (bool b) { w->select_all(c, b); return *this; } // -1
	int number_of_selected_items () { return w->number_of_selected_items(c); } // -1
	int first_selected_item () { return w->first_selected_item(c); } // -1
	int next_selected_item (int index) { return w->next_selected_item(c,index); } // -1
	bool has_selection () { return w->has_selection(c); } // -1
	table_control_class& check_all (int col, int b) { w->check_all(c, col, b); return *this; } // -1
	int first_checked_item (int col) { return w->first_checked_item(c, col); } // -1
	int next_checked_item (int col, int index) { return w->next_checked_item(c, col, index); } // -1
	bool has_checked (int col) { return w->has_checked(c, col); } // -1
	bool is_selected (int row) { return w->is_selected(c, row); } // -1
	table_control_class& set_selected (int row, bool b) { w->set_selected(c, row, b); return *this; } // -1
	bool is_active_row (int row) { return w->is_active_row(c, row); } // -1
	table_control_class& set_active_row (int row, bool b) { w->set_active_row(c, row, b); return *this; } // -1
	bool is_active_cell (int row, int col) { return w->is_active_cell(c, row, col); } // -1
	table_control_class& set_active_cell (int row, int col, bool b) { w->set_active_cell(c, row, col, b); return *this; } // -1
	int number_of_rows () { return w->number_of_rows(c); } // -1
	int number_of_columns () { return w->number_of_columns(c); } // -1
	virtual void table_select_changed ( const int indices[],const int n ) { } // -1
	virtual bool double_clicked ( const int row_index ) { return false; } // -1
		};

		virtual ~window_interface () { }
	window_interface (shade_interface& shade) : shade(shade), w(0) { } // -1
	window_interface (shade_interface& shade, sxsdk::dialog_interface& dialog, dialog_item_class& item, int flags) : shade(shade), w(0) { w = shade.implementation().window_new_dialog_item(*this, dialog, item, flags); } // -1
	window_interface (sxsdk::window_interface& parent, int flags) : shade(parent.shade), w(0) { w = shade.implementation().window_new(*this, &parent, flags); } // -1
	window_interface (shade_interface& shade, int flags) : shade(shade), w(0) { w = shade.implementation().window_new(*this, 0, flags | sx::transient_window); } // -1
	virtual void delete_self (void* aux = 0) { shade.implementation().window_delete_self(*this); } // 0
	virtual void initialize (void* aux = 0) { }  // 1
	virtual void clear (sxsdk::graphic_context_interface& gc, void* aux = 0) { shade.implementation().window_clear(*this, gc); }  // 2
	virtual void paint (sxsdk::graphic_context_interface& gc, const sx::rectangle_class* visible_rectangle, void* aux = 0) { shade.implementation().window_paint(*this, gc, visible_rectangle); }  // 3
	virtual void resize (int x, int y, bool remake = true, void* aux = 0) { shade.implementation().window_resize(*this, x, y, remake); }  // 4
	virtual void mouse_enter (void* aux = 0) { shade.implementation().window_mouse_enter(*this); }  // 5
	virtual void mouse_move (sx::vec<int,2> p, void* aux = 0) { shade.implementation().window_mouse_move(*this, p); }  // 6
	virtual void mouse_exit (void* aux = 0) { shade.implementation().window_mouse_exit(*this); }  // 7
	virtual bool mouse_down (int button, sx::vec<int,2> p, int key_down, int time, bool double_click, void* aux = 0) { shade.implementation().window_mouse_down(*this, button, p, key_down, time, double_click); return true; }  // 8
	virtual void idle (void* aux = 0) { shade.implementation().window_idle(*this); }  // 9
	virtual void scrolled (sx::vec<int,2> offset, void* aux = 0) { shade.implementation().window_scrolled(*this, offset); }  // 10
	virtual bool is_resizable (void* aux = 0) { return false; }  // 11
	virtual sx::rectangle_class get_client_rectangle_obsolete (void* aux = 0) { return shade.implementation().window_get_client_rectangle_excluding_scroll_bars(*this); }  // 12
	virtual void invalidate (void* aux = 0) { shade.implementation().window_invalidate(*this); }  // 13
	virtual int window_interface_test_1 (void* aux = 0) { return 1; }  // 14
	virtual sx::vec<int,2> get_minimum_size_obsolete (void* aux = 0) { return sx::vec<int,2>(-1,-1); }  // 15
	virtual sx::vec<int,2> get_maximum_size_obsolete (void* aux = 0) { return sx::vec<int,2>(-1,-1); }  // 16
	virtual sx::vec<int,2> get_ideal_size (void* aux = 0) { return sx::vec<int,2>(-1,-1); }  // 17
	virtual void* get_text_object (void* aux = 0) { return shade.implementation().window_get_text_object(*this); }  // 18
	virtual int get_placement_flags (void* aux = 0) { return view_menu_placement_flag; }  // 19
	virtual int get_flags (void* aux = 0) { return 0; }  // 20
	virtual void activate ( void*aux = 0 ) { shade.implementation().window_activate(*this); }  // 21
	virtual void deactivate ( void*aux = 0 ) { shade.implementation().window_deactivate(*this); }  // 22
	virtual void drag_file (const char* path, void* aux = 0) { shade.implementation().window_drag_file(*this, path); }  // 23
	virtual sxsdk::image_interface* get_image_interface (void* aux = 0) { return shade.implementation().window_get_image_interface(*this); }  // 24
	virtual sx::vec<int,2> get_frame_position (void * = 0) const { return shade.implementation().window_get_frame_rectangle(*this).min; } // 25
	virtual window_interface &set_frame_position (sx::vec<int,2> frame_position_param, void * = 0) { sx::rectangle_class r = get_frame_rectangle(); r.max.x += frame_position_param.x - r.min.x; r.max.y += frame_position_param.y - r.min.y; r.min.x = frame_position_param.x; r.min.y = frame_position_param.y; set_frame_rectangle(r); return *this; } // 26
	virtual bool should_clear (void* aux = 0) { return true; }  // 27
	virtual void* get_native_window (void* aux = 0) { return shade.implementation().window_get_native_window(*this); }  // 28
	virtual void push_button_clicked (sxsdk::window_interface::push_button_class& push_button, void* aux = 0) { }  // 29
	virtual void checkbox_value_changed (sxsdk::window_interface::checkbox_class& checkbox, void* aux = 0) { }  // 30
	virtual void disclosure_button_value_changed (sxsdk::window_interface::disclosure_button_class& disclosure_button, void* aux = 0) { }  // 31
	virtual void slider_value_changed (sxsdk::window_interface::slider_class& slider, void* aux = 0) { }  // 32
	virtual void number_value_changed (sxsdk::window_interface::number_class& number, void* aux = 0) { }  // 33
	virtual void popup_menu_value_changed (sxsdk::window_interface::popup_menu_class& popup_menu, void* aux = 0) { }  // 34
	virtual void color_disk_value_changed (sxsdk::window_interface::color_disk_class& color_disk, void* aux = 0) { }  // 35
	virtual void color_box_value_changed (sxsdk::window_interface::color_box_class& color_box, void* aux = 0) { }  // 36
	virtual void image_box_image_changed (sxsdk::window_interface::image_box_class& image_box, void* aux = 0) { }  // 37
	virtual void radio_button_value_changed (sxsdk::window_interface::radio_button_class& radio_button, void* aux = 0) { }  // 38
	virtual void vec2_value_changed (sxsdk::window_interface::vec2_control_class& vec2_control, void* aux = 0) { }  // 39
	virtual void vec3_value_changed (sxsdk::window_interface::vec3_control_class& vec3_control, void* aux = 0) { }  // 40
	virtual void vec4_value_changed (sxsdk::window_interface::vec4_control_class& vec4_control, void* aux = 0) { }  // 41
	virtual void quaternion_value_changed (sxsdk::window_interface::quaternion_control_class& quaternion_control, void* aux = 0) { }  // 42
	virtual void matrix_value_changed (sxsdk::window_interface::matrix_control_class& matrix_control, void* aux = 0) { }  // 43
	virtual void scale_value_changed (sxsdk::window_interface::scale_control_class& scale_control, void* aux = 0) { }  // 44
	virtual void initialize_push_button (sxsdk::window_interface::push_button_class& push_button, void* aux = 0) { }  // 45
	virtual void initialize_checkbox (sxsdk::window_interface::checkbox_class& checkbox, void* aux = 0) { }  // 46
	virtual void initialize_disclosure_button (sxsdk::window_interface::disclosure_button_class& disclosure_button, void* aux = 0) { }  // 47
	virtual void initialize_slider (sxsdk::window_interface::slider_class& slider, void* aux = 0) { }  // 48
	virtual void initialize_number (sxsdk::window_interface::number_class& number, void* aux = 0) { }  // 49
	virtual void initialize_popup_menu (sxsdk::window_interface::popup_menu_class& popup_menu, void* aux = 0) { }  // 50
	virtual void initialize_color_disk (sxsdk::window_interface::color_disk_class& color_disk, void* aux = 0) { }  // 51
	virtual void initialize_color_box (sxsdk::window_interface::color_box_class& color_box, void* aux = 0) { }  // 52
	virtual void initialize_image_box (sxsdk::window_interface::image_box_class& image_box, void* aux = 0) { }  // 53
	virtual void initialize_radio_button (sxsdk::window_interface::radio_button_class& radio_button, void* aux = 0) { }  // 54
	virtual void initialize_vec2 (sxsdk::window_interface::vec2_control_class& vec2_control, void* aux = 0) { }  // 55
	virtual void initialize_vec3 (sxsdk::window_interface::vec3_control_class& vec3_control, void* aux = 0) { }  // 56
	virtual void initialize_vec4 (sxsdk::window_interface::vec4_control_class& vec4_control, void* aux = 0) { }  // 57
	virtual void initialize_quaternion (sxsdk::window_interface::quaternion_control_class& quaternion_control, void* aux = 0) { }  // 58
	virtual void initialize_matrix (sxsdk::window_interface::matrix_control_class& matrix_control, void* aux = 0) { }  // 59
	virtual void initialize_scale (sxsdk::window_interface::scale_control_class& scale_control, void* aux = 0) { }  // 60
	virtual void initialize_static_text (sxsdk::window_interface::static_text_class& static_text, void* aux = 0) { }  // 61
	virtual void initialize_flasher (sxsdk::window_interface::flasher_class& flasher, void* aux = 0) { }  // 62
	virtual bool setup_push_button (sxsdk::window_interface::push_button_class& push_button, void* aux = 0) { return false; }  // 63
	virtual bool setup_checkbox (sxsdk::window_interface::checkbox_class& checkbox, void* aux = 0) { return false; }  // 64
	virtual bool setup_disclosure_button (sxsdk::window_interface::disclosure_button_class& disclosure_button, void* aux = 0) { return false; }  // 65
	virtual bool setup_slider (sxsdk::window_interface::slider_class& slider, void* aux = 0) { return false; }  // 66
	virtual bool setup_number (sxsdk::window_interface::number_class& number, void* aux = 0) { return false; }  // 67
	virtual bool setup_popup_menu (sxsdk::window_interface::popup_menu_class& popup_menu, void* aux = 0) { return false; }  // 68
	virtual bool setup_color_disk (sxsdk::window_interface::color_disk_class& color_disk, void* aux = 0) { return false; }  // 69
	virtual bool setup_color_box (sxsdk::window_interface::color_box_class& color_box, void* aux = 0) { return false; }  // 70
	virtual bool setup_image_box (sxsdk::window_interface::image_box_class& image_box, void* aux = 0) { return false; }  // 71
	virtual bool setup_radio_button (sxsdk::window_interface::radio_button_class& radio_button, void* aux = 0) { return false; }  // 72
	virtual bool setup_vec2 (sxsdk::window_interface::vec2_control_class& vec2_control, void* aux = 0) { return false; }  // 73
	virtual bool setup_vec3 (sxsdk::window_interface::vec3_control_class& vec3_control, void* aux = 0) { return false; }  // 74
	virtual bool setup_vec4 (sxsdk::window_interface::vec4_control_class& vec4_control, void* aux = 0) { return false; }  // 75
	virtual bool setup_quaternion (sxsdk::window_interface::quaternion_control_class& quaternion_control, void* aux = 0) { return false; }  // 76
	virtual bool setup_matrix (sxsdk::window_interface::matrix_control_class& matrix_control, void* aux = 0) { return false; }  // 77
	virtual bool setup_scale (sxsdk::window_interface::scale_control_class& scale_control, void* aux = 0) { return false; }  // 78
	virtual bool setup_static_text (sxsdk::window_interface::static_text_class& static_text, void* aux = 0) { return false; }  // 79
	virtual bool setup_flasher (sxsdk::window_interface::flasher_class& flasher, void* aux = 0) { return false; }  // 80
	virtual void tab_value_changed (sxsdk::window_interface::tab_class& tab, void* aux = 0) { }  // 81
	virtual void initialize_tab (sxsdk::window_interface::tab_class& tab, void* aux = 0) { }  // 82
	virtual bool setup_tab (sxsdk::window_interface::tab_class& tab, void* aux = 0) { return false; }  // 83
	virtual bool key_down (int code, int flags, void* aux = 0) { return shade.implementation().window_key_down(*this, code, flags); }  // 84
	virtual bool scroll_wheel (const sxsdk::vec2& delta, sx::vec<int,2> p, int key_down, void* aux = 0) { return shade.implementation().window_scroll_wheel(*this, delta, p, key_down); }  // 85
	virtual void initialize_table (sxsdk::window_interface::table_control_class& table, void* aux = 0) { }  // 86
	virtual bool setup_table (sxsdk::window_interface::table_control_class& table, void* aux = 0) { return false; }  // 87
	virtual void obsolete (void* aux = 0) { shade.implementation().window_obsolete(*this); }  // 88
	virtual void table_selection_changed (sxsdk::window_interface::table_control_class& table, int count, const int* indice, void* aux = 0) { }  // 89
	virtual bool table_double_clicked (sxsdk::window_interface::table_control_class& table, int row, void* aux = 0) { return false; }  // 90
	virtual void initialize_editable_text (sxsdk::window_interface::editable_text_class& editable_text, void* aux = 0) { } // 91
	virtual bool setup_editable_text (sxsdk::window_interface::editable_text_class& editable_text, void* aux = 0) { return false; } // 92
	virtual void editable_text_changed (sxsdk::window_interface::editable_text_class& editable_text, void* aux = 0) { } // 93
	virtual int window_interface_dummy94(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 94
	virtual int window_interface_dummy95(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 95
	virtual int window_interface_dummy96(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 96
	virtual int window_interface_dummy97(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 97
	virtual int window_interface_dummy98(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 98
	virtual int window_interface_dummy99(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 99
	virtual int window_interface_dummy100(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 100
	virtual int window_interface_dummy101(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 101
	virtual int window_interface_dummy102(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 102
	virtual int window_interface_dummy103(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 103
	virtual int window_interface_dummy104(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 104
	virtual int window_interface_dummy105(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 105
	virtual int window_interface_dummy106(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 106
	virtual int window_interface_dummy107(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 107
	virtual int window_interface_dummy108(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 108
	virtual int window_interface_dummy109(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 109
	virtual int window_interface_dummy110(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 110
	virtual int window_interface_dummy111(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 111
	virtual int window_interface_dummy112(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 112
	virtual int window_interface_dummy113(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 113
	virtual int window_interface_dummy114(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 114
	virtual int window_interface_dummy115(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 115
	virtual int window_interface_dummy116(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 116
	virtual int window_interface_dummy117(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 117
	virtual int window_interface_dummy118(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 118
	virtual int window_interface_dummy119(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 119
	virtual int window_interface_dummy120(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 120
	virtual int window_interface_dummy121(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 121
	virtual int window_interface_dummy122(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 122
	virtual int window_interface_dummy123(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 123
	virtual int window_interface_dummy124(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 124
	virtual int window_interface_dummy125(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 125
	virtual int window_interface_dummy126(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 126
	virtual int window_interface_dummy127(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 127
	virtual int window_interface_dummy128(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 128
	virtual int window_interface_dummy129(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 129
	virtual int window_interface_dummy130(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 130
	virtual int window_interface_dummy131(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 131
	virtual int window_interface_dummy132(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 132
	virtual int window_interface_dummy133(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 133
	virtual int window_interface_dummy134(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 134
	virtual int window_interface_dummy135(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 135
	virtual int window_interface_dummy136(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 136
	virtual int window_interface_dummy137(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 137
	virtual int window_interface_dummy138(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 138
	virtual int window_interface_dummy139(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 139
	virtual int window_interface_dummy140(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 140
	virtual int window_interface_dummy141(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 141
	virtual int window_interface_dummy142(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 142
	virtual int window_interface_dummy143(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 143
	virtual int window_interface_dummy144(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 144
	virtual int window_interface_dummy145(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 145
	virtual int window_interface_dummy146(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 146
	virtual int window_interface_dummy147(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 147
	virtual int window_interface_dummy148(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 148
	virtual int window_interface_dummy149(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 149
	virtual int window_interface_dummy150(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 150
	virtual int window_interface_dummy151(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 151
	virtual int window_interface_dummy152(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 152
	virtual int window_interface_dummy153(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 153
	virtual int window_interface_dummy154(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 154
	virtual int window_interface_dummy155(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 155
	virtual int window_interface_dummy156(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 156
	virtual int window_interface_dummy157(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 157
	virtual int window_interface_dummy158(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 158
	virtual int window_interface_dummy159(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 159
	virtual int window_interface_dummy160(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 160
	virtual int window_interface_dummy161(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 161
	virtual int window_interface_dummy162(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 162
	virtual int window_interface_dummy163(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 163
	virtual int window_interface_dummy164(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 164
	virtual int window_interface_dummy165(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 165
	virtual int window_interface_dummy166(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 166
	virtual int window_interface_dummy167(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 167
	virtual int window_interface_dummy168(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 168
	virtual int window_interface_dummy169(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 169
	virtual int window_interface_dummy170(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 170
	virtual int window_interface_dummy171(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 171
	virtual int window_interface_dummy172(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 172
	virtual int window_interface_dummy173(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 173
	virtual int window_interface_dummy174(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 174
	virtual int window_interface_dummy175(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 175
	virtual int window_interface_dummy176(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 176
	virtual int window_interface_dummy177(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 177
	virtual int window_interface_dummy178(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 178
	virtual int window_interface_dummy179(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 179
	virtual int window_interface_dummy180(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 180
	virtual int window_interface_dummy181(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 181
	virtual int window_interface_dummy182(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 182
	virtual int window_interface_dummy183(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 183
	virtual int window_interface_dummy184(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 184
	virtual int window_interface_dummy185(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 185
	virtual int window_interface_dummy186(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 186
	virtual int window_interface_dummy187(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 187
	virtual int window_interface_dummy188(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 188
	virtual int window_interface_dummy189(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 189
	virtual int window_interface_dummy190(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 190
	virtual int window_interface_dummy191(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 191
	virtual int window_interface_dummy192(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 192
	virtual int window_interface_dummy193(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 193
	virtual int window_interface_dummy194(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 194
	virtual int window_interface_dummy195(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 195
	virtual int window_interface_dummy196(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 196
	virtual int window_interface_dummy197(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 197
	virtual int window_interface_dummy198(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 198
	virtual int window_interface_dummy199(void *) { assert(false); throw "invalid interface window_interface"; return 0; } // 199
float get_horizontal_line_scroll (void * = 0) const { return shade.implementation().window_get_horizontal_line_scroll(*this); }
window_interface &set_horizontal_line_scroll (float horizontal_line_scroll_param, void * = 0) { shade.implementation().window_set_horizontal_line_scroll(*this, horizontal_line_scroll_param); return *this; }
float get_vertical_line_scroll (void * = 0) const { return shade.implementation().window_get_vertical_line_scroll(*this); }
window_interface &set_vertical_line_scroll (float vertical_line_scroll_param, void * = 0) { shade.implementation().window_set_vertical_line_scroll(*this, vertical_line_scroll_param); return *this; }
float get_horizontal_page_scroll (void * = 0) const { return shade.implementation().window_get_horizontal_page_scroll(*this); }
window_interface &set_horizontal_page_scroll (float horizontal_page_scroll_param, void * = 0) { shade.implementation().window_set_horizontal_page_scroll(*this, horizontal_page_scroll_param); return *this; }
float get_vertical_page_scroll (void * = 0) const { return shade.implementation().window_get_vertical_page_scroll(*this); }
window_interface &set_vertical_page_scroll (float vertical_page_scroll_param, void * = 0) { shade.implementation().window_set_vertical_page_scroll(*this, vertical_page_scroll_param); return *this; }
void show_hide (void* aux = 0) { if (is_shown()) hide(); else { show(); bring_to_front(); } }
void show (void* aux = 0) { shade.implementation().window_show(*this); }
void hide (void* aux = 0) { shade.implementation().window_hide(*this); }
void bring_to_front (void* aux = 0) { shade.implementation().window_select(*this); }
bool is_shown (void * = 0) const { return shade.implementation().window_is_shown(*this); }
const char* get_title (void * = 0) const { return shade.implementation().window_get_title(*this); }
window_interface &set_title (const char* title_param, void * = 0) { shade.implementation().window_set_title(*this, title_param); return *this; }
sx::vec<int,2> get_canvas_size (void * = 0) const { return shade.implementation().window_get_canvas_size(*this); }
window_interface &set_canvas_size (sx::vec<int,2> canvas_size_param, void * = 0) { shade.implementation().window_set_canvas_size(*this, canvas_size_param); return *this; }
sx::vec<int,2> get_client_size (void * = 0) const { return shade.implementation().window_get_client_size(*this); }
window_interface &set_client_size (sx::vec<int,2> client_size_param, void * = 0) { shade.implementation().window_set_client_size(*this, client_size_param); return *this; }
sx::rectangle_class get_frame_rectangle (void * = 0) const { return shade.implementation().window_get_frame_rectangle(*this); }
window_interface &set_frame_rectangle (sx::rectangle_class frame_rectangle_param, void * = 0) { shade.implementation().window_set_frame_rectangle(*this, frame_rectangle_param); return *this; }
sx::rectangle_class get_layout_bounds (void * = 0) const { return shade.implementation().window_get_layout_bounds(*this); }
void pump (void* aux = 0) { shade.implementation().window_pump(*this); }
void paint (void* aux = 0) { shade.implementation().window_paintself(*this); }
void set_client_rectangle (const sx::rectangle_class& client) { shade.implementation().window_set_client_rectangle(*this, client); }
sx::rectangle_class get_client_rectangle (bool include_scroll_bars) const { return shade.implementation().window_get_client_rectangle(*this, include_scroll_bars); }
sx::vec<int,2> global_to_window (const sx::vec<int,2>& p) const { return shade.implementation().window_global_to_window_point(*this, p); }
sx::rectangle_class global_to_window (const sx::rectangle_class& r) const { return shade.implementation().window_global_to_window_rectangle(*this, r); }
sx::vec<int,2> window_to_global (const sx::vec<int,2>& p) const { return shade.implementation().window_window_to_global_point(*this, p); }
sx::rectangle_class window_to_global (const sx::rectangle_class& r) const { return shade.implementation().window_window_to_global_rectangle(*this, r); }
sx::vec<int,2> get_scroll_position () const { return shade.implementation().window_get_scroll_position(*this); }
void set_scroll_position ( sx::vec<int,2> position ) { shade.implementation().window_set_scroll_position(*this, position); }
int get_current_time () const { return shade.implementation().get_current_time(); }
sxsdk::rgb_class get_highlight_color_obsolete () const { return shade.implementation().get_highlight_color(); }
sxsdk::rgb_class get_face_color_obsolete () const { return shade.implementation().get_face_color(); }
sxsdk::rgb_class get_shadow_color_obsolete () const { return shade.implementation().get_shadow_color(); }
sxsdk::rgb_class get_text_color_obsolete () const { return shade.implementation().get_text_color(); }
sxsdk::rgb_class get_graytext_color_obsolete () const { return shade.implementation().get_graytext_color(); }
sxsdk::rgb_class get_selected_color_obsolete () const { return shade.implementation().get_selected_color(); }
sxsdk::rgb_class get_selectedtext_color_obsolete () const { return shade.implementation().get_selectedtext_color(); }
void push_anchor_control () { shade.implementation().window_push_anchor_control(*this); }
void pop_anchor_control () { shade.implementation().window_pop_anchor_control(*this); }
void set_minimum_size (sx::vec<int,2> size) { shade.implementation().window_set_minimum_size(*this, size); }
void set_maximum_size (sx::vec<int,2> size) { shade.implementation().window_set_maximum_size(*this, size); }
void load_sxul (const char* sxul) { shade.implementation().window_load_sxul(*this, sxul); }
void load_sxul (sxsdk::stream_interface& stream) { shade.implementation().window_load_sxul_stream(*this, stream); }
void set_trigger (enums::trigger_enum trigger) { shade.implementation().window_set_trigger(*this, trigger); }
void begin_opengl (void* aux = 0) { shade.implementation().window_begin_opengl(*this); }
void end_opengl (void* aux = 0) { shade.implementation().window_end_opengl(*this); }
sxsdk::rgb_class get_theme_color (int flags) const { return shade.implementation().get_theme_color(flags); }
void set_cursor (int cursor_index, void* aux = 0) { shade.implementation().window_set_cursor(*this, cursor_index); }
int get_string_height () const { return shade.implementation().get_string_height(); }
	private:
		plugin_push_button_class &create_button (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_button(*this, handler, control_id, x, y, dx, dy, title); }
		plugin_checkbox_class &create_check_box (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_check_box(*this, handler, control_id, x, y, dx, dy, title); }
		plugin_disclosure_button_class &create_disclosure_button (handler_interface &handler, int control_id, int x, int y,bool reversed =false , void* aux =0) { return shade.implementation().window_create_disclosure_button(*this, handler, control_id, x, y, reversed); }
		plugin_slider_class &create_slider (handler_interface &handler, int control_id, int x, int y, int size, bool vertical, const char*title, bool show_marks, void* aux =0) { return shade.implementation().window_create_slider(*this, handler, control_id, x, y, size, vertical, title, show_marks); }
		plugin_number_class &create_number (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_number(*this, handler, control_id, x, y, dx, dy, title); }
		plugin_number_class &create_number_with_unit (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, const char*unit, void* aux =0) { return shade.implementation().window_create_number_with_unit(*this, handler, control_id, x, y, dx, dy, title, unit); }
		plugin_popup_menu_class &create_popup (handler_interface &handler, int control_id, int x, int y, const char*title, int width, const char*items, void* aux =0) { return shade.implementation().window_create_popup(*this, handler, control_id, x, y, title, width, items); }
		plugin_color_disk_class &create_color_disk (handler_interface &handler, int control_id, int x, int y, void* aux =0) { return shade.implementation().window_create_color_disk(*this, handler, control_id, x, y); }
		plugin_color_box_class &create_color_box (handler_interface &handler, int control_id, int x, int y, int dx, int dy, void* aux =0) { return shade.implementation().window_create_color_box(*this, handler, control_id, x, y, dx, dy); }
		plugin_image_box_class &create_image_box (handler_interface &handler, int control_id, int x, int y, int dx, int dy, void* aux =0) { return shade.implementation().window_create_image_box(*this, handler, control_id, x, y, dx, dy); }
		plugin_editable_text_class &create_editable_text (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_editable_text(*this, handler, control_id, x, y, dx, dy, title); }
		plugin_static_text_class &create_static_text (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_static_text(*this, handler, control_id, x, y, dx, dy, title); }
		plugin_radio_button_class &create_radio_button (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_radio_button(*this, handler, control_id, x, y, dx, dy, title); }
		int get_button_int_value (plugin_push_button_class &c) { return shade.implementation().window_get_button_int_value(*this, c); }
		void set_check_box_int_value (plugin_checkbox_class &c, int i) { shade.implementation().window_set_check_box_int_value(*this, c, i); }
		int get_check_box_int_value (plugin_checkbox_class &c) { return shade.implementation().window_get_check_box_int_value(*this, c); }
		void set_disclosure_button_int_value (plugin_disclosure_button_class &c, int i) { shade.implementation().window_set_disclosure_button_int_value(*this, c, i); }
		int get_disclosure_button_int_value (plugin_disclosure_button_class &c) { return shade.implementation().window_get_disclosure_button_int_value(*this, c); }
		void set_number_float_value (plugin_number_class &c, float f) { shade.implementation().window_set_number_float_value(*this, c, f); }
		float get_number_float_value (plugin_number_class &c) { return shade.implementation().window_get_number_float_value(*this, c); }
		void set_number_double_value (plugin_number_class &c, double d) { shade.implementation().window_set_number_double_value(*this, c, d); }
		double get_number_double_value (plugin_number_class &c) { return shade.implementation().window_get_number_double_value(*this, c); }
		void set_popup_int_value (plugin_popup_menu_class &c, int i) { shade.implementation().window_set_popup_int_value(*this, c, i); }
		int get_popup_int_value (plugin_popup_menu_class &c) { return shade.implementation().window_get_popup_int_value(*this, c); }
		void set_radio_button_int_value (plugin_radio_button_class &c, int i) { shade.implementation().window_set_radio_button_int_value(*this, c, i); }
		int get_radio_button_int_value (plugin_radio_button_class &c) { return shade.implementation().window_get_radio_button_int_value(*this, c); }
		void set_color_disk_vec2_value (plugin_color_disk_class &c, const sx::vec<float,2> &v) { shade.implementation().window_set_color_disk_vec2_value(*this, c, v); }
		sx::vec<float,2> get_color_disk_vec2_value (plugin_color_disk_class &c) { return shade.implementation().window_get_color_disk_vec2_value(*this, c); }
		void set_color_box_rgb_value (plugin_color_box_class &c, const sx::rgb<float>&r) { shade.implementation().window_set_color_box_rgb_value(*this, c, r); }
		sx::rgb<float> get_color_box_rgb_value (plugin_color_box_class &c) { return shade.implementation().window_get_color_box_rgb_value(*this, c); }
		void set_image_box_image_value (plugin_image_box_class &c, image_interface *i) { shade.implementation().window_set_image_box_image_value(*this, c, i); }
		image_interface *get_image_box_image_value (plugin_image_box_class &c) { return shade.implementation().window_get_image_box_image_value(*this, c); }
		void set_slider_float_value (plugin_slider_class &c, float f) { shade.implementation().window_set_slider_float_value(*this, c, f); }
		float get_slider_float_value (plugin_slider_class &c) { return shade.implementation().window_get_slider_float_value(*this, c); }
		void set_slider_range (plugin_slider_class &c, float min, float max) { shade.implementation().window_set_slider_range(*this, c, min, max); }
		int get_control_id (xshade::control::control_class &c) { return shade.implementation().window_get_control_id(*this, c); }
		const char *get_control_idname (xshade::control::control_class &c) { return shade.implementation().window_get_control_idname(*this, c); }
		bool select (xshade::control::control_class &c, bool select = true, bool invalidate_flag = true) { return shade.implementation().control_select(c, select, invalidate_flag); }
		void set_image (xshade::control::control_class &c, image_interface &image) { shade.implementation().control_set_image(c, image); }
		void set_handler (xshade::control::control_class &c, unknown_interface &handler) { shade.implementation().control_set_handler_with_uuid(c, handler, uuid()); }
		void set_popup_menu (xshade::control::control_class &c, const char*titles) { shade.implementation().control_set_popup_menu(c, titles); }
		void set_tooltip (xshade::control::control_class &c, const char*s) { shade.implementation().control_set_tooltip(c, s); }
		void set_active (xshade::control::control_class &c, bool active) { shade.implementation().control_set_active(c, active); }
		bool get_active (xshade::control::control_class &c) { return shade.implementation().control_get_active(c); }
		void invalidate_control (xshade::control::control_class &c) { shade.implementation().control_invalidate(c); }
		void show_control (xshade::control::control_class &c) { shade.implementation().control_show(c); }
		void hide_control (xshade::control::control_class &c) { shade.implementation().control_hide(c); }
		sx::vec<int,2> get_position (xshade::control::control_class &c) { return shade.implementation().control_get_position(c); }
		void set_position (xshade::control::control_class &c, const sx::vec<int,2> &position) { shade.implementation().control_set_position(c, position); }
		sx::vec<int,2> get_size (xshade::control::control_class &c) { return shade.implementation().control_get_size(c); }
		void set_size (xshade::control::control_class &c, const sx::vec<int,2> &size) { shade.implementation().control_set_size(c, size); }
		const char*get_title (xshade::control::control_class &c) { return shade.implementation().control_get_title(c); }
		void set_title (xshade::control::control_class &c, const char*title) { shade.implementation().control_set_title(c, title); }
		void set_items (xshade::control::control_class &c, const char*items) { shade.implementation().control_set_items(c, items); }
		sx::mouse_tracker_class &create_mouse_tracker (void *mouse_tracker, const sx::vec<int,2> &where) { return shade.implementation().window_create_mouse_tracker(*this, mouse_tracker, where); }
		void set_bounds (xshade::control::control_class &c, const sx::bounds<sx::vec<int,2> > &bounds) { shade.implementation().control_set_bounds(c, bounds); }
		sx::bounds<sx::vec<int,2> > get_bounds (xshade::control::control_class &c) const { return shade.implementation().control_get_bounds(c); }
		int get_title_width (xshade::control::control_class &c) const { return shade.implementation().control_get_title_width(c); }
		void set_handler (sx::mouse_tracker_class &m, unknown_interface &handler) { shade.implementation().mousetracker_set_handler(m, handler); }
		void delete_control (xshade::control::control_class &c) { shade.implementation().control_delete_self(c); }
		void reset_control_position (void* aux =0) { shade.implementation().window_reset_control_position(*this); } //35029
		void set_number_integer (plugin_number_class &c) { shade.implementation().window_set_number_integer(*this, c); } //36014
		void set_number_columns (plugin_number_class &c, int columns) { shade.implementation().window_set_number_columns(*this, c, columns); } //36014
		void set_number_fraction (plugin_number_class &c, int fraction) { shade.implementation().window_set_number_fraction(*this, c, fraction); } //36032
		void set_number_min (plugin_number_class &c, double min) { shade.implementation().window_set_number_min(*this, c, min); }
		void set_number_max (plugin_number_class &c, double max) { shade.implementation().window_set_number_max(*this, c, max); }
		void set_slider_integer (plugin_slider_class &c) { shade.implementation().window_set_slider_integer(*this, c); } //36014
		void set_slider_columns (plugin_slider_class &c, int columns) { shade.implementation().window_set_slider_columns(*this, c, columns); } //36014
		plugin_tab_class &create_tab (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_tab(*this, handler, control_id, x, y, dx, dy, title); }
		void set_tab_int_value (plugin_tab_class &c, int i) { shade.implementation().window_set_tab_int_value(*this, c, i); }
		int get_tab_int_value (plugin_tab_class &c) { return shade.implementation().window_get_tab_int_value(*this, c); }
		void set_tab_lazy (plugin_tab_class &c, bool lazy) { shade.implementation().window_set_tab_lazy(*this, c, lazy); }
		bool get_tab_lazy (plugin_tab_class &c) { return shade.implementation().window_get_tab_lazy(*this, c); }
		plugin_vec2_control_class &create_vec2_control (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_vec2_control(*this, handler, control_id, x, y, dx, dy, title); }
		void set_vec2_control_value (plugin_vec2_control_class &c, const sx::vec<float,2> &v) { shade.implementation().window_set_vec2_control_value(*this, c, v); }
		sx::vec<float,2> get_vec2_control_value (plugin_vec2_control_class &c) { return shade.implementation().window_get_vec2_control_value(*this, c); }
		plugin_vec3_control_class &create_vec3_control (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_vec3_control(*this, handler, control_id, x, y, dx, dy, title); }
		void set_vec3_control_value (plugin_vec3_control_class &c, const sx::vec<float,3> &v) { shade.implementation().window_set_vec3_control_value(*this, c, v); }
		sx::vec<float,3> get_vec3_control_value (plugin_vec3_control_class &c) { return shade.implementation().window_get_vec3_control_value(*this, c); }
		plugin_vec4_control_class &create_vec4_control (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_vec4_control(*this, handler, control_id, x, y, dx, dy, title); }
		void set_vec4_control_value (plugin_vec4_control_class &c, const sx::vec<float,4> &v) { shade.implementation().window_set_vec4_control_value(*this, c, v); }
		sx::vec<float,4> get_vec4_control_value (plugin_vec4_control_class &c) { return shade.implementation().window_get_vec4_control_value(*this, c); }
		plugin_quaternion_control_class &create_quaternion_control (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_quaternion_control(*this, handler, control_id, x, y, dx, dy, title); }
		void set_quaternion_value (plugin_quaternion_control_class &c, const quaternion_class &v) { shade.implementation().window_set_quaternion_control_value(*this, c, v); }
		quaternion_class get_quaternion_value (plugin_quaternion_control_class &c) { return shade.implementation().window_get_quaternion_control_value(*this, c); }
		plugin_matrix_control_class &create_matrix_control (handler_interface &handler, int control_id, int x, int y, int dx, int dy, const char*title, void* aux =0) { return shade.implementation().window_create_matrix_control(*this, handler, control_id, x, y, dx, dy, title); }
		void set_matrix_control_value (plugin_matrix_control_class &c, const mat4 &v) { shade.implementation().window_set_matrix_control_value(*this, c, v); }
		mat4 get_matrix_control_value (plugin_matrix_control_class &c) { return shade.implementation().window_get_matrix_control_value(*this, c); }
		plugin_scale_control_class &create_scale_control (handler_interface &handler, int control_id, int x, int y, const char*title, void* aux =0) { return shade.implementation().window_create_scale_control(*this, handler, control_id, x, y, title); }
		void set_scale_control_value (plugin_scale_control_class &c, int s) { shade.implementation().window_set_scale_control_value(*this, c, s); }
		int get_scale_control_value (plugin_scale_control_class &c) { return shade.implementation().window_get_scale_control_value(*this, c); }
		plugin_flasher_class &create_flasher (handler_interface &handler, int control_id, int x, int y, int dx, int dy, void* aux =0) { return shade.implementation().window_create_flasher(*this, handler, control_id, x, y, dx, dy); }
		plugin_table_control_class &create_table_control (handler_interface &handler, int control_id, int x, int y, int dx, int dy, void* aux =0) { return shade.implementation().window_create_table_control(*this, handler, control_id, x, y, dx, dy); }
		void insert_table_column (plugin_table_control_class &c, table_cell_type_enum type, int width, const char *label, int col) { shade.implementation().window_insert_table_column(*this, c, type, width, label, col); }
		void remove_table_column (plugin_table_control_class &c, int row) { shade.implementation().window_remove_table_column(*this, c, row); }
		void insert_table_row (plugin_table_control_class &c, int row) { shade.implementation().window_insert_table_row(*this, c, row); }
		void remove_table_row (plugin_table_control_class &c, int row) { shade.implementation().window_remove_table_row(*this, c, row); }
		void clear_table (plugin_table_control_class &c) { shade.implementation().window_clear_table(*this, c); }
		void set_bool_value (plugin_table_control_class &c, int row, int col, bool value) { shade.implementation().window_set_table_bool_value(*this, c, row, col, value); }
		void set_int_value (plugin_table_control_class &c, int row, int col, int value) { shade.implementation().window_set_table_int_value(*this, c, row, col, value); }
		void set_float_value (plugin_table_control_class &c, int row, int col, float value) { shade.implementation().window_set_table_float_value(*this, c, row, col, value); }
		void set_string_value_deprecated (plugin_table_control_class &c, int row, int col, const std::string &value) { shade.implementation().window_set_table_string_value_deprecated(*this, c, row, col, value); }
		void set_string_value (plugin_table_control_class &c, int row, int col, const char* value) { shade.implementation().window_set_table_string_value(*this, c, row, col, value); }
		void set_color_value (plugin_table_control_class &c, int row, int col, const sx::rgb<float> &value) { shade.implementation().window_set_table_color_value(*this, c, row, col, value); }
		bool get_bool_value (plugin_table_control_class &c, int row, int col) { return shade.implementation().window_get_table_bool_value(*this, c, row, col); }
		int get_int_value (plugin_table_control_class &c, int row, int col) { return shade.implementation().window_get_table_int_value(*this, c, row, col); }
		float get_float_value (plugin_table_control_class &c, int row, int col) { return shade.implementation().window_get_table_float_value(*this, c, row, col); }
		std::string get_string_value_deprecated (plugin_table_control_class &c, int row, int col) { return shade.implementation().window_get_table_string_value_deprecated(*this, c, row, col); }
		const char* get_string_value (plugin_table_control_class &c, int row, int col) { return shade.implementation().window_get_table_string_value(*this, c, row, col); }
		sx::rgb<float> get_color_value (plugin_table_control_class &c, int row, int col) { return shade.implementation().window_get_table_color_value(*this, c, row, col); }
		void set_table_style (plugin_table_control_class &c, int mode) { shade.implementation().window_set_table_style(*this, c, mode); }
		int get_table_style (plugin_table_control_class &c) { return shade.implementation().window_get_table_style(*this, c); }
		void select (plugin_table_control_class &c, int row) { shade.implementation().window_select_table_item(*this, c, row); }
		void select_all (plugin_table_control_class &c, bool b) { shade.implementation().window_select_all_table_items(*this, c, b); }
		int number_of_selected_items (plugin_table_control_class &c) { return shade.implementation().window_number_of_selected_table_items(*this, c); }
		int first_selected_item (plugin_table_control_class &c) { return shade.implementation().window_get_first_selected_table_item(*this, c); }
		int next_selected_item (plugin_table_control_class &c, int index) { return shade.implementation().window_get_next_selected_table_item(*this, c,index); }
		bool has_selection (plugin_table_control_class &c) { return shade.implementation().window_table_has_selection(*this, c); }
		void check_all (plugin_table_control_class &c, int col, int b) { shade.implementation().window_check_all_table_items(*this, c, col, b); }
		int first_checked_item (plugin_table_control_class &c, int col) { return shade.implementation().window_get_first_checked_table_item(*this, c, col); }
		int next_checked_item (plugin_table_control_class &c, int col, int index) { return shade.implementation().window_get_next_checked_table_item(*this, c, col, index); }
		bool has_checked (plugin_table_control_class &c, int col) { return shade.implementation().window_table_item_has_check(*this, c, col); }
		bool is_selected (plugin_table_control_class &c, int row) { return shade.implementation().window_get_table_item_selected(*this, c, row); }
		void set_selected (plugin_table_control_class &c, int row, bool b) { shade.implementation().window_set_table_item_selected(*this, c, row, b); }
		bool is_active_row (plugin_table_control_class &c, int row) { return shade.implementation().window_get_table_item_active(*this, c, row); }
		void set_active_row (plugin_table_control_class &c, int row, bool b) { shade.implementation().window_set_table_item_active(*this, c, row, b); }
		bool is_active_cell (plugin_table_control_class &c, int row, int col) { return shade.implementation().window_get_table_cell_active(*this, c, row, col); }
		void set_active_cell (plugin_table_control_class &c, int row, int col, bool b) { shade.implementation().window_set_table_cell_active(*this, c, row, col, b); }
		int number_of_rows (plugin_table_control_class &c) { return shade.implementation().window_get_number_of_table_rows(*this, c); }
		int number_of_columns (plugin_table_control_class &c) { return shade.implementation().window_get_number_of_table_columns(*this, c); }
		void set_editable_text_string_value (plugin_editable_text_class &c, const char *s) { shade.implementation().window_set_editable_text_string_value(*this, c, s); }
		const char *get_editable_text_string_value (plugin_editable_text_class &c) { return shade.implementation().window_get_editable_text_string_value(*this, c); }
		int get_focused (xshade::control::control_class &c) { return shade.implementation().control_get_focused(c); }
	public:
		shade_interface &shade;
		xshade::window_class *w; // xshade::window_class is opaque to plugins
	};

	class aggregate_view_interface : public window_interface {
	public:
	virtual void eject_all (void* aux = 0) = 0; // 0
	virtual void uneject_all (void* aux = 0) = 0; // 1
	virtual void eject_camera (void* aux = 0) = 0; // 2
	virtual void uneject_camera (void* aux = 0) = 0; // 3
	virtual void select_camera (void* aux = 0) = 0; // 4
	virtual void eject_distant_light (void* aux = 0) = 0; // 5
	virtual void uneject_distant_light (void* aux = 0) = 0; // 6
	virtual void select_distant_light (void* aux = 0) = 0; // 7
	virtual void eject_background (void* aux = 0) = 0; // 8
	virtual void uneject_background (void* aux = 0) = 0; // 9
	virtual void select_background (void* aux = 0) = 0; // 10
	virtual void eject_surface (void* aux = 0) = 0; // 11
	virtual void uneject_surface (void* aux = 0) = 0; // 12
	virtual void select_surface (void* aux = 0) = 0; // 13
	virtual int aggregate_view_interface_dummy14(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 14
	virtual int aggregate_view_interface_dummy15(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 15
	virtual int aggregate_view_interface_dummy16(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 16
	virtual int aggregate_view_interface_dummy17(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 17
	virtual int aggregate_view_interface_dummy18(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 18
	virtual int aggregate_view_interface_dummy19(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 19
	virtual void eject_object_info (void* aux = 0) = 0; // 20
	virtual void uneject_object_info (void* aux = 0) = 0; // 21
	virtual void select_object_info (void* aux = 0) = 0; // 22
	virtual camera_view_interface* get_camera_view_interface (void * = 0) const = 0; // 23
	virtual distant_light_view_interface* get_distant_light_view_interface (void * = 0) const = 0; // 24
	virtual background_view_interface* get_background_view_interface (void * = 0) const = 0; // 25
	virtual surface_view_interface* get_surface_view_interface (void * = 0) const = 0; // 26
	virtual int aggregate_view_interface_dummy27(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 27
	virtual int aggregate_view_interface_dummy28(void *) { assert(false); throw "invalid interface aggregate_view_interface"; return 0; } // 28
	virtual object_info_view_interface* get_object_info_view_interface (void * = 0) const = 0; // 29
	};

	class rendering_options_view_interface : public window_interface {
	public:
	virtual void select_basics (void* aux = 0) = 0; // 0
	virtual void select_image (void* aux = 0) = 0; // 1
	virtual void select_global_illumination (void* aux = 0) = 0; // 2
	virtual void select_effects (void* aux = 0) = 0; // 3
	virtual void select_multipass (void* aux = 0) = 0; // 4
	virtual void select_misc (void* aux = 0) = 0; // 5
	};

	class image_view_interface : public window_interface {
	public:
	virtual void show_options (void* aux = 0) = 0; // 0
	virtual void hide_options (void* aux = 0) = 0; // 1
	virtual rendering_options_view_interface* get_rendering_options_view_interface (void * = 0) const = 0; // 2
	};

	class tool_box_view_interface : public window_interface {
	public:
	virtual tool_box_view_interface &set_memory_disclosed (bool memory_disclosed_param, void * = 0) = 0; // 0
	virtual bool get_memory_disclosed (void * = 0) const = 0; // 1
	};

	class color_view_interface : public window_interface {
	public:
	virtual color_view_interface &set_hsv_disclosed (bool hsv_disclosed_param, void * = 0) = 0; // 0
	virtual bool get_hsv_disclosed (void * = 0) const = 0; // 1
	virtual color_view_interface &set_lists_disclosed (bool lists_disclosed_param, void * = 0) = 0; // 2
	virtual bool get_lists_disclosed (void * = 0) const = 0; // 3
	};

	class background_view_interface : public window_interface {
	public:
	};

	class surface_view_interface : public window_interface {
	public:
	virtual void update_preview_image (void* aux = 0) = 0; // 0
	};

	class browser_view_interface : public window_interface {
	public:
	};

	class camera_view_interface : public window_interface {
	public:
	virtual camera_view_interface &set_disclosed (bool disclosed_param, void * = 0) = 0; // 0
	virtual bool get_disclosed (void * = 0) const = 0; // 1
	};

	class distant_light_view_interface : public window_interface {
	public:
	};

	class correction_view_interface : public window_interface {
	public:
	};

	class ruler_view_interface : public window_interface {
	public:
	};

	class message_view_interface : public window_interface {
	public:
	virtual void clear_message (void* aux = 0) = 0; // 0
	virtual message_view_interface &set_message (const char* message_param, void * = 0) = 0; // 1
	virtual const char* get_message (void * = 0) const = 0; // 2
	};

	class script_view_interface : public window_interface {
	public:
	};

	class shortcut_view_interface : public window_interface {
	public:
	};

	class radiosity_options_view_interface : public window_interface {
	public:
	virtual void select_exposure (void* aux = 0) = 0; // 0
	virtual void select_display (void* aux = 0) = 0; // 1
	virtual void select_solution (void* aux = 0) = 0; // 2
	};

	class radiosity_view_interface : public window_interface {
	public:
	virtual void show_options (void* aux = 0) = 0; // 0
	virtual void hide_options (void* aux = 0) = 0; // 1
	virtual radiosity_options_view_interface* get_radiosity_options_view_interface (void * = 0) const = 0; // 2
	};

	class skin_view_interface : public window_interface {
	public:
	};

	class motion_view_interface : public window_interface {
	public:
	};

	class object_info_view_interface : public window_interface {
	public:
	};

	class control_bar_interface : public window_interface {
	public:
	};

	class status_bar_interface : public window_interface {
	public:
	virtual void add_message (const char* key, const char* message, void* aux = 0) = 0; // 0
	virtual void remove_message (const char* key, void* aux = 0) = 0; // 1
	virtual void start_indicator (const char* key, void* aux = 0) = 0; // 2
	virtual void stop_indicator (const char* key, void* aux = 0) = 0; // 3
	};

	class figure_view_interface : public window_interface {
	public:
	virtual void pick (const sx::rectangle_class& area, void* aux = 0) = 0; // 0
	virtual void wait (void* aux = 0) = 0; // 1
	virtual int get_redraw_time (void * = 0) const = 0; // 2
	virtual figure_view_interface &set_redraw_time (int redraw_time_param, void * = 0) = 0; // 3
	virtual void update (int viewmask = 15, void* aux = 0) = 0; // 4
	virtual int get_redraw_count (void * = 0) const = 0; // 5
	};

	class figure_window_interface : public window_interface {
	public:
	virtual sxsdk::control_bar_interface* get_control_bar_interface (void * = 0) const = 0; // 0
	virtual sxsdk::figure_view_interface* get_figure_view_interface (void * = 0) const = 0; // 1
	virtual sxsdk::status_bar_interface* get_status_bar_interface (void * = 0) const = 0; // 2
	};

	class image_window_interface : public window_interface {
	public:
	virtual image_view_interface* get_image_view_interface (void * = 0) const = 0; // 0
	};

	class tool_box_window_interface : public window_interface {
	public:
	virtual tool_box_view_interface* get_tool_box_view_interface (void * = 0) const = 0; // 0
	};

	class color_window_interface : public window_interface {
	public:
	virtual color_view_interface* get_color_view_interface (void * = 0) const = 0; // 0
	};

	class background_window_interface : public window_interface {
	public:
	virtual background_view_interface* get_background_view_interface (void * = 0) const = 0; // 0
	};

	class surface_window_interface : public window_interface {
	public:
	virtual surface_view_interface* get_surface_view_interface (void * = 0) const = 0; // 0
	};

	class browser_window_interface : public window_interface {
	public:
	virtual browser_view_interface* get_browser_view_interface (void * = 0) const = 0; // 0
	};

	class correction_window_interface : public window_interface {
	public:
	virtual correction_view_interface* get_correction_view_interface (void * = 0) const = 0; // 0
	};

	class camera_window_interface : public window_interface {
	public:
	virtual camera_view_interface* get_camera_view_interface (void * = 0) const = 0; // 0
	};

	class distant_light_window_interface : public window_interface {
	public:
	virtual distant_light_view_interface* get_distant_light_view_interface (void * = 0) const = 0; // 0
	};

	class ruler_window_interface : public window_interface {
	public:
	virtual ruler_view_interface* get_ruler_view_interface (void * = 0) const = 0; // 0
	};

	class message_window_interface : public window_interface {
	public:
	virtual message_view_interface* get_message_view_interface (void * = 0) const = 0; // 0
	};

	class script_window_interface : public window_interface {
	public:
	virtual script_view_interface* get_script_view_interface (void * = 0) const = 0; // 0
	};

	class shortcut_window_interface : public window_interface {
	public:
	virtual shortcut_view_interface* get_shortcut_view_interface (void * = 0) const = 0; // 0
	};

	class radiosity_window_interface : public window_interface {
	public:
	virtual radiosity_view_interface* get_radiosity_view_interface (void * = 0) const = 0; // 0
	};

	class skin_window_interface : public window_interface {
	public:
	virtual skin_view_interface* get_skin_view_interface (void * = 0) const = 0; // 0
	};

	class motion_window_interface : public window_interface {
	public:
	virtual motion_view_interface* get_motion_view_interface (void * = 0) const = 0; // 0
	};

	class object_info_window_interface : public window_interface {
	public:
	virtual object_info_view_interface* get_object_info_view_interface (void * = 0) const = 0; // 0
	};

	class aggregate_window_interface : public window_interface {
	public:
	virtual aggregate_view_interface* get_aggregate_view_interface (void * = 0) const = 0; // 0
	};

	class meshtools_window_interface : public window_interface {
	public:
	virtual meshtools_view_interface* get_meshtools_view_interface (void * = 0) const = 0; // 0
	};

	class gridmanager_view_interface : public window_interface {
	public:
	virtual int get_server_total (void* aux = 0) = 0; // 0
	virtual const char * get_server_name (int i, void* aux = 0) = 0; // 1
	virtual const char * get_server_ip (int i, void* aux = 0) = 0; // 2
	virtual bool get_server_check (int i, void* aux = 0) = 0; // 3
	virtual void set_server_check (int i, bool useit, void* aux = 0) = 0; // 4
	virtual void remove_server (int i, void* aux = 0) = 0; // 5
	virtual void refresh_server_list (void* aux = 0) = 0; // 6
	virtual void add_server (const char* name, const char* ip) = 0; // 7
	virtual const char * get_server_version (int i, void* aux = 0) = 0; // 8
	virtual const char * get_server_os (int i, void* aux = 0) = 0; // 9
	};

	class gridmanager_window_interface : public window_interface {
	public:
	virtual gridmanager_view_interface* get_gridmanager_view_interface (void * = 0) const = 0; // 0
	};
}
#if _MSC_VER
	#pragma warning(pop)
#endif
