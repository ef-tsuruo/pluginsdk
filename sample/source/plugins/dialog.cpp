#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_DIALOG0_ID	("F4060A64-549F-11D9-84E6-000A95BACEB2");
	const sx::uuid_class SIMPLE_DIALOG1_ID	("F8A008B2-549F-11D9-8B23-000A95BACEB2");
	const sx::uuid_class SIMPLE_DIALOG2_ID	("FCCE8321-549F-11D9-B12D-000A95BACEB2");
	const sx::uuid_class SIMPLE_DIALOG3_ID	("016FEDEC-54A0-11D9-A4E1-000A95BACEB2");
	const sx::uuid_class SIMPLE_DIALOG4_ID	("069AEB5A-54A0-11D9-A0A2-000A95BACEB2");
	const sx::uuid_class SIMPLE_DIALOG5_ID	("0B01D6C0-54A0-11D9-BA85-000A95BACEB2");
}

//  \en simple_dialog0 is an example of the most typical usage of a dialog box. \enden \ja simple_dialog0は最も典型的なダイアログボックスの実装例 \endja 
//  \en It loads dialog items and strings from SXUL resource files, and respnds to user actions with overridden respond() function. \enden \ja SXULファイルとして定義されたダイアログアイテムと文字列を読み込み、オーバライドしたrespond関数でユーザの操作を待ち受ける。 \endja 
namespace {
	class simple_dialog0 : public sxsdk::plugin_interface {
	public:
		explicit simple_dialog0 (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		enum {
			short_string_id = 100, long_string_id = 101, long_text_id = 102, push_button0_id = 103, push_button1_id = 104, push_button2_id = 105, check_box_id = 106, int_id = 107, int_with_stepper_id = 108,
			float_id = 109, float_with_slider_id = 110, double_id = 111, selection_id = 112, rgb_id = 113, vec3_id = 114, custom_id = 115, listbox_id = 116
		};
		sxsdk::shade_interface &shade;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void * = 0) { return SIMPLE_DIALOG0_ID; }
		virtual void do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *);
		virtual void initialize_dialog (sxsdk::dialog_interface &d, void *);
		virtual bool respond (sxsdk::dialog_interface &d, sxsdk::dialog_item_class &item, int action, void *);
		virtual void load_dialog_data (sxsdk::dialog_interface &d, void *);
		virtual void save_dialog_data (sxsdk::dialog_interface &d, void *);
		virtual int terminate (sxsdk::dialog_interface &d, int result, void *);
	};
}
void simple_dialog0::do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *) {
	compointer<sxsdk::strings_interface> strings(shade.create_strings_interface("simple_strings_id"));
	compointer<sxsdk::dialog_interface> d(shade.create_dialog_interface_with_uuid(SIMPLE_DIALOG0_ID));
	d->set_title(strings->get_string(0));
	d->set_resource_name("simple_dialog");
	d->set_responder(this);
	d->ask();
}
void simple_dialog0::initialize_dialog (sxsdk::dialog_interface &d, void *) {
//	sxsdk::dialog_item_class &i = d.get_dialog_item(listbox_id);
//	i.append_listbox_item("item0", true);
//	i.append_listbox_item("item1", false);
//	i.append_listbox_item("item2", true);
//	i.append_listbox_item("item3", false);
//	i.append_listbox_item("item4", true);
//	i.append_listbox_item("item5", false);
//	i.append_listbox_item("item6", true);
//	i.append_listbox_item("item7", false);
	//d.get_dialog_item(short_string_id).set_string("short-string").set_tooltip("tooltipttoooo");
	//d.get_dialog_item(short_string_id).set_string("short-string").set_enabled(false);
	//d.get_dialog_item(long_string_id).set_string("long-string").set_enabled(false);
	//d.get_dialog_item(long_text_id).set_text("text0\ntext1").set_enabled(false);
	//d.get_dialog_item(check_box_id).set_bool(true).set_enabled(false);
	//d.get_dialog_item(int_id).set_int(100).set_enabled(false);
	//d.get_dialog_item(int_with_stepper_id).set_int(200).set_enabled(false);
	//d.get_dialog_item(float_id).set_float(123.45).set_enabled(false);
	//d.get_dialog_item(float_with_slider_id).set_float(0.5).set_enabled(false);
	//d.get_dialog_item(double_id).set_double(2.5).set_enabled(false);
	//d.get_dialog_item(selection_id).set_selection(2).set_enabled(false);
	//d.get_dialog_item(rgb_id).set_rgb(sx::vec<float,3>(1,0,0)).set_enabled(false);
	//d.get_dialog_item(vec3_id).set_vec3(sx::vec<float,3>(0,1,2)).set_enabled(false);
}
bool simple_dialog0::respond (sxsdk::dialog_interface &d, sxsdk::dialog_item_class &item, int action, void *) {
	//std::string m = "";
	//switch (action) {
	//case sx::dialog_item::step_down_action:	m += "step_down: ";	break;
	//case sx::dialog_item::step_up_action:	m += "step_up: ";	break;
	//case sx::dialog_item::track_action:		m += "tracking : ";	break;
	//case sx::dialog_item::changing_action:	m += "changing : ";	break;
	//}
	//sxsdk::dialog_item_class &message = d.get_dialog_item(long_text_id);
	//switch (item.get_id()) {
	//case short_string_id:		message.set_text(m + "short_string changed"); return true;
	//case long_string_id:		message.set_text(m + "long_string changed"); return true;
	//case push_button0_id:		message.set_text(m + "push_button0 clicked"); return true;
	//case push_button1_id:		message.set_text(m + "push_button1 clicked"); return true;
	//case push_button2_id:		message.set_text(m + "push_button2 clicked"); return true;
	//case check_box_id:			message.set_text(m + "check_box clicked"); return true;
	//case int_id:				message.set_text(m + "int changed"); return true;
	//case int_with_stepper_id:   message.set_text(m + "int_with_stepper changed"); return true;
	//case float_id:				message.set_text(m + "float changed"); return true;
	//case float_with_slider_id:  message.set_text(m + "float_with_slider changed"); return true;
	//case double_id:				message.set_text(m + "double changed"); return true;
	//case selection_id:			message.set_text(m + "selection changed"); return true;
	//case rgb_id:				message.set_text(m + "rgb changed"); return true;
	//case vec3_id:				message.set_text(m + "sx::vec<float,3> changed"); return true;
	//case custom_id:				message.set_text(m + "custom clicked"); return true;
	//}
	return false;
}
void simple_dialog0::load_dialog_data (sxsdk::dialog_interface &d, void *) {
	shade.message("load_dialog_data called");
}
void simple_dialog0::save_dialog_data (sxsdk::dialog_interface &d, void *) {
	shade.message("save_dialog_data called");
}
int simple_dialog0::terminate (sxsdk::dialog_interface &d, int result, void *) {
	shade.message("terminate called");
	return result;
}

