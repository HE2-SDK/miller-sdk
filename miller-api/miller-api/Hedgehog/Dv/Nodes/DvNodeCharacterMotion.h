#pragma once

namespace hh::dv{
    class DvNodeCharacterMotion : public DvNodeBase {
    public:
        struct Description : DvNodeBase::Description {
        public:
            enum class Flags : unsigned int {
                UNK0,
                UPDATE_TRANSFORM,
                USE_ROOT_BONE
            };

            csl::ut::Bitset<Flags> flags;
            int start;
            int end;
            int field0c;
            char asmState[8];
            float speed;
            int unk0;
            int unk1;
            int unk2;
            int unk3;
            int unk4;
        };

        Description binaryData;
        int unk1;
        int unk2;
        int unk3;
        float unk4; //prolly a bitset
        csl::math::Transform transform0;
        csl::math::Transform transform1;
        float unk5;

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Start() override;
        virtual void Update(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeCharacterMotion)
    };
}
