#pragma once

namespace hh::needle {
    class SCSkyCube : public SceneContext {
    public:
        uint64_t unk1;
        uint64_t unk2;
        csl::math::Matrix34 transform;

        SCENECONTEXT_CLASS_DECLARATION(SCSkyCube);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
