#pragma once

namespace hh::fnd {
    class ResourceResolver {
    public:
        virtual ~ResourceResolver() {};
        virtual ManagedResource* Resolve(csl::fnd::IAllocator* allocator, const char* name, const ResourceTypeInfo* typeInfo) = 0;
    };

    class ResourceManagerResolver : public ResourceResolver {
    public:
        ResourceManagerResolver() {}
        virtual ManagedResource* Resolve(csl::fnd::IAllocator* allocator, const char* name, const ResourceTypeInfo* typeInfo) override;
        
        //  {
        //     return ResourceManager::GetInstance()->GetResource(name, typeInfo);
        // }
    };
}
