#pragma once

namespace hh::anim {
    class Calc {
    public:
        static float CalcDuration(const AsmResourceManager& asmResourceManager, const BlendNodeBase* blendTree);
    };
}
