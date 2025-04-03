#pragma once

namespace hh::dv {
    class DvResource : public DvResourceBase {
    public:
        fnd::ManagedResource* resource;

        DvResource(csl::fnd::IAllocator* allocator);
    };
}
