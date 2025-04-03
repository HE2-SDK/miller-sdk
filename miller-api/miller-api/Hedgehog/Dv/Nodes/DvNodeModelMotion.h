#pragma once

namespace hh::dv{
    class DvNodeModelMotion : public DvNodeCharacterMotion{
    public:
        virtual void Update(int currentFrame) override;

        DV_NODE_DECLARATION_BASE(DvNodeModelMotion)
    };
}
