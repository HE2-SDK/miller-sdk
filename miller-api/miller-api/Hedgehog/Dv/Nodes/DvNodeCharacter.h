#pragma once

namespace hh::dv{
    class DvNodeCharacter : public DvNodeBaseAnimationModel {
    public:
        virtual void Update(int currentFrame) override;

        DV_NODE_DECLARATION_BASE(DvNodeCharacter)
    };
}
