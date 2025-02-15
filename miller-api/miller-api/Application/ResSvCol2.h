#pragma once
#include <ucsl/resources/svcol/v1.h>

namespace app {
    using ucsl::resources::svcol::v1::SvColData;

    class ResSvCol2 : public hh::fnd::ManagedResource {
    public:
        SvColData* svColData;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResSvCol2);
    };
}
