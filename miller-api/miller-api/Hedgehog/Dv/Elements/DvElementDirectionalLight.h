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

        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementDirectionalLight)
    };
}