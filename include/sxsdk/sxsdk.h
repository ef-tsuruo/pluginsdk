#pragma once
#include "sx/core/debug.hpp"
#include "sx/core/config.hpp"
#include "sx/core.h"
#include "sxsdk/shadebuildnumber.h"
#include "sxsdk/com.h"
#include "sxsdk/uuid.h"
#include "sxsdk/types.h"
#include "sx/core/signature.hpp"
#include "sx/core/memory.hpp"
#include "sx/core/simd.hpp"
#include "sx/core/bounds.hpp"
#include "sx/core/vectors.hpp"
#include "sx/core/pixel.hpp"
#include "sx/core/vectorutility.hpp"
#include "sxsdk/vecs.h"

#if SXQUICKTIME
	#if SXMACOSX
		#include <QuickTime/ImageCompression.h>
	#else
		#define DEBUG _DEBUG
		#include <ImageCompression.h>
	#endif
#else
	typedef void CodecType;
	typedef void CodecQ;
#endif

#if USE_PYTHON
	#include <Python.h>
#else
	typedef void PyObject;
#endif

#if !SXWINDOWS
	typedef void *HWND;
#endif

#if SXPLUGIN
	#define SXPLUGINNAMESPACEBEGIN(NAME)
	#define SXPLUGINNAMESPACEEND
	#define SXPLUGINENTRY
	#if SXWINDOWS
		#define DLLEXPORT __declspec(dllexport)
	#else
		#define DLLEXPORT
	#endif
#else
	#define SXPLUGINNAMESPACEBEGIN(NAME) namespace NAME {
	#define SXPLUGINNAMESPACEEND }
	#define SXPLUGINENTRY
#ifndef DLLEXPORT
	#define DLLEXPORT
#endif
#endif

namespace sx {
	class mouse_tracker_class;
	class uuid_class;
	class list_item_value_class;
}
namespace xshade {
	namespace control {
		typedef void *control_class;
	}
	typedef void *window_class;
}
namespace sxsdk {
	// opaque types
	typedef void *plugin_push_button_class;
	typedef void *plugin_checkbox_class;
	typedef void *plugin_slider_class;
	typedef void *plugin_number_class;
	typedef void *plugin_popup_menu_class;
	typedef void *plugin_color_disk_class;
	typedef void *plugin_color_box_class;
	typedef void *plugin_image_box_class;
	typedef void *plugin_static_text_class;
	typedef void *plugin_radio_button_class;
	typedef void *plugin_disclosure_button_class;
	typedef void *plugin_tab_class;
	typedef void *plugin_vec2_control_class;
	typedef void *plugin_vec3_control_class;
	typedef void *plugin_vec4_control_class;
	typedef void *plugin_quaternion_control_class;
	typedef void *plugin_matrix_control_class;
	typedef void *plugin_scale_control_class;
	typedef void *plugin_flasher_class;
	typedef void *plugin_table_control_class;
	typedef void *plugin_editable_text_class;

