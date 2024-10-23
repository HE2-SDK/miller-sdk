#pragma once

namespace hh::needle {
    class GraphicsMemoryLayout : public NeedleObject {
    public:
        size_t ObtainRequestSize(MemoryType memoryType, size_t size, size_t alignment);
    };
}
