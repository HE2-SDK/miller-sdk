#pragma once

namespace hh::dv{
    class DvNodeCharacter : public DvNodeBaseAnimationModel {
    public:
        virtual void Update(int curFrame) override;

        DV_NODE_DECLARATION_BASE(DvNodeCharacter)
    };
}