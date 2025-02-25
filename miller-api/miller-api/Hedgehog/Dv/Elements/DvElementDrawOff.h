#pragma once

namespace hh::dv{
    class DvElementDrawOff : public DvElementBase {
    public:
        struct Data {
        public:
            int unk0[4];
        };

        Data binaryData;
        
        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementDrawOff)
    };
}