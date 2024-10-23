#pragma once

namespace hh::anim {
    class AsmControlCreator {
    public:
        static AnimationControl* Create(csl::fnd::IAllocator* allocator, const AsmResourceManager& asmResourceManager, int clipIndex, bool multiCycle);
    };
}
