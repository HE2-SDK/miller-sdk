#pragma once

namespace hh::hid {
    class VibrationWin32 : public Vibration {
        int64_t unk101;
        uint32_t unk102;
    public:
        VibrationWin32(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int UnkFunc10() override;
        virtual void UnkFunc11() override;
        virtual void UnkFunc12() override;
        virtual void UnkFunc13() override;

        static VibrationWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
    };
}
