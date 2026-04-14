#pragma once

namespace hh::eff{
    class ResEffect;
}

namespace Cyan {
    struct PerEffectData {
        int64_t unk0;
        int unk1;
        float unk2;
        int unk3;
        char unk4[0x100];
        int64_t unk5;
        csl::math::Matrix44 unk6;
    };

    struct EffectInstanceParam {
        hh::eff::ResEffect* resource{};
        hh::needle::intrusive_ptr<hh::needle::NeedleRefcountObject>* nodeUnkParam1{};
        void* nodeUnkParam2{};
        unsigned int nodeIndex{};
        uint64_t unk1{};
    };

    class Effect;
    class Emitter;
    class EffectTag {
    public:
        int id;
        Effect* effect;
        EffectTag();
        EffectTag(const EffectTag& other);

        const csl::math::Vector3& GetScale() const;
        const csl::ut::Color8& GetColor() const;
        uint8_t GetAlpha() const;

        void SetScale(const csl::math::Vector3& scale);
        void SetColor(const csl::ut::Color8& color);
        void SetAlpha(uint8_t alpha);
    };

    class EffectHandle {
    public:
        int unk1;
        Cyan::EffectTag* tag;

        EffectHandle();
        EffectHandle(const EffectHandle& other);
    };

    class Effect {
    public:
        struct SetupInfo { };

        virtual void Start() = 0;
        virtual void Stop(bool unk) = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;
        virtual bool IsPaused() const = 0;
        virtual void Step() = 0;
        virtual void SetMatrix(const csl::math::Matrix34& matrix) = 0;
        virtual csl::math::Matrix34 GetMatrix() const = 0;
        virtual void SetColor(csl::ut::Color8 color) = 0;
        virtual csl::ut::Color8 GetColor() const = 0;
        virtual void SetAlpha(unsigned char alpha) = 0;
        virtual unsigned char GetAlpha() const = 0;
        virtual void SetScale(const csl::math::Vector3& scale) = 0;
        virtual csl::math::Vector3 GetScale() const = 0;
        virtual void SetElementScale(const csl::math::Vector3 scale) = 0;
        virtual csl::math::Vector3 GetElementScale() const = 0;
        virtual void SetEmitRatio(float emitRatio) = 0;
        virtual float GetEmitRatio() const = 0;
        virtual void* GetData() = 0;
        virtual Resource::EffectParam* GetParam() const = 0;
        virtual const char* GetName() const = 0;
        virtual void* GetUnk1() const = 0;
        virtual void SetViewMask(unsigned int viewMask) = 0;
        virtual unsigned int GetViewMask() const = 0;
        virtual void SetUnk2(unsigned int value) = 0;
        virtual unsigned int GetUnk2() const = 0;
        virtual void SetVisibility(bool enabled) = 0;
        virtual bool GetVisibility() const = 0;
        virtual void SetBillboardViewportID(unsigned int viewportId) = 0;
        virtual EffectInstanceParam& GetInstanceParam() const = 0;
        virtual void Setup(SetupInfo& setupInfo) = 0;
        virtual void SetPlaybackSpeed(float value) = 0;
        virtual void SetElementLifetimeScale(float value) = 0;
        virtual bool GetUnk5() const = 0;
        virtual bool GetUnk6() const = 0;
        virtual bool GetUnk7() const = 0;
        virtual ~Effect() = default;
    };

    class EffectImpl : public Effect {
    public:
        enum class Flag {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            FIXED_REFRESH_RATE, // 60 fps
        };

        struct SetupInfo : Effect::SetupInfo {
            hh::eff::ResEffect* resource;
            int64_t unk0;
            int64_t unk1;
            int32_t unk2;
            int64_t unk3;
        };

        char name[128];
        ManagerImpl* manager;
        uint64_t root;
        const Resource::EffectParam* param;
        uint32_t dwordA0;
        uint32_t viewMask;
        uint32_t dwordA8;
        Emitter* emitter;
        System::LinkList<EffectImpl>::Entry managerLinkListEntry;
        System::LinkList<EffectImpl>::Entry sceneLinkListEntry;
        EffectHandle effecthandleE8;
        EffectHandle effecthandleF8;
        csl::ut::Bitset<Flag> flags;
        EffectInstanceParam instanceParam;
        PerEffectData* perEffectData;

        EffectImpl(ManagerImpl* managerImpl, Resource::EffectParam* effectParam, unsigned int unkParam1, const EffectInstanceParam& instanceParam, const InheritChildParam* unkParam3, EffectImpl* parent, bool unkParam5, float unkParam6);

        void SetDataBuffer(PerEffectData* data);
        void PrepareRender(Graphics::Renderer* renderer, const Graphics::DeviceContainer& deviceContainer);
        float GetWorldScale() const;

        virtual void Start() override;
        virtual void Stop(bool unk) override; //bool prolly means "immediately"
        virtual void Pause() override;
        virtual void Resume() override;
        virtual bool IsPaused() const override;
        virtual void Step() override;
        virtual void SetMatrix(const csl::math::Matrix34& matrix) override;
        virtual csl::math::Matrix34 GetMatrix() const override;
        virtual void SetColor(csl::ut::Color8 color) override;
        virtual csl::ut::Color8 GetColor() const override;
        virtual void SetAlpha(unsigned char alpha) override;
        virtual unsigned char GetAlpha() const override;
        virtual void SetScale(const csl::math::Vector3& scale) override;
        virtual csl::math::Vector3 GetScale() const override;
        virtual void SetElementScale(const csl::math::Vector3 scale) override;
        virtual csl::math::Vector3 GetElementScale() const override;
        virtual void SetEmitRatio(float emitRatio) override;
        virtual float GetEmitRatio() const override;
        virtual void* GetData() override;
        virtual Resource::EffectParam* GetParam() const override;
        virtual const char* GetName() const override;
        virtual void* GetUnk1() const override;
        virtual void SetViewMask(unsigned int viewMask) override;
        virtual unsigned int GetViewMask() const override;
        virtual void SetUnk2(unsigned int value) override;
        virtual unsigned int GetUnk2() const override;
        virtual void SetVisibility(bool enabled) override;
        virtual bool GetVisibility() const override;
        virtual void SetBillboardViewportID(unsigned int viewportId) override;
        virtual EffectInstanceParam& GetInstanceParam() const override;
        virtual void Setup(Effect::SetupInfo& setupInfo) override;
        virtual void SetPlaybackSpeed(float value) override;
        virtual void SetElementLifetimeScale(float value) override;
        virtual bool GetUnk5() const override;
        virtual bool GetUnk6() const override;
        virtual bool GetUnk7() const override;
        virtual void SetUnk8(bool enabled);
    };
}
