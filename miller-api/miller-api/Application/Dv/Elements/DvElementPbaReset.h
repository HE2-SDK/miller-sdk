#pragma once

namespace app::dv{
    class DvElementPbaReset : public AppDvElementBase{
    public:
        struct Data {
        public:
            char data[800];
        };

        hh::dv::DvNodeBaseAnimationModel* dvMdl;

        virtual bool UnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementPbaReset)
    };
}
