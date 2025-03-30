#pragma once

namespace app::ui {
    struct OverlayTextVariable {
        csl::ut::String tag;
        csl::ut::String value;
        bool translated;

        void SetTranslatedValue(const char* tag, const char* replaceLabel);
        void SetUntranslatedValue(const char* tag, const char* value);
    };

    class RequestOverlayTagReplace {
    public:
        csl::ut::MoveArray<OverlayTextVariable> variables;

        struct AddInfo {
            csl::fnd::IAllocator* allocator;
        };

        inline RequestOverlayTagReplace(csl::fnd::IAllocator* allocator) : variables{ allocator } {}
        OverlayTextVariable* AddVariable(const AddInfo& addInfo);
    };
}
