#pragma once
#include <ucsl/resources/converse-meta/v2.h>

namespace hh::text {
    using ucsl::resources::converse_meta::v2::CnvrsMetaData;

    class ResTextMeta : public fnd::ManagedResource {
    public:
        CnvrsMetaData* cnvrsMetaData;
        void* unk102;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResTextMeta)
    };
}
