#pragma once

namespace hh::gfx {
    class RenderingEngineRangers : public RenderingEngineNeedle {
    public:
        needle::SupportFXAll supportFX;
        needle::intrusive_ptr<needle::RenderUnit> mainRenderUnit;
        needle::intrusive_ptr<needle::RenderingPipelineRangers> mainRenderingPipeline;
        uint64_t unk203;

        RenderingEngineRangers(csl::fnd::IAllocator* allocator);
        
        virtual uint64_t Startup() override;
        virtual void SetFXParameter(hh::needle::NeedleFxParameter* parameter, needle::CNameIDObject* renderUnitName) override;
        virtual void GetFXParameter(hh::needle::NeedleFxParameter* parameter) override;
        virtual void SetSceneConfig(hh::needle::NeedleFxSceneConfig* sceneConfig) override;
        virtual void GetSceneConfig(hh::needle::NeedleFxSceneConfig* sceneConfig) override;
        virtual uint64_t CreateRenderTextureHandle(const needle::RenderTextureCreateArgs& createArgs, csl::fnd::IAllocator* allocator) override;
        virtual void AddRenderableToRenderTextureHandle(needle::RenderTextureHandle* handle, gfnd::Renderable* renderable) override;
        virtual void SetDebugViewType(unsigned int debugViewType) override;
        virtual needle::RenderingPipeline* GetMainRenderingPipeline() const override;
        virtual void SetupMainRenderUnit() override;
    };
}
