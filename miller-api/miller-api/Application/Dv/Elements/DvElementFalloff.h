#pragma once

namespace app::dv{
    class DvElementFalloff : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            float value;
        };

        csl::ut::MoveArray<void*> unkArray0;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFalloff)
    };
}
