#pragma once

namespace hh::ui {
    class alignas(8) UIStackPanel : public UIPanel {
    public:
        struct Layout {
            uint32_t width;

            Layout();
        };
    private:
        Layout layout;

    public:
        UIStackPanel(csl::fnd::IAllocator* pAllocator);
        void Initialize(const Layout& layout);
        virtual void LayoutChildren();
        virtual uint32_t GetWidth();
        virtual uint32_t GetHeight();
        virtual void GetChildCount();
    };
}