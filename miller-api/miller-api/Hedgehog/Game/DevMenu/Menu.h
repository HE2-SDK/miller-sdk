#pragma once

namespace hh::game::dmenu {
    class Menu;
    struct Color {
        uint8_t a;
        uint8_t b;
        uint8_t g;
        uint8_t r;
    };
    class CallbackBase {
        void* unk[6];
    public:
        virtual ~CallbackBase();
    };
    class Text {
        char dirty;
        char unk1a;
        uint16_t unk1b;
        uint32_t unk1c;
        uint64_t unk2;
        uint64_t unk3;
        float maybex;
        float maybey;
        uint8_t unk4;
        uint8_t unk4b;
        uint8_t unk4c;
        uint8_t unk4d;
        uint64_t unk5;
        csl::fnd::IAllocator* allocator;
    public:
        Text(csl::fnd::IAllocator* allocator);
        virtual ~Text();
    };
    class Object {
        csl::fnd::IAllocator* allocator;
    public:
        virtual ~Object();
    };
    class Item : public Object {
        uint16_t unk1;
        uint64_t unk2;
        CallbackBase cb1;
        CallbackBase cb2;
        CallbackBase cb3;
        CallbackBase cb4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        uint32_t unk8;
        uint32_t unk9;
        uint64_t unk10;
        uint32_t unk11;
        csl::ut::MoveArray<Item*> children;
        csl::ut::VariableString unk13;
        Text text;
        float unk14;
        float unk15;
        Color targetColor;
    public:
        Item(csl::fnd::IAllocator* allocator, const char* text);

        void SetOpacity(uint8_t opacity, bool immediate);
        void SetVisibility_(bool visible);
        Item* GetChild(int idx);

        virtual void SetUnk10(); //maybe parent
        virtual void GetX();
        virtual void GetY();
        virtual void CallCB1();
        virtual void CallCB2();
        virtual void CallCB3();
        virtual void CallCB4();
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void GetUnk13();
        virtual void SetVisibility(bool visible);
        virtual void SetUnk3();
        virtual void SetColor(const Color& colorMaybe);
        virtual void Render();
        virtual int UnkFunc6() { return 0; }
    };
    class ContextMenu {
    public:
        class ItemContainer : public fnd::ReferencedObject {
            Menu* menu;
            Item* item;
            float unk2;
            int32_t itemUnk9;
            int32_t itemUnk10;
            int32_t unk5;
            int32_t unk6;
            int32_t unk7;
            int32_t unk8;
            int32_t unk9;
            int32_t unk10;
            uint16_t unk11;
        public:
            int GetChildCount();
        };
    };
    class DefaultControl : public fnd::ReferencedObject {
    public:
        void* wut;
        InputComponent* inputComponent;
        DefaultControl(csl::fnd::IAllocator* allocator, InputManager* inputManager);

        virtual void UnkFunc1();
        virtual void SetInputEnabled(bool unkParam1);
    };
    class Menu : public fnd::ReferencedObject {
    public:
        uint16_t unk1;
        bool unk2;
        Item* item_1;
        Item* item_2;
        ContextMenu::ItemContainer* itemContainer;
        fnd::Reference<DefaultControl> control;
        uint64_t renderable;
        Menu(csl::fnd::IAllocator* allocator, InputManager* inputManager);
    };
}
