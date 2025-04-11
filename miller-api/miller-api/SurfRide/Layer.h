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

		CastInstanceBuffer(csl::fnd::IAllocator* allocator, size_t size);

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
		uint32_t repeatCount;
		csl::ut::Bitset<Flag> flags;
		bool atAnimationStart;
		bool pause;
		bool repeat;
		bool dontSetRepeating;
		bool atAnimationEnd;
		bool playInReverse;
		bool unk16;
		Transform rootTransform;
		CastInstanceBuffer castInstanceBuffer;

		Layer(csl::fnd::IAllocator* allocator, const SRS_LAYER& layerData, Scene* scene);

		//void SetHideFlag(bool in_hide)
		//{
		//	if (in_hide)
		//		flags |= 0x100;
		//	else
		//		flags &= ~0x100;
		//}

		const char* GetAnimationName() const;
		int GetAnimationIndex(const char* animationName) const;
		float GetAnimationLength(const char* animationName) const;
		bool ApplyAnimation(int animationId);
		bool ApplyAnimation(const char* animationName);
		bool ApplyAnimationByIndex(unsigned int animationIdx);
		void SetCurrentFrame(float frame);
		void SetHideFlag(bool enabled);
		void SetRepeatFlag(bool enabled);
		bool Is3D();
		Layer* Copy();

		inline Cast* GetCast(unsigned int id) {
			for (auto* cast : casts)
				if (cast->castData->id == id)
					return cast;
			
			return nullptr;
		}
		Cast* GetCast(const char* name);

        inline csl::ut::MoveArray<SurfRide::Cast*> GetCasts() const {
            return topLevelCasts;
        }

	private:
		void CreateCast(int index, Cast* parentCast);
		void InitializeAnimation();
		void SetUpAnimationLinks(SRS_ANIMATION* animation);
		void UpdateFrame(float timestep);

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