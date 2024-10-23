#pragma once

namespace hh::needle {
    class SCColorGradingLUT : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCColorGradingLUT& sceneContext;
            intrusive_ptr<NeedleRefcountObject> unk1[8];

        public:
            Impl(SCColorGradingLUT& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCColorGradingLUT);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
