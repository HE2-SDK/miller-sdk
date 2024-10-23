#pragma once

namespace hh::hid {
    class DeviceManagerWin32 : public DeviceManager, public csl::fnd::Singleton<DeviceManagerWin32> {
        uint64_t unk101;
        uint64_t unk102;
        uint64_t unk103;
        uint32_t unk104;
        csl::ut::MoveArray<void*> unk105;
        csl::ut::MoveArray<void*> unk106;
        csl::ut::MoveArray<void*> unk107;
        csl::ut::MoveArray<void*> unk108;
        char unk109;
    public:
        DeviceManagerWin32(csl::fnd::IAllocator* pAllocator);
    };
}
