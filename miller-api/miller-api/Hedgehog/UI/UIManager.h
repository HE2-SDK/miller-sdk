#pragma once

namespace hh::ui {
    class UIManagerExtension : public fnd::ReferencedObject {
    public:
        UIManagerExtension(csl::fnd::IAllocator* allocator);
        virtual void* GetRuntimeTypeInfo() const;
        virtual void* AddedToUIManager() {}
        virtual void* RemovedFromUIManager() {}
    };

    class UIManagerListener {
    public:
        struct UIRenderInfo {
            const hh::gfnd::RenderableParameter* renderableParameter;
            // more here
        };

        virtual ~UIManagerListener() = default;
        virtual void ExtensionAddedCallback(UIManagerExtension* extension) {}
        virtual void ExtensionRemovedCallback(UIManagerExtension* extension) {}
        virtual void GOCSpriteAddedCallback(GOCSprite* gocSprite) {}
        virtual void GOCSpriteRemovedCallback(GOCSprite* gocSprite) {}
        virtual void TextObjectUpdaterAddedCallback(TextObjectUpdater* textObjectUpdater) {}
        virtual void TextObjectUpdaterRemovedCallback(TextObjectUpdater* textObjectUpdater) {}
        virtual void PreRenderCallback(UIRenderInfo& renderInfo) {}
    };

    class UIManager : public game::GameService, public game::GameStepListener {
    public:
        // struct UIActions {
        //     const char* up;
        //     const char* down;
        //     const char* left;
        //     const char* right;
        //     const char* decide;
        //     const char* cancel;
        //     const char* pageUp;
        //     const char* pageDown;
        // };

        struct Config {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            UITextInterface* textInterface;
            uint32_t unk6;
            const char* uiActions[8];
            const char* unk7[1]; // unk118 in the service
        public:
            Config();
        };

    private:
        uint32_t unk101;
        uint32_t unk101a;
        uint32_t unk102;
        uint32_t unk103;
        UITextInterface* textInterface;
        uint32_t unk105;
        const char* uiActions[8];
        void* unk106[1];
        csl::ut::MoveArray<fnd::Reference<UIManagerExtension>> extensions;
        csl::ut::MoveArray<UIManagerListener*> listeners;
        csl::ut::VariableString unk116[8];
        csl::ut::VariableString unk117[1];
        int unk119;
        uint32_t unk120;

    public:
        void Initialize(const Config& config);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PreStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        void AddExtension(UIManagerExtension* extension);
        void RemoveExtension(UIManagerExtension* extension);

        void AddGOCSprite(GOCSprite* gocSprite);
        void RemoveGOCSprite(GOCSprite* gocSprite);

        void AddTextObjectUpdater(TextObjectUpdater* textObjectUpdater);
        void RemoveTextObjectUpdater(TextObjectUpdater* textObjectUpdater);

        void AddListener(UIManagerListener* listener);
        void RemoveListener(UIManagerListener* listener);

        SurfRide::Project* SetupSurfRideProject(ResSurfRideProject* resource, csl::fnd::IAllocator* allocator);
        void RenderSurfRideProject(gfnd::RenderableParameter* renderableParameter, SurfRide::Project* project, const ViewportDimensions& viewportDimensions);

        GAMESERVICE_CLASS_DECLARATION(UIManager)
    };
}
