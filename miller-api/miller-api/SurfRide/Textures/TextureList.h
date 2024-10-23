#pragma once

namespace SurfRide {
    struct SRS_TEXTURELIST {
        const char* name;
        unsigned int unk1;
        unsigned int textureCount;
        SRS_TEXTURE* textures;
        SRS_USERDATA* userData;
    };

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
