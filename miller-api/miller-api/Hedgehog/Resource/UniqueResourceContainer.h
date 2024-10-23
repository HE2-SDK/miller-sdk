#pragma once

namespace hh::fnd {
    class UniqueResourceContainer : public ReferencedObject {
        csl::ut::MoveArray<ManagedResource*> onceAddedResources; // I don't quite get it yet -- see AddResource
        csl::ut::MoveArray<ManagedResource*> twiceAddedResources;
        csl::ut::StringMap<ManagedResource*> addedResourcesByName;
    public:
        UniqueResourceContainer(csl::fnd::IAllocator* allocator);
    };
}
