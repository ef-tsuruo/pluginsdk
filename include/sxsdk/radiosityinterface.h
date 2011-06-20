#pragma once

namespace sxsdk {
	class radiosity_interface : public shade_interface {
	public:
	virtual void start (void* aux = 0) = 0; // 0
	virtual void stop (void* aux = 0) = 0; // 1
	virtual void resume (void* aux = 0) = 0; // 2
	virtual void clear (void* aux = 0) = 0; // 3
	virtual bool get_solving (void * = 0) const = 0; // 4
	virtual radiosity_interface &set_solution_convergence (float solution_convergence_param, void * = 0) = 0; // 5
	virtual float get_solution_convergence (void * = 0) const = 0; // 6
	virtual radiosity_interface &set_solution_diffuse (float solution_diffuse_param, void * = 0) = 0; // 7
	virtual float get_solution_diffuse (void * = 0) const = 0; // 8
	virtual radiosity_interface &set_solution_initial_mesh_spacing (float solution_initial_mesh_spacing_param, void * = 0) = 0; // 9
	virtual float get_solution_initial_mesh_spacing (void * = 0) const = 0; // 10
	virtual radiosity_interface &set_solution_minimum_mesh_spacing (float solution_minimum_mesh_spacing_param, void * = 0) = 0; // 11
	virtual float get_solution_minimum_mesh_spacing (void * = 0) const = 0; // 12
	virtual radiosity_interface &set_solution_direct_radiation_mesh_subdivision_sensitivity (float solution_direct_radiation_mesh_subdivision_sensitivity_param, void * = 0) = 0; // 13
	virtual float get_solution_direct_radiation_mesh_subdivision_sensitivity (void * = 0) const = 0; // 14
	virtual radiosity_interface &set_solution_indirect_radiation_mesh_subdivision_sensitivity (float solution_indirect_radiation_mesh_subdivision_sensitivity_param, void * = 0) = 0; // 15
	virtual float get_solution_indirect_radiation_mesh_subdivision_sensitivity (void * = 0) const = 0; // 16
	virtual radiosity_interface &set_solution_source_subdivision_sensitivity (int solution_source_subdivision_sensitivity_param, void * = 0) = 0; // 17
	virtual int get_solution_source_subdivision_sensitivity (void * = 0) const = 0; // 18
	virtual radiosity_interface &set_solution_sky_light_accuracy (int solution_sky_light_accuracy_param, void * = 0) = 0; // 19
	virtual int get_solution_sky_light_accuracy (void * = 0) const = 0; // 20
	virtual radiosity_interface &set_display_mesh (bool display_mesh_param, void * = 0) = 0; // 21
	virtual bool get_display_mesh (void * = 0) const = 0; // 22
	virtual radiosity_interface &set_display_solid (bool display_solid_param, void * = 0) = 0; // 23
	virtual bool get_display_solid (void * = 0) const = 0; // 24
	virtual radiosity_interface &set_display_cull_face (bool display_cull_face_param, void * = 0) = 0; // 25
	virtual bool get_display_cull_face (void * = 0) const = 0; // 26
	virtual radiosity_interface &set_display_blend (bool display_blend_param, void * = 0) = 0; // 27
	virtual bool get_display_blend (void * = 0) const = 0; // 28
	virtual radiosity_interface &set_display_radiator (bool display_radiator_param, void * = 0) = 0; // 29
	virtual bool get_display_radiator (void * = 0) const = 0; // 30
	virtual radiosity_interface &set_display_updates (int display_updates_param, void * = 0) = 0; // 31
	virtual int get_display_updates (void * = 0) const = 0; // 32
	virtual void abort (void* aux = 0) = 0; // 33
	virtual void solve (void* aux = 0) = 0; // 34
	virtual int radiosity_interface_test_1 ( void* aux =0 ) { return 1; } // 35
	virtual radiosity_interface &set_auto_exposure (bool auto_exposure_param, void * = 0) = 0; // 36
	virtual bool get_auto_exposure (void * = 0) const = 0; // 37
	virtual radiosity_interface &set_exposure (float exposure_param, void * = 0) = 0; // 38
	virtual float get_exposure (void * = 0) const = 0; // 39
	virtual void stream_to_clipboard (void* aux = 0) = 0; // 40
	};
}
