#pragma once
#include "sx/sxsdk/enums.hpp"

namespace sxsdk {
	inline static int text (const char t[]) {
		return (int(t[0]) << 24) | (int(t[1]) << 16) | (int(t[2]) << 8) | t[3];
	}

	class shade_plugin_info {
	public:
		int sdk_version;
		int recommended_shade_version;
		int major_version;
		int minor_version;
		int micro_version;
		int build_number;
		const char *product_name;
		const char *author;
		const char *company;
		const char *comments;
	};

	/// enums
	namespace enums {
		enum { U_PARAMETER, V_PARAMETER, U_DISTANCE, V_DISTANCE };

		/// \en blah \enden \ja トリガのためのフラグ\endja
		enum trigger_enum {
			active_scene_changed	= (1<<0),	///< \en blah \enden \ja アクティブなシーンの変更\endja
			active_shapes_changed	= (1<<1),	///< \en blah \enden \ja アクティブな形状の変更\endja
			texture_changed			= (1<<2),	///< \en blah \enden \ja テクスチャの変更\endja
			//active_image_changed	= (1<<3),	///< \en blah \enden \ja 画像の変更\endja
			active_shapes_modified	= (1<<4),	///< \en blah \enden \ja 形状の編集\endja
			shapes_deleted			= (1<<5),	///< \en blah \enden \ja 形状の削除\endja
		};
		/// \en blah \enden \ja 単位系\endja
		/// \ref supplement
		enum unit {
			mm,		///< \en mm (Shade native unit) \enden \ja mm (Shadeのネイティブ単位系) \endja
			cm,		///< cm
			m,		///< m
			km,		///< km
			inch,	///< inch
			foot,	///< foot
			yard,	///< yard
			mile	///< mile
		};
		/// \en blah \enden \ja 背景レイヤの適用範囲(\c enums::background_target_mask に移行)\endja
		enum background_part {
			upper,
			lower,
			current
		}; // obsolete
		/// \en blah \enden \ja 背景レイヤの適用範囲\endja
		enum background_target_mask {
			upper_hemisphere = 0x01,								///< \en blah \enden \ja 上半球\endja
			lower_hemisphere = 0x02,								///< \en blah \enden \ja 下半球\endja
			whole_sphere = (lower_hemisphere | upper_hemisphere)	///< \en blah \enden \ja 全体\endja
		};
		/// \en blah \enden \ja 形状の種類\endja
		enum shape_type {
			sentinel		= 0,	///< \en blah \enden \ja 番兵形状\endja
			dxf_insert		= 1,	///< \en blah \enden \ja 未使用\endja
			part			= 2,	///< \en blah \enden \ja パート\endja
			light			= 3,	///< \en blah \enden \ja 光源\endja
			line			= 4,	///< \en blah \enden \ja 線形状\endja
			sphere			= 5,	///< \en blah \enden \ja 球\endja
			disk			= 6,	///< \en blah \enden \ja 円\endja
			polygon_mesh	= 7,	///< \en blah \enden \ja ポリゴンメッシュ\endja
			master_surface	= 8,	///< \en blah \enden \ja マスターサーフェス\endja
			proxy_shape		= 9,	///< \en blah \enden \ja プロクシ形状\endja
			master_image	= 10,	///< \en blah \enden \ja イメージオブジェクト\endja
			base_shape,					///< \en blah \enden \ja 未使用\endja
			shape,						///< \en blah \enden \ja 未使用\endja

