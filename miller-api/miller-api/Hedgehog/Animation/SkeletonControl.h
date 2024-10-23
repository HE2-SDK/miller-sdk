#pragma once

namespace hh::anim {
    class SkeletonControl {
    public:
        static AnimationControlPxd* Create(csl::fnd::IAllocator* allocator, ResAnimation* resource, bool multiCycle);
    };
}
