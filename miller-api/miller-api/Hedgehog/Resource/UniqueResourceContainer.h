#pragma once

namespace hh::fnd {
    class UniqueResourceContainer : public ResourceContainer {
        const ResourceTypeInfo* typeInfo;
        csl::ut::MoveArray<ManagedResource*> onceAddedResources; // I don't quite get it yet -- see AddResource
        csl::ut::MoveArray<ManagedResource*> twiceAddedResources;
        csl::ut::StringMap<ManagedResource*> addedResourcesByName;
    public:
        UniqueResourceContainer(csl::fnd::IAllocator* allocator, const ResourceTypeInfo* typeInfo);
        virtual void* GetRuntimeTypeInfo() const override;
        virtual ManagedResource* GetResourceByName(const char* name) const override;
        virtual int GetNumResources() const override;
        virtual ManagedResource* GetResourceByIndex(int index) const override;
    };
}
