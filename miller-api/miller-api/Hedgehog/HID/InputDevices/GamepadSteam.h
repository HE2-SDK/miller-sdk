#pragma once

namespace hh::hid {
    class GamepadSteam : public Gamepad {
        int32_t unk101;
        uint32_t unk102;
        int32_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint64_t unk106b;
        uint64_t unk107;
        uint64_t unk107b;
        uint64_t unk109;
        uint64_t unk110;
        uint64_t unk111;
        uint64_t unk112;
        uint64_t unk113;
        uint64_t unk114;
        uint64_t unk115;
        uint64_t unk116;
        uint64_t unk117;
        uint64_t unk117b;
        uint64_t unk118;
        char unk120[192];
        uint32_t unk121;
        uint32_t unk121b;
        uint32_t unk121c;
        bool unk122;
    public:
        GamepadSteam(csl::fnd::IAllocator* pAllocator, unsigned int deviceIndex);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Update(float unkParam) override;
        virtual int UnkFunc11() override;
        virtual bool UnkFunc12() override;
        virtual bool UnkFunc13() override;
        virtual uint64_t UnkFunc14() override;

        static GamepadSteam* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
    };
}
