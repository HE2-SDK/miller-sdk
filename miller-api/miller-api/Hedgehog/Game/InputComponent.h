#pragma once

namespace hh::game {
    class InputListener {
	public:
		virtual ~InputListener() = default;
        virtual void IL_UnkFunc1() {};
        virtual void IL_UnkFunc2() {};
    };

    class InputComponent : public fnd::ReferencedObject {
    public:
        enum class Flags : char {
            LISTENING = 0,
            CAPTURE_INPUTS = 1,
        };
        // enum class ActionState : uint16_t {
        //     PRESSED
        // }

        template<typename T>
        struct InputMonitor {
            csl::ut::Bitset<Flags> flags; //this seems to be kept in sync with the inputcomponent's flags (see SetUnk5Flag1)
            uint8_t inputMapSettingsIndex;
            int16_t mappingId;
            uint8_t mappingUnk1;
            T state;
        };

        struct ActionMonitor : InputMonitor<uint16_t> {};
        struct AxisMonitor : InputMonitor<float> {};
        struct UnkMonitor : InputMonitor<csl::math::Vector4> {};

    private:
        char internalPlayerInputIndex;
        char objectLayer;
        char priority;
        bool unk4; // GOCInput's unk103
    public:
        csl::ut::Bitset<Flags> flags;
    private:
        InputManager* inputManager_; // This is set in RegisterInputComponent and used in GOCInput's OnGOCEvent and in SetUnk5Flag1, but I don't know why this is a separate pointer.
        InputManager* inputManager;
        InternalPlayerInput* internalPlayerInput;
        csl::ut::VariableString objectName;
        csl::ut::InplaceMoveArray<InputListener*, 2> inputListeners;
    public:
        csl::ut::MoveArray<ActionMonitor> actionMonitors;
        csl::ut::MoveArray<AxisMonitor> axisMonitors;
        csl::ut::MoveArray<UnkMonitor> unkMonitors; // probably not a vector but it takes the same space and alignment

        struct Config {
            uint32_t internalPlayerInputIndex;
            uint32_t objectLayer;
            uint32_t priority;
            int actionMonitorCount;
            int axisMonitorCount;
            int unkMonitorCount;
            const char* objectName;
            bool exclusive; // flag 1
        };

        InputComponent(csl::fnd::IAllocator* pAllocator, const Config& config, InputManager** inputManager);
        static InputComponent* Create(csl::fnd::IAllocator* pAllocator, const Config& config, InputManager** inputManager);
        static InputComponent* Create(csl::fnd::IAllocator* pAllocator, const Config& config, InputManager* inputManager);

        inline char GetInternalPlayerInputId() {
            return internalPlayerInputIndex;
        }

        inline bool IsListening() {
            return flags.test(Flags::LISTENING);
        }

        void RegisterInputListener(InputListener& listener);
        void UnregisterInputListener(InputListener& listener);

        void SetListening(bool value);
        void SetActionEnabled(int actionMonitorId, bool value);
        void SetAxisEnabled(int actionMonitorId, bool value);

        void MonitorActionMapping(const char* actionMappingName, int actionMonitorId, int unused);
        void MonitorAxisMapping(const char* axisMappingName, int axisMonitorId);
    };
}