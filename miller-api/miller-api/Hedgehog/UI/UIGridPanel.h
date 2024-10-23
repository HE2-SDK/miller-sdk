#pragma once

namespace hh::ui {
    class UIGridPanel : public UIPanel {
    public:
        struct Layout {
            uint32_t columns;
            uint32_t height;
            uint32_t width;

            Layout();
        };
    private:
        Layout layout;

    public:
        UIGridPanel(csl::fnd::IAllocator* pAllocator);
        void Initialize(const Layout& layout);
        virtual void LayoutChildren();
        virtual uint32_t GetWidth();
        virtual uint32_t GetHeight();
        virtual void GetChildCount();
    };
}
