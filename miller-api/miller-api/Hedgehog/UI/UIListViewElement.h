#pragma once

namespace hh::ui {
    class UIListViewElement;

    class UIListViewCursor : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        bool unk3;
        uint32_t unk4;
        void* unk5[7];
        UIListViewElement* listViewElement;
        fnd::Handle<SurfRideCastHandle> hCast;
        fnd::Reference<LayerController> layerController;
        float unk7[7]; // something with animations, see constructor
        uint32_t unk12;
        int unk13;
        int cursorIndex;
        fnd::Reference<CastTextContainer> castTextContainer;
    public:
        UIListViewCursor(csl::fnd::IAllocator* allocator, UIListViewElement* listViewelement, GOCSprite* gocSprite, SurfRide::Cast* cast);
    };

    class UIListViewItemView : public UIElement {
        int unk101;
        void* unk102[9];
        fnd::Handle<SurfRideCastHandle> hCast;
        LayerController* layerController;
        uint64_t unk105;
        CastTextContainer* castTextContainer;
        int unk107a;
        int unk107b;
        uint64_t unk108;
        UIListViewElement* listViewElement;
        uint16_t unk110;
        float unk111;
        uint32_t unk112;
        float unk113;
        csl::fnd::Delegate<void ()> unk114;
    public:
        UIListViewItemView(csl::fnd::IAllocator *pAllocator, int a3, GOCSprite* gocSprite, SurfRide::Cast* cast, hh::ui::UITextInterface textInterface, GOCUIComposition* gocUIComposition, UIListViewElement* listViewElement);
    };

    class UIListViewItemBase : public UIObject {
        UIListViewElement* listView;
        UIListViewItemView* view;
        uint64_t unk103;
        int32_t index;
        uint16_t unk105;
        bool unk106;
    public:
        UIListViewItemBase(csl::fnd::IAllocator* pAllocator);
        void SetListViewElement(hh::ui::UIListViewElement* listViewElement);
        void SetDimensions(const Dimensions& dimensions);
        virtual void* GetRuntimeTypeInfo() const;
        virtual void Update();
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
    };

    class UIListViewItem : public UIListViewItemBase {
        // Holds localization data when the item has no view.
        struct alignas(8) DeferredLocalizationInfo {
            struct alignas(8) TagInfo {
                enum class Type : uint32_t {
                    TEXT_DATA = 1,
                    LOCALIZATION_TAG = 2,
                    LOCALIZATION_TAG_AND_LOCALE_ID = 3,
                    CLEAR = 4,
                };

                Type type;
                csl::ut::VariableString elementName;
                csl::ut::VariableString tag;
                csl::ut::VariableString localeId;
                csl::ut::VariableString textDataUnk1;
                uint32_t unk6;
                uint64_t unk7;
                uint32_t textDataUnk2;

                void Clear();
            };

            struct alignas(8) VarInfo {
                uint32_t type;
                csl::ut::VariableString elementName;
                csl::ut::VariableString value;
                csl::ut::VariableString varName;
                uint32_t unk5;
                // some weird 32-bit movearray?
                uint32_t unk6;
                uint32_t unk7;
                uint32_t unk8; // 0x80000000
                csl::fnd::IAllocator* pAllocator;
                uint64_t unk9;

                void Clear();
            };

            csl::fnd::IAllocator* pAllocator;
            TagInfo tagInfo;
            csl::ut::MoveArray<VarInfo> varInfos;

            static VarInfo& CreateVarInfo(csl::ut::MoveArray<VarInfo>& infos, csl::fnd::IAllocator* allocator);
        public:
            DeferredLocalizationInfo(csl::fnd::IAllocator* pAllocator);

            void SetTextElementTextData(const char* unk1, int unk2);
            void SetNamedTextElementTextData(const char* name, const char* unk1, int unk2);

            void SetTextElementLocalizationTag(const char* tag);
            void SetNamedTextElementLocalizationTag(const char* name, const char* tag);

            void SetTextElementLocalizationTagAndLocaleId(const char* tag, const char* localeId);
            void SetNamedTextElementLocalizationTagAndLocaleId(const char* name, const char* tag, const char* localeId);

            void SetTextElementLocalizationVariable(const char* varName, const char* value);
            void SetNamedTextElementLocalizationVariable(const char* name, const char* varName, const char* value);

            void ClearTextElement();
            void ClearNamedTextElement(const char* name);
        };

        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        DeferredLocalizationInfo deferredLocalizationInfo;
    public:
        UIListViewItem(csl::fnd::IAllocator* pAllocator, uint64_t maybeUserDataOrIndex);

        UITextElement& GetTextElement();
        UITextElement& GetNamedTextElement(const char* name);

        void SetTextElementTextData(const char* unk1, int unk2);
        void SetNamedTextElementTextData(const char* name, const char* unk1, int unk2);

        void SetTextElementLocalizationTag(const char* tag);
        void SetNamedTextElementLocalizationTag(const char* name, const char* tag);

        void SetTextElementLocalizationTagAndLocaleId(const char* tag, const char* localeId);
        void SetNamedTextElementLocalizationTagAndLocaleId(const char* name, const char* tag, const char* localeId);

        void SetTextElementLocalizationVariable(const char* varName, const char* value);
        void SetNamedTextElementLocalizationVariable(const char* name, const char* varName, const char* value);

        void ClearTextElement();
        void ClearNamedTextElement(const char* name);

        virtual void* GetRuntimeTypeInfo() const;
        virtual void UnkFunc3();
        virtual void UnkFunc4();
    };

    struct ListViewEventArg {
    };

    class UIListViewElement : public UIElement {
        class alignas(8) ScrollController : public fnd::ReferencedObject {
            uint32_t unk1;
            uint32_t unk1b;
            uint64_t unk2;
            UIListViewElement* pListView;
            UIPanel* panel;
            uint16_t unk4;
            int16_t scrollPosition;
            uint16_t unk5;
            int16_t panelHeight;
            uint32_t unk6;
            bool enabled;
            uint32_t unk8;
            uint32_t unk9;
            int unk10;
        public:
            void ScrollTo(uint32_t scrollPosition);
        };
        
        class ScissorCastListener : public fnd::ReferencedObject, public SurfRide::CastListener {
            UIListViewElement* listView;

            /*
             * Loaded from user data:
             *
             *   SCISSOR:
             *     SCISSOR_OFFSET_L
             *     SCISSOR_OFFSET_T
             *     SCISSOR_OFFSET_R
             *     SCISSOR_OFFSET_B
             */
            ScissorOffsets offsets;
        };

        struct UIListViewLayout {
            struct Dimensions {
                uint32_t rows;              // User data ROWS
                uint32_t cols;              // User data COLS
                uint32_t width;             // User data WIDTH
                uint32_t height;            // User data HEIGHT
                uint32_t currentWidth;
                uint32_t currentHeight;
                uint32_t currentRows;
                uint32_t currentCols;
            };

            struct alignas(8) Options {
                bool sizeFixed;
                float scrollTime;           // User data SCROLL_TIME
                float grabAdjustScrollTime; // User data GRAB_ADJUST_SCROLL_TIME
                Dimensions dimensions;
                uint32_t scrollStartRow;
                int scrollBarMinSize;  // User data SCROLL_BAR_MIN_SIZE, max 100
                uint32_t scrollLargeChange; // User data SCROLL_LARGE_CHANGE
                bool scrollEnabled;         // User data SCROLL_ENABLED
                bool loopHorizontally;      // User data LOOP || LOOP_H
                bool loopVertically;        // User data LOOP || LOOP_V
                bool fixedLayout;           // User data FIXED_LAYOUT
                bool scrollStartFixed;      // User data SCROLL_START_FIXED
                bool waitItemActIn;         // User data WAIT_ITEM_ACT_IN
            };

            Options options;
            uint32_t documentWidth;
            uint32_t documentHeight;
            fnd::Handle<SurfRideCastHandle> unk42;
            UIPanel* panel;
            ScrollController* pScrollController;
            UIScrollBarElement* scrollBarElement;
            uint64_t unk45;
        };

        class CursorType : public fnd::ReferencedObject {
            char unk1;
            char unk2;
            bool unk3;
            csl::ut::VariableString name;
        };

        class Cursor : public fnd::ReferencedObject {
            fnd::Reference<CursorType> unk1;
            uint32_t index;
            bool unk3;
            csl::ut::VariableString unk4;
            fnd::Reference<UIListViewCursor> cursorElement;
        };

        struct CursorBinding {
            SurfRide::ReferenceCast* cast;
            Cursor* cursor;
        };

    public:

        csl::fnd::Delegate<void ()> unk15;
        csl::fnd::Delegate<void (UIListViewElement*, ListViewEventArg&)> onHighlightItem; // guessed at the moment
        csl::fnd::Delegate<void ()> unk17;
        csl::fnd::Delegate<void (UIListViewElement*, ListViewEventArg&)> onSelectItem; // guessed at the moment
        csl::fnd::Delegate<void ()> unk19;
        csl::fnd::Delegate<void (UIListViewElement*, bool)> onScroll;
        csl::ut::MoveArray<void*> unk21;
        csl::ut::MoveArray<void*> unk22;
        bool initialized;
        float unk24;
        UIListViewLayout layout;
        csl::ut::MoveArray<UIListViewItemView*> listViewItemViews;
        csl::ut::MoveArray<CursorBinding> cursorCasts; // casts that have a name that starts with "cursor"
        csl::ut::MoveArray<fnd::Reference<Cursor>> cursors;
        csl::math::Vector4 unk29;
        csl::math::Vector4 unk30;
        uint32_t scrollLargeChange;
        uint32_t unk31;
        float grabAdjustScrollTime;
        uint32_t unk32;
        bool unk33;
        bool scrollEnabled;
        bool fixedLayout;
        bool unk34;
        bool unk35;
        bool changingCursors;
        bool unk37;
        bool unk38;
        bool unk39;

        UIListViewElement(csl::fnd::IAllocator* pAllocator, SurfRide::Cast* cast, GOCUIComposition* gocUIComposition);
        void SetupLayout(SurfRide::Cast* cast);
        void AddItem(UIListViewItem* item);
        void Reset();
        int GetCurrentItemIndex();
        UIListViewItem* GetItem(uint32_t index);
        LayerController* GetItemLayerController(UIListViewItem* item);
        LayerController* GetCurrentItemViewLayerController();
        void NUnkFunc1(int a2, char a3, char a4);
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Update(const fnd::SUpdateInfo& updateInfo) override;
        virtual void UpdateAsync(const fnd::SUpdateInfo& updateInfo) override;
        virtual void Initialize() override;
        virtual void Deinitialize() override;
        virtual bool ProcessMessage(fnd::Message& message) override;
        virtual void ProcessActionInput(const game::InputListener::ActionInputInfo& actionInputInfo) override;
        virtual void ProcessAxisInput(const game::InputListener::AxisInputInfo& axisInputInfo) override;
        virtual bool IsVisible() const override { return true; }
        virtual bool UnkFunc14() override;
        virtual void OnEnabledChange() override;
        virtual void OnCollisionEnabledChange() override;
    };
}
