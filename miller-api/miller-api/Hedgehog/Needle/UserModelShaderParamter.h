#pragma once

namespace hh::needle {
    class UserModelShaderParamter : NeedleRefcountObject {
    public:
        struct ParameterInfo {
            CNameIDObject** parameterNames;
            uint32_t parameterCount;
        };

        CNameIDObject* name;
        uint32_t unk2;
        uint64_t unk3;

        UserModelShaderParamter();
        void SetParameter(const ParameterInfo parameterInfo);
    };
}
