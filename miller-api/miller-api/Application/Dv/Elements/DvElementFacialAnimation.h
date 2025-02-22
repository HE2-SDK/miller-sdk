#pragma once

namespace app::dv{
    class DvElementFacialAnimation : public AppDvElementBase{
    public:
        struct Data {
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

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void AppUnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFacialAnimation)
    };
}
