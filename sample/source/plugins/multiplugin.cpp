#include "sxsdk.cxx"

//#include "sx/core/path.hpp"
//#include "model/socketconnection.hpp"
//#include "sx/core/tcp.hpp"
//#include "sx/core/idletask.hpp"
//#include "model/io/parser.hpp"
//#include "model/io/tag.hpp"
//#include "model/io/io.hpp"

//#include "surrogate/pluginprotocol.hpp"
//#include "model/io/in.hpp"
//#include "model/scene.hpp"

//namespace external {
//	class buffer_class : public sx::memorystream_class {
//	public:
//		sx::semaphore_class semaphore;
//		sx::recursive_mutex mutex;
//	};
//
//	class wait_class : public sx::idle::task_class {
//		sx::semaphore_class semaphore;
//	public:
//		explicit wait_class () : sx::idle::task_class(1000) { }
//		void wait () { semaphore.wait(); }
//	private: // notification
//		virtual void idle_pulse () { semaphore.set(); }
//	};
//
//	class plugin_connection_class : public socket_connection_class {
//		sx::uuid_class uuid;
//		sxsdk::scene_interface *scene;
//		std::string path;
//		buffer_class ibuffer, obuffer;
//		wait_class wait;
//	public:
//		plugin_connection_class (const sx::uuid_class &uuid, sxsdk::scene_interface *scene, const std::string &path) : uuid(uuid), scene(scene), path(path) { }
//		virtual void connected (sx::tcpstream_class &stream) {
//			std::cerr << "connected" << std::endl;
//			stream < sx::unsigned32(0x76543210) < std::flush;
//			stream < interface_version < std::flush;
//			stream < uuid < std::flush;
//			stream < model::io::string(0) < path;
//			stream < model::io::end();
//			stream < std::flush;
//			parser_class parser(stream);
//			parser.process_endian_marker();
//			sx::thread::sleep(1000);
//			try {
//				while (true) {
//					const int command = parser.read_command();
//					switch (command) {
//					case pluginprotocol::importer_result:
//						{	//scene->load_shape("C:\\Users\\takahashi\\Downloads\\Wall-E.shd");
//							const sx::vec<float,3> at(scene->scene.reference_point);
//							::load_shape(scene->scene, stream, false, at, true, true);
//						}
//						throw sx::no_error();
//					case pluginprotocol::terminate:
//						throw sx::no_error();
//					default:
//						std::cerr << "-1" << std::endl;
//						sx::thread::sleep(1000);
//						break;
//					}
//				}
//			}
//			catch (sx::no_error &) { }
//		}
//	};
//	void do_import (const sx::uuid_class &uuid, sxsdk::scene_interface *scene, sxsdk::stream_interface *stream, sxsdk::text_stream_interface *text_stream) {
//		#if SXMACOSX
//			SXASSERT(false);
//		#elif SXWINDOWS
////			const std::string exepath = sx::path::join(sx::path::application_directory_path(), "surrogate_debug.exe");
////			sx::path::shell_execute(exepath, "", false);
//		#endif
//		plugin_connection_class connection(uuid, scene, stream->get_file_path());
//		connection.start_session("127.0.0.1", 12345);
//	}
//}


namespace {
	const sx::uuid_class MULTI_CREATOR_0_ID("1B223D15-549D-11D9-ACA0-000A95BACEB3");
	const sx::uuid_class MULTI_CREATOR_1_ID("203F4B0A-549D-11D9-A577-000A95BACEB3");
	const sx::uuid_class MULTI_IMPORTER_0_ID("24CFB772-549D-11D9-B340-000A95BACEB3");
	const sx::uuid_class MULTI_IMPORTER_1_ID("299F1CFF-549D-11D9-A92C-000A95BACEB3");
}

namespace {
	class creator_0_component : public sxsdk::creator_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return MULTI_CREATOR_0_ID; }
		virtual bool create (sxsdk::scene_interface *scene, void *);
	};
}
bool creator_0_component::create (sxsdk::scene_interface *scene, void *) {
	try {
		scene->message("creator 0");
	} catch (...) { return false; }
	return true;
}

namespace {
	class creator_1_component : public sxsdk::creator_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return MULTI_CREATOR_1_ID; }
		virtual bool create (sxsdk::scene_interface *scene, void *);
	};
}
bool creator_1_component::create (sxsdk::scene_interface *scene, void *) {
	try {
		scene->message("creator 1");
	} catch (...) { return false; }
	return true;
}

