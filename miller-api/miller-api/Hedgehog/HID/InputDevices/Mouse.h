#pragma once

#ifdef RELATIVE
#undef RELATIVE
#endif

namespace hh::hid {
    class Mouse : public InputDevice {
    public:
        static constexpr unsigned int deviceId = 4;
        
        enum class InputId : uint32_t {
            AXIS_X = deviceId | 0,
            AXIS_Y = deviceId | 1,
            LBUTTON = deviceId | 2,
            RBUTTON = deviceId | 3,
            MBUTTON = deviceId | 4,
            BUTTON4 = deviceId | 5,
            BUTTON5 = deviceId | 6,
            BUTTON6 = deviceId | 7,
            ANY_BUTTON = deviceId | 8,
            UNK1 = deviceId | 9,
            SCROLL = deviceId | 10,
            SCROLL_UP = deviceId | 11,
            SCROLL_DOWN = deviceId | 12,
        };

        enum class Flag : uint8_t {
            UNK0,
            UPDATED,
            UNK1,
        };

        struct MouseState {
            enum class ButtonStateFlag : unsigned short {
                LEFT,
                RIGHT,
                MIDDLE,
                MEDIA_UP,
                MEDIA_DOWN,
            };
            csl::ut::Bitset<ButtonStateFlag> buttonState;
            unsigned short deltaX;
            unsigned short deltaY;
            unsigned short unk1;
            unsigned short unk2;
            uint8_t unk3;
        };

        csl::ut::Bitset<Flag> flags;
        MouseState state;
        csl::ut::InplaceMoveArray<InputId, 13> buttonInputIds;

        Mouse(csl::fnd::IAllocator* pAllocator);
        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual float GetInputValue(unsigned int inputId) const override;
        virtual void Update(float unkParam) override;
        virtual bool UnkFunc7() const override;
        virtual void UpdateMouseState(MouseState& state) const;
        virtual void CalculateNewState(MouseState& state) const = 0;
        virtual void SetCursorPosition(unsigned int x, unsigned int y) {}
        virtual bool GetCursorPosition(unsigned int* x, unsigned int* y) const;
        virtual bool GetCursorPositionDelta(unsigned int* x, unsigned int* y) const;
        virtual bool UnkFunc13() const { return false; }
        virtual void SetLockCursor(bool locked) {}
        virtual bool IsCursorLocked() const { return false; }
        virtual bool IsFlag4() const { return false; }
        virtual bool UnkFunc17() const { return false; }
        virtual void UnkFunc18(unsigned int x, unsigned int y) {}
    };
}
