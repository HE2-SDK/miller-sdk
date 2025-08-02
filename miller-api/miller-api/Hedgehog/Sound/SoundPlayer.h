#pragma once

namespace hh::snd {
    struct SoundParam {
        float volume;
        float time;
        uint32_t unk2;
        uint32_t unk3;

        int unk4;
        uint32_t unk5;
        long long startTime;
        char pad1[0x18];
        uint64_t unk6;
        uint8_t unk7;
        uint32_t unk8;
        int firstBlockIndex;
    };

    class SoundPlayer;
    class SoundCategoryListener : public fnd::ReferencedObject, public SoundSystemListener {
    public:
        SoundPlayer* soundPlayer;

        virtual void PostRegisterData(unsigned int index) override;
        virtual void PreUnregisterData(unsigned int index) override;
    };

    class SoundPlayer : public fnd::BaseObject, public csl::fnd::Singleton<SoundPlayer> {
    public:

        struct ListenerIdMapArgs {
            unsigned int ids[1]; // size currently unknown
        };

        csl::ut::MoveArray<void*> unk10;
        csl::ut::MoveArray<SoundListenerObject> listenerObjects;
        csl::ut::MoveArray<void*> unk50;
        csl::ut::MoveArray<SoundPlaybackObject> playbackObjects;
        uint64_t qword90;
        uint64_t qword98;
        uint64_t qwordA0;
        uint64_t qwordA8;
        uint64_t qwordB0;
        uint64_t qwordB8;
        uint32_t dwordC0;
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint64_t qwordD8;
        uint64_t qwordE0;
        uint64_t qwordE8;
        uint64_t qwordF0;
        fnd::Reference<SoundCategoryListener> soundCategoryListener;
        csl::ut::MoveArray<void*> unk100;
        fnd::Reference<fnd::ReferencedObject> vibrationHapticListener; // todo

        CREATE_FUNC(SoundPlayer, unsigned int size);
        SoundSystemListener* GetCategoryListener() const;

        SoundPlaybackObject* GetFreePlaybackObject();

        void AddListenerObject(SoundListenerObject& obj);
        void AddPlaybackObject(SoundPlaybackObject& obj);

