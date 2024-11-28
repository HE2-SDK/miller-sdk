#pragma once

namespace SurfRide {
    struct BLUR3D_DATA {
        SRS_CELL3D cells[9];
        uint8_t unk1;

        BLUR3D_DATA();
    };

    class Blur : public ReferencedObject {
    public:
        SRS_BLUR* binaryData;
        Cast* cast;
        float fps; // 1 / project->frameRate
        float frame;
        float stepSize; // 1 / steps
        uint32_t cellCount;
        uint32_t steps;
        uint32_t dword34;
        EBlendMode blendMode;
        int hides; // flags & 0x1000
        uint8_t byte40;

        Blur(SRS_BLUR* binaryData, Cast* cast);
        bool Hides() const;
        bool IsIntervalZero() const;
        float GetGainFrame(float deltaTime) const;

        virtual int64_t UnkFunc1() = 0;
        virtual int64_t UnkFunc2() = 0;
        virtual int64_t UnkFunc3() = 0;
    };

    class Blur3D : public Blur {
    public:
        BLUR3D_DATA* blurDataIn;
        BLUR3D_DATA* blurDataOut;

        Blur3D(SRS_BLUR3D* binaryData, Cast* cast);

        virtual int64_t UnkFunc1();
        virtual int64_t UnkFunc2();
        virtual int64_t UnkFunc3();
    };
}
