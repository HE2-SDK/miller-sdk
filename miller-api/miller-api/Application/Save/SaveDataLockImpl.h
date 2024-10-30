#pragma once

namespace app::save {
    class SaveDataLockImpl : public SaveDataLock {
    public:
        hh::fnd::Reference<UserElement> userElement;

        SaveDataLockImpl(csl::fnd::IAllocator* allocator, UserElement* userElement) : SaveDataLock{ allocator }, userElement { userElement } {
            userElement->mutex.Lock();
        }

        virtual ~SaveDataLockImpl() {
            userElement->mutex.Unlock();
        }
    };
}
