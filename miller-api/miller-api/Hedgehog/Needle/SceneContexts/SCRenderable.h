#pragma once

namespace hh::needle {
    class SCRenderable : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCRenderable& sceneContext;
        public:
            csl::ut::MoveArray<void*> unk1[10];

            Impl(SCRenderable& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCRenderable);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
