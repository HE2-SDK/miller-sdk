#pragma once

namespace hh::ui {
    class alignas(8) UIPanel : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<hh::fnd::Reference<UIObject>> children;

        UIPanel(csl::fnd::IAllocator* pAllocator);
        void Clear();
        void AddChild(UIObject* child);
        virtual void LayoutChildren() = 0;
        virtual uint32_t GetWidth() = 0;
        virtual uint32_t GetHeight() = 0;
        virtual void GetChildCount() = 0;
    };
}
