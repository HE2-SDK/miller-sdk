#pragma once

namespace hh::dv{
    class DvElementCullingDisable : public DvElementBase {
    public:
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCullingDisable)
    };
}
