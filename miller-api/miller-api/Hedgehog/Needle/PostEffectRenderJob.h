#pragma once

namespace hh::needle {
    class PostEffectRenderJob : public RenderJob {
    public:
        Texture* renderTextures[10];
        RenderTarget* renderTargets[8];
        RenderTargetReference renderTarget;

        PostEffectRenderJob();
        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void SetTexture(unsigned int index, Texture* texture);
        virtual void SetRenderTarget(unsigned int index, RenderTarget* renderTarget);
        virtual void Setup(const RenderJobContext& context);
        virtual void UnkFunc23();
        virtual void UnkFunc24();
    };
}
