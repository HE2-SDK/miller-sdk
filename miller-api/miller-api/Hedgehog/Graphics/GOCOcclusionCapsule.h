#pragma once

namespace hh::gfx {
    class GOCOcclusionCapsule : public game::GOComponent, public fnd::HFrameListener {
    public:
        csl::ut::MoveArray<void*> unk1;
        uint32_t unk4;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual const char* GetCategory() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCOcclusionCapsule)
    };
}
