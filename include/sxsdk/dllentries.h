#pragma once

#if _MSC_VER
	#pragma warning(disable:4190)
#endif

namespace sxsdk {
	class shade_interface;
	class shade_plugin_info;
}

/// \file
/// \en The global functions common to all plugins. \enden \ja 共通のグローバル関数 \endja

/// \en Creates a new plugin interface object. \enden \ja インターフェイスの構築を行う。 \endja
extern "C" DLLEXPORT void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *aux = 0);
/// \en Returns the number of plugin interface objects. \enden \ja 使用するインターフェイスの数を返す。 \endja
extern "C" DLLEXPORT int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade);
/// \en Returns the name of the plugin  interface. \enden \ja プラグインの名前を返す。 \endja
extern "C" DLLEXPORT const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *aux = 0);
/// \en The menu group name. \enden \ja メニューのグループ名を定義する。 \endja
extern "C" DLLEXPORT const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *aux = 0);
/// \en Should return the plugin interface version number. \enden \ja プラグインインターフェイスバージョンを設定する。\c interface_version を返す。 \endja
extern "C" DLLEXPORT int __stdcall get_interface_version (void *aux = 0);
/// \en Should return true if the plugin is a resident plugin. \enden \ja 常駐させるかどうかを設定する。 \endja
extern "C" DLLEXPORT bool __stdcall is_resident (const IID &iid, int i, void* aux =0);
/// \en Returns the text encoding. \enden \ja テキストのエンコーディングを指定する。0を返し、UTF-8でコードを記述することを推奨。 \endja
extern "C" DLLEXPORT int __stdcall get_text_encoding (sxsdk::shade_interface *shade, void* aux =0);
/// \en Unused. \enden \ja 例外処理の設定をする。通常、定義する必要はない。 \endja
extern "C" DLLEXPORT int __stdcall get_exception (sxsdk::shade_interface *shade, void* aux =0);
/// \en Returns various plugin info. \enden \ja バージョン・デベロッパ情報を設定する。 \endja
extern "C" DLLEXPORT void __stdcall get_info (sxsdk::shade_plugin_info &info, sxsdk::shade_interface *shade, void* aux =0);
/// \en Should return true if the plugin interfaces do not depend on each other. \enden \ja 各インターフェイスが独立して動作可能かどうかを設定する。 \endja
extern "C" DLLEXPORT bool __stdcall has_separate_interfaces (void* aux =0);
/// \en Returns the plugin ID. \enden \ja プラグインIDを設定する。(\ref pluginid) \endja
extern "C" DLLEXPORT sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *aux = 0);
