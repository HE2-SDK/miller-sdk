#pragma once

namespace SurfRide {
    class ImageCast;
    class Text {
    public:
        ImageCast* imageCast;
        SRS_IMAGECAST* imageCastData;
        SRS_TEXTDATA* textData;
        uint32_t lineCount;
        uint32_t glyphCount;
        Vector2 startPosition;
        bool counted;
        const char* buffer; // UTF-8 encoded
        uint32_t bufferSize;
        Vector2 calculatedTextSize;
        Vector2 textAreaSize;
        csl::ut::MoveArray<SRS_CELL3D> cells;

        Text(ImageCast* imageCast);

        void SetText(const char* str);
        void Count();
        void AllocateTextCells();
    };
}
