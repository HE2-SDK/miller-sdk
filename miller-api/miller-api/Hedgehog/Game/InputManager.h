#pragma once

namespace hh::game {
    class InputComponent;
    class InternalPlayerInput : public fnd::ReferencedObject {
        uint32_t index;
        int32_t unk1;
        csl::ut::MoveArray<hid::InputMap*> inputMaps; // same length as InputManager's unk1
        csl::ut::MoveArray<InputComponent*> inputComponents;
        uint32_t maxMappingUnk1PlusOneOverAllInputMaps;
    public:
        void CreateInputMap(uint32_t index, hid::InputMapSettings* settings);
    };

    class InputManager : public GameService, public GamePauseListener, public GameStepListener {
        csl::ut::MoveArray<hid::InputMapSettings*> inputMapSettings;
        csl::ut::MoveArray<InputComponent*> inputComponents;
        csl::ut::MoveArray<InternalPlayerInput*> internalPlayerInputs;
        csl::ut::InplaceMoveArray<void*, 1> unk4; // Something being done with this in RegisterInputComponent
        char activeInternalPlayerInputs; // bitmask
        int32_t unk6;
    public:
        struct SetupInfo {
            uint32_t internalPlayerInputCount;
            uint32_t inputMapSettingsCount;
            hid::InputMapSettings* settings;
        };
        void Setup(const SetupInfo& setupInfo);

        void RegisterInputComponent(InputComponent& inputComponent);
        void UnregisterInputComponent(InputComponent& inputComponent);
        void CreateInputMaps(hid::InputMapSettings* settings);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void GPL_UnkFunc2() override;
        virtual void PreStepCallback(GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(InputManager)
    };
}
