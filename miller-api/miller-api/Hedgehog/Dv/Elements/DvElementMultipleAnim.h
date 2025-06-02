#pragma once

namespace hh::dv{
    class DvElementMultipleAnim : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
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
            int unk0;
            char stateName[8];
            int unk1;
            Animation animations[16];
            int activeAnimationsCount;
        };

        Description binaryData;
        csl::ut::MoveArray<void*> unkArray0;
        csl::math::Vector4 unk0;
        csl::math::Vector4 unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        csl::math::Vector4 unk4;
        csl::math::Vector4 unk5;
        char unk6;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementMultipleAnim)
    };
}
