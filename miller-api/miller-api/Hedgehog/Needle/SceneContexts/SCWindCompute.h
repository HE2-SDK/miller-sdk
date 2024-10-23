#pragma once

namespace hh::needle {
    class SCWindCompute : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            struct Unk1 {
                SCWindCompute& sceneContext;
                unsigned int index;
                uint32_t unk2;
            };

            SCWindCompute& sceneContext;
            uint64_t unk0;
            char byte10[0x10000];
            uint32_t unk1;
            csl::math::Vector4 unk2;
            csl::math::Vector4 unk3;
            csl::math::Vector4 unk4;
            csl::math::Vector4 unk5;
            float unk6;
            uint64_t unk7;
            uint64_t unk8;
            uint64_t unk9;
            uint64_t unk10;
            csl::math::Vector4 unk11;
            csl::math::Vector4 unk12;
            csl::math::Vector4 unk13;
            csl::math::Vector4 unk14;
            uint64_t unk15;
            uint32_t unk16;
            uint32_t unk16a;
            uint64_t unk17[0x380];
            Unk1 unk18[256];
            uint8_t unk19;

        public:
            Impl(SCWindCompute& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCWindCompute);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
