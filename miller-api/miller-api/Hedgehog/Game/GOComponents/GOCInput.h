#pragma once

namespace hh::game {
    class GOCInput : public GOComponent, public InputListener {
        bool startListeningOnInitialization;
        // These are copied to InputComponent on GOC event activate
        uint8_t inputComponentInternalPlayerInputIndex;
        uint8_t inputComponentPriority;
        uint8_t inputComponentActionMonitorCount;
        uint8_t inputComponentAxisMonitorCount;
        uint8_t inputComponentUnknownMonitorCount;
        bool inputComponentUnk7;
        bool unk104;
        hh::game::InputComponent* inputComponent;

    public:
        struct alignas(8) Config {
            bool unk1;
            uint32_t inputComponentInternalPlayerInputIndex;
            uint32_t inputComponentPriority;
            uint32_t inputComponentActionMonitorCount;
            uint32_t inputComponentAxisMonitorCount;
            uint32_t inputComponentUnknownMonitorCount;
            bool inputComponentUnk7;
        };

        GOCInput(csl::fnd::IAllocator* pAllocator);
        static GOCInput* Create(csl::fnd::IAllocator* pAllocator);
        static GOComponentClass* GetClass();
        void Initialize(const Config& config);
		virtual void* GetRuntimeTypeInfo() const;
		virtual bool fUnk5() { return true; }
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data);
        
        inline InputComponent* GetInputComponent() const {
            return inputComponent;
        }
    };
}
