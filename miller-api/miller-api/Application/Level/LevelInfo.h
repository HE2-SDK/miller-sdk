#pragma once

namespace app::level {
    class LevelInfo : public hh::game::GameService, public save::SaveManagerListener {
    public:
        StageData* stageData;
        void* unk6;
        char unk7[32];
        char unk11[32];
        hh::fnd::Reference<PlayerInformation> playerInformation;
        uint32_t unk16;
        uint32_t unk17;
        uint32_t unk18;
        uint8_t unk18a;
        csl::ut::MoveArray<hh::fnd::Handle<hh::fnd::Messenger>> uiObjects;
        uint16_t unk20;
        uint8_t unk21;
        uint32_t unk22;
        uint32_t unk23;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void SML_UnkFunc1() override;

        inline StageData* GetStageData() {
            return stageData;
        }

        PlayerInformation* GetPlayerInformation(char playerId);
        char GetPlayerIdFromPlayerObject(const hh::fnd::Handle<hh::fnd::Messenger>& playerObj);
        hh::fnd::Handle<hh::fnd::Messenger> GetPlayerObject(char playerId);
        csl::ut::MoveArray<hh::fnd::Handle<hh::fnd::Messenger>>& GetUIObjects();
        const char* GetStageName();
        unsigned int GetCyberStageIndex() const;

        GAMESERVICE_CLASS_DECLARATION(LevelInfo)
    };
}
