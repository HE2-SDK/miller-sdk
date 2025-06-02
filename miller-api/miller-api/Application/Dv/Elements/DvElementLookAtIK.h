#pragma once

namespace app::dv{
    class DvElementLookAtIK : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct Object {
            public:
                int unk1;
                char guid[16];
                csl::math::Position offset;
            };

            bool curveEnabled;
            Object obj;
            Object finishObj;
            float curveData[64];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementLookAtIK)
    };
}
