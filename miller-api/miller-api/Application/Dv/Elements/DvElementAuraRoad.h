#pragma once

namespace app::dv{
    class DvElementAuraRoad : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            int unk0;
            float curveData0[32];
            float curveData1[32];
        };

        int unk0;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAuraRoad)
    };
}
