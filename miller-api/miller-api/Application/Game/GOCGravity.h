#pragma once

namespace app::game {
    class GOCGravity : public hh::game::GOComponent, public hh::fnd::HFrameListener {
    public:
        csl::math::Vector4 vector90;
        uint64_t qwordA0;
        uint16_t wordA8;
        uint64_t qwordB0;
        uint64_t qwordB8;
        uint64_t qwordC0;
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint32_t dwordD8;
        csl::math::Vector4 vectorE0;
        csl::math::Vector4 vectorF0;
        float dword100;
        uint64_t gravityPhantomListener;

        GOCGravity(csl::fnd::IAllocator* allocator);

        GOCOMPONENT_CLASS_DECLARATION(GOCGravity);
        
        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;
    };
}