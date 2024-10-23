#pragma once

namespace hh::fnd
{
	class RflTypeInfo
	{
	public:
		typedef void* TypeConstructor(void* pInstance, csl::fnd::IAllocator* pAllocator);
		typedef void TypeFinisher(void* pInstance);
		typedef void TypeCleaner(void* pInstance);
		
		const char* m_pName{};
		const char* m_pScopedName{}; // Assuming they're copying havok
		TypeConstructor* m_fpConstruct{};
		TypeFinisher* m_fpFinisher{};
		TypeCleaner* m_fpCleaner{};
		size_t m_Size{};

	public:
        const char* GetName() const
		{
			return m_pName;
		}

		const char* GetScopedName() const
		{
			return m_pScopedName;
		}

		void ConstructObject(void* pInst, csl::fnd::IAllocator* pAllocator) const;
		void FinishLoadedObject(void* pInstance) const;
		void CleanupLoadedObject(void* pInstance) const;

		size_t GetSize() const
		{
			return m_Size;
		}
	};
}