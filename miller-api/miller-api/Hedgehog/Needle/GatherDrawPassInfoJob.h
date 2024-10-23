#pragma once

namespace hh::needle {
    class PipelineInfo;
    class RenderJob;
    class GatherDrawPassInfoJob : public NeedleRefcountObject {
    public:
        struct DrawPassState {
            bool passEnabled[128];
            bool pass2Enabled[128];

            bool IsPassEnabled(unsigned int passId) const;
            bool IsPass2Enabled(unsigned int passId) const;
            void SetPassEnabled(unsigned int passId);
            void SetPass2Enabled(unsigned int passId);
            unsigned int GetEnabledPassCount() const;
        };

        RenderJob* renderJob;
        unsigned int viewportId;
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;

        GatherDrawPassInfoJob(RenderJob* renderJob, csl::fnd::IAllocator* allocator, unsigned int viewportId);
        virtual void Run(DrawPassState& drawPassState, const PipelineInfo& pipelineInfo);
    };
}
