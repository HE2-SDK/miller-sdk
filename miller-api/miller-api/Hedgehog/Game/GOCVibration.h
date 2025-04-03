#pragma once

namespace hh::game{
    class GOCVibration : public GOComponent {
    public:
        csl::ut::MoveArray<hid::VibrationContainer*> vibrationContainers;  
        fnd::HFrame* hFrame;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCVibration)
    };
}
