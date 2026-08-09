#pragma once

namespace app::ut {
    class Timer {
    public:
        float target;
        float current;

        Timer(float time);
        Timer();

        virtual void Update(float time);
        virtual void UnkFunc(); // called in Update when current+time >= target

        float GetTarget() const;
        float GetCurrent() const;
        float GetProgress();
        float GetRemaining() const;
        bool IsFinished() const;
        bool IsActive() const;
        void Reset();
        void ResetCurrent();
        void Set(float time);
        bool Add(float time);
    };
}
