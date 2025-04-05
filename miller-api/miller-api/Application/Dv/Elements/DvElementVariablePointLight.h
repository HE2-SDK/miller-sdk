#pragma once

namespace app::dv{
    class DvElementVariablePointLight : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
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

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void UnkFunc6(int currentFrame, csl::math::Transform transform) override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementVariablePointLight)
    };
}
