#pragma once

namespace hh::needle {
    class SCEnvironment : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCEnvironment& sceneContext;
            uint64_t qword18;
            uint64_t qword20;

        public:
            Impl(SCEnvironment& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCEnvironment);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
