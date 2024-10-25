#pragma once

namespace SurfRide {
    struct SRS_IMAGECAST {
        unsigned int flags{};
        csl::math::Vector2 size{};
        csl::math::Vector2 pivot{};
        Color vertexColorTopLeft{};
        Color vertexColorBottomLeft{};
        Color vertexColorTopRight{};
        Color vertexColorBottomRight{};
        short cropIndex0{};
        short cropIndex1{};
        short cropRef0Count{};
        short cropRef1Count{};
        SRS_CROPREF* cropRefs0{};
        SRS_CROPREF* cropRefs1{};
        SRS_TEXTDATA* textData{};
        uint32_t effectType{};
        void* effectData{};

        inline SRE_EFFECT_TYPE GetEffectType() const {
            return static_cast<SRE_EFFECT_TYPE>(effectType & 0xF);
        }

        inline void SetEffectType(SRE_EFFECT_TYPE type) {
            effectType = (effectType & ~0xF) | static_cast<unsigned int>(type & 0xF);
        }

        // Apparently shifting 4 is some mirror flag

        inline EPivotType GetPivotType() const {
            return static_cast<EPivotType>((flags >> 19) & 0xF);
        }

        inline void SetPivotType(EPivotType pivotType) {
            flags = (flags & ~(0xF << 19)) | ((static_cast<unsigned int>(pivotType) & 0xF) << 19);
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

        inline EOrientation GetOrientation() const {
            return static_cast<EOrientation>((flags >> 6) & 0x3);
        }

        inline void SetOrientation(EOrientation orientation) {
            flags = (flags & ~(0x3 << 6)) | ((static_cast<unsigned int>(orientation) & 0x3) << 6);
        }

        inline bool GetDisableTextureFlag() const {
            return flags & 0x100;
        }

        inline void SetDisableTextureFlag(bool enabled) {
            if (enabled)
                flags |= 0x100;
            else
                flags &= ~0x100;
        }

        inline bool GetUseCropSurface0Flag() const {
            return flags & 0x20000;
        }

        inline void SetUseCropSurface0Flag(bool enabled) {
            if (enabled)
                flags |= 0x20000;
            else
                flags &= ~0x20000;
        }
    };

    class Text;
    class ImageCast : public Cast {
    public:

        SRS_IMAGECAST* imageCastData;
        uint32_t imageCastFlags;
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

        ImageCast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);
        
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
