#pragma once

namespace hh::physics {
    class EventQueue : public fnd::ReferencedObject {
        csl::ut::MoveArray<void*> unk1;
    public:
        EventQueue(csl::fnd::IAllocator* allocator);
    };
}
