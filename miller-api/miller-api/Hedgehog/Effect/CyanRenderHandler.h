#pragma once

namespace hh::eff {
    class CyanRenderHandler : Cyan::Graphics::ExternalMeshInstance<needle::Model, needle::PBRModelInstance>::RenderHandler {
    public:
        Cyan::Manager* cyanManager;
        uint64_t qword108;
        uint32_t dword110;
        uint64_t qword118;
        uint64_t qword120;
        uint8_t byte128;
        uint32_t qword12C;
        uint32_t qword130;
        uint32_t qword134;
        uint32_t qword138;
        uint32_t qword13C;
        uint32_t qword140;
        uint32_t qword144;
        uint32_t qword148;
        uint32_t qword14C;
        uint32_t qword150;

        virtual needle::PBRModelInstance* CreateModelInstance(needle::Model* model) override;
        virtual void SetVisible(needle::PBRModelInstance* modelInstance, bool visible) override;
        virtual void UnkFunc3(void* unkParam1, unsigned int unkParam2) override;
        virtual bool UnkFunc4(void* unkParam1) override;
        virtual void UnkFunc5() override {}
        virtual void UnkFunc6(needle::PBRModelInstance* modelInstance, void* unkParam1, void* unkParam2) override;
    };
}
