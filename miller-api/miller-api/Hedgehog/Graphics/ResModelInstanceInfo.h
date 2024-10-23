#pragma once

namespace hh::gfx {
    class ResModelInstanceInfo : public fnd::ManagedResource {
    public:
        void* unk101;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResModelInstanceInfo)
    };
}
