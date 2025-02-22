#pragma once

namespace hh::dv{
    class DvElementMaterialParam : public DvElementBase {
    public:
        struct Data {
        public:
            enum class Flags : unsigned int {
                PARAM_X,
                PARAM_Y,
                PARAM_Z,
                PARAM_W
            };

            char materialName[64];
            char paramName[64];
            csl::ut::Bitset<Flags> flags;
            float params[4];
            float finishParams[4];
            float curveData[32];
        };

        Data binaryData;
        csl::ut::VariableString materialName;
        csl::ut::VariableString paramName;
        csl::ut::Bitset<Data::Flags> flags;
        int64_t unk1;

        virtual void Setup(void* unk) override;
        virtual void* UnkFunc2() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementMaterialParam)
    };
}