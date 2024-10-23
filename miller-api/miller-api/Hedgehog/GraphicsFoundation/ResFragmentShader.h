#pragma once

namespace hh::gfnd {
    class ResFragmentShader : public fnd::ManagedResource {
    public:
        needle::PixelShader* shader;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResFragmentShader)
    };
}
