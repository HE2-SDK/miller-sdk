#pragma once

namespace SurfRide {
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
        EPivotType pivotType;
        uint64_t qwordE0;
        Vector2 size;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        bool bool100;
        csl::ut::MoveArray<Slice> slices;

        SliceCast(csl::fnd::IAllocator* allocator, SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);

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
