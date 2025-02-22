#pragma once

namespace app::dv{
    class DvElementBulletTime : public AppDvElementBase{
    public:
        struct Data {
        public:
            int type;
            int unk0;
            int unk1;
        };

        virtual bool UnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementBulletTime)
    };
}