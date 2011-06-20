#pragma once
// implementation
namespace model {
	class surface_class;
}
// end

namespace sxsdk {
	class surface_class {
	public:
		virtual ~surface_class () { }
		VTABLE_PADDING
		#include "surface_class.sdkfunctions"
	// implementation
	public:
		model::surface_class &self;
		
		explicit surface_class (model::surface_class &self) : self(self) { }
		surface_class &operator= (const surface_class &) { return *this; }
		void check_encryption () const;
	private:
		surface_class (const surface_class &);
	// end
	};
}
