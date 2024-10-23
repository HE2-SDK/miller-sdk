#pragma once

namespace csl::ut
{
	class VariableString
	{
	protected:
		inline static const char* ms_Empty = "";
		
		char* m_pStr{};
		fnd::IAllocator* m_pAllocator{};

		inline bool isFree() const
		{
			return m_pStr == nullptr;
		}

		void assign(fnd::IAllocator* pAllocator, const char* pStr, int size);
		
	public:
		VariableString(const char* pStr, csl::fnd::IAllocator* pAlloc);

		VariableString(const char* pStr, int size, csl::fnd::IAllocator* pAlloc)
		{
			assign(pAlloc, pStr, size);
		}

		VariableString(csl::fnd::IAllocator* pAlloc)
		{
			m_pAllocator = pAlloc;
		}

		VariableString(const VariableString& other);
		VariableString(VariableString&& other);
		
		~VariableString();

		csl::fnd::IAllocator* GetAllocator() const
		{
			return reinterpret_cast<csl::fnd::IAllocator*>(reinterpret_cast<size_t>(m_pAllocator) & ~1ui64);
		}
		VariableString& operator=(VariableString&& other);

		void SetDataUserFree(csl::fnd::IAllocator* allocator, const char* str);
		
		inline void Set(const char* pStr, int size, csl::fnd::IAllocator* pAlloc)
		{
			assign(pAlloc, pStr, size);
		}

		inline void Set(const char* pStr, int size)
		{
			assign(GetAllocator(), pStr, size);
		}

		inline void Set(const char* pStr)
		{
			assign(GetAllocator(), pStr, -1);
		}
		
		const char* c_str() const;
		// {
		// 	if (m_pStr)
		// 		return reinterpret_cast<const char*>(reinterpret_cast<size_t>(m_pStr) & ~1);

		// 	return ms_Empty;
		// }

		//char* c_str()
		//{
		//	if (m_pStr)
		//		return reinterpret_cast<char*>(reinterpret_cast<size_t>(m_pStr) & ~1);

		//	return m_pStr;
		//}

		bool Compare(const char* pStr) const;
		
		operator const char*() const
		{
			return c_str();
		}

		//operator char* ()
		//{
		//	return c_str();
		//}
		
		VariableString& operator=(const VariableString& str)
		{
			return operator=(str.c_str());
		}

		VariableString& operator=(const char* pStr)
		{
			Set(pStr);
			return *this;
		}

		friend bool operator==(const VariableString& lhs, const VariableString& rhs)
		{
			return lhs.Compare(rhs.c_str());
		}

		friend bool operator==(const VariableString& lhs, const char* rhs)
		{
			return lhs.Compare(rhs);
		}
	};
}