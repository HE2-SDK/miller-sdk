#pragma once

namespace hh::ut {
	template<typename T>
	class TempMoveArray : public csl::ut::MoveArray<T>
	{
	public:
		inline TempMoveArray() : csl::ut::MoveArray<T>{ fnd::MemoryRouter::GetTempAllocator() } {}
	};
}
