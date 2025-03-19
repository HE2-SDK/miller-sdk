#pragma once

namespace hh::fnd {
	class alignas(8) RefByHandleObject : public ReferencedObject {
		using ReferencedObject::ReferencedObject;

        friend class HandleBase;
		uint32_t handle;
	};
}
