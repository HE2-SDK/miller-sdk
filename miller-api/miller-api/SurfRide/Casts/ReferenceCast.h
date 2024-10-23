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

	class ReferenceCast : public Cast3D {
	public:
		SRS_REFERENCECAST* referenceCastData;
		Layer* layer;
		uint32_t animationId;
		float animationFrame;
		bool isFlag2Set;

		ReferenceCast(SRS_CASTNODE* castData, SRS_TRS3D* transform, Cast* parentCast, Layer* layer);

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateThis(float time, const Transform* transform, const Cast* parent, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void Draw(DrawInterface* drawInterface, Transform* transformLayerBuffer, void* cellLayerBuffer) override {}
        virtual void InitializeTransformFromLayerBuffer(Transform* layerBuffer) override;
	};
}
