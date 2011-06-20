#include "sxsdk.cxx"

namespace {
	const sx::uuid_class TEST_IMAGE_BOX_ID("1B81C15C-549E-11D9-9437-000A95BACEB2");

	class image_box_component : public sxsdk::image_box_interface {
	public:
		explicit image_box_component (sxsdk::shade_interface &shade) : shade(shade) { }
		virtual int get_shade_version () const { return get_shade_build_number(); }
		virtual sx::uuid_class get_uuid (void * = 0) { return TEST_IMAGE_BOX_ID; }
		virtual bool do_image_box (sxsdk::image_interface *image, void * = 0);
		virtual void initialize_dialog (sxsdk::dialog_interface &d, void* aux);
		virtual int terminate (sxsdk::dialog_interface &d, int result, void *);
	private:
		sxsdk::shade_interface &shade;
		sxsdk::image_interface *image;
		int pixel_depth_id;
	};
}
bool image_box_component::do_image_box (sxsdk::image_interface *image, void *) {
	this->image = image;
	if (image->has_image()) {
		compointer<sxsdk::dialog_interface> d(shade.create_dialog_interface());
		d->set_title("test dialog");
		d->set_responder(this);
		pixel_depth_id = d->append_selection("pixel depth/8/16/32/64/128");
		d->ask();
	}
	return true; 
}
void image_box_component::initialize_dialog (sxsdk::dialog_interface &d, void* aux) {
	unsigned s = 0;
	switch (image->get_pixel_depth()) {
	case 8:		s = 0; break;
	case 16:	s = 1; break;
	case 32:	s = 2; break;
	case 64:	s = 3; break;
	case 128:	s = 4; break;
	}
	d.get_dialog_item(pixel_depth_id).set_selection(s);
}
int image_box_component::terminate (sxsdk::dialog_interface &d, int result, void *) {
	switch (d.get_dialog_item(pixel_depth_id).get_selection()) {
	case 0:	image->set_pixel_depth(8); break;
	case 1:	image->set_pixel_depth(16); break;
	case 2:	image->set_pixel_depth(32); break;
	case 3:	image->set_pixel_depth(64); break;
	case 4:	image->set_pixel_depth(128); break;
	}
	return result;
}

SXPLUGINNAMESPACEBEGIN(test_image_box)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		image_box_component *u = new image_box_component(*shade);
		u->AddRef();
		*p = (void *)u;
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == image_box_iid) return 1;
		return 0;
	}
	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		return "Simple Image Box";
	}
	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		return TEST_IMAGE_BOX_ID;
	}
	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		return 0;
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
