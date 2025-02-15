#pragma once

namespace SurfRide
{
	class ReferenceCast : public Cast {
	public:
		SRS_REFERENCECAST* referenceCastData;
		Layer* refLayer;
		uint32_t animationId;
		bool isFlag2Set;
		EBlendMode blendMode;

		ReferenceCast(csl::fnd::IAllocator* allocator, SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void UnkFunc3() override;
        virtual void UpdateThis(float time, const Cast* parentCast) override;
	};
}
