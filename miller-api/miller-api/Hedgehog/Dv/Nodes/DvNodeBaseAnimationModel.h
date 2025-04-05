#pragma once

namespace app::dv{
    class AppDvSceneObjectBase;
}

namespace hh::dv{
    class DvNodeBaseAnimationModel : public DvNodeBase{
    public:
        struct Description : DvNodeBase::Description {
            bool useName3;
        private:
            char padding[3];
        public:
            char modelName[64];
            char skeletonName[64];
            char name3[64];
            char unkData[76];
        };

        enum class Flags : unsigned int {
            UNHANDLED,
            HIDDEN
        };

        Description binaryData;
        app::dv::AppDvSceneObjectBase* nodeCharacterObj;
        csl::ut::Bitset<Flags> mdlFlags;
        int maybeHandle0;
        csl::ut::MoveArray<void*> guids;
        int unk0;
        float unk1;
        csl::ut::MoveArray<const char*> unk2;
        char unk3;

        virtual void Setup(DvNodeBase::Description& description) override;
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
