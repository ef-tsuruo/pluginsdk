#pragma once
SXCORE

namespace sx {
	template<typename T> class setting {
	public:
		explicit setting () : overridden(false) { }
		template<typename U> explicit setting (const U &u) : overridden(false), m_persistent_value(u), m_default_value(u) { }
		template<typename U, typename V> explicit setting (const U &u, const V &v) : overridden(false), m_persistent_value(u, v), m_default_value(u, v) { }
		template<typename U, typename V, typename W> explicit setting (const U &u, const V &v, const W &w) : overridden(false), m_persistent_value(u, v, w), m_default_value(u, v, w) { }
		const T &operator() () { // getter
			return overridden ? m_overridden_value : m_persistent_value;
		}
		void operator() (const T &t) { // setter
			m_persistent_value = t;
		}
		const T &persistent_value () const {
			return m_persistent_value;
		}
		const T &default_value () const {
			return m_default_value;
		}
		void override (const T &t) {
			overridden = true;
			m_overridden_value = t;
		}
	private:
		T m_overridden_value;
		T m_persistent_value;
		const T m_default_value;
		bool overridden;
	};
	
	namespace core {
		namespace unittest {
			inline void test_setting () {
			}
		}
	}
}
