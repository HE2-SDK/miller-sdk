#pragma once

namespace Cyan{
    class HistoricalStripe;

    

    class Element {
    public:
        enum class AxisFlag : unsigned char {
            X,
            Y,
            Z,
        };

        struct _Texcoord {
            csl::math::Vector2 current;
            csl::math::Vector2 start;
            csl::math::Vector2 step;
            System::AnimCtrl* scaleAnimation;
            System::AnimCtrl* rotationAnimation;
            System::AnimCtrl* translationAnimation;
        };

        struct ColorParameters {
            csl::ut::Color8 colors[2][2];
            float unk7[2];
            float luminance[2][2];
        };

        struct ColorAnimations {
            System::AnimCtrl* colorAnimation[2][2];
            System::AnimCtrl* alphaAnimation[2][2];
            System::AnimCtrl* luminanceAnimation[2][2];
            System::AnimCtrl* unk7Animation[2];
        };

#ifdef EXPORTING_TYPES
        char pad[8]; // deal with https://randomascii.wordpress.com/2013/12/01/vc-2013-class-layout-change-and-wasted-space/, see 2013 section of https://learn.microsoft.com/en-us/cpp/porting/visual-cpp-change-history-2003-2015?view=msvc-170&redirectedfrom=MSDN#visual-studio-2013-conformance-changes
#endif
        System::LinkList<Element>::Entry elementListEntry;
        int32_t dword28;
        Emitter* emitter;
        const Resource::ElementParam* param;
        float lifetimeScale;
        float time;
        float patternAnimTime;
        int32_t dword4C;
        csl::math::Vector3 position;
        csl::math::Vector3 previousPosition;
        csl::math::Vector3 velocity;
        csl::math::Vector3 unkVec;
        csl::math::Position rotation;
        float unk124252;
        csl::math::Position initialRotation;
        csl::math::Position angularVelocity;
        csl::math::Position emitterSize;
        csl::math::Position emitterScale;
        float lifetime;
        float gap4Cbb[4];
        float unk4Cbbb;
        float directionJitter; //unsure
        unsigned int colorAnimationCount;
        ColorParameters colorParameters;
        int8_t gap4Cbbc[4];
        uint32_t unk1431523;
        uint32_t unk14315232;
        csl::ut::Bitset<AxisFlag> rotationAxes;
        char byte11D;
        char byte11E; // 0x01 init children
        bool byte11F;
        EmitParam emitParam;
        System::AnimCtrl* childrenAnimation[16];
        System::AnimCtrl* rotationAnimation;
        System::AnimCtrl* scaleAnimation;
        ColorAnimations colorAnimations;
        System::AnimCtrl* fieldAnimations[8][5];
        int64_t qword290[16];
        System::AnimCtrl* patternAnimation[4];
        System::AnimCtrl* uvAnimation;
        float textureUvScale[2]; //unsure, when used, it's multiplied by worldScale
        _Texcoord texCoords[4][2];
        Matrix23 matrices[4][2];
        HistoricalStripe* historicalStripe;
        unsigned int lightId;
        int32_t dword73C;
        System::AnimCtrl* animationBuffer; // 140FF3B70
        System::AnimCtrl* nextFreeAnimation; // 140FF3B77

        void UpdatePattern(float deltaTime, const Resource::TextureParam* textureParam, unsigned int textureIndex, float* stepSizes, float* unk3);
        void CalcTexcoordImpl(
            float arg0,
            const Resource::TextureParam* texParam,
            _Texcoord* texcoord,
            Cyan::Matrix23* matrix,
            float* p1,
            float* p2,
            unsigned int scrollIdx
        );
        void CalcTexcoord(float deltaTime);
        void InitColor(System::Random* random);
        void CalcInitVelocity(const csl::math::Vector3& acceleration, const csl::math::Vector3& velocityDirection, const csl::math::Vector3& accelarationDirection);
        static void CalcSphericalVector(csl::math::Vector3* direction, Cyan::System::Random* random);
        MemObject<System::AnimCtrl> CreateAnimCtrl(
            const Resource::PtrData<Resource::AnimationParam>& animParam,
            unsigned int unk0,
            float unk1,
            Cyan::Resource::ColorRandomSet* colorSet,
            System::AnimCtrl::CreateParam::RandomSetType type
        );
        void InitElement();
        void EmitChild(float deltaTime);

        virtual void Process(float deltaTime, Cyan::Element* unk);
        virtual void UpdateChildren(float deltaTime);
        virtual void Update(float deltaTime, Cyan::Element* unk) {}
        virtual void PrepareRender(Graphics::Renderer* renderer, Graphics::EffectObject* effectObject) {}
        virtual int GetHistoricalStripeBufferSize() const;
        virtual ~Element();
        virtual void InitParameter() {}

        Element(Emitter* emitter, const Resource::ElementParam* element);
    };
}
