#pragma once

namespace app::dv{
    class DvElementWeather : public AppDvElementBase{
    public:
        struct Data {
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

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementWeather)
    };
}
