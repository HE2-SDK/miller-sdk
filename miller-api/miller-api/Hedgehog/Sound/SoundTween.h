#pragma once

namespace hh::snd {
    struct SoundTween {
        float duration;
        float startRatio;
        float targetRatio;
        float ratio;
        float step;
        unsigned int state;
    };

    void ResetTween(SoundTween* tween, float ratio, bool running);
    bool MoveToTween(SoundTween* tween, float duration, float ratio);
    bool MoveToTweenReset(SoundTween* tween, float duration, float ratio);
    bool UpdateTween(SoundTween* tween, float duration, float ratio);
    bool IsUpdateTween(const SoundTween* tween);
    float GetValueTween(const SoundTween* tween);
}
