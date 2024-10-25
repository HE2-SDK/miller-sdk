#pragma once

namespace hh::fnd
{
	class RflClassMember;
	
	class RflClass
	{
	protected:
	public:
		const char* m_pName{};
		const RflClass* m_pParent{};
		uint32_t m_ClassSize{};
		RflArray<const RflClassEnum> m_pEnums{ nullptr, 0 };
		RflArray<const RflClassMember> m_pMembers{ nullptr, 0 };
		const RflCustomAttributes* m_pAttributes{};
		unsigned int nameHash{};

		RflClass() {}

		RflClass(const char* pName, 
			const RflClass* pParent,
			uint32_t objectSizeInBytes,
			const RflClassEnum* pDeclaredEnums,
			uint32_t declaredEnumsNum,
			const RflClassMember* pDeclaredMembers,
			uint32_t declaredMembersNum,
			const RflCustomAttributes* pAttributes) : RflClass{ pName, pParent, objectSizeInBytes, pDeclaredEnums, declaredEnumsNum, pDeclaredMembers, declaredMembersNum, pAttributes, HashString(pName) }
		{}

		RflClass(const char* pName, 
			const RflClass* pParent,
			uint32_t objectSizeInBytes,
			const RflClassEnum* pDeclaredEnums,
			uint32_t declaredEnumsNum,
			const RflClassMember* pDeclaredMembers,
			uint32_t declaredMembersNum,
			const RflCustomAttributes* pAttributes,
			unsigned int nameHash) : m_pName{ pName }, m_pEnums{ pDeclaredEnums, declaredEnumsNum }, m_pMembers{ pDeclaredMembers, declaredMembersNum }, nameHash{ nameHash }
		{
			m_pParent = pParent;
			m_ClassSize = objectSizeInBytes;
			m_pAttributes = pAttributes;
		}

        const char* GetName() const
		{
			return m_pName;
		}

		[[nodiscard]] const RflClass* GetBaseType() const
		{
			return m_pParent;
		}

		[[nodiscard]] uint32_t GetDeclaredSizeInBytes() const
		{
			return m_ClassSize;
		}
		
		[[nodiscard]] uint32_t GetNumMembers() const
		{
			uint32_t count = m_pMembers.count;

			for (const RflClass* base = m_pParent; base != nullptr; base = base->m_pParent)
			{
				count += base->m_pMembers.count;
			}
			
			return count;
		}

		[[nodiscard]] const RflClassMember* GetMember(uint32_t i) const
		{
			const uint32_t num = GetNumMembers();

			if (i > num)
			{
				return nullptr;
			}

			const RflClass* cls = this;
			int j = i - num;

			while(true)
			{
				j += cls->m_pMembers.count;
				if (j >= 0)
					break;

				const RflClass* parent = cls->m_pParent;
				if (!parent)
					return cls->m_pMembers.items;
				cls = parent;
			}
			
			return &cls->m_pMembers.items[j];
		}

		[[nodiscard]] const RflClassMember* GetMemberByName(const char* name) const
		{
			for (uint32_t i = 0; i < GetNumMembers(); i++)
			{
				const RflClassMember* member = GetMember(i);
				if (member->GetName() == name || !strcmp(member->GetName(), name))
				{
					return member;
				}				
			}
			
			return nullptr;
		}

		[[nodiscard]] uint32_t GetDeclaredMemberIndexByName(const char* name) const
		{
			if (m_pMembers.count <= 0)
				return -1;

			for (uint32_t i = 0; i < m_pMembers.count; i++)
			{
				const auto* memberName = m_pMembers.items[i].GetName();
				if (memberName == name || !strcmp(memberName, name))
				{
					return i;
				}
			}
			
			return -1;
		}

		[[nodiscard]] const RflClassMember* GetDeclaredMemberByName(const char* name) const
		{
			const uint32_t i = GetDeclaredMemberIndexByName(name);

			if (i == static_cast<uint32_t>(-1))
				return nullptr;

			return &m_pMembers.items[i];
		}
		
		[[nodiscard]] const RflCustomAttribute* GetAttribute(const char* name) const
		{
			if (!m_pAttributes)
				return nullptr;

			return m_pAttributes->GetAttribute(name);
		}

		size_t GetAlignment() const {
			size_t maxAlignment = 0;

			if (m_pParent) {
				maxAlignment = m_pParent->GetAlignment();
			}
			
			for (uint32_t i = 0; i < m_pMembers.count; i++) {
				size_t memberAlignment = m_pMembers.items[i].GetAlignment();

				if (memberAlignment > maxAlignment) {
					maxAlignment = memberAlignment;
				}
			}

			return maxAlignment;
		}

		size_t GetSizeInBytes() const
		{
			auto size = GetDeclaredSizeInBytes();
			auto alignment = GetAlignment();
			auto misalignment = size % alignment;
			auto alignedSize = misalignment > 0 ? size + alignment - misalignment : size;

			assert(size == alignedSize);

			return alignedSize;
		}
	};
}
