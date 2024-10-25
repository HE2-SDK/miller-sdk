#pragma once

namespace SurfRide
{
	struct SRS_LAYER;
	struct SRS_REFERENCECAST
	{
		SRS_LAYER* layer{};
		int flags{};
		uint32_t animationId{};
		uint32_t animationFrame{};
		int unk2{};
	};

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
