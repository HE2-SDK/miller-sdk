#pragma once

namespace hh::needle {
    class SCPostEffectResource : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            RenderingDevice* renderingDevice;
            csl::ut::InplaceMoveArray<CNameIDObject*, 32> renderUnitNames;
            csl::ut::InplaceMoveArray<Texture*, 32> textures;
            csl::ut::InplaceMoveArray<void*, 32> unk3;
            csl::ut::MoveArray<void*> unk4[64];
            uint64_t unk5;
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCPostEffectResource);

        Texture* GetTextureForRenderUnit(CNameIDObject* renderUnitName) const;

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual void UnkFunc3();
        virtual void UnkFunc4();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
