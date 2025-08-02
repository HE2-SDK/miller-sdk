#pragma once
#include <ucsl/resources/converse-text/v6.h>

namespace hh::text {
    using ucsl::resources::converse_text::v6::CnvrsTextData;

    struct UnicodeString {
        const wchar_t* str;
        int size;
    };

    class ConverseDataCollection : public fnd::ReferencedObject {
    public:
        csl::ut::InplaceMoveArray<CnvrsTextData*, 16> textResources;
        csl::ut::StringMap<ConverseData*> converseDatas;
        csl::fnd::Mutex mutex;
        
        ConverseDataCollection(csl::fnd::IAllocator* pAllocator);
        const ConverseData& GetTranslation(const char* tag);
    };
}
