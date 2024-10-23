#pragma once

namespace hh::fnd {
    class ResourceCriticalSection : public ReferencedObject {
    public:
        struct LockItem : public ReferencedObject {
            const ResourceTypeInfo* typeInfo;
            csl::fnd::Mutex mutex;
        };
    private:
        csl::ut::MoveArray<LockItem*> lockItems;
        csl::ut::PointerMap<ResourceTypeInfo*, LockItem*> lockItemsByTypeInfo;
    public:
        ResourceCriticalSection(csl::fnd::IAllocator* allocator);
        void Initialize();
    };
}
