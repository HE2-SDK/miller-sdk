#pragma once

namespace hh::fw {
    class WindowD3D11UnkListener {
    public:
        virtual ~WindowD3D11UnkListener() = default;
        virtual void WD3D11UL_UnkFunc1() {}
    };

    class FrameworkWin32;
    class WindowD3D11 : public Window, public WindowD3D11UnkListener {
        csl::ut::MoveArray<void*> unk101;
        csl::ut::MoveArray<void*> unk102;
        uint8_t unk103;
        uint64_t unk104;
        FrameworkWin32* framework;
        size_t hModule;
        uint32_t unk107;
        uint32_t unk108;
        uint32_t unk108b;
        uint8_t unk109;
        uint32_t unk110;
        uint64_t unk111;
        uint64_t unk111b;
        uint32_t width;
        uint32_t height;
        uint8_t unk112;
        int unk113;
        uint32_t unk114;
        uint64_t unk115;
        uint8_t unk116;
    public:
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
