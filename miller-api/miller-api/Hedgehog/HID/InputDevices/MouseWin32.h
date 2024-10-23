#pragma once

namespace hh::hid {
    class MouseWin32 : public Mouse, public hh::fw::MouseEventHandler {
    public:
        enum class Flag : uint8_t {
            UNK0,
            CURSOR_LOCKED,
            UNK2,
            UNK3,
            UNK4,
        };

        uint16_t absoluteX;
        uint16_t absoluteY;
        uint16_t deltaX;
        uint16_t deltaY;
        uint16_t prevX;
        uint16_t prevY;
        csl::ut::Bitset<MouseState::ButtonStateFlag> buttonState;
        uint16_t xPos;
        uint16_t unk105a;
        uint16_t yPos;
        uint16_t unk106a;
        csl::ut::Bitset<Flag> mouseWin32Flags;
        uint64_t unk108;
        HWND hWnd;
        csl::math::Vector4 unk112;
        uint32_t currentFSMState;
        uint32_t unk110a;
        uint32_t unk111;
        uint32_t unk111a;
        uint32_t unk113;
        float unk114;
        MouseWin32(csl::fnd::IAllocator* pAllocator);
        static MouseWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Update(float unkParam) override;
        virtual void UpdateMouseState(MouseState& state) const override;
        virtual void SetCursorPosition(unsigned int x, unsigned int y) override;
        virtual bool GetCursorPosition(unsigned int* x, unsigned int* y) const override;
        virtual bool GetCursorPositionDelta(unsigned int* x, unsigned int* y) const override;
        virtual void SetFlag0(bool unkParam) override;
        virtual void SetLockCursor(bool locked) override;
        virtual bool IsCursorLocked() const override;
        virtual bool IsFlag4() const override;
        virtual bool UnkFunc17() const override;
        virtual void UnkFunc18(unsigned int x, unsigned int y) override;
        virtual bool MEH_Unk1() override;
        virtual bool MEH_Unk2() override;
        virtual bool MEH_Unk3() override;
        virtual bool MEH_Unk4() override;
    };
}
