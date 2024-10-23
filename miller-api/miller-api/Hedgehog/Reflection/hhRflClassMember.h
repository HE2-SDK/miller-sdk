#pragma once

namespace hh::fnd
{
	using namespace csl::ut;
	
	class RflClass;
	class RflClassEnum;
	
	class RflClassMember
	{
	public:
		enum Type : unsigned char
		{
			TYPE_VOID,
			TYPE_BOOL,
			TYPE_SINT8,
			TYPE_UINT8,
			TYPE_SINT16,
			TYPE_UINT16,
			TYPE_SINT32,
			TYPE_UINT32,
			TYPE_SINT64,
			TYPE_UINT64,
			TYPE_FLOAT,
			TYPE_VECTOR2,
			TYPE_VECTOR3,
			TYPE_VECTOR4,
			TYPE_QUATERNION,
			TYPE_MATRIX34,
			TYPE_MATRIX44,
			TYPE_POINTER,
			TYPE_ARRAY,
			TYPE_SIMPLE_ARRAY,
			TYPE_ENUM,
			TYPE_STRUCT,
			TYPE_FLAGS,
			TYPE_CSTRING,
			TYPE_STRING,
			TYPE_OBJECT_ID,
			TYPE_POSITION,
			TYPE_COLOR_BYTE,
			TYPE_COLOR_FLOAT,
		};

		struct Value {
			const char* m_pName{};
			Type m_Type;
			const void* m_Value;

			const char* GetName() const
			{
				return m_pName;
			}
		};

		struct alignas(8) Metadata
		{
			Type m_Type;
			const char* m_pName;
			int16_t m_ByteSize;
			int16_t m_ByteAlignment;
		};

		static const Metadata ms_typeMetadata[];
		
	protected:
	public:
		const char* m_pName{};
		const RflClass* m_pClass{};
		const RflClassEnum* m_pEnum{};
		Type m_Type{};
		Type m_SubType{};
		uint32_t m_ArrayLength{};
		uint32_t m_Flags{};
		uint32_t m_Offset{};
		const RflCustomAttributes* m_pAttributes{};

        const char* GetName() const
		{
			return m_pName;
		}

		[[nodiscard]] const RflClass* GetClass() const
		{
			return m_pClass;
		}
		
		[[nodiscard]] const RflClass* GetStructClass() const
		{
			return m_pClass;
		}

		[[nodiscard]] const RflClassEnum* GetEnumClass() const
		{
			return m_pEnum;
		}

		[[nodiscard]] unsigned int GetCstyleArraySize() const
		{
			return m_ArrayLength;
		}

		[[nodiscard]] const RflCustomAttribute* GetAttribute(const char* name) const
		{
			return m_pAttributes == nullptr ? nullptr : m_pAttributes->GetAttribute(name);
		}

		[[nodiscard]] Type GetType() const
		{
			return m_Type;
		}

		[[nodiscard]] Type GetSubType() const
		{
			return m_SubType;
		}

		[[nodiscard]] size_t GetByteOffset() const
		{
			return m_Offset;
		}
		
		[[nodiscard]] size_t GetSizeInBytes() const;
		[[nodiscard]] size_t GetSingleSizeInBytes() const;
		[[nodiscard]] size_t GetSubTypeSizeInBytes() const;
		[[nodiscard]] size_t GetAlignment() const;
		[[nodiscard]] size_t GetSubTypeAlignment() const;
		[[nodiscard]] size_t GetArraySizeInBytes(size_t count) const;
		[[nodiscard]] size_t GetSubTypeArraySizeInBytes(size_t count) const;

		static const RflClassMember::Metadata& GetTypeMetadata();
	};

#ifndef NO_METADATA
#ifndef __CLR_VER
#define DEFINE_METADATA_FULL(id, type, size, align) Metadata { id, type, (unsigned char)(size), (unsigned char)(align) }
#define DEFINE_METADATA_WITH_NAME(id, name, type) Metadata { id, name, sizeof(type), alignof(type) }
#define DEFINE_METADATA(id, type) Metadata { id, #type, sizeof(type), alignof(type) }
#define DEFINE_DUMMY_METADATA(id, type) Metadata { id, #type, (unsigned char)-1, (unsigned char)-1 }

