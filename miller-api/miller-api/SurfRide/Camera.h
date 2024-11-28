#pragma once

namespace SurfRide
{
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
