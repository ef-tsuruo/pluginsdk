#include "sxsdk.cxx"

namespace {
	const sx::uuid_class STRIPE_SHADER_ID	("2EEE4CB0-549F-11D9-9A8F-000A95BACEB2");
	const sx::uuid_class CHECK_SHADER_ID		("3360117C-549F-11D9-9AD8-000A95BACEB2");
	const sx::uuid_class SPOTTED_SHADER_ID	("37C08A16-549F-11D9-8BC9-000A95BACEB2");
	const sx::uuid_class MARBLE_SHADER_ID	("3BE2D7A0-549F-11D9-A1E7-000A95BACEB2");
	const sx::uuid_class WOOD_SHADER_ID		("40CAE2C1-549F-11D9-80A7-000A95BACEB2");
	const sx::uuid_class  LOG_SHADER_ID		("461225B9-549F-11D9-A8F5-000A95BACEB2");
	const sx::uuid_class WAVE_SHADER_ID		("4B387CE6-549F-11D9-BC5E-000A95BACEB2");
	const sx::uuid_class CLOUD_SHADER_ID		("5130B6A8-549F-11D9-AFD1-000A95BACEB2");
	const sx::uuid_class WRINKLE_SHADER_ID	("5749F032-549F-11D9-8D4A-000A95BACEB2");
	const sx::uuid_class IMAGE_SHADER_ID		("5FA95BF8-549F-11D9-8C67-000A95BACEB2");
	const sx::uuid_class BUMP_SHADER_ID		("64B888F2-549F-11D9-A444-000A95BACEB2");
	const sx::uuid_class TEST_SHADER_ID		("6A2BFB2C-549F-11D9-A1D3-000A95BACEB2");
}

namespace {
	template<typename T> inline const T lerp (const T &a, const T &b, float t) {
		return (b - a) * t + a;
	}
	class stripe_component : public sxsdk::shader_interface {
	public:
		stripe_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return STRIPE_SHADER_ID; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual bool supports_shade (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			return step(0.1f, mod(get_P().x, 0.2f));
		}
		virtual void shade (void *) {
			//set_Ci(sx::vec<float,3>(1,0,0));
			set_Ci(lerp(get_Cs(), get_mapping_color(), evaluate(get_P())));
		}
	};
}

namespace {
	class check_component : public sxsdk::shader_interface {
	public:
		check_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return CHECK_SHADER_ID; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual bool supports_shade (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p_, void * = 0) {
			const sx::vec<float,3> p = p_ * 2.0f;
			const float dx = mod(p.x, 1.0f);
			const float dy = mod(p.y, 1.0f);
			const float dz = mod(p.z, 1.0f);
			float a;
			if (dx < 0.5f) 
				if (dy < 0.5f)
					if (dz < 0.5f)	a = 0.0f;
					else			a = 1.0f;
				else
					if (dz < 0.5f)	a = 1.0f;
					else			a = 0.0f;
			else
				if (dy < 0.5f)
					if (dz < 0.5f)	a = 1.0f;
					else			a = 0.0f;
				else
					if (dz < 0.5f)	a = 0.0f;
					else			a = 1.0f;
			return a;
		}
		virtual void shade (void *) {
			set_Ci(lerp(get_Cs(), get_mapping_color(), evaluate(get_P())));
		}
	};
}

namespace {
	class spotted_component : public sxsdk::shader_interface {
	public:
		spotted_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SPOTTED_SHADER_ID; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			return noise1(p*10.0f);
		}
		virtual bool supports_shade (void *) { return true; }
		virtual void shade (void *) {
			set_Ci(lerp(get_Cs(), get_mapping_color(), evaluate(get_P())));
		}
	};
}

namespace {
	class marble_component : public sxsdk::shader_interface {
	public:
		marble_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return MARBLE_SHADER_ID; }
		virtual bool needs_turbulence (void *) { return true; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			const float x = p.x*25.0f + turbulence1(p*5.0f, 4)*25.0f*get_turbulence();
			return (sin(x)+1.0f)*0.5f;
		}
		virtual bool supports_shade (void *) { return true; }
		virtual void shade (void *) {
			set_Ci(lerp(get_Cs(), get_mapping_color(), evaluate(get_P())));
		}
	};
}

