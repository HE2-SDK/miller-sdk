#pragma once

namespace app::game {
    class GOCEventListener {
    public:
        virtual void EventCallback(unsigned int event) {}
    };

    class GOCEvent : public hh::game::GOComponent {
    public:
        enum Flag : uint8_t {
            ENABLED,
            UNK1,
            MAYBE_DEACTIVATE_AFTER_EVENT,
        };

        struct SetupInfo {
            bool enabled;
            bool maybeDeactivateAfterEvent;

            SetupInfo();
        };

        csl::ut::MoveArray<GOCEventListener*> listeners;
        csl::ut::Bitset<Flag> flags;

        virtual void* GetRuntimeTypeInfo() override;

        void Setup(const SetupInfo& setupInfo);
        void AddListener(GOCEventListener* listener);
        void RemoveListener(GOCEventListener* listener);

        GOCOMPONENT_CLASS_DECLARATION(GOCEvent);
    };
}
