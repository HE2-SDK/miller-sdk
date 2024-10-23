#pragma once

#define NEEDLE_RESOURCE_MODEL_INSTANCE 0x3030534E494C444Dui64 // '00SNILDM'

namespace hh::needle {
    class ModelInstance : public TNeedleRefcountResource<NEEDLE_RESOURCE_MODEL_INSTANCE, NeedleRefcountResource> {
    public:
        // virtual void UnkFunc8();
        // virtual void UnkFunc9() {}
        // virtual void UnkFunc10() {}
        // virtual void UnkFunc11() {}
        // virtual void UnkFunc12();
        // virtual void UnkFunc13();
        // virtual void UnkFunc14();

        int GetParameterValueObjectContainerByName(CNameIDObject* name);
        ParameterValueObjectContainer* GetParameterValueObjectContainer(int index);
    };
}
