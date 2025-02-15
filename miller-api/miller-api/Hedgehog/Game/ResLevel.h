#pragma once

namespace hh::game {
    class ResLevel : public hh::fnd::ManagedResource {
        void* binaryData;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResLevel);
        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;   
    };
}
