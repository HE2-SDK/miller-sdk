#pragma once

namespace hh::gfnd {
    class ResTexture : public fnd::ManagedResource {
        hh::needle::Texture* texture;
        void* unk102[12];
        uint64_t unk103;
        uint64_t unk104;
        uint8_t unk105;
        uint32_t nameHash;
    public:
        inline hh::needle::Texture* GetTexture() const { return texture; }

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResTexture)
    };
}
