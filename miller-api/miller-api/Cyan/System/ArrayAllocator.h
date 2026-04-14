#pragma once

namespace Cyan::System {
    template<size_t Len>
    class ArrayAllocator : public IAllocator {
    public:
        const char* name;
        void* start;
        size_t size;
        unsigned int numIndices;
        void* mem2;
        unsigned int* indices;
        uint32_t unk1;
        uint32_t unk2;

        virtual void* Alloc(size_t size) override;
        virtual void* Alloc(size_t size, const char* name, size_t alignment) override;
        virtual void Free(void* ptr) override;
        virtual void SetupMemory(void* ptr, size_t size) override;
        virtual void SetName(const char* name) override;
        virtual const char* GetName() const override;
    };
}