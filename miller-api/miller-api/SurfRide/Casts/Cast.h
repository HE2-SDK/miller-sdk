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
		short childIndex{ -1 };
		short siblingIndex{ -1 };
		SRS_USERDATA* userData{};

        inline Type GetType() const {
            return static_cast<Type>(flags & 0xF);
        }

        inline void SetType(Type type) {
            flags = (flags & ~0xF) | (static_cast<unsigned int>(type) & 0xF);
        }
	};

    class Scene;
    class Cast : public ReferencedObject {
    public:
		struct Unk1 {
			// This is actually an unknown structure containing this movearray, it's used in multiple resources.
			csl::ut::MoveArray<void*> unk1;
			Cast* cast;
			Unk1(csl::fnd::IAllocator* allocator);
		};

        Transform* transform;
        RefPtr<Blur> blurEffect;
        RefPtr<Reflect> reflectEffect;
        uint32_t unk4;
        uint64_t unk5;
        SRS_CASTNODE* castData;
        Layer* layer;
        Cast* parentCast;
        csl::ut::MoveArray<SurfRide::Cast*> children;
        SRS_MOTION* motion;
        uint32_t flags;
        bool unk8;
        bool is3D;
        uint16_t unk9;
        uint16_t unk9a;
        uint64_t unk10;
        Vector3 position;
        Unk1 unk12;
        bool unk14;

        Cast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);
        UserData GetUserData();
        void SetFlag1000(bool enabled);
        void InitializeTransform2D(Transform* transform, SRS_TRS2D* cell);
        void InitializeTransform3D(Transform* transform, SRS_TRS3D* cell);
        Scene* GetScene();
        void CreateEffectCast(void* effectData);
        SRS_TEXTURELIST* GetTextureListData(int index) const;

        static Vector2 CalcPivot(float width, float height, EPivotType pivotType, const Vector2& customPivot);

        virtual void* GetRuntimeTypeInfo() const;
        virtual bool UnkFunc2();
        virtual void UnkFunc3() {}
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) {}
        virtual void* GetCellProbably() const;
        virtual void SetCellProbably(void* cell) {}
        virtual unsigned int GetCellCount() const;
        virtual void UpdateThis(float time, const Cast* parentCast);
        virtual uint64_t UnkFunc12();

        inline void SetPosition(const Vector3& pos) {
			transform->position = pos;
			transform->dirtyFlag.flags.m_dummy |= transform->dirtyFlag.transformAny.m_dummy;
        }

        inline csl::ut::MoveArray<SurfRide::Cast*> GetChildren() const {
            return children;
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
