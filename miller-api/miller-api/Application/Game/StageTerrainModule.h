#pragma once

namespace app::trr {
    class TerrainManager;
}

namespace app::game {
    class StageTerrainModule : public GameModeResourceModule {
    public:
        struct SetupInfo {
            bool unk1;
            uint64_t unk2;
            uint64_t unk3;
        };

        enum class StageTerrainModuleFlag : uint8_t {
            UNK0,
            SECTORS_LOADED,
            TERRAIN_MANAGER_INITIALIZED,
            UNK3,
        };

        trr::TerrainManager* terrainManager;
        csl::ut::InplaceMoveArray<uint8_t, 100> staticSectors;
        csl::ut::InplaceMoveArray<uint8_t, 100> dynamicSectors;
        csl::ut::Bitset<StageTerrainModuleFlag> stageTerrainModuleFlags;

        DEFAULT_CREATE_FUNC(StageTerrainModule)

        virtual unsigned int GetNameHash() override;
        virtual unsigned int UnkFunc2() override { return 0; }
        virtual void Initialize() override;
        virtual void Load() override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc7() override;
        virtual uint64_t UnkFunc8() override {}
        virtual uint64_t UnkFunc9() override {}
        virtual uint64_t UnkFunc10() override;
        virtual bool UnkFunc11() override;
        virtual bool UnkFunc12() override;

        void Setup(const SetupInfo& setupInfo);
    };
}
