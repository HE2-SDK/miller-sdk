#pragma once

namespace app::dv{
    class DvElementTimeStop : public AppDvElementBase{
    public:
        struct Data {
        public:
            int type;
            int unk0;
            float unk1;
        };

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementTimeStop)
    };
}
