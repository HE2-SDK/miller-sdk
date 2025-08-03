#pragma once

namespace hh::needle {
    class EntryLink {
        EntryLink* prev;
        EntryLink* next;
    public:
        ~EntryLink() {
            Unlink();
        }
        void LinkNext(EntryLink* link);
        void Unlink();
    };
}
