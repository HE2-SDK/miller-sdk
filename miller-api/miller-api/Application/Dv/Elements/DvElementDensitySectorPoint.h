#pragma once

namespace app::dv{
    class DvElementDensitySectorPoint : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            int unk0;
            csl::math::Position unk1;
            float unk2[4];
        };

        char unk0[56];

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementDensitySectorPoint)
    };
}
