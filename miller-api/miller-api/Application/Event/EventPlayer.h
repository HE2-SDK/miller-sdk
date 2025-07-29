#pragma once

namespace app::evt {
    class EventPlayerListener {
    public:
        virtual void EPL_UnkFunc1() {}
        virtual void EPL_UnkFunc2() {}
        virtual void EPL_UnkFunc3() {}
        virtual void EPL_UnkFunc4() {}
        virtual void EPL_UnkFunc5() {}
        virtual void EPL_UnkFunc6() {}
        virtual void OnMessage(hh::fnd::Message* msg) {}
        virtual void EPL_UnkFunc8() {}
        virtual void EPL_UnkFunc9() {}
    };

    class EventPlayer;

    struct EventSetupData {
    public:
        struct UnkStr {
        public:
            float dword0;
            int64_t qword4;
            int dwordC;
            int64_t qword10;
            int64_t qword18;
            int64_t qword20;
            int64_t qword28;
            int64_t qword30;
            int64_t qword38;
            int64_t qword40;
            int64_t qword48;
            int dword50;
            char unk7;
            int64_t unk8;
        };

        enum class PlayFlag : unsigned int {
            USE_SETUP_TRANSFORM, // uses the position, rotation and scale variables instead of the ones in the file
            STOP_FADE_OUT,       // whetever the cutscene should end or it should be in a limbo
            CANT_SKIP,           // whetever the cutscene is unskippable or not
            UNK0,                // unknown
            UNK1,                // unknown
            ENABLE_HUD,          // whetever the cockpit ui will show up
        };

        enum class PlayerFlag : unsigned char {
            USE_POSITION,   // set the player position from world position
            USE_ROTATION,   // set the player rotation from world position
            UNK0,           // unknown
        };

        char cutsceneName[40];
        char soundName[40];
        csl::math::Vector3 position;
        csl::math::Quaternion rotation;
        csl::math::Vector3 scale;
        int unk2;
        float speed;
        csl::ut::Bitset<PlayFlag> playFlags;
        int unk3;
        int unk4;
        float unk5;
        UnkStr unkStr;
        char unk7;
        int unk8;
        hh::fnd::WorldPosition playerWorldPos;
        csl::ut::Bitset<PlayerFlag> playerFlags;
        int flags2;
        int64_t unk11;

        void Setup(const char* cutsceneName);
        inline void SetCutsceneName(const char* name){
            strcpy(cutsceneName, name);
        }
        inline void SetSoundName(const char* name){
            strcpy(soundName, name);
        }
        void SetTransform(csl::math::Vector4* transform);
    };

    class EventScene : public hh::fnd::BaseObject, hh::dv::DvSceneControlListener {
    public:
        enum class Flags : int {
            UNK0 = 0x11,
            MOVIE_PLAYING = 0x12
        };

        EventPlayer* evtPlayer;
        hh::ut::TinyFsm<EventScene, hh::ut::TinyFsmEvent> fsm;
        hh::dv::DiEventManager* diEvtMgr;
        EventSetupData setupData;
        void* resourceCollection;
        long long unk0;
        bool unkBool1;
        long long unk2;
        void* levelLoader;
        hh::fnd::Handle<hh::fmv::MoviePlaybackObject> movieHandle;
        float unk5;
        csl::ut::Bitset<Flags> flags;

        EventScene(csl::fnd::IAllocator* allocator, const char* cutsceneName);

        EventSetupData& GetSetupData() const;
        void SetEventPlayer(EventPlayer* evtPlayer);
        void SetMovie(bool playing);
    };

    class EventSceneManager : public hh::fnd::BaseObject {
    public:
        EventPlayer* evtPlayer;
        csl::ut::MoveArray<EventScene*> evtScenes;
        csl::ut::MoveArray<csl::ut::VariableString> cutsceneNames;

        EventScene* GetEventScene(const char* cutsceneName);
        bool HasCutscene(const char* cutsceneName);
        void AddCutscene(const char* cutsceneName, bool addCutsceneName);
    };

    class EventEnvironmentContext;

