#pragma once
#include <ucsl/resources/converse-text/v6.h>

namespace hh::text {
    using ucsl::resources::converse_text::v6::CnvrsTextData;

    class ResText : public fnd::ManagedResource {
    public:
        CnvrsTextData* cnvrsTextData;
        void* unk102;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResText)
    };
}
