#pragma once

namespace hh::anim {
    class AnimationControl : public fnd::ReferencedObject {
    public:
        fnd::Reference<ResAnimation> resource;
        uint64_t unk2;
        uint64_t unk3;

        AnimationControl(csl::fnd::IAllocator* allocator);
        virtual void Update(float unkParam1) = 0;
        virtual void UnkFunc2(float unkParam1) = 0;
        virtual float UnkFunc3() const = 0;
        virtual void SetLocalTime(float unkParam1) = 0;
        virtual float GetLocalTime() const = 0;
        virtual void UnkFunc6() = 0;
        virtual void SetPlaybackSpeed(float unkParam1) = 0;
        virtual float GetPlaybackSpeed() const = 0;
        virtual void SetStartTime(float unkParam1) = 0;
        virtual float GetStartTime() const = 0;
        virtual void SetEndTime(float unkParam1) = 0;
        virtual float GetEndTime() const = 0;
        virtual void UnkFunc14(uint8_t* unkParam1) = 0;
        virtual void UnkFunc15(float unkParam1) = 0;
        virtual float UnkFunc16() const = 0;
        virtual bool UnkFunc17() const = 0;
        virtual bool IsPaused() const = 0;
        virtual void UnkFunc19(bool unkParam1) = 0;
        virtual void UnkFunc20(bool unkParam1) = 0;
    };
}
