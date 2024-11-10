#pragma once

namespace hh::anim {
    class TransitionEffect : public fnd::ReferencedObject {
    public:
        struct Input {
            float unk1;
            float* unk2;
            float* unk3;
        };

        struct Output {
            float unk1;
            float unk2;
            float unk3;
            float unk4;
            float unk5;
            float unk6;
            float unk7;
            float unk8;
            bool unk9;
            bool unk10;
        };

        TransitionEasingType easingType;
        float duration;

        virtual void Activate() = 0;
        virtual void Update(const Input& input, Output* output) = 0;
        virtual bool IsStarted() const = 0;
        virtual bool IsDone() const = 0;
        virtual void SetTime(float time) = 0;
    };

    TransitionEffect* CreateTransitionEffect(TransitionType type, csl::fnd::IAllocator* allocator);
}
