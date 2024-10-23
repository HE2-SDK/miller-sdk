#pragma once

namespace csl::ut
{
	template <typename T, const size_t Bsz>
	class InplaceMoveArray32 : public MoveArray32<T>
	{
	protected:
		T reserved[Bsz]{};

	public:
		constexpr InplaceMoveArray32(fnd::IAllocator* allocator_) : MoveArray32<T>(allocator_)
		{
			this->m_capacity = Bsz;
			this->m_capacity |= SIGN_BIT;
			this->m_pBuffer = (T*)reserved;
		}
	};

	// template <typename T, const size_t Bsz>
	// class alignas(16) InplaceMoveArrayAligned16 : public MoveArray<T>
	// {
	// protected:
	// 	char alignas(16) reserved[sizeof(T) * Bsz]{};

	// public:
	// 	constexpr InplaceMoveArrayAligned16(fnd::IAllocator* allocator_) : MoveArray<T>(allocator_)
	// 	{
	// 		this->m_capacity = Bsz;
	// 		this->m_capacity |= SIGN_BIT;
	// 		this->p_buffer = (T*)reserved;
	// 	}
	// };
}
