#pragma once

namespace app::save {
    class SaveManagerListener {
    public:
        virtual ~SaveManagerListener() = default;
        virtual void SML_UnkFunc1() {}
        virtual void SML_UnkFunc2() {}
        virtual void SML_UnkFunc3() {}
    };

    class SaveManager
        : public hh::game::GameService
        , public hh::game::GameStepListener
        , public hh::fw::FrameworkNotificationListener
        , public hh::fnd::user::UserInfoEventListener
        , public hh::game::stats::StatsListener
    {
    public:
        csl::fnd::Mutex mutex;
        hh::fnd::Reference<SaveInterface> saveInterface;
        csl::ut::MoveArray<void*> unkC0;
        csl::ut::InplaceMoveArray<void*, 4> unkE0[2];
        csl::ut::InplaceMoveArray<void*, 4> unk160[2];
        uint32_t dword1E0;
        uint8_t byte1E4;
        uint64_t qword1E8;
        uint32_t dword1F0;
        csl::ut::MoveArray<void*> unk1F8;
        uint32_t dword218;
        uint8_t byte21C;
        uint64_t qword220;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void UIEL_UnkFunc1() override;
        virtual void SL_UnkFunc2() override;

        GAMESERVICE_CLASS_DECLARATION(SaveManager);
    };
}
