#pragma once

namespace hh::needle {
    class SMAAJob : public PostEffectRenderJob {
    public:
        intrusive_ptr<PostEffectShader> shaders[3];
        intrusive_ptr<Texture> unkTexture;
        intrusive_ptr<Texture> unkTexture1;

        SMAAJob();
        virtual void UnkFunc9() override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
        virtual void Setup(const RenderJobContext& context) override;
        virtual void UnkFunc23() override;
    };
}
