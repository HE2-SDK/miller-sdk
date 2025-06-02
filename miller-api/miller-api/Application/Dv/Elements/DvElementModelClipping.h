#pragma once

namespace app::dv{
    class DvElementModelClipping : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            csl::math::Rotation unk0;
            float unk1;
        };

        int unk0;
        int unk1;
        csl::math::Vector4 unk2;
        csl::math::Vector4 unk3;
        csl::ut::MoveArray<void*> unk4;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementModelClipping)
    };
}
