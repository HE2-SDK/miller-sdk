#pragma once

namespace hh::hid {
    class InputDeviceFactory : public fnd::BaseObject {
        csl::ut::StringMap<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::StringMap<void*> unk3;
    public:
        InputDeviceFactory(csl::fnd::IAllocator* pAllocator);
    };
}
