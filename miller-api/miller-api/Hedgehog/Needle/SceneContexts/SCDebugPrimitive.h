#pragma once

namespace hh::needle {
    class SCDebugPrimitive : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCDebugPrimitive& sceneContext;
            uint64_t unk1;

        public:
            Impl(SCDebugPrimitive& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCDebugPrimitive);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
