#pragma once

namespace Cyan::System {
    template<typename T>
    class LinkList {
    public:
        class Entry {
        public:
            T* value;
            Entry* prev;
            Entry* next;
        };

        Entry sentinel;
        volatile long long first; // pointer to first entry, as a volatile long long
        volatile long length;

        inline void push_back(T* value) {
            _m_prefetchw(&first);

            T* old;
            do {
                old = (T*)first;
                value->next = old;
                value->prev = nullptr;
            } while (old != InterlockedCompareExchange64(&first, (long long)value, (long long)old));
            
            old->prev = value;

            InterlockedExchangeAdd(&length, 1);
        }

        // inline void clear() {
        //     Entry* current = sentinel.prev;

        //     while (current) {
        //         if ((long long)current == first)
        //             first = (long long)current->next;
        //     }
        // }
    };
}
