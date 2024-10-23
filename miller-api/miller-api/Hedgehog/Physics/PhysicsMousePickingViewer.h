#pragma once

namespace hh::physics {
    class PhysicsMousePickingViewer
        : public PhysicsViewerBase
        , public PhysicsWorldListener
        , public fw::MouseEventHandler
        , public fw::ApplicationListener
    {
    public:
        class PhysicsMouseSpringAction {
        public:
            csl::math::Vector3 unk1;
            float unk2;
            float unk3;
            void* obj;

            PhysicsMouseSpringAction();
        };

        game::GameApplication* gameApplication;
        PhysicsMouseSpringAction mouseSpringAction;
        bool mouseDown;
        csl::ut::InplaceMoveArray<PhysicsViewerBase*, 2> physicsViewers;

        static float rayLength;
        static unsigned int selectionMask;

        virtual int OnLifeCycleChange(bool created) override;
        virtual void PhysicsWorldAdded(PhysicsWorld* physicsWorld) override;
        virtual void PhysicsWorldRemoved(PhysicsWorld* physicsWorld) override;
        virtual void ColliderRemovedCallback(GOCCollider* collider) override;
        virtual bool MEH_Unk1() override;
        virtual bool MEH_Unk2() override;
        virtual bool MEH_Unk3() override;

        VIEWER_CLASS_DECLARATION(PhysicsMousePickingViewer)
    };
}
