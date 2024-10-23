#pragma once

namespace hh::anim {
    class ResAnimation : public fnd::ManagedResource {
    public:
        ResAnimation(csl::fnd::IAllocator* allocator);

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;
        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual ResAnimation* CreateMirrorAnimation(csl::fnd::IAllocator* allocator, ResSkeleton* skeleton, ResAnimation* resolvedAnimation) = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t UnkFunc7() = 0;
        virtual bool UnkFunc8() = 0;
        virtual uint64_t UnkFunc9() = 0;
    };
}
