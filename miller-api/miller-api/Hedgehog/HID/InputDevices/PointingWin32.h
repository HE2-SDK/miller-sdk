#pragma once

namespace hh::hid {
    class PointingWin32 : public Pointing {
    public:
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
        };
    private:
        csl::ut::InplaceMoveArray<Unk1, 1> unk1;
    public:
        PointingWin32(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual csl::math::Vector4 GetTarget1(unsigned int inputId) const override;
        virtual void UnkFunc8() override;
        virtual unsigned int UnkFunc9() override;
        virtual unsigned int UnkFunc11() override;
        virtual bool UnkFunc12() override;
        virtual csl::math::Vector2 UnkFunc13() override;
        virtual bool UnkFunc14() override { return true; }

        static PointingWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
    };
}