namespace {
	class wood_component : public sxsdk::shader_interface {
	public:
		wood_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return WOOD_SHADER_ID; }
		virtual bool needs_turbulence (void *) { return true; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			const float x = p.x*4.0f + turbulence1(p, 5)*16.0f*get_turbulence();
			return mod(x, 1.0f);
		}
		virtual bool supports_shade (void *) { return true; }
		virtual void shade (void *) {
			set_Ci(lerp(get_Cs(), get_mapping_color(), evaluate(get_P())));
		}
	};
}

namespace {
	class log_component : public sxsdk::shader_interface {
	public:
		log_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return LOG_SHADER_ID; }
		virtual bool needs_turbulence (void *) { return true; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p_, void * = 0) {
			const sx::vec<float,3> p = p_ * 4.0f;
			const float x = sqrt(p.x*p.x + p.y*p.y) + turbulence1(sx::vec<float,3>(p.x,p.y,0), 5)*2.0f*get_turbulence();
			return mod(x, 1.0f);
		}
		virtual bool supports_shade (void *) { return true; }
		virtual void shade (void *) {
			set_Ci(lerp(get_Cs(), get_mapping_color(), evaluate(get_P())));
		}
	};
}

namespace {
	class wave_component : public sxsdk::shader_interface {
	public:
		wave_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return WAVE_SHADER_ID; }
		virtual bool needs_turbulence (void *) { return true; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p_, void * = 0) {
			const sx::vec<float,3> p = p_ * 25.0f;
			const float x = sin(sqrt(p.x*p.x + p.z*p.z) + turbulence1(get_P(), 5)*50.0f*get_turbulence());
			return (x + 1.0f) * 0.5f;
		}
		virtual bool supports_bump (void *) { return true; }
		virtual void bump (void *) {
			const sx::vec<float,3> p = get_P();
			const float x = evaluate(get_P()) * 2.0f - 1.0f;
			set_N(normalize(get_N()+normalize(sx::vec<float,3>(p.x,0,p.z))*x));
		}
	};
}

namespace {
	class cloud_component : public sxsdk::shader_interface {
	public:
		cloud_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return CLOUD_SHADER_ID; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			return turbulence1(p*10.0f, 5);
		}
		virtual bool supports_shade (void *) { return true; }
		virtual void shade (void *) {
			set_Ci(lerp(get_Cs(), get_mapping_color(), evaluate(get_P())));
		}
	};
}

namespace {
	class wrinkle_component : public sxsdk::shader_interface {
	public:
		wrinkle_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return WRINKLE_SHADER_ID; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			return turbulence1(get_P()*10.0f, 5);
		}
		virtual bool supports_bump (void *) { return true; }
		virtual void bump (void *) {
			set_N(normalize(get_N() + (turbulence3(get_P()*10.0f, 5)-sx::vec<float,3>(0.5f,0.5f,0.5f))));
		}
	};
}

namespace {
	class image_component : public sxsdk::shader_interface {
	public:
		image_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return IMAGE_SHADER_ID; }
		virtual bool needs_uv (void *) { return true; }
		virtual bool needs_to_sample_image (void *) { return true; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			const sx::rgba<float> c = sample_image(get_u(), get_v());
			return (c.red + c.green + c.blue) / 3.0f;
		}
		virtual bool supports_shade (void *) { return true; }
		virtual void shade (void *) {
			if (has_uv())	set_Ci(sx::rgb<float>(sample_image(get_u(), get_v())));
			else			set_Ci(get_mapping_color());
		}
	};
}

namespace {
	class bump_component : public sxsdk::shader_interface {
	public:
		bump_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return BUMP_SHADER_ID; }
		virtual bool needs_uv (void *) { return true; }
		virtual bool needs_tangents (void *) { return true; }
		virtual bool needs_to_sample_bump (void *) { return true; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			const sx::rgba<float> c = sample_image(get_u(), get_v());
			return (c.red + c.green + c.blue) / 3.0f;
		}
		virtual bool supports_bump (void *) { return true; }
		virtual void bump (void *) {
			sx::vec<float,2> d = sample_bump(get_u(), get_v());
			set_N(normalize(get_N() + (get_dPdu()*d.x + get_dPdv()*d.y)*get_mapping()));
		}
	};
}

namespace {
	class test_component : public sxsdk::shader_interface {
	public:
		test_component (sxsdk::shade_interface &shade) : sxsdk::shader_interface(shade) { }
	private:
		class test_info_class : public sxsdk::shader_info_base_class {
		public:
			float weight;

