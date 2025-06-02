#pragma once

namespace hh::text {
    class TextLanguageData : public fnd::ReferencedObject {
    public:
        csl::ut::VariableString probablyLocaleId;
        int index;
        csl::ut::StringMap<void*> unk3;
        csl::ut::StringMap<void*> unk4;
        ConverseDataCollection* converseDataCollection;
        csl::fnd::Mutex mutex;

        TextLanguageData(csl::fnd::IAllocator* pAllocator, const char* probablyLocaleId, int index);
        const ConverseData& GetTranslation(const char* tag);
    };
}
