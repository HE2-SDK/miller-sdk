#pragma once

namespace hh::needle {
    class SCWorld : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCWorld& sceneContext;
            uint64_t unk1;
        public:

            Impl(SCWorld& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCWorld);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
