#pragma once

namespace hh::fnd {
    namespace res {
        class PacV4Header {
        public:
            struct Header {
                enum class Type : unsigned char {
                    ROOT,
                    SPLIT,
                    HAS_SPLITS,
                };

                enum class RuntimeFlag : unsigned char {
                    LOADED,
                    UNK1,
                    BYTESWAPPED,
                    RESOLVED,
                };

                unsigned int magic{};
                unsigned char version[3]{};
                char endianness{};
                unsigned int id{};
                unsigned int fileSize{};
                unsigned int dicSize{};
                unsigned int dependTableSize{};
                unsigned int dataEntriesSize{};
                unsigned int strTableSize{};
                unsigned int fileDataSize{};
                unsigned int offsetTableSize{};
                csl::ut::Bitset<Type> type{};
                csl::ut::Bitset<RuntimeFlag> runtimeFlags{};
                unsigned char flags{};
                unsigned char dicCount{};
                unsigned short dependCount{};
            };

            Header* header;

            bool IsValid() const;
            void Convert();
            void Resolve();
            bool IsRoot() const;
        };
    }

    class Packfile : public ManagedResource {
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<StaticResourceContainer*> resourceContainers;
        csl::ut::PointerMap<ResourceTypeInfo*, int> resourceIdByClass;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::VariableString unk5;
        csl::ut::MoveArray<void*> unk6;
        uint8_t unk8;
        volatile int spinLock;

        Packfile(csl::fnd::IAllocator* pAllocator);
        static ManagedResource* Create(csl::fnd::IAllocator* pAllocator);
    public:
        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        static const ResourceTypeInfo* GetTypeInfo();
        
        csl::ut::MoveArray<StaticResourceContainer*>& GetResourceContainers() {
            return resourceContainers;
        }

        StaticResourceContainer* GetResourceContainer(const ResourceTypeInfo* typeInfo) const;
        ManagedResource* GetResourceByName(const char* name, const ResourceTypeInfo* typeInfo);
        template<typename T>
        T* GetResourceByName(const char* name) {
            return static_cast<T*>(GetResourceByName(name, T::GetTypeInfo()));
        }
        const char* GetResourceIDName(int resourceId, const ResourceTypeInfo* typeInfo);
    };
}
