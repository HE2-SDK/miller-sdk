#pragma once

namespace hh::physics {
    class PickedObjectInfo {
    public:
        game::GOComponent* collider;
        csl::math::Vector3 unk2;
        csl::math::Vector3 unk3;
        uint32_t unk4;
        int unk5;
        bool unk6;
        
        PickedObjectInfo();
    };

    class PhysicsViewerContextListener {
    public:
        virtual ~PhysicsViewerContextListener() = default;
        virtual void PhysicsWorldAdded(PhysicsWorld* physicsWorld) {}
        virtual void PhysicsWorldRemoved(PhysicsWorld* physicsWorld) {}
        virtual void PVCL_UnkFunc3() {}
    };

    class PhysicsViewerContext
        : public game::ServiceViewerContextBase
        , public PhysicsWorldListener
    {
    public:
        csl::ut::MoveArray<PhysicsViewerContextListener*> listeners{ GetAllocator() };
        csl::ut::MoveArray<PhysicsWorld*> worlds{ GetAllocator() };
        PickedObjectInfo pickedObject;
        void* unk209; // object specific to this viewer that's created in the constructor
        csl::ut::VariableString unk210[32];
        uint64_t unk211;
    
        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual void ColliderRemovedCallback(GOCCollider* collider) override;

        void AddListener(PhysicsViewerContextListener* listener);
        void RemoveListener(PhysicsViewerContextListener* listener);

        VIEWER_CONTEXT_CLASS_DECLARATION(PhysicsViewerContext)
    };
}
