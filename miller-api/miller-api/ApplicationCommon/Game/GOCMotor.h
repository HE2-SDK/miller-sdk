#pragma once

namespace app_cmn::game {
    class GOCMotor : public hh::game::GOComponent {
    public:
        enum class TimeType : uint32_t {
            GLOBAL,
            LOCAL,
        };

        enum class Flag : uint8_t {
            TRANSFORM_TRANSLATION,
            TRANSFORM_ROTATION,
        };

        csl::math::Transform transform;
        hh::fnd::HFrame* frame;
        csl::ut::Bitset<Flag> flags;
        TimeType timeType;
        float maybeLoopTime;
        float time;
        int unk106;
        bool stopped;

        struct SetupInfo {
            TimeType timeType{};
            hh::fnd::HFrame* frame{};
        };

        GOCMotor(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void InitTransform(csl::math::Transform& transform);
        virtual void UpdateSetEditor() {}
        virtual void InitConfig() {}
        virtual void UpdateTransform(float time, csl::math::Transform& transform) = 0;

        void Setup(const SetupInfo& setupInfo);
        void UpdateFrameWithTransform(const csl::math::Transform& transform);

        GOCOMPONENT_CLASS_DECLARATION(GOCMotor);
    };
}
