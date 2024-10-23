#pragma once

namespace hh::needle {
    class SCDensity : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCDensity& sceneContext;
            uint64_t unk1;
            uint64_t unk2;

        public:
            Impl(SCDensity& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCDensity);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
        virtual void UnkFunc7();
    };
}
