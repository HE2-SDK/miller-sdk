#pragma once

namespace hh::fnd {
    class TagResourceContainerListener {
    public:
        virtual ~TagResourceContainerListener() = default;
        virtual void RMRU1L_UnkFunc1(uint64_t unkParam1, uint64_t unkParam2) {}
        virtual void RMRU1L_UnkFunc2(uint64_t unkParam1, uint64_t unkParam2) {}
    };

    class TagResourceContainer : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::StringMap<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::PointerMap<void*, void*> unk4;
        csl::ut::MoveArray<void*> unk5;
    public:
        TagResourceContainer(csl::fnd::IAllocator* allocator);
    };
}
