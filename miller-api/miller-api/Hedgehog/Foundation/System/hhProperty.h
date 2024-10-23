#pragma once

namespace hh::fnd
{
	struct alignas(8) PropertyValue
	{
		uint64_t m_Data;

		inline PropertyValue() { m_Data = 0; }
		inline PropertyValue(const float f);
		inline PropertyValue(const int32_t i);
		inline PropertyValue(void* p);
		inline PropertyValue(uint64_t i);

		inline void setFloat(const float f);
		inline void setInt(const int32_t i);
		inline void setPtr(void* p);
		inline void setUint64(uint64_t i);

		inline float getFloat() const;
		inline int32_t getInt() const;
		inline void* getPtr() const;
		inline uint64_t getUint64() const;
	};
	
	class Property
	{
	public:
		uint32_t m_Key{};
		PropertyValue m_Value{};

		Property() {}
		Property(uint32_t key) : m_Key(key) { }
		Property(uint32_t key, PropertyValue value) : m_Key(key), m_Value(value) {}

		uint32_t GetKey() const
		{
			return m_Key;
		}

		PropertyValue GetValue() const
		{
			return m_Value;
		}

		void SetValue(PropertyValue value)
		{
			m_Value = value;
		}

		static uint32_t MapStringToKey(const char* pStr);
	};
}
