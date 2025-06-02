#pragma once

#define APP_DV_PAGE_CONDITION_DECLARATION_BASE(ClassName)public:\
		static DvPageConditionBase* Create(DvPageConditionBase* self, csl::fnd::IAllocator* allocator);

namespace app::dv {
    class DvPageConditionQTE : public hh::dv::DvPageConditionBase {
    public:
        struct Description : hh::dv::DvPageConditionBase::Description {
        public:
            bool failed;
            int unk1;
            int unk2;
            int unk3;
        };

        Description binaryData;
        evt::EventPlayer* evtPlayer;
        bool unk0;

        virtual void Setup(hh::dv::DvPageConditionBase::Description& description) override;
        virtual bool UnkFunc5() override;

        APP_DV_PAGE_CONDITION_DECLARATION_BASE(DvPageConditionQTE)
    };
}
