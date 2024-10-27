#pragma once

namespace app::game {
    class IslandWorldChunkAabbTreeHandle : public hh::fnd::ReferencedObject, hh::ut::AabbTreeHandle {
    public:
        class RangeInAabbTreeHandle : public hh::fnd::ReferencedObject, hh::ut::AabbTreeHandle {
        public:
            uint64_t unk1;
            hh::fnd::Handle<hh::game::GameObject> gameObject;
            csl::math::Vector3 position;
            float range;
        };

        hh::game::ObjectWorldChunk* objectWorldChunk;
        hh::fnd::Reference<hh::ut::AabbTree> aabbTree;
        csl::ut::MoveArray<hh::fnd::Reference<RangeInAabbTreeHandle>> rangeInAabbTreeHandles;
        csl::ut::PointerMap<hh::game::ObjectData*, RangeInAabbTreeHandle*> rangeInAabbTreeHandlesByObjectData;
        csl::ut::MoveArray<hh::game::ObjectId> unk6;
        csl::ut::MoveArray<void*> unk7;


    };

    class IslandRangeSpawningManager
        : public hh::game::ObjectWorldExtension
        , public hh::game::ObjectWorldListener
        , public hh::game::ObjectWorldChunkListener
        , public hh::game::GameStepListener
    {
    public:
        hh::fnd::Reference<hh::ut::AabbTree> aabbTree;
        csl::ut::MoveArray<hh::fnd::Reference<IslandWorldChunkAabbTreeHandle>> worldChunkAabbTreeHandles;
        uint8_t unk3;

        IslandRangeSpawningManager(csl::fnd::IAllocator* allocator);
        virtual ~IslandRangeSpawningManager();
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Initialize() override;
        virtual void Deinitialize() override;
        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual void UnkFunc6() override;
        virtual void WorldChunkAddedCallback(hh::game::ObjectWorldChunk* chunk) override;
        virtual void WorldChunkRemovedCallback(hh::game::ObjectWorldChunk* chunk) override;
        virtual void ObjectDataAddedCallback(const hh::game::ObjectWorldChunk* chunk, const hh::game::ObjectData* objectData) override;
        virtual void ObjectDataRemovedCallback(const hh::game::ObjectWorldChunk* chunk, const hh::game::ObjectData* objectData) override;
        virtual void ObjectDataChangedCallback(const hh::game::ObjectWorldChunk* chunk, const hh::game::ObjectData* objectData) override;
        virtual void FinishEditorCallback() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
    };
}
