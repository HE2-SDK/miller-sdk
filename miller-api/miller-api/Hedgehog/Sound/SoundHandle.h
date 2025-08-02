#pragma once

enum CriAtomExParameterIdTag {
    CRIATOMEX_PARAMETER_ID_VOLUME = 0,
    CRIATOMEX_PARAMETER_ID_PITCH = 1,
    CRIATOMEX_PARAMETER_ID_PAN3D_ANGLE = 2,
    CRIATOMEX_PARAMETER_ID_PAN3D_DISTANCE = 3,
    CRIATOMEX_PARAMETER_ID_PAN3D_VOLUME = 4,
    CRIATOMEX_PARAMETER_ID_PAN_TYPE = 5,
    CRIATOMEX_PARAMETER_ID_PAN_SPEAKER_TYPE = 6,
    CRIATOMEX_PARAMETER_ID_PAN_CH0 = 7,
    CRIATOMEX_PARAMETER_ID_PAN_CH1 = 8,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_0 = 9,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_1 = 10,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_2 = 11,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_3 = 12,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_4 = 13,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_5 = 14,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_6 = 15,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_7 = 16,
    CRIATOMEX_PARAMETER_ID_BANDPASS_FILTER_COF_LOW = 17,
    CRIATOMEX_PARAMETER_ID_BANDPASS_FILTER_COF_HIGH = 18,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_TYPE = 19,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_FREQ = 20,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_Q = 21,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_GAIN = 22,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_ATTACK_TIME = 23,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_HOLD_TIME = 24,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_DECAY_TIME = 25,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_RELEASE_TIME = 26,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_SUSTAIN_LEVEL = 27,
    CRIATOMEX_PARAMETER_ID_START_TIME = 28,
    CRIATOMEX_PARAMETER_ID_PRIORITY = 31,
    CRIATOMEX_PARAMETER_ID_SILENT_MODE = 32,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_0 = 33,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_1 = 34,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_2 = 35,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_3 = 36,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_4 = 37,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_5 = 38,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_6 = 39,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_7 = 40,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_8 = 41,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_9 = 42,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_10 = 43,
    CRIATOMEX_PARAMETER_ID_DSP_BYPASS_FLAG = 44,
    CRIATOMEX_PARAMETER_ID_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
};

struct CriAtomExPlayerParameter{};
typedef CriAtomExPlayerParameter* CriAtomExPlayerParameterHn;

void criAtomExPlayerParameter_SetParameterValue(CriAtomExPlayerParameterHn player_parameter, unsigned int id, unsigned int value);
void criAtomExPlayerParameter_SetParameterFloat32(CriAtomExPlayerParameterHn player_parameter, unsigned int id, float value);
void criAtomExPlayerParameter_SetParameterUint32(CriAtomExPlayerParameterHn player_parameter, unsigned int id, unsigned int value);
void criAtomExPlayerParameter_SetParameterSint32(CriAtomExPlayerParameterHn player_parameter, unsigned int id, int value);

struct CriAtomExPlayer{
    char pad1[0x1D8];
    CriAtomExPlayerParameterHn parameter;
};
typedef CriAtomExPlayer* CriAtomExPlayerHn;

unsigned int criAtomExPlayer_GetParameterId(CriAtomExParameterIdTag id);

namespace hh::snd {
    class SoundPlayer;

    struct HandleTag3d {
        float position[3];
        float velocity[3];
        float float48;
    };

    struct HandleTag {
        uint64_t qword0;
        CriAtomExPlayerHn* player;

        SoundCueCri::CdataTag cueData;
        HandleTag3d tag3d;
        uint32_t dword4C;
        uint32_t dword50;
        uint64_t qword58;
        uint64_t qword60;
        uint32_t dword68;
        uint32_t dword6C;
        uint32_t dword70;
        uint32_t dword74;
        SoundTween hh__snd__soundtween78;
        uint32_t qword90;
        uint32_t qword94;
    };

    void HandleTagInit(HandleTag* tag);

    class SoundObjectBase : public fnd::RefByHandleObject {
    public:
        HandleTag* tag;
        uint32_t id;

        SoundObjectBase();
    };

    class SoundListenerObject : public SoundObjectBase {
    public:
        typedef fnd::HandleManager<SoundListenerObject> HandleManager;
        SoundListenerObject();
    };

    class SoundPlaybackObject : public SoundObjectBase {
    public:
        typedef fnd::HandleManager<SoundPlaybackObject> HandleManager;
    
        csl::ut::MoveArray<void*> unk101;
        uint64_t unk102;

        SoundPlaybackObject();
    };

    class SoundListenerHandle {
    public:
        fnd::Handle<SoundListenerObject> handle;
        SoundPlayer* soundPlayer;

        SoundListenerHandle(const SoundListenerObject* handle);
        SoundListenerHandle();
    };

    class SoundHandle {
    public:
        fnd::Handle<SoundPlaybackObject> handle;

        void Stop(float time);
        void StopImm();
        void Pause(bool enabled, float time);
        void SetVolume(float volume);
        void SetBlockIdx(int idx);
        void SetBlockIdxByName(char const* name);
        unsigned int GetStatus() const;
        bool IsPlay() const;
        bool IsPause() const;
        bool IsLoop() const;
        const char* GetCueName() const;
        csl::math::Vector3 GetPosition() const;
        void SetPosition(const csl::math::Vector3& position);
        void SetVelocity(const csl::math::Vector3& velocity);
        float GetDistance(const SoundListenerHandle& listener);
        float GetPlayTime() const;
        bool IsAisac() const;
        void SetAisac(const char* id, float value);
        void AttachAisac(const char* id);
        void DetachAisac(const char* id);
        void DetachAisacAll();
        void SetMultiTrackMode(bool unkParam);
        void SetTrackVolume(int track, float volume);
        void SetMaxDistance(float maxDistance);
        void SetMinDistance(float minDistance);
        void SetMinMaxDistance(float minDistance, float maxDistance);
    };
}
