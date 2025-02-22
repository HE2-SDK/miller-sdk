#pragma once

namespace hh::dv{
    class DvElementCullingDisable : public DvElementBase {
    public:
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCullingDisable)
    };
}