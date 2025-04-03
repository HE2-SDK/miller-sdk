#pragma once

namespace hh::dv{
    class ResDvScene : public hh::fnd::ManagedResource{
    public:
        void* binaryData; // could make structs for it, but no
        int64_t unk;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        MANAGED_RESOURCE_CLASS_DECLARATION(ResDvScene)
    };
}
