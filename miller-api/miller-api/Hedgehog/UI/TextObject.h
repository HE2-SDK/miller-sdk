#pragma once

namespace hh::ui {
    struct TextStyleParameters {
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
        uint8_t byte3D;
        uint8_t byte3E;
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

        TextStyleParameters(csl::fnd::IAllocator* allocator);
        inline ~TextStyleParameters() {
            RESOLVE_STATIC_VARIABLE(heur::rfl::DecoTechParam::typeInfo).m_fpCleaner(&decoTechParam);
        }
    };

    class TextTextureBuilder : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<void*> unk1;
        void* unk2[2];
        void* unk3[2];
        void* unk4[2];
        uint64_t qword68;
        uint32_t dword70;
        bool debugModeEnabled;
        uint32_t dword78;
        heur::rfl::DecoTechParam decoTechParam;
        uint64_t unk5;
        csl::ut::VariableString unk6;

        DEFAULT_CREATE_FUNC(TextTextureBuilder);
        void SetDebugModeEnabled(bool enabled);
    };

    class TextObjectPage : public fnd::ReferencedObject {
    public:
        unsigned int index;
        hh::fnd::Reference<hh::ui::PageInfo> pageInfo;
        uint64_t unk0;
        hh::fnd::Reference<TextTextureBuilder> textureBuilder;

        CREATE_FUNC(TextObjectPage, unsigned int index, TextData* textData);
    };

    class TextObjectPageCollection : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<hh::fnd::Reference<TextObjectPage>> pages;

        DEFAULT_CREATE_FUNC(TextObjectPageCollection);

        void SetTextData(TextData* textData);
    };

    class TextObject : public fnd::ReferencedObject, public font::TextListener, public font::TextTagWriterFeedListener {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint32_t unk6;
            uint32_t unk7;

            Unk1();
        };

        struct Unk2 {
            csl::ut::MoveArray<void*> unk1;
            uint16_t word20;
            uint8_t byte22;
            uint32_t dword24;
            uint32_t dword28;
            csl::math::Vector2 vec2C;
            csl::math::Vector2 vec34;
            csl::math::Vector2 vec3C;
            csl::math::Vector2 vec44;

            DEFAULT_CREATE_FUNC(Unk2);
        };

        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        TextStyleParameters styleParameters;
        hh::fnd::Reference<TextData> textData;
        hh::fnd::Reference<TextObjectPageCollection> pageCollection;
        int qword248;
        uint32_t qword24C;
        uint8_t byte250;
        uint8_t byte251;
        uint8_t word252;
        uint8_t word253;
        uint16_t word254;
        uint32_t dword258;
        uint16_t word25C;
        uint8_t byte25E;
        uint64_t qword260;
        uint64_t qword268;
        Unk1 char270[4];
        Unk1 char2E0[4];
        uint64_t qword350;
        Unk2 unk358;
        csl::ut::MoveArray<void*> unk3A8;
        csl::ut::MoveArray<void*> unk3C8;
        hh::fnd::Reference<TextListenerObject> textListenerObject;
        hh::fnd::Reference<hh::text::ConverseTextListener> converseTextListener;
        hh::fnd::Reference<hh::text::TagReplaceableCollection> tagReplaceableCollection1;
        hh::fnd::Reference<hh::text::TagReplaceableCollection> tagReplaceableCollection2;
        float dword408;
        csl::ut::VariableString str410;

        CREATE_FUNC(TextObject, TextData* textData);

        virtual bool TL_UnkFunc1(void* unkParam1, void* unkParam2) override;
        virtual int TL_UnkFunc2() override;
        virtual void TTWFL_UnkFunc1() override;
        virtual void TTWFL_UnkFunc2() override;
        virtual void TTWFL_UnkFunc3() override;
        virtual void TTWFL_UnkFunc4() override;

        void SetTextData(TextData* textData);
        void SetStyleParameters(const TextStyleParameters& styleParams);
    };
}
