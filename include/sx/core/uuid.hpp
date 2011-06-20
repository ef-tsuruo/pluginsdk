#pragma once
SXCORE
#include "sx/core/endian.hpp"

#include <iosfwd>
#include <string>
#include <sstream>

namespace sx {
	/// \brief \en uuid_class \enden \ja UUIDを扱うクラス \endja
	///
	/// \en \enden \ja UUIDの定義や、int型のプラグインIDをUUIDに変換することができる。詳細は \ref uuid を参照。 \endja
	class uuid_class {
	public:
		uuid_class () : a(0), b(0), c(0), d(0) { }
		/// \en blah \enden \ja ハイフン区切りでのUUIDを使用する場合に使う。\endja
		explicit uuid_class (const char *s) {
			set(s);
		}
		explicit uuid_class (sx::unsigned32 a) : a(a), b(0), c(0), d(0) { }
		explicit uuid_class (sx::unsigned32 a, sx::unsigned32 b, sx::unsigned32 c, sx::unsigned32 d) : a(a), b(b), c(c), d(d) { }
		#if SXMACOSX || SXIOS
			explicit uuid_class (const CFUUIDRef uuid) { set(uuid); }
		#endif
		#if SXWINDOWS
			explicit uuid_class (const UUID &uuid) { set(uuid); }
		#endif
		bool operator< (const uuid_class &b) const {
			const uuid_class &a = *this;
			if (a.a < b.a)		return true;
			else if (b.a < a.a)	return false;
			if (a.b < b.b)		return true;
			else if (b.b < a.b)	return false;
			if (a.c < b.c)		return true;
			else if (b.c < a.c)	return false;
			if (a.d < b.d)		return true;
			else if (b.d < a.d)	return false;
			return false;
		}
		/// \brief \en blah \enden \ja uuidが同じかどうか判別する。 \endja
		bool operator== (const uuid_class &t) const {
			return (a == t.a) && (b == t.b) && (c == t.c) && (d == t.d);
		}
		bool operator!= (const uuid_class &t) const {
			return !((*this) == t);
		}
		/// \brief \en blah \enden \ja UUIDの先頭の32bitを返す。\endja
		sx::unsigned32 n () const {
			if ((b == 0) && (c == 0) && (d == 0))	return a;
			return 0xffffffff;
		}
		bool is_enum () const {
			return ((b == 0) && (c == 0) && (d == 0));
		}
		/// \en blah \enden \ja ハイフン区切りのUUIDをstringで返す。\endja
		std::string string () const;
		void revert_endian () {
			sx::revert_endian(a);
			sx::revert_endian(b);
			sx::revert_endian(c);
			sx::revert_endian(d);
		}
	private:
		sx::unsigned32 a;
		sx::unsigned32 b;
		sx::unsigned32 c;
		sx::unsigned32 d;

		#if SXMACOSX || SXIOS
			void set (const CFUUIDRef uuid);
		#endif
		#if SXWINDOWS
			void set (const UUID &uuid);
		#endif
		void set (const char *s) {
			SXASSERT(s);
			a = get8(s);
			s += 9;
			b = (get4(s)<<16) + get4(s+5);
			s += 10;
			c = (get4(s)<<16) + get4(s+5);
			s += 9;
			d = get8(s);
		}
		void set (sx::unsigned32 a, sx::unsigned32 b, sx::unsigned32 c, sx::unsigned32 d) {
			this->a = a; this->b = b; this->c = c; this->d = d;
		}
		sx::unsigned32 get8 (const char *s) {
			return (get1(s[0])<<28) + (get1(s[1])<<24) + (get1(s[2])<<20) + (get1(s[3])<<16) + (get1(s[4])<<12) + (get1(s[5])<<8) + (get1(s[6])<<4) + (get1(s[7])<<0);
		}
		sx::unsigned32 get4 (const char *s) {
			return (get1(s[0])<<12) + (get1(s[1])<<8) + (get1(s[2])<<4) + (get1(s[3])<<0);
		}
		sx::unsigned32 get1 (char s) {
			switch (s) {
			case '0':			return 0x00;
			case '1':			return 0x01;
			case '2':			return 0x02;
			case '3':			return 0x03;
			case '4':			return 0x04;
			case '5':			return 0x05;
			case '6':			return 0x06;
			case '7':			return 0x07;
			case '8':			return 0x08;
			case '9':			return 0x09;
			case 'A': case 'a':	return 0x0A;
			case 'B': case 'b':	return 0x0B;
			case 'C': case 'c':	return 0x0C;
			case 'D': case 'd':	return 0x0D;
			case 'E': case 'e':	return 0x0E;
			case 'F': case 'f':	return 0x0F;
			}
			return 0;
		}
	};
	/// \brief \en blah \enden \ja 新規のUUIDを生成する。 \endja
	uuid_class create_uuid ();

	inline static sx::uuid_class &revert_endian (sx::uuid_class &uuid) {
		uuid.revert_endian();
		return uuid;
	}

}


namespace sx {
	namespace core {
		namespace unittest {
			void test_uuid ();
		}
	}
}
