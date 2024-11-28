#pragma once

namespace SurfRide {
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
        EBlendMode blendMode;
        uint32_t dword8C; // flags & 0x1000
        bool byte90; // flags & 0x10
        bool byte91;

        Reflect(SRS_REFLECT* binaryData, Cast* cast);
        bool Hides() const;
        bool IsIntervalZero() const;
        float GetGainFrame(float deltaTime) const;

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
