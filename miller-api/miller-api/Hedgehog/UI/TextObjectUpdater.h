#pragma once

namespace hh::ui {
    class TextObjectUpdaterListener {
    public:
        virtual ~TextObjectUpdaterListener();
        virtual void TOUL_UnkFunc1() {}
        virtual void TOUL_UnkFunc2() {}
    };

    class UIManager;
    class TextObjectUpdater : public fnd::ReferencedObject {
        void* unknownListenerVftable;
        csl::ut::MoveArray<void*> unk1; // delegates
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::MoveArray<void*> unk5;
        bool unk6;
        fnd::Handle<SurfRideCastHandle> hCast;
        csl::ut::VariableString unk7;
        UITextInterface* textInterface;
        fnd::Handle<GOCSprite> hGOCSprite;
        hh::ui::UIManager* uiManager;
        uint64_t unk8;
        uint64_t unk9;
        uint64_t unk10;
        uint64_t unk11;
        void* unk12; // set in constructor
        text::TagReplacer* tagReplacer;
        csl::ut::MoveArray<TextObjectUpdaterListener*> listeners;
        bool unk15a;
        bool unk15b;
        uint32_t unk16;
    public:
        TextObjectUpdater(csl::fnd::IAllocator* pAllocator, UITextInterface* textInterface, GOCSprite* gocSprite, SurfRide::Cast* cast, void* unkParam1);
        void RegisterListener(TextObjectUpdaterListener* listener);
        void UnregisterListener(TextObjectUpdaterListener* listener);
        void SetLocalizationVariable(const char* name, const char* value);
        void SetLocalizationTag(const char* name);
        void SetText(const char* text, unsigned int unkParam1);
        text::TagReplacer& GetTagReplacer();
    };
}
