#pragma once

namespace app::gfx {
    class FxParamTimeProgressExtension
        : public FxParamExtension
        , public hh::game::GameManagerListener
        , public evt::EventPlayerListener {
        game::TimeService* timeService;
        evt::EventPlayer* eventPlayer;
        heur::rfl::TimeProgressNeedleFxParam timeProgressNeedleFxParam;
        hh::needle::FxAtmosphereParameter atmosphereParameter;
        uint16_t unk1;
        
    public:
        FxParamTimeProgressExtension(csl::fnd::IAllocator* allocator);
        virtual void Initialize() override;
        virtual void Destroy() override;
        virtual void BeforeUpdate(hh::fnd::SUpdateInfo* updateInfo) override;
        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
        virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual void EPL_UnkFunc2() override;
        virtual void EPL_UnkFunc5() override;
    };
}
