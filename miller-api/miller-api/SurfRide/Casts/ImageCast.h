#pragma once

namespace SurfRide {
    class Text;
    class ImageCast : public Cast {
    public:

        SRS_IMAGECAST* imageCastData;
        EPivotType pivotType;
        Text* text;
        Vector2 size;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        short cropIndex[2];
        SrTexCoord cropRectMin[2];
        SrTexCoord cropRectMax[2];
        bool cropRectDirty[2];
        SRS_CELL3D* cell;

        ImageCast(csl::fnd::IAllocator* allocator, SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);
        
        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) override;
        virtual void* GetCellProbably() const override;
        virtual void SetCellProbably(void* cell) override;
        virtual unsigned int GetCellCount() const override;
        virtual void UpdateThis(float time, const Cast* parentCast) override;
        virtual uint64_t UnkFunc12() override;

        void InitializeText();
        void SetText(const char* str);
        Vector2 GetSize() const;
        static Vector2 CalcPivot(float width, float height, const SRS_IMAGECAST& imageCastData);
    };
}
