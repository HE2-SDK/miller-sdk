#pragma once

namespace hh::needle {
    class AnimController {
    public:
        uint8_t unk1;
        bool unk2;
        float unk3;
        float start;
        float end;
        float fps;
        float unk5;
        float unk6;
        uint32_t unk7;

        AnimController();
        virtual ~AnimController() = default;
        virtual void UnkFunc1(float unkParam);
        virtual void SetUnk2();

        void SetAnimationParameters(float start, float end, float fps);
    };
}
