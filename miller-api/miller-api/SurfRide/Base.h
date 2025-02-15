#pragma once

namespace SurfRide
{
	class Base
	{
	public:
		csl::fnd::IAllocator* allocator;
		virtual ~Base() = default;
	};
}
