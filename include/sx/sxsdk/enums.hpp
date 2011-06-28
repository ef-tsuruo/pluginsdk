#pragma once

namespace sx {
	/// dialog_item
	namespace dialog_item {
		/// \en Dialog item actions \enden \ja ダイアログアイテムに対してされた動作の詳細。\c dialog_interface::respond() の引数として渡される。\endja
		enum item_action_enum {
			generic_action,		///< \en Default action such as completion of changing the value, clicking button. \enden \ja デフォルトアクション(数値、文字列入力の確定、ボタンのクリック)\endja
			step_down_action,	///< \en Step up button clicked \enden \ja 数値入力のステップダウンボタン\endja
			step_up_action,		///< \en Step down button clicked  \enden \ja 数値入力のステップアップボタン\endja
			track_action,		///< \en Slider is being tracked \enden \ja スライダコントロールのドラッグ\endja
			changing_action,	///< \en blah \enden \ja テキストボックス(数値、文字列)の値を変更したとき\endja
			item_changed,		///< \en blah \enden \ja リストボックスのアイテムのテキストを変更したとき\endja
			item_checked,		///< \en blah \enden \ja リストボックスのアイテムのチェックボックスを変更したとき\endja
		};
		/// \en Dialog item flags \enden \ja interfaceからダイアログアイテムを追加するときの追加設定フラグ\endja
		enum item_flag {
			terminator		=  0x01,	///< \en blah \enden \ja ダイアログを閉じるボタン(push_button)\endja
			bordered		=  0x02,	///< \en blah \enden \ja 枠なしのボタン(push_button, bool)\endja
			pushon_pushoff	=  0x04,	///< \en blah \enden \ja プッシュボタン型のチェックボックス(bool)\endja
			read_only		=  0x08,	///< \en blah \enden \ja テキストボックスの編集可、不可(string, text, listbox)\endja
			short_text		=  0x10,	///< \en blah \enden \ja 短いテキストボックス(string, text)\endja
			secure			=  0x20,	///< \en blah \enden \ja パスワード入力用のテキストボックス(string)\endja
			slider			=  0x40,	///< \en blah \enden \ja スライダを追加(float, double)\endja
			stepper			=  0x80,	///< \en blah \enden \ja ステッパを追加(int)\endja
			swap_boxes		= 0x100,	///< \en blah \enden \ja 直下にboxを複数配置すると、そのうち1つだけを表示する。\c set_selection()で表示されるboxを切り替えることができる。(group)\endja
			has_checkbox	= 0x200,	///< \en blah \enden \ja リストボックスにチェックボックスを追加\endja
			vertical		= 0x400,	///< \en blah \enden \ja ラジオボタンのアイテムを縦に配置する\endja
			horizontal		= 0x800,	///< \en blah \enden \ja ラジオボタンのアイテムを横に配置する\endja
			square			= 0x1000,	///< \en blah \enden \ja 角の四角いフラットなプッシュボタン（push_button Mac OS X only）\endja
		};
	}
	/// \en blah \enden \ja ダイアログの基本的なボタンのitem_id \endja
	enum dialog_item_id {
		idok = 1,		///< \en blah \enden \ja OKボタン \endja
		idcancel = 2,	///< \en blah \enden \ja キャンセルボタン \endja
		idreset = 3,	///< \en blah \enden \ja 復帰ボタン \endja
		iddefault = 4,	///< \en blah \enden \ja 初期設定ボタン \endja
	};
	/// \en Window flags \enden \ja ウインドウのフラグ \endja
	enum window_flag {
		h_resizeable = 0x02,							///< \en The window is horizontally resizable. Only applicable to a root level window.\enden \ja サイズ変更可能なウィンドウ（vとhの区別は無し）\endja
		v_resizeable = 0x04,							///< \en The window is vertically resizable. Only applicable to a root level window.\enden \ja サイズ変更可能なウィンドウ（vとhの区別は無し）\endja
		resizable = (h_resizeable | v_resizeable),		///< \en The window is horizontally and vertically resizable. Only applicable to a root level window.\enden \ja サイズ変更可能なウィンドウ（vとhの区別は無し）(== h_resizeable | v_resizeable)\endja
		h_scroll = 0x08,								///< \en The window is horizontally scrollable.\enden \ja 水平スクロール可能なウィンドウ\endja
		v_scroll = 0x10,								///< \en The window is vertically scrollable.\enden \ja 垂直スクロール可能なウィンドウ\endja
		hv_scroll = (h_scroll | v_scroll),				///< \en The window is horizontally and vertically scrollable.\enden \ja 水平および垂直スクロール可能なウィンドウ (== h_scroll | v_scroll)\endja
		h_scroll_bar = 0x20,							///< \en The window has a horizontal scroll bar.\enden \ja 水平スクロールバーをもつウィンドウ\endja
		v_scroll_bar = 0x40,							///< \en The window has a vertical scroll bar.\enden \ja 垂直スクロールバーをもつウィンドウ\endja
		hv_scroll_bar = (h_scroll_bar | v_scroll_bar),	///< \en The window has a vertical scroll bar and a vertical scroll bar.\enden \ja 水平および垂直スクロールバーをもつウィンドウ (== h_scroll_bar | v_scroll_bar)\endja
		maximize = 0x80,								///< \en The window is maximizable. Only applicable to a root level window. May not be supported depending on platforms.\enden \ja Win版のみ実装 最大化可能なウィンドウ\endja
		maximize_box = 0x100,							///< \en The window has a maximize button. Only applicable to a root level window. May not be supported depending on platforms or the type of the window.\enden \ja Win版のみ実装 最大化ボックスをもつウィンドウ\endja
		minimize_box = 0x200,							///< \en The window has a minimize button. Only applicable to a root level window. May not be supported depending on platforms or the type of the window.\enden \ja Win版のみ実装 最小化ボックスをもつウィンドウ\endja
		zoomable = 0x400,								///< \en The window is zoomable. Only applicable to a root level window. May not be supported depending on platforms or the type of the window.\enden \ja ズーム可能なウインドウウィンドウ\endja
		opengl_window = 0x800,							///< \en The plugin supports OpenGL.\enden \ja OpenGLをサポートするプラグインウインドウ\endja
		no_title_bar = 0x1000,							///< \en The window has no title bar. Only applicable to a root level window.\enden \ja タイトルバーのないウィンドウ\endja
		text_window = 0x2000,							///< \en The window is a text field. Editable and multi-lined by default. Only applicable to a child window.\enden \ja このフラグを指定したウィンドウはエディットテキストになる。enums::edit_text_controlとの違いはOSX版でMLTE(MuitiLingualTextEngine)が使われることです。Win版はともにCRichEditCtrlが使われる。\endja
		size_box = 0x4000,								///< \en The window is has a size box. Only applicable to a root level window. May not be supported depending on platforms or the type of the window.\enden \ja 未使用\endja
		auto_center = 0x8000,								///< \en  \ja \endja
		scalable = 0x40000,								///< \en The window's display can be magnified and shrunk using mouse wheel.\enden \ja 内部で使用\endja
		grouped_window = 0x200000,						///< \en The window is a grouped window which is not confined within its parent window's client area. Only applicable to a child window. Supported only on Mac OS X.\enden \ja Mac OS X版のみ実装 グループウインドウ \endja
		readonly_text = 0x400000,						///< \en The text is NOT ediable. Use it with enums::text_window.\enden \ja 書き込み不可テキスト。enums::text_windowとともに用いる\endja
		single_line_text = 0x2000000,					///< \en The text is single-line. Use it with enums::text_window.\enden \ja 1行エディットテキスト。enums::text_windowまたはenums::edit_text_controlフラグとともに用いる\endja
		text_hscroll = 0x4000000,						///< \en The text is horizontally scrollable. Use it with enums::text_window.\enden \ja 水平スクロール可能なエディットテキスト\endja
		text_vscroll = 0x8000000,						///< \en The text is vertically scrollable. Use it with enums::text_window.\enden \ja 垂直スクロール可能なエディットテキスト\endja
		transient_window = 0x40000000,					///< \en transient\enden \ja transient\endja
		command_key_hook_enabled = 0x80000000,			///< \en enables command key hook for float window on mac\enden \ja Macintosh環境でツールウィンドウのCMDキーフックを行う\endja
		caption_bar = 0x10000,							///< \en forces caption bar in subwindow
	};
	/// \en Embedded mouse cursor \enden \ja マウスカーソル \endja
	enum mouse_cursor_enum {
		cursor_arrow,			///< \en An arrow shaped mouse pointer. \enden \ja デフォルトの矢印カーソル \endja
		cursor_cross,			///< \en A cross shaped mouse pointer. \enden \ja 十字カーソル \endja
		cursor_small_cross,		///< \en A small cross shaped mouse pointer. \enden \ja 小さな十字カーソル \endja
		cursor_small_cross_dot,	///< \en A small cross shaped mouse pointer with a dot mark. \enden \ja 小さな十字カーソル＋ドット \endja
		cursor_hand,			///< \en A hand shaped mouse pointer. \enden \ja 手のひらカーソル \endja
		cursor_pointing_hand,	///< \en A hand shaped mouse pointer. \enden \ja 指さした手のカーソル \endja
		cursor_h_arrow,			///< \en A horizontal arrow shaped mouse pointer. \enden \ja 水平サイズ変更カーソル \endja
		cursor_v_arrow,			///< \en A vertical arrow shaped mouse pointer. \enden \ja 垂直サイズ変更カーソル \endja
		cursor_hv_arrow,		///< \en A horizontal AND vertical arrow shaped mouse pointer. \enden \ja 水平垂直サイズ変更カーソル \endja
		cursor_shrink,			///< \en A shrink icon. \enden \ja 縮小カーソル \endja
		cursor_magnify,			///< \en A magnify icon. \enden \ja 拡大カーソル \endja
		cursor_neutral,			///< \en A neutral icon. \enden \ja blah \endja
		cursor_watch,			///< \en A watch icon. \enden \ja blah \endja
		cursor_add,				///< \en An append icon. \enden \ja blah \endja
		cursor_remove,			///< \en A remove icon. \enden \ja blah \endja
		cursor_rotate,			///< \en A rotate icon. \enden \ja blah \endja
		cursor_drag_panel,		///< \en A panel drag icon. \enden \ja blah \endja
		cursor_drag_panel_target, ///< \en A panel drag icon. \enden \ja blah \endja
		cursor_grab_hand,
		cursor_custom			///< \en End of embedded icon. \enden \ja 組み込みのマウスカーソルの終端 \endja
	};
	namespace key {
		/// \en Key flags \enden \ja キーフラグ \endja
		enum key_flag {
			option = 0x01,	///< Z(Win), option(Mac)
			command = 0x02,	///< X(Win), command(Mac)
			alt = 0x02,		///< Alt(Win)
			control = 0x04,	///< Ctrl(Win)
			shift = 0x08,	///< Shift(Win), shift(Mac)
			space = 0x10,	///< Space(Win), space(Mac)

