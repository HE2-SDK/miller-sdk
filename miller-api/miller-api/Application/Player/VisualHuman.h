#pragma once

namespace app::player {
    class VisualHuman : public PlayerVisual, public hh::anim::TriggerListener {
    public:
        uint64_t unk101;
        uint32_t unk102;
        hh::fnd::HFrame* unkFrames[22];
        uint8_t unk104;

        VisualHuman(csl::fnd::IAllocator* allocator);
        
        
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc7() override;
        virtual uint64_t UnkFunc8() override;
        virtual uint64_t UnkFunc9() {}
        virtual uint64_t UnkFunc10() {}
        virtual uint64_t UnkFunc11() {}
        virtual uint64_t UnkFunc12() {}
        virtual void TL_MaybeOnTrigger() override;
    };
}