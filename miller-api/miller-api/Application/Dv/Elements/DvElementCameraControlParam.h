#pragma once

namespace app::dv{
    class DvElementCameraControlParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            int empty0;
            float exposureValue;
            int empty1[6];
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCameraControlParam)
    };
}
