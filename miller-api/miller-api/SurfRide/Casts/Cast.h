#pragma once

namespace SurfRide {
    class CastListener {
    public:
        virtual ~CastListener();
        virtual void* GetRuntimeTypeInfo();
        virtual int64_t Unk1();
        virtual int64_t Unk2();
        virtual int64_t Unk3();
        virtual int64_t Unk4();
        virtual int64_t Unk5();
        virtual int64_t Unk6();
        virtual int64_t Unk7();
        virtual int64_t Unk8();
    };

	struct SRS_CASTNODE
	{
        enum class Type {
            NORMAL,
            IMAGE,
            SLICE,
            REFERENCE,
        };

		const char* name{};
		int id{};
		unsigned int flags{}; // 0xF mask -> Type
		void* data{};
		short childIndex{};
		short siblingIndex{};
		SRS_USERDATA* userData{};

        inline Type GetType() const {
            return static_cast<Type>(flags & 0xF);
        }

        inline void SetType(Type type) {
            flags = (flags & ~0xF) | (static_cast<unsigned int>(type) & 0xF);
        }
	};

    class DrawInterface;
    class Scene;
    class Cast : public ReferencedObject {
    public:
		struct Unk1 {
			// This is actually an unknown structure containing this movearray, it's used in multiple resources.
			csl::ut::MoveArray<void*> unk1;
			Cast* cast;
			Unk1(csl::fnd::IAllocator* allocator);
		};

        int index;
        Transform3D* transform;
        SRS_TRS_BASE* transformData;
        RefPtr<Blur> blurEffect;
        RefPtr<Reflect> reflectEffect;
        uint32_t unk4;
        void* unk3;
        SRS_CASTNODE* castData;
        uint32_t unk6;
        Layer* layer;
        Cast* parentCast;
        Cast* previousSiblingCast;
        Cast* nextSiblingCast;
        Cast* firstChild;
        Cast* lastChild;
        uint32_t flags; // 0x1000000 = no local material color, 0x4000000 = no local illumination color, & 0xF = effect type
        bool unk10;
        bool is3D;
        Cast* rootCast;
        Unk1 unk12;

        Cast(SRS_CASTNODE* castData, SRS_TRS_BASE* transform, Cast* parentCast, Layer* layer);
        UserData GetUserData();
        void SetFlag1000(bool enabled);
        void InitializeTransform2D(Transform* transform, SRS_TRS2D* cell);
        void InitializeTransform3D(Transform* transform, SRS_TRS3D* cell);
        Scene* GetScene();
        SRS_TEXTURELIST* GetTextureListData(int index) const;

        static Cast* NextCast(Cast* cast) { return cast->nextSiblingCast; }
#ifndef EXPORTING_TYPES
		inline NullTerminatedCollection<Cast, &NextCast> GetChildren() const {
			return { firstChild };
		}
#endif

        static Vector2 CalcPivot(float width, float height, EPivotType pivotType, const Vector2& customPivot);

        virtual void* GetRuntimeTypeInfo() const;
        virtual Color GetLocalMaterialColor() const;
        virtual Color GetGlobalMaterialColor() const;
        virtual void SetLocalMaterialColor(const Color& color);
        virtual Color GetLocalIlluminationColor() const;
        virtual Color GetGlobalIlluminationColor() const;
        virtual void SetLocalIlluminationColor(const Color& color);
        virtual bool GetLocalDisplayFlag() const;
        virtual bool GetGlobalDisplayFlag() const;
        virtual void SetLocalDisplayFlag(bool enabled);
        virtual void CreateEffectCast(void* effectData);
        virtual void CalcMotion(float, float, bool, bool, const SRS_MOTION* motion) = 0;
        virtual void MakeCellData(bool, Transform* transformLayerBuffer, void* cellLayerBuffer) = 0;
        virtual void Update(float time, const Transform* transform, const Cast* parent, Transform* transformLayerBuffer, void* cellLayerBuffer) = 0;
        virtual void UpdateParentsAndThisTransformRecursively() = 0;
        virtual void UpdateParentsTransformRecursively() = 0;
        virtual void UpdateThis(float time, const Transform* transform, const Cast* parent, Transform* transformLayerBuffer, void* cellLayerBuffer) = 0;
        virtual void Draw(DrawInterface* drawInterface, Transform* transformLayerBuffer, void* cellLayerBuffer) = 0;
        virtual Transform* GetTransform();
        virtual Transform* GetTransform2();
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) = 0;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) = 0;
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) = 0;
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) = 0;
        virtual unsigned int GetCellCount() const = 0;
        virtual void InitializeTransformFromLayerBuffer(Transform* layerBuffer) = 0;
        virtual void CopyTransformToLayerBuffer(Transform* transform, Transform* layerBuffer, bool unkParam) = 0;
        virtual void InitializeCellFromLayerBuffer(void* layerBuffer, unsigned int index) = 0;
        virtual void CopyCellToLayerBuffer(void* data, void* layerBuffer, unsigned int index) = 0;
        virtual SRS_CELL3D* GetCell() const = 0;
    };

    class Cast3D : public Cast {
    public:
        // from the 2D transforms;
        unsigned short unk1;
        unsigned short unk2;
        Vector3 position;

        Cast3D(SRS_CASTNODE* castData, SRS_TRS3D* transform, Cast* parentCast, Layer* layer);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void CreateEffectCast(void* effectData) override;
        virtual void CalcMotion(float, float, bool, bool, const SRS_MOTION* motion) override;
        virtual void MakeCellData(bool, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void Update(float time, const Transform* transform, const Cast* parent, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void UpdateParentsAndThisTransformRecursively() override;
        virtual void UpdateParentsTransformRecursively() override;
        virtual void UpdateThis(float time, const Transform* transform, const Cast* parent, Transform* transformLayerBuffer, void* cellLayerBuffer) override;
        virtual void Draw(DrawInterface* drawInterface, Transform* transformLayerBuffer, void* cellLayerBuffer) override {}
        virtual Transform* GetTransform() override;
        virtual Transform* GetTransform2() override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override {}
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override {}
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) override {}
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) override {}
        virtual unsigned int GetCellCount() const override { return 0; }
        virtual void InitializeTransformFromLayerBuffer(Transform* layerBuffer) override;
        virtual void CopyTransformToLayerBuffer(Transform* transform, Transform* layerBuffer, bool unkParam) override;
        virtual void InitializeCellFromLayerBuffer(void* layerBuffer, unsigned int index) override {}
        virtual void CopyCellToLayerBuffer(void* data, void* layerBuffer, unsigned int index) override {}
        virtual SRS_CELL3D* GetCell() const override { return nullptr; }

        inline void SetPosition(const Vector3& pos) {
            transform->transformData->position = pos;
			transform->dirtyFlag.SetAll();
        }
    };

    struct SRS_LAYER;
	struct CastCollection {
		SRS_LAYER* layer;
		SRS_CASTNODE* current;
		SRS_CASTNODE* end;
	};

	struct CastIterator {
		SRS_LAYER* layer;
		SRS_CASTNODE* cast;

		void Next();
		SRS_CASTNODE::Type GetType() const;
		const char* GetName() const;
		bool IsSysfCast() const;
        UserData GetUserData() const;
	};
}
