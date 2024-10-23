#pragma once

namespace hh::gfx {
    class ScreenShotComponent : public RenderingComponent {
        class Impl : public fnd::ReferencedObject {
            uint64_t unk1;
            uint64_t unk2;
            char unk3a[260];
            char unk3[520];
            bool unk4;
            uint32_t unk5;
            bool unk6;
            uint64_t unk7; // function pointer 0x140D0CA40, set right after constructor
            uint64_t unk8; // function pointer 0x140D0CA30, set right after constructor
        };

        fnd::Reference<Impl> implementation;

    public:
        ScreenShotComponent(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc1() override {}
        virtual void UnkFunc2() override {}
        virtual void UnkFunc3() override {}
        virtual int UnkFunc4() override;
        virtual const char* GetName() override;
    };
}
