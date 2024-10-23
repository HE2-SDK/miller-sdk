#pragma once

namespace hh::ui {
    class alignas(8) UIPanel : public fnd::ReferencedObject {
        csl::ut::MoveArray<UIObject*> children;
    public:
        UIPanel(csl::fnd::IAllocator* pAllocator);
        void Clear();
        void AddChild(UIObject* child);
        virtual void LayoutChildren() = 0;
        virtual uint32_t GetWidth() = 0;
        virtual uint32_t GetHeight() = 0;
        virtual void GetChildCount() = 0;
    };
}