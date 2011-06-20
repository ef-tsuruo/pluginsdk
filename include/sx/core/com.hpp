#pragma once

#if SXWINDOWS
	#include <windows.h>
#else
	#if SXMACOSX
		#include <CoreFoundation/CFPluginCOM.h>
	#else
		typedef unsigned long ULONG;
		#define STDMETHODCALLTYPE
		typedef int HRESULT;
		const HRESULT S_OK = 1;
		const HRESULT E_NOINTERFACE = 0;
		class IUnknown {
		public:
			virtual ~IUnknown () { }
			virtual ULONG AddRef () = 0;
			virtual ULONG Release () = 0;
		};
	#endif

	class GUID {
	public:
		unsigned long  data1;
		unsigned short data2;
		unsigned short data3;
		unsigned short data4[8];
		bool operator== (const GUID &g) const {
			return data1 == g.data1
				&& data2 == g.data2
				&& data3 == g.data3
				&& data4[0] == g.data4[0]
				&& data4[1] == g.data4[1]
				&& data4[2] == g.data4[2]
				&& data4[3] == g.data4[3]
				&& data4[4] == g.data4[4]
				&& data4[5] == g.data4[5]
				&& data4[6] == g.data4[6]
				&& data4[7] == g.data4[7];
		}
		bool operator!= (const GUID &g) const {
			return !operator==(g);
		}
	};

	typedef GUID IID;
	typedef GUID CLSID;

	const IID IID_IUnknown = { 0x32bb8320, 0xb41b, 0x11cf, { 0xa6, 0xbb, 0x00, 0x80, 0xc7, 0xb2, 0xd6, 0x82 } };
	#if !SXMACOSX
		typedef GUID &REFIID;
		typedef void *LPVOID;
	#endif
	
#endif
