#pragma once

namespace hh::game
{
	class ObjectMapOperation
	{
	public:
		inline static size_t hash(ObjectId key)
		{
			return key.objectId ^ key.groupId;
		}

		inline static bool compare(ObjectId key, ObjectId other)
		{
			return key == other;
		}
	};
	
	template<typename TValue>
	class ObjectMap : public csl::ut::HashMap<ObjectId, TValue, ObjectMapOperation> {};
}
