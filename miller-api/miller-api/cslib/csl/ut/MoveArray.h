#pragma once

namespace csl::ut
{
	template<typename T>
	class MoveArray : public Array<T, size_t> {
    public:
		MoveArray() : Array<T, size_t>{}
		{
		}

		MoveArray(fnd::IAllocator* in_pAllocator) : Array<T, size_t>{ in_pAllocator }
		{
		}

		MoveArray(size_t in_capacity, fnd::IAllocator* in_pAllocator) : Array<T, size_t>{ in_capacity, in_pAllocator }
		{
		}

		MoveArray(const MoveArray<T>& other) : Array<T, size_t>{ other }
		{
		}

		MoveArray(MoveArray<T>&& other) : Array<T, size_t>{ std::move(other) }
		{
		}

		MoveArray<T>& operator=(MoveArray<T>&& other) {
			return static_cast<MoveArray<T>&>(Array<T, size_t>::operator=(std::move(other)));
		}
	};
}
