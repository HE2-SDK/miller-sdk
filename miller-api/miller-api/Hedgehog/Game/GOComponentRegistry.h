#pragma once

namespace hh::game
{
    class GOComponentRegistry : fnd::BaseObject {
    public:
        class GOComponentRegistryItem {
            const char* name;
            const GOComponentClass* componentClass;
            const fnd::RflClass* rflClass;

        public:
            inline const char* GetName() const { return name; }
            inline const GOComponentClass* GetComponentClass() const { return componentClass; }
            inline const fnd::RflClass* GetSpawnerDataClass() const { return rflClass; }
        };
    private:
        csl::ut::MoveArray<GOComponentRegistryItem*> components;
        csl::ut::StringMap<GOComponentRegistryItem*> componentsByName;

        static GOComponentRegistryItem* staticGOComponentRegistryItems[3];
    public:
        GOComponentRegistry(csl::fnd::IAllocator* pAllocator);
        void LoadComponents(GOComponentRegistryItem** components);

        inline const GOComponentRegistryItem* GetComponentInformationByName(const char* name) {
            return componentsByName.GetValueOrFallback(name, nullptr);
        }

        inline const csl::ut::MoveArray<GOComponentRegistryItem*>& GetComponents() {
            return components;
        }
    };

    struct GOComponentConfiguration {
        GOComponentRegistry::GOComponentRegistryItem* component;
        void* data;
    };
}
