#pragma once

namespace hh::snd {
    class SoundCue {};
    class SoundCueCri : public SoundCue {
    public:
        struct PoolParam {

        };

        struct CdataTag {
            void* cueSheetResource;
            int cueId;
            void* cueSheet;
            float minDistance;
            float maxDistance;
            unsigned short numBlocks;
            bool isInfinite;
            bool isStreaming;
            bool is3DPosPanning;
        };
    };
}