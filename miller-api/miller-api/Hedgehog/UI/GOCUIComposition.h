#pragma once

namespace hh::ui {
    class UIElement;
    class UIElementGroup;
    class UIElementGroupContainer;
    class GOCUIComposition : public game::GOComponent {
    public:
        csl::ut::MoveArray<void*> unk101;
        csl::fnd::Delegate<void (GOCUIComposition* gocUIComposition)> onCurrentGroupChange;
        bool unk103;
        int currentGroupIndex;
        UIElementGroupContainer* rootContainer;
        csl::ut::MoveArray<UIElementGroup*> elementGroups;
        csl::ut::MoveArray<UIElementGroup*> elementGroupsToBeUpdated;
        csl::ut::MoveArray<void*> unk108;
        SurfRide::Project* project;
        uint64_t unk110;
        uint32_t unk111;
        UITextInterface* textInterface;
        csl::ut::MoveArray<fnd::Reference<CastSizeBinder>> castSizeBinders;
        uint64_t unk114;

        void Unk12421(SurfRide::Project* project, csl::ut::InplaceMoveArray<const char*, 32>& sceneNames);
        int FindGlobalIndexOfGroup(UIElementGroupContainer* container, const char* name);
        void SetCurrentGroupByGlobalIndex(int index);

        GOCOMPONENT_CLASS_DECLARATION(GOCUIComposition);

        struct SetupInfo {
            uint32_t unk1;
            uint64_t unk2;
            uint32_t unk3;
        };

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);
        void Initialize();
        void SetProject(SurfRide::Project* project);
        void SetCurrentGroup(const char* name);
        UIElement* FindElement(const char* container, const char* name);
        UIElement* FindElement(const char* name);
        UIElementGroupContainer* GetRootContainer() const;

    private:
        void UnloadProject();
        void LoadProject(SurfRide::Project* project, const csl::ut::MoveArray<SurfRide::Scene*>& scenes);
        void LoadScene(SurfRide::Scene* scene);
        void LoadElementsRecursively(UIElement* parent, UIElementGroup* group, UIElementGroupContainer* container, SurfRide::Cast* cast, csl::ut::MoveArray<SurfRide::Cast*>& casts);
        void SetupCastSizeBinders(UIElementGroup* group, const csl::ut::MoveArray<SurfRide::Cast*>& casts);
    };
}
