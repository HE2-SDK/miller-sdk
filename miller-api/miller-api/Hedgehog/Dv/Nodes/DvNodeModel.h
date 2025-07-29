#pragma once

namespace hh::dv{
    class DvNodeModel : public DvNodeBaseAnimationModel {
    public:
        virtual void Update(int currentFrame) override;
        virtual void UnkUpdate(int currentFrame, csl::math::Transform& transform) override;
        virtual bool UnkFuncBase() override;

        DV_NODE_DECLARATION_BASE(DvNodeModel)
    };
}