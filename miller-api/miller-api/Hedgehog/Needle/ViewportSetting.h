#pragma once

namespace hh::needle {
    struct ViewportSetting {
        int x;
        int y;
        int renderResX;
        int renderResY;
        int unk3;
        float unk4;
    
        ViewportSetting(int width, int height);
    };
}
