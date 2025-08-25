#pragma once

namespace hh::pba{
    class GOCPhysicalAnimation;
    class PbaManager;

    class PbaManagerListener {
    public:
        virtual ~PbaManagerListener() = default;
        virtual void PhysicalAnimationComponentAddedCallback(GOCPhysicalAnimation* component);
        virtual void PhysicalAnimationComponentRemovedCallback(GOCPhysicalAnimation* component);
    };

    class PbaManager : public hh::game::GameService, public hh::game::GameManagerListener, public hh::fnd::ReloaderListener{
    public:
        //probably linked list
        struct Unk1 {
            uint64_t unk1;
            int unk2;
            void* unk3;
            void* unk4;
        };

        Unk1 unk101[32]; // one for each layer
        csl::ut::InplaceMoveArray<PbaManagerListener*, 1> listeners;
        physics::PhysicsWorld* physicsWorld;
        csl::ut::MoveArray<GOCPhysicalAnimation*> components;

        DEFAULT_CREATE_FUNC(PbaManager);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void GameServiceAddedCallback(game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(game::GameService* gameService) override;
        virtual void PostResourceReloadCallback(fnd::ManagedResource* resource) override;

        virtual void UnkFunc9() = 0;
        virtual void UnkFunc10() = 0;
        virtual void AddPhysicsWorld(physics::PhysicsWorld* physicsWorld) {}
        virtual void RemovePhysicsWorld(physics::PhysicsWorld* physicsWorld) {}
        virtual void UnkFunc13() = 0;
        virtual void UnkFunc14() = 0;

        void AddComponent(GOCPhysicalAnimation* component, int layer);
        void RemoveComponent(GOCPhysicalAnimation* component, int layer);
        void AddListener(PbaManagerListener* listener);
        void RemoveListener(PbaManagerListener* listener);
    };

    class PbaManagerBullet : public PbaManager{
    public:
        csl::ut::MoveArray<void*> unk201;
        void* overlapFilterCallbackVftable;

        GAMESERVICE_CLASS_DECLARATION(PbaManagerBullet)
        
        virtual void UnkFunc9() {}
        virtual void UnkFunc10() {}
        virtual void AddPhysicsWorld(physics::PhysicsWorld* physicsWorld) {}
        virtual void RemovePhysicsWorld(physics::PhysicsWorld* physicsWorld) {}
        virtual void UnkFunc13() {}
        virtual void UnkFunc14() {}
    };
}
