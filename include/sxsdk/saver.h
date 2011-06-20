#pragma once

namespace sxsdk {
	class polygon_mesh_saver_class : public sx::signature<0x2321B3D8> {
	public:
		virtual ~polygon_mesh_saver_class ();
		virtual void release (void* aux = 0); //30013
		virtual sx::vec<float,3> get_point (int i, void* aux = 0)	const; //30013
		virtual void set_undo (void* aux = 0);
	};

	class sphere_saver_class : public sx::signature<0x7BECCAEF> {
	public:
		virtual ~sphere_saver_class ();
		virtual void release (void* aux = 0); //30013
		virtual sx::vec<float,3> get_center (void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_radius (void* aux = 0)	const; //30013
		virtual mat4 get_matrix (void* aux = 0)	const; //30013
	};

	class disk_saver_class : public sx::signature<0x201E63A1> {
	public:
		virtual ~disk_saver_class ();
		virtual void release (void* aux = 0); //30013
		virtual sx::vec<float,3> get_center (void* aux = 0)	const; //30013
		virtual sx::vec<float,2> get_radius (void* aux = 0)	const; //30013
		virtual mat4 get_matrix (void* aux = 0)	const; //30013
	};

	class line_saver_class : public sx::signature<0xD120E976> {
	public:
		virtual ~line_saver_class ();
		virtual void release (void* aux = 0); //30013
		virtual int get_number_of_control_points (void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_anchor_point (int i, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_inhandle (int i, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_outhandle (int i, void* aux = 0)	const; //30013
		virtual bool get_handle_linked (int i, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_lateral_inhandle (int i, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_lateral_outhandle (int i, void* aux = 0)	const; //30013
		virtual bool get_lateral_handle_linked (int i, void* aux = 0)	const; //30013
	};

	class surface_saver_class : public sx::signature<0x91DDC272> {
	public:
		virtual ~surface_saver_class ();
		virtual void release (void* aux = 0); //30013
		virtual int get_m (void* aux = 0)	const; //30013
		virtual int get_n (void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_anchor_point (int i, int j, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_inhandle (int i, int j, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_outhandle (int i, int j, void* aux = 0)	const; //30013
		virtual bool get_handle_linked (int i, int j, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_lateral_inhandle (int i, int j, void* aux = 0)	const; //30013
		virtual sx::vec<float,3> get_lateral_outhandle (int i, int j, void* aux = 0)	const; //30013
		virtual bool get_lateral_handle_linked (int i, int j, void* aux = 0)	const; //30013
	};
}
