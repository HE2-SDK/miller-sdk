#pragma once

namespace app::ui {
    class RequestOverlayWindow : public RequestOverlayBegin, public RequestOverlayTagReplace {
    public:
        uint8_t unk101;
        uint8_t unk102;
        csl::ut::String header;
        csl::ut::String text;
        bool unk107;
        bool unk108;
        bool unk109;

        DEFAULT_CREATE_FUNC(RequestOverlayWindow);
    };
}
