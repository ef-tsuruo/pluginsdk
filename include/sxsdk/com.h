#pragma once
#include "sx/core/com.hpp"

#if __GNUG__
	#define VTABLE_PADDING virtual void gcc_dummy0 () { }
#else
	#define VTABLE_PADDING
#endif

class unknown_interface : public IUnknown {
public:
	enum property_type_enum {
		void_type, bool_type, selection_type, int_type, float_type, vec3_type, rgb_type, string_type, double_type, group_begin_type, group_end_type, short_string_type, text_type, rgba_type, window_type,
		tab_group_begin_type, tab_group_end_type,
		vec2_type, vec4_type, quaternion_type, mat4_type,
		hbox_begin_type, vbox_begin_type, box_end_type, custom_type, progress_type, listbox_type, push_button_type,
		secure_string_type, secure_short_string_type,
		path_type, radio_button_type
	};
	explicit unknown_interface ();
	virtual ~unknown_interface ();
	virtual HRESULT STDMETHODCALLTYPE QueryInterface (REFIID, LPVOID *) { return E_NOINTERFACE; }
	virtual ULONG STDMETHODCALLTYPE AddRef ();
	virtual ULONG STDMETHODCALLTYPE Release ();
	virtual bool is_implemented () { return true; }
	int get_refcount () const { return ref; }
	int get_shade_build_number () const;
	volatile static unsigned interface_total_count;
	void check_invariant () const { }
protected:
	volatile unsigned ref;
};

/// \brief \en A smart pointer for reference counted *_interface classes. \enden \ja *_interfaceクラスのオブジェクトを指す参照カウントスマートポインタ。 \endja 
template<class T> class compointer {
public:
	explicit compointer () : ptr(0) { }
	/// \en blah \enden \ja compointerコンストラクタ。 \endja
	explicit compointer (T *p, int n = 0) : ptr(p) {
		if (ptr) while (n--) ptr->AddRef();
	}
	/// \en blah \enden \ja compointerコンストラクタ。 \endja
	compointer (const compointer<T> &p) : ptr(p.ptr) {
		if (ptr) ptr->AddRef();
	}
	~compointer () {
		if (ptr) ptr->Release();
	}
	/// \en blah \enden \ja compointerが管理しているオブジェクトのポインタを返す。 \endja
	T *get () const {
		return ptr;
	}
	/// \en blah \enden \ja compointerが管理しているオブジェクトの参照を取得する。 \endja
	T &operator* () const {
		return *ptr;
	}
	/// \en blah \enden \ja compointerが管理しているオブジェクトのメンバを呼び出す。 \endja
	T *operator-> () const {
		return ptr;
	}
	/// \en blah \enden \ja キャストによりcompointerが管理しているオブジェクトのポインタを取得する。 \endja
	operator T * () const {
		return ptr;
	}
	/// \en blah \enden \ja compointerが管理するオブジェクトをpに変更する。それまで管理していたオブジェクトには \c Release() が呼ばれる。 \endja
	compointer<T> &operator= (T *p) {
		if (ptr != p && ptr != 0) ptr->Release();
		ptr = p;
		return *this;
	}
	/// \en blah \enden \ja compointerが管理するオブジェクトをpに変更する。それまで管理していたオブジェクトには \c Release() が呼ばれる。 \endja
	compointer<T> &operator= (const compointer<T> &p) {
		if (ptr != p.get() && ptr != 0) ptr->Release();
		ptr = p.get();
		if (ptr != 0) ptr->AddRef();
		return *this;
	}
	/// \en blah \enden \ja compointerが管理するオブジェクトのAddRef()を呼び出して参照カウントを増やす。 \endja
	T *retain () {
		ptr->AddRef();
		return ptr;
	}
	/// \en blah \enden \ja オブジェクトの管理を破棄する。このとき、Release() は呼び出されないので、オブジェクトの破棄を別途行う必要がある。 \endja
	T *release () { // note that release() is NOT the reverse operation of retatin().
		T *p = ptr; ptr = 0; return p;
	}
	void check_invariant () const { }
private:
	T *ptr;
};
