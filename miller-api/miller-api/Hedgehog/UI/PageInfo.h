#pragma once

namespace hh::ui {
    class PageInfo : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<const wchar_t> str;
        bool isDebug;
    };
}
