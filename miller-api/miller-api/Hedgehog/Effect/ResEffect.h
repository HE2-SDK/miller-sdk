#pragma once

namespace hh::eff {
    class ResEffect : public fnd::ManagedResource {
    public:
        uint8_t unk101;
        csl::ut::MoveArray<void*> unk102;
        csl::ut::MoveArray<void*> unk103;
        uint64_t unk104;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResEffect)
    };
}
