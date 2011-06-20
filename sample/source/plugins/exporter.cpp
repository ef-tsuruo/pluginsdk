#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_IMAGE_EXPORTER_ID("E6EC5DDC-549D-11D9-91C9-000A95BACEB2");
	const sx::uuid_class SIMPLE_EXPORTER_ID("EC411A4A-549D-11D9-8E07-000A95BACEB2");
}

namespace {
	class image_exporter_component : public sxsdk::image_exporter_interface {
	public:
		explicit image_exporter_component (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		sxsdk::shade_interface &shade;

		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_IMAGE_EXPORTER_ID; }
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual const char *get_file_extension (int index, void *);
		virtual const char *get_file_description (int index, void *);
		virtual bool do_pre_export (int index, sxsdk::image_interface *image, void *);
		virtual bool do_export (int index, sxsdk::image_interface *image, sxsdk::stream_interface *stream, void *) { return true; }
		virtual bool do_post_export (int index, sxsdk::image_interface *image, void *) { return true; }
	};
}
const char *image_exporter_component::get_file_extension (int index, void *) {
	if (index == 0) return "imageext";
	return 0;
}
const char *image_exporter_component::get_file_description (int index, void *) {
	if (index == 0) return "imageexporter-description";
	return 0;
}
bool image_exporter_component::do_pre_export (int index, sxsdk::image_interface *image, void *) {
	compointer<sxsdk::dialog_interface> dialog(shade.create_dialog_interface_with_uuid(SIMPLE_IMAGE_EXPORTER_ID));
	dialog->append_item(sxsdk::dialog_interface::double_type, "double");
	dialog->append_item(sxsdk::dialog_interface::float_type, "float");
	dialog->append_item(sxsdk::dialog_interface::rgb_type, "rgb");
	if (dialog->ask()) {
		shade.message("ok");
		return true;
	}
	shade.message("cancel");
	return true;
}

namespace {
	class exporter_component : public sxsdk::exporter_interface {
	public:
		exporter_component () : stream(0)  { }
	private:
		compointer<sxsdk::stream_interface> stream;
		compointer<sxsdk::text_stream_interface> text_stream;

		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_EXPORTER_ID; }

		virtual void do_export (sxsdk::plugin_exporter_interface *plugin_exporter, void *);

		virtual bool can_accept_polyline (void *) { return false; }
		virtual bool can_accept_polygon (void *) { return false; }
		virtual bool can_accept_sphere (void *) { return false; }
		virtual bool can_accept_bezier_surface (void *) { return false; }
		virtual bool can_accept_polymesh (void *) { return true; }

		virtual bool skips_dialog (void *) { return true; }
		virtual int get_max_vertices_per_face (void *) { return -1; }
		virtual bool can_accept_texture (void *) { return true; }

		virtual bool must_triangulate_polymesh (void *) { return true; }

		virtual void begin (void *);
		virtual void end (void *);
	};
}
void exporter_component::begin (void *) {
	std::cerr << "exporter_component::begin\n";
}
void exporter_component::end (void *) {
	std::cerr << "exporter_component::end\n";
}
void exporter_component::do_export (sxsdk::plugin_exporter_interface *plugin_exporter, void *) {
	plugin_exporter->do_export();
}

SXPLUGINNAMESPACEBEGIN(test_exporter)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		sxsdk::plugin_interface *u = 0;
		if (iid == exporter_iid)			u = new exporter_component();
		else if (iid == image_exporter_iid)	u = new image_exporter_component(*shade);
		u->AddRef();
		*p = (void *)u;
	}

	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == exporter_iid)		return 1;
		if (iid == image_exporter_iid)	return 1;
		return 0;
	}

	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "simple exporter";
	}

	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		if (iid == exporter_iid)			return SIMPLE_EXPORTER_ID;
		else if (iid == image_exporter_iid)	return SIMPLE_IMAGE_EXPORTER_ID;
		return sx::uuid_class(0u);
	}
	SXPLUGINENTRY  const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY  bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
