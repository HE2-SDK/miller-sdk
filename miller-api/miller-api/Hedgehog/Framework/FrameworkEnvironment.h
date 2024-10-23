#pragma once

namespace hh::fw {
    class FrameworkEnvironment {
    public:
        class CriSystemThing {
        public:
            csl::ut::InplaceMoveArray<void*, 10> unk1;
            csl::ut::InplaceMoveArray<void*, 30> unk2;
            csl::ut::InplaceMoveArray<void*, 10> unk3;
            CriSystemThing();
        };

        bool unk1;
        fnd::SUpdateInfo updateInfo;
        Window* window;
        FrameworkOptions* options;
        uint64_t unk7;
        uint32_t unk8;
        uint32_t unk8b;
        uint64_t unk9;
        uint64_t unk10;
        uint64_t unk11;
        EventStack* eventStack;
        CriSystemThing criSystemThing;
        fnd::Reference<font::FontContainer> fontContainer;
        uint8_t flags;

        FrameworkEnvironment(csl::fnd::IAllocator* allocator);
    };
}
