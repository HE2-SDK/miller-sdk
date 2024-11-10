#pragma once

namespace hh::anim {
    class AnimationControlPxd : public AnimationControl {
    public:
        bool paused;
        float localTime;
        float playbackSpeed;
        float startPadding;
        float endPadding;
        int unk105;
        float unk106;
        float unk107;
        csl::ut::MoveArray<void*> unk108;
        uint64_t unk109;

        DEFAULT_CREATE_FUNC(AnimationControlPxd);
        virtual void Update(float time) override;
        virtual void UnkFunc2(float unkParam1) override;
        virtual float UnkFunc3() const override;
        virtual void SetLocalTime(float time) override;
        virtual float GetLocalTime() const override;
        virtual void UnkFunc6() override;
        virtual void SetPlaybackSpeed(float speed) override;
        virtual float GetPlaybackSpeed() const override;
        virtual void SetStartTime(float time) override;
        virtual float GetStartTime() const override;
        virtual void SetEndTime(float unkParam1) override;
        virtual float GetEndTime() const override;
        virtual void UnkFunc14(uint8_t* unkParam1) override;
        virtual void UnkFunc15(float unkParam1) override;
        virtual float UnkFunc16() const override;
        virtual bool UnkFunc17() const override;
        virtual bool IsPaused() const override;
        virtual void UnkFunc19(bool unkParam1) override;
        virtual void UnkFunc20(bool unkParam1) override;
    };
}
