#pragma once

namespace hh::fnd
{
	class RflClassEnumMember
	{
	protected:
		const int32_t m_Idx{};
		const char* m_pEnglishName{};
		const char* m_pJapaneseName{};
		const uint64_t m_Flags{};

	public:
		RflClassEnumMember(int32_t idx, const char* englishName, const char* japaneseName, uint64_t flags) : m_Idx{ idx }, m_pEnglishName{ englishName }, m_pJapaneseName{ japaneseName }, m_Flags{ flags } {}
		[[nodiscard]] const char* GetEnglishName() const
		{
			return m_pEnglishName;
		}

		[[nodiscard]] const char* GetJapaneseName() const
		{
			return m_pJapaneseName;
		}

		[[nodiscard]] size_t GetIndex() const
		{
			return m_Idx;
		}

		[[nodiscard]] size_t GetFlags() const
		{
			return m_Flags;
		}
	};
	
	class RflClassEnum
	{
	public:
		const char* m_pName{};
		RflArray<const RflClassEnumMember> m_pValues{ nullptr, 0 };

		RflClassEnum(const char* name, const RflClassEnumMember* values, uint32_t valueCount) : m_pName{ name }, m_pValues{ values, valueCount } {}

        const char* GetName() const
		{
			return m_pName;
		}

		const RflClassEnumMember* GetValues() const
		{
			return m_pValues.items;
		}

		size_t GetValueCount() const
		{
			return m_pValues.count;
		}

		bool GetEnglishNameOfValue(size_t value, const char** pp_name) const
		{
			if (m_pValues.count <= 0)
				return false;

			if (!pp_name)
				return false;
			
			for (size_t i = 0; i < m_pValues.count; i++)
			{
				const RflClassEnumMember* p_member = &m_pValues.items[i];
				
				if (p_member->GetIndex() == value)
				{
					*pp_name = p_member->GetEnglishName();
					return true;
				}
			}
			
			return false;
		}

		bool GetJapaneseNameOfValue(size_t value, const char** pp_name) const
		{
			if (m_pValues.count <= 0)
				return false;

			if (!pp_name)
				return false;

			for (size_t i = 0; i < m_pValues.count; i++)
			{
				const RflClassEnumMember* p_member = &m_pValues.items[i];

				if (p_member->GetIndex() == value)
				{
					*pp_name = p_member->GetJapaneseName();
					return true;
				}
			}

			return false;
		}

		bool GetValueOfEnglishName(const char* name, size_t* p_value) const
		{
			if (m_pValues.count <= 0)
				return false;

			if (!p_value)
				return false;

			for (size_t i = 0; i < m_pValues.count; i++)
			{
				const RflClassEnumMember* p_member = &m_pValues.items[i];

				if (p_member->GetEnglishName() == name || !strcmp(p_member->GetEnglishName(), name))
				{
					*p_value = p_member->GetIndex();
					return true;
				}
			}

			return false;
		}

		bool GetValueOfJapaneseName(const char* name, size_t* p_value) const
		{
			if (m_pValues.count <= 0)
				return false;

			if (!p_value)
				return false;

			for (size_t i = 0; i < m_pValues.count; i++)
			{
				const RflClassEnumMember* p_member = &m_pValues.items[i];

				if (p_member->GetJapaneseName() == name || !strcmp(p_member->GetJapaneseName(), name))
				{
					*p_value = p_member->GetIndex();
					return true;
				}
			}

			return false;
		}
	};
}