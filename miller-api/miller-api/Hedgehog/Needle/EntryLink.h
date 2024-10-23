#pragma once

namespace hh::needle {
    class EntryLink {
        EntryLink* prev;
        EntryLink* next;
    public:
        void LinkNext(EntryLink* link);
        void Unlink();
    };
}
