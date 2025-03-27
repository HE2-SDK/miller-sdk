#pragma once

namespace hh::dv{
    class DvElementPointLight : public DvElementBase {
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
            
            enum class Flags : unsigned int {
                UNK0,
                UNK1,
                UNK2,
                UNK3,
                UNK4,
                UNK5,
            };

            csl::ut::Bitset<Flags> flags;
            csl::math::Position position;
            csl::math::Position finishPosition;
            unsigned int color[3];
            unsigned int finishColor[3];
            Parameters params;
            Parameters finishParams;
            bool unkBool0;
            float unk14[10];
            float curveData[128];
        };

        Data binaryData;
        hh::fnd::Reference<hh::game::GameObject> light;
        
        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;
        virtual void* RemoveCallback() override;
        virtual void SetData(void* data) override;
        virtual void DeleteData() override;
        virtual void UnkFunc6(int currentFrame, csl::math::Transform transform) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementPointLight)
    };
}
