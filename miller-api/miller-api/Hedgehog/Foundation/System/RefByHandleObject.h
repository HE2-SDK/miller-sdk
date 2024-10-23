#pragma once

namespace hh::fnd {
	class alignas(8) RefByHandleObject : public ReferencedObject
	{;
        friend class HandleBase;
		uint32_t handle;
	};
}