			polygon = line,				///< \en for backward compat. \enden \ja 未使用\endja
			polygonmesh = polygon_mesh,	///< \en for backward compat. \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja パートの種類\endja
		enum part_type {
			simple_part					= 0,	///< \en blah \enden \ja パート\endja
			surface_part				= 1,	///< \en blah \enden \ja 自由曲面\endja
			rotator_joint				= 2,	///< \en blah \enden \ja 回転ジョイント\endja
			slider_joint				= 3,	///< \en blah \enden \ja 直線移動ジョイント\endja
			scale_joint					= 4,	///< \en blah \enden \ja 拡大縮小ジョイント\endja
			uniscale_joint				= 5,	///< \en blah \enden \ja 均等拡大縮小ジョイント\endja
			light_joint					= 6,	///< \en blah \enden \ja 光源ジョイント\endja
			path_joint					= 7,	///< \en blah \enden \ja パスジョイント\endja
			morph_joint					= 8,	///< \en blah \enden \ja 変形ジョイント\endja
			custom_joint				= 9,	///< \en blah \enden \ja カスタムジョイント\endja
			ball_joint					= 10,	///< \en blah \enden \ja ボールジョイント\endja
			camera_joint				= 11,	///< \en blah \enden \ja カメラ\endja
			sound_part					= 12,	///< \en blah \enden \ja サウンド\endja
			switch_joint				= 13,	///< \en blah \enden \ja スイッチジョイント\endja
			path_replicator				= 14,	///< \en blah \enden \ja パスリプリケータendja
			master_surface_part			= 100,	///< \en blah \enden \ja マスターサーフェスパート\endja
			link_part					= 101,	///< \en blah \enden \ja リンク形状\endja
			master_image_part			= 102,	///< \en blah \enden \ja イメージパート\endja
			master_shape_part			= 103,	///< \en blah \enden \ja マスターオブジェクトパート\endja
			master_shape_object_part	= 104,	///< \en blah \enden \ja 外部参照形状\endja
			local_axis_part				= 105	///< \en blah \enden \ja ローカル座標\endja
		};
		/// \ja 背景マッピングパターンの種類\endja
		enum background_texture {
			NoEnv,		///< \en blah \enden \ja なし\endja
			Cloud,		///< \en blah \enden \ja 雲\endja
			Ocean,		///< \en blah \enden \ja 海\endja
			Marble,		///< \en blah \enden \ja 大理石\endja
			Spotted,	///< \en blah \enden \ja スポット\endja
			Check,		///< \en blah \enden \ja チェック\endja
			Fog,		///< \en blah \enden \ja 霧\endja
			Pic,		///< \en blah \enden \ja イメージマッピング\endja
		};
		/// \en blah \enden \ja 表面材質マッピングパターンの種類\endja
		enum pattern_type { // do not change order
			no_pattern,					///< \en blah \enden \ja なし\endja
			void_pattern,				///< \en blah \enden \ja 未使用\endja
			stripe_pattern,				///< \en blah \enden \ja ストライプ\endja
			check_pattern,				///< \en blah \enden \ja チェック\endja
			spotted_pattern,			///< \en blah \enden \ja スポット\endja
			marble_pattern,				///< \en blah \enden \ja 大理石\endja
			woody_pattern,				///< \en blah \enden \ja 木目\endja
			log_pattern,				///< \en blah \enden \ja 丸太\endja
			bumpy_pattern_obsolete,		///< \en blah \enden \ja 未使用\endja
			wrinkle_pattern_obsolete,	///< \en blah \enden \ja 未使用\endja
			wave_pattern,				///< \en blah \enden \ja 波\endja
			waves_pattern,				///< \en blah \enden \ja 海\endja
			cloud_pattern,				///< \en blah \enden \ja 雲\endja
			metallic_pattern_obsolete,	///< \en blah \enden \ja 未使用\endja
			image_pattern,				///< \en blah \enden \ja イメージマッピング\endja
			last_pattern,				///< \en blah \enden \ja 未使用\endja
			//custom_pattern = 256 // and up...
		};
		/// \en blah \enden \ja マッピングのタイプ\endja
		enum mapping_type { // do not change order
			diffuse_mapping,			///< \en blah \enden \ja 拡散反射\endja
			specular1_mapping,			///< \en blah \enden \ja 光沢１\endja
			specular2_mapping,			///< \en blah \enden \ja 光沢２\endja
			reflection_mapping,			///< \en blah \enden \ja 反射\endja
			transparency_mapping,		///< \en blah \enden \ja 透明度\endja
			bump_mapping,				///< \en blah \enden \ja バンプ\endja
			trim_mapping,				///< \en blah \enden \ja トリム\endja
			environment_mapping,		///< \en blah \enden \ja 環境\endja
			glow_mapping,				///< \en blah \enden \ja 発光\endja
			backlight_mapping,			///< \en blah \enden \ja バックライト\endja
			weight_mapping,				///< \en blah \enden \ja マット\endja
			refraction_mapping,			///< \en blah \enden \ja 屈折\endja
			roughness_mapping,			///< \en blah \enden \ja 反射の荒さ\endja
			anisotropic_mapping,		///< \en blah \enden \ja 異方性反射\endja
			fresnel_reflection_mapping,	///< \en blah \enden \ja フレネル反射\endja
			aberration_mapping,			///< \en blah \enden \ja 屈折の収差\endja
			ambient_mapping,			///< \en blah \enden \ja 環境光\endja
			volume_distance_mapping,	///< \en blah \enden \ja ボリューム減衰距離\endja
			volume_color_mapping,		///< \en blah \enden \ja ボリューム色\endja
			volume_transparency_mapping,///< \en blah \enden \ja ボリューム透明度\endja
			volume_glow_mapping,		///< \en blah \enden \ja ボリューム発光\endja
			normal_mapping,				///< \en blah \enden \ja ノーマル\endja
			displacement_mapping,		///< \en blah \enden \ja ディスプレイスメント\endja
			// <-- append new mapping type here, before void_mapping
			void_mapping,				///< \en blah \enden \ja 未使用\endja
			last_mapping = void_mapping	///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja マッピングの投影手法の種類\endja
		enum mapping_projection_type {
			x_projection		= 0,	///< \en blah \enden \ja X軸投影\endja
			y_projection		= 1,	///< \en blah \enden \ja Y軸投影\endja
			z_projection		= 2,	///< \en blah \enden \ja Z軸投影\endja
			wrap				= 3,	///< \en blah \enden \ja ラップ（UVマッピング）\endja
			omni = wrap,				///< \en blah \enden \ja ラップ（プロシージャルのソリッドマッピング）\endja
			cylinder_projection	= 4,	///< \en blah \enden \ja 円柱投影\endja
			sphere_projection	= 5,	///< \en blah \enden \ja 球投影\endja
			box_projection		= 6,	///< \en blah \enden \ja ボックス投影（法線に合わせてX, Y, Z軸投影のいずれかに割り振り）\endja
			last_mapping_projection	///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja オブジェクトカメラのモーションの移動モード\endja
		enum anchor_type {
			eye_target_mode,	///< \en blah \enden \ja 視点＆注視点\endja
			eye_mode,			///< \en blah \enden \ja 視点\endja
			target_mode,		///< \en blah \enden \ja 注視点\endja
			void_anchor_mode	///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja カメラの動作モード\endja
		enum camera_mode {
			normal_camera_mode,	///< \en blah \enden \ja 通常\endja
			top_camera_mode,	///< \en blah \enden \ja 上面図\endja
			free_camera_mode	///< \en blah \enden \ja フリー\endja
		};
		enum master_camera_mode {
			none_master_camera_mode,
			eye_master_camera_mode,
			target_master_camera_mode
		};
		/// \en blah \enden \ja 影の種類\endja
		enum shadow_type {
			inherit_shadow_type,	///< \en blah \enden \ja 継承\endja
			raytracing_shadow_type,	///< \en blah \enden \ja レイトレーシング\endja
			shadowmap_shadow_type	///< \en blah \enden \ja シャドウマップ\endja
		};
		/// \en blah \enden \ja 影を落とす方式の種類\endja
		enum castshadow_type {
			disable_castshadow,	///< \en blah \enden \ja 影なし\endja
			enable_castshadow,	///< \en blah \enden \ja 影あり\endja
			inverse_castshadow,	///< \en blah \enden \ja 影の範囲を反転\endja
			last_castshadow		///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja マッピングの合成モード \endja
		enum mapping_mix_mode {
			mapping_blend_mode,			///< \en blah \enden \ja 通常\endja
			mapping_alpha_blend_mode,	///< \en blah \enden \ja αブレンド\endja
			mapping_add_mode,			///< \en blah \enden \ja 加算\endja
			mapping_sub_mode,			///< \en blah \enden \ja 減算\endja
			mapping_mul_mode,			///< \en blah \enden \ja 乗算\endja
			mapping_max_mode,			///< \en blah \enden \ja 比較(明)\endja
			mapping_min_mode			///< \en blah \enden \ja 比較(暗)\endja
		};
		/// \en blah \enden \ja \c image_interface への描画の合成モード \endja
		enum image_mix_mode {
			image_blend_mode,		///< \en blah \enden \ja 通常\endja
			image_alpha_blend_mode,	///< \en blah \enden \ja αブレンド\endja
			image_add_mode,			///< \en blah \enden \ja 加算\endja
			image_sub_mode,			///< \en blah \enden \ja 減算\endja
			image_mul_mode,			///< \en blah \enden \ja 乗算\endja
			image_max_mode,			///< \en blah \enden \ja 比較(明)\endja
			image_min_mode			///< \en blah \enden \ja 比較(暗)\endja
		};
		/// \en blah \enden \ja 面光源、線光源のどちらか \endja
		enum light_type {
			area_light,		///< \en blah \enden \ja 面光源\endja
			linear_light,	///< \en blah \enden \ja 線光源\endja
			no_light = -1	///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja 光源の種類 \endja
		enum light_distribution_type {
			point_light,		///< \en blah \enden \ja 点光源\endja
			spotlight,			///< \en blah \enden \ja スポットライト\endja
			distribution_light,	///< \en blah \enden \ja 配光光源\endja
			directional_light,	///< \en blah \enden \ja 平行光源\endja
			last_light_distribution	///< \en blah \enden \ja 未使用\endja
		};
		static inline bool has_direction (light_distribution_type type) { return (type != point_light); }	///< \en blah \enden \ja 光源が向きを持つ種類かどうか \endja
		/// \en blah \enden \ja 減衰の種類 \endja
		enum attenuation_type {
			no_attenuation,			///< \en blah \enden \ja 減衰なし\endja
			linear_attenuation,		///< \en blah \enden \ja 線形減衰\endja
			quadratic_attenuation,	///< \en blah \enden \ja 二次減衰\endja
			last_attenuation		///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja 大域照明の種類 \endja
		enum global_illumination_type {
			no_global_illumination,		///< \en blah \enden \ja なし\endja
			path_tracing,				///< \en blah \enden \ja パストレーシング\endja
			photon_mapping,				///< \en blah \enden \ja フォトンマップ\endja
			radiosity,					///< \en blah \enden \ja ラジオシティ\endja
			native_radiosity_obsolete,	///< \en blah \enden \ja ラジオシティ\endja
			final_gathering,			///< \en blah \enden \ja パストレーシング+フォトンマップ\endja
			last_global_illumination	///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja 背景のイメージマッピングの投影の種類 \endja
		enum background_projection_type {
			background_planar_projection,		///< \en blah \enden \ja 平面\endja
			background_spherical_projection,	///< \en blah \enden \ja 球\endja
			background_lightprobe_projection,	///< \en blah \enden \ja ライトプローブ\endja
			background_cubemap_projection,		///< \en blah \enden \ja キューブマップ\endja
			background_verticalcross_projection	///< \en blah \enden \ja バーティカルクロス\endja
		};
		/// \en blah \enden \ja パノラマレンダリングの投影の種類 \endja
		enum panorama_projection_type {
			panorama_none_projection,			///< \en blah \enden \ja なし\endja
			panorama_cylindrical_projection,	///< \en blah \enden \ja 円柱投影\endja
			panorama_spherical_projection,		///< \en blah \enden \ja 球投影\endja
			panorama_lightprobe_projection,		///< \en blah \enden \ja ライトプローブ\endja
			panorama_cubemap_projection,		///< \en blah \enden \ja キューブマップ\endja
			panorama_verticalcross_projection	///< \en blah \enden \ja バーティカルクロス\endja
		};
		/// \en Correction type of Path joint \enden \ja パスジョイントの補正モード \endja
		enum path_correction_type {
			parameter_correction,	///< \en blah \enden \ja コントロールポイント（パラメータ）\endja
			distance_correction		///< \en blah \enden \ja 距離補正\endja
		};
		/// \en Upper direction type of Path joint direction control \enden \ja パスジョイント方向制御の上方向 \endja
		enum path_upper_direction_type {
			X_axis = 0,	///< \en blah \enden \ja X軸 \endja
			Y_axis = 1,		///< \en blah \enden \ja Y軸 \endja
			Z_axis = 2,		///< \en blah \enden \ja Z軸 \endja
			auto_roll = 3,		///< \en blah \enden \ja 自動ロール \endja
		};
		/// \en Mode of path replicator \enden \ja パスリプリケータのモード \endja
		enum path_replicator_mode {
			path_replicator_mode_count = 0,	///< \en Count \enden \ja 個数指定 \endja
			path_replicator_mode_step = 1,		///< \en Step \enden \ja 間隔指定 \endja
		};
		/// \en Replication alignment type of path replicator \enden \ja パスリプリケータの配列タイプ \endja
		enum path_replicator_alignment_type {
			path_replicator_alignment_cluster = 0,	///< \en Cluster \enden \ja クラスター \endja
			path_replicator_alignment_iterate = 1,		///< \en Iterate \enden \ja 反復 \endja
			path_replicator_alignment_random = 2,		///< \en Random \enden \ja ランダム \endja
		};
		/// \en Replication rounding type of path replicator \enden \ja パスリプリケータの端数処理タイプ \endja
		enum path_replicator_step_rounding_type {
			path_replicator_step_rounding_none = 0,			///< \en None \enden \ja 無し \endja
			path_replicator_step_rounding_round_down = 1,	///< \en Round Down \enden \ja 切り捨て（均等化） \endja
			path_replicator_step_rounding_round_up = 2,		///< \en Round Up \enden \ja 切り上げ（均等化） \endja
			path_replicator_step_rounding_extend = 3,		///< \en Extend \enden \ja 延長 \endja
		};
		/// \en blah \enden \ja カメラウインドウの操作のモード \endja
		enum camera_trackmode_enum {
			eye_trackmode,		///< \en blah \enden \ja 視点\endja
			target_trackmode,	///< \en blah \enden \ja 注視点\endja
			eyetarget_trackmode,///< \en blah \enden \ja 視点＆注視点\endja
			zoom_trackmode		///< \en blah \enden \ja ズーム\endja
		};
		/// \en Selection mode of polygonmesh. \enden \ja ポリゴンメッシュの選択モード \endja
		enum selection_mode_enum {
			face_selection_mode,	///< \en face selection. \enden \ja 面選択\endja
			edge_selection_mode,	///< \en edge selection. \enden \ja 稜線選択\endja
			vertex_selection_mode	///< \en vertex selection. \enden \ja 頂点選択\endja
		};
		/// \en blah \enden \ja ブーリアンの種類 \endja
		enum boolean_operation {
			null_boolean_operation,
			nand,
			cut,
			or_, and_,
			local_nand,
			local_cut,
			local_or,
			local_and,
			partial_mapping,
			local_partial_mapping,
			exempt
		};
		/// \en blah \enden \ja UVマップの展開指定 \endja
		enum make_uv {
			uv_plane,
			uv_cylinder,
			uv_sphere,
			uv_box
		};
		/// \en blah \enden \ja 線種 \endja
		enum drafting_line_type {
			none_line,
			solid_line,
			dot_line,
			dashed_line,
			dash_dotted_line,
			dashed_two_dotted_line
		};
		/// \en blah \enden \ja 線の太さ \endja
		enum drafting_line_width {
			extension_line,
			extra_fine_line,
			fine_line,
			medium_line,
			thick_line,
			extra_thisk_line
		};
		/// \en blah \enden \ja 面の種類 \endja
		enum drafting_face_type {
			none_face,
			fill_face,
			transmission_face,
			hollow_out_face,
			hatching_envelope_face,
			architrave_face
		};
		/// \en blah \enden \ja シーンのプリセット \endja
		enum preset_scene_enum {
			empty_scene,			///< \en blah \enden \ja 空の新規シーン \endja
			surface_preview_scene,	///< \en blah \enden \ja 表面材質プレビューで使用するサンプルシーン \endja
			last_preset_scene		///< \en blah \enden \ja 未使用\endja
		};
		/// \en blah \enden \ja \c sxsdk::shade_interface::encode, \c sxsdk::shade_interface::decode で使用するテキストエンコーディングの種類 \endja
		enum text_encoding_enum {
			default_encoding,		///< \en blah \enden \ja \c get_text_encoding で設定したテキストエンコーディング \endja
			utf8_encoding,			///< \en blah \enden \ja UTF-8 \endja
			utf16_encoding,			///< \en blah \enden \ja UTF-16 \endja
			shift_jis_encoding,		///< \en blah \enden \ja Shift JIS \endja
			euc_jp_encoding,		///< \en blah \enden \ja EUC JP \endja
			iso_2022_jp_encoding,	///< \en blah \enden \ja ISO 2022 JP \endja
			system_encoding,		///< \en blah \enden \ja システムで設定されたエンコーディング(日本語環境では通常、Shift JISとなる。Macは環境設定を反映する) \endja
			last_encoding			///< \en blah \enden \ja 未使用 \endja
		};
		enum type_enum {
			universal_type,
			translate_type,
			scale_type,
			rotate_type,
			none_type,
			translate_rotate_type
		};
		enum matrix_type_enum {
			user_type,
			world_type,
			local_type,
			normal_type
		};
		enum stereo_output_type_enum {
			stereo_side_by_side,		///< \en Side by Side \enden \ja 平行法 \endja
			stereo_crosseye,			///< \en Crosseye \enden \ja 交差法 \endja
			stereo_anaglyph_dubois,		///< \en Anaglyph(Dubois method) \enden \ja 赤青メガネ(デュボア法) \endja
			stereo_anaglyph_halfcolor,	///< \en Anaglyph(Half Color) \enden \ja 赤青メガネ(ハーフカラー) \endja
			stereo_anaglyph_monochrome,	///< \en Anaglyph(Monochrome) \enden \ja 赤青メガネ(モノクロ) \endja
			stereo_striping_left,		///< \en Striping(Left first) \enden \ja ストライピング(左優先) \endja
			stereo_striping_right,		///< \en Striping(Right first) \enden \ja ストライピング(右優先) \endja
			stereo_left_eye,			///< \en Left eye only \enden \ja 左目画像のみ \endja
			stereo_right_eye,			///< \en Right eye only \enden \ja 右目画像のみ \endja
			last_stereo_output_type,	///< \en blah \enden \ja 未使用 \endja
			number_of_stereo_output_types = last_stereo_output_type
		};
	}

