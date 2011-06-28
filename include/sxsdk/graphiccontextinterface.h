#pragma once

namespace sxsdk {
	class graphic_context_interface : public shade_interface {
	public:
	virtual int graphic_context_interface_dummy0(void *) { assert(false); throw "invalid interface graphic_context_interface"; return 0; } // 0
	virtual int graphic_context_interface_dummy1(void *) { assert(false); throw "invalid interface graphic_context_interface"; return 0; } // 1
	virtual void set_color (const sxsdk::rgb_class& color, void* aux = 0) = 0; // 2
	virtual void restore_color (void* aux = 0) = 0; // 3
	virtual void get_pixel_rgb_obsolete (int x, int y, sxsdk::rgb_class& color, void* aux = 0) = 0; // 4
	virtual void set_pixel_rgb_obsolete (int x, int y, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 5
	virtual void set_pixel_native_rgba_obsolete (int x, int y, const sx::pixel32& color, void* aux = 0) = 0; // 6
	virtual void add_pixel_rgb_obsolete (int x, int y, const sxsdk::rgb_class& color, void* aux = 0) = 0; // 7
	virtual void add_pixel_native_rgba_obsolete (int x, int y, const sx::pixel32& color, void* aux = 0) = 0; // 8
	virtual void draw_string (const char* s, void* aux = 0) = 0; // 9
	virtual void draw_string_left_in_rectangle (const char* s, const sx::rectangle_class& r, void* aux = 0) = 0; // 10
	virtual void draw_string_center_in_rectangle (const char* s, const sx::rectangle_class& r, void* aux = 0) = 0; // 11
	virtual void draw_string_right_in_rectangle (const char* s, const sx::rectangle_class& r, void* aux = 0) = 0; // 12
	virtual void paint_rectangle (const sx::rectangle_class& r, void* aux = 0) = 0; // 13
	virtual void highlight_rectangle_obsolete (const sx::rectangle_class& r, void* aux = 0) = 0; // 14
	virtual void erase_rectangle_obsolete (const sx::rectangle_class& r, void* aux = 0) = 0; // 15
	virtual void frame_rectangle (const sx::rectangle_class& r, void* aux = 0) = 0; // 16
	virtual void paint_oval (const sx::rectangle_class& r, void* aux = 0) = 0; // 17
	virtual void frame_oval (const sx::rectangle_class& r, void* aux = 0) = 0; // 18
	virtual void draw_image (sxsdk::image_interface* image, const sx::rectangle_class& destination_rectangle, void* aux = 0) = 0; // 19
	virtual int get_string_width (const char* s, void* aux = 0) = 0; // 20
	virtual int get_string_height (void* aux = 0) = 0; // 21
	virtual void move_to (float x, float y, void* aux = 0) = 0; // 22
	virtual void line_to (float x, float y, void* aux = 0) = 0; // 23
	virtual void begin_path (void* aux = 0) = 0; // 24
	virtual void end_path (void* aux = 0) = 0; // 25
	virtual void set_text_position (float x, float y, void* aux = 0) = 0; // 26
	virtual int graphic_context_interface_dummy27(void *) { assert(false); throw "invalid interface graphic_context_interface"; return 0; } // 27
	virtual void set_small_text (bool monospace = false, void* aux = 0) = 0; // 28
	virtual void restore_text (void* aux = 0) = 0; // 29
	virtual void* get_native_context (void* aux = 0) = 0; // 30
	virtual void line (float x0, float y0, float x1, float y1, void* aux = 0) = 0; // 31
	virtual void draw_bitmap (bitmap_interface* image, const sx::rectangle_class& destination_rectangle, void* aux = 0) = 0; // 32
	virtual void draw_uniscaled_image (sxsdk::image_interface* image, const sx::rectangle_class& destination_rectangle, void* aux = 0) = 0; // 33
	virtual void draw_uniscaled_bitmap (bitmap_interface* image, const sx::rectangle_class& destination_rectangle, void* aux = 0) = 0; // 34
	virtual void paint_polygon (int n_points, const sxsdk::vec2 points[], void* aux = 0) = 0; // 35
	virtual void frame_polygon (int n_points, const sxsdk::vec2 points[], void* aux = 0) = 0; // 36
	};
}
