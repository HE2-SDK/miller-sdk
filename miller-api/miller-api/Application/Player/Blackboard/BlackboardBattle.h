#pragma once

namespace app::player {
    class BlackboardBattle : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardBattle";
        uint8_t powerLevel;
        uint8_t defenseLevel;
        uint8_t unk1;
        uint8_t unk2;
        csl::math::Vector4 unk3;
        csl::ut::MoveArray<void*> debugArray1;
        csl::ut::MoveArray<void*> debugArray2;
        csl::ut::MoveArray<void*> unk4;
        uint32_t unk5;
        uint16_t unk6;
        uint8_t unk7;
        uint32_t comboCount;
        float phantomRushAmount;
        float unk9;
        float unk10;
        float quickCyloopAmount;
        void* unkself12;
        uint64_t unk12;
        uint64_t unk13;
        uint64_t unk14;
        csl::ut::VariableString unk16;
        uint16_t unk17;

        virtual unsigned int GetNameHash() const override;

        DEFAULT_CREATE_FUNC(BlackboardBattle);
    };
}
