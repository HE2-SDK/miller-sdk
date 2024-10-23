#pragma once

namespace hh::needle {
    class PostEffectRenderJob : public RenderJob {
    public:
        void* qword50[10];
        void* qword98[8];
        RenderManager* renderManager;
        RenderTargetReference renderTarget;

        PostEffectRenderJob(RenderManager* renderManager);
        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void UnkFunc20(unsigned int index, void* obj);
        virtual void UnkFunc21(unsigned int index, void* obj);
        virtual void UnkFunc22();
        virtual void UnkFunc23();
        virtual void UnkFunc24();
    };
}
