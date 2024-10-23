#pragma once

namespace SurfRide
{
	struct SRS_CASTNODE;
	struct SRS_LAYER
	{
		union SRS_TRS_PTR {
			SRS_TRS2D* transforms2d;
			SRS_TRS3D* transforms3d;
		};

		const char* name{};
		int id{};
		int flags{};
		int castCount{};
		SRS_CASTNODE* casts{};
		SRS_TRS_PTR transforms{};
		int animationCount{};
		SRS_ANIMATION* animations{};
		int currentAnimationIndex{};
		SRS_USERDATA* userData{};
	};

	class Cast;
	class ReferenceCast;
	class ImageCastCast;
	class SliceCast;
	class Scene;

	// class CastInstanceBuffer : public Base {
	// public:
	// 	union CastInstance {
	// 		Cast cast;
	// 		ImageCast imageCast;
	// 		ReferenceCast referenceCast;
	// 		SliceCast sliceCast;
	// 	};

	// 	csl::fnd::IAllocator* allocator;
	// 	CastInstance* buffer;

	// 	CastInstanceBuffer(csl::fnd::IAllocator* allocator);

	// 	CastInstance* GetCastInstance(unsigned int idx);
	// };

	class Project;
	class Layer : public ReferencedObject
	{
	public:
		enum class Flag : uint32_t {
			IS_3D,
		};

		SRS_LAYER* layerData;
		uint32_t unk1;
		const char* name;
		Scene* scene;
		ReferenceCast* referenceCast;
		Cast** casts;
		uint32_t castCount;
		Transform* transforms;
		uint32_t transformCount;
		CellList* cells;
		Cast* firstCast;
		Cast* lastCast;
		uint32_t currentAnimationIndex;
		float currentFrame;
		float currentFrame2;
		float startFrame;
		float endFrame;
		float unk11a;
		float currentFrame3;
		uint32_t unk13;
		csl::ut::Bitset<Flag> flags;
		uint16_t unk14;
		bool atAnimationStart;
		bool unk14b;
		bool isLooping;
		bool dontLoop;
		bool atAnimationEnd;
		bool playInReverse;
		bool unk16;
		Project* project;

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

#ifndef EXPORTING_TYPES
		inline NullTerminatedCollection<Cast, &Cast::NextCast> GetCasts() const {
			return { firstCast };
		}
#endif

	private:
		Cast* CopyCastsRecursively(SRS_CASTNODE* casts, SRS_TRS3D* transforms, int idx, Cast* parentCast, unsigned int* totalTransforms);
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