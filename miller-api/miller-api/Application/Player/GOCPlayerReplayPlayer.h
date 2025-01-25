#pragma once

namespace app::player {
    class GOCPlayerReplayPlayer : public hh::game::GOComponent {
    public:
        uint16_t word80;
        uint8_t byte82;
        uint64_t qword88;
        uint64_t qword90;
        uint32_t dword98;
        uint32_t dword9C;
        uint64_t qwordA0;
        uint64_t qwordA8;
        hh::eff::EffectHandle hh__eff__effecthandleB0;
        hh::eff::EffectHandle hh__eff__effecthandleC0;
        app_cmn::camera::CameraParameter app_cmn__camera__cameraparameterD0;
        csl::math::Vector4 csl__math__vector4160;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerReplayPlayer);
    };
}
