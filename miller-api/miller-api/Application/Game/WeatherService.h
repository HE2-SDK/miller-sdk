#pragma once

namespace app::game {
    class WeatherService
        : public hh::game::GameService
        , public hh::game::GameStepListener
        , public hh::game::GameManagerListener
        , public app::save::SaveManagerListener
        , public app::game::TimeServiceListener
    {
    public:
        struct Unk1 {
            float unk1;
            uint32_t unk2;
            Unk1();
        };

        enum class WeatherType : uint8_t {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
        };

        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        uint32_t unk4;
        float unk5;
        Unk1 unk6;
        WeatherType unk7;
        Timestamp unk8;
        WeatherType unk9;
        Timestamp unk10;
        Timestamp unk11;
        Timestamp unk12;
        Timestamp unk13;
        Timestamp unk14;
        Timestamp unk15;
        Timestamp unk16;
        uint64_t unk17;
        uint8_t unk18;
    
		virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
		virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual void SML_UnkFunc1() override;
        virtual void TimeChangeCallback(const Timestamp& previousTime, const Timestamp& currentTime) override;

        void SetWeather(WeatherType type, float unkParam);

        GAMESERVICE_CLASS_DECLARATION(WeatherService);
    };
}
