#pragma once

namespace hh::hid {
    class Vibration : public InputDevice {
    public:
        Vibration(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual void UnkFunc8() {}
        virtual unsigned int UnkFunc9();
        virtual unsigned int UnkFunc10();
        virtual void UnkFunc11() {}
        virtual void UnkFunc12() {}
        virtual void UnkFunc13() {}
    };
}