//  \en simple_dialog1 shows you how to hard-code dialog box creation (rather than to read from resources). \enden \ja ダイアログボックスの生成を（リソースから読み込むのではなく）ハードコードした例 \endja 
//  \en This method is not recomended for production quality plugin, but a quick way to write a simple plugin. \enden \ja この方法はエンドユーザに配布する製品としてのプラグインには適さないが、ダイアログボックスを簡単に作成することができる。 \endja 
namespace {
	class simple_dialog1 : public sxsdk::plugin_interface {
	public:
		explicit simple_dialog1 (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		sxsdk::shade_interface &shade;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void * = 0) { return SIMPLE_DIALOG1_ID; }
		virtual void do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *);
	};
}
void simple_dialog1::do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *) {
	compointer<sxsdk::dialog_interface> d(shade.create_dialog_interface(0));
	d->set_title("title");
	d->append_bool("bool");
	d->append_int("int");
	d->append_float("float");
	d->append_double("double");
	d->append_vec3("vec3");
	d->append_rgb("rgb");
	d->append_selection("sel/1/2/3");
	d->append_string("string");
	d->append_short_string("shortstring");
	d->begin_group("group");
	d->append_text("test", 3);
	d->end_group();
	d->ask();
}

//  \en simple_dialog2 shows you how to create a tabbed dialog. \enden \ja タブビュー付きダイアログボックスの例 \endja 
//  \en This example hard-codes the dialog creation for simplicity, but the same thing can be done with SXUL resources. \enden \ja この例ではハードコードしているが、同様のことをSXULリソースで定義することも可能。 \endja 
namespace {
	class simple_dialog2 : public sxsdk::plugin_interface {
	public:
		explicit simple_dialog2 (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		sxsdk::shade_interface &shade;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void * = 0) { return SIMPLE_DIALOG2_ID; }
		virtual void do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *);
	};
}
void simple_dialog2::do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *) {
	compointer<sxsdk::dialog_interface> d(shade.create_dialog_interface(0));
	d->set_title("title");
	d->begin_tab_group("tab0");
	d->append_bool("bool0");
	d->end_tab_group();
	d->begin_tab_group("tab1");
	d->append_bool("bool1");
	d->end_tab_group();
	d->begin_tab_group("tab2");
	d->append_bool("bool2");
	d->end_tab_group();
	d->ask();
}

