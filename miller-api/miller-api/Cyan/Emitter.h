#pragma once

namespace hh::needle{
    class Texture;
}

namespace Cyan {
    class Element;

    class Emitter : public System::Job {
    public:
        class FSMEmitter : public System::FSM {
        public:
            FSMEmitter();
        };

        class StateBase : public System::FSMState {
        public:
            inline Emitter* GetEmitter(System::FSMContext* ctx) { return reinterpret_cast<Emitter*>(ctx->owner); }

            virtual ~StateBase();
            virtual void OnEnter(System::FSMContext* ctx) override {}
            virtual void OnUpdate(System::FSMContext* ctx) override {}
            virtual void OnExit(System::FSMContext* ctx) override {}
        };

        class WaitingState : public StateBase {
        public:
            WaitingState();

            virtual void OnUpdate(System::FSMContext* ctx) override;
        };

        class AliveState : public StateBase {
        public:
            bool alive;
            bool dead;

            AliveState();

            virtual void OnEnter(System::FSMContext* ctx) override;
            virtual void OnUpdate(System::FSMContext* ctx) override;
            virtual void OnExit(System::FSMContext* ctx) override;
            virtual void UnkFunc1(System::FSMContext* ctx);
        };

        class DeadState : public StateBase {
        public:
            DeadState();

            virtual void OnEnter(System::FSMContext* ctx) override;
        };

        struct Unk1Resource {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
        };

        enum class Flag : unsigned int {
            UNK0,
            UNK1,
            HAS_CHILD_EFFECTS,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            USE_DISTANCE_ATTENUATION,
            UNK8,
            UNK9,
            UNK10,
            UNK11,
            UNK12,
            UNK13,
        };

        csl::ut::Bitset<Flag> flags;
        const Resource::EmitterParam* param;
        EffectImpl* effect;
        Cyan::System::LinkList<Element> elements;
        csl::math::Matrix34 emitterMatrix;
        csl::math::Matrix34 poseMatrix;
        csl::math::Matrix34 localMatrix;
        csl::math::Matrix34 inheritMatrix;
        csl::math::Matrix34 invInheritMatrix;
        csl::math::Matrix34 emissionMatrix;
        csl::math::Matrix34 invEmissionMatrix;
        csl::math::Matrix34 emissionMatrix2;
        csl::math::Matrix34 poseMatrix2;
        csl::math::Matrix34 whoKnowsMatrix;
        csl::math::Matrix34 worldMatrix;
        csl::math::Vector3 position;
        csl::math::Vector3 scale;
        csl::math::Vector3 elementScale;
        System::Random random;
        uint64_t pad0;
        Graphics::EmitterDecl declaration;
        csl::ut::Color8 color;
        float emitRatio;
        float playbackSpeed;
        float elementLifetimeScale;
        float distanceAttenuation;
        float unk5AC;
        float unk5B0;
        uint8_t gap5BC[20];
        csl::math::Vector3 unk5BC2;
        csl::math::Vector3 maxEmitterSize;
        csl::math::Vector3 unkVec2Offset;
        uint8_t gap5EC[40];
        uint8_t gap6C8bbc[0x40];
        uint8_t defaultRenderLayer;
        uint8_t gap5A0b[15];
        void* unk5A0c;
        //Particle* particle630;
        Emitter* parentEmitter;
        uint64_t qword648;
        uint64_t qword650;
        float renderPriority;
        int dword65C;
        uint32_t billboardViewportId;
        uint8_t gap65Cb[4];
        FSMEmitter fsm;
        System::FreeListAllocator* renderAllocator;
        WaitingState waitingState;
        AliveState aliveState;
        DeadState deadState;
        uint64_t gap6C8;
        csl::math::Vector3 position1;
        csl::math::Vector3 rotation1;
        csl::math::Vector3 scale1;
        csl::math::Vector3 unkPosition;
        uint8_t gap6C8a[16];
        csl::math::Vector3 inheritPosition;
        float lifetime;
        float time;
        float unkTime2;
        float emitInterval;
        float subDivisionCount;
        float unkTime3;
        uint8_t gap6C8bbb[8];
        float emitCount;
        Resource::EmitterParam::EmissionDynamicsParam::Settings emissionDynamicsSettings;
        csl::math::Position randomPosition;
        float spread;
        float startAngle; //randomized, multiplied by Random::GetFloat
        float endAngle; //randomized, multiplied by Random::GetFloat
        Resource::JitteredValue sizeX;
		Resource::JitteredValue sizeY;
		Resource::JitteredValue sizeZ;
        System::AnimCtrl* positionAnimation;
        System::AnimCtrl* rotationAnimation;
        System::AnimCtrl* scaleAnimation;
        System::AnimCtrl* emissionCountAnimation;
        System::AnimCtrl* direction1VelocityAnimation;
        System::AnimCtrl* direction2VelocityAnimation;
        System::AnimCtrl* localSpreadVelocityAnimation;
        System::AnimCtrl* localSpreadAnimation;
        System::AnimCtrl* worldSpreadVelocityAnimation;
        System::AnimCtrl* worldSpreadAnimation;
        System::AnimCtrl* worldSpreadAnglesOrDirectionAnimation;
        System::AnimCtrl* emitPositionJitterAnimation;
        System::AnimCtrl* emissionSpreadAnimation;
        System::AnimCtrl* startAngleAnimation;
        System::AnimCtrl* endAngleAnimation;
        System::AnimCtrl* sizeAnimation;
        System::AnimCtrl* unk1;
        System::AnimCtrl* unk2;
        System::AnimCtrl* unk3;
        System::AnimCtrl* unk4;
        System::AnimCtrl* animationBuffer;
        System::AnimCtrl* nextFreeAnimCtrl;
        Resource::ResObject<Resource::Texture> textures[4];
        Resource::ResObject<Unk1Resource> unk1Resource;
        Resource::ResObject<Resource::Effect> childEffects[16];
        Resource::ResObject<Resource::Model> model;
        Resource::ResObject<Resource::Skeleton> skeleton;
        Resource::ResObject<Resource::NodeAnim> nodeAnim;
        System::LinkPool<EffectHandle, 32> childEffectHandlePool;
        Graphics::EffectObject* effectObject;
        Graphics::Renderer* renderer;
        Graphics::EmitterDecl* emitterDecl;
        int unk1860;
        float unk1864;
        uint64_t gap1868;
        csl::math::Vector3 unkVec1;
        csl::math::Vector3 unkVec2;
        csl::math::Vector3 unkVec3;
        csl::math::Vector3 unkVec4;
        System::AnimCtrl* unkVec1Animation;
        System::AnimCtrl* unkVec2Animation;
        System::AnimCtrl* unkVec3Animation;
        System::AnimCtrl* unkVec4Animation;

        Emitter(EffectImpl* effect, const Resource::EmitterParam* param);

        void Start();
        void Stop(bool unk);
        void Pause();
        void Resume();
        void Step();
        void SetMatrix(const csl::math::Matrix34& matrix);
        csl::math::Matrix34 GetMatrix() const;
        void SetColor(csl::ut::Color8 color);
        inline csl::ut::Color8 GetColor() const { return color; }
        void SetAlpha(char alpha);
        inline char GetAlpha() const { return color.a; }
        void SetScale(const csl::math::Vector3& scale);
        inline csl::math::Vector3 GetScale() const { return scale; }
        void SetElementScale(const csl::math::Vector3& scale);
        inline csl::math::Vector3 GetElementScale() const { return elementScale; }
        void SetElementLifetimeScale(float lifetime);
        void SetPlaybackSpeed(float playbackSpeed);
        void SetEmitRatio(float emitRatio);
        inline float GetEmitRatio() const { return emitRatio; }
        void SetViewMask(unsigned int viewMask);
        //inline unsigned int GetViewMask() const { return viewMask; }
        void SetVisibility(bool enabled);
        inline void SetBillboardViewportID(unsigned int viewportId) { billboardViewportId = viewportId; }
        inline unsigned int GetBillboardViewportID() const { return billboardViewportId; }
        void CalcLocalMatrix();
        void CalcPoseMatrix(csl::math::Matrix34* outMatrix) const;
        void CalcInheritMatrix(const csl::math::Matrix34& poseMatrix, unsigned int flags, float inheritRate, csl::math::Matrix34* outMatrix, csl::math::Vector3* outTranslation) const;
        void CalcDistanceAttenuation();
        void EntryElement(Element* element);
        csl::math::Matrix34& GetEmissionMatrix();
        bool IsEnableEmit() const;

        virtual void Process(float unk) override;
        virtual uint64_t UnkFunc2(float unkParam1) override;
        virtual uint64_t UnkFunc3(void* unkParam1) override;
        virtual void UnkFunc4(void* unkParam1);
        virtual void Reset(const Resource::EmitterParam* param);
        virtual void PrepareRender(Graphics::Renderer* renderer, const Graphics::DeviceContainer& deviceContainer);
        virtual System::FSMState* GetState(unsigned int stateId);
        virtual void UnkFunc8(float time);
        virtual void UnkFunc9(void* unkParam1);
        virtual void InitEmitter(bool useLocalMatrix);
        virtual void ProcessEmitter(float time);
        virtual void UpdateEmitter(float time);
        virtual void EmitElements(float time);
        virtual void EmitElements2(float time);

        void ProcessAnimations(float time);
        void RandomizeStartAndEndAngles();
        void DeleteAllElements();
        void DeleteAllChildren();
        void DeleteAllAnimation();
        void StopChildren();

        System::AnimCtrl* CreateAnimCtrl(const Resource::PtrData<Resource::AnimationParam>& param, unsigned int flags);
    };
}
