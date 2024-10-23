#pragma once

namespace hh::needle {
    class SCLocalLight : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            struct Unk1 {
                int unk1;
                uint64_t unk2;
            };

            SCLocalLight& sceneContext;
            char unk1[64000];
            unsigned int numLights;
            unsigned int maxLights;
            Unk1 unk4[1000];
            unsigned int unk5;
            csl::math::Vector4 unk6;
            float unk7;
            int unk8;
            csl::fnd::Mutex mutex;

            Impl(SCLocalLight& sceneContext);
        };

        intrusive_ptr<Impl> implementation;
        uint64_t unk4;

        SCENECONTEXT_CLASS_DECLARATION(SCLocalLight);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
