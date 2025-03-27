#pragma once

namespace hh::animeff {
    class ResParticleLocation : public fnd::ManagedResource {
    public:
        csl::ut::MoveArray<void*> unk201;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResParticleLocation);
    };
}
