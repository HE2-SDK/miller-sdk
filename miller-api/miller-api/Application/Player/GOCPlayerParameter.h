#pragma once

namespace app::player {
    class GOCPlayerParameter : public hh::game::GOComponent {
    public:
        enum class Mode : uint32_t {
            FORWARD_VIEW,
            SIDE_VIEW,
            BOSS,
            WHITE_SPACE,
        };

        hh::fnd::Reference<hh::fnd::ResReflectionT<PlayerParameters>> playerParameters;
        hh::fnd::Reference<hh::fnd::ResReflectionT<PlayerCameraSetParameters>> cameraSetParameters;
        ModePackage* modePackages[4];
        Mode mode;
        uint32_t unk1; // initialized in ctor but never used. used to contain super state in frontiers
        PlayerParamCommon* commonParameters[4];
        PlayerParamSpeed* speedParameters[4];
        PlayerParamJump* jumpParameters[4];
        PlayerParamJumpSpeed* jumpSpeedParameters[4];
        PlayerParamDoubleJump* doubleJumpParameters[4];
        PlayerParamBoost* boostParameters[4];
        PlayerParamAirBoost* airBoostParameters[4];

    private:
        void* GetPlayerParameter(const hh::fnd::RflClass& rflClass);
    public:
        struct SetupInfo {
            Mode mode;
            hh::fnd::Reference<hh::fnd::ResReflectionT<PlayerParameters>> playerParameters;
            hh::fnd::Reference<hh::fnd::ResReflectionT<PlayerCameraSetParameters>> cameraSetParameters;
        };

        GOCPlayerParameter(csl::fnd::IAllocator* allocator);
        void Setup(const SetupInfo& setup);

        PlayerParamCommon& GetCommonParameters() const;
        PlayerParamSpeed& GetSpeedParameters() const;
        PlayerParamJump& GetJumpParameters() const;
        PlayerParamJumpSpeed& GetJumpSpeedParameters() const;
        PlayerParamDoubleJump& GetDoubleJumpParameters() const;
        PlayerParamBoost& GetBoostParameters() const;
        PlayerParamAirBoost& GetAirBoostParameters() const;

        void SetMode(Mode mode);

        template<typename T>
        T* GetPlayerParameter() {
            return reinterpret_cast<T*>(GetPlayerParameter(RESOLVE_STATIC_VARIABLE(T::rflClass)));
        }

        // template<typename T>
        // T* GetPlayerParameter(const hh::fnd::RflClass& rflClass) {
        //     return reinterpret_cast<T*>(GetPlayerParameter(rflClass));
        // }

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(hh::game::GOComponent::GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerParameter);
    };
}
