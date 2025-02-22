#pragma once

namespace app::dv{
    class DvElementCaption : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class LanguageID : unsigned int {
                ENGLISH,
                FRENCH,
                ITALIAN,
                GERMAN,
                SPANISH,
                POLISH,
                PORTUGUESE,
                RUSSIAN,
                JAPANESE,
                CHINESE,
                CHINESE_SIMPLIFIED,
                KOREAN,
                THAI
            };

            char converseName[32];
            LanguageID languageId;
            int eventNameOffset;
            bool soundEnabled;
        private:
            char padding0[3];
        public:
            bool captionEnabled;
        private:
            char padding1[3];
        public:
            char soundName[32];
        };

        int unk0; // adds +1 whenver it appears

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCaption)
    };
}
