#pragma once

namespace hh::needle {
    class SCInteractionCompute : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCInteractionCompute& sceneContext;
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4[10];
            csl::math::Vector4 unk5[8];
            uint64_t unk6;
            uint64_t unk7;
            uint64_t unk8;

        public:
            Impl(SCInteractionCompute& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCInteractionCompute);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
