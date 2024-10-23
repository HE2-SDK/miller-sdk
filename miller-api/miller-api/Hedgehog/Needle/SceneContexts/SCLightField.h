#pragma once

namespace hh::needle {
    class SCLightField : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
        private:
            SCLightField& sceneContext;
            SupportFX::SFXAllocator allocator;

        public:
            Impl(SCLightField& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCLightField);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual void UnkFunc2();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
