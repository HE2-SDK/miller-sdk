#pragma once

namespace SurfRide {
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

		inline void ClearCellAll() { flags.bits &= ~cellAny.bits; }
		inline void ClearCellCropUV() { flags.bits &= ~cellCropUV.bits; }
		inline void ClearCellIlluminationColor() { flags.bits &= ~cellIlluminationColor.bits; }
		inline void ClearCellMaterialColor() { flags.bits &= ~cellMaterialColor.bits; }
		inline void ClearCellVertexColor() { flags.bits &= ~cellVertexColor.bits; }
		inline void ClearCellVertices() { flags.bits &= ~cellVertices.bits; }
		inline void ClearTransformAll() { flags.bits &= ~transformAny.bits; }
		inline void ClearTransformIlluminationColor() { flags.bits &= ~transformIlluminationColor.bits; }
		inline void ClearTransformMaterialColor() { flags.bits &= ~transformMaterialColor.bits; }
		inline void ClearTransformMatrix() { flags.bits &= ~transformMatrix.bits; }
		inline bool IsCellAny() { return flags.bits & cellAny.bits; }
		inline bool IsCellCropUV() { return flags.bits & cellCropUV.bits; }
		inline bool IsCellIlluminationColor() { return flags.bits & cellIlluminationColor.bits; }
		inline bool IsCellMaterialColor() { return flags.bits & cellMaterialColor.bits; }
		inline bool IsCellVertexColor() { return flags.bits & cellVertexColor.bits; }
		inline bool IsCellVertices() { return flags.bits & cellVertices.bits; }
		inline bool IsTransformAny() { return flags.bits & transformAny.bits; }
		inline bool IsTransformDisplayFlag() { return flags.bits & transformDisplayFlag.bits; }
		inline bool IsTransformIlluminationColor() { return flags.bits & transformIlluminationColor.bits; }
		inline bool IsTransformMaterialColor() { return flags.bits & transformMaterialColor.bits; }
		inline bool IsTransformMatrix() { return flags.bits & transformMatrix.bits; }
		inline void SetCellAll() { flags.bits |= cellAny.bits; }
		inline void SetCellCropUV() { flags.bits |= cellCropUV.bits; }
		inline void SetCellIlluminationColor() { flags.bits |= cellIlluminationColor.bits; }
		inline void SetCellMaterialColor() { flags.bits |= cellMaterialColor.bits; }
		inline void SetCellVertexColor() { flags.bits |= cellVertexColor.bits; }
		inline void SetCellVertices() { flags.bits |= cellVertices.bits; }
		inline void SetTransformAll() { flags.bits |= transformAny.bits; }
		inline void SetTransformDisplayFlag() { flags.bits |= transformDisplayFlag.bits; }
		inline void SetTransformIlluminationColor() { flags.bits |= transformIlluminationColor.bits; }
		inline void SetTransformMaterialColor() { flags.bits |= transformMaterialColor.bits; }
		inline void SetTransformMatrix() { flags.bits |= transformMatrix.bits; }
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
