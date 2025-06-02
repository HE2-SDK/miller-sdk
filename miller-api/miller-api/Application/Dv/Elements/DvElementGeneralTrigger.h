#pragma once

namespace app::dv{
    class DvElementGeneralTrigger : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            int unk0;
            char triggerName[64];
        };

        char triggerName[64];

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementGeneralTrigger)
    };
}
