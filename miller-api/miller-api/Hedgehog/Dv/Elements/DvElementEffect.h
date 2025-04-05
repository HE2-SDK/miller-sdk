#pragma once

namespace hh::dv{
    class DvElementEffect : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            enum class EffectTransType : unsigned int {
                NODE,
                NODE_AND_FRAME,
                NODE_POSITION
            };

            enum class Flags : unsigned int {
                UNK0,
                QUATERNION,
                UNK1,
                MODEL_SPACE_NODE
            };

            enum class Flags2 : unsigned int {
                UNK0,
                PERSISTENT
            };

            csl::math::Matrix44 effectMatrix;
            csl::ut::Bitset<Flags> flags;
            char effectName[64];
            bool effCreateInfoUnk1A;
            csl::ut::Bitset<Flags2> flags2;
            unsigned char b;
            unsigned char g;
            unsigned char r;
            unsigned char a;
            int effCreateInfoUnk5A;
            float effCreateInfoUnk5;
            EffectTransType effTransType;
            int unk7;
            int unk8;
            float curveData[128];
        };
        
        enum class EffectHandleFlags : unsigned char {
            LOADED
        };

        Description binaryData;
        eff::EffectHandle effectHandle;
        csl::ut::Bitset<EffectHandleFlags> effectHandleFlags;
        DvNodeBase* parentNode;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void SetData(void* data) override;
        virtual void DeleteData() override;

        DV_ELEMENT_DECLARATION_BASE(DvElementEffect)
    };
}