	/// \en blah \enden \ja マルチパスレンダリングに関連するenum \endja
	namespace multipass {
		/// \en blah \enden \ja マルチパスレンダリングで生成されるイメージレイヤーのカテゴリ \endja
		enum layer_type {
			combined_layers,		///< \en blah \enden \ja 統合レイヤー \endja
			color_layers,			///< \en blah \enden \ja カラー要素 \endja
			parameter_layers,		///< \en blah \enden \ja パラメータ要素 \endja
			object_mask_layers,		///< \en blah \enden \ja 形状マスク \endja
			surface_mask_layers,	///< \en blah \enden \ja 表面材質マスク \endja
			custom_layers,			///< \en blah \enden \ja プラグイン、スクリプトで生成したレイヤー \endja
			last_layers				///< \en blah \enden \ja 未使用 \endja
		};

		/// \en blah \enden \ja マルチパスレンダリングのカラー要素レイヤー \endja
		namespace color {
			/// \en blah \enden \ja レイヤーの種類のインデックス \endja
			enum type {
				background,		///< \en blah \enden \ja 背景 \endja
				diffuse,		///< \en blah \enden \ja 拡散反射 \endja
				specular,		///< \en blah \enden \ja 光沢 \endja
				shadow,			///< \en blah \enden \ja 影 \endja
				ambient,		///< \en blah \enden \ja 環境光 \endja
				glow,			///< \en blah \enden \ja 発光 \endja
				environment,	///< \en blah \enden \ja 環境マップ \endja
				refract,		///< \en blah \enden \ja 透明 \endja
				reflect,		///< \en blah \enden \ja 反射 \endja
				gi,				///< \en blah \enden \ja 大域照明 \endja
				caustics,		///< \en blah \enden \ja コースティクス(フォトンマッピング) \endja
				volumelight,	///< \en blah \enden \ja ボリュームライト \endja
				fog,			///< \en blah \enden \ja フォグ \endja
				last_type		///< \en blah \enden \ja 未使用 \endja
			};
			/// \en blah \enden \ja レイヤーのID名 \endja
			static const char *name[last_type] = {
				"Background",
				"Diffuse",
				"Specular",
				"Shadow",
				"Ambient",
				"Glow",
				"Environment",
				"Refract",
				"Reflect",
				"GI",
				"Caustics",
				"VolumeLight",
				"Fog"
			};
			static inline const char *get_name (type i) { return name[i]; }	///< \en blah \enden \ja レイヤーのID名を取得する \endja
			static inline std::size_t size () { return last_type; }			///< \en blah \enden \ja レイヤーの数 \endja
		}
		/// \en blah \enden \ja マルチパスレンダリングのパラメータ要素レイヤー \endja
		namespace parameter {
			/// \en blah \enden \ja レイヤーの種類のインデックス \endja
			enum type {
				pre_effect,			///< \en blah \enden \ja エフェクタ適用前 \endja
				transparency,		///< \en blah \enden \ja 透明度 \endja
				z_depth,			///< \en blah \enden \ja Z値 \endja
				z_depth_n,			///< \en blah \enden \ja Z値(n次レイ) \endja
				position,			///< \en blah \enden \ja 座標値 \endja
				xy_normal,			///< \en blah \enden \ja 法線(カメラ) \endja
				normal,				///< \en blah \enden \ja 法線(グローバル) \endja
				uv1,				///< \en blah \enden \ja UV座標(UV1, 距離補正) \endja
				uv2,				///< \en blah \enden \ja UV座標(UV2, UV) \endja
				light_diffuse,		///< \en blah \enden \ja 光源: 拡散反射 \endja
				light_specular,		///< \en blah \enden \ja 光源: 光沢 \endja
				light_gi,			///< \en blah \enden \ja 光源: 大域照明 \endja
				surface_diffuse,	///< \en blah \enden \ja 表面材質: 拡散反射色 \endja
				object_id,			///< \en blah \enden \ja 形状ID \endja
				surface_id,			///< \en blah \enden \ja 表面材質ID \endja
				marker,				///< \en blah \enden \ja マーカー色 \endja
				last_type			///< \en blah \enden \ja 未使用 \endja
			};
			/// \en blah \enden \ja レイヤーのID名 \endja
			static const char *name[last_type] = {
				"PreEffect",
				"Transparency",
				"ZDepth",
				"ZDepthN",
				"Position",
				"XYNormal",
				"Normal",
				"UV1",
				"UV2",
				"LightDiffuse",
				"LightSpecular",
				"LightGI",
				"SurfaceDiffuse",
				"ObjectID",
				"SurfaceID",
				"Marker"
			};
			static inline const char *get_name (type i) { return name[i]; }	///< \en blah \enden \ja レイヤーのID名を取得する \endja
			static inline std::size_t size () { return last_type; }			///< \en blah \enden \ja レイヤーの数 \endja
		}
		/// \en blah \enden \ja マルチパスレンダリングの形状マスクレイヤー \endja
		namespace object_mask {
			/// \en blah \enden \ja レイヤーのID名 \endja
			static const char *name = "ObjectMask";
			/// \en blah \enden \ja \a index からレイヤーのID名を取得する \endja
			static inline std::string get_name (int index) {
				std::stringstream ss;
				ss << name << index;
				return ss.str();
			}
			/// \en blah \enden \ja レイヤーのID名からマスクのindexを取得する。形状マスクのID名ではない場合は-1を返す。 \endja
			static inline int get_index (const std::string &s) {
				if (s.compare(0, strlen(name), name)) return -1;

				int index = -1;
				std::istringstream iss(s.substr(strlen(name)));
				iss >> index;
				return index;
			}
		}
		/// \en blah \enden \ja マルチパスレンダリングの表面材質マスクレイヤー \endja
		namespace surface_mask {
			/// \en blah \enden \ja レイヤーのID名 \endja
			static const char *name = "SurfaceMask";
			/// \en blah \enden \ja \a index からレイヤーのID名を取得する \endja
			static inline std::string get_name (int index) {
				std::stringstream ss;
				ss << name << index;
				return ss.str();
			}
			/// \en blah \enden \ja レイヤーのID名からマスクのindexを取得する。表面材質マスクのID名ではない場合は-1を返す。 \endja
			static inline int get_index (const std::string &s) {
				if (s.compare(0, strlen(name), name)) return -1;

				int index = -1;
				std::istringstream iss(s.substr(strlen(name)));
				iss >> index;
				return index;
			}
		}
	}

