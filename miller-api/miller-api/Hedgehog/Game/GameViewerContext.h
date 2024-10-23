#pragma once

namespace hh::game {
    class GameViewerContextListener {
    public:
        virtual ~GameViewerContextListener() = default;
        virtual void GVCL_UnkFunc1() {}
        virtual void GVCL_UnkFunc2() {}
    };

    class GameViewerContext : public dbg::ViewerContext, public GameManagerListener {
    public:
        csl::ut::MoveArray<GameManager*> gameManagers{ GetAllocator() };
        csl::ut::MoveArray<GameViewerContextListener*> listeners{ GetAllocator() };

		virtual void GML_UnkFunc8() override;

        void AddGameManager(GameManager* gameManager);
        void RemoveGameManager(GameManager* gameManager);
        void AddListener(GameViewerContextListener* listener);
        void RemoveListener(GameViewerContextListener* listener);

        VIEWER_CONTEXT_CLASS_DECLARATION(GameViewerContext)
    };
}