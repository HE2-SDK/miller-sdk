#pragma once

#define MANAGED_RESOURCE_CLASS_DECLARATION(ClassName) private:\
		static const hh::fnd::ResourceTypeInfo typeInfo;\
		ClassName(csl::fnd::IAllocator* allocator);\
		static hh::fnd::ManagedResource* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::fnd::ResourceTypeInfo* GetTypeInfo();

namespace hh::fnd {
    class ManagedResource;

    struct ResourceTypeInfo {
        const char *pName;
        const char *pScopedName;
        size_t objectSize;
        bool isInBinaContainer;
        bool unk1;
        ManagedResource* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class ResourceResolver;
    class StaticResourceContainer;
    class ManagedResource : public ReferencedObject, private csl::ut::NonCopyable {
    public:
        void* ref2InnerData;
        size_t unk1;
        uint32_t ref2Hash;
        bool isRef2;
        csl::ut::VariableString unk5;
        csl::ut::MoveArray<void*> unk6;
        csl::ut::VariableString name2;
        csl::ut::VariableString unkStrPrefix; // before hyphen
        csl::ut::VariableString unkStrPostfix; // after hyphen
        // in rangers there were 6 members here, now there are only 5, don't know which one is missing
        const ResourceTypeInfo* resourceTypeInfo;
        void* unpackedBinaryData;
        size_t size;
        FileResource* file;
        csl::fnd::IAllocator* resourceAllocator;
        uint16_t unk7;
        uint8_t unk8;

        ManagedResource(csl::fnd::IAllocator* pAllocator);

        inline const char* GetName() const {
            return name2.c_str();
        }

        // This doesn't work. Seems to be a bug.
        const char* GetName_() const;

        inline const ResourceTypeInfo& GetClass() const {
            return *resourceTypeInfo;
        }

        void* GetData() const;
        size_t GetSize() const;

        inline csl::fnd::IAllocator* GetResourceAllocator() {
            return resourceAllocator;
        }

        static ManagedResource* Create(csl::fnd::IAllocator* allocator, FileResource* file, const char* name, ResourceTypeInfo* resourceTypeInfo);
        static ManagedResource* Create(csl::fnd::IAllocator* allocator, csl::fnd::IAllocator* resourceAllocator, const char* unkStrParam, const char* name, void* data, size_t size, ResourceTypeInfo* resourceTypeInfo);

		virtual void ReferencedObject_UnkFunc1(const ReferencedObject::Unk1& unkParam) override;
        virtual void Load(void* data, size_t size) = 0;
        virtual void LoadRef2(void* data, size_t size);
        virtual void Unload() = 0;
        virtual void Resolve(ResourceResolver& resolver) {}
        virtual uint64_t UnkFunc5() {}
        virtual void Reload(void* data, size_t size);

        void SetFile(FileResource* file);
    };
}
