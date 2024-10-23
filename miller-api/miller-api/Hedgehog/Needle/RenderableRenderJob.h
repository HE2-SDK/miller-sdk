#pragma once

namespace hh::needle {
    class RenderableRenderJob : public RenderJob {
    public:
        typedef void Callback(RenderManager* renderManager, RenderingDeviceContext* deviceContext);

        unsigned int renderableId;
        int viewportId;
        const char* name;
        Callback* onBeforeRender;
        Callback* onAfterRender;
        uint64_t unk103;

        RenderableRenderJob(unsigned int renderableId, int viewportId, const char* name);
        
        virtual unsigned int UnkFunc6(PipelineInfo* pipelineInfo) override;
        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
    };
}
