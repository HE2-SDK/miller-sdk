#pragma once

namespace app::fnd
{
	template<typename T>
	class ResCommon
	{
	protected:
		T* m_pRes{};

	public:
		ResCommon() : m_pRes(nullptr)
		{
			
		}

		ResCommon(void* pRes) : m_pRes((T*)pRes)
		{
			
		}

		bool IsValid() const
		{
			return m_pRes != nullptr;
		}

		T* operator->() const
		{
			return m_pRes;
		}

		T& operator*() const
		{
			return *m_pRes;
		}

		operator T*() const
		{
			return m_pRes;
		}
		
		const T& ref() const
		{
			return *m_pRes;
		}

		T& ref()
		{
			return *m_pRes;
		}
	};
}