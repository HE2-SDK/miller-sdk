#pragma once
#include <ucsl/resources/master-level/v0.h>

namespace app::level {
    using ucsl::resources::master_level::v0::DependencyData;
    using ucsl::resources::master_level::v0::ResourceData;
    using ucsl::resources::master_level::v0::LevelData;
    using ucsl::resources::master_level::v0::MasterLevelData;

    class ResMasterLevel : public hh::fnd::ManagedResource {
        MasterLevelData* masterLevelData;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResMasterLevel)    

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
    };
}
