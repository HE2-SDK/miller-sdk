#pragma once

namespace app::ui {
    class UIOverlayService : public hh::game::GameService, public hh::game::GameUpdateListener, public app::fnd::AppResourceManagerListener {
        csl::fnd::Mutex mutex1;
        csl::fnd::Mutex mutex2;
        uint8_t unk100;
        csl::ut::StringMap<void*> unk101;
        uint64_t unk102;
        uint32_t unk103;
        uint32_t unk103b;
        uint32_t unk103c;
        csl::ut::StringMap<void*> unk108;
        csl::ut::StringMap<void*> unk109;

    public:
		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PreGameUpdateCallback(hh::game::GameManager* gameManager, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void PostGameUpdateCallback(hh::game::GameManager* gameManager, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void ARML_UnkFunc0(int unkParam1) override;
        virtual void ARML_UnkFunc1(int unkParam1) override;
        void QueueBeginRequest(RequestOverlayBegin* request);

        GAMESERVICE_CLASS_DECLARATION(UIOverlayService);
    };
}
