#pragma once

namespace csl::ut
{
	class StringMapOperation
	{
	public:
		inline static size_t hash(const char* key)
		{
			if (!key)
				return 0;

			size_t hashResult{};
			size_t i = 0;
			char c = *key;

			if (*key)
			{
				do
				{
					++i;
					hashResult = 31 * hashResult + c;
					c = key[i];
				} while (key[i]);
			}

			return hashResult;
		}

		inline static bool compare(const char* key, const char* other)
		{
			return strcmp(key, other) == 0;
		}
	};
	
	template<typename TValue>
	class StringMap : public HashMap<const char*, TValue, StringMapOperation> {};
}
