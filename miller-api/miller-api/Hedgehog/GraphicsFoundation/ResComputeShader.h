#pragma once

namespace hh::gfnd {
    class ResComputeShader : public fnd::ManagedResource {
    public:
        needle::ComputeShader* shader;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResComputeShader)
    };
}
