#pragma once

namespace hh::fnd {
    class ResourceManager;
    class DynamicResourceContainer : public ResourceContainer {
        const ResourceTypeInfo* typeInfo;
        ResourceManager* resourceManager;
        FilePathResolver* filePathResolver;
        csl::ut::InplaceMoveArray<void*, 1> unk3;
        csl::ut::StringMap<void*> resourcesByName;
        csl::ut::MoveArray<ManagedResource*> resources;
        csl::fnd::Mutex mutex;
    public:
        DynamicResourceContainer(csl::fnd::IAllocator* allocator, const ResourceTypeInfo* typeInfo);
        void SetFilePathResolver(FilePathResolver* filePathResolver);

        const ResourceTypeInfo* GetTypeInfo() {
            return typeInfo;
        }

        virtual void* GetRuntimeTypeInfo() const override;
        virtual ManagedResource* GetResourceByName(const char* name) const override;
        virtual int GetNumResources() const override;
        virtual void LoadResource(csl::fnd::IAllocator* resourceAllocator, const char* name) override;
        virtual ManagedResource* GetResourceByIndex(int index) const override;
    };
}
