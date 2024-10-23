#pragma once

namespace hh::text {
    class TagReplacer : public TagReplaceable {
    public:
        class Entity : public fnd::ReferencedObject {
            bool unk3;
            csl::ut::VariableString name;
            csl::ut::VariableString unk1;
            csl::ut::MoveArray<void*> unk2;
        public:
            Entity(csl::fnd::IAllocator* pAllocator, const char **name);
            static Entity* Create(csl::fnd::IAllocator* pAllocator, const char **name);
        };

    private:
        csl::ut::MoveArray<Entity*> entities;
        csl::ut::StringMap<Entity*> entitiesByName;

        Entity& GetEntityByName(const char* name);
        void RegisterEntity(Entity* entity);
    public:
        TagReplacer(csl::fnd::IAllocator* pAllocator);

        void SetLocalizationVariable(const char* name, const char* value);
        // void SetLocalizationVariable(const char* name);

        virtual void* UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual uint32_t UnkFunc3(void* unkParam1, void* unkParam2) override;
        virtual void* UnkFunc4(void* unkParam1) override;
        virtual bool UnkFunc5(void* unkParam1, void* unkParam2) override;
        virtual void* UnkFunc6(void* unkParam1, void* unkParam2, void* unkParam3) override;
        virtual void* UnkFunc7(void* unkParam1, void* unkParam2) override;
    };
}
