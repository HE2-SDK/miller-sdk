#pragma once

namespace hh::needle {
    class ParameterValueObject : public NeedleRefcountObject, public ParameterValueObjectContainer {
    public:
        static ParameterValueObject* Create(const InstanceParameterContainerData* ipcd, unsigned int unk1);
    };
}
