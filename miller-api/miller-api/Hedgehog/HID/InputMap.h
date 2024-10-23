#pragma once

namespace hh::hid {
    class ActionMapping : public fnd::ReferencedObject {
    public:
        struct Binding {
            uint32_t inputId;
            int unk; 
        };

    private:
        uint8_t unk1;
        bool unk2;
        csl::ut::VariableString name;
        csl::ut::MoveArray<Binding> bindings;
    public:
        ActionMapping(csl::fnd::IAllocator* pAllocator, const char* name);
        void BindInput(uint32_t inputId, int unkParam);
    };

    class AxisMapping : public fnd::ReferencedObject {
    public:
        struct Binding {
            uint32_t inputId;
            float limit;
            float treshold;
            int unk;
        };
    private:
        uint8_t unk1;
        csl::ut::VariableString name;
        csl::ut::MoveArray<Binding> bindings;
    public:
        AxisMapping(csl::fnd::IAllocator* pAllocator, const char* name);
        void BindInput(uint32_t inputId, float limit, int unkParam);
        void BindInputEx(uint32_t inputId, float limit, float threshold, int unkParam);
    };

    class InputMapSettings : public fnd::ReferencedObject {
        csl::ut::MoveArray<ActionMapping*> actionMappings;
        csl::ut::MoveArray<AxisMapping*> axisMappings;
        uint32_t maxMappingUnk1PlusOne;
        float unk4; // in musashi default 0.4
        float unk5; // in musashi default 0.15

    public:
        InputMapSettings(csl::fnd::IAllocator* pAllocator);

        int FindActionMappingId(const char* name);
        int FindAxisMappingId(const char* name);

        inline void BindActionMapping(const char* mappingName, uint32_t inputId) {
            return BindActionMapping(mappingName, inputId, -1);
        }
        
        inline void BindAxisMapping(const char* mappingName, uint32_t inputId, float limit) {
            return BindAxisMapping(mappingName, inputId, limit, -1);
        }

        inline void BindAxisMappingEx(const char* mappingName, uint32_t inputId, float limit, float threshold) {
            return BindAxisMappingEx(mappingName, inputId, limit, threshold, -1);
        }
        
        void BindActionMapping(const char* mappingName, uint32_t inputId, int unkParam);
        void BindAxisMapping(const char* mappingName, uint32_t inputId, float limit, int unkParam2);
        void BindAxisMappingEx(const char* mappingName, uint32_t inputId, float limit, float threshold, int unkParam2);
        
        uint8_t GetActionMappingUnk1(int actionMappingId);
        uint8_t GetAxisMappingUnk1(int axisMappingId);
        void SetActionMappingUnk1(const char* mappingName, uint8_t value);
        void SetActionMappingUnk2(const char* mappingName, bool value);
    };

    class InputMap : public fnd::ReferencedObject {
    public:
        struct Config {
            InputMapSettings* settings;
            csl::ut::InplaceMoveArray<InputDevice*, 10> devices;
            uint32_t unk3;
        public:
            Config();
            void AddDevice(InputDevice* device);
        };

    private:
        InputMapSettings* settings;
        csl::ut::InplaceMoveArray<InputDevice*, 5> devices;
        csl::ut::MoveArray<void*> actionMaps;
        csl::ut::MoveArray<void*> axisMaps;
        csl::ut::MoveArray<void*> unk5;
        uint32_t unk6;
        float unk7; // the 2 floats from the settings
        float unk8;
        uint32_t unk9; // unk3 from config

    public:
        InputMap(csl::fnd::IAllocator* pAllocator, Config& config);
    };
}
