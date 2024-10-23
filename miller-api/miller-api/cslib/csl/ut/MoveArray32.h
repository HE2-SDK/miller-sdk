#pragma once

namespace csl::ut
{
	template<typename T>
	class MoveArray32 : public Array<T, uint32_t> {
    public:
		MoveArray32() : Array<T, uint32_t>{}
		{
		}

		MoveArray32(fnd::IAllocator* in_pAllocator) : Array<T, uint32_t>{ in_pAllocator }
		{
		}

		MoveArray32(uint32_t in_capacity, fnd::IAllocator* in_pAllocator) : Array<T, uint32_t>{ in_capacity, in_pAllocator }
		{
		}

		MoveArray32(const MoveArray32<T>& other) : Array<T, uint32_t>{ other }
		{
		}

		MoveArray32(MoveArray32<T>&& other) : Array<T, uint32_t>{ std::move(other) }
		{
		}
	};
}
