#pragma once

namespace SurfRide
{
    struct SrScreenResolution {
        unsigned int width;
        unsigned int height;
    };

	class Camera : public Base
	{
	public:
		SRS_CAMERA camera;
		csl::math::Matrix44 viewMatrix;
		csl::math::Matrix44 projectionMatrix;

		Camera(csl::fnd::IAllocator* allocator, const SRS_CAMERA& camera, float resolutionX, float resolutionY);

		inline SRS_CAMERA& GetCameraData() { return camera; }
	};

	SrScreenResolution GetScreenResolution();
}