        virtual void* GetRuntimeTypeInfo() const;
        virtual SoundHandle Play(unsigned int category, const char* name, const SoundParam& soundParam);
        virtual SoundHandle Play3D(unsigned int category, const char* name, const csl::math::Vector3& position, const SoundParam& soundParam);
        virtual void SetListenerIdMap(const ListenerIdMapArgs& listenerIdMapArgs) {}
        virtual void SetSourceDefaultDistance(float dist1, float dist2) {}
        virtual void SetMinDistance(const SoundHandle& source, float minDistance) {}
        virtual void SetMaxDistance(const SoundHandle& source, float maxDistance) {}
        virtual void SetMinMaxDistance(const SoundHandle& source, float minDistance, float maxDistance) {}
        virtual void SetMasterVolume(unsigned int category, float volume) {}
        virtual float GetMasterVolume(unsigned int category) const;
        virtual void SetMasterMute(unsigned int category, bool enabled) {}
        virtual bool IsMasterMute(unsigned int category) const { return false; }
        virtual void AttachCategoryAisac(unsigned int category, const char* aisacName, const char* controlName);
        virtual void DetachCategoryAisac(unsigned int category, const char* aisacName, const char* controlName);
        virtual void DetachCategoryAisacAll(unsigned int category);
        virtual void UnkFunc16() {}
        virtual void UnkFunc17() {}
        virtual void SetDspParameter(const SoundHandle& source, int id, float value) {}
        virtual void UnkFunc19() {}
        virtual void UnkFunc20();
        virtual void UnkFunc21();
        virtual void Stop(const SoundHandle& source, float time);
        virtual void StopImm(const SoundHandle& source) {}
        virtual void UnkFunc24() {}
        virtual void Pause(const SoundHandle& source, bool enabled, float time) {}
        virtual void UnkFunc26() {}
        virtual void SetVolume(const SoundHandle& source, float volume) {}
        virtual int UnkFunc28(const SoundHandle& source) const;
        virtual void SetBlockIdx(const SoundHandle& source, int idx) {}
        virtual void SetBlockIdxByName(const SoundHandle& source, const char* name) {}
        virtual int UnkFunc31(const SoundHandle& source) const;
        virtual unsigned int GetNumBlocks(const SoundHandle& source) const;
        virtual void SetSelectorLabel(const SoundHandle& source, const char* unkParam1, const char* unkParam2) {}
        virtual unsigned int GetStatus(const SoundHandle& source) const;
        virtual bool IsPause(const SoundHandle& source) const { return false; }
        virtual bool IsPlay(const SoundHandle& source) const { return false; }
        virtual bool IsLoop(const SoundHandle& source) const { return false; }
        virtual bool IsLoop2(const SoundHandle& source) const { return false; }
        virtual csl::math::Vector3 GetSourcePosition(const SoundHandle& source) const;
        virtual void SetSourcePosition(const SoundHandle& source, const csl::math::Vector3& position) {}
        virtual void SetSourceVelocity(const SoundHandle& source, const csl::math::Vector3& velocity) {}
        virtual float GetListenerDistance(const SoundHandle& source, const SoundListenerHandle& listener) const;
        virtual void UnkFunc43() {}
        virtual float GetPlayTime(const SoundHandle& source) const;
        virtual unsigned int UnkFunc45() const;
        virtual float UnkFunc46() const;
        virtual const char* GetCueName(const SoundHandle& source) const;
        virtual unsigned int UnkFunc48() const;
        virtual unsigned int UnkFunc49() const;
        virtual bool IsAisac(const SoundHandle& source) const { return false; }
        virtual void SetAisac(const SoundHandle& source, const char* controlName, float value);
        virtual bool AttachAisac(const SoundHandle& source, const char* controlName, float value) { return false; }
        virtual bool DetachAisac(const SoundHandle& source, const char* controlName);
        virtual void DetachAisacAll(const SoundHandle& source);
        virtual void UnkFunc55() {}
        virtual unsigned int UnkFunc56() const;
        virtual unsigned int UnkFunc57() const;
        virtual csl::math::Vector3 UnkFunc58() const;
        virtual void UnkFunc59() {}
        virtual void UnkFunc60() {}
        virtual void UnkFunc61() {}
        virtual void UnkFunc62() {}
        virtual csl::math::Vector3 UnkFunc63() const;
        virtual void UnkFunc64() {}
        virtual float UnkFunc65() const;
        virtual void UnkFunc66() {}
        virtual void UnkFunc67() {}
        virtual void UnkFunc68() {}
        virtual void CategoryPause(const SoundHandle& source, bool enabled, float time) {}
        virtual bool MatchCategory(unsigned int category, void* unkParam) { return true; }
    };

