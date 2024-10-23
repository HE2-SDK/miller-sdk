#pragma once

namespace hh::fw {
    class SaveManagerInterface : public fnd::ReferencedObject, public fnd::user::UserInfoEventListener {
    public:
        uint32_t dword20;
        uint32_t dword24;
        uint64_t qword28;
        uint8_t byte30;
        uint8_t byte31;
        csl::ut::MoveArray<void*> unk38;
        csl::ut::MoveArray<void*> unk58;
        uint16_t word78;
        uint64_t qword80;
        uint64_t qword88;

        SaveManagerInterface(csl::fnd::IAllocator* allocator);
    };
}
