#pragma once

namespace hh::fnd {
    class ResReflection : public ManagedResource {
    public:
        void* reflectionData;
        uint64_t unk1;
        uint64_t unk2;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        inline void* GetData() {
            return reflectionData;
        }

        MANAGED_RESOURCE_CLASS_DECLARATION(ResReflection)
    };

    template<typename T>
    class ResReflectionT : public ResReflection {
    public:
        inline T* GetData() {
            return static_cast<T*>(ResReflection::GetData());
        }

        inline static const ResourceTypeInfo* GetTypeInfo() {
            return ResReflection::GetTypeInfo();
        }
    };
}
