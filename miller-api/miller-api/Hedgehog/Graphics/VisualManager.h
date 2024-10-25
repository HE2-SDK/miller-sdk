#pragma once

namespace hh::gfx {
    class VisualModelListener {
    public:
        virtual ~VisualModelListener() = default;
        virtual void OnModelAdded(GOCVisualModel* model) {}
        virtual void OnModelRemoved(GOCVisualModel* model) {}
    };

    class VisualModelUpdaterBase {

    };

    class VisualManager : public game::GameService, public game::GameStepListener {
        csl::ut::MoveArray<GOCVisualModel*> models;
        csl::ut::InplaceMoveArray<VisualModelListener*, 2> visualModelListeners;
        csl::ut::InplaceMoveArray<VisualModelUpdaterBase*, 2> visualModelUpdaters;
        volatile uint32_t spinlock;

    public:
        static VisualManager* instance;
        static VisualManager* GetInstance();

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        void AddModel(GOCVisualModel* model);
        void RemoveModel(GOCVisualModel* model);
        void AddVisualModelListener(VisualModelListener* listener);
        void RemoveVisualModelListener(VisualModelListener* listener);
        void AddVisualModelUpdater(VisualModelUpdaterBase* updater);
        void RemoveVisualModelUpdater(VisualModelUpdaterBase* updater);
        uint64_t SetModelTransform(GOCVisualModel* model);

        GAMESERVICE_CLASS_DECLARATION(VisualManager)
    };
}
