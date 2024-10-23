#pragma once

namespace hh::needle {
    class DisplaySwapDevice : public NeedleRefcountObject {
    public:
        virtual uint64_t UnkFunc0() = 0;
        virtual uint64_t UnkFunc00() = 0;
        virtual unsigned int UnkFunc1() = 0;
        virtual void UnkFunc2(uint8_t* unkParam1, uint8_t* unkParam2) = 0;
        virtual void* UnkFunc3() = 0;
        virtual bool ResizeBuffers(unsigned int* width, unsigned int* height) = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t UnkFunc7() = 0;
        virtual void SetFullScreenState(bool fullscreen) = 0;
        virtual bool GetFullScreenState() = 0;
        virtual uint64_t UnkFunc10() = 0;
        virtual uint64_t UnkFunc11() = 0;
        virtual uint64_t UnkFunc12() = 0;
        virtual RenderTarget* GetBackBuffer(unsigned int id) = 0;
        virtual uint64_t UnkFunc14() = 0;
        virtual uint64_t UnkFunc15() = 0;
        virtual uint64_t UnkFunc16() = 0;
        virtual bool Present(unsigned int flags) = 0;
        virtual uint64_t UnkFunc18() = 0;
        virtual uint64_t UnkFunc19() = 0;
    };
}
