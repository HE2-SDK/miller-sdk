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
    public:
        struct StyleParameters {
            csl::ut::MoveArray<hh::fnd::Reference<hh::fnd::ReferencedObject>> fonts;
            uint64_t qword20;
            uint8_t dword28;
            uint8_t dword29;
            uint8_t dword2A;
            uint8_t dword2B;
            float dword2C;
            float dword30;
            uint8_t byte34;
            uint8_t byte35;
            uint8_t byte36;
            uint8_t byte37;
            uint8_t byte38;
            uint8_t byte39;
            uint8_t byte3A;
            uint8_t byte3B;
            uint8_t byte3C;
            uint16_t byte3E;
            float unk1;
            uint32_t unk2;
            uint8_t unk3;
            heur::rfl::DecoTechParam decoTechParam;
            float dword160;
            float dword164;
            uint32_t dword168;
            uint32_t dword16C;
            uint64_t qword170;
            uint64_t qword178;
            int dword180;
            float dword184;
            float qword188;
            float qword18C;
            float unk4;

            StyleParameters(csl::fnd::IAllocator* allocator);
            inline ~StyleParameters() {
                RESOLVE_STATIC_VARIABLE(heur::rfl::DecoTechParam::typeInfo).m_fpCleaner(&decoTechParam);
            }
        };

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

        TextObjectUpdater(csl::fnd::IAllocator* pAllocator, UITextInterface* textInterface, GOCSprite* gocSprite, SurfRide::Cast* cast, void* unkParam1);
        void AddListener(TextObjectUpdaterListener* listener);
        void RemoveListener(TextObjectUpdaterListener* listener);
        void SetLocalizationVariable(const char* name, const char* value);
        void SetLocalizationTag(const char* name);
        void SetText(const char* text, unsigned int unkParam1);
        void Clear();
        bool LoadTextParameters(csl::ut::VariableString& text, StyleParameters& styleParams);
        void SetStyleParameters(const StyleParameters& styleParams);
        void Update();
        text::TagReplacer& GetTagReplacer();
    };
}
