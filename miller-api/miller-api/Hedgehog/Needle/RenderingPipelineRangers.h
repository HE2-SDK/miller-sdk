#pragma once

namespace hh::needle {
    class PBRModelInstanceRenderer;
    class RenderingPipelineRangers : public WorldRenderingPipeline {
    public:
        const char* name;
        uint64_t qword118;
        uint64_t qword120;
        uint64_t qword128;
        uint64_t qword130;
        uint64_t qword138;
        uint64_t qword140;
        uint64_t qword148;
        uint64_t qword150;
        csl::ut::MoveArray<void*> qword158;
        uint64_t qword178;
        uint64_t qword180;
        uint64_t qword188;
        uint64_t qword190;
        uint64_t qword198;
        uint64_t qword1A0;
        uint64_t qword1A8;
        uint64_t qword1B0;

        RenderingPipelineRangers(csl::fnd::IAllocator* allocator, PBRModelInstanceRenderer* renderer);

        virtual uint64_t UnkFunc1() override;
        virtual void UnkFunc3(PipelineInfo* pipelineInfo) override;
        virtual void InitializeJobs() override;
        virtual void DeinitializeJobs() override;
    };
}
