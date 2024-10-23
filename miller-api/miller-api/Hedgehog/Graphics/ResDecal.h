#pragma once

namespace hh::gfx {
    struct ResDecalData {
        unsigned int unk1;
        unsigned int numBlocksMaybe;
        void* decals;
        unsigned int decalCount;
    };

    class ResDecal : public fnd::ManagedResource {
    public:
        ResDecalData* decalData;
        uint64_t unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResDecal)
    };
}
