#pragma once

namespace hh::needle {
    class SCInteractionWave : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCInteractionWave& sceneContext;
            uint64_t qword18;
            uint8_t byte20;

        public:
            Impl(SCInteractionWave& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCInteractionWave);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
