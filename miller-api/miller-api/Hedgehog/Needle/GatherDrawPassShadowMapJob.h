#pragma once

namespace hh::needle {
    class GatherDrawPassShadowMapJob : public GatherDrawPassInfoJob {
    public:
        GatherDrawPassShadowMapJob(RenderJob* renderJob, csl::fnd::IAllocator* allocator, unsigned int viewportId);
        virtual ~GatherDrawPassShadowMapJob();

        virtual void Run(DrawPassState& drawPassState, const PipelineInfo& pipelineInfo) override;
    };
}
