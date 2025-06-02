#pragma once

namespace hh::pba{
    class PbaManager : public hh::game::GameService, hh::game::GameManagerListener, hh::fnd::ReloaderListener{
    public:
        
    };

    class PbaManagerBullet : public PbaManager{
    public:
    };
}