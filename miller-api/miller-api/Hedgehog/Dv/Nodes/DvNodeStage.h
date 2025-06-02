#pragma once

namespace hh::dv{
    class DvNodeStage : public DvNodeBase{
    public:
        char unk0[148];

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Start() override;

        DV_NODE_DECLARATION_BASE(DvNodeStage)
    };
}
