#pragma once

namespace SurfRide {
    struct SRS_SLICE {
        uint32_t flags;
        Vector2 fixedSize;
        Color materialColor;
        Color illuminationColor;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        short cropIndex0;
        short cropIndex1;
    };

    struct SRS_SLICECAST {
        uint32_t flags;
        Vector2 size;
        Vector2 pivot;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        Vector2 fixedSize;
        short sliceHorizontalCount;
        short sliceVerticalCount;
        short horizontalFixedCount;
        short verticalFixedCount;
        short cropRef0Count;
        short cropRef1Count;
        SRS_CROPREF* cropRefs0;
        uint32_t effectType;
        void* effectData;
        SRS_SLICE slices[1];

        inline SRE_EFFECT_TYPE GetEffectType() const {
            return static_cast<SRE_EFFECT_TYPE>(effectType & 0xF);
        }

        inline void SetEffectType(SRE_EFFECT_TYPE type) {
            effectType = (effectType & ~0xF) | static_cast<unsigned int>(type & 0xF);
        }

        inline EPivotType GetPivotType() const {
            return static_cast<EPivotType>((flags >> 19) & 0xF);
        }

        inline void SetPivotType(EPivotType pivotType) {
            flags = (flags & ~(0xF << 19)) | ((static_cast<unsigned int>(pivotType) & 0xF) << 19);
        }

        inline EOrientation GetOrientation() const {
            return static_cast<EOrientation>((flags >> 6) & 0x3);
        }

        inline void SetOrientation(EOrientation orientation) {
            flags = (flags & ~(0x3 << 6)) | ((static_cast<unsigned int>(orientation) & 0x3) << 6);
        }

        inline bool GetMaterialColorFlag() const {
            return flags & 0x10;
        }

        inline void SetMaterialColorFlag(bool enabled) {
            if (enabled)
                flags |= 0x10;
            else
                flags &= ~0x10;
        }

        inline bool GetIlluminationColorFlag() const {
            return flags & 0x20;
        }

        inline void SetIlluminationColorFlag(bool enabled) {
            if (enabled)
                flags |= 0x20;
            else
                flags &= ~0x20;
        }
    };

    class Slice {
    public:
        SRS_SLICE* sliceData;
        uint64_t unk1;
        Vector2 fixedSize;
        uint32_t flags;
        short cropIndex0;

        Slice(SRS_SLICE* sliceData);
    };

    class SliceCast : public Cast {
    public:
        SRS_SLICECAST* sliceCastData;
        uint32_t type; // (data.flags >> 19) & 0xF
        uint64_t qwordE0;
        Vector2 size;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        bool bool100;
        csl::ut::MoveArray<Slice> slices;

        SliceCast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);

        static Vector2 CalcPivot(float width, float height, const SRS_SLICECAST& sliceCastData);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual void* GetCellProbably() const override;
        virtual void SetCellProbably(void* cell) override;
        virtual unsigned int GetCellCount() const override;
        virtual uint64_t UnkFunc12() override;
    };
}
