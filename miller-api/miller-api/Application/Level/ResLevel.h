#pragma once

namespace app::level {
    class ResLevel : public hh::fnd::ManagedResource {
        void* binaryData;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResLevel)    
    };
}
