#pragma once

namespace hh::snd {
    class SoundListenerHandle;
    class SoundHandle {
        hh::fnd::HandleBase handle;

    public:
        void Stop(float time);
        void StopImm();
        void Pause(bool unkParam, float time);
        void SetVolume(float volume);
        void SetBlockIdx(int idx);
        void SetBlockIdxByName(char const* name);
        unsigned int GetStatus() const;
        bool IsPlay() const;
        bool IsPause() const;
        bool IsLoop() const;
        void SetPosition(const csl::math::Vector3& position);
        void SetVelocity(const csl::math::Vector3& velocity);
        float GetDistance(const SoundListenerHandle& listener);
        float GetPlayTime() const;
        bool IsAisac() const;
        void SetAisac(const char* id, float value);
        void AttachAisac(const char* id);
        void DetachAisac(const char* id);
        void DetachAisacAll();
        void SetMultiTrackMode(bool unkParam);
        void SetTrackVolume(int track, float volume);
    };
}
