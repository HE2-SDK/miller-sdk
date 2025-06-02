#pragma once

namespace app::dv{
    class DvElementVignetteParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                CURVE_ENABLED = 1
            };

            enum class GradationType : unsigned int {
                GRADATION_MODE_CIRCLE,
                GRADATION_MODE_LINE,
            };
    
            enum class BlendMode : unsigned int {
                BLEND_MODE_ALPHA_BLEND,
                BLEND_MODE_ADD,
                BLEND_MODE_MUL,
                BLEND_MODE_SCREEN,
                BLEND_MODE_OVERLAY,
            };

            struct ImageCircleParam {
            public:
                csl::math::Vector2 position;
                csl::math::Vector2 size;
                float scale;
            };

            struct VignetteParam {
            public:
                ImageCircleParam imgCrclParam;
                csl::math::Vector2 direction;
                float opacity;
                unsigned int color[3];
                float penumbraScale;
                float intensity;
                float rotation;
            };

            csl::ut::Bitset<Flags> flags;
            GradationType gradationType;
            VignetteParam vignetteParams;
        private:
            float unused0;
        public:
            BlendMode blendMode;
        private:
            float unused1[9];
        public:
            VignetteParam finishVignetteParams;
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementVignetteParam)
    };
}
