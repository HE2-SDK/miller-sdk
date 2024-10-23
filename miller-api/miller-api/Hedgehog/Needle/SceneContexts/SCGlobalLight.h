#pragma once

namespace hh::needle {
    class SCGlobalLight : public SceneContext {
    public:
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        uint64_t unk7;
        uint64_t unk8;
        uint64_t unk9;
        uint64_t unk10;

        SCENECONTEXT_CLASS_DECLARATION(SCGlobalLight);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
