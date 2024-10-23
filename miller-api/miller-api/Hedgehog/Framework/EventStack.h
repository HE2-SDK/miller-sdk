#pragma once

namespace hh::fw {
    struct KeyEventArgs {
        uint16_t scanCode; // USB HID scancode
        uint8_t unk2;
        uint16_t modifier;
        uint16_t unk4;
    };

    class KeyEventHandler {
    public:
        virtual ~KeyEventHandler() = default;
        virtual bool OnKeyDown(KeyEventArgs& keyEventArgs) { return false; }
        virtual bool OnKeyUp(KeyEventArgs& keyEventArgs) { return false; }
        virtual bool OnKeyPressed(KeyEventArgs& keyEventArgs) { return false; } // This also gets triggered right after OnKeyDown?
        virtual bool OnKeyEvent() { return false; }
    };

    class MouseEventHandler {
    public:
        virtual ~MouseEventHandler() = default;
        virtual bool MEH_Unk1() { return false; }
        virtual bool MEH_Unk2() { return false; }
        virtual bool MEH_Unk3() { return false; }
        virtual bool MEH_Unk4() { return false; }
        virtual bool MEH_Unk5() { return false; }
    };

    class EventStack : public fnd::ReferencedObject {
        struct KeyEventHandlerInfo {
            KeyEventHandler* handler;
            uint32_t unk1;
            uint32_t unk2;
        };

        struct MouseEventHandlerInfo {
            MouseEventHandler* handler;
            uint32_t unk1;
            uint32_t unk2;
        };

        csl::ut::MoveArray<KeyEventHandlerInfo> keyEventHandlers;
        csl::ut::MoveArray<MouseEventHandlerInfo> mouseEventHandlers;
    public:
        EventStack(csl::fnd::IAllocator* allocator, void* unkParam1, void* unkParam2);
        void AddKeyEventHandler(KeyEventHandler* handler, int unkParam1, uint32_t unkParam2);
        void RemoveKeyEventHandler(KeyEventHandler* handler);
        void AddMouseEventHandler(MouseEventHandler* handler, int unkParam1, uint32_t unkParam2);
        void RemoveMouseEventHandler(MouseEventHandler* handler);

        void FireOnKeyDown(KeyEventArgs& keyEventArgs, uint8_t& mask);
        void FireOnKeyUp(KeyEventArgs& keyEventArgs, uint8_t& mask);
        void FireOnKeyPressed(KeyEventArgs& keyEventArgs, uint8_t& mask);
    };
}
