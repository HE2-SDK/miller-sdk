#pragma once

namespace hh::gfx {
    class ResMirageTerrainInstanceInfo : public fnd::ManagedResource {
    public:
        void* unk101;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResMirageTerrainInstanceInfo)
    };
}
