#pragma once

namespace hh::snd {
    class ResAtomConfig : public hh::fnd::ManagedResource {
    public:
        uint8_t unk100;
        uint64_t unk101[23];

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAtomConfig)
    };
}
