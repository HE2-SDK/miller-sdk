#pragma once

namespace app::physics {
    class GOCMoveSphereColliderQuery;
}

namespace app::player {
    class StatePluginCollision : public PlayerStatePlugin {
    public:
        // struct BodyAttackParam {
            // unsigned char type;
            // csl::math::Vector3 position;
            // float radius;
            // char unk0;
        // };

        // struct DamageCollider {
            // hh::fnd::Handle<hh::physics::GOCCollider> collider;
            // char unk0;
            // char unk0b;
            // char unk0c;
            // int unk1;
            // float unk2;
            // int flags;
            // int unk4;
        // };

        static constexpr const char* name = "StatePluginCollision";
        
        // csl::ut::MoveArray<DamageCollider> damageColliders;
        // app::ut::PriorityList<BodyAttackParam, unsigned int> bodyAttackParams;
        // physics::GOCMoveSphereColliderQuery* colliderQuery;
        // unsigned char currentType;

        uint64_t qword28;
        uint64_t qword30;
        uint64_t qword38;
        csl::fnd::IAllocator* allocator;
        app::physics::GOCMoveSphereColliderQuery* gocColliderQuery;
        char type;

        StatePluginCollision(csl::fnd::IAllocator* allocator);

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        void SetTypeAndRadius(unsigned char type, float radius);
    };
}
