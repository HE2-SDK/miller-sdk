#pragma once

namespace hh::fnd {
    class StaticResourceContainer : public ResourceContainer {
        const ResourceTypeInfo* typeInfo;
        void* unk2;
        csl::ut::MoveArray<ManagedResource*> resources;
    public:
        StaticResourceContainer(csl::fnd::IAllocator* allocator, const ResourceTypeInfo* typeInfo, void* unk2);
        const ResourceTypeInfo* GetTypeInfo() {
            return typeInfo;
        }

        virtual void* GetRuntimeTypeInfo() const override;
        virtual ManagedResource* GetResourceByName(const char* name) const override;
        virtual int GetNumResources() const override;
        virtual ManagedResource* GetResourceByIndex(int index) const override;
        virtual uint64_t UnkFunc5();
    };
}