//  \en simple_dialog3 shows you how to respond to each item individually. \enden \ja それぞれのダイアログアイテムが個別にユーザの操作に対して反応する例 \endja 
//  \en This example hard-codes the dialog creation for simplicity, but the same thing can be done with SXUL resources. \enden \ja この例ではハードコードしているが、同様のことをSXULリソースで定義することも可能。 \endja 
namespace {
	class simple_dialog3 : public sxsdk::plugin_interface {
	public:
		explicit simple_dialog3 (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		class responder0_class : public sxsdk::plugin_interface {
		public:
			sxsdk::shade_interface &shade;

			explicit responder0_class (sxsdk::shade_interface &shade) : shade(shade) { }
		private:
			virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
			virtual bool respond (sxsdk::dialog_interface &d, sxsdk::dialog_item_class &item, int action, void *) {
				shade.message("bool0 clicked");
				return true;
			}
		};
		class responder1_class : public plugin_interface {
		public:
			explicit responder1_class (sxsdk::shade_interface &shade) : shade(shade) { }
		private:
			sxsdk::shade_interface &shade;

			virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
			virtual bool respond (sxsdk::dialog_interface &d, sxsdk::dialog_item_class &item, int command, void *) {
				shade.message("bool1 clicked");
				return true;
			}
		};
		sxsdk::shade_interface &shade;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void * = 0) { return SIMPLE_DIALOG3_ID; }
		virtual void do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *);
	};
}
void simple_dialog3::do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *) {
	compointer<sxsdk::dialog_interface> d(shade.create_dialog_interface(0));
	d->append_bool("bool0", 0, 0, new responder0_class(shade));
	d->append_bool("bool1", 0, 0, new responder1_class(shade));
	d->ask();
}

//  \en simple_dialog4 shows you how to use custom dialog items. \enden \ja カスタムダイアログアイテムの例 \endja 
//  \en This example hard-codes the dialog creation for simplicity, but the same thing can be done with SXUL resources. \enden \ja この例ではハードコードしているが、同様のことをSXULリソースで定義することも可能。 \endja 
namespace {
	class simple_dialog4 : public sxsdk::plugin_interface {
	public:
		explicit simple_dialog4 (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		class window_class : public sxsdk::window_interface {
		public:
			explicit window_class (sxsdk::shade_interface &shade, sxsdk::dialog_interface &dialog, sxsdk::dialog_item_class &item) : sxsdk::window_interface(shade, dialog, item, 0) { }
		private:
			virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
			virtual void paint (sxsdk::graphic_context_interface &gc, const sx::bounds<sx::vec<int,2> > *visible_rectangle, void *) {
				gc.line(0,0,128,128);
				gc.line(0,128,128,0);
			}
		};
		sxsdk::shade_interface &shade;
		int custom_item_id;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void * = 0) { return SIMPLE_DIALOG4_ID; }
		virtual void initialize_dialog (sxsdk::dialog_interface &dialog, void *);
		virtual void do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *);
	};
}
void simple_dialog4::initialize_dialog (sxsdk::dialog_interface &dialog, void *) {
	sxsdk::dialog_item_class &item = dialog.get_dialog_item(custom_item_id);
	compointer<sxsdk::window_interface> w(new window_class(shade, dialog, item), 1);
	item.set_window(w);
}
void simple_dialog4::do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *) {
	compointer<sxsdk::dialog_interface> d(shade.create_dialog_interface(0));
	custom_item_id = d->append_custom(sx::vec<int,2>(128, 128));
	d->set_responder(this);
	d->ask();
}

