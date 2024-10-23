#pragma once

namespace hh::needle {
    class SCDecal : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCDecal& sceneContext;
            uint64_t unk0;
            float unk1;
            uint64_t unk2;
            uint64_t unk3;
            csl::ut::MoveArray<void*> unk4;
            uint64_t unk5;
            csl::ut::MoveArray<void*> unk6;

        public:
            Impl(SCDecal& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCDecal);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
