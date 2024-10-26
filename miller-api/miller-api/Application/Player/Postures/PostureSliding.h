#pragma once

namespace app::player {
    class PostureSliding : public PlayerPosture {
    public:
        uint64_t unk1;
        uint8_t unk2;

        PostureSliding(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetNameHash() const override;
        virtual unsigned int UnkFunc2() override;
        virtual void Enter() override;
        virtual void Leave() override;
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UnkFunc6() override;
    };
}