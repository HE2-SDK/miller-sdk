#pragma once

namespace hh::needle {
    class NeedleBlob : public NeedleRefcountObject {
    public:
        size_t size;

        static NeedleBlob* Create(size_t size);

        inline void* GetData() const {
            return reinterpret_cast<void*>(reinterpret_cast<size_t>((void*)this) + 0x20);
        }
    };
}
