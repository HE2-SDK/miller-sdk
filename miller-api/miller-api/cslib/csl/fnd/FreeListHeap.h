#pragma once

namespace csl::fnd {
    class FreeListHeapBase : public FreeListHeapCommonBase {
        bool initialized;

    public:
        FreeListHeapBase(const char* name);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual const char* GetHeapTypeName() const override;

        void Initialize(void* unkParam1, void* unkParam2, size_t unkParam3);
    };

    template<typename TLock>
    class alignas(8) FreeListHeapTemplate : public FreeListHeapBase {
        TLock m_Lock;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
        virtual void Lock() override;
        virtual void Unlock() override;
    };
}