	class meshtools_window_interface;
	class meshtools_view_interface;
	class scene_interface;
	class renderingservice_interface;
	class dialog_interface;
	class image_view_interface;
	class tool_box_view_interface;
	class color_view_interface;
	class background_view_interface;
	class surface_view_interface;
	class browser_view_interface;
	class correction_view_interface;
	class camera_view_interface;
	class distant_light_view_interface;
	class ruler_view_interface;
	class message_view_interface;
	class script_view_interface;
	class shortcut_view_interface;
	class radiosity_view_interface;
	class skin_view_interface;
	class motion_view_interface;
	class object_info_view_interface;
	class aggregate_view_interface;
	class rendering_options_view_interface;
	class radiosity_options_view_interface;
	class stream_interface;
	class window_interface;
	class handler_interface;
	class image_interface;
	class image_layer_interface;
	class graphic_context_interface;
	class shortcut_interface;
	class script_interface;
	class progress_dialog_interface;
	class text_stream_interface;
	class critical_section_interface;
	class color_interface;
	class color_list_interface;
	class preference_interface;
	class dll_interface;
	class plugin_interface;
	class image_window_interface;
	class tool_box_window_interface;
	class camera_window_interface;
	class distant_light_window_interface;
	class color_window_interface;
	class color_list_window_interface;
	class background_window_interface;
	class surface_window_interface;
	class browser_window_interface;
	class correction_window_interface;
	class get_backdrop_window_interface;
	class ruler_window_interface;
	class radiosity_window_interface;
	class shortcut_window_interface;
	class script_window_interface;
	class skin_window_interface;
	class motion_window_interface;
	class aggregate_window_interface;
	class stream_interface;
	class text_stream_interface;
	class message_window_interface;
	class object_info_window_interface;
	class strings_interface;
	class surface_interface;
	class rendering_context_interface;
	class motion_interface;
	class mesh_interface;
	class shape_interface;
	class meshes_interface;
	class polygon_mesh_interface;
	class shape_saver_interface;
	class texture_interface;
	class radiosity_attributes_interface;
	class rotator_joint_interface;
	class slider_joint_interface;
	class scale_joint_interface;
	class uniscale_joint_interface;
	class light_effector_interface;
	class path_joint_interface;
	class morph_effector_interface;
	class ball_joint_interface;
	class custom_joint_interface;
	class sound_track_interface;
	class switch_effector_interface;
	class part_interface;
	class surface_saver_class;
	class light_interface;
	class disk_interface;
	class line_interface;
	class vertex_attribute_interface;
	class sphere_interface;
	class distant_light_interface;
	class camera_interface;
	class plugin_exporter_interface;
	class exporter_settings_interface;
	class points_interface;
	class bitmap_interface;
	class motion_point_interface;
	class property_list_interface;
	class renderer_interface;
	class background_interface;
	class graphics_interface;
	class rendering_interface;
	class rendering_image_invalidator_interface;
	class correction_interface;
	class quickrendering_interface;
	class fog_interface;
	class radiosity_interface;
	class animation_settings_interface;
	class keyframes_interface;
	class figure_window_interface;
	class figure_view_interface;
	class display_interface;
	class path_replicator_interface;
	class speed_interface;
	class loader_interface;
	class loader_info_interface;
	class expression_interface;
	class shade_interface;
	class implementation_interface;

	class output_function_class;
	class shader_info_base_class;
	class dialog_item_class;
	class shape_class;
	class part_class;
	class joint_value_class;
	class master_surface_class;
	class line_class;
	class polygon_mesh_class;
	class disk_class;
	class sphere_class;
	class light_class;
	class proxy_shape_class;
	class master_image_class;
	class master_shape_class;
	class line_saver_class;
	class polygon_mesh_saver_class;
	class sphere_saver_class;
	class disk_saver_class;
	class background_layer_class;
	class camera_class;
	class control_point_class;
	class distant_light_item_class;
	class edge_class;
	class face_class;
	class vertex_class;
	class joint_value_class;
	class mapping_layer_class;
	class shader_node_class;
	class rendering_light_class;
	class skin_bind_class;
	class skin_class;
	class surface_class;
	class shape_mix_class;
	class proxy_shape_mix_class;
	class intersection_class;
	class custom_element_info_base_class;
}
#define DEFINE_DYNAMIC_CAST(class_name, base_name, shape_type) static class_name &cast (base_name &s) { if (s.get_type() != shape_type) throw std::bad_cast(); return static_cast<class_name &>(s); } static const class_name &cast (const base_name &s) { if (s.get_type() != shape_type) throw std::bad_cast(); return static_cast<const class_name &>(s); } static class_name *cast (base_name *s) { if (s && s->get_type() != shape_type) return 0; return static_cast<class_name *>(s); } static const class_name *cast (const base_name *s) { if (s && s->get_type() != shape_type) return 0; return static_cast<const class_name *>(s); } 

