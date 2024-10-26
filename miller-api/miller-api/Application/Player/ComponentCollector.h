#pragma once

namespace app::player {
    class GOCPlayerVisual;
    class ComponentCollector : public hh::fnd::ReferencedObject {
    public:
        struct Unk1 {
            struct Unk2 {
                uint64_t unk1[12];
            };
            csl::ut::MoveArray<Unk2> unk1;
            ComponentCollector* componentCollector;
            uint64_t unk3;
            uint8_t unk4;

            Unk1();
        };

    private:
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        Unk1 unk1[4];
        hh::fnd::Reference<hh::fnd::HFrame> frame;
        uint64_t unk2;
        bool unk3;

    public:
        ComponentCollector(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, GOCPlayerVisual* gocPlayerVisual);
        Unk1& GetUnk1ByIndex(char idx);
    };
}