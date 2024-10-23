#pragma once

namespace hh::gfx {
    template<typename T>
    class ResModelParameterInterface {
    public:
        virtual void* GetParameterInterface() = 0;
    };
}
