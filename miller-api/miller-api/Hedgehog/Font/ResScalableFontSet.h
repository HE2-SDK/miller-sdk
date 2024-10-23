#pragma once

namespace hh::font {
    class ResScalableFontSet : public fnd::ManagedResource {
    public:
        void* unk101;
        void* unk102;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResScalableFontSet)
    };
}
