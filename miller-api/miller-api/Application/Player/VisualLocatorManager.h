#pragma once

namespace app::player {
    class GOCPlayerVisual;
    class VisualLocatorManager : public hh::fnd::ReferencedObject {
        GOCPlayerVisual* gocPlayerVisual;
        uint64_t unk1;
        uint64_t unk2;
        csl::math::Transform playerTransformBuf1;
        csl::math::Transform playerTransformBuf2;
        float unk5;
        float unk6;
        uint8_t unk7;
        csl::math::Transform playerTransform;
    public:
        VisualLocatorManager(csl::fnd::IAllocator* allocator, GOCPlayerVisual* gocPlayerVisual);

        void SetPlayerTransform(const csl::math::Transform& transform);
    };
}
