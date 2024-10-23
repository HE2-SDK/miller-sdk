#pragma once

namespace hh::anim {
    struct EventData;
    class EventArray {
    public:
        csl::ut::StringMap<EventData*> eventsByName;

        EventData* GetEventData(const char* name);
    };
}
