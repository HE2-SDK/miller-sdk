#pragma once

namespace app::level {
    class StageData : hh::fnd::ReferencedObject {
    public:
        enum class ChunkType : unsigned char {
            INITIAL = 0,
            AFTER = 1,
        };

        enum class AttributeFlags : unsigned long long
        {
            TEST_STAGE = 2,
            NAVMESH = 3,
            HEIGHTFIELD = 4,
            POINTCLOUD = 5,
            AUTOSAVE = 6,
            DIVING = 8,
            SIDE_STEP = 9,
            ATHLETIC = 10,
            BOARDING = 11,
            DRIFT = 12,
            SIDE_VIEW = 13,
            LAVA = 14,
            BOSS = 15,
            WHITE_SPACE = 16,
            IBL_CAPTURE_WITH_SV_COL = 17,
            USE_SPEED_LINE_FOLLOW_EFFECT = 18,
        };

        enum class ClearType : unsigned int
        {
            GOAL = 0,
            TIME = 1,
        };

        csl::ut::String name;
        csl::ut::String stage;
        csl::ut::String path;
        csl::ut::String sceneParamName;
        csl::ut::String sceneParamStage;
        csl::ut::String geditResourceName;
        csl::ut::String bgm;
		int stageIndex;
		unsigned int defaultSceneParamIndex;
		csl::ut::Bitset<AttributeFlags> attributeFlags;
		csl::ut::MoveArray<uint8_t> staticSectors;
		csl::ut::MoveArray<uint8_t> dynamicSectors;
		ChunkType chunkType;
		float timeLimit;
		float deathPlaneHeight;
		float noiseTime;
		ClearType clearType;
        unsigned int unk1;
		unsigned int rank[4];
    
        static StageData* Create(csl::fnd::IAllocator* allocator);
        StageData(csl::fnd::IAllocator* allocator);

        // returns value of `stage` if cyber stage, `name` if other stage
        const char* GetStageName() const;

        inline const char* GetName() const {
            return name.c_str();
        }
    };
}
