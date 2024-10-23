#pragma once

namespace hh::needle {
    class SCAtmosphericFog : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCAtmosphericFog& sceneContext;
            uint64_t qword18;
            float float20;

        public:
            Impl(SCAtmosphericFog& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCAtmosphericFog);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
