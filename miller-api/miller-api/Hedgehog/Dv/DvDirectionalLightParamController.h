#pragma once

namespace hh::dv{
    class DvDirectionalLightParamController : public DvParamController{
    public:
        char unk0;
        int unk1;
        short unk2;
        int unk3;
        int unk4;
        float unk5;
        float unk6;
        float unk7;
        float unk8;
        float unk9;
        float unk10;
        int64_t unk11;
        int64_t unk12;
        int64_t unk13;

        virtual bool Load();
        virtual hh::gfx::RenderingComponent* GetRenderingComponent();
        virtual void* UnkFunc(int curFrame);
    };
}