			constraint = shift,
			range_selection = shift,
			#if SXMACOSX
				multiple_selection = command,
				extension = option,
				pure_extension = option
			#else
				multiple_selection = control,
				extension = (option | control),
				pure_extension = control
			#endif
		};
		/// \en Key codes \enden \ja キーコード \endja
		enum key_code {
			// ascii
			space_key			= ' ',
			tab_key				= '\t',
			backspace_key		= '\b',
			esc_key				= 27,
			delete_key			= 127,

			f1_key				= 0x100,
			f2_key				= 0x101,
			f3_key				= 0x102,
			f4_key				= 0x103,
			f5_key				= 0x104,
			f6_key				= 0x105,
			f7_key				= 0x106,
			f8_key				= 0x107,
			f9_key				= 0x108,
			f10_key				= 0x109,
			f11_key				= 0x10a,
			f12_key				= 0x10b,
			f13_key				= 0x10c,
			f14_key				= 0x10d,
			f15_key				= 0x10e,
			f16_key				= 0x10f,

			insert_key			= 0x200,
			pageup_key			= 0x201,
			pagedown_key		= 0x202,
			end_key				= 0x203,
			home_key			= 0x204,
			enter_key			= 0x205,

			left_key			= 0x300,
			up_key				= 0x301,
			right_key			= 0x302,
			down_key			= 0x303,

