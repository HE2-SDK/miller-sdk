#pragma once

namespace hh::gfx {
    class ResOcclusionCapsule : public fnd::ManagedResource {
    public:
        uint64_t unk201;
        uint64_t unk202;
        csl::ut::MoveArray<void*> unk203;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResOcclusionCapsule);
    };
}
