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
		
		csl::ut::Bitset<Flag> transformMatrix;
		csl::ut::Bitset<Flag> transformMaterialColor;
		csl::ut::Bitset<Flag> transformIlluminationColor;
		csl::ut::Bitset<Flag> transformDisplayFlag;
		csl::ut::Bitset<Flag> transformAny;
		csl::ut::Bitset<Flag> cellVertices;
		csl::ut::Bitset<Flag> cellVertexColor;
		csl::ut::Bitset<Flag> cellMaterialColor;
		csl::ut::Bitset<Flag> cellIlluminationColor;
		csl::ut::Bitset<Flag> cellCropUV;
		csl::ut::Bitset<Flag> cellUnk;
		csl::ut::Bitset<Flag> cellAny;
		csl::ut::Bitset<Flag> flags;

		inline void ClearCellAll() { flags.m_dummy &= ~cellAny.m_dummy; }
		inline void ClearCellCropUV() { flags.m_dummy &= ~cellCropUV.m_dummy; }
		inline void ClearCellIlluminationColor() { flags.m_dummy &= ~cellIlluminationColor.m_dummy; }
		inline void ClearCellMaterialColor() { flags.m_dummy &= ~cellMaterialColor.m_dummy; }
		inline void ClearCellVertexColor() { flags.m_dummy &= ~cellVertexColor.m_dummy; }
		inline void ClearCellVertices() { flags.m_dummy &= ~cellVertices.m_dummy; }
		inline void ClearTransformAll() { flags.m_dummy &= ~transformAny.m_dummy; }
		inline void ClearTransformIlluminationColor() { flags.m_dummy &= ~transformIlluminationColor.m_dummy; }
		inline void ClearTransformMaterialColor() { flags.m_dummy &= ~transformMaterialColor.m_dummy; }
		inline void ClearTransformMatrix() { flags.m_dummy &= ~transformMatrix.m_dummy; }
		inline bool IsCellAny() { return flags.m_dummy & cellAny.m_dummy; }
		inline bool IsCellCropUV() { return flags.m_dummy & cellCropUV.m_dummy; }
		inline bool IsCellIlluminationColor() { return flags.m_dummy & cellIlluminationColor.m_dummy; }
		inline bool IsCellMaterialColor() { return flags.m_dummy & cellMaterialColor.m_dummy; }
		inline bool IsCellVertexColor() { return flags.m_dummy & cellVertexColor.m_dummy; }
		inline bool IsCellVertices() { return flags.m_dummy & cellVertices.m_dummy; }
		inline bool IsTransformAny() { return flags.m_dummy & transformAny.m_dummy; }
		inline bool IsTransformDisplayFlag() { return flags.m_dummy & transformDisplayFlag.m_dummy; }
		inline bool IsTransformIlluminationColor() { return flags.m_dummy & transformIlluminationColor.m_dummy; }
		inline bool IsTransformMaterialColor() { return flags.m_dummy & transformMaterialColor.m_dummy; }
		inline bool IsTransformMatrix() { return flags.m_dummy & transformMatrix.m_dummy; }
		inline void SetCellAll() { flags.m_dummy |= cellAny.m_dummy; }
		inline void SetCellCropUV() { flags.m_dummy |= cellCropUV.m_dummy; }
		inline void SetCellIlluminationColor() { flags.m_dummy |= cellIlluminationColor.m_dummy; }
		inline void SetCellMaterialColor() { flags.m_dummy |= cellMaterialColor.m_dummy; }
		inline void SetCellVertexColor() { flags.m_dummy |= cellVertexColor.m_dummy; }
		inline void SetCellVertices() { flags.m_dummy |= cellVertices.m_dummy; }
		inline void SetTransformAll() { flags.m_dummy |= transformAny.m_dummy; }
		inline void SetTransformDisplayFlag() { flags.m_dummy |= transformDisplayFlag.m_dummy; }
		inline void SetTransformIlluminationColor() { flags.m_dummy |= transformIlluminationColor.m_dummy; }
		inline void SetTransformMaterialColor() { flags.m_dummy |= transformMaterialColor.m_dummy; }
		inline void SetTransformMatrix() { flags.m_dummy |= transformMatrix.m_dummy; }
    };

	class Layer;
	class Cast;
	class Transform {
	public:
		Vector3 position;
		Rotation3 rotation;
		Vector3 scale;
		Color materialColor;
		Color fullMaterialColor;
		Color illuminationColor;
		Color fullIlluminationColor;
		bool display;
		uint8_t unk9;
		DirtyFlag dirtyFlag;
		Layer* layer;
		Cast* cast;
		uint64_t unk17;
		Matrix34 transformationMatrix;
		
		Transform(Layer* layer);
		void Initialize2D(SRS_TRS2D* cell, Cast* cast);
		void Initialize3D(SRS_TRS3D* cell, Cast* cast);
	};
}