			numpad_0_key		= 0x400,
			numpad_1_key		= 0x401,
			numpad_2_key		= 0x402,
			numpad_3_key		= 0x403,
			numpad_4_key		= 0x404,
			numpad_5_key		= 0x405,
			numpad_6_key		= 0x406,
			numpad_7_key		= 0x407,
			numpad_8_key		= 0x408,
			numpad_9_key		= 0x409,
			numpad_asterisk_key	= 0x40a,
			numpad_slash_key	= 0x40b,
			numpad_minus_key	= 0x40c,
			numpad_plus_key		= 0x40d,
			numpad_dot_key		= 0x40e,

			// Windows only
			pause_key			= 0x500,
			num_lock_key		= 0x501,
			scroll_lock_key		= 0x502,
			caps_lock_key		= 0x503,

			ime_process_key		= 0x504,
			convert_key			= 0x505,
			nonconvert_key		= 0x506,
			clear_key			= 0x507,

			// accelerator keys
			option_key			= 0x801,	///< Z(Win), option(Mac)
			command_key			= 0x802,	///< X(Win), command(Mac)
			alt_key				= 0x803,	///< Alt(Win)
			control_key			= 0x804,	///< Ctrl(Win)
			shift_key			= 0x805,	///< Shift(Win), shift(Mac)
		};
	}
}
