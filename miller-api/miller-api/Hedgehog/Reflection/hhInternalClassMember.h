#pragma once

namespace hh::fnd
{
	class RflClass;
	class RflClassEnum;
	class RflCustomAttributes;
	
	struct RflClassMemberInternal
	{
		const char* m_pName{};
		RflClass* m_pClass{};
		RflClassEnum* m_pEnum{};
		unsigned char m_Type{};
		unsigned char m_SubType{};
		unsigned short m_ArrayLength{};
		unsigned short m_Flags{};
		unsigned short m_Offset{};
		const RflCustomAttributes* m_pAttributes{};
	};
}
