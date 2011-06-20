#include "sxsdk.cxx"

namespace {
	const sx::uuid_class LENSFLARE_EFFECTOR_ID("073AEC2B-8B7D-11D9-8C8B-000A95BACEB2");
	const sx::uuid_class SHOWALPHAZ_EFFECTOR_ID("D08D63A3-8C06-11D9-A057-000A95BACEB2");
}

namespace {
	class flare_function_class : public sxsdk::image_interface::smudge_function_class {
	public:
		flare_function_class () {
			for (int i = 0; i < N; i++) {
				x[i] = float(std::rand()) / float(RAND_MAX) * 3.14f;
				r[i] = float(std::rand()) / float(RAND_MAX) * 3.0f;
			}
		}
	private:
		enum { N = 10 };
		std::array<float, N> x;
		std::array<float, N> r;

		//  \en a function that defines shape of the lens flare \enden  \ja レンズフレアの形を定義する関数 \endja 
		float f (const sx::vec<float,2> &p, float w, float r) {
			const float Pi = 3.1415f;
			sx::vec<float,2> c(sxsdk::polar_to_cartesian(p));
			float k = std::pow((std::cos(c.x*Pi) + 1.0f) * 0.5f, w);
			return k * std::pow((std::cos(c.y*Pi) + 1.0f) * 0.5f, r);
		}
		virtual sx::rgba<float> function (const sx::vec<float,2> &p_) { //  \en p is in polar coordinates. \enden  \ja pは極座標 \endja 
			float k = 0.0f;
			for (int i = 0; i < N; i++) {
				sx::vec<float,2> p(p_);
				p.x += x[i];
				k += f(p, 200.0f, std::pow(2.0f, r[i])) * 0.3f;
			}
			return sx::rgba<float>(k, k, k, 1.0f);
		}
	};
}

//  \en Very simple lens flare implementation. \enden  \ja 簡単なレンズフレアの実装 \endja 
namespace {
	class lensflare_effector : public sxsdk::effector_interface {
	public:
		explicit lensflare_effector () : rendering_context(0), stream(0), default_size(20.0f) { }
	private:
		sxsdk::rendering_context_interface *rendering_context;
		sxsdk::stream_interface *stream;

		const float default_size;
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SHOWALPHAZ_EFFECTOR_ID; }
		//  \en A rendering image will contain Z data if needs_z() function returns true. \enden  \ja needs_z()をオーバライドしてtrueを返すと、Z値を持つレンダリングイメージが作成される。 \endja 
		virtual bool needs_z (void *) { return true; }
		//  \en ask() function gets called if can_ask() function returns true. \enden  \ja can_ask()をオーバライドしてtrueを返すと、ダイアログを表示するask()関数が呼ばれる。。 \endja 
		virtual bool can_ask (void *) { return true; } 
		//  \en The following ask() function displays a dialog. \enden  \ja ask()オーバライドしてダイアログを表示する。 \endja 
		virtual void ask (sxsdk::stream_interface *stream, void *);
		virtual void begin (sxsdk::rendering_context_interface *rendering_context, sxsdk::stream_interface *stream, void *);
		virtual void do_post_effect (void *);
	};
}
//  \en The following ask() function displays a dialog. \enden  \ja ask()オーバライドしてダイアログを表示する。 \endja 
void lensflare_effector::ask (sxsdk::stream_interface *stream, void *) {
	stream->set_swap_endian(stream->is_little_endian()); //  \en Ensure that the same binary data can be properly read from both big and little endian platforms. \enden  \ja これを呼んでおかないと、プラットフォーム間で非互換になる。 \endja 

	//  \en Create a dialog box that inquires one numeric value. \enden  \ja 数値を1個だけ入力するダイアログを作成する。 \endja 
	compointer<sxsdk::dialog_interface> dialog(stream->create_dialog_interface());
	dialog->set_title("Simple Lens Flare");
	const int size_id = dialog->append_item(sxsdk::dialog_interface::float_type, "SIZE(pixels)");

	//  \en Read a floating point value from the stream and set it to the dialog item. \enden  \ja ストリームから浮動小数点数１個を読み込み、ダイアログにその値を設定する。 \endja 
	{	float s = default_size;
		stream->set_pointer(0);
		try { stream->read_float(s); } catch (...) { }
		dialog->set_float_property_value(size_id, s);
	}

	if (dialog->ask()) { //  \en Display the dialog box. \enden  \ja ダイアログボックスを表示する。 \endja 

		//  \en Get the new value from the dialog item and write it to the stream. \enden  \ja ユーザが入力した数値を読み取り、それをストリームに書き込む。 \endja 
		float s;
		dialog->get_float_property_value(size_id, s);
		stream->set_pointer(0);
		stream->set_size(0);
		stream->write_float(s);
	}
}
void lensflare_effector::begin (sxsdk::rendering_context_interface *rendering_context, sxsdk::stream_interface *stream, void *) {
	this->rendering_context = rendering_context;
	this->stream = stream;
}
void lensflare_effector::do_post_effect (void *) {
	sxsdk::rendering_context_interface &rc = *rendering_context;
	compointer<sxsdk::image_interface> image(rc.get_image_interface());

	float size = default_size;
	try {
		stream->set_pointer(0);
		stream->read(size);
	} catch (...) { }
	flare_function_class func;
	const sx::bounds<sx::vec<int,2> > bounds = sx::bounds<sx::vec<int,2> >(rc.get_whole_image_size());
	const int n = rc.get_number_of_lights();
	for (int i = 0; i < n; ++i) {
		sxsdk::rendering_light_class &light = rc.get_light(i);
		const sx::vec<float,4> p = light.get_position() * rc.get_world_to_device_matrix();
		
		if (0.0f < p.w && 0.0f < p.z && p.z <= p.z) { //  \en Process only the points on the yonder side of the eye point. \enden  \ja 視点より向こう側にある点だけ処理する。 \endja 
			const sx::vec<float,3> r(p.x/p.w, p.y/p.w, p.z/p.w); //  \en Convert from homogeneous coordinates to normal coordinates. \enden  \ja 斉次座標を通常座標に変換する。 \endja 
			if (bounds.min.x <= r.x && r.x < bounds.max.x && bounds.min.y <= r.y && r.y < bounds.max.y) {
				if (image->has_z()) {
					//  \en Compare the Z values and skip if the light source is hidden. \enden  \ja Z値を比較し、光源が隠れている場合にはスキップする。 \endja 
					float z; image->get_z(int(r.x+0.5f), int(r.y+0.5f), z);
					if (z < p.z) continue;
				}
				image->draw_smudge(sx::vec<float,2>(r), sx::vec<float,2>(size, size), func, false);
			}
		}
	}
}

