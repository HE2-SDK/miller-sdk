#pragma once

namespace hh::game {
    class GameViewerBase : public dbg::Viewer, public GameViewerContextListener {
        fnd::Reference<GameViewerContext> gameViewerContext;
    public:
        GameViewerBase(csl::fnd::IAllocator* allocator);
    };
}