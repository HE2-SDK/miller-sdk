#pragma once

#ifdef PlaySound
#undef PlaySound
#endif

namespace hh::snd {
    struct SoundFollowFrameInfo {
        hh::fnd::HFrame* frame;
        csl::math::Vector3 offset;
    };

    struct SoundPlayInfo {
        enum class Flag : unsigned char {
            UNK0,
            OFFSET,
        };

        const char* name{};
        uint32_t unk1{};
        uint32_t unk2{};
        float time{};
        fnd::HFrame* frame{};
        csl::math::Vector3 unk3{ 0.0f, 0.0f, 0.0f };
        csl::ut::Bitset<Flag> flags{};
        unsigned int unk4{};
        csl::math::Vector3 offset{ 0.0f, 0.0f, 0.0f };
    };

    struct SoundTransInfo {
        enum class Flag : unsigned char {
            UNK0,
            OFFSET,
        };

        csl::math::Vector3 offset;
        uint8_t unk1;
        csl::ut::Bitset<Flag> flags;
        fnd::HFrame* frame;
        SoundHandle handle;
    };

    class GOCSound : public game::GOComponent {
    public:
        struct LiveSoundInfo {
            SoundHandle handle;
            SoundFollowFrameInfo followFrameInfo;
        };

        SoundManager* soundManager;
        fnd::HFrame* frame;
        uint32_t unk103;
        csl::ut::MoveArray<SoundHandle> sounds;
        csl::ut::MoveArray<SoundTransInfo> soundTransInfos;
        csl::ut::MoveArray<LiveSoundInfo> liveSoundInfos;
    
        struct SetupInfo {
            int soundCount{};
            int transInfoCount{};
            uint32_t unk2{};
            bool noUpdate{};
        };

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool fUnk5() override { return true; }
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);

        SoundHandle CreateSoundHandle3D(unsigned int category, const char* name, const SoundFollowFrameInfo& followFrameInfo, const SoundParam& soundParam);
        SoundHandle CreateSoundHandle(unsigned int category, const char* name, const SoundParam& soundParam);

        SoundHandle Play3D(const SoundPlayInfo& playInfo);
        SoundHandle Play3D(unsigned int category, const char* name);
        SoundHandle Play3D(const char* name, const SoundParam& soundParam);
        SoundHandle Play3D(const char* name, const csl::math::Vector3& position, const SoundParam& soundParam);
        SoundHandle Play3D(const char* name, const csl::math::Vector3& position, float time);
        SoundHandle Play3D(const char* name, float time);
        SoundHandle Play(unsigned int category, const char* name);
        SoundHandle Play(unsigned int category, const char* name, const SoundParam& soundParam);
        SoundHandle Play(const char* name, const SoundParam& soundParam);
        SoundHandle Play(const char* name, float time);
        
        SoundHandle Play3D(unsigned int category, const SoundPlayInfo& playInfo);
        SoundHandle PlayVoice3D(const SoundPlayInfo& playInfo);
        SoundHandle PlayVoice3D(const char* name);
        SoundHandle PlayVoice(const char* name);

        void StopFollow(const SoundHandle& handle, float time);
        void StopAll(float time);

        GOCOMPONENT_CLASS_DECLARATION(GOCSound);
    };
}
