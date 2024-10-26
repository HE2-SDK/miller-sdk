#pragma once

namespace app::player {
    class BlackboardSpeed : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardSpeed";
        float speed;
        float speed2;

        virtual unsigned int GetNameHash() const override;

        DEFAULT_CREATE_FUNC(BlackboardSpeed);
    };
}
