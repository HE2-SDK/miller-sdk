#pragma once

namespace hh::dv {
    class DvPageConditionEnd : public DvPageConditionBase {
    public:
        virtual bool UnkFunc5() override;

        DV_PAGE_CONDITION_DECLARATION_BASE(DvPageConditionEnd)
    };
}
