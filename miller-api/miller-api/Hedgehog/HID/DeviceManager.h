#pragma once

namespace hh::hid {
    class DeviceManager : public fnd::BaseObject {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<InputDevice*> inputDevices;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        uint32_t unk5; // 8 nibbles with initial values going from 0 to 7
        Keyboard* keyboard;
        Mouse* mouse;
        uint64_t unk7;
        ActiveDeviceManager* activeDeviceManager;
        void* unk8;
        InputDeviceFactory inputDeviceFactory;
    public:
        DeviceManager(csl::fnd::IAllocator* pAllocator);
        ActiveDeviceManager* GetActiveDeviceManager();
    };
}
