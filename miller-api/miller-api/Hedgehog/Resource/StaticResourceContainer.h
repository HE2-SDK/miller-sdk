#pragma once

namespace hh::fnd {
    class StaticResourceContainer : public ResourceContainer {
        const ResourceTypeInfo* typeInfo;
        void* unk2;
        csl::ut::MoveArray<ManagedResource*> resources;
    public:
        StaticResourceContainer(csl::fnd::IAllocator* allocator);
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