#include "sx/sxsdk/enums.hpp"
#include "sxsdk/implementationinterface.h"
#include "sxsdk/shadeinterface.h"
#include "sxsdk/shapeclass.h"
#include "sxsdk/vertexclass.h"
#include "sxsdk/controlpointclass.h"
#include "sxsdk/plugininterface.h"
#include "sxsdk/mappinglayerclass.h"
#include "sxsdk/surfaceinterface.h"
#include "sxsdk/camerainterface.h"
#include "sxsdk/distantlightitemclass.h"
#include "sxsdk/distantlightinterface.h"
#include "sxsdk/dialoginterface.h"
#include "sxsdk/streaminterface.h"
#include "sxsdk/attributeinterface.h"
#include "sxsdk/sceneinterface.h"
#include "sxsdk/creatorinterface.h"
#include "sxsdk/importerinterface.h"
#include "sxsdk/browserinterface.h"
#include "sxsdk/stringsinterface.h"
#include "sxsdk/handlerinterface.h"
#include "sxsdk/windowinterface.h"
#include "sxsdk/graphiccontextinterface.h"
#include "sxsdk/imageinterface.h"
#include "sxsdk/imagelayerinterface.h"
#include "sxsdk/effectorinterface.h"
#include "sxsdk/renderingcontextinterface.h"
#include "sxsdk/renderinglightclass.h"
#include "sxsdk/exporterinterface.h"
#include "sxsdk/imageexporterinterface.h"
#include "sxsdk/pluginexporterinterface.h"
#include "sxsdk/textstreaminterface.h"
#include "sxsdk/figureinterface.h"
#include "sxsdk/imageboxinterface.h"
#include "sxsdk/imageimporterinterface.h"
#include "sxsdk/modifierinterface.h"
#include "sxsdk/renderinginterface.h"
#include "sxsdk/rendererinterface.h"
#include "sxsdk/pointsinterface.h"
#include "sxsdk/meshesinterface.h"
#include "sxsdk/textureinterface.h"
#include "sxsdk/shaderinterface.h"
#include "sxsdk/dllentries.h"
#include "sxsdk/pluginids.h"
#include "sxsdk/saver.h"
#include "sxsdk/jointvalueclass.h"
#include "sxsdk/cameraclass.h"
#include "sxsdk/animationsettingsinterface.h"
#include "sxsdk/backgroundinterface.h"
#include "sxsdk/backgroundlayerclass.h"
#include "sxsdk/bitmapinterface.h"
#include "sxsdk/colorinterface.h"
#include "sxsdk/colorlistinterface.h"
#include "sxsdk/correctioninterface.h"
#include "sxsdk/criticalsectioninterface.h"
#include "sxsdk/displayinterface.h"
#include "sxsdk/dllinterface.h"
#include "sxsdk/edgeclass.h"
#include "sxsdk/expressioninterface.h"
#include "sxsdk/faceclass.h"
#include "sxsdk/foginterface.h"
#include "sxsdk/graphicsinterface.h"
#include "sxsdk/keyframesinterface.h"
#include "sxsdk/loaderinterface.h"
#include "sxsdk/loaderinfointerface.h"
#include "sxsdk/meshinterface.h"
#include "sxsdk/motioninterface.h"
#include "sxsdk/preferenceinterface.h"
#include "sxsdk/progressdialoginterface.h"
#include "sxsdk/quickrenderinginterface.h"
#include "sxsdk/radiosityattributesinterface.h"
#include "sxsdk/radiosityinterface.h"
#include "sxsdk/renderingimageinterface.h"
#include "sxsdk/renderingserviceinterface.h"
#include "sxsdk/shadernodeclass.h"
#include "sxsdk/shapeinterface.h"
#include "sxsdk/shapesaverinterface.h"
#include "sxsdk/shortcutinterface.h"
#include "sxsdk/skinclass.h"
#include "sxsdk/speedinterface.h"
#include "sxsdk/surfaceclass.h"
