#pragma once

namespace app::dv{
    class DvElementWeather : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class WeatherType : unsigned int {
                UNK0 = 1,
                UNK1,
                UNK2,
            };

            WeatherType weatherType;
            float curveData[32];
        };

        bool timeSet;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementWeather)
    };
}