    class SoundPlayerCri : public SoundPlayer {
    public:
        CREATE_FUNC(SoundPlayerCri, const SoundCueCri::PoolParam* poolParam);
        SoundPlaybackObject* CreatePlaybackObject(unsigned int category, const char* name);
        SoundHandle PlayCore(SoundPlaybackObject* playbackObject, const SoundParam& soundParam);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual SoundHandle Play(unsigned int category, const char* name, const SoundParam& soundParam) override;
        virtual SoundHandle Play3D(unsigned int category, const char* name, const csl::math::Vector3& position, const SoundParam& soundParam) override;
        virtual void SetListenerIdMap(const ListenerIdMapArgs& listenerIdMapArgs) override;
        virtual void SetSourceDefaultDistance(float dist1, float dist2) override;
        virtual void SetMinDistance(const SoundHandle& source, float minDistance) override;
        virtual void SetMaxDistance(const SoundHandle& source, float maxDistance) override;
        virtual void SetMinMaxDistance(const SoundHandle& source, float minDistance, float maxDistance) override;
        virtual void SetMasterVolume(unsigned int category, float volume) override;
        virtual float GetMasterVolume(unsigned int category) const override;
        virtual void SetMasterMute(unsigned int category, bool enabled) override;
        virtual bool IsMasterMute(unsigned int category) const override;
        virtual void AttachCategoryAisac(unsigned int category, const char* aisacName, const char* controlName) override;
        virtual void DetachCategoryAisac(unsigned int category, const char* aisacName, const char* controlName) override;
        virtual void DetachCategoryAisacAll(unsigned int category) override;
        virtual void UnkFunc16() override;
        virtual void UnkFunc17() override;
        virtual void SetDspParameter(const SoundHandle& source, int id, float value) override;
        virtual void UnkFunc19() override;
        virtual void Stop(const SoundHandle& source, float time) override;
        virtual void StopImm(const SoundHandle& source) override;
        virtual void UnkFunc24() override;
        virtual void Pause(const SoundHandle& source, bool enabled, float time) override;
        virtual void UnkFunc26() override;
        virtual void SetVolume(const SoundHandle& source, float volume) override;
        virtual int UnkFunc28(const SoundHandle& source) const override;
        virtual void SetBlockIdx(const SoundHandle& source, int idx) override;
        virtual void SetBlockIdxByName(const SoundHandle& source, const char* name) override;
        virtual int UnkFunc31(const SoundHandle& source) const override;
        virtual unsigned int GetNumBlocks(const SoundHandle& source) const override;
        virtual void SetSelectorLabel(const SoundHandle& source, const char* unkParam1, const char* unkParam2) override;
        virtual unsigned int GetStatus(const SoundHandle& source) const override;
        virtual bool IsPause(const SoundHandle& source) const override;
        virtual bool IsPlay(const SoundHandle& source) const override;
        virtual bool IsLoop(const SoundHandle& source) const override;
        virtual bool IsLoop2(const SoundHandle& source) const override;
        virtual csl::math::Vector3 GetSourcePosition(const SoundHandle& source) const override;
        virtual void SetSourcePosition(const SoundHandle& source, const csl::math::Vector3& position) override;
        virtual void SetSourceVelocity(const SoundHandle& source, const csl::math::Vector3& velocity) override;
        virtual float GetListenerDistance(const SoundHandle& source, const SoundListenerHandle& listener) const override;
        virtual void UnkFunc43() override;
        virtual float GetPlayTime(const SoundHandle& source) const override;
        virtual unsigned int UnkFunc45() const override;
        virtual float UnkFunc46() const override;
        virtual const char* GetCueName(const SoundHandle& source) const override;
        virtual unsigned int UnkFunc48() const override;
        virtual unsigned int UnkFunc49() const override;
        virtual bool IsAisac(const SoundHandle& source) const override;
        virtual void SetAisac(const SoundHandle& source, const char* controlName, float value) override;
        virtual bool DetachAisac(const SoundHandle& source, const char* controlName) override;
        virtual void DetachAisacAll(const SoundHandle& source) override;
        virtual void UnkFunc55() override;
        virtual unsigned int UnkFunc56() const override;
        virtual unsigned int UnkFunc57() const override;
        virtual csl::math::Vector3 UnkFunc58() const override;
        virtual void UnkFunc59() override;
        virtual void UnkFunc60() override;
        virtual void UnkFunc61() override;
        virtual void UnkFunc62() override;
        virtual csl::math::Vector3 UnkFunc63() const override;
        virtual void UnkFunc64() override;
        virtual float UnkFunc65() const override;
        virtual void UnkFunc66() override;
        virtual void UnkFunc67() override;
        virtual void UnkFunc68() override;
        virtual void CategoryPause(const SoundHandle& source, bool enabled, float time) override;
        virtual bool MatchCategory(unsigned int category, void* unkParam) override;
        virtual void UnkFunc71();
        virtual bool UnkFunc72();
    };
}
