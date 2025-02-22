#pragma once

namespace app::dv{
    class DvElementOpeningLogo : public AppDvElementBase{
    public:
        struct Data {};

        hh::fnd::Reference<hh::game::GameObject> handle;

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementOpeningLogo)
    };
}
