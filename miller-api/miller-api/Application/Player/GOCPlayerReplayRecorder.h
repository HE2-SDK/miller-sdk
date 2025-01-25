#pragma once

namespace app::player {
    class GOCPlayerReplayRecorder : public hh::game::GOComponent {
    public:
        uint16_t word80;
        uint8_t byte82;
        uint64_t qword88;
        uint64_t qword90;
        uint64_t qword98;
        uint64_t qwordA0;
        uint32_t dwordA8;
        uint8_t byteAC[9];
        uint16_t owordB6[8];
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint64_t qwordD8;
        uint64_t qwordE0;
        uint16_t wordE8;
        csl::math::Vector4 csl__math__vector4F0;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerReplayRecorder);
    };
}
