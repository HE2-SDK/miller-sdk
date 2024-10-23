#pragma once

namespace hh::needle::ImplDX11 {
    struct SMeshBuildCommonInfo {

        template<typename T>
        void MeasureEachShaderStage_One(unsigned int index, unsigned int unkParam, const ShaderMeshMaterialBuilder::SLayoutMaterial& layoutMaterial);
        template<> void MeasureEachShaderStage_One<SVSTypeDX11>(unsigned int index, unsigned int unkParam, const ShaderMeshMaterialBuilder::SLayoutMaterial& layoutMaterial);
        template<> void MeasureEachShaderStage_One<SPSTypeDX11>(unsigned int index, unsigned int unkParam, const ShaderMeshMaterialBuilder::SLayoutMaterial& layoutMaterial);
        template<> void MeasureEachShaderStage_One<SCSTypeDX11>(unsigned int index, unsigned int unkParam, const ShaderMeshMaterialBuilder::SLayoutMaterial& layoutMaterial);
    };
}
