#pragma once

namespace hh::anim {
    class ResAnimationPxd : public ResAnimation {
    public:
        uint64_t qword78;
        uint64_t qword80;
        uint64_t qword88;
        uint64_t qword90;
        uint64_t qword98;
        uint64_t qwordA0;
        uint64_t qwordA8;
        uint64_t qwordB0;
        uint64_t qwordB8;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimationPxd)

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual ResAnimationPxd* CreateMirrorAnimation(csl::fnd::IAllocator* allocator, ResSkeleton* skeleton, ResAnimation* resolvedAnimation) override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc7() override;
        virtual bool UnkFunc8() override;
        virtual uint64_t UnkFunc9() override;
    };
}
