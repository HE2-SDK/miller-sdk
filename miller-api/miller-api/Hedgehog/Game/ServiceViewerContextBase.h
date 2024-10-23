#pragma once

namespace hh::game {
    class ServiceViewerContextBase
        : public dbg::ViewerContext
        , public GameViewerContextListener
        , public GameManagerListener
    {
        fnd::Reference<GameViewerContext> gameViewerContext;
        const GameServiceClass* gameServiceClass;
    public:
        ServiceViewerContextBase(csl::fnd::IAllocator* allocator, const GameServiceClass* gameServiceClass);

        virtual uint64_t Initialize(const csl::ut::MoveArray<fnd::Reference<ViewerContext>>& viewerContexts) override;
        virtual uint64_t OnCreated() override;
        virtual uint64_t OnDestroyed() override;
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual void GVCL_UnkFunc1() override;
        virtual void GVCL_UnkFunc2() override;
		virtual void GameServiceAddedCallback(GameService* gameService) override;
		virtual void GameServiceRemovedCallback(GameService* gameService) override;
    };
}
