#pragma once

namespace hh::physics {
    class PhysicsWorld;

    struct ColliShape {
        enum Type : uint8_t {
            SPHERE,
            BOX,
            CAPSULE,
            CYLINDER,
        };

        struct SphereParameters {
            float radius;
        };

        struct BoxParameters {
            csl::math::Vector3 dimensions;
        };

        struct CapsuleParameters {
            float radius;
            float halfHeight;
        };

        struct CylinderParameters {
            float radius;
            float halfHeight;
        };

        union ColliShapeParameters {
            SphereParameters sphere;
            BoxParameters box;
            CapsuleParameters capsule;
            CylinderParameters cylinder;

            inline ColliShapeParameters& operator=(const ColliShapeParameters& other) {
                box = other.box;
                return *this;
            }
        };

        Type type;
        ColliShapeParameters parameters;
    };

    class GOCCollider;
    class GOCColliderListener {
    public:
        virtual ~GOCColliderListener() = default;
        virtual void GOCCL_UnkFunc1(GOCCollider* collider) {}
        virtual void GOCCL_UnkFunc2(GOCCollider* collider) {}
        virtual void GOCCL_UnkFunc3(GOCCollider* collider) {}
    };

    class GOCCollider : public game::GOComponent, public fnd::HFrame::Listener {
    public:
        struct SetupInfo {
            enum class Flag : uint8_t {
                HAS_POSITION,
                HAS_ROTATION,
                HAS_SCALE,
            };

            ColliShape::Type shapeType;
            uint8_t unk2;
            csl::ut::Bitset<Flag> flags;
            uint16_t filterCategory;
            uint16_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint32_t unk6;
            uint32_t unk7;
            fnd::HFrame* frame2;
            csl::math::Transform transform;
            float unk9;
            float unk10;

            SetupInfo(ColliShape::Type shape);
            void SetPosition(csl::math::Vector3 position);
            void SetRotation(csl::math::Quaternion rotation);
            void SetScale(csl::math::Vector3 scale);
        };

        enum class Flag : uint8_t {
            ENABLED,
            FRAME_DIRTY,
        };

        uint64_t pad; // probably some of the next data is actually one big block that's 16 aligned
        uint64_t unk101;
        fnd::HFrame* frame;
        fnd::HFrame* frame2;
        fnd::WorldPosition transformedWorldPosition;
        fnd::WorldPosition localWorldPosition;
        csl::math::Vector3 scale;
        ColliShape::Type shapeType;
        uint8_t unk104b;
        uint8_t filterCategory;
        csl::ut::Bitset<Flag> flags;
        uint16_t unk105b;
        uint32_t unk106;
        uint32_t unk106b;
        uint32_t unk107;
        PhysicsWorld* physicsWorld;
        csl::ut::InplaceMoveArray<void*, 1> unk109; // incorrect, the inner obj here is actually 2 floats
        csl::ut::MoveArray<void*> unk110;
        uint64_t unk111;
        float unk112;
        float unk113;

        GOCCollider(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool fUnk5() override { return true; }
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
		virtual void SetScale(const csl::math::Vector3& scale);
        virtual void GetShape(ColliShape& shape) const = 0;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        void Setup(const SetupInfo& setupInfo);
        void AddListener(GOCColliderListener* listener);
        void RemoveListener(GOCColliderListener* listener);
        void SetEnabled(bool enabled);

        inline csl::math::Matrix34 GetWorldTransform() const {
           csl::math::Matrix34 matrix;
        //    matrix.fromPositionOrientationScale(transformedWorldPosition.m_Position, transformedWorldPosition.m_Rotation, scale);
           return matrix;
        };

        inline csl::math::Matrix34 GetLocalTransform() const {
           csl::math::Matrix34 matrix;
        //    matrix.fromPositionOrientationScale(localWorldPosition.m_Position, localWorldPosition.m_Rotation, scale);
           return matrix;
        };

        GOCOMPONENT_CLASS_DECLARATION(GOCCollider);
    };
}
