#pragma once

namespace hh::needle {
    class FxRenderTextureCamera : public FxCamera, public NeedleRefcountObject {
    public:
        csl::math::Vector4 position;
        csl::math::Matrix44 viewMatrix;
        csl::math::Matrix44 projMatrix;

        FxRenderTextureCamera();

        virtual csl::math::Vector3 GetEyePos() const override;
        virtual void GetEyePosF(float* eyePos) const override;
        virtual csl::math::Vector3 GetLookAtPos() const override;
        virtual void GetLookAtPosF(float* lookAtPos) const override {}
        virtual csl::math::Matrix44 GetViewMatrix() const override;
        virtual void GetViewMatrixF(float* viewMatrix) const override;
        virtual csl::math::Matrix44 GetProjectionMatrix() const override;
        virtual void GetProjectionMatrixF(float* projectionMatrix) const override;
    };

    struct RenderTextureCreateArgs {
        uint32_t unk1;
        uint32_t unk2;
        uint32_t unk3;
        uint32_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        RenderTexturePipeline* pipeline;
        const char* name;
        const char* sceneName;
    };

    class RenderTextureHandle : public RenderUnit {
    public:
        uint8_t unk101;
        intrusive_ptr<NeedleRefcountObject> unk102[4];
        intrusive_ptr<NeedleRefcountObject> unk103[4];
        intrusive_ptr<NeedleRefcountObject> unk104[4];
        intrusive_ptr<NeedleRefcountObject> unk105[4];
        uint64_t unk106;
        uint64_t unk107;
        uint64_t unk108;
        uint64_t unk109;
        uint32_t unk110;
        uint32_t unk111;
        csl::math::Vector4 unk112;
        uint32_t unk113;
        uint32_t unk114;
        FxRenderTextureCamera* camera;
        uint32_t unk115;
        int unk116;
        int unk117;
        uint64_t unk118;
        uint64_t unk119;
        uint64_t unk120;
        uint64_t unk121;

        RenderTextureHandle(const RenderTextureCreateArgs& createArgs, SupportFXAll* supportFX, RenderManager* renderManager);
        RenderTextureHandle(const RenderTextureCreateArgs& createArgs, SupportFXAll* supportFX);
        
        virtual bool IsEnabled(const RenderInfo& renderInfo) override;
        virtual void SetRenderDimensions(const RenderInfo& renderInfo) override;
        virtual void UnkFunc5() override;
        virtual void LoadRenderParams(const RenderInfo& renderInfo) override;
    };
}
