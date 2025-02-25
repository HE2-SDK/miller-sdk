#pragma once

namespace app::dv{
    class AppDvSceneObjectBase;
}

namespace hh::dv{
    class DvNodeBaseAnimationModel : public DvNodeBase{
    public:
        struct Data {
            int useName3;
            char modelName[64];
            char skeletonName[64];
            char name3[64];
            char unkData[76];
        };

        Data binaryData;
        app::dv::AppDvSceneObjectBase* nodeCharacterObj;
        int unk0;
        csl::ut::MoveArray<void*> guids;
        float unk1;
        csl::ut::MoveArray<void*> unk3;
        float unk4;
        uint32_t unk5;
        uint32_t unk6;

        virtual void Setup(void* setupInfo) override;
        virtual void Start() override;
        virtual void PostStepUpdate(int currentFrame) override;
        virtual bool IsUnkFlag0() override;
        virtual bool UnkFunc3() override;
        virtual int GetUpdateTiming() override;
        virtual void* GetUnkNodeChar();
        virtual bool UnkFuncBase();

        app::dv::AppDvSceneObjectBase* GetDvSceneObject();

        DvNodeBaseAnimationModel(csl::fnd::IAllocator* allocator);
    };
}