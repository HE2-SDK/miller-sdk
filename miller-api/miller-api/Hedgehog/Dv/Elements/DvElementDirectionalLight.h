#pragma once

namespace hh::dv{
    class DvElementDirectionalLight : public DvElementBase {
    public:
        struct Data {
        public:
            int unk0;
            csl::math::Position direction;
            int unk1[8];
        };

        Data binaryData;

        virtual void Setup(void* unk) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementDirectionalLight)
    };
}