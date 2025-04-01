#pragma once

namespace app::dv{
    class DvElementFootIk : public AppDvElementBase{
    public:
        struct Data { };

        void* unk0;

        virtual bool AddCallback(int currentFrame, csl::math::Transform* transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFootIk)
    };
}