//  \en Shows alpha channel and the depth. \enden  \ja アルファチャネルと奥行きを表示 \endja 
namespace {
	class showalphaz_effector : public sxsdk::effector_interface {
	public:
		explicit showalphaz_effector () : rendering_context(0), stream(0) { }
	private:
		static const unsigned default_channel = 0;
		sxsdk::rendering_context_interface *rendering_context;
		sxsdk::stream_interface *stream;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return LENSFLARE_EFFECTOR_ID; }
		//  \en ask() function gets called if can_ask() function returns true. \enden  \ja can_ask()をオーバライドしてtrueを返すと、ダイアログを表示するask()関数が呼ばれる。。 \endja 
		virtual bool can_ask (void *) { return true; } 
		virtual void ask (sxsdk::stream_interface *stream, void *);
		virtual void begin (sxsdk::rendering_context_interface *rendering_context, sxsdk::stream_interface *stream, void *);
		virtual void do_post_effect (void *);
	};
}
void showalphaz_effector::ask (sxsdk::stream_interface *stream, void *) {
	stream->set_swap_endian(stream->is_little_endian()); //  \en Ensure that the same binary data can be properly read from both big and little endian platforms. \enden  \ja これを呼んでおかないと、プラットフォーム間で非互換になる。 \endja 

	//  \en Create a dialog box that inquires one numeric value. \enden  \ja ポップアップメニューを持つダイアログを作成する。 \endja 
	compointer<sxsdk::dialog_interface> dialog(stream->create_dialog_interface());
	dialog->set_title("Show Alpha / Z");
	const int chennel_id = dialog->append_item(sxsdk::dialog_interface::selection_type, "Channel:/Alpha/Z");

	//  \en Read a floating point value from the stream and set it to the dialog item. \enden  \ja ストリームから浮動小数点数１個を読み込み、ダイアログにその値を設定する。 \endja 
	{	unsigned c = default_channel;
		stream->set_pointer(0);
		try { stream->read_int((int &)c); } catch (...) { }
		dialog->set_selection_property_value(chennel_id, c);
	}

	if (dialog->ask()) { //  \en Display the dialog box. \enden  \ja ダイアログボックスを表示する。 \endja 

		//  \en Get the new value from the dialog item and write it to the stream. \enden  \ja ユーザが入力した数値を読み取り、それをストリームに書き込む。 \endja 
		unsigned c;
		dialog->get_selection_property_value(chennel_id, c);
		stream->set_pointer(0);
		stream->set_size(0);
		stream->write_int(c);
	}
}
void showalphaz_effector::begin (sxsdk::rendering_context_interface *rendering_context, sxsdk::stream_interface *stream, void *) {
	this->rendering_context = rendering_context;
	this->stream = stream;
}
void showalphaz_effector::do_post_effect (void *) {
	sxsdk::rendering_context_interface &rc = *rendering_context;
	compointer<sxsdk::image_interface> image(rc.get_image_interface());

	unsigned channel = default_channel;
	try {
		stream->set_pointer(0);
		stream->read((int &)channel);
	} catch (...) { }
	const sx::vec<int,2> size = image->get_size();
	switch (channel) {
	case 0:
		for (int y = 0; y < size.y; ++y) {
			for (int x = 0; x < size.x; ++x) {
				sx::rgba<sx::unsigned8> c; image->get_pixel(x, y, c);
				c.red = c.green = c.blue = c.alpha;
				image->set_pixel(x, y, c);
			}
		}
		break;
	case 1:
		if (image->has_z()) {
			for (int y = 0; y < size.y; ++y) {
				for (int x = 0; x < size.x; ++x) {
					float z; image->get_z(x, y, z);
					image->set_pixel(x, y, sx::rgb<float>(0, z, 0));
				}
			}
		}
		break;
	}
}

SXPLUGINNAMESPACEBEGIN(test_effector)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		sxsdk::effector_interface *u = 0;
		switch (i) {
		case 0:
			u = new lensflare_effector;
			break;
		case 1:
			u = new showalphaz_effector;
			break;
		}
		if (u) {
			u->AddRef();
			*p = (void *)u;
		}
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == effector_iid) return 2;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		switch (i) {
		case 0:	return "Simple Lens Flare";
		case 1:	return "Simple Show Alpha / Z";
		}
		return 0;
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		switch (i) {
		case 0:	return LENSFLARE_EFFECTOR_ID;
		case 1:	return SHOWALPHAZ_EFFECTOR_ID;
		}
		return sx::uuid_class();
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
