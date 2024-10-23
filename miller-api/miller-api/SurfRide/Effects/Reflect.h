#pragma once

namespace SurfRide {
    struct SRS_REFLECT : public SRS_EFFECT {
        uint32_t unk1;
        uint32_t unk2;
        uint32_t unk3;
        float unk4;
        float unk5;
        float unk6;
        float unk7;
        uint32_t flags;
        Color color;
    };

    struct SRS_REFLECT3D : public SRS_REFLECT {

    };

    class Reflect : public ReferencedObject {
    public:
        SRS_REFLECT* binaryData;
        Cast* cast;
        uint64_t qword20;
        uint64_t qword28;
        SurfRide::SrTexCoord texCoords[4];
        Vector2 qword50;
        Vector2 qword58;
        Vector2 qword60;
        Vector2 qword68;
        float qword70;
        Colorf color;
        uint32_t cellCount;
        SRE_BLEND_MODE blendMode;
        uint32_t dword8C; // flags & 0x1000
        bool byte90; // flags & 0x10
        bool byte91;

        Reflect(SRS_REFLECT* binaryData, Cast* cast);

        virtual int64_t UnkFunc1() = 0;
        virtual int64_t UnkFunc2() = 0;
    };

    class Reflect3D : public Reflect {
    public:
        SRS_CELL3D cells[9];

        Reflect3D(SRS_REFLECT3D* binaryData, Cast* cast);

        virtual int64_t UnkFunc1();
        virtual int64_t UnkFunc2();
    };
}
