#pragma once

namespace csl::ut
{
	template<typename TKey>
	class PointerMapOperation
	{
	public:
		/*
		 * This uses MurmurHash3's avalanche mix finalizer for x64.
		 * I couldn't find any evidence for an actual hash function being used.
		 * Maybe they decided that pointers are random enough to be acceptably
		 * distributed after only applying an avalanche mixer.
		 */
		inline static size_t hash(TKey key)
		{
			size_t k = (size_t)key;

			k ^= k >> 33;
			k *= 0xff51afd7ed558ccd;
			k ^= k >> 33;
			k *= 0xc4ceb9fe1a85ec53;
			k ^= k >> 33;

			return k;
		}

		inline static bool compare(const TKey& key, const TKey& other)
		{
			return key == other;
		}
	};

	template<typename TKey, typename TValue>
	class PointerMap : public HashMap<TKey, TValue, PointerMapOperation<TKey>> {};
}
