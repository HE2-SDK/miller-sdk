#pragma once

namespace SurfRide
{
	class Cast;
	class ReferenceCast;
	class ImageCastCast;
	class SliceCast;
	class Scene;

	class CastInstanceBuffer : public Base {
	public:
		union CastInstance {
			Cast cast;
			ImageCast imageCast;
			ReferenceCast referenceCast;
			SliceCast sliceCast;
		};

		size_t size;
		CastInstance* buffer;

		CastInstanceBuffer(size_t size);

		CastInstance* GetCastInstance(unsigned int idx);
	};

	class Layer : public ReferencedObject
	{
	public:
		enum class Flag : uint32_t {
			IS_3D,
		};

		csl::ut::MoveArray<void*> unk1;
		SRS_LAYER* layerData;
		csl::ut::VariableString name;
		Scene* scene;
		ReferenceCast* referenceCast;
		csl::ut::MoveArray<Cast*> casts;
		csl::ut::MoveArray<Cast*> topLevelCasts;
		csl::ut::MoveArray<Cast*> animatingCasts;
		csl::ut::MoveArray<Transform> transforms;
		csl::ut::MoveArray<void*> unk8;
		csl::ut::StringMap<Cast*> castsByName;
		uint32_t currentAnimationIndex;
		float currentFrame;
		float currentFrame2;
		float startFrame;
		float endFrame;
		float unk11a;
		float currentFrame3;
		uint32_t unk13;
		csl::ut::Bitset<Flag> flags;
		bool atAnimationStart;
		bool unk14b;
		bool isLooping;
		bool dontLoop;
		bool atAnimationEnd;
		bool playInReverse;
		bool unk16;
		uint32_t unk17;
		uint32_t unk18;
		uint32_t unk19;
		Transform rootTransform;
		CastInstanceBuffer castInstanceBuffer;

		Layer(const SRS_LAYER& layerData, Scene* scene);

		//void SetHideFlag(bool in_hide)
		//{
		//	if (in_hide)
		//		flags |= 0x100;
		//	else
		//		flags &= ~0x100;
		//}

		bool StartAnimation(int animationId, float initialFrame, bool playInReverse);
		bool StartAnimation(int animationId);
		void SetAnimationFrame(float frame);
		bool Is3D();

        inline csl::ut::MoveArray<SurfRide::Cast*> GetCasts() const {
            return topLevelCasts;
        }

	private:
		void CreateCast(int index, Cast* parentCast);
		void StartCurrentAnimation();
		void InitializeAnimation(SRS_ANIMATION* animation);
		void UpdateAnimation(float timestep);
	};

	struct LayerCollection {
		SRS_LAYER* current;
		SRS_LAYER* end;
	};

	struct LayerIterator {
		SRS_LAYER* layer;
		
		void Next();
		CastCollection GetCasts() const;
	};
}