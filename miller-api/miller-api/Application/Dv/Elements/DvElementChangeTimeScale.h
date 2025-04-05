#pragma once

namespace app::dv{
    class DvElementChangeTimeScale : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            bool unkEnabled;
            float timeScale;
            int unk1;
            float multiplier;
        };

        bool messageSent;
        int unkHandle;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementChangeTimeScale)
    };
}
