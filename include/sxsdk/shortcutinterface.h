#pragma once

namespace sxsdk {
	class shortcut_interface : public shade_interface {
	public:
		/// \en blah \enden \ja キーのインデックス \endja
		enum key_enum {
			/// \en "a" key \enden \ja "a"キー \endja
			key_a,
			/// \en "b" key \enden \ja "b"キー \endja
			key_b,
			/// \en "c" key \enden \ja "c"キー \endja
			key_c,
			/// \en "d" key \enden \ja "d"キー \endja
			key_d,
			/// \en "e" key \enden \ja "e"キー \endja
			key_e,
			/// \en "f" key \enden \ja "f"キー \endja
			key_f,
			/// \en "g" key \enden \ja "g"キー \endja
			key_g,
			/// \en "h" key \enden \ja "h"キー \endja
			key_h,
			/// \en "i" key \enden \ja "i"キー \endja
			key_i,
			/// \en "j" key \enden \ja "j"キー \endja
			key_j,
			/// \en "k" key \enden \ja "k"キー \endja
			key_k,
			/// \en "l" key \enden \ja "l"キー \endja
			key_l,
			/// \en "m" key \enden \ja "m"キー \endja
			key_m,
			/// \en "n" key \enden \ja "n"キー \endja
			key_n,
			/// \en "o" key \enden \ja "o"キー \endja
			key_o,
			/// \en "p" key \enden \ja "p"キー \endja
			key_p,
			/// \en "q" key \enden \ja "q"キー \endja
			key_q,
			/// \en "r" key \enden \ja "r"キー \endja
			key_r,
			/// \en "s" key \enden \ja "s"キー \endja
			key_s,
			/// \en "t" key \enden \ja "t"キー \endja
			key_t,
			/// \en "u" key \enden \ja "u"キー \endja
			key_u,
			/// \en "v" key \enden \ja "v"キー \endja
			key_v,
			/// \en "w" key \enden \ja "w"キー \endja
			key_w,
			/// \en "x" key \enden \ja "x"キー \endja
			key_x,
			/// \en "y" key \enden \ja "y"キー \endja
			key_y,
			/// \en "z" key \enden \ja "z"キー \endja
			key_z,
			/// \en "1" key \enden \ja "1"キー \endja
			key_1,
			/// \en "2" key \enden \ja "2"キー \endja
			key_2,
			/// \en "3" key \enden \ja "3"キー \endja
			key_3,
			/// \en "4" key \enden \ja "4"キー \endja
			key_4,
			/// \en "5" key \enden \ja "5"キー \endja
			key_5,
			/// \en "6" key \enden \ja "6"キー \endja
			key_6,
			/// \en "7" key \enden \ja "7"キー \endja
			key_7,
			/// \en "8" key \enden \ja "8"キー \endja
			key_8,
			/// \en "9" key \enden \ja "9"キー \endja
			key_9,
			/// \en "0" key \enden \ja "0"キー \endja
			key_0,
			/// \en "f1" key \enden \ja "f1"キー \endja
			key_f1,
			/// \en "f2" key \enden \ja "f2"キー \endja
			key_f2,
			/// \en "f3" key \enden \ja "f3"キー \endja
			key_f3,
			/// \en "f4" key \enden \ja "f4"キー \endja
			key_f4,
			/// \en "f5" key \enden \ja "f5"キー \endja
			key_f5,
			/// \en "f6" key \enden \ja "f6"キー \endja
			key_f6,
			/// \en "f7" key \enden \ja "f7"キー \endja
			key_f7,
			/// \en "f8" key \enden \ja "f8"キー \endja
			key_f8,
			/// \en "f9" key \enden \ja "f9"キー \endja
			key_f9,
			/// \en "f10" key \enden \ja "f10"キー \endja
			key_f10,
			/// \en "f11" key \enden \ja "f11"キー \endja
			key_f11,
			/// \en "f12" key \enden \ja "f12"キー \endja
			key_f12,
			/// \en "f13" key \enden \ja "f13"キー \endja
			key_f13,
			/// \en "f14" key \enden \ja "f14"キー \endja
			key_f14,
			/// \en "f15" key \enden \ja "f15"キー \endja
			key_f15,
			/// \en "tab" key \enden \ja "tab"キー \endja
			key_tab
		};
		virtual ~shortcut_interface () { }
	virtual bool execute (int key, int modifiers = 0, void* aux = 0) = 0; // 0
	virtual bool is_assigned (int key, void* aux = 0) = 0; // 1
	virtual const char* get_command_string (int key, void* aux = 0) = 0; // 2
	virtual int get_command_id (int key, void* aux = 0) = 0; // 3
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 4
	};
}
