#pragma once

namespace app::player {
    class BlackboardAmy : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardAmy";
        uint32_t unk1;
        uint8_t unk2;

        virtual unsigned int GetNameHash() const override;

        DEFAULT_CREATE_FUNC(BlackboardAmy);
    };
}
