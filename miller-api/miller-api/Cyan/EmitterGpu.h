#pragma once

namespace Cyan {
    class AliveStateGpu : public Emitter::AliveState {
    public:
        virtual void OnUpdate(System::FSMContext* ctx) override;
        virtual void UnkFunc1(System::FSMContext* ctx) override;
    };

    class EmitterGpu : public Emitter {
    public:
        // struct EmitterDeclGpu : public EmitterDecl {
        //     uint64_t qword0;
        //     uint64_t qword8;
        //     uint64_t qword10;
        //     uint64_t qword18;
        //     uint64_t qword20;
        //     uint8_t gap28[8];
        //     uint64_t qword30;
        //     uint64_t qword38;
        //     uint64_t qword40;
        //     uint64_t qword48;
        //     uint64_t qword50;
        //     uint64_t qword58;
        //     uint64_t qword60;
        //     uint64_t qword68;
        //     AliveStateGpu aliveState;
        //     uint32_t dword88;
        //     uint32_t dword8C;
        //     uint32_t dword90;
        //     float dword94;
        //     uint32_t dword98;
        //     uint32_t dword9C;

        //     EmitterDeclGpu();
        // };

        EmitterGpu(EffectImpl* effect, const Resource::EmitterParam* param);

        virtual uint64_t UnkFunc3(void* unkParam1) override;
        virtual void PrepareRender(Graphics::Renderer* renderer, const Graphics::DeviceContainer& deviceContainer) override;
        virtual System::FSMState* GetState(unsigned int stateId) override;
        virtual void UnkFunc9(void* unkParam1) override;
        virtual void InitEmitter(bool useLocalMatrix) override;
        virtual void ProcessEmitter(float time) override;
        virtual void UpdateEmitter(float time) override;
        virtual void EmitElements(float time) override;
        virtual void EmitElements2(float time) override;
    };
}
