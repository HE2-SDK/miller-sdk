#pragma once

namespace SurfRide
{
	class ReferenceCast : public Cast {
	public:
		SRS_REFERENCECAST* referenceCastData;
		Layer* layer;
		uint32_t animationId;
		bool isFlag2Set;
		uint32_t referenceCastFlags;

		ReferenceCast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void UnkFunc3() override;
        virtual void UpdateThis(float time, const Cast* parentCast) override;
	};
}
