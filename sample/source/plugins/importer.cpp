#include "sxsdk.cxx"

namespace {
	const sx::uuid_class SIMPLE_IMAGE_IMPORTER_ID("3E2D1C8F-549E-11D9-9329-000A95BACEB2");
	const sx::uuid_class SIMPLE_IMPORTER_ID("4235C0F4-549E-11D9-BAAD-000A95BACEB2");
}

namespace {
	class image_importer_component : public sxsdk::image_importer_interface {
	public:
		image_importer_component (sxsdk::shade_interface &shade) : shade(shade) { }
	private:
		sxsdk::shade_interface &shade;

		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_IMAGE_IMPORTER_ID; }
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual const char *get_file_extension (int index, void *);
		virtual const char *get_file_description (int index, void *);
		virtual bool do_pre_import (int index, void *);
		virtual sxsdk::image_interface *do_import (int index, sxsdk::stream_interface *stream, void *);
	};
}
const char *image_importer_component::get_file_extension (int index, void *) {
	if (index == 0) return "imageext";
	return 0;
}
const char *image_importer_component::get_file_description (int index, void *) {
	if (index == 0) return "imageimporter-description";
	return 0;
}
bool image_importer_component::do_pre_import (int index, void *) {
	compointer<sxsdk::dialog_interface> dialog(shade.create_dialog_interface_with_uuid(SIMPLE_IMAGE_IMPORTER_ID));
	dialog->append_item(sxsdk::dialog_interface::double_type, "double");
	dialog->append_item(sxsdk::dialog_interface::float_type, "float");
	dialog->append_item(sxsdk::dialog_interface::rgb_type, "rgb");
	if (dialog->ask()) {
		shade.message("ok");
		return true;
	}
	shade.message("cancel");
	return false;
}
sxsdk::image_interface *image_importer_component::do_import (int index, sxsdk::stream_interface *stream, void *) {
	compointer<sxsdk::image_interface> image(shade.get_new_image_interface(sx::vec<int,2>(100, 100)));
	image->AddRef();
	return image;
}

namespace {
	class importer_component : public sxsdk::importer_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return SIMPLE_IMPORTER_ID; }
		virtual int get_file_type (int i, void *);
		virtual const char *get_file_extension (int i, void *);
		virtual void do_import (sxsdk::scene_interface *scene, sxsdk::stream_interface *stream, sxsdk::text_stream_interface *text_stream, void *);
	};
}
int importer_component::get_file_type (int i, void *) {
	return sxsdk::text("TEXT");
}
const char *importer_component::get_file_extension (int i, void *) {
	return "txt";
}
void importer_component::do_import (sxsdk::scene_interface *scene, sxsdk::stream_interface *stream, sxsdk::text_stream_interface *text_stream, void *) {
	scene->message("importing");
	try {
		while (true) {
			const char *s;
			text_stream->read_line(s);
			scene->message(s);
		}
	}
	catch (...) {
	}
}

SXPLUGINNAMESPACEBEGIN(test_importer)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		sxsdk::plugin_interface *u = 0;
		if (iid == importer_iid)			u = new importer_component;
		else if (iid == image_importer_iid)	u = new image_importer_component(*shade);
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == importer_iid)		return 1;
		if (iid == image_importer_iid)	return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "Simple Importer";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		if (iid == importer_iid)			return SIMPLE_IMPORTER_ID;
		else if (iid == image_importer_iid)	return SIMPLE_IMAGE_IMPORTER_ID;
		return sx::uuid_class(0u);
	}
	SXPLUGINENTRY  const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY  bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
