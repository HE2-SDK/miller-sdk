
#pragma once

namespace hh::fnd {
    class ResourceTypeRegistry : public BaseObject, public csl::fnd::Singleton<ResourceTypeRegistry> {
        csl::ut::StringMap<const ResourceTypeInfo*> typeInfosByName;
        csl::ut::StringMap<const ResourceTypeInfo*> typeInfosByExtension;
        csl::ut::PointerMap<const ResourceTypeInfo*, const char*> extensionsByTypeInfo;

        static const ResourceTypeInfo* typeInfos[81];
        // If you uncomment this, cppsharp crashes.
        // static csl::ut::Pair<const char*, const ResourceTypeInfo*> typeInfoExtensionMap[44];
    public:
        ResourceTypeRegistry();
        static ResourceTypeRegistry* Create();
        void GetTypeInfos(csl::ut::MoveArray<const ResourceTypeInfo*>& typeInfos);
        const ResourceTypeInfo* GetTypeInfoByName(const char* name);
        const ResourceTypeInfo* GetTypeInfoByExtension(const char* extension);
        const char* GetExtensionByTypeInfo(const ResourceTypeInfo* typeInfo);

        inline void RegisterTypeInfo(const ResourceTypeInfo* typeInfo) {
            typeInfosByName.Insert(typeInfo->pScopedName, typeInfo);
        }

        inline void RegisterExtension(const char* extension, const ResourceTypeInfo* typeInfo) {
            typeInfosByExtension.Insert(extension, typeInfo);
        }
    };
}
