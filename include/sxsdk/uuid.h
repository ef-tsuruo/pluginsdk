#pragma once
#include "sx/core/uuid.hpp"

namespace sxsdk {
	static sx::uuid_class uuid_from_pluginid (sx::unsigned32 pluginid) {
		sx::uuid_class uuid(0u);
		((sx::unsigned32 *)(&uuid))[0] = pluginid;
		((sx::unsigned32 *)(&uuid))[1] = 0x53B811D9;
		((sx::unsigned32 *)(&uuid))[2] = 0xBCFF000A;
		((sx::unsigned32 *)(&uuid))[3] = 0x95BACEB2;
		return uuid;
	}
	static sx::unsigned32 pluginid (const sx::uuid_class &uuid) {
		return (const sx::unsigned32 &)(uuid);
	}
}
static bool operator== (const sx::uuid_class &uuid, sx::unsigned32 id) {
	if (id == 0) return (uuid == sxsdk::uuid_from_pluginid(0)) || (uuid == sx::uuid_class(0u));
	return (uuid.n() == id);
}
static bool operator!= (const sx::uuid_class &uuid, sx::unsigned32 id) {
	return !(uuid == id);
}
