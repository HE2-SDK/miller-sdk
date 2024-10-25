#pragma once

namespace hh::game {
    enum class GameStepPhase : uint8_t {
        PRE_SIM,
        POST_SIM,
    };

    class BucketedGameUpdater : public GameUpdater, public GameObjectListener {
    public:
        struct SetupInfo : public GameUpdater::SetupInfo {
            struct BucketSpecification {
                GameStepPhase gameStepPhase;
                uint32_t layerMask;
                char name[0x18];
            };

            csl::ut::MoveArray<BucketSpecification> buckets;

            void AddBucket(GameStepPhase gameStepPhase, uint32_t layerMask, const char* name);
        };

        struct Bucket {
            csl::ut::VariableString name;
            uint32_t layerMask;
            csl::ut::MoveArray<void*> unk;
        };

        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
        };

        csl::ut::MoveArray<Bucket> buckets;
        csl::ut::MoveArray<csl::ut::MoveArray<hh::game::GameObject*>> unk1;
        csl::ut::MoveArray<Unk1> unk2;
        signed char updatingBucketIdByLayer[32]; // -1 = none
        uint32_t preSimBucketCount;
        uint32_t postSimBucketCount;

        CREATE_FUNC(BucketedGameUpdater, const SetupInfo& setupInfo);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* DoStep(const GameStepInfo& stepInfo) override;
		virtual void ObjectAddedToLayerCallback(GameObject* gameObject, int layer) override;
		virtual void ObjectRemovedFromLayerCallback(GameObject* gameObject, int layer) override;
    };
}
