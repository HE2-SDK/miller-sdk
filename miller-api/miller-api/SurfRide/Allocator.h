#pragma once

namespace SurfRide {
    csl::fnd::IAllocator* GetAllocator();
    void* SrAllocate(size_t size);
    void SrFree(void* ptr);
}
