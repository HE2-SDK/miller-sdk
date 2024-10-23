#pragma once

namespace hh::needle {
    class CachedShadowMapRenderJob : public RenderJob {
    public:
        struct alignas(16) Unk1 {
            char pads1[240];
        };

        struct alignas(16) Unk2 {
            char pad[2800];
        };

        unsigned int viewportId;
        RenderingPipeline* renderingPipeline;
        GatherDrawPassInfoJob* gatherDrawPassInfoJob;
        ParamBuildJob* paramBuildJob;
        char unk104[0x68];
        bool unk105;
        Unk1 unk106[4];
        Unk1 unk107[4];
        Unk1 unk108[4];
        char unk109[0x68];
        csl::ut::MoveArray<void*> unk110;
        FxShadowMapParameter shadowMapParameter;
        uint64_t unk110a;
        uint64_t unk110b;
        uint64_t unk110c;
        uint64_t unk110d;
        uint64_t unk110e;
        uint64_t unk110f;
        uint64_t unk110g;
        uint64_t unk110h;
        uint64_t unk110i;
        Unk2 unk111;
        Unk2 unk112;
        uint8_t unk113;
        uint32_t unk114;
        char unk115[360];
        PostEffectShader unk116;
        PostEffectShader unk117;
        uint32_t unk118;
        uint8_t unk119;
        uint64_t unk120;
        uint64_t unk121;

        CachedShadowMapRenderJob(csl::fnd::IAllocator* allocator, unsigned int viewportId, bool unk105Param);
        virtual ~CachedShadowMapRenderJob();

        virtual unsigned int UnkFunc6(PipelineInfo* pipelineInfo) override;
        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void UnkFunc9() override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
        virtual unsigned int UnkFunc17() override;
    };
}
