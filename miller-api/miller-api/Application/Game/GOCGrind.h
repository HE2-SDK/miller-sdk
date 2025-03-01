#pragma once

namespace app::game {
    class GOCGrind : public hh::game::GOComponent, public hh::fnd::HFrameListener {
    public:
        uint64_t unk1;
        unsigned int pathComponentNameHash;
        unsigned int model1ComponentNameHash;
        unsigned int model2ComponentNameHash;
        unsigned int model3ComponentNameHash;
        const char* pathName;
        float unk5;
        uint8_t unk6;
        GrindModelUpdater* updater;
        hh::fnd::Reference<hh::fnd::HFrame> frame;
        unsigned char flags;

        GOCOMPONENT_CLASS_DECLARATION(GOCGrind);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;
    };
}
