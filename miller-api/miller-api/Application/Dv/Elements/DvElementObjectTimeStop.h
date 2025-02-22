#pragma once

namespace app::dv{
    class DvElementObjectTimeStop : public AppDvElementBase{
    public:
        struct Data {
        public:
            int type;
        };

        virtual bool UnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementObjectTimeStop)
    };
}