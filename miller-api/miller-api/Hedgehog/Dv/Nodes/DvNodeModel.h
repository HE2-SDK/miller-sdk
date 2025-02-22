#pragma once

namespace hh::dv{
    class DvNodeModel : public DvNodeBaseAnimationModel {
    public:
        virtual void Update(int curFrame) override;
        virtual void UnkFunc6(void* unk0, void* unk1) override;
        virtual bool UnkFuncBase() override;

        DV_NODE_DECLARATION_BASE(DvNodeModel)
    };
}