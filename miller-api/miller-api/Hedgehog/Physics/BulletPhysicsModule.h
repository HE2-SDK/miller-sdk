#pragma once

namespace hh::physics {
    class BulletPhysicsModule : public fw::AppModule {
    public:
        uint64_t unk1;
        uint64_t unk2;
        csl::fnd::TlsfHeapTemplate<csl::fnd::Mutex> heap;

        static BulletPhysicsModule* instance;
        static BulletPhysicsModule* Create(csl::fnd::IAllocator*);
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
    };
}
