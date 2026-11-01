#pragma once

namespace app::player {
    class BlackboardBattle : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardBattle";

        struct Description {
            int unk0;
        };

        int unk0;
        csl::math::Vector4 unk1;
        int unk2;
        int64_t unk3;
        int64_t unk4;
        int64_t unk5;
        int64_t unk6;
        csl::ut::VariableString unk7;
        short flags;

        virtual unsigned int GetNameHash() const override;

        void Setup(const Description& desc);

        DEFAULT_CREATE_FUNC(BlackboardBattle);
    };
}