			test_info_class (float weight) : weight(weight) { }
			unsigned magic_number () const { return 0x76543210; }
		};

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return TEST_SHADER_ID; }
		//virtual bool needs_uv (void *) { return true; }
		virtual bool supports_evaluate (void *) { return true; }
		virtual float evaluate (const sx::vec<float,3> &p, void * = 0) {
			test_info_class &info = (test_info_class &)(*(get_shader_info()));
			if (info.magic_number() != 0x76543210) return 0.0f;
			return sxsdk::absolute((get_Ng()+sx::vec<float,3>(1,1,1))*0.5f*info.weight);
		}
		virtual bool supports_shade (void *) { return true; }
		virtual void shade (void *) {
			test_info_class &info = (test_info_class &)(*(get_shader_info()));
			if (info.magic_number() != 0x76543210) { set_Ci(sx::rgb<float>(0,0,0)); }
			const sx::vec<float,3> c = (get_Ng()+sx::vec<float,3>(1,1,1))*0.5f*info.weight;
			set_Ci(sx::rgb<float>(c.x, c.y, c.z));
			//float u = get_u()*40.0; u = u - floor(u);
			//float v = get_v()*40.0; v = v - floor(v);
			//set_Ci((u<0.2||v<0.2) ? sx::vec<float,3>(1,1,1) : sx::vec<float,3>(0,0,0));
		}
		virtual bool ask (sxsdk::stream_interface *stream, void *) {
			compointer<sxsdk::dialog_interface> dialog(stream->get_dialog_interface()) ;
			const int index1 = dialog->append_item(sxsdk::dialog_interface::float_type, "float");
			float value;
			try {
				stream->set_pointer(0) ;
				stream->read_float(value);
				dialog->set_float_property_value(index1, value);
			} catch (...) {
			}
			if(dialog->ask()) {
				dialog->get_float_property_value(index1, value);
				stream->set_pointer(0) ;
				stream->write_float(value);
				return true;
			}
			return false;
		}
		virtual sxsdk::shader_info_base_class *new_shader_info (sxsdk::stream_interface *stream, void *) {
			float weight = 1.0f;
			if (stream) {
				stream->set_pointer(0);
				if (4 <= stream->get_size()) stream->read_float(weight);
			}
			return new test_info_class(weight);
		}
	};
}

SXPLUGINNAMESPACEBEGIN(test_shader)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		sxsdk::shader_interface *u = 0;
		switch (i) {
		case 0:		u = new stripe_component(*shade); break;
		case 1:		u = new check_component(*shade); break;
		case 2:		u = new spotted_component(*shade); break;
		case 3:		u = new marble_component(*shade); break;
		case 4:		u = new wood_component(*shade); break;
		case 5:		u = new log_component(*shade); break;
		case 6:		u = new wave_component(*shade); break;
		case 7:		u = new cloud_component(*shade); break;
		case 8:		u = new wrinkle_component(*shade); break;
		case 9:		u = new image_component(*shade); break;
		case 10:	u = new bump_component(*shade); break;
		case 11:	u = new test_component(*shade); break;
		}
		if (u) {
			u->AddRef();
			*p = (void *)u;
		}
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == shader_iid) return 12;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		switch (i) {
		case 0:		return "stripe";
		case 1:		return "check";
		case 2:		return "spotted";
		case 3:		return "marble";
		case 4:		return "wood";
		case 5:		return "log";
		case 6:		return "wave";
		case 7:		return "cloud";
		case 8:		return "wrinkle";
		case 9:		return "image";
		case 10:	return "bump";
		case 11:	return "test";
		}
		return 0;
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		switch (i) {
		case 0:		return STRIPE_SHADER_ID;
		case 1:		return CHECK_SHADER_ID;
		case 2:		return SPOTTED_SHADER_ID;
		case 3:		return MARBLE_SHADER_ID;
		case 4:		return WOOD_SHADER_ID;
		case 5:		return LOG_SHADER_ID;
		case 6:		return WAVE_SHADER_ID;
		case 7:		return CLOUD_SHADER_ID;
		case 8:		return WRINKLE_SHADER_ID;
		case 9:		return IMAGE_SHADER_ID;
		case 10:	return BUMP_SHADER_ID;
		case 11:	return TEST_SHADER_ID;
		}
		return sx::uuid_class(0u);
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return true;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
SXPLUGINNAMESPACEEND
