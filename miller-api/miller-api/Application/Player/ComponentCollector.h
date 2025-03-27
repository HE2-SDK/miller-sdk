#pragma once

namespace app::player {
    struct ComponentCollection;
    struct Component {
        ComponentCollection* collection;
        csl::ut::MoveArray<hh::fnd::Reference<hh::game::GOComponent>> components;
        hh::fnd::Reference<hh::gfx::GOCVisualModel> visual;
        hh::fnd::Reference<hh::anim::GOCAnimator> animator;
        csl::ut::MoveArray<hh::eff::EffectHandle> effects;
        uint64_t unk3;

        void AddComponent(hh::game::GOComponent* component);
        void RemoveComponent(hh::game::GOComponent* component);
        void UpdateVisibility();
    };

    class ComponentCollector;
    struct ComponentCollection {
        enum class Flag {
            UNK0,
            VISIBLE,
        };

        csl::ut::MoveArray<Component> components;
        ComponentCollector* componentCollector;
        uint64_t unk3;
        csl::ut::Bitset<Flag> flags;

        ComponentCollection();
        void Initialize(hh::game::GameObject* gameObject, unsigned int componentCount);
        Component& GetComponent(int id);
        hh::fnd::HFrame* GetFrame() const;
        void SetVisibility(bool visible);
    };

    class GOCPlayerVisual;
    class ComponentCollector : public hh::fnd::ReferencedObject {
    public:
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        ComponentCollection componentCollections[3];
        hh::fnd::Reference<hh::fnd::HFrame> frame;
        int currentPlayerVisual;
        int unk3;
        bool unk4;

        ComponentCollector(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, GOCPlayerVisual* gocPlayerVisual);
        void AttachFrames();
        void SetCurrentPlayerVisual(int id, bool unk4Param);
    };
}
