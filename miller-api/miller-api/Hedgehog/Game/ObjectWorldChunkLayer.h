#pragma once

namespace hh::game {
    class ObjectWorldChunkLayer : public fnd::ReferencedObject {
        enum class Flag : uint8_t {
            ENABLED,
        };

        csl::ut::Bitset<Flag> flags;
        ObjectWorldChunk* chunk;
        ResObjectWorld* resource;
    public:
        ObjectWorldChunkLayer(csl::fnd::IAllocator* allocator, ResObjectWorld* resource);
        static inline ObjectWorldChunkLayer* Create(csl::fnd::IAllocator* allocator, ResObjectWorld* resource) {
            return new (allocator) ObjectWorldChunkLayer(allocator, resource);
        }
        void SetObjectWorldChunk(ObjectWorldChunk* chunk);
        const char* GetName() const;
        inline ResObjectWorld* GetResource() {
            return resource;
        }
        void SetEnable(bool enabled);
        bool IsEnable() const;

        // inline void AddObjectData(const hh::game::GameObjectClass& objClass, const char* name, )

        inline void RemoveObjectData(ObjectData* objData) {
            if (chunk)
                chunk->RemoveWorldObjectStatus(objData);
            if (resource) {
                resource->RemoveObject(objData);
                TerminateObjectData(GetAllocator(), objData);
            }
        }
    };
}
