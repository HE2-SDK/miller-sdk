#pragma once

namespace app::game {
    class GameModeResourceManager;
    class GameModeResourceModule : public hh::fnd::ReferencedObject {
    public:
        enum class Flag : uint8_t {
            DISABLED_MAYBE,
        };

        uint32_t unk1;
        uint32_t gameModeNameHash;
        uint32_t unk3;
        GameModeResourceManager* manager;
        csl::ut::String stageName;
        hh::fnd::Reference<hh::game::LevelLoader> levelLoader;
        csl::ut::Bitset<Flag> flags;
        uint8_t unk7;

        CREATE_FUNC(GameModeResourceModule, uint32_t)

        virtual unsigned int GetNameHash() = 0;
        virtual unsigned int UnkFunc2() = 0;
        virtual void Initialize() {}
        virtual uint64_t UnkFunc4() {}
        virtual void Load() {}
        virtual uint64_t UnkFunc6() {}
        virtual uint64_t UnkFunc7() {}
        virtual uint64_t UnkFunc8() {}
        virtual uint64_t UnkFunc9() {}
        virtual uint64_t UnkFunc10() {}
        virtual bool UnkFunc11() { return false; }
        virtual bool UnkFunc12() { return false; }

        void SetStageName(const char* name);
        void SetLevelLoader(hh::game::LevelLoader* levelLoader);
        level::StageData* GetStageData();
        void CallUnkFunc3();
    };
}
