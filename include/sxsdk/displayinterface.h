#pragma once

namespace xshade {
	class scene_class;
}

namespace sxsdk {
	class display_interface : public shade_interface {
	public:
		enum shading_mode_enum {	
			wireframe,				
			hidden_line,			
			shading,				
			shading_and_wireframe,	
			texture,				
			texture_and_wireframe,
			drafting,
			preview_rendering,
		};							
		enum lighting_mode_enum {	
			default_light,			
			modeling_light,			
			all_light				
		};							
	virtual display_interface &set_shading_side_view_deprecated (bool shading_side_view_deprecated_param, void * = 0) = 0; // 0
	virtual bool get_shading_side_view_deprecated (void * = 0) const = 0; // 1
	virtual display_interface &set_shading_top_view_deprecated (bool shading_top_view_deprecated_param, void * = 0) = 0; // 2
	virtual bool get_shading_top_view_deprecated (void * = 0) const = 0; // 3
	virtual display_interface &set_shading_front_view_deprecated (bool shading_front_view_deprecated_param, void * = 0) = 0; // 4
	virtual bool get_shading_front_view_deprecated (void * = 0) const = 0; // 5
	virtual display_interface &set_shading_pers_view_deprecated (bool shading_pers_view_deprecated_param, void * = 0) = 0; // 6
	virtual bool get_shading_pers_view_deprecated (void * = 0) const = 0; // 7
	virtual display_interface &set_shading_all_views_deprecated (bool shading_all_views_deprecated_param, void * = 0) = 0; // 8
	virtual display_interface &set_visiblelines_side_view_deprecated (bool visiblelines_side_view_deprecated_param, void * = 0) = 0; // 9
	virtual bool get_visiblelines_side_view_deprecated (void * = 0) const = 0; // 10
	virtual display_interface &set_visiblelines_top_view_deprecated (bool visiblelines_top_view_deprecated_param, void * = 0) = 0; // 11
	virtual bool get_visiblelines_top_view_deprecated (void * = 0) const = 0; // 12
	virtual display_interface &set_visiblelines_front_view_deprecated (bool visiblelines_front_view_deprecated_param, void * = 0) = 0; // 13
	virtual bool get_visiblelines_front_view_deprecated (void * = 0) const = 0; // 14
	virtual display_interface &set_visiblelines_pers_view_deprecated (bool visiblelines_pers_view_deprecated_param, void * = 0) = 0; // 15
	virtual bool get_visiblelines_pers_view_deprecated (void * = 0) const = 0; // 16
	virtual display_interface &set_visiblelines_all_views_deprecated (bool visiblelines_all_views_deprecated_param, void * = 0) = 0; // 17
	virtual display_interface &set_singlesided_obsolete (bool singlesided_obsolete_param, void * = 0) = 0; // 18
	virtual bool get_singlesided_obsolete (void * = 0) const = 0; // 19
	virtual void update_solid_texture (int viewpane, void* aux = 0) = 0; // 20
	virtual void clear_texture_obsolete (void* aux = 0) = 0; // 21
	virtual void clear_cache_deprecated (void* aux = 0) = 0; // 22
	virtual display_interface &set_all_lights_deprecated (bool all_lights_deprecated_param, void * = 0) = 0; // 23
	virtual bool get_all_lights_deprecated (void * = 0) const = 0; // 24
	virtual display_interface &set_texture_size (int texture_size_param, void * = 0) = 0; // 25
	virtual int get_texture_size (void * = 0) const = 0; // 26
	virtual void update_uv_texture_obsolete (void* aux = 0) = 0; // 27
	virtual void update_background (int viewpane, void* aux = 0) = 0; // 28
	virtual void clear_background_obsolete (void* aux = 0) = 0; // 29
	virtual display_interface &set_colored_shading_obsolete (bool colored_shading_obsolete_param, void * = 0) = 0; // 30
	virtual bool get_colored_shading_obsolete (void * = 0) const = 0; // 31
	virtual void setup_shading (void* aux = 0) = 0; // 32
	virtual void setup_normals (void* aux = 0) = 0; // 33
	virtual void setup_wireframe (void* aux = 0) = 0; // 34
	virtual display_interface &set_highlight_preview_obsolete (bool highlight_preview_obsolete_param, void * = 0) = 0; // 35
	virtual bool get_highlight_preview_obsolete (void * = 0) const = 0; // 36
	virtual display_interface &set_envmap_preview_obsolete (bool envmap_preview_obsolete_param, void * = 0) = 0; // 37
	virtual bool get_envmap_preview_obsolete (void * = 0) const = 0; // 38
	virtual void set_shading_mode (int viewpane, int shading_mode, void* aux = 0) = 0; // 39
	virtual int get_shading_mode (int viewpane, void* aux = 0) = 0; // 40
	virtual void set_lighting_mode (int viewpane, int lighting_mode, void* aux = 0) = 0; // 41
	virtual int get_lighting_mode (int viewpane, void* aux = 0) = 0; // 42
	virtual void set_show_normal (int viewpane, bool show_normal_param, void* aux = 0) = 0; // 43
	virtual bool get_show_normal (int viewpane, void* aux = 0) = 0; // 44
	virtual void set_show_bbox (int viewpane, bool show_bbox_param, void* aux = 0) = 0; // 45
	virtual bool get_show_bbox (int viewpane, void* aux = 0) = 0; // 46
	virtual void set_show_highlight (int viewpane, bool show_highlight_param, void* aux = 0) = 0; // 47
	virtual bool get_show_highlight (int viewpane, void* aux = 0) = 0; // 48
	virtual void set_show_envmap (int viewpane, bool show_envmap_param, void* aux = 0) = 0; // 49
	virtual bool get_show_envmap (int viewpane, void* aux = 0) = 0; // 50
	virtual void set_show_singlesided (int viewpane, bool show_singlesided_param, void* aux = 0) = 0; // 51
	virtual bool get_show_singlesided (int viewpane, void* aux = 0) = 0; // 52
	virtual void set_show_colored_shading (int viewpane, bool show_colored_shading_param, void* aux = 0) = 0; // 53
	virtual bool get_show_colored_shading (int viewpane, void* aux = 0) = 0; // 54
	virtual void set_show_grid (int viewpane, bool show_grid_param, void* aux = 0) = 0; // 55
	virtual bool get_show_grid (int viewpane, void* aux = 0) = 0; // 56
	virtual void set_show_background (int viewpane, bool show_background_param, void* aux = 0) = 0; // 57
	virtual bool get_show_background (int viewpane, void* aux = 0) = 0; // 58
	virtual void load_template_image (int viewpane, const char*const& file_path, void* aux = 0) = 0; // 59
	virtual void display_template_image (int viewpane, bool display_template_image_param, void* aux = 0) = 0; // 60
	virtual void clear_template_image (int viewpane, void* aux = 0) = 0; // 61
	virtual display_interface &set_colored_shading (bool colored_shading_param, void * = 0) = 0; // 62
	virtual display_interface &set_envmap_preview (bool envmap_preview_param, void * = 0) = 0; // 63
	virtual display_interface &set_highlight_preview (bool highlight_preview_param, void * = 0) = 0; // 64
	virtual display_interface &set_singlesided (bool singlesided_param, void * = 0) = 0; // 65
	virtual display_interface &set_all_shading_mode (int all_shading_mode_param, void * = 0) = 0; // 66
	virtual display_interface &set_all_lighting_mode (int all_lighting_mode_param, void * = 0) = 0; // 67
	virtual display_interface &set_flat (bool flat_param, void * = 0) = 0; // 68
	virtual display_interface &set_normal (bool normal_param, void * = 0) = 0; // 69
	virtual display_interface &set_bbox (bool bbox_param, void * = 0) = 0; // 70
	virtual display_interface &set_grid (bool grid_param, void * = 0) = 0; // 71
	virtual void set_uv_shading (int viewpane, bool uv_shading_param, void* aux = 0) = 0; // 72
	virtual void set_uv_display_image (int viewpane, bool uv_display_image_param, void* aux = 0) = 0; // 73
	virtual display_interface &set_uv_mode (int uv_mode_param, void * = 0) = 0; // 74
	virtual int get_uv_mode (void * = 0) const = 0; // 75
	virtual void set_uv_image_brightness (int viewpane, bool uv_image_brightness_param, void* aux = 0) = 0; // 76
	virtual void set_camera_type (int viewpane, int camera_type, int camera_index = 0, void* aux = 0) = 0; // 77
	virtual int get_camera_type (int viewpane, void* aux = 0) = 0; // 78
	virtual bool set_stereo_type (int stereo_type, void* aux = 0) = 0; // 79
	virtual int get_stereo_type (void* aux = 0) = 0; // 80
	};
}
