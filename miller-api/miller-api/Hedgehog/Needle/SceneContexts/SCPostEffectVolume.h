#pragma once

namespace hh::needle {
    class SCPostEffectVolume : public SceneContext {
    public:
        struct Unk1 {
            uint32_t unk1;
            csl::math::Matrix34 unk2;
            csl::math::Vector4 unk3;
        };

        Unk1 unk1[16];

        SCENECONTEXT_CLASS_DECLARATION(SCPostEffectVolume);
        void InitializeUnk1s();

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
