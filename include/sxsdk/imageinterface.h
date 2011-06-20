#pragma once

namespace sxsdk {
	class image_interface : public shade_interface {
	public:
		struct smudge_function_class {
			virtual ~smudge_function_class () { }
			virtual sx::rgba<float> function (const sx::vec<float,2> &p) {
				if (1.0 < p.y) return sx::rgba<float>(0.0f, 0.0f, 0.0f, 0.0f);
				const float k = 1.0 - p.y;
				return sx::rgba<float>(k, k, k, 1.0f);
			}
			virtual bool is_polar () { return true; }
			virtual bool is_cartesian () { return false; }
		};
	#if SXWINDOWS 
	virtual void save_ (void* aux = 0) = 0; // -1
	virtual void save (const char*const& path = "", void* aux = 0) = 0; // -1
	#else 
	virtual void save (const char*const& path = "", void* aux = 0) = 0; // -1
	virtual void save_ (void* aux = 0) = 0; // -1
	#endif 
	virtual sx::vec<int,2> get_size (void * = 0) const = 0; // 2
	virtual void set_pixel (int x, int y, const sxsdk::rgb_class& rgb, void* aux = 0) = 0; // 3
	virtual void get_pixel (int x, int y, sxsdk::rgb_class& rgb, void* aux = 0) = 0; // 4
	virtual void set_pixel (int x, int y, const sx::pixel32& rgba, void* aux = 0) = 0; // 5
	virtual void get_pixel (int x, int y, sx::pixel32& rgba, void* aux = 0) = 0; // 6
	virtual void set_pixel (int x, int y, int dx, int dy, const sx::pixel32* rgba, void* aux = 0) = 0; // 7
	virtual void get_pixel (int x, int y, int dx, int dy, sx::pixel32* rgba, void* aux = 0) = 0; // 8
	virtual void draw_smudge (const sxsdk::vec2& c, const sxsdk::vec2& r, smudge_function_class& func, bool antialiasing = false, enums::image_mix_mode mix_mode = enums::image_add_mode) = 0; // 9
	virtual void begin_opengl (void* aux = 0) = 0; // 10
	virtual void end_opengl (void* aux = 0) = 0; // 11
	virtual sx::vec<int,2> get_offset (void * = 0) const = 0; // 12
	virtual bool has_z (void * = 0) const = 0; // 13
	virtual void set_z (int x, int y, float z, void* aux = 0) = 0; // 14
	virtual void get_z (int x, int y, float& z, void* aux = 0) = 0; // 15
	virtual void set_zs (int x, int y, int dx, int dy, const float* z, void* aux = 0) = 0; // 16
	virtual void get_zs (int x, int y, int dx, int dy, float* z, void* aux = 0) = 0; // 17
	virtual void mix_smudge (const sxsdk::vec2& c, const sxsdk::vec2& r, smudge_function_class& func, bool antialiasing = false, enums::image_mix_mode mix_mode = enums::image_add_mode) = 0; // 18
	virtual bool has_real_color (void * = 0) const = 0; // 19
	virtual void set_real_color (int x, int y, const sxsdk::rgb_class& real_color, void* aux = 0) = 0; // 20
	virtual void get_real_color (int x, int y, sxsdk::rgb_class& real_color, void* aux = 0) = 0; // 21
	virtual void set_real_colors (int x, int y, int dx, int dy, const sxsdk::rgb_class* real_color, void* aux = 0) = 0; // 22
	virtual void get_real_colors (int x, int y, int dx, int dy, sxsdk::rgb_class* real_color, void* aux = 0) = 0; // 23
	virtual sxsdk::graphic_context_interface* get_graphic_context_interface (void * = 0) const = 0; // 24
	virtual void set_pixel_rgba (int x, int y, const sx::rgba8_class& rgba, void* aux = 0) = 0; // 25
	virtual void get_pixel_rgba (int x, int y, sx::rgba8_class& rgba, void* aux = 0) = 0; // 26
	virtual void set_pixels_rgba (int x, int y, int dx, int dy, const sx::rgba8_class* rgba, void* aux = 0) = 0; // 27
	virtual void get_pixels_rgba (int x, int y, int dx, int dy, sx::rgba8_class* rgba, void* aux = 0) = 0; // 28
	virtual sxsdk::image_interface* create_duplicate_image_interface (const sx::vec<int,2>* size = 0, bool fit = true, int depth = 32, void* aux = 0) = 0; // 29
		sxsdk::image_interface* duplicate_image (const sx::vec<int,2>* size = 0, bool fit = true, int depth = 32, void* aux = 0) { return create_duplicate_image_interface(size, fit, depth); }
	virtual void write_pict (stream_interface* stream, void* aux = 0) = 0; // 30
	virtual void load_test_image (int i, void* aux = 0) = 0; // 31
	virtual bool has_image (void * = 0) const = 0; // 32
	virtual int image_interface_test_1 ( void* aux =0 ) { return 1; } // 33
	virtual bool is_fake (void * = 0) const = 0; // 34
	virtual void copy_to_clipboard (void* aux = 0) = 0; // 35
	virtual sxsdk::image_interface* create_difference_image_interface (sxsdk::image_interface* image, void* aux = 0) = 0; // 36
	virtual image_interface &set_shift (const sxsdk::vec2 &shift_param, void * = 0) = 0; // 37
	virtual sxsdk::vec2 get_shift (void * = 0) const = 0; // 38
	virtual bool equal (sxsdk::image_interface* image, void* aux = 0) = 0; // 39
	virtual bool similar (sxsdk::image_interface* image, void* aux = 0) = 0; // 40
	virtual sxsdk::window_interface* create_window_interface (const char* title = (const char*)0, void* aux = 0) = 0; // 41
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 42
	virtual bitmap_interface* create_bitmap_interface (bool alpha_blend = true, float opacity = 1.0f, void* aux = 0) = 0; // 43
	virtual void clear (void* aux = 0) = 0; // 44
	virtual sx::rectangle_class get_bounds (void * = 0) const = 0; // 45
	virtual void set_pixel_rgba_float (int x, int y, const rgba_class& rgba, void* aux = 0) = 0; // 46
	virtual void get_pixel_rgba_float (int x, int y, rgba_class& rgba, void* aux = 0) = 0; // 47
	virtual void set_pixels_rgba_float (int x, int y, int dx, int dy, const rgba_class* rgba, void* aux = 0) = 0; // 48
	virtual void get_pixels_rgba_float (int x, int y, int dx, int dy, rgba_class* rgba, void* aux = 0) = 0; // 49
	virtual int get_pixel_depth (void * = 0) const = 0; // 50
	virtual image_interface &set_pixel_depth (int pixel_depth_param, void * = 0) = 0; // 51
	virtual bool file_exists (void* aux = 0) = 0; // 52
	virtual bool update (int frame = 0, const bool* ask = 0) = 0; // 53
	virtual bool is_movie (void * = 0) const = 0; // 54
	virtual int get_total_frames (void * = 0) const = 0; // 55
	virtual image_interface &set_path (const char* path_param, void * = 0) = 0; // 56
	virtual const char* get_path (void * = 0) const = 0; // 57
	virtual bool get_external_reference (void * = 0) const = 0; // 58
	virtual image_interface &set_external_reference (bool external_reference_param, void * = 0) = 0; // 59
	virtual bool update_external_reference (int frame = 0, bool ask = false, bool* ignore_all = 0, void* aux = 0) = 0; // 60
	virtual sxsdk::rgb_class get_pixel_ (int x, int y, void* aux = 0) = 0; // 61
	virtual sxsdk::rgba_class get_pixel_rgba_float_ (int x, int y, void* aux = 0) = 0; // 62
	virtual int get_pixel_format (void * = 0) const = 0; // 63
	virtual image_interface &set_pixel_format (int pixel_format_param, void * = 0) = 0; // 64
	virtual sxsdk::image_interface* create_duplicate_image_interface_square (const sx::vec<int,2>* size = 0, bool fit = true, int depth = 32, void* aux = 0) = 0; // 65
	};
}
