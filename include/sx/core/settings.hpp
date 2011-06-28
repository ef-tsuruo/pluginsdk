#pragma once
SXCORE
#include "sx/core/setting.hpp"
#include "sx/core/unittest.hpp" // for unittest_enum

namespace sx {
	namespace core {
		namespace settings {
			extern sx::setting<bool> help;
			extern sx::setting<bool> mappedimage;
			extern sx::setting<bool> forcemappedimage;
			extern sx::setting<bool> strippedimage;
			extern sx::setting<bool> log_exr;
			extern sx::setting<bool> log_mmap;
			extern sx::setting<bool> log_mappedimage;
			extern sx::setting<bool> verbose;
			extern sx::setting<bool> break_on_error;
			extern sx::setting<bool> smooth_text;
			extern sx::setting<unsigned> langid;
			extern sx::setting<unittest_enum> unittest;
			extern sx::setting<bool> switchtothread;
			extern sx::setting<bool> check_invariant;
			extern sx::setting<double> idleinterval;
			extern sx::setting<bool> debugbreak;
			extern sx::setting<bool> breakonbadalloc;
			extern sx::setting<bool> breakonbitmaperror;
			extern sx::setting<std::size_t> memorystresstest;
			extern sx::setting<std::string> locale;

			void set (const std::string &option);
		}
	}
	
	namespace core {
		namespace unittest {
			void test_settings ();
		}
	}
}
std::string get_preferredLocalization ();

