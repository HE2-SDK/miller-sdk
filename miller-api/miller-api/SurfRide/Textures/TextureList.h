#pragma once

namespace SurfRide {
    class BinaryData;
    class TextureList {
    public:
        SRS_TEXTURELIST* textureListData;
        RefPtr<TextureData> textureData;

        TextureList(SRS_TEXTURELIST* textureListData);
        void SetTextureData(TextureData* textureData);
    };

	struct TextureListCollection {
		SRS_TEXTURELIST* current;
		SRS_TEXTURELIST* end;
	};

	struct TextureListIterator {
		SRS_TEXTURELIST* textureList;

		void Next();
		unsigned int GetTextureCount() const;
		TextureIterator GetTexture(unsigned int i) const;
	};
}
