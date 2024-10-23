#pragma once

namespace SurfRide
{
	enum class SRE_CURVE_TYPE : uint16_t
	{
		TranslationX,
		TranslationY,
		TranslationZ,
		RotationX,
		RotationY,
		RotationZ,
		ScaleX,
		ScaleY,
		ScaleZ,
		MaterialColor,
		Display,
		Width,
		Height,
		VertexColorTopLeft,
		VertexColorTopRight,
		VertexColorBottomLeft,
		VertexColorBottomRight,
		CropIndex0,
		CropIndex1,
		Unknown,
		IlluminationColor,
		MaterialColorR,
		MaterialColorG,
		MaterialColorB,
		MaterialColorA,
		VertexColorTopLeftR,
		VertexColorTopLeftG,
		VertexColorTopLeftB,
		VertexColorTopLeftA,
		VertexColorTopRightR,
		VertexColorTopRightG,
		VertexColorTopRightB,
		VertexColorTopRightA,
		VertexColorBottomLeftR,
		VertexColorBottomLeftG,
		VertexColorBottomLeftB,
		VertexColorBottomLeftA,
		VertexColorBottomRightR,
		VertexColorBottomRightG,
		VertexColorBottomRightB,
		VertexColorBottomRightA,
		IlluminationColorR,
		IlluminationColorG,
		IlluminationColorB,
		IlluminationColorA,
	};

	enum class SRE_TRACK_INTERPOLATION_TYPE : uint16_t {
		CONSTANT,
		LINEAR,
		HERMITE,
		INDIVIDUAL,
	};

	enum class SRE_TRACK_DATA_TYPE : uint16_t {
		UNKNOWN,
		FLOAT,
		INDEX,
		BOOL,
		INT,
		COLOR,

		// These are uncertain
		UNK_FLOAT,
		UNK_DOUBLE, // Types say double, but used for what? Won't interpolate linearly.
		UNK_CHAR, // Char? doubt
	};

	enum class SRE_INTERPOLATION_TYPE : uint32_t {
		CONSTANT,
		LINEAR,
		HERMITE,
	};

	struct SRS_KEYFRAME
	{
		uint32_t frame{};
	};

	template<typename T>
	struct Key : public SRS_KEYFRAME {
		T value;
	};

    template<typename T>
    struct KeyLinear : public Key<T> {
    };

    template<typename T>
    struct KeyHermite : public Key<T> {
		T derivativeIn;
		T derivativeOut;
    };

    template<typename T>
    struct KeyIndividual : public Key<T> {
		T derivativeIn;
		T derivativeOut;
		SRE_INTERPOLATION_TYPE interpolationType;
    };

	struct SRS_TRACK
	{
		SRE_CURVE_TYPE trackType{};
		uint16_t keyCount{};
		uint16_t flags{};
		uint32_t firstFrame{};
		uint32_t lastFrame{};
		SRS_KEYFRAME* keyFrame{};

		inline SRE_TRACK_INTERPOLATION_TYPE GetInterpolationType() const {
			return static_cast<SRE_TRACK_INTERPOLATION_TYPE>(flags & 0x3);
		}

		inline SRE_TRACK_DATA_TYPE GetDataType() const {
			return static_cast<SRE_TRACK_DATA_TYPE>((flags >> 4) & 0xF);
		}
	};

	struct SRS_MOTION
	{
		uint16_t castId{};
		uint16_t trackCount{};
		SRS_TRACK* tracks{};
	};

	struct SRS_ANIMATION
	{
		const char* name{};
		uint32_t id{};
		uint32_t motionCount{};
		uint32_t frameCount{};
		SRS_MOTION* motions{};
		void* userData{};
		bool isLooping{};
	};
}