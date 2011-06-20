#pragma once

namespace sxsdk {
	class renderingservice_interface : public shade_interface {
	public:
	virtual std::string get_username (void * = 0) const = 0; // 0
	virtual renderingservice_interface &set_username (const std::string &username_param, void * = 0) = 0; // 1
	virtual std::string get_password (void * = 0) const = 0; // 2
	virtual renderingservice_interface &set_password (const std::string &password_param, void * = 0) = 0; // 3
	virtual bool check_authorization (void* aux = 0) = 0; // 4
	virtual std::string get_freedata (void * = 0) const = 0; // 5
	virtual bool is_available (void * = 0) const = 0; // 6
	virtual std::string get_status_message (void * = 0) const = 0; // 7
	virtual bool add_reservation (const std::string & code, void* aux = 0) = 0; // 8
	virtual bool remove_reservation (const std::string & code, void* aux = 0) = 0; // 9
	};
}
