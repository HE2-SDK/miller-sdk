#pragma once

namespace app::dv{
    class DvElementOverrideAsm : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
            char asmName[64];
            char asmNameTarget[64];
        };

        void* unk0;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementOverrideAsm)
    };
}
