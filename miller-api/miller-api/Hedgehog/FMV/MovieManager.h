#pragma once

namespace hh::fmv{
    class MovieHandleObj : public fnd::RefByHandleObject {
    public:
        typedef fnd::HandleManager<MovieHandleObj> HandleManager;

        MoviePlayerCri* moviePlayer;
    };

    class MovieManager : public game::GameService, game::GameStepListener {
    public:
        struct MovieSetupData {
        public:
            enum class Flags : char {
                UNK0,
                UNK1,
                UNK2,
                USE_RENDER_SETTINGS,
                UNK4,
                LOOP,
                USE_AUDIO,
                UNK7,
            };

            int unk0a[3];
            int unk0;
            int unk1[5];
            int pass;
            short priority;
            csl::ut::Bitset<Flags> flags;
            MovieRenderObject* movieRenderObj;
            int64_t unk3;
            float unk4;
        };

        csl::ut::MoveArray<void*> unkArray;
        csl::ut::MoveArray<fnd::Handle<MovieHandleObj>> movies;
        csl::ut::MoveArray<const char*> shaderNames;
        const char* shaderName;
        bool paused;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PreStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
		virtual void PostStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        fnd::Handle<MovieHandleObj> CreateMovie(const char* movieName, MovieSetupData* setupData, csl::fnd::IAllocator* allocator, char unk);

        GAMESERVICE_CLASS_DECLARATION(MovieManager)
    };
}
