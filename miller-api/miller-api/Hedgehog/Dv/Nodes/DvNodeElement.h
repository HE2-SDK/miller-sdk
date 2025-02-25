#pragma once

#define DV_ELEMENT_DECLARATION_BASE(ClassName)public:\
        ClassName(csl::fnd::IAllocator* allocator);\
		static hh::dv::DvElementBase* Create(hh::dv::DvNodeElement* baseNode, csl::fnd::IAllocator* allocator);

namespace hh::dv{
    class DvNodeElement;

    class DvElementBase : public hh::fnd::ReferencedObject {
    public:
        DvNodeElement* baseNode;

        DvElementBase(csl::fnd::IAllocator* allocator);

        virtual void Update(int currentFrame, csl::math::Transform transform) {};
        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) { return true; };
        virtual void* RemoveCallback() {};
        virtual void SetData(void* data) {};
        virtual void DeleteData() {};
        virtual bool UnkFunc5() { return true; };
        virtual void UnkFunc6(int currentFrame, csl::math::Transform transform) {};
        virtual void UnkFunc7() {};
        virtual void UnkFunc8() {};

        game::GameService* GetService(const game::GameServiceClass* gameServiceClass);
        DvSceneControl* GetDvSceneControl();
        float CalculateCurrentCurve(int dataSize, int currentFrame, float* data, int unk);
    };

    class DvNodeElement : public DvNodeBase {
    public:
        enum class ElementID : unsigned int {
            CAMERA_PARAMS = 1,
            // 2 = Empty, nothing
            DRAW_OFF = 3,
            // 4 = Empty, nothing
            PATH_OFFSET = 5,
            CAMERA_SHAKE = 6,
            CAMERA_SHAKE_LOOP = 7,
            EFFECT = 8,
            DIRECTIONAL_LIGHT = 9,
            PATH_INTERPOLATION = 10,
            CULLING_DISABLE = 11,
            CAMERA_NEAR_FAR = 12,
            UV_ANIM = 13,
            VISIBILITY_ANIM = 14,
            MATERIAL_ANIM = 15,
            MULTIPLE_ANIM = 16,
            CAMERA_OFFSET = 17,
            MODEL_FADE = 18,
            DEBUG_MOTION = 19,
            CAMERA_HEDGEHOG = 20,
            CAMERA_IN_GAME = 21,
            POINT_LIGHT = 22,
            VERTEX_ANIMATION_TEXTURE = 23,
            SPOTLIGHT = 24,
            CONTROLLER_VIBRATION = 25,
            TEXTURE_PATTERN_ANIM = 26,
            MATERIAL_PARAM = 27,
        
            BLOOM_PARAM = 1000,
            DOF_PARAM = 1001,
            COLOR_CONTRAST = 1002,
            CAMERA_CONTROL = 1003,
            SHADOW_RESOLUTION = 1004,
            SSAO_PARAM = 1005,
            OCCLUSION_CAPSULE_PARAM = 1006,
            GODRAY_PARAM = 1007,
            ATMOSPHERE_GODRAY_PARAM = 1008,
            ATMOSPHERE_HEIGHT_FOG_PARAM = 1009,
            CHROMATIC_ABERRATION_FILTER_PARAM = 1010,
            VIGNETTE_PARAM = 1011,
            FADE = 1012,
            LETTER_BOX = 1013,
            MODEL_CLIPPING = 1014,
            PBA_RESET = 1015,
            BOSS_NAME = 1016,
            CAPTION = 1017,
            SOUND = 1018,
            TIME = 1019,
            SUN = 1020,
            LOOK_AT_IK = 1021,
            CAMERA_BLUR_PARAM = 1022,
            GENERAL_TRIGGER = 1023,
            FOOT_IK = 1024,
            DITHER_PARAM = 1025,
            QTE = 1026,
            FACIAL_ANIMATION = 1027,
            OVERRIDE_ASM = 1028,
            AURA = 1029,
            CHANGE_TIME_SCALE = 1030,
            CYBER_SPACE_NOISE = 1031,
            LIP_ANIMATION = 1032,
            AURA_ROAD = 1033,
            MOVIE_VIEW = 1034,
            CROSS_FADE = 1035,
            WEATHER = 1036,
            SHADOW_MAP_PARAM = 1037,
            VARIABLE_POINT_LIGHT = 1038,
            OPENING_LOGO = 1039,
            DENSITY_SECTOR_POINT = 1040,
            BULLET_TIME = 1041,
            TIME_STOP = 1042,
            OBJECT_TIME_STOP = 1043,
            SHADOW_SHAPE = 1044,
            FALLOFF = 1045,
            FOG = 1046,
            DOF = 1047,
            FX_COL_UPDATE = 1048
        };

        enum class PlayType : uint32_t{
            NORMAL,
            ONESHOT,
            ALWAYS
        };

        enum class UpdateTiming : uint32_t{
            ON_EXEC_PATH,
            ON_PRE_UPDATE,
            CHARACTER_FIX_POSTURE,
            ON_POST_UPDATE_CHARACTER,
            ON_UPDATE_POS,
            ON_FIX_BONE_POSTURE,
            ON_EVALUATE_DETAIL_MOTION,
            CHARACTER_JOB_UPDATE,
            MODIFY_POSE_AFTER,
            JOB_REGISTER,
            MOTION_UPDATE
        };

        struct Data {
            enum class Flags : unsigned char {
                UNK0,
                LOOSE_LENGTH
            };

            ElementID elementId;
            float start;
            float end;
            int unk1;
            csl::ut::Bitset<Flags> flags;
            PlayType playType;
            UpdateTiming updateTiming;
            int padding;
        };

        int isActive;
        Data binaryData;
        int unk0;
        DvElementBase* element;
        int start;
        int end;

        virtual void Setup(void* setupInfo) override;
        virtual void Start() override;
        virtual void Update(int curFrame) override;
        virtual void UnkFunc1(void* unk) override;
        virtual bool IsUnkFlag0() override;
        virtual int GetUpdateTiming() override;
        virtual void UnkFunc6(void* unk0, void* unk1) override;

        static const void** elementBaseCreateFuncs[28];

        DV_NODE_DECLARATION_BASE(DvNodeElement)
    };
}