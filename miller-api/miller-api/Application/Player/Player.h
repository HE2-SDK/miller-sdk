#pragma once

namespace app::player {
    class Player : public hh::game::GameObject {
    public:
        enum class StartType : uint32_t {
            STAND = 0,
            RUNNING = 1,
            FALL = 2,
            DOWN = 3,
            BOARDING = 4,
        };

        struct PlayerSetupInfo {
            char playerId;
            hh::fnd::WorldPosition worldPos;
            CharacterIdU8 characterId;
            uint32_t unk2;
            float deadline;
            float deadFallTime;
            float oceanSurface;
            uint8_t unk6;
            int unk7;
            float unk8;
            uint8_t unk9;
            StartType startType;
            float startSpeed;
            float startTime;
            float startOutOfControlTime;
            uint8_t unk14;
            PlayerSetupInfo();
        };

        PlayerSetupInfo setupInfo;

        Player(csl::fnd::IAllocator* allocator);
        
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;

        virtual void InitializePlayer() = 0;
        virtual void DeinitializePlayer() = 0;

        void Setup(const PlayerSetupInfo& setupInfo);
		static void Kill(hh::game::GameManager* gameManager, uint8_t playerId);
        static Player* Spawn(hh::game::GameManager* gameManager, const PlayerSetupInfo& playerSetupInfo);
    };
}
