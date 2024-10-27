#pragma once

namespace app::game {
    class RespawnTimeManager : public hh::game::GameService, public hh::game::GameManagerListener, public hh::game::GameStepListener, hh::game::EditorStepListener {
    public:
        enum class RespawnTimeType : uint8_t {
            TIME_SERVICE_MINUTES,
            GLOBAL_TIME_SECONDS,
        };

        enum class RespawnTimeTypePreference : uint32_t {
            AUTO, // timeservice minutes if timeservice is active, otherwise globalTime seconds
            GLOBAL_TIME_SECONDS,
            TIME_SERVICE_MINUTES,
        };

        enum class RespawnGroupId : int {
            DEFAULT,
            W1,
            W2,
            W3,
            W4,
        };

        struct ObjectRespawnInfo {
            hh::game::ObjectId objectId;
            Timestamp timestamp;
            float respawnTime;
            uint8_t unk1;
            uint8_t unk2;
            uint32_t unk3;
            bool shouldRespawn;
            RespawnTimeType respawnTimeType;
        };

        csl::ut::MoveArray<ObjectRespawnInfo> respawnGroups[5];
        RespawnGroupId currentRespawnGroup;
        float timeUntilNextUpdate;
        csl::fnd::Mutex mutex;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void ClearCurrentRespawnGroup();
        bool GetRespawnInfo(hh::game::ObjectId objectId, ObjectRespawnInfo* respawnInfo);
        void RemoveObject(hh::game::ObjectId objectId);
        void AddObject(hh::game::ObjectId objectId, float respawnTime, uint8_t unk1Param, uint8_t unk2Param, RespawnTimeTypePreference respawnTimeTypePreference, uint32_t unk3Param);
        void SetRespawnGroupFromStageName(const char* name);

        GAMESERVICE_CLASS_DECLARATION(RespawnTimeManager);
    };
}
