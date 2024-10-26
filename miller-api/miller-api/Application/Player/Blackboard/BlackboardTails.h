#pragma once

namespace app::player {
    class BlackboardTails : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardTails";
        int unk1;
        uint32_t unk2;
        uint32_t unk3;
        uint32_t unk4;
        uint32_t unk5;
        uint32_t unk6;

        virtual unsigned int GetNameHash() const override;

        DEFAULT_CREATE_FUNC(BlackboardTails);
    };
}
