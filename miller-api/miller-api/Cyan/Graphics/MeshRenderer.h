#pragma once

namespace Cyan::Graphics {
    // class MeshRendererNeedle : public hh::needle::ModelInstanceRenderer {

    // };
    class MeshRendererNeedle;

    class MeshRenderer : public Renderer {
    public:
        MeshRendererNeedle* meshRendererNeedle;

        MeshRenderer(ManagerImpl* managerImpl);

        virtual void Initialize(const DeviceContainer& deviceContainer) override {}
        virtual unsigned int Render(const DeviceContainer& deviceContainer, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned int unkParam4, void* unkParam5) override;
        virtual EffectObject* BeginEmitter(const EmitterDecl& emitterDecl) override;
        virtual void UnkFunc5(void* unkParam1) override;
        virtual void AddParticle(Graphics::EffectObject* effectObject, const Graphics::ParticleDecl& particleDecl, const Matrix23* matrices) override;
        virtual void AddCpuTransformedParticle(Graphics::EffectObject* effectObject, const Graphics::ParticleDecl& particleDecl, const Matrix23* matrices) override;
        virtual void UnkFunc9();
    };
}
