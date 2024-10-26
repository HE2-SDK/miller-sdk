#pragma once

namespace hh::fnd {
    class UnpackedResourceContainer : public BaseObject {
    public:
        csl::ut::MoveArray<UniqueResourceContainer*> uniqueResourceContainers;
        csl::ut::PointerMap<const ResourceTypeInfo*, UniqueResourceContainer*> uniqueResourceContainersByTypeInfo;
        ResourceCriticalSection* resourceCriticalSection;

        UnpackedResourceContainer(csl::fnd::IAllocator* allocator);
        UniqueResourceContainer* CreateUniqueResourceContainer(const ResourceTypeInfo* typeInfo);
        const csl::ut::MoveArray<ManagedResource*>& GetResourcesByTypeInfo(const ResourceTypeInfo* typeInfo);
        void Initialize(ResourceCriticalSection* resourceCriticalSection); 
        void Clear();
    };
}
