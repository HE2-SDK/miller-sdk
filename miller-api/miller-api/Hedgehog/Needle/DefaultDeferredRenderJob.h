#pragma once

namespace hh::needle {
    class DefaultDeferredRenderJob : public DeferredRenderJob {
    public:
        uint64_t unk201;
        uint64_t unk202;

        DefaultDeferredRenderJob(csl::fnd::IAllocator* allocator, unsigned int viewportId);

        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
        virtual void UnkFunc19() override;
        virtual void UnkFunc20() override;
        virtual void UnkFunc21() override;
        virtual void UnkFunc23() {}
        virtual void UnkFunc24() {}
        virtual void SetupDefaultDeferredRenderingPipeline();
    };
}
