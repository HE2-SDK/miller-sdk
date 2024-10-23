#pragma once

namespace SurfRide {
	struct SRS_TRS_BASE
	{
		Color materialColor{};
		Color illuminationColor{};
		bool display{};
	};

	struct SRS_TRS2D : public SRS_TRS_BASE
	{
		Vector2 position{};
		int rotation{};
		Vector2 scale{ 1.0f, 1.0f };
		uint32_t unkX;
		uint32_t unkY;
	};

	struct SRS_TRS3D : public SRS_TRS_BASE
	{
		Vector3 position{};
		Rotation3 rotation{};
		Vector3 scale{ 1.0f, 1.0f, 1.0f };
	};

    struct DirtyFlag {
		enum Flag : uint32_t {
			TRANSFORM_MATRIX = 0,
			TRANSFORM_MATERIAL_COLOR = 1,
			TRANSFORM_ILLUMINATION_COLOR = 2,
			TRANSFORM_DISPLAY_FLAG = 3,
			CELL_VERTICES = 8,
			CELL_VERTEX_COLOR = 9,
			CELL_MATERIAL_COLOR = 10,
			CELL_ILLUMINATION_COLOR = 11,
			CELL_CROP_UV = 12,

			// Think this is no longer in Frontiers version of SurfRide.
			// TRANSFORM_MULTIRESOLUTION_POSITION = 0x10,
			// TRANSFORM_MULTIRESOLUTION_SIZE = 0x20,
			// TRANSFORM_ANY = 0x3F,
			// ANY = 0x3F3F,
		};
		
		// csl::ut::Bitset<Flag> transformMatrix;
		// csl::ut::Bitset<Flag> transformMaterialColor;
		// csl::ut::Bitset<Flag> transformIlluminationColor;
		// csl::ut::Bitset<Flag> transformDisplayFlag;
		// csl::ut::Bitset<Flag> transformAny;
		// csl::ut::Bitset<Flag> cellVertices;
		// csl::ut::Bitset<Flag> cellVertexColor;
		// csl::ut::Bitset<Flag> cellMaterialColor;
		// csl::ut::Bitset<Flag> cellIlluminationColor;
		// csl::ut::Bitset<Flag> cellCropUV;
		// csl::ut::Bitset<Flag> cellUnk;
		// csl::ut::Bitset<Flag> cellAny;
		csl::ut::Bitset<Flag> flags;

		void ClearCellAll();
		void ClearTransformIlluminationColor();
		void ClearTransformMaterialColor();
		void ClearTransformMatrix();
		void ClearTransformMultiResolutionPosition();
		void ClearTransformMultiResolutionSize();
		bool IsCellAny();
		bool IsCellCropUV();
		bool IsCellIlluminationColor();
		bool IsCellMaterialColor();
		bool IsCellVertexColor();
		bool IsCellVertices();
		bool IsTransformIlluminationColor();
		bool IsTransformMaterialColor();
		bool IsTransformMatrix();
		bool IsTransformMultiResolutionPosition();
		bool IsTransformMultiResolutionSize();
		void SetAll();
		void SetCellCropUV();
		void SetCellIlluminationColor();
		void SetCellMaterialColor();
		void SetCellVertexColor();
		void SetCellVertices();
		void SetTransformDisplayFlag();
		void SetTransformIlluminationColor();
		void SetTransformMaterialColor();
		void SetTransformMatrix();
		void SetTransformMultiResolutionPosition();
		void SetTransformMultiResolutionSize();

		inline void SetCellAll() { SetAll(); }
		inline void SetTransformAll() { SetAll(); }
    };

	class Layer;
	class Cast;
	class Transform : public Base {
	public:
		SRS_TRS3D* transformData;
		Color materialColor;
		Color fullMaterialColor;
		Color illuminationColor;
		bool display;
		DirtyFlag dirtyFlag;
		Cast* cast;
		
		Transform();
		void Initialize2D(SRS_TRS2D* cell, Cast* cast);
		void Initialize3D(SRS_TRS3D* cell, Cast* cast);
	};

	class Transform3D : public Transform {
	public:
		Matrix34 transformationMatrix;
		Transform3D();
	};
}
