#pragma once

namespace hh::text {
    class TextLanguageDataCollection : public fnd::ReferencedObject {
        csl::ut::MoveArray<TextLanguageData*> textLanguageData;
        csl::ut::StringMap<TextLanguageData*> textLanguageDataByLocaleId;
    public:
        TextLanguageDataCollection(csl::fnd::IAllocator* pAllocator);

        TextLanguageData* CreateTextLanguageData(const char* localeId, int index);
        TextLanguageData* GetTextLanguageDataByIndex(int index);
        TextLanguageData* GetTextLanguageDataByLocaleId(const char* localeId);
    };
}