    class EventEnvironment : public hh::fnd::BaseObject {
    public:
        EventEnvironmentContext* evtEnvCtx;

        virtual bool EE_UnkFunc1() {}
        virtual bool EE_UnkFunc2() {}
        virtual void EE_UnkFunc3() {}
        virtual void EE_UnkFunc4() {}
        virtual void EE_UnkFunc5() {}
        virtual void EE_UnkFunc6() {}
        virtual void EE_UnkFunc7() {}
        virtual void EE_UnkFunc8() {}
        virtual void EE_UnkFunc9() {}
        virtual void EE_UnkFunc10() {}
        virtual void EE_UnkFunc11() {}
        virtual void EE_UnkFunc12() {}
        virtual void EE_UnkFunc13() {}
        virtual int EE_UnkFunc14() {}
        virtual void EE_UnkFunc15() {}
        virtual void EE_UnkFunc16() {}
    };

    class EventEnvironmentContext : public hh::fnd::BaseObject {
    public:
        EventPlayer* evtPlayer;
        EventSetupData setupData[2];
        app_cmn::camera::CameraParameter camParam;
        bool isPlaying;
    };

    class EventEnvironmentManager : public hh::fnd::BaseObject {
    public:
        EventEnvironmentContext* evtEnvCtx;
        csl::ut::MoveArray<EventEnvironment*> evtEnvs;
    };

    class EventPlayer : public hh::game::GameService, hh::game::GameStepListener, hh::game::GameManagerListener, hh::dv::DvSceneControlListener {
    public:
        class MyDvSceneControlListener {
        public:
            char id;
            EventPlayer* eventPlayer;
            hh::dv::DvSceneControlListener* listener;

            virtual void* EventPlayerDtor();
            virtual void* GetEventPlayerRuntimeTypeInfo();
            virtual void* EventPlayerProcessMessage();
            virtual void KillDvSceneControl(int64_t a2);
            virtual void UnkFunc0() {};
            virtual void* EventPlayerIsAcceptingMessages();
            virtual void* EventPlayerOnAddedToGame();
            virtual void UnkFunc1() {};
            virtual void UnkFunc2() {};
            virtual void UnkFunc3() {};
            virtual void UnkFunc4() {};
            virtual void UnkFunc5() {};
            virtual void* EventPlayerUnk();
            virtual bool UnkFunc6() { return false; };
            virtual void UnkFunc7() {};
            virtual void UnkFunc8() {};
        };

        enum class Flag : unsigned long long {
            LOADING   =  29,
            PLAYING   =  30,
            UNLOADING =  31,
            UNK0      =  32,
        };

        hh::ut::TinyFsm<EventPlayer, hh::ut::TinyFsmEvent> fsm;
        hh::dv::DiEventManager* diEvtMgr;
        long long unk0;
        MyDvSceneControlListener dvSceneControlListeners[2];
        csl::ut::MoveArray<EventPlayerListener*> listeners;
        EventSceneManager* evtSceneMgr;
        EventEnvironmentManager* evtEnvMgr;
        hh::fnd::Handle<hh::game::GameObject> fadeObject;
        int unk2;
        hh::fnd::Handle<hh::game::GameObject> eventLayerChecker;
        bool unk4;
        int unk5; //handle prolly
        bool unk6;
        int unk7; // some flags?
        int unk8;
        csl::ut::Bitset<Flag> flags;

        void AddListener(EventPlayerListener* listener);
        void RemoveListener(EventPlayerListener* listener);
        void PlayEvent(EventSetupData& setupData);
        void SetMovie(const char* movieName, bool playing);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
        virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual bool DSCL_UnkFunc1(void* unk0, void* unk1) override;
        virtual bool DSCL_UnkFunc2(void* unk0, void* unk1) override;
        virtual bool DSCL_UnkFunc3() override;
        virtual void OnCutsceneEnd() override;
        virtual bool DSCL_UnkFunc13(void* unk0) override;
        virtual bool DSCL_UnkFunc14() override;

        GAMESERVICE_CLASS_DECLARATION(EventPlayer)
    };
}
