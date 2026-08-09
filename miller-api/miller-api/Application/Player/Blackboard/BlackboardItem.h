#pragma once

namespace app::player {
    class BlackboardItem : public BlackboardContent {
    public:
        static constexpr const char* name = "BlackboardItem";

        struct Description {
            int unk0;
            int ringCapacity;
        };

        uint32_t unk1;
        uint32_t ringCapacity;
        uint32_t ringCount;

        virtual unsigned int GetNameHash() const override;

        void Setup(const Description& desc);

        DEFAULT_CREATE_FUNC(BlackboardItem);
    };
}
