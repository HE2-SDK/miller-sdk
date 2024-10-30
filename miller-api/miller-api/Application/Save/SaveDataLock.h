#pragma once

namespace app::save {
    class SaveDataLock : public hh::fnd::ReferencedObject {
    public:
        SaveDataLock(csl::fnd::IAllocator* allocator) : ReferencedObject{ allocator, true } {}
    };
}
