#pragma once
#include <ucsl/resources/converse-project/v4.h>

namespace hh::text {
    using ucsl::resources::converse_project::v4::CnvrsProjData;

    class ResTextProject : public fnd::ManagedResource {
    public:
        CnvrsProjData* cnvrsProjData;
        void* unk102;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResTextProject)
    };
}
