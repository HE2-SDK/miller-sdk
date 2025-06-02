#pragma once

namespace hh::ui {
    struct UIElementEventArg {
        unsigned int unk1;
        uint64_t unk2;
    };

    class UIElement;

    class UIElementTraverser {
    public:
        virtual ~UIElementTraverser() = default;
        virtual void BeginElement(UIElement* element) {}
        virtual void EndElement(UIElement* element) {}
    };

	struct UIElementClass {
		typedef UIElement* CreateFunction(csl::fnd::IAllocator* allocator);

		const char* name{};
		const char* prefix{};
		CreateFunction* instantiator{};
    };

    class UIElement : public fnd::ReferencedObject {
    public:
        class UIElementListener {
        public:
            virtual ~UIElementListener();
            virtual void UIEL_UnkFunc1() {}
        };

        struct Unk1 {
            uint32_t unk1;
            uint64_t unk2;
            UIElement* element;
            uint32_t unk3;
        };

        csl::fnd::Delegate<void (UIElement*, UIElementEventArg&)> onEnabledChange; // tt
        csl::fnd::Delegate<void (UIElement*, UIElementEventArg&)> onVisibleChange;
        csl::fnd::Delegate<void (UIElement*, UIElementEventArg&)> onCollisionChange; // tt
        csl::fnd::Delegate<void ()> unk4;
        csl::fnd::Delegate<void ()> unk5;
        csl::fnd::Delegate<void ()> unk6;
        csl::fnd::Delegate<void ()> unk6a;
        fnd::Handle<GOCUIComposition> hGOCUIComposition;
        fnd::Handle<GOCUICollider> hGOCUICollider;
        fnd::Handle<GOCSprite> hGOCSprite;
        csl::ut::MoveArray<UIElementListener*> listeners;
        csl::fnd::Delegate<void ()> unk8;
        csl::ut::VariableString name;
        csl::ut::VariableString type;
        fnd::Handle<SurfRideLayerHandle> hLayer;
        fnd::Handle<SurfRideCastHandle> hCast;
        UIElement* parent;
        csl::ut::MoveArray<fnd::Reference<UIElement>> children;
        bool enabled; // tt
        bool collisionEnabled; // tt
        bool updateRequired;
        bool asyncUpdatesEnabled;

        UIElement(csl::fnd::IAllocator* pAllocator, const char* name, GOCUIComposition* gocUIComposition);
        UIElement(csl::fnd::IAllocator* pAllocator, SurfRide::Cast* cast, GOCUIComposition* gocUIComposition);

        virtual void* GetRuntimeTypeInfo() const;
        virtual void Update(const fnd::SUpdateInfo& updateInfo) {}
        virtual void UpdateAsync(const fnd::SUpdateInfo& updateInfo) {}
        virtual void Initialize() {}
        virtual void Deinitialize() {}
        virtual void Focus() {}
        virtual void Unfocus() {}
        virtual void UnkFunc8() {}
        virtual bool ProcessMessage(fnd::Message& message) { return false; }
        virtual void ProcessActionInput(const game::InputListener::ActionInputInfo& actionInputInfo) {}
        virtual void ProcessAxisInput(const game::InputListener::AxisInputInfo& axisInputInfo) {}
        virtual void UnkFunc12() {}
        virtual bool IsVisible() const;
        virtual bool UnkFunc14() { return true; }
        virtual void UnkFunc15() {}
        virtual void OnEnabledChange(); // tt
        virtual void OnCollisionEnabledChange(); // tt
        virtual void OnVisibleChange();
        virtual void DoSomethingWithUnk7(const Unk1& unkParam);

        bool IsCastVisible() const;
        void SetCastVisible(bool visible);
        void SetEnabled(bool enabled);
        void SetCollisionEnabled(bool enabled);
        void MarkUpdateRequired(bool enabled);
        void SetAsyncUpdatesEnabled(bool enabled);

        game::GameObject* GetGameObject() const;
        GOCSprite* GetGOCSprite() const;
        GOCUICollider* GetGOCUICollider() const;
        GOCUIComposition* GetGOCUIComposition() const;
        UITextInterface* GetTextInterface() const;
        void Traverse(UIElementTraverser* traverser);
        // This is a strange interface. The this pointer doesn't seem to be used in the function. Instead it uses parent.
        // Later note: maybe this is actually a helper function on UIObject
        UIElement* FindDescendant(const char*& name, UIElement* parent);
        void AddChild(UIElement* child);

        void AddListener(UIElementListener* listener);
        void RemoveListener(UIElementListener* listener);
    };
}
