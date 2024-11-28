#pragma once

namespace SurfRide {
    struct TextureIterator {
		SRS_TEXTURE* texture;

		void Next();
        const char* GetFilename() const;
        unsigned int GetFlags() const;
	};
}
