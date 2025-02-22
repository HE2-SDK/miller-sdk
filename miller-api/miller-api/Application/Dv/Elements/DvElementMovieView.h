#pragma once

namespace app::dv{
    class DvElementMovieView : public AppDvElementBase{
    public:
        struct Data {};

        char unk0;

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementMovieView)
    };
}
