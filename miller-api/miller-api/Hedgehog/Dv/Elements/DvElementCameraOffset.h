#pragma once

namespace hh::dv{
    class DvElementCameraOffset : public DvElementBase {
    public:
        struct Data {
        public:
            bool disabled;
            csl::math::Position finishOffsetPosition;
            csl::math::Position offsetPosition;
            float unk1[5]; //unused
            float curveData[256];
        };

        Data binaryData;

        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraOffset)
    };
}