#pragma once

namespace app::dv{
    class DvElementSSAOParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class SSAOType : unsigned int {
                SSAO,
                HBAO,
                HBAO_SSS,
                SSS
            };

            enum class RenderTargetSize : unsigned int {
                RTSIZE_SAME_AS_FRAMEBUFFER,
                RTSIZE_ONE_SECOND,
                RTSIZE_ONE_FORTH
            };

            enum class BlurType : unsigned int {
                None,
                Gauss2x2,
                Gauss3x3,
                Gauss4x4,
                Gauss5x5,
                Gauss6x6,
                Gauss7x7,
                Gauss8x8,
                Gauss9x9,
                Bilateral,
                NoisySample
            };

            enum class Flags : unsigned int {
                ENABLED,
                USE_RENDER_TARGET_SIZE
            };

            csl::ut::Bitset<Flags> flags;
            SSAOType postType;
            float intensity;
            float radius;
            float fadeoutDistance;
            float fadeoutRadius;
            float power;
            float bias;
            float occlusionDistance;
            float directLightingInfluence;
            RenderTargetSize renderTargetSize;
            BlurType blurStep;
            float bilateralThreshold;
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementSSAOParam)
    };
}
