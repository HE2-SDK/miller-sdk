#pragma once

namespace app::game {
    class GameModeLayerStatusExtension : public GameModeExtension {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
        };

        struct Unk2 {
            float timeScale;
            uint64_t unk1;
            float incrementPerSecond;
            float currentDelta;
            csl::fnd::Delegate<void (uint64_t, const float&)> unk3;
        };

        struct TimeScaleInterpolator {
            csl::ut::MoveArray<Unk2> unk1;
            float (*interpolationFunction)(float* from, float* to, float delta);
            float timeScale;
        };

        uint64_t unk1;
        uint64_t unk1a;
        csl::ut::MoveArray<Unk1> layersActiveDuringNormalOperation;
        csl::ut::MoveArray<Unk1> layersActiveDuringIngamePause;
        csl::ut::MoveArray<TimeScaleInterpolator> timeScaleInterpolators;
        TimeScaleInterpolator globalInterpolator;
        csl::ut::MoveArray<TimeScaleInterpolator> unk2;
        
        DEFAULT_CREATE_FUNC(GameModeLayerStatusExtension);

        virtual unsigned int GetNameHash() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual uint64_t UnkFunc1() override;
    };
}
