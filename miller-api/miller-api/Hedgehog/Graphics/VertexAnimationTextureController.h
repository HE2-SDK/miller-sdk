#pragma once

namespace hh::gfx {
    class VertexAnimationTextureController : public fnd::ReferencedObject {
    public:
        uint8_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        needle::AnimController animController;

        VertexAnimationTextureController(csl::fnd::IAllocator* allocator);
    };
}
