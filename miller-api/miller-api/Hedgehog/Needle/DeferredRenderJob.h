#pragma once

namespace hh::needle {
    class DeferredRenderJob : public RenderJob {
    public:
        uint32_t dword48;
        RenderingPipeline* deferredRenderingPipeline;
        uint64_t qword58;
        uint64_t qword60;
        uint64_t qword68;
        uint64_t qword70;
        uint32_t dword78;
        uint64_t qword80;
        uint64_t qword88;
        uint64_t qword90;
        uint64_t qword98;
        uint64_t qwordA0;
        uint64_t qwordA8;
        uint64_t qwordB0;
        uint64_t qwordB8;
        uint64_t qwordC0;
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint32_t dwordD8;
        uint8_t byteDC;
        uint64_t qwordE0;
        uint32_t dwordE8;
        uint64_t qwordF0;
        uint64_t qwordF8;
        uint64_t qword100;
        uint64_t qword108;
        uint64_t enabledBitsCopy;
        uint64_t qword118;
        void (*getRenderResolutionOverride)(void* userData, float& renderResX, float& renderResY);
        void* getRenderResolutionOverrideUserData;
        uint64_t qword130;

        DeferredRenderJob(csl::fnd::IAllocator* allocator, unsigned int viewportId);

        virtual unsigned int UnkFunc6(PipelineInfo* pipelineInfo) override;
        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void UnkFunc9() override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
        virtual unsigned int UnkFunc17() override;
        virtual void UnkFunc19() {}
        virtual void UnkFunc20() {}
        virtual void UnkFunc21() {}
        virtual void SetupDeferredRenderingPipeline();
    };
}
