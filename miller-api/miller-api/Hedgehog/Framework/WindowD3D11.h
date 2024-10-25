#pragma once

namespace hh::fw {
    class FrameworkWin32;
    class WindowD3D11 : public Window {
        csl::ut::MoveArray<void*> unk100a;
        csl::ut::MoveArray<void*> unk100b;
        csl::ut::MoveArray<void*> unk100c;
        csl::ut::MoveArray<void*> unk101a;
        csl::ut::MoveArray<void*> unk101;
        csl::ut::MoveArray<void*> unk102;
        uint32_t unk103;
        uint32_t unk103a;
        uint16_t unk104;
        FrameworkWin32* framework;
        size_t hModule;
        uint32_t width;
        uint32_t height;
        int unk110;
        uint32_t unk110a;
        uint64_t unk111;
        uint32_t unk111a;
        uint32_t unk111b;
        uint32_t unk111c;

    public:
        static WindowD3D11* Create(csl::fnd::IAllocator* allocator);

        WindowD3D11(csl::fnd::IAllocator* allocator);
        virtual uint64_t UnkFunc1() override;
        virtual void UnkFunc2() override {}
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual void UnkFunc6() override;
        virtual void UnkFunc7() override;
        virtual void UnkFunc8() override;
        virtual bool UnkFunc9() override;
        virtual bool UnkFunc10() override;
        virtual void UnkFunc11() override;
        virtual void UnkFunc12() override;
        virtual bool UnkFunc13() override;
        virtual void UnkFunc14() override;
        virtual void UnkFunc15() override;
        virtual bool UnkFunc16() override;
        virtual void UnkFunc17() override;

        static LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    };
}
