#pragma once

namespace app::dv{
    class DvElementFalloff : public AppDvElementBase{
    public:
        struct Data {
        public:
            float value;
        };

        csl::ut::MoveArray<void*> unkArray0;

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFalloff)
    };
}
