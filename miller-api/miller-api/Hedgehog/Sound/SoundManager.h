#pragma once

namespace hh::snd {
    class GOCSound;
    class SoundManager;
    class SoundManagerListener {
    public:
        virtual ~SoundManagerListener() = default;
        virtual void SML_UnkFunc1() {}
        virtual void GOCSoundAddedCallback(SoundManager* soundManager, GOCSound* gocSound) {}
        virtual void GOCSoundRemovedCallback(SoundManager* soundManager, GOCSound* gocSound) {}
        virtual void SML_UnkFunc4() {}
        virtual void SML_UnkFunc5() {}
        virtual void SoundsChangedCallback(SoundManager* soundManager) {}
    };

    class SoundManager : public game::GameService, game::GameStepListener {
    public:
        csl::ut::MoveArray<void*> unk201;
        csl::ut::MoveArray<void*> unk202;
        csl::ut::MoveArray<GOCSound*> gocSounds;
        csl::ut::MoveArray<SoundHandle> sounds;
        csl::ut::InplaceMoveArray<SoundManagerListener*, 1> listeners;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        void AddGOCSound(GOCSound* gocSound);
        void RemoveGOCSound(GOCSound* gocSound);
        void AddListener(SoundManagerListener* listener);
        void RemoveListener(SoundManagerListener* listener);

        SoundHandle Play(unsigned int category, const char* name, const SoundParam& soundParam);
        SoundHandle Play3D(unsigned int category, const char* name, const csl::math::Vector3& position, const SoundParam& soundParam);

        GAMESERVICE_CLASS_DECLARATION(SoundManager);
    };
}
