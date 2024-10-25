#pragma once

namespace SurfRide {
    struct SRS_BLUR : public SRS_EFFECT {
        uint32_t unk1{};
        uint32_t unk2{};
        uint32_t cropCount{};
        uint32_t steps{};
        int duration{};
        unsigned int flags{};
        Color color{};

        inline SRE_BLEND_MODE GetBlendMode() const {
            return static_cast<SRE_BLEND_MODE>(flags & 0xF);
        }

        inline void SetBlendMode(SRE_BLEND_MODE type) {
            flags = (flags & ~0xF) | (static_cast<unsigned int>(type) & 0xF);
        }

        inline bool Hides() const {
            return flags & 0x1000;
        }

        inline void SetHides(bool type) {
            if (type)
                flags |= 0x1000;
            else
                flags &= ~0x1000;
        }
    };

    struct SRS_BLUR3D : public SRS_BLUR {
    };

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
        SRE_BLEND_MODE blendMode;
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
