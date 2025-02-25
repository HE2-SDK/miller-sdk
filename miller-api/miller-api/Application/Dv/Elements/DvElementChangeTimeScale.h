#pragma once

namespace app::dv{
    class DvElementChangeTimeScale : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool enabled;
            float timeScale;
            int unk1;
            int unk2;
        };

        bool messageSent;
        int unkHandle;

        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;
        virtual void* RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementChangeTimeScale)
    };
}