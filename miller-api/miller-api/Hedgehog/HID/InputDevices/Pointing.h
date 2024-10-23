#pragma once

namespace hh::hid {
    class Pointing : public InputDevice {
    public:
        Pointing(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual void UnkFunc8() {}
        virtual unsigned int UnkFunc9();
        virtual unsigned int UnkFunc10();
        virtual unsigned int UnkFunc11();
        virtual bool UnkFunc12() { return false; }
        virtual csl::math::Vector2 UnkFunc13();
        virtual bool UnkFunc14() { return false; }
    };
}
