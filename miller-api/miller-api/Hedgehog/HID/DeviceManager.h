#pragma once

namespace hh::hid {
    class DeviceManager : public fnd::BaseObject {
    public:
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<InputDevice*> inputDevices;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        uint32_t unk5; // 8 nibbles with initial values going from 0 to 7
        Keyboard* keyboard;
        Mouse* mouse;
        ActiveDeviceManager* activeDeviceManager;
        VibrationManager* vibrationManager;
        void* unk8;
        InputDeviceFactory inputDeviceFactory;

        DeviceManager(csl::fnd::IAllocator* pAllocator);
        ActiveDeviceManager* GetActiveDeviceManager();
    };
}
