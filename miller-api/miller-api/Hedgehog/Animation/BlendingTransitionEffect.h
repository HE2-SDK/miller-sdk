#pragma once

namespace hh::anim {
    class BlendingTransitionEffect : public TransitionEffect {
    public:
        enum class StartMode : uint8_t {
            NORMAL,
            REVERSE,
        };

        enum class StepMode : uint8_t {
            UNK_0,
            UNK_1,
            UNK_2,
        };

        StartMode startMode;
        StepMode stepMode1;
        StepMode stepMode2;
        float time;

        CREATE_FUNC(BlendingTransitionEffect, StartMode startMode, StepMode stepMode1, StepMode stepMode2);

        virtual void Activate() override;
        virtual void Update(const Input& input, Output* output) override;
        virtual bool IsStarted() const override;
        virtual bool IsDone() const override;
        virtual void SetTime(float time) override;
    };
}
