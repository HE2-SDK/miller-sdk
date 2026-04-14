#pragma once

namespace Cyan {
    class ManagerImpl;
    class HistoricalStripe;
}

namespace Cyan::Graphics {
    class EffectObject {
    public:
        EmitterDecl declaration;
        unsigned int nextParticleIndex;
        ParticleDecl* particleDeclBufferStart;
        ParticleDecl* particleDeclBufferEnd;
        MeshDecl* meshDeclBuffer;
        System::LinkList<EmitterDecl>::Entry emitterListEntry;
    };

    class RendererImpl {
    public:
        hh::needle::intrusive_ptr<hh::needle::ParameterValueObject> parameterValueObject0;
        hh::needle::intrusive_ptr<hh::needle::ParameterValueObject> parameterValueObject1;
        hh::needle::intrusive_ptr<hh::needle::VertexLayout> vertexLayout0;
        hh::needle::intrusive_ptr<hh::needle::VertexLayout> vertexLayout1;
        hh::needle::intrusive_ptr<hh::needle::ShaderObject> shaderObject0;
        hh::needle::intrusive_ptr<hh::needle::ShaderObject> shaderObject1;
        hh::needle::intrusive_ptr<hh::needle::ShaderObject> shaderObject2;
        uint8_t byte38;
    };

    class Renderer {
    public:
        struct RenderState {
            hh::needle::ParamValueOverrideHelper pvoHelper;
            char pad[0x2620];
        };

        ManagerImpl* managerImpl;
        System::LinkList<EmitterDecl> emitters[2];
        unsigned int frameIndex;
        System::LinkList<EmitterDecl>::Entry* currentFrameFirstEmitterListEntry;
        unsigned int dword70;
        uint8_t byte74;
        RendererImpl* implementation;
        void* renderAllocator;
        int dword88;

        Renderer(ManagerImpl* managerImpl);

        void SetGammaCorrect(bool enabled);

        virtual ~Renderer();
        virtual void Initialize(const DeviceContainer& deviceContainer);
        virtual void PrepareRender();
        virtual unsigned int Render(const DeviceContainer& deviceContainer, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned int unkParam4, void* unkParam5); 
        virtual EffectObject* BeginEmitter(const EmitterDecl& emitterDecl);
        virtual void UnkFunc5(void* unkParam1);
        virtual void AddParticle(Graphics::EffectObject* effectObject, const Graphics::ParticleDecl& particleDecl, const Matrix23* matrices);
        virtual void AddCpuTransformedParticle(Graphics::EffectObject* effectObject, const Graphics::ParticleDecl& particleDecl, const Matrix23* matrices);
        virtual void AddStripe(HistoricalStripe* historicalStripe, Graphics::EffectObject* effectObject, const Graphics::ParticleDecl& particleDecl, const Matrix23* matrices);

    private:
        void ClearList(unsigned int index);
        void AddList(EffectObject* effectObject, int layer, float priority);
    };
}