	inline const RflClassMember::Metadata RflClassMember::ms_typeMetadata[] = {
		DEFINE_DUMMY_METADATA(TYPE_VOID, void),
		DEFINE_METADATA(TYPE_BOOL, bool),
		DEFINE_METADATA(TYPE_SINT8, int8_t),
		DEFINE_METADATA(TYPE_UINT8, uint8_t),
		DEFINE_METADATA(TYPE_SINT16, int16_t),
		DEFINE_METADATA(TYPE_UINT16, uint16_t),
		DEFINE_METADATA(TYPE_SINT32, int32_t),
		DEFINE_METADATA(TYPE_UINT32, uint32_t),
		DEFINE_METADATA(TYPE_SINT64, int64_t),
		DEFINE_METADATA(TYPE_UINT64, uint64_t),
		DEFINE_METADATA(TYPE_FLOAT, float),
		DEFINE_METADATA_WITH_NAME(TYPE_VECTOR2, "vector2", csl::math::Vector2),
		DEFINE_METADATA_WITH_NAME(TYPE_VECTOR3, "vector3", csl::math::Vector3),
		DEFINE_METADATA_WITH_NAME(TYPE_VECTOR4, "vector4", csl::math::Vector4),
		DEFINE_METADATA_WITH_NAME(TYPE_QUATERNION, "quaternion", csl::math::Quaternion),
		DEFINE_METADATA_WITH_NAME(TYPE_MATRIX34, "matrix34", csl::math::Matrix34),
		DEFINE_METADATA_WITH_NAME(TYPE_MATRIX44, "matrix44", csl::math::Matrix44),
		DEFINE_METADATA_WITH_NAME(TYPE_POINTER, "pointer", void*),
		DEFINE_METADATA_FULL(TYPE_ARRAY, "array", sizeof(csl::ut::MoveArray<void*>), -1),
		DEFINE_METADATA_FULL(TYPE_SIMPLE_ARRAY, "simplearray", 16, -1),
		DEFINE_METADATA_FULL(TYPE_ENUM, "enum", -1, -1),
		DEFINE_METADATA_FULL(TYPE_STRUCT, "struct", -1, -1),
		DEFINE_METADATA_FULL(TYPE_FLAGS, "flags", -1, -1),
		DEFINE_METADATA_WITH_NAME(TYPE_CSTRING, "cstring", char*),
		DEFINE_METADATA_WITH_NAME(TYPE_STRING, "string", csl::ut::VariableString),
		DEFINE_METADATA_WITH_NAME(TYPE_OBJECT_ID, "csetobjectid", hh::game::ObjectId),
		DEFINE_METADATA_FULL(TYPE_POSITION, "position", 0xC, 4),
		DEFINE_METADATA_WITH_NAME(TYPE_COLOR_BYTE, "color8", csl::ut::Color8),
		DEFINE_METADATA_WITH_NAME(TYPE_COLOR_FLOAT, "colorf", csl::ut::Colorf),
	};

#undef DEFINE_METADATA_WITH_NAME
#undef DEFINE_DUMMY_METADATA
#undef DEFINE_METADATA_FULL
#undef DEFINE_METADATA
#endif
#endif
}

#include "hhRflClass.h"

inline size_t hh::fnd::RflClassMember::GetSubTypeSizeInBytes() const
{
	switch (m_SubType) {
	case TYPE_VOID:
		return 0;
	case TYPE_STRUCT:
		return GetStructClass()->GetSizeInBytes();
	default:
		return ms_typeMetadata[m_SubType].m_ByteSize;
	}
}

inline size_t hh::fnd::RflClassMember::GetSingleSizeInBytes() const
{
	switch (m_Type)
	{
	case TYPE_VOID:
		return 0;
	case TYPE_STRUCT:
		return GetStructClass()->GetSizeInBytes();
	case TYPE_ENUM:
	case TYPE_FLAGS:
		return GetSubTypeSizeInBytes();
		
	default:
		return ms_typeMetadata[m_Type].m_ByteSize;
	}
}

inline size_t hh::fnd::RflClassMember::GetSizeInBytes() const
{
	return m_ArrayLength ? m_ArrayLength * GetSingleSizeInBytes() : GetSingleSizeInBytes();
}

inline size_t hh::fnd::RflClassMember::GetSubTypeAlignment() const
{
	switch(m_SubType) {
	case TYPE_VOID:
		return 0;

	case TYPE_STRUCT:
		return GetStructClass()->GetAlignment();

	default:
		return ms_typeMetadata[m_SubType].m_ByteAlignment ? ms_typeMetadata[m_SubType].m_ByteAlignment : -1;
	}
}

inline size_t hh::fnd::RflClassMember::GetAlignment() const
{
	switch(m_Type) {
	case TYPE_VOID:
		return 0;

	case TYPE_STRUCT:
		return GetStructClass()->GetAlignment();
	
	case TYPE_ARRAY:
		return alignof(csl::ut::MoveArray<void*>);
	
	case TYPE_SIMPLE_ARRAY:
		return alignof(size_t);

	case TYPE_ENUM:
	case TYPE_FLAGS:
		return GetSubTypeAlignment();
		
	default:
		return ms_typeMetadata[m_Type].m_ByteAlignment ? ms_typeMetadata[m_Type].m_ByteAlignment : -1;
	}
}

inline size_t hh::fnd::RflClassMember::GetArraySizeInBytes(size_t count) const {
	return GetSizeInBytes() * count;
}

inline size_t hh::fnd::RflClassMember::GetSubTypeArraySizeInBytes(size_t count) const {
	return GetSubTypeSizeInBytes() * count;
}
