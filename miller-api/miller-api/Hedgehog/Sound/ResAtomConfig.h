#pragma once

namespace hh::snd {
    class ResAtomConfig : public hh::fnd::ManagedResource {
    public:
        char unk101[0x110];

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAtomConfig)
    };
}
