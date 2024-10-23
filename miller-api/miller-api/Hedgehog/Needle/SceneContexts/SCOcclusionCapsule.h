#pragma once

namespace hh::needle {
    class SCOcclusionCapsule : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            struct Unk1 {
                float_vector4 unk1;
                float_vector4 unk2;
                uint64_t unk5;
                uint64_t unk6;
                uint64_t unk7;
                uint64_t unk8;
                uint64_t unk9;
                uint64_t unk10;
                uint64_t unk11;
                uint64_t unk12;
                uint32_t unk14;
                uint32_t unk15;
                float unk16;
                float unk17;
                float unk18;
                uint8_t unk19;
            };
        
        private:
            SCOcclusionCapsule& sceneContext;
            Unk1 unk1[512];
            uint64_t unk1a;
            csl::ut::MoveArray<void*> unk2[64];
            uint64_t unk3;
            uint32_t unk4;
            uint64_t pad2[0x1400];
            uint64_t unk5;
            uint64_t unk6;
            uint32_t unk7;

        public:
            Impl(SCOcclusionCapsule& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCOcclusionCapsule);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
