#pragma once

namespace hh::needle {
    class NeedleResContainer : public NeedleRefcountObject {
    public:
        template<typename T>
        class NeedleResourceHolder : public NeedleRefcountObject {
        public:
            csl::ut::PointerMap<CNameIDObject*, T*> resources;
        };

        csl::ut::PointerMap<CNameIDObject*, NeedleRefcountObject*> resourceHolders;
        csl::fnd::IAllocator* allocator;

        NeedleResContainer(csl::fnd::IAllocator* allocator);
    };
}
