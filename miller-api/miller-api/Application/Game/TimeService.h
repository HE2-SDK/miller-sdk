#pragma once

#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

namespace app::gfx {
    class FxParamManager;
}

namespace app::game {
    class TimeServiceListener {
    public:
        virtual void NightTimeChangeCallback(bool isNight) {}
        virtual void TimeChangeCallback(const Timestamp& previousTime, const Timestamp& currentTime) {}
    };

    class TimeService : public hh::game::GameService, public hh::game::GameManagerListener, public app::save::SaveManagerListener, public hh::game::GameStepListener {
    public:
        struct TimeProgressSpeed {
            float start;
            float speed;
        };

        Timestamp currentTime;
        Timestamp previousTime;
        float startOfNightInHours;
        float endOfNightInHours;
        csl::ut::InplaceMoveArray<float, 4> unk4;
        csl::ut::MoveArray<TimeProgressSpeed> timeProgressSpeeds;
        app::gfx::FxParamManager* fxParamManager;
        csl::ut::MoveArray<TimeServiceListener*> listeners;
        uint64_t unk8;
        uint64_t unk9;
        bool sceneDataLoaded;
        bool timeProgressEnabled;
        bool fixedTime;
        float secondsUntilNextUpdate;

		virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void GameServiceAddedCallback(GameService* gameService) override;
		virtual void GameServiceRemovedCallback(GameService* gameService) override;
        virtual void SML_UnkFunc1() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        bool HaveMinutesPassedSinceTimestamp(const Timestamp& timestamp, int minutes) const;
        const Timestamp& GetCurrentTime() const;
        bool IsNightTime() const;
        void AddListener(TimeServiceListener* listener);
        void RemoveListener(TimeServiceListener* listener);
        void SetFixedTime(int hours, int minutes);

    protected:
        void FireNightTimeChangeCallback(bool isNight);
        void FireTimeChangeCallback(const Timestamp& previousTime, const Timestamp& currentTime);

        GAMESERVICE_CLASS_DECLARATION(TimeService);
    };
}
