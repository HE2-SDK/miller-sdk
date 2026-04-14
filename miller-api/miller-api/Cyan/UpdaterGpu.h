#pragma once

namespace Cyan {
    class UpdaterGpuBase {
    public:
#ifdef EXPORTING_TYPES
        uint64_t pad0;
#endif
        EmitterGpu* emitter;
        uint64_t qword18;
        uint64_t qword20;
        uint64_t qword28;
        uint64_t qword30;
        uint32_t dword38;
        csl::math::Matrix44 csl__math__matrix4440;
        csl::math::Matrix44 csl__math__matrix4480;

        UpdaterGpuBase();
        virtual ~UpdaterGpuBase();
        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
    };

    class UpdaterGpuPrimitive : public UpdaterGpuBase {
    public:
        struct GParam {
            uint32_t dword0;
            uint32_t dword4;
            uint32_t dword8;
            uint32_t dwordC;
            float float10;
            float float14;
            uint32_t dword18;
            float float1C;
            float float20;
            float float24;
            float float28;
            uint32_t dword2C;
            float float30;
            float float34;
            float float38;
            float float3C;
            uint32_t dword40;
            uint32_t dword44;
            uint32_t dword48;
            uint32_t dword4C;
            uint32_t dword50;
            uint32_t dword54;
            uint32_t dword58;
            uint32_t dword5C;
            uint32_t dword60;
            uint32_t dword64;
            uint32_t dword68;
            uint32_t dword6C;
            uint32_t dword70;
            uint32_t dword74;
            uint32_t dword78;
            uint32_t dword7C;
            uint32_t dword80;
            uint32_t dword84;
            uint32_t dword88;
            uint32_t dword8C;
            uint32_t dword90;
            uint32_t dword94;
            uint32_t dword98;
            uint32_t dword9C;
            uint32_t dwordA0;
            uint32_t dwordA4;
            uint32_t dwordA8;
            uint32_t dwordAC;
            uint32_t dwordB0;
            uint32_t dwordB4;
            uint32_t dwordB8;
            uint32_t dwordBC;
            csl::math::Vector4 m128C0;
            csl::math::Vector4 m128D0;
            csl::math::Vector4 m128E0;
            uint32_t dwordF0;
            uint32_t dwordF4;
            uint32_t dwordF8;
            uint32_t dwordFC;
            uint32_t dword100;
            uint32_t dword104;
            uint32_t dword108;
            uint32_t dword10C;
            uint32_t dword110;
            uint32_t dword114;
            uint32_t dword118;
            uint32_t dword11C;
            uint32_t dword120;
            uint32_t dword124;
            uint32_t dword128;
            uint32_t dword12C;
            uint32_t dword130;
            uint32_t dword134;
            uint32_t dword138;
            uint32_t dword13C;
            uint32_t dword140;
            uint32_t dword144;
            uint32_t dword148;
            uint32_t dword14C;
            uint32_t dword150;
            uint32_t dword154;
            uint32_t dword158;
            uint32_t dword15C;
            uint32_t dword160;
            uint32_t dword164;
            uint32_t dword168;
            uint32_t dword16C;
            csl::math::Vector4 oword170;
            csl::math::Vector4 oword180;
            csl::math::Vector4 oword190;
            csl::math::Vector4 oword1A0;
            csl::math::Vector4 oword1B0;
            float float1C0;
            float float1C4;
            uint64_t qword1C8;
            csl::math::Vector4 oword1D0;
            csl::math::Vector4 oword1E0;
            csl::math::Vector4 oword1F0;
            uint64_t qword200;
            uint64_t qword208;
            uint64_t qword210;
        };

        uint64_t unk101;
        hh::needle::ShaderObject* unk102;

        UpdaterGpuPrimitive();
        virtual ~UpdaterGpuPrimitive();
        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
    };

    class UpdaterGpuMesh : public UpdaterGpuBase {
    public:
        uint64_t unk101;
        uint64_t unk102;
        uint64_t unk103;
        uint32_t unk104;

        UpdaterGpuMesh();
        virtual ~UpdaterGpuMesh();
        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
    };
}
