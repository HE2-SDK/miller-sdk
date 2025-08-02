#pragma once
#include <ucsl/resources/effdb/v100.h>

namespace hh::animeff {
    using ucsl::resources::effdb::v100::Particle;
    using ucsl::resources::effdb::v100::Binding;
    using ucsl::resources::effdb::v100::EffdbData;

    class ResParticleLocation : public fnd::ManagedResource {
    public:
        csl::ut::StringMap<Binding*> bindings;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResParticleLocation);
    };
}
