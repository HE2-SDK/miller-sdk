#pragma once

namespace hh::needle {
    class WorldRenderingPipelineExecContext : public NeedleObject {
    public:
        struct Unk1 {
            bool byte470;
            bool byte471;
            uint32_t drawPassCount;
            WorldRenderingPipeline::SetupInfo pipelineSetupInfo;
        };

        struct Unk2 {
            RenderJob* job;
            RenderJob* oncePerPass1;
            RenderJob* oncePerPass2;
            RenderJob* beforeFirstPass;
            RenderJob* afterLastPass;
            SyncDrawContext* drawContext;
            void* unk6;
            uint32_t flags;
            uint16_t unk2Count; // like, the object itself? it's wierd
            uint16_t maybeType;
            uint32_t unk9;
            uint32_t unk10; // unsure if this exists
        };

        struct Unk3 {
            CScratchMemoryContext memCtx;
            Unk2* jobs;
            uint32_t jobCount;
            uint32_t qword464;
            uint32_t dword468;
        };


        bool shouldFlushParameterQueue;
        GatherRenderingPassContext gatherRenderingPassContext;
        DrawPassInfo drawPassInfo;
        PipelineInfo pipelineInfo;
        intrusive_ptr<GlobalParameterBuilder> globalParameterBuilder;
        intrusive_ptr<ParameterValueObject> globalParameters;
        Unk3 unk0;
        Unk1 unk1;

        WorldRenderingPipelineExecContext(unsigned int unkParam);
        virtual ~WorldRenderingPipelineExecContext();
    };
}