//  \en simple_dialog5 shows you how to property values are automatically saved and restored. \enden \ja ダイアログボックスのプロパティ値が自動的に保存、復帰される例 \endja 
//  \en This example hard-codes the dialog creation for simplicity, but the same thing can be done with SXUL resources. \enden \ja この例ではハードコードしているが、同様のことをSXULリソースで定義することも可能。 \endja 
//  \en If a dialog box is constructed with explicitly specified ID number, Shade automatically saves and restores the values so they appear persistent. \enden \ja ダイアログ生成時に明示的にID番号を指定すると、そのダイアログのプロパティ値が自動的に保存、復帰される。 \endja 
//  \en This example also shows you how to set default values and initial values. \enden \ja この例では、さらに、デフォルト値と初期値を設定する方法を示す。 \endja 
//  \en set_*_default specifies the value that is set when the Default button is clicked. \enden \ja set_*_default関数は、デフォルトボタンを押した際に設定される値を設定する。 \endja 
namespace {
	class simple_dialog5 : public sxsdk::plugin_interface {
	public:
		explicit simple_dialog5 (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		sxsdk::shade_interface &shade;
		int bool_id;
		int int_id;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void * = 0) { return SIMPLE_DIALOG5_ID; }
		virtual void initialize_dialog (sxsdk::dialog_interface &dialog, void *);
		virtual void do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *);
	};
}
void simple_dialog5::initialize_dialog (sxsdk::dialog_interface &dialog, void *) {
	dialog.get_dialog_item(bool_id).set_bool_default(true); //  \en The checkbox is set to true when the Default button is clicked. \enden \ja デフォルトボタンが押されると、チェックボックスがオンになる。 \endja 
	dialog.get_dialog_item(int_id).set_int_default(1);		//  \en The text box is set to "1" when the Default button is clicked. \enden \ja デフォルトボタンが押されると、テキストボックスが「１」になる。 \endja 
}
void simple_dialog5::do_it (sxsdk::shade_interface *, sxsdk::scene_interface *, void *) {
	compointer<sxsdk::dialog_interface> d(shade.create_dialog_interface_with_uuid(SIMPLE_DIALOG5_ID)); //  \en Specifiy an ID for the dialog. \enden \ja ダイアログ生成時にID番号を指定する。 \endja  
	d->set_title("title");
	d->append_default_button(); //  \en Create a dialog box with the Default button. \enden \ja ダイアログにデフォルトボタンを追加する。 \endja 
	bool_id = d->append_bool("bool");
	int_id = d->append_int("int");
	d->set_responder(this);
	d->ask();
}

SXPLUGINNAMESPACEBEGIN(test_dialog)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		unknown_interface *u = 0;
		switch (i) {
		case 0: u = new simple_dialog0(*shade); break;
		case 1: u = new simple_dialog1(*shade); break;
		case 2: u = new simple_dialog2(*shade); break;
		case 3: u = new simple_dialog3(*shade); break;
		case 4: u = new simple_dialog4(*shade); break;
		case 5: u = new simple_dialog5(*shade); break;
		}
		if (u) {
			u->AddRef();
			*p = (void *)u;
		}
	}
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == plugin_iid) return 6;
		return 0;
	}

	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		switch (i) {
		case 0: return shade->gettext("dialog 0");
		case 1: return shade->gettext("dialog 1");
		case 2: return shade->gettext("dialog 2");
		case 3: return shade->gettext("dialog 3");
		case 4: return shade->gettext("dialog 4");
		case 5: return shade->gettext("dialog 5");
		}
		return 0;
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		switch (i) {
		case 0: return SIMPLE_DIALOG0_ID;
		case 1: return SIMPLE_DIALOG1_ID;
		case 2: return SIMPLE_DIALOG2_ID;
		case 3: return SIMPLE_DIALOG3_ID;
		case 4: return SIMPLE_DIALOG4_ID;
		case 5: return SIMPLE_DIALOG5_ID;
		}
		return sx::uuid_class(0u);
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
