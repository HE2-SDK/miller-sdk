#pragma once

namespace SurfRide {
	struct SRS_CELLTEXTURE {
		short textureListIndex;
		short textureIndex;
		SrTexCoord texCoords[4];

		SRS_CELLTEXTURE();
	};

	// FIXME: THESE ARE CURRENTLY INCORRECT!
	struct SRS_CELL2D : Base {
		SRS_CELL2D();
	};

	struct SRS_CELL3D {
		uint32_t flags;
		uint32_t qword4;
		uint32_t qword8;
		uint32_t qwordC;
		uint32_t qword10;
		SRS_CELLTEXTURE textures[2];
		uint32_t qword3C;
		Matrix34 transform;
		uint32_t qword78a;

		SRS_CELL3D();

		void SetVertexColor(unsigned int idx, const Color& color);
		void SetIlluminationColor(const Color& color);
	};

    struct CellList {
        uint32_t count;
        SRS_CELL3D cells[1];
    };

    void SR_MakeCellUv(const SRS_CROPREF* cropRef, unsigned int cropIndex, unsigned int imageCastFlags, unsigned int currentCropIndex, const SRS_TEXTURELIST* textureList, ECropSurface cropSurface, SRS_CELL3D* cell);
    void SR_MakeCellUv2(const SRS_CROPREF* cropRef, unsigned int cropIndex, unsigned int imageCastFlags, const SrTexCoord& cropRectMin, const SrTexCoord& cropRectMax, unsigned int currentCropIndex, ECropSurface cropSurface, SRS_CELL3D* cell);

	template<typename T>
	void SR_MakeCellUv_Sub(float left, float top, float right, float bottom, unsigned int imageCastFlags, ECropSurface cropSurface, T* cell);
	void SR_MakeCellUv_Sub(float left, float top, float right, float bottom, unsigned int imageCastFlags, ECropSurface cropSurface, SRS_CELL3D* cell);
}
