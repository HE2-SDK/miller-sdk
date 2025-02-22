#pragma once

namespace app::dv{
    class DvElementVariablePointLight : public AppDvElementBase{
    public:
        struct Data {
        public:
            struct Parameters {
            public:
                float range;
                float intensity;
                float falloff;
                float angle;
            };

            int unk0;
            csl::math::Position position;
            csl::math::Position finishPosition;
            unsigned int color[3];
            unsigned int finishColor[3];
            Parameters params;
            Parameters finishParams;
            int unk4;
            int unk5[10];
            float curveData[128];
        };

        hh::fnd::Reference<hh::game::GameObject> lightHandle;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void UnkFunc6() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementVariablePointLight)
    };
}
