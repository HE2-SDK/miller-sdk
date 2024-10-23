#pragma once

#define NEEDLE_RESOURCE_MODEL_DATA 0x5441444C45444F4Dui64 // 'TADLEDOM'

namespace hh::needle {
    class ModelCreationInfoCreator : public NeedleObject {
    //     PODArray<InstanceParameterContainerData> instanceParameterContainerDatas;
    //     PODArray<InstanceParameterContainer> instanceParameterContainers;
    //     PODArray<unsigned short> unk1;
    //     uint64_t unk2;
        

    // public:
    //     void Setup(MeshResource* meshResource, const ShaderMaterialParameterSetting& shaderParamSetting);
    };

    class LocalModelCreationInfoCreator : public ModelCreationInfoCreator {

    };

    class Model : TNeedleRefcountUniqueObjectBase<TNeedleRefcountResource<NEEDLE_RESOURCE_MODEL_DATA, NeedleRefcountResource>> {
    public:
        MeshResource* GetMeshResource(unsigned int idx) const;
    };
}
