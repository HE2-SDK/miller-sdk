#pragma once

namespace app::dv{
    class DvElementFxColUpdate : public AppDvElementBase{
    public:
        struct Data {};

        virtual bool UnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFxColUpdate)
    };
}