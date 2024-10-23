#pragma once

namespace hh::gfnd {
    class ResVertexShader : public fnd::ManagedResource {
    public:
        needle::VertexShader* shader;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResVertexShader)
    };
}