namespace {
	class importer_0_component : public sxsdk::importer_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return MULTI_IMPORTER_0_ID; }
		virtual int get_file_type (int i, void *);
		virtual const char *get_file_type_description (int i, void *);
		virtual const char *get_file_extension (int i, void *);
		virtual const char *get_file_extension_description (int i, void *);
		virtual void do_import (sxsdk::scene_interface *scene, sxsdk::stream_interface *stream, sxsdk::text_stream_interface *text_stream, void *);
	};
}
int importer_0_component::get_file_type (int i, void *) {
	return sxsdk::text("TEXT");
}
const char *importer_0_component::get_file_type_description (int i, void *) {
	return "Text file";
}
const char *importer_0_component::get_file_extension (int i, void *) {
	return "txt";
}
const char *importer_0_component::get_file_extension_description (int i, void *) {
	return "Text file";
}
void importer_0_component::do_import (sxsdk::scene_interface *scene, sxsdk::stream_interface *stream, sxsdk::text_stream_interface *text_stream, void *) {
	scene->message("importer 0");
}

namespace {
	class importer_1_component : public sxsdk::importer_interface {
	private:
		virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }
		virtual sx::uuid_class get_uuid (void *) { return MULTI_IMPORTER_1_ID; }
		virtual int get_file_type (int i, void *);
		virtual const char *get_file_type_description (int i, void *);
		virtual const char *get_file_extension (int i, void *);
		virtual const char *get_file_extension_description (int i, void *);
		virtual void do_import (sxsdk::scene_interface *scene, sxsdk::stream_interface *stream, sxsdk::text_stream_interface *text_stream, void *);
	};
}
int importer_1_component::get_file_type (int i, void *) {
	return sxsdk::text("TEXT");
}
const char *importer_1_component::get_file_type_description (int i, void *) {
	return "Text file";
}
const char *importer_1_component::get_file_extension (int i, void *) {
	return "skp";
}
const char *importer_1_component::get_file_extension_description (int i, void *) {
	return "Text file";
}
void importer_1_component::do_import (sxsdk::scene_interface *scene, sxsdk::stream_interface *stream, sxsdk::text_stream_interface *text_stream, void *) {
	scene->message("importer 1");
//	external::do_import(sx::uuid_class("1B47B9-6F2F-4fde-B033-30F7EC1F03F4"), scene, stream, text_stream);
}

SXPLUGINNAMESPACEBEGIN(test_multiplugin)
	SXPLUGINENTRY void __stdcall create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
		unknown_interface *u = 0;
		if (iid == creator_iid) {
			switch (i) {
			case 0:	u = new creator_0_component; break;
			case 1: u = new creator_1_component; break;
			}
		}
		else if (iid == importer_iid) {
			switch (i) {
			case 0: u = new importer_0_component; break;
			case 1: u = new importer_1_component; break;
			}
		}
		if (u) {
			u->AddRef();
			*p = (void *)u;
		}
	};
	SXPLUGINENTRY int __stdcall has_interface (const IID &iid, sxsdk::shade_interface *shade) {
		if (iid == creator_iid) return 2;
		if (iid == importer_iid) return 2;
		return 0;
	}

	SXPLUGINENTRY const char * __stdcall get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
		if (iid == creator_iid) {
			switch (i) {
			case 0:	return "creator 0";
			case 1: return "creator 1";
			}
		}
		else if (iid == importer_iid) {
			switch (i) {
			case 0:	return "importer 0";
			case 1: return "importer 1";
			}
		}
		return 0;
	}

	SXPLUGINENTRY const char * __stdcall get_group_name (const IID &iid, sxsdk::shade_interface *shade, void *) {
		if (iid == creator_iid)			return "multicreator";
		else if (iid == importer_iid)	return "multiimporter";
		return 0;
	}

	SXPLUGINENTRY sx::uuid_class __stdcall get_uuid (const IID &iid, int i, void *) {
		if (iid == creator_iid) {
			switch (i) {
			case 0:	return MULTI_CREATOR_0_ID;
			case 1: return MULTI_CREATOR_1_ID;
			}
		}
		else if (iid == importer_iid) {
			switch (i) {
			case 0:	return MULTI_IMPORTER_0_ID;
			case 1: return MULTI_IMPORTER_1_ID;
			}
		}
		return sx::uuid_class(0u);
	}
	SXPLUGINENTRY bool __stdcall is_resident (const IID &iid, int i, void *) {
		return false;
	}
SXPLUGINNAMESPACEEND