	namespace tag {
		namespace name {
			/// \en blah \enden \ja vector格納用タグ名称 \endja
			static const char *vector[4] = { "_x", "_y", "_z", "_w" };
		}
		static inline std::string add_vector (const std::string &path, int axis) { return path + tag::name::vector[axis]; }

		namespace drafting {
			/// \en blah \enden \ja メタタグのキー(UUID) \endja
			static const char *key = "D534EF1E-6AF5-4ce7-B171-43288DF0150C";
			enum name_type {
				line_type,
				line_width,
				face_type,
				face_color,
				last_name_type
			};
			static const char *name[last_name_type] = {
				"line_type",
				"line_width",
				"face_type",
				"face_color"
			};
			static inline std::string path (name_type type) { return std::string(key) + "." + name[type]; }
			static inline std::size_t size () { return last_name_type; }
		}
		namespace speed_display {
			/// \en blah \enden \ja メタタグのキー(UUID) \endja
			static const char *key = "5EE4376C-0E6E-4c1d-B549-58300682EAF0";
			/// \en blah \enden \ja SPEED用表示タグ名称 \endja
			enum name_type {
				t_3D,						///< \en blah \enden \ja 3D \endja
				t_3D_hole,					///< \en blah \enden \ja 3D 開口情報 \endja
				t_2D_floor_plan,			///< \en blah \enden \ja 2D 簡易平面表現 \endja
				t_2D_detailed_floor_plan,	///< \en blah \enden \ja 2D 詳細平面表現 \endja
				t_2D_cross_section_A,		///< \en blah \enden \ja 2D 断面表現 (A) \endja
				t_2D_cross_section_B,		///< \en blah \enden \ja 2D 断面表現 (B) \endja
				t_2D_cross_section_C,		///< \en blah \enden \ja 2D 断面表現 (C) \endja
				t_2D_cross_section_D,		///< \en blah \enden \ja 2D 断面表現 (D) \endja
				t_2D_detailed_section_A,	///< \en blah \enden \ja 2D 矩計表現 (A) \endja
				t_2D_detailed_section_B,	///< \en blah \enden \ja 2D 矩計表現 (B) \endja
				t_2D_detailed_section_C,	///< \en blah \enden \ja 2D 矩計表現 (C) \endja
				t_2D_detailed_section_D,	///< \en blah \enden \ja 2D 矩計表現 (D) \endja
				t_2D_projection_A,			///< \en blah \enden \ja 2D 投影表現 (A) \endja
				t_2D_projection_B,			///< \en blah \enden \ja 2D 投影表現 (B) \endja
				t_2D_projection_C,			///< \en blah \enden \ja 2D 投影表現 (C) \endja
				t_2D_projection_D,			///< \en blah \enden \ja 2D 投影表現 (D) \endja
				separator,					///< \en blah \enden \ja セパレータ \endja
				last_name_type
			};
			static const char *name[last_name_type] = {
				"3D",						///< \en blah \enden \ja 3D \endja
				"3D_hole",					///< \en blah \enden \ja 3D 開口情報 \endja
				"2D_floor_plan",			///< \en blah \enden \ja 2D 簡易平面表現 \endja
				"2D_detailed_floor_plan",	///< \en blah \enden \ja 2D 詳細平面表現 \endja
				"2D_cross_section_A",		///< \en blah \enden \ja 2D 断面表現 (A) \endja
				"2D_cross_section_B",		///< \en blah \enden \ja 2D 断面表現 (B) \endja
				"2D_cross_section_C",		///< \en blah \enden \ja 2D 断面表現 (C) \endja
				"2D_cross_section_D",		///< \en blah \enden \ja 2D 断面表現 (D) \endja
				"2D_detailed_section_A",	///< \en blah \enden \ja 2D 矩計表現 (A) \endja
				"2D_detailed_section_B",	///< \en blah \enden \ja 2D 矩計表現 (B) \endja
				"2D_detailed_section_C",	///< \en blah \enden \ja 2D 矩計表現 (C) \endja
				"2D_detailed_section_D",	///< \en blah \enden \ja 2D 矩計表現 (D) \endja
				"2D_projection_A",			///< \en blah \enden \ja 2D 投影表現 (A) \endja
				"2D_projection_B",			///< \en blah \enden \ja 2D 投影表現 (B) \endja
				"2D_projection_C",			///< \en blah \enden \ja 2D 投影表現 (C) \endja
				"2D_projection_D",			///< \en blah \enden \ja 2D 投影表現 (D) \endja
				"separator"					///< \en blah \enden \ja セパレータ \endja
			};
			static inline std::string path (name_type type) { return std::string(key) + "." + name[type]; }
			static inline std::size_t size () { return last_name_type; }
		}
		namespace axis_sets {
			/// \en blah \enden \ja メタタグのキー(UUID) \endja
			static const char *key = "6D8A1BE3-A60E-4275-986E-BDB009920F29";
			/// \en blah \enden \ja メタタグのキーと組み合わせる名前(任意文字列) \endja
			enum name_type {
				axis,				///< \en blah \enden \ja axis \endja
				temp_axis,			///< \en blah \enden \ja temp_axis \endja
				modeling_camera,	///< \en blah \enden \ja modeling_camera \endja
				last_name_type
			};
			static const char *name[last_name_type] =
			{
				"axis",					///< \en blah \enden \ja axis \endja
				"temp_axis",			///< \en blah \enden \ja temp_axis \endja
				"modeling_camera"		///< \en blah \enden \ja modeling_camera \endja
			};
			static inline std::string path (name_type type) { return std::string(key) + "." + name[type]; }
			static inline std::size_t size () { return last_name_type; }
		}
	}
	// compatibility definition for SPEED plugins
	//#if !XSHADE && !RENDERER && !MEDIATOR && !PLUGIN
	//	namespace tag {
	//		///< \en blah \enden \ja メタタグのキー(UUID) \endja
	//		namespace key {
	//			const std::string drafting_tag_key	= "D534EF1E-6AF5-4ce7-B171-43288DF0150C";
	//			const std::string display_tag_key	= "5EE4376C-0E6E-4c1d-B549-58300682EAF0";
	//		}
	//		///< \en blah \enden \ja メタタグのキーと組み合わせる名前(任意文字列) \endja
	//		namespace name {
	//		///< \en blah \enden \ja vector格納用タグ名称 \endja
	//			const std::string vector_tag_name[4] = { "_x", "_y", "_z", "_w" };
	//		///< \en blah \enden \ja SPEED用表示タグ名称 \endja
	//			const std::string speed_display_tag_name[] = {
	//				"3D",						///< \en blah \enden \ja 3D \endja
	//				"3D_hole",					///< \en blah \enden \ja 3D 開口情報 \endja
	//				"2D_floor_plan",			///< \en blah \enden \ja 2D 簡易平面表現 \endja
	//				"2D_detailed_floor_plan",	///< \en blah \enden \ja 2D 詳細平面表現 \endja
	//				"2D_cross_section_A",		///< \en blah \enden \ja 2D 断面表現 (A) \endja
	//				"2D_cross_section_B",		///< \en blah \enden \ja 2D 断面表現 (B) \endja
	//				"2D_cross_section_C",		///< \en blah \enden \ja 2D 断面表現 (C) \endja
	//				"2D_cross_section_D",		///< \en blah \enden \ja 2D 断面表現 (D) \endja
	//				"2D_detailed_section_A",	///< \en blah \enden \ja 2D 矩計表現 (A) \endja
	//				"2D_detailed_section_B",	///< \en blah \enden \ja 2D 矩計表現 (B) \endja
	//				"2D_detailed_section_C",	///< \en blah \enden \ja 2D 矩計表現 (C) \endja
	//				"2D_detailed_section_D",	///< \en blah \enden \ja 2D 矩計表現 (D) \endja
	//				"2D_projection_A",			///< \en blah \enden \ja 2D 投影表現 (A) \endja
	//				"2D_projection_B",			///< \en blah \enden \ja 2D 投影表現 (B) \endja
	//				"2D_projection_C",			///< \en blah \enden \ja 2D 投影表現 (C) \endja
	//				"2D_projection_D"			///< \en blah \enden \ja 2D 投影表現 (D) \endja
	//			};
	//		}
	//	}
	#//endif

