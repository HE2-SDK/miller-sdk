#pragma once

namespace hh::text {
    struct UnicodeString {
        const wchar_t* str;
        int size;
    };

    class ConverseDataCollection : public fnd::ReferencedObject {
        csl::ut::InplaceMoveArray<void*, 16> unk1;
        csl::ut::StringMap<ConverseData*> converseDatas;
        csl::fnd::Mutex mutex;
    public:
        ConverseDataCollection(csl::fnd::IAllocator* pAllocator);
        const ConverseData& GetTranslation(const char* tag);
    };
}
