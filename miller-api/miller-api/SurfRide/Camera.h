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

	class Camera
	{
	public:
		SRS_CAMERA camera;
		csl::math::Matrix44 viewMatrix;
		csl::math::Matrix44 projectionMatrix;

		Camera(const SRS_CAMERA& camera, float resolutionX, float resolutionY);

		inline SRS_CAMERA& GetCameraData() { return camera; }
	};
}
