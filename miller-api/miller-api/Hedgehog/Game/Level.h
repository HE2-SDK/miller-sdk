#pragma once

namespace hh::game {
    class LevelListener {
    public:
        virtual ~LevelListener() = default;

        virtual void LL_UnkFunc1(void* unkParam1) {}
        virtual void LL_UnkFunc2(void* unkParam1) {}
        virtual void LL_UnkFunc3(void* unkParam1) {}
    };

    class MasterLevel;
    class Level : public fnd::ReferencedObject {
    public:
        csl::ut::VariableString name;
        MasterLevel* masterLevel;
        fnd::Reference<ResLevel> resource;
        csl::ut::InplaceMoveArray<csl::ut::VariableString, 2> files;
        fnd::Reference<fnd::ResourceLoader> resourceLoader;
        uint64_t unk3;
        csl::ut::MoveArray<Level*> dependencies;
        csl::ut::InplaceMoveArray<LevelListener*, 1> listeners;
        bool loaded;
        uint16_t wordCA;
        uint32_t loadStatus;
        uint8_t byteD0;
        int dwordD4;
        csl::ut::VariableString unk1;
        csl::ut::VariableString unk2;

        struct LoadInfo {
            uint8_t unk1{};
            int unk2{};
            const char* unk3{};
            const char* unk4{};
        };

        CREATE_FUNC(Level, const char* name, MasterLevel* masterLevel);
        void Setup(); // incorrect, this has an extra parameter.

        void AddListener(LevelListener* listener);
        void RemoveListener(LevelListener* listener);
        void AddDependency(Level* dependency);
        void AddResource(const char* resource);
        bool Load();
        void Load2();
        void Load3(const LoadInfo& loadInfo);
        void Unload();
    };
}
