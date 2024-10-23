#pragma once

namespace hh::physics {
    class PhysicsViewerBase
        : public dbg::Viewer
        , public game::GameViewerContextListener
        , public game::GameUpdateListener
        , public PhysicsViewerContextListener
    {
    public:
        fnd::Reference<PhysicsViewerContext> physicsViewerContext;
        fnd::Reference<game::GameViewerContext> gameViewerContext;

        PhysicsViewerBase(csl::fnd::IAllocator* allocator);
        virtual int64_t UnkFunc6();
        virtual void GVCL_UnkFunc1() override;
        virtual void GVCL_UnkFunc2() override;
		virtual void PostGameUpdateCallback(game::GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;
    };
}
