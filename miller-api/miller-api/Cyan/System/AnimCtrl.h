#pragma once

namespace Cyan::System {
    class AnimCtrl {
    public:
        struct CurveStatus {
            const Resource::AnimationTrackParam* animationTrackParam;
            Resource::JitteredValue value;
            int currentFrame;
            int unk5;
            const Resource::JitteredValue* randomSet;
            int randomSetSize;
            int randomTableOffset;
            int randomSetRandomTableOffset;
            unsigned char unk10;
            bool includesEndFrame;
        };

        struct CreateParam {
            enum class RandomSetType : unsigned int {
                NONE,
                COLOR_1,
                COLOR_2,
                UNK_1,
                UNK_2,
                ALPHA_1,
                ALPHA_2,
            };

            System::RandomTable* randomTable;
            System::Random* random;
            unsigned int flags;
            float duration;
            float startTime;
            float jitterConstantNess; // 0 -> 1; 0: jitter 100% = value, 1: jitter 100% = 1; i.e. `value = value + rand() * jitter * (jitterConstantNess + (1 - jitterConstantness) * value)`
            Resource::ColorRandomSet* colorSet;
            RandomSetType randomSetType;
            int unk4;
        };

        const Resource::AnimationParam* animParam;
        float durationScaling;
        float time;
        float currentFrame;
        int loopCount;
        float speed;
        CurveStatus curves[4];
        CreateParam createParam;
        bool initialized;
        bool byte111;
        int64_t qword118;
        int64_t qword120;

        AnimCtrl(const Resource::AnimationParam* animParam, const CreateParam& createParam);

        void InitAnimation(const CreateParam& createParam);
        void InitAnimationJittered(const CreateParam& createParam);
        void Update(float deltaTime);
        void Update(float deltaTime, unsigned char* unk10values);
        void UpdateJittered(float deltaTime);
        void UpdateJittered(float deltaTime, unsigned char* unk10values);
        float GetValue(int curveIndex) const;
        unsigned int GetValues(float* values, int count) const;
        void GetValuesJittered(Resource::JitteredValue* values) const;
        float GetKeyValue(const CurveStatus* curveStatus, int key) const;
        unsigned int GetCurveNum() const;
        float CalcKeyValue(float unk, float unk2, CurveStatus* curveStatus);
        float CalcKeyValueJittered(float unk, float unk2, CurveStatus* curveStatus);
        float Interpolation(const CurveStatus* curveStatus, int startKeyIndex, float ratio, float range);
        Resource::JitteredValue InterpolationJittered(const CurveStatus* curveStatus, int startKeyIndex, float ratio, float range);
        void SetTime(float time, bool unkParam);
        void SetTimeJittered(float time, bool unkParam);
        bool HasRandomTableTrack() const;
    };
}
