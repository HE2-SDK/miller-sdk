#pragma once

namespace hh::physics {
    struct PhysicsQueryResult {
        csl::math::Vector3 hitLocation;
        csl::math::Vector3 unk1;
        uint32_t hitFlags;
        float unk3;
        fnd::Handle<GOCCollider> collider;
        uint32_t unk4;
        uint8_t unk5;
    };

    class PhysicsWorldListener {
    public:
        virtual ~PhysicsWorldListener() = default;
        virtual void ColliderAddedCallback(GOCCollider* collider) {}
        virtual void ColliderRemovedCallback(GOCCollider* collider) {}
        virtual void PWL_UnkFunc3() {}
        virtual void PWL_UnkFunc4() {}
        virtual void PWL_UnkFunc5() {}
        virtual void PWL_UnkFunc6() {}
    };

    // This class is mostly guessed from dtor and previous engine versions because it is obfuscated
    class PhysicsWorld : public game::GameService {
        uint64_t unk100;
        csl::ut::MoveArray<GOCCollider*> colliders;
        csl::ut::MoveArray<void*> unk102;
        csl::ut::MoveArray<void*> unk103;
        csl::ut::MoveArray<PhysicsWorldListener*> listeners;
        csl::ut::MoveArray<void*> unk105;
        csl::ut::MoveArray<void*> unk106;
        csl::ut::MoveArray<void*> unk107;
        csl::ut::MoveArray<void*> unk108;
        csl::ut::MoveArray<void*> unk108b;
        EventQueue* eventQueue;
        uint32_t unk109;
        uint16_t unk110;
        bool unk111;
        uint64_t unk112;
        uint64_t unk113;
    public:
        PhysicsWorld(csl::fnd::IAllocator* allocator);
        virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual bool PerformRayCastClosest(const csl::math::Vector3& from, const csl::math::Vector3& to, uint32_t filterMask, PhysicsQueryResult& result, uint64_t unkParam) = 0;
        virtual bool PerformRayCastAllHits(const csl::math::Vector3& from, const csl::math::Vector3& to, uint32_t filterMask, csl::ut::MoveArray<PhysicsQueryResult>& result, uint64_t unkParam) = 0;
        virtual uint64_t UnkFunc9() = 0;
        virtual uint64_t UnkFunc10() = 0;
        virtual uint64_t UnkFunc11() = 0;
        virtual uint64_t UnkFunc12() = 0;
        virtual uint64_t UnkFunc13() = 0;
        void AddListener(PhysicsWorldListener* listener);
        void RemoveListener(PhysicsWorldListener* listener);
        void AddCollider(GOCCollider* collider);
        void RemoveCollider(GOCCollider* collider);
        bool RayCastClosest(const csl::math::Vector3& from, const csl::math::Vector3& to, uint32_t filterMask, PhysicsQueryResult& result);
        bool RayCastAllHits(const csl::math::Vector3& from, const csl::math::Vector3& to, uint32_t filterMask, csl::ut::MoveArray<PhysicsQueryResult>& result);
        
        inline static const hh::game::GameServiceClass* GetClass();
    };
}
