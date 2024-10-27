#pragma once

namespace app::game {
    class MonologueService : public hh::game::GameService, public hh::game::GameStepListener {
    public:
        csl::fnd::Mutex mutex;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::MonologueParameters>> parametersResource;
        heur::rfl::MonologueParameters* parameters;
        int unk1;
        int unk2;
        float monologueTimeout;
        float timeUntilNextMonologue;
        uint32_t unk5;
        uint32_t unk6;
        uint8_t unk7a;

		virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void ResetTimeout();

        GAMESERVICE_CLASS_DECLARATION(MonologueService);
    };
}
