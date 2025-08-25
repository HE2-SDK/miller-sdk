#pragma once

namespace hh::anim {
    class SkeletalMeshBinding : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
    public:
        SkeletalMeshBinding(csl::fnd::IAllocator* allocator, fnd::ManagedResource* pose, gfx::ResModel* model);
    };
}
