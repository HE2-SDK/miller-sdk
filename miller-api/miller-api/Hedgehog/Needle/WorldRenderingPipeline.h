#pragma once

namespace hh::needle {
    class WorldRenderingPipelineExecContext;
    class WorldRenderingPipeline : public RenderingPipeline {
    public:
        struct RenderParameters {
            SDrawPassSceneSetting* drawPassSettings;
            unsigned int parameterCount; // possibly viewport count?
            unsigned int unk104;
            unsigned int parameterSize;
            unsigned int cullingGroupCount;
            SCullGroupSetting* cullingGroupSettings;
            uint64_t unk107;
            unsigned int* occlusionCullingIndices; // dunno
            uint32_t enableOcclusionCullingView; // or maybe occlusion culling view type? dunno
            uint32_t unk109;
            uint64_t unk110;
        };
        struct SetupInfo {
            PBRModelInstanceRenderer* modelInstanceRenderer;
            uint32_t drawPassCount;
            RenderParameters renderParameters;
            uint8_t unk111;
        };

        csl::fnd::Mutex mutex;
        SetupInfo settings;
        csl::ut::MoveArray<GatherDrawPassInfoJob*> gatherDrawPassInfoJobs;
        csl::ut::MoveArray<ParamBuildJob*> paramBuildJobs;
        int unk114;
        uint32_t unk115;

        WorldRenderingPipeline(csl::fnd::IAllocator* allocator);

        WorldRenderingPipelineExecContext* CreateExecContext(unsigned int unkParam);
        void Setup(const SetupInfo& setupInfo);
        void AddGatherDrawPassInfoJob(GatherDrawPassInfoJob* gatherDrawPassInfoJob);
        void RemoveGatherDrawPassInfoJob(GatherDrawPassInfoJob* gatherDrawPassInfoJob);
        void AddParamBuildJob(ParamBuildJob* gatherDrawPassInfoJob);
        void RemoveParamBuildJob(ParamBuildJob* gatherDrawPassInfoJob);

        virtual uint64_t UnkFunc1() override;
        virtual void UnkFunc2(PipelineInfo* pipelineInfo) override;
        virtual void StopJobs() override;
        virtual void Execute(PipelineInfo* pipelineInfo, WorldRenderingPipelineExecContext* execContext);
        virtual void UnkFunc14() {}
        virtual void UnkFunc15() {}
        virtual void UnkFunc16() {}
        virtual void UnkFunc17() {}
    };
}
