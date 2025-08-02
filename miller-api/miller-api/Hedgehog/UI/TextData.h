#pragma once

namespace hh::ui {
    class TextData : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<hh::fnd::Reference<PageInfo>> pages;

        CREATE_FUNC(TextData, const wchar_t* str, int size);

        void AddPage(PageInfo* page);
    };
}
