#pragma once

namespace hh::dv{
    class DvElementCameraNearFar : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                DISABLED_NEAR_CLIP,
                DISABLED_FAR_CLIP
            };
            
            csl::ut::Bitset<Flags> flags;
            float nearClip;
            float farClip;
            int unk1[5];
        };

        Description binaryData;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraNearFar)
    };
}
