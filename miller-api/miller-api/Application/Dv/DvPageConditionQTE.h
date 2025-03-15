#pragma once

#define APP_DV_PAGE_CONDITION_DECLARATION_BASE(ClassName)public:\
		static DvPageConditionBase* Create(DvPageConditionBase* self, csl::fnd::IAllocator* allocator);

namespace app::dv {
    class DvPageConditionQTE : public hh::dv::DvPageConditionBase {
    public:
        struct Data {
        public:
            bool failed;
            int unk1;
            int unk2;
            int unk3;
        };

        Data binaryData;
        evt::EventPlayer* evtPlayer;
        bool unk0;

        virtual void Setup(void* setupInfo) override;
        virtual bool UnkFunc5() override;

        APP_DV_PAGE_CONDITION_DECLARATION_BASE(DvPageConditionQTE)
    };
}