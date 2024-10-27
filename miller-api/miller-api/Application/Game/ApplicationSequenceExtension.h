#pragma once

namespace app::game {

    class ApplicationSequenceExtension
        : public ApplicationExtension
        , public hh::game::GameManagerListener
        , public hh::fnd::user::UserInfoEventListener
        , public hh::fw::FrameworkNotificationListener
    {
        struct Unk2 {
            char stageName[16];
            int unk2;
            hh::fnd::WorldPosition unk3;
            int unk4;
            uint8_t unk5;

            Unk2();

            const char* GetStageName() const;
        };

        struct Unk1 {
            char levelName[16];
            char unk1[32];
            Unk2 unk2;
            uint16_t unk3;
            uint16_t unk3a;
            uint16_t unk4;
            uint32_t unk5;
            uint8_t unk6;

        };

        hh::ut::TinyFsm<ApplicationSequenceExtension> fsm;
        GameMode* currentGameMode;
        hh::ut::TinyFsm<ApplicationSequenceExtension>::State_t state;
        Unk1 unk1;
        uint64_t unk2;
        uint16_t unk3;
        uint32_t unk4a;

    public:
        inline static const char name[] = "ApplicationSequenceExtension";
        ApplicationSequenceExtension(csl::fnd::IAllocator* allocator);
        virtual uint64_t GetNameHash() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override {}
		virtual void MessageProcessedCallback(hh::game::GameManager* gameManager, const hh::fnd::Message& msg) override;
        virtual void UIEL_UnkFunc1() override;
        virtual void FNL_UnkFunc4() override;

        inline GameMode* GetCurrentGameMode() {
            return currentGameMode;
        }
    };
}
