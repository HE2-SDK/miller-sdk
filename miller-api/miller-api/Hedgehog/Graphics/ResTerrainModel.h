#pragma once

namespace hh::gfx {
    class ResTerrainModel : public fnd::ManagedResource, public ResModelParameterInterface<ResTerrainModel> {
    public:
        uint64_t unk101;
        csl::ut::MoveArray<void*> unk102;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override;
        virtual void* GetParameterInterface() override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResTerrainModel)
    };
}
