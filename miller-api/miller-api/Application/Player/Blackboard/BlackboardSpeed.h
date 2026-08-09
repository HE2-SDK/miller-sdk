#pragma once

namespace app::player {
    class BlackboardSpeed : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardSpeed";
        float unk0;
        float unk1;
        float unk2;
        float unk3;
        float unk4;
        int unk5;
        int unk6;

        virtual unsigned int GetNameHash() const override;

        DEFAULT_CREATE_FUNC(BlackboardSpeed);
    };
}
