#pragma once

namespace app::ui {
    class UIOptionMenuBase;

    class UIOptionSubConfig : public hh::game::GameObject {
    public:
        struct UnkStr {
            struct UnkStr0 {
                char data[84];
            };

            hh::fnd::Handle<hh::game::GameObject> uiOptionConfig;
            int dword4;
            hh::ui::GOCSprite* gocSprite;
            hh::ui::GOCUIComposition* gocUiComposition;
            hh::fnd::HandleBase dword18;
            int64_t qword20;
            int64_t qword28;
            char byte30[0x40];
            int64_t qword70;
            int64_t qword78;
            int64_t qword80;
            char byte88;
            int dword8C;
            char byte90[0x40];
            csl::ut::InplaceMoveArray<UnkStr0, 0x100> qwordD0;
        };

        csl::ut::MoveArray<int64_t> qword248;
        csl::ut::MoveArray<int64_t> qword268;
        UnkStr unkStr288;
        char byte5778;
        int dword577C;
        char byte5780[0x40];
        csl::ut::InplaceMoveArray<UnkStr::UnkStr0, 0x100> qwordD0;
        int64_t qwordABE0;
        int dwordABE8;
        int64_t qwordABF0;
        char byteABF8[0x40];
        int dwordAC38;
        int dwordAC3C;
        int dwordAC40;
        int byteAC44;
        int byteAC48;

        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION(UIOptionSubConfig);
    };

    class UIOptionConfig : public hh::game::GameObject, public hh::ui::UIListener {
    public:
        struct Option {
            char id;
            int64_t unk0;
            hh::fnd::Handle<hh::game::GameObject> subConfig;
        };

        struct Description {
            hh::fnd::Handle<hh::game::GameObject> uiOptionMenuBase;
            hh::ui::LayerController* uiOptions;
            hh::ui::LayerController* refOptionsTab;
            char byte268;
            int dword26C;
            char byte270;
        };

        Description description;
        int64_t qword278;
        int dword280;
        csl::ut::InplaceMoveArray<Option, 0x2A> options;
        hh::fnd::Handle<hh::game::GameObject> uiInputHelp;
        int64_t qword6A0;
        int64_t qword6A8;
        int dword6B0;

        void Setup(const Description& description);
        Option* GetOption(int id);

		virtual void AddCallback(hh::game::GameManager* gameManager) override;

        virtual void UOC_UnkFunc0() {}
        virtual void UOC_UnkFunc1() {}
        virtual void UOC_UnkFunc2() {}
        virtual void UOC_UnkFunc3() {}
        virtual void ApplyChanges() {}
        virtual void ResetOptions() {}
        virtual void InitUI() {}
        virtual char UOC_UnkFunc7(int optionIndex) { return 0; }
        virtual char UOC_UnkFunc8() { return 0; }
        virtual char UOC_UnkFunc9() { return 0; }
        virtual void GetDescriptionText(int64_t a2, char* a3);
        virtual bool IsIndexInRange(int optionIndex) { return false; }
        virtual char UOC_UnkFunc12() { return 0; }
        virtual char UOC_UnkFunc13() { return 0; }
        virtual int GetOptionCount() { return 0; }
        virtual int GetOptionID(int optionIndex) { return 0; }
        virtual char UOC_UnkFunc16() { return 0; }
        virtual char* UOC_UnkFunc17(); // RefCatLayerController name
        virtual char* GetOptionName(int optionIndex);
        virtual char* UOC_UnkFunc19();
        virtual char* UOC_UnkFunc20();
        virtual void UOC_UnkFunc21(int optionIndex, int64_t a3) {}
        virtual void OnValueChanged(int optionIndex, char value, bool unk) {}
        virtual void UOC_UnkFunc23() {}
        virtual void UOC_UnkFunc24() {}
        virtual void UOC_UnkFunc25() {}
        virtual void UOC_UnkFunc26() {}
        virtual void UOC_UnkFunc27(int a2, int a3, char a4);
        virtual void UOC_UnkFunc28() {}
        virtual void UOC_UnkFunc29() {}
        virtual void UOC_UnkFunc30() {}

        GAMEOBJECT_CLASS_DECLARATION_BASE(UIOptionConfig);
    };

    class UIOptionSoundConfig : public UIOptionConfig {
    public:
        virtual void ApplyChanges() override;
        virtual void ResetOptions() override;
        virtual void InitUI() override;
        virtual char UOC_UnkFunc7(int optionIndex) override;
        virtual bool IsIndexInRange(int optionIndex) override;
        virtual int GetOptionCount() override;
        virtual int GetOptionID(int optionIndex) override;
        virtual char* UOC_UnkFunc17() override; // RefCatLayerController name
        virtual char* GetOptionName(int optionIndex) override;
        virtual char* UOC_UnkFunc19() override;
        virtual void UOC_UnkFunc21(int optionIndex, int64_t a3) override;
        virtual void OnValueChanged(int optionIndex, char value, bool unk) override;

        GAMEOBJECT_CLASS_DECLARATION_BASE(UIOptionSoundConfig);
    };
}
