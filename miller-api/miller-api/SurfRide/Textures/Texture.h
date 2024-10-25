#pragma once

namespace SurfRide {
    struct SRS_TEXTURE {
        const char* name{};
        const char* filename{};
        unsigned int id{};
        unsigned short width{};
        unsigned short height{};
        unsigned int flags{};
        unsigned int cropCount{};
        SRS_CROP* crops{};
        SRS_USERDATA* userData{};
    };

	struct TextureIterator {
		SRS_TEXTURE* texture;

		void Next();
        const char* GetFilename() const;
        unsigned int GetFlags() const;
	};
}
