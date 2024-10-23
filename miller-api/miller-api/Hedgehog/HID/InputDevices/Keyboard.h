#pragma once

namespace hh::hid {
    class Keyboard : public InputDevice {
        uint8_t unk1;
        bool unk2;
        csl::ut::InplaceMoveArray<uint32_t, 16> unk3;
        csl::ut::InplaceMoveArray<uint32_t, 4> unk4;
        char unk5[256];
    public:
        Keyboard(csl::fnd::IAllocator* pAllocator);
        
        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual float GetInputValue(unsigned int inputId) const override;
        virtual void Update(float unkParam) override;
        virtual bool UnkFunc7() const override;
        virtual uint64_t UnkFunc8() = 0;
        virtual const char* UnkFunc9() const;
        virtual unsigned int UnkFunc10();
    };
}
