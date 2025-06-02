#pragma once

namespace hh::dv{
    class DvElementPathOffset : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                DISABLED = 2
            };

            csl::math::Matrix44 offsetMatrix;
            csl::ut::Bitset<Flags> flags;
            int unk0[3];
        };
        
        Description binaryData;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementPathOffset)
    };
}
