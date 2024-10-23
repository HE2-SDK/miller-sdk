#pragma once

namespace hh::fnd {
    struct ObjectWriter {
        void* ptr;
        int offset;
    };
    struct CopyInfo {
        RflClass* rflClass;
        void* data;
        int offset;
        int size;
    };

    struct CopiedObject {
        struct ObjectHeader {
            RflTypeInfo* typeInfo;
            void* data;
        };

        uint32_t magic;
        csl::fnd::IAllocator* allocator;
        unsigned int numChunks;
        CopiedObject::ObjectHeader* header;
    };

    // void csl::ut::Array<T1>::ClearAndDeallocate() [with T1=hh::fnd::<unnamed>::CopyInfo]
    void CalcCArraySize(const RflClassMember& rflClassMember);
    void CalcCstringSize(const char* str, int* size);
    void CalcVstringSize(const csl::ut::VariableString& str, int* size);
    void CalcExtraSize(const void* data, const RflClass& rflClass, int* size);
    void GetCopiedObjects(const void* data, const RflClass& rflClass, csl::fnd::IAllocator* allocator, csl::ut::MoveArray32<CopyInfo>* copyInfos, size_t* size);
    void SaveCstring(const char* str, void* data, ObjectWriter& objectWriter);
    void SaveVstring(const csl::ut::VariableString& str, void* data, csl::fnd::IAllocator* allocator, ObjectWriter& objectWriter);
    void SaveBody(const void* data, const RflClass& rflClass, csl::fnd::IAllocator* allocator, void* target, ObjectWriter& objectWriter);
    void SaveExtras(const void* data, const RflClass& rflClass, csl::fnd::IAllocator* allocator, void* target, ObjectWriter& objectWriter);

    class DeepCopier {
    public:
        // inline static void* Construct(const RflClass& rflClass, csl::fnd::IAllocator* allocator) {
        //     size_t rflClassSize = (rflClass.GetSizeInBytes() + 15) & 0xFFFFFFF0;

        //     void* buffer = static_cast<char*>(allocator->Alloc(rflClassSize + 48, 16));
        //     void* rflObj = reinterpret_cast<void*>(reinterpret_cast<size_t>(buffer) + 32);

        //     RflTypeInfo* typeInfo = hh::fnd::RflTypeInfoRegistry::GetInstance()->GetByName(rflClass.GetName());
        //     typeInfo->ConstructObject(rflObj, allocator);

        //     CopiedObject::ObjectHeader* header = new (reinterpret_cast<void*>(reinterpret_cast<size_t>(buffer) + 32 + rflClassSize)) CopiedObject::ObjectHeader{ typeInfo, rflObj };
        //     CopiedObject* copiedObj = new (buffer) CopiedObject{ 0xDEE6C061, allocator, 1, header };

        //     return rflObj;
        // }
        static void* Copy(const void* data, const RflClass& rflClass, csl::fnd::IAllocator* allocator);
        static void* Copy(const void* data, const RflClass& rflClass, csl::fnd::IAllocator* allocator, size_t* totalSize);
        static void Free(void* data);
    };
}
