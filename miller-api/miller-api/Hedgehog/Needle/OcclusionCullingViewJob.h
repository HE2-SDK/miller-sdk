#pragma once

namespace hh::needle {
    class PipelineInfo;
    class OcclusionCullingViewJob : public RenderJob {
    public:
        unsigned int unk101;

        OcclusionCullingViewJob(unsigned int unkParam);
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
    };
}
