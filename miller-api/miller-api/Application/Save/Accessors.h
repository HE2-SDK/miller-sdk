#pragma once

namespace app::save {
    class CRMContainerAc : public app::save::SaveDataAccessor<app::save::CRMContainerData> {
    public:
    };

    class CharacterAc : public app::save::SaveDataAccessor<app::save::CharacterData> {
    public:
    };

    class CollectionDataAc : public app::save::SaveDataAccessor<app::save::CollectionData> {
    public:
    };

    class FlagContainerAc : public app::save::SaveDataAccessor<app::save::FlagContainerData> {
    public:
    };

    class GameDataAc : public app::save::SaveDataAccessor<app::save::GameData> {
    public:
    };

    class GamePlayAc : public app::save::SaveDataAccessor<app::save::GamePlayData> {
    public:
    };

    class HeaderAc : public app::save::SaveDataAccessor<app::save::HeaderData> {
    public:
    };

    class NoSaveDataAc : public app::save::SaveDataAccessor<app::save::NoSaveData> {
    public:
    };

    class OptionAudioAc : public app::save::SaveDataAccessor<app::save::OptionAudioData> {
    public:
    };

    class OptionCameraAc : public app::save::SaveDataAccessor<app::save::OptionCameraData> {
    public:
    };

    class OptionControlsAc : public app::save::SaveDataAccessor<app::save::OptionControlsData> {
    public:
    };

    class OptionGamePlayAc : public app::save::SaveDataAccessor<app::save::OptionGamePlayData> {
    public:
    };

    class OptionGraphicsAc : public app::save::SaveDataAccessor<app::save::OptionGraphicsData> {
    public:
    };

    class PlayLogAc : public app::save::SaveDataAccessor<app::save::PlayLogData> {
    public:
    };

    class QADataAc : public app::save::SaveDataAccessor<app::save::QAData> {
    public:
    };

    class RankingAc : public app::save::SaveDataAccessor<app::save::RankingData> {
    public:
    };

    class RankingContainerAc : public app::save::SaveDataAccessor<app::save::RankingContainerData> {
    public:
    };

    class StageAc : public app::save::SaveDataAccessor<app::save::StageData> {
    public:
    };

    class StageContainerAc : public app::save::SaveDataAccessor<app::save::StageContainerData> {
    public:
    };

    class StatsContainerAc : public app::save::SaveDataAccessor<app::save::StatsContainerData> {
    public:
    };

    class SystemAc : public app::save::SaveDataAccessor<app::save::SystemData> {
    public:
    };

    class WorldFlagAc : public app::save::SaveDataAccessor<app::save::WorldFlagData> {
    public:
    };

    class WorldFlagContainerAc : public app::save::SaveDataAccessor<app::save::WorldFlagContainerData> {
    public:
    };
}
