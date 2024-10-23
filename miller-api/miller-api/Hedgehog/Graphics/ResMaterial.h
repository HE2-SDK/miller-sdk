#pragma once

namespace hh::gfx {
    class ResMaterial : public fnd::ManagedResource {
    public:
        needle::MaterialResource* resource;
        // needle::MaterialResourceReference* resourceReference;
        void* resourceReference;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResMaterial)
    };
}
