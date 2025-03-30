#pragma once

namespace app::ui {
    struct CaptionCollection {
        struct Caption {
            csl::ut::String label;
            csl::ut::String cue;
            float duration;
            unsigned int unk1;
        };

        struct AddInfo {
            csl::fnd::IAllocator* allocator;
        };

        csl::ut::MoveArray<Caption> items;

        CaptionCollection(csl::fnd::IAllocator* allocator) : items{ allocator } {}
        Caption* Add(const AddInfo& addInfo);
    };

    struct CaptionInfo {
        CaptionCollection captions;
        uint8_t unk202{};
        uint8_t unk203{};
        uint8_t unk204{};
        uint8_t unk205{};
        uint8_t unk206{};
        uint8_t unk207{ 2 };
        uint8_t unk208{ 20 };
        uint8_t unk209{ 1 };

        CaptionInfo(csl::fnd::IAllocator* allocator) : captions{ allocator } {}
    };

    class RequestOverlayCaption : public RequestOverlayBegin, public RequestOverlayTagReplace, public CaptionInfo {
    public:
        inline RequestOverlayCaption(csl::fnd::IAllocator* allocator)
            : RequestOverlayBegin{ allocator, OverlayType::CAPTION }, RequestOverlayTagReplace{ allocator }, CaptionInfo{ allocator }
        {}

        inline static RequestOverlayCaption* Create(csl::fnd::IAllocator* allocator) {
            return new (allocator) RequestOverlayCaption{ allocator };
        }
    };
}
