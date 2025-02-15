#pragma once

namespace hh::dv{
    class DvParamUpdater : public hh::fnd::ReferencedObject{
    public:
        csl::ut::MoveArray<DvDirectionalLightParamController*> lightParamControllers;

        DvParamUpdater(csl::fnd::IAllocator* allocator);
    };
}
