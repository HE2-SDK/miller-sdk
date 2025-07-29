#pragma once

namespace app::dv{
    class DvElementAtmosphereHeightFogParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
          	struct Parameter{
				float heightScale;
				float distanceOffset;
				float distanceScale;
				csl::math::Position rayleighScale;
				csl::math::Position mieScale;
				float noiseBlend;
				float noiseScale;
				float noiseDistance;
				float animationSpeed;
				float animationAngle;
				float sunColor[3];
				float ambColor[3];
          	};

          	bool enabled;
		private:
			char padding[3];
		public:
          	bool isAtmospheric;
          	Parameter params;
          	bool curveEnabled;
          	Parameter paramsFinish;
			float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;
        virtual void AppUnkFunc4(void* unk) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAtmosphereHeightFogParam)
    };
}
