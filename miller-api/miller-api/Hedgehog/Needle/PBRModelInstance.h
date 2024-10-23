#pragma once

namespace hh::needle {
    struct MaterialparamSetting {
        InstanceParameterContainerData** globalParameterSettings;
        void* unk1;
        size_t unk2;
        size_t unk3;
    };
    
    MaterialparamSetting* GetMaterialparamSetting(int index);

    class PBRModelInstance : public ModelInstance {
        void SetShadowReceiveFlag(bool enabled);
        void GetModelSpaceAabb(csl::geom::Aabb* aabb) const;
        static InstanceParameterContainerData* GetGlobalParameterSetting();
        static ParameterValueObject* CreateGlobalParamContainer();
    };
}
