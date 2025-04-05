#pragma once

namespace app::dv{
    class DvElementFacialAnimation : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct Animation {
            public:
                enum class AnimationType : unsigned int {
                    SKELETAL_ANIMATION = 1,
                    UV_ANIMATION,
                    VISIBILITY_ANIMATION,
                    MATERIAL_ANIMATION
                };

                AnimationType animType;
                char fileName[64];
            };

            Animation animations[3];
            int activeAnimationsCount;
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void AppUnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFacialAnimation)
    };
}
