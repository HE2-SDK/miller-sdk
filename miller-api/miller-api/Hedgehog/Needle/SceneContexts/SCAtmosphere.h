#pragma once

namespace hh::needle {
    class SCAtmosphere : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            uint64_t unk1;
            uint64_t unk2;
            csl::math::Vector4 unk3;
            csl::math::Vector4 unk4;
            csl::math::Vector4 unk5;
            uint64_t unk6;
            uint64_t unk7;
            uint64_t unk8[16];
            uint32_t unk9;
            SCAtmosphere& sceneContext;
            intrusive_ptr<Texture> renderTargetViews[2];
            intrusive_ptr<RenderTarget> renderTargets[2];
            intrusive_ptr<Texture> unk12;
            uint64_t unk13;
            uint64_t unk14;
            uint64_t unk15;
            uint64_t unk16;
            uint64_t unk17;
            uint64_t unk18;
            uint64_t unk19;
            uint64_t unk20;
            uint64_t unk21;
            uint64_t unk22;
            uint64_t unk23;
            intrusive_ptr<NeedleRefcountObject> unk24[2];
            intrusive_ptr<Texture> unk25;
            intrusive_ptr<Texture> unk26;
            uint64_t unk27;
            uint64_t unk28;
            uint64_t unk29;
            uint64_t unk30;
            uint64_t unk31;
            uint64_t unk32;

            Impl(SCAtmosphere& sceneContext);
        };

        intrusive_ptr<Impl> implementation;
        uint32_t unk1;

        SCENECONTEXT_CLASS_DECLARATION(SCAtmosphere);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
