#pragma once

namespace hh::ui {
    class LayerController;
    class UIManager;
    class GOCSprite : public game::GOComponent {
    public:
        enum class Flag : uint8_t{
            HAS_RENDERABLE_MAYBE,
            ENABLED,  
        };

        struct Unk1 {

        };

    private:
        class Renderable : public gfnd::Renderable {
            GOCSprite* gocSprite;
        public:
            Renderable(csl::fnd::IAllocator* pAllocator);
            virtual void Render(const gfnd::RenderableParameter* renderableParameter) override;
        };

    public:
        csl::fnd::Delegate<void (GOCSprite*)> OnProjectUnloaded;
        csl::fnd::Delegate<void (GOCSprite*)> OnProjectLoaded;
        csl::fnd::Delegate<void (GOCSprite*)> OnLayerControllerCreated;
        UIManager* uiManager;
        fnd::Reference<SurfRide::Project> project;
        hh::ui::ResSurfRideProject* projectResource;
        csl::ut::VariableString projectName;
        bool initialized;
        fnd::Reference<SurfRideProjectContext> projectContext;
        csl::ut::MoveArray<LayerController*> layerControllers;
        csl::ut::MoveArray<void*> field_138;
        csl::ut::MoveArray<void*> field_158;
        uint64_t renderable;
        csl::ut::Bitset<Flag> flags;
        unsigned short nextId;
        ViewportDimensions viewportDimensions;
        uint64_t field_190;
        uint64_t field_198;
        uint64_t field_1A0;
        uint64_t field_1A8;
        csl::ut::MoveArray<SurfRideCastHandle*> castHandles;
        csl::ut::PointerMap<SurfRide::Cast*, SurfRideCastHandle> castHandleMap;
        csl::ut::MoveArray<SurfRideLayerHandle*> layerHandles;
        csl::ut::PointerMap<SurfRide::Layer*, SurfRideLayerHandle> layerHandleMap;

        LayerController* CreateLayerController(SurfRide::Layer* layer, unsigned short id);
        fnd::Handle<SurfRideCastHandle> GetCastHandle(SurfRide::Cast* cast);
        fnd::Handle<SurfRideLayerHandle> GetLayerHandle(SurfRide::Layer* layer);

        struct SetupInfo {
            hh::ui::ResSurfRideProject* resource{};
            const char* name{};
            unsigned int renderableContainer{ 7 };
            unsigned char renderPriority{ 10 };
            unsigned int renderableUnk5{ 2 };
            unsigned int layerControllerCount{};
            unsigned int updatePriority{ 2 };
            ViewportDimensions viewportDimensions{};
        };
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& config);
        LayerController* GetLayerController(unsigned short id) const;
        LayerController* CopyLayerController(LayerController* layerController, unsigned short id);
        LayerController* CopyLayerController(SurfRide::Layer* layer, unsigned short id);
        LayerController* CreateLayerController(const char* sceneName, const char* layerName, unsigned short id);
        LayerController* CreateLayerControllerWithNextId(SurfRide::Layer* layer);
        SurfRide::Project* GetProject();

        void SetFlag(Flag flag, bool enabled);
        void EnableFlag(Flag flag);
        void DisableFlag(Flag flag);

        GOCOMPONENT_CLASS_DECLARATION(GOCSprite)
    };
}