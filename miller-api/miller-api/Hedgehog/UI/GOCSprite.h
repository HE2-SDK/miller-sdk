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
        uint16_t nextId;
        ViewportDimensions viewportDimensions;
        uint64_t field_190;
        uint64_t field_198;
        uint64_t field_1A0;
        uint64_t field_1A8;
        csl::ut::MoveArray<SurfRideCastHandle> casts;
        csl::ut::PointerMap<SurfRide::Cast*, SurfRideCastHandle> castMap;
        csl::ut::MoveArray<SurfRideLayerHandle> layers;
        csl::ut::PointerMap<SurfRide::Layer*, SurfRideLayerHandle> layerMap;
        
        LayerController* GetLayerController(SurfRide::Layer* layer, uint16_t id);
        fnd::Handle<SurfRideCastHandle> GetCastHandle(SurfRide::Cast* cast);
        fnd::Handle<SurfRideLayerHandle> GetLayerHandle(SurfRide::Layer* layer);

        struct alignas(8) SetupInfo {
            hh::ui::ResSurfRideProject* projectResource;
            const char* name;
            uint32_t renderPass;
            uint8_t renderPriority;
            uint32_t renderableUnk5;
            uint32_t layerControllerCount;
            uint32_t unk5;
            ViewportDimensions viewportDimensions;
        };
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& config);
        LayerController* GetLayerController(const char* sceneName, const char* layerName, uint16_t id);
        LayerController* GetLayerControllerWithNextId(SurfRide::Layer* layer);
        SurfRide::Project* GetProject();

        void SetFlag(Flag flag, bool enabled);
        void EnableFlag(Flag flag);
        void DisableFlag(Flag flag);

        GOCOMPONENT_CLASS_DECLARATION(GOCSprite)
    };
}