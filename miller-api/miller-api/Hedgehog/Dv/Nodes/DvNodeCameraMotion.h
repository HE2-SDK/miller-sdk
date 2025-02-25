#pragma once

namespace hh::dv{
    class DvNodeCameraMotion : public DvNodeBase {
    public:
        struct Data {
        public:
            enum class Flags : unsigned int {
                UNK0,
                USE_NEAR_FAR_CLIP
            };

            csl::ut::Bitset<Flags> flags;
            int start;
            int end;
            int field0c;
        };

        Data binaryData;
        csl::ut::MoveArray<void*> unkArray;
        int unk3;
        int unk4;

        virtual void Setup(void* setupInfo) override;
        virtual void Start() override;
        virtual void Update(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeCameraMotion)
    };
}