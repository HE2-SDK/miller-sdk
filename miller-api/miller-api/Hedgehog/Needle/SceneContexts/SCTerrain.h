#pragma once

namespace hh::needle {
    class SCTerrain : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCTerrain& sceneContext;
            uint32_t dword18;
            uint8_t byte1C;
            uint32_t dword20;
            float dword24;
            float dword28;
            uint8_t byte2C;
            float dword30;
            float dword34;
            float dword38;
            float qword3C;
            uint32_t qword40;
            uint32_t qword44;
            uint32_t qword48;
            uint32_t dword4C;
            uint64_t qword50;
            uint64_t qword58;
            uint64_t qword60;
            uint64_t qword68;
            uint64_t qword70;
            uint64_t qword78;
            uint64_t qword80;
            uint64_t qword88;
            uint64_t qword90;
            intrusive_ptr<NeedleRefcountObject> qword98[6];
            intrusive_ptr<NeedleRefcountObject> qwordC8[6];
            uint64_t qwordF8;
            uint64_t qword100;
            uint64_t qword108;
            csl::ut::MoveArray<void*> qword110;
            intrusive_ptr<NeedleRefcountObject> qword130[6];

        public:
            Impl(SCTerrain& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCTerrain);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
