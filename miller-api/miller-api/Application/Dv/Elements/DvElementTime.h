#pragma once

namespace app::dv{
    class DvElementTime : public AppDvElementBase{
    public:
        struct Data {
        public:
            bool curveEnabled;
            int unk1;
            int unk2;
            int unk3;
            int unk4;
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementTime)
    };
}
