#pragma once

namespace app::dv{
    class DvElementDitherParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            float grassDitherStart;
            float grassDitherEnd;
        };

        int unk0;
        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementDitherParam)
    };
}
