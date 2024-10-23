#pragma once

namespace hh::gfx {
    struct ProbeData {
        char pad1[0x50];
        const char* textureName;
        uint64_t unk1;
        needle::Texture* texture; // loaded at runtime
        char pad2[0x10];
    };

    struct ResProbeData {
        uint64_t unk1;
        ProbeData* probes;
        unsigned int probeCount;
    };

    class ResProbe : public fnd::ManagedResource {
    public:
        ResProbeData* probeData;
        void* reloadedPackedBinaryData;

        virtual void Load(void* data, size_t size) override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResProbe)
    };
}
