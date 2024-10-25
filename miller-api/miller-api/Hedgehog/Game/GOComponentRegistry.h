#pragma once

namespace hh::game
{
    class GOComponentRegistry : fnd::BaseObject {
    public:
        class GOComponentRegistryItem {
        public:
            const char* name;
            const GOComponentClass* componentClass;
            const fnd::RflClass* rflClass;
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
