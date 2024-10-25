#pragma once

namespace app::gfx {
    class FxColManager
        : public hh::game::GameService
		, public SceneParameters::Listener
		, public hh::game::GameManagerListener
		, public hh::game::GameStepListener
		, public hh::dv::DvSceneControlListener {
    public:
		class ReloaderListener : public hh::fnd::ReferencedObject, public hh::fnd::ReloaderListener {
		public:
        	virtual void PostResourceReloadCallback(hh::fnd::ManagedResource* resource) override;
		};

		enum class Flag : uint32_t {
			INITIALIZED,
			DISABLE,
			DISABLE_LIGHT_PARAMETERS, // or USE_ATMOSPHERIC_LIGHTING ? not sure, but it's related to usingCameraBasedShadowmapParameter, see PostStepCallback
			USE_DVSCENE_CAMERA_POSITION,
			USE_DVSCENE_STRIPPED_PROBABLE_DEBUG_CAMERA_POSITION,
		};

		app::level::LevelInfo* levelInfo;
		app::gfx::FxParamManager* fxParamManager;
		hh::eff::EffectManager* effectManager;
		app::camera::CameraService* cameraService;
		app::game::TimeService* timeService;
		hh::dv::DiEventManager* diEventManager;
		hh::dv::DiEventPreviewManager* diEventPreviewManager;
		csl::ut::VariableString stageName;
		hh::fnd::Reference<app::gfx::ResFxColFile2> resource;
		csl::ut::String terrainPackfileName;
		hh::fnd::Reference<hh::ut::KdTree> collisionTree;
		hh::ut::ResKdTreeData* collisionTreeResource;
		csl::ut::InplaceMoveArray<unsigned int, 16> activeCollisionShapes;
		csl::ut::InplaceMoveArray<unsigned int, 16> shapesToActivate;
		csl::ut::InplaceMoveArray<unsigned int, 16> shapesToDeactivate;
		csl::ut::Bitset<Flag> flags;
		hh::fnd::ResLightParameter sunlightParameter;
		hh::fnd::ResLightParameter shadowlightParameter;
		csl::math::Vector3 previousPosition;
		csl::math::Vector3 dvSceneCameraPosition;
		csl::math::Vector3 dvSceneStrippedProbablyDebugCameraPosition;
		csl::math::Vector4 shadowLightUnk105;
		uint32_t currentSceneParamIndex;
		uint32_t currentIBLIndex;
		bool usingCameraBasedShadowmapParameter;
		uint64_t unk130;

	protected:
		void LoadFxColResource(ResFxColFile2* resource);
		void LoadLightParameter(unsigned int index, hh::fnd::ResLightParameter* sunlightParameter, hh::fnd::ResLightParameter shadowLightParameter);
		void SetDefaultSceneParam(bool interpolatorJobExists);
		void Update(const csl::math::Vector3 position);
		void QueryCollisionShapes(const csl::geom::Aabb queryAabb, bool filter, csl::ut::MoveArray<unsigned int>& results);
		void CollectCollisionShapesToActivateAndDeactivate(const csl::ut::MoveArray<unsigned int>& newActiveShapes);
		void HandleSceneParamCollisionShapes();
		void HandleLightParamCollisionShapesLight();
		void HandleLightParamCollisionShapesIBL();

		static float InterpolateCollisionShape(FxColCollisionShape* shape, const csl::math::Vector3& position);
		static float InterpolateSphere(const csl::math::Vector3& cameraPosition, const csl::math::Vector3& position, float radius, float borderThickness);
		static float InterpolateCylinder(const csl::math::Vector3& cameraPosition, const csl::math::Vector3& position, const csl::math::Quaternion, float halfHeight, float radius, float borderThickness);
		static float InterpolateAnisotropicObb(const csl::math::Vector3& cameraPosition, const csl::math::Vector3& position, const csl::math::Quaternion, float halfWidth, float halfHeight, float halfDepth, float positiveDepthBorderThickness, float negativeDepthBorderThickness);
		static float InterpolateIsotropicObb(const csl::math::Vector3& cameraPosition, const csl::math::Vector3& position, const csl::math::Quaternion, float halfWidth, float halfHeight, float halfDepth, float borderThickness);

	public:
		virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void SPL_UnkFunc1() override;
		virtual void SPL_UnkFunc3() override;
		virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
		virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void DSCL_UnkFunc7() override;
        virtual void DSCL_UnkFunc9() override;

		void StartLevel(const char* stageName);
		void EndLevel();
		hh::ut::KdTree* CreateKdTree(ResFxColFile2* resource);

		GAMESERVICE_CLASS_DECLARATION(FxColManager)
    };
}
