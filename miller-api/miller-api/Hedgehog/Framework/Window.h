#pragma once

namespace hh::fw {
    class Window : public fnd::ReferencedObject {
    public:
        uint64_t hWnd;
        uint64_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        csl::ut::VariableString unk8;
        Window(csl::fnd::IAllocator* allocator);
        virtual uint64_t UnkFunc1() = 0;
        virtual void UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4();
        virtual void UnkFunc5() {}
        virtual void UnkFunc6() {}
        virtual void UnkFunc7() {}
        virtual void UnkFunc8() {}
        virtual bool UnkFunc9() { return false; }
        virtual bool UnkFunc10() { return false; }
        virtual void UnkFunc11() {}
        virtual void UnkFunc12() {}
        virtual bool UnkFunc13() { return true; }
        virtual void UnkFunc14() {}
        virtual void UnkFunc15() {}
        virtual bool UnkFunc16() { return false; }
        virtual void UnkFunc17() {}
    };
}
