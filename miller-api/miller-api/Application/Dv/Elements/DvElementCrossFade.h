#pragma once

namespace app::dv{
    class DvElementCrossFade : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            bool curveEnabled;
            int unk1;
            float curveData[32];
        };

        int unkHandle;
        int unk0;
        void* unk1;
        void* unk2;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCrossFade)
    };
}
