#pragma once

namespace hh::gfx {
    class ResMirageLight : public fnd::ManagedResource {
    public:
        fnd::ResLightParameter lightParameter;
        uint32_t unk2;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResMirageLight)
    };
}
