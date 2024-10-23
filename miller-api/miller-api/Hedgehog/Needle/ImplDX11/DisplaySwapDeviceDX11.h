#pragma once

namespace hh::needle::ImplDX11 {
    class DisplaySwapDeviceDX11 : public DisplaySwapDevice {
    public:
        IDXGISwapChain* swapChain;
        intrusive_ptr<RenderTarget> backBuffers[1];

        DisplaySwapDeviceDX11(ID3D11Device* d3dDevice);

        virtual uint64_t UnkFunc0() override;
        virtual uint64_t UnkFunc00() override;
        virtual unsigned int UnkFunc1() override;
        virtual void UnkFunc2(uint8_t* unkParam1, uint8_t* unkParam2) override;
        virtual void* UnkFunc3() override;
        virtual bool ResizeBuffers(unsigned int* width, unsigned int* height) override;
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc7() override;
        virtual void SetFullScreenState(bool fullscreen) override;
        virtual bool GetFullScreenState() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual RenderTarget* GetBackBuffer(unsigned int id) override;
        virtual uint64_t UnkFunc14() override;
        virtual uint64_t UnkFunc15() override;
        virtual uint64_t UnkFunc16() override {}
        virtual bool Present(unsigned int flags) override;
        virtual uint64_t UnkFunc18() override;
        virtual uint64_t UnkFunc19() override;
    };
}
