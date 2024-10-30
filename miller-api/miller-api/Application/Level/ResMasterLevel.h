#pragma once

namespace app::level {
    class ResMasterLevel : public hh::fnd::ManagedResource {
        void* binaryData;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResMasterLevel)    
    };
}
