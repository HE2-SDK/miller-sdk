#pragma once

namespace hh::fnd {
    class UnpackedResourceContainer : public BaseObject {
    public:
    private:
        csl::ut::MoveArray<UniqueResourceContainer*> uniqueResourceContainers;
        csl::ut::PointerMap<const ResourceTypeInfo*, UniqueResourceContainer*> uniqueResourceContainersByTypeInfo;
        ResourceCriticalSection* resourceCriticalSection;
    public:
        UnpackedResourceContainer(csl::fnd::IAllocator* allocator);
        UniqueResourceContainer* CreateUniqueResourceContainer(const ResourceTypeInfo* typeInfo);
        const csl::ut::MoveArray<ManagedResource*>& GetResourcesByTypeInfo(const ResourceTypeInfo* typeInfo);
        void Initialize(ResourceCriticalSection* resourceCriticalSection); 
        void Clear();
    };
}
