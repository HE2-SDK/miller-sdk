#pragma once

namespace SurfRide
{
	struct SRS_CAMERA
	{
		const char* name{};
		int id{};
		csl::math::Vector3 position{};
		csl::math::Vector3 target{};
		bool isOrthogonal{};
		int fov;
		float nearPlane{};
		float farPlane{};
		float unk1{};
		uint64_t unk2{};
	};

    struct SrCamera {
		SRS_CAMERA cameraData;

		SrCamera(const SRS_CAMERA& cameraData);
    };

    struct SrScreenResolution {
        unsigned int width;
        unsigned int height;
    };

	class Camera
	{
	public:
		SrCamera camera;
		csl::math::Matrix34 viewMatrix;

		Camera(const SrCamera& camera);
		void SetCamera(const SrCamera& camera);

		inline SRS_CAMERA& GetCameraData() { return camera.cameraData; }
	};

	SrScreenResolution GetScreenResolution();
}