	// compatibility
	using sx::little_endian;
	using sx::big_endian;
//	using sx::swap_endian_2;
//	using sx::swap_endian_4;
//	using sx::swap_endian_8;
	using sx::revert_endian;
	using sx::to_little_endian;
	using sx::to_big_endian;
	using sx::from_little_endian;
	using sx::from_big_endian;

	// compatibility
	namespace shade {
		enum { R, G, B, A };
		enum { U, V };
		enum {
			U_PARAMETER = sxsdk::enums::U_PARAMETER,
			V_PARAMETER = sxsdk::enums::V_PARAMETER,
			U_DISTANCE	= sxsdk::enums::U_DISTANCE,
			V_DISTANCE	= sxsdk::enums::V_DISTANCE,
		};
	}

	namespace enums {
		/// \en Dialog action flags \enden \ja ダイアログアイテムに対してされた動作の詳細 (過去互換定義： sx::dialog_item::item_action_enum の使用を推奨) \endja
		enum dialog_item_action_enum {
			generic_dialog_item_action		= sx::dialog_item::generic_action,
			step_down_dialog_item_action	= sx::dialog_item::step_down_action,
			step_up_dialog_item_action		= sx::dialog_item::step_up_action,
			track_dialog_item_action		= sx::dialog_item::track_action,
			change_dialog_item_action		= sx::dialog_item::changing_action,
		};
		/// \en Window flags \enden \ja ウインドウのフラグ (過去互換定義： sx::window_flag の使用を推奨) \endja
		enum window_flag {
			h_resizeable		= sx::h_resizeable,
			v_resizeable		= sx::v_resizeable,
			resizable			= sx::resizable,
			h_scroll			= sx::h_scroll,
			v_scroll			= sx::v_scroll,
			hv_scroll			= sx::hv_scroll,
			h_scroll_bar		= sx::h_scroll_bar,
			v_scroll_bar		= sx::v_scroll_bar,
			hv_scroll_bar		= sx::hv_scroll_bar,
			maximize			= sx::maximize,
			maximize_box		= sx::maximize_box,
			minimize_box		= sx::minimize_box,
			zoomable			= sx::zoomable,
			opengl_window		= sx::opengl_window,
			no_title_bar		= sx::no_title_bar,
			text_window			= sx::text_window,
			size_box			= sx::size_box,
			scalable			= sx::scalable,
			grouped_window		= sx::grouped_window,
			readonly_text		= sx::readonly_text,
			single_line_text	= sx::single_line_text,
			text_hscroll		= sx::text_hscroll,
			text_vscroll		= sx::text_vscroll,
			transient_window	= sx::transient_window,
		};
		/// \en Key flags \enden \ja キーフラグ (過去互換定義： sx::key::key_flag の使用を推奨) \endja
		enum key_flag {
			option				= sx::key::option,
			command				= sx::key::command,
			alt					= sx::key::alt,
			control				= sx::key::control,
			shift				= sx::key::shift,
			space				= sx::key::space,
			constraint			= sx::key::constraint,
			range_selection		= sx::key::range_selection,
			multiple_selection	= sx::key::multiple_selection,
			extension			= sx::key::extension,
			pure_extension		= sx::key::pure_extension
		};
	}

	namespace smlib {
		enum err_status { sm_success, sm_err, sm_memory, sm_unknown, sm_fatal, sm_assert_failure, sm_null_pointer };
		enum boolean_operation_type {
			bo_union,					// Union of solids A and B (A + B)
			bo_intersection,			// Intersection of solids A and B (A & B)
			bo_different,				// Difference of solids - A minus B (A - B)
			bo_merge,					// Merge Operation (A + B = C)
			bo_partial_merge,			// Merge subset of parts of one polymesh into the other
			bo_extract_separate,		// Extract into separate polymesh
			bo_surface_intersection,	// Intersection of surface A and B (A & B)
			bo_surface_different		// Difference of surface - A minus B (A - B)
		};
	}
	
	namespace database {
		struct blobdata {
			const void *blob;
			int byts;
		};
	}
}
