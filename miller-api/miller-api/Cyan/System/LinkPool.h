#pragma once

namespace Cyan::System {
    template<typename T, size_t size>
    class LinkPool {
        struct Entry {
            T data;
            LinkList<Entry>::Entry linkListEntry;

            Entry();
        };

        LinkList<Entry> available;
        LinkList<Entry> used;
        Entry pool[size];

        LinkPool();
    };
}
