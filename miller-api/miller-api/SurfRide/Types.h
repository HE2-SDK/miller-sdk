#pragma once
#include <ucsl/resources/swif/v6.h>

namespace SurfRide {
    struct SrTexCoord {
        float u;
        float v;

        SrTexCoord();
    };

	using EPivotType = ucsl::resources::swif::v6::EPivotType;
	using EOrientation = ucsl::resources::swif::v6::EOrientation;
	using ECurveType = ucsl::resources::swif::v6::ECurveType;
	using EInterpolationType = ucsl::resources::swif::v6::EInterpolationType;
	using ETrackDataType = ucsl::resources::swif::v6::ETrackDataType;
	using EEffectType = ucsl::resources::swif::v6::EEffectType;
	using EBlendMode = ucsl::resources::swif::v6::EBlendMode;
	using Vector2 = ucsl::resources::swif::v6::Vector2;
	using Vector3 = ucsl::resources::swif::v6::Vector3;
	using Matrix34 = ucsl::resources::swif::v6::Matrix34;
	using Matrix44 = ucsl::resources::swif::v6::Matrix44;
	using Rotation3 = ucsl::resources::swif::v6::Rotation3;
	using Color = ucsl::resources::swif::v6::Color;
	using Colorf = ucsl::resources::swif::v6::Colorf;
	using SRS_KEYFRAME = ucsl::resources::swif::v6::SRS_KEYFRAME;
	template<typename T> using Key = ucsl::resources::swif::v6::Key<T>;
	template<typename T> using KeyLinear = ucsl::resources::swif::v6::KeyLinear<T>;
	template<typename T> using KeyHermite = ucsl::resources::swif::v6::KeyHermite<T>;
	template<typename T> using KeyIndividual = ucsl::resources::swif::v6::KeyIndividual<T>;
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_TRACK, ucsl::resources::swif::v6::SRS_TRACK);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_MOTION, ucsl::resources::swif::v6::SRS_MOTION);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_ANIMATION, ucsl::resources::swif::v6::SRS_ANIMATION);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_CROP, ucsl::resources::swif::v6::SRS_CROP);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_CROPREF, ucsl::resources::swif::v6::SRS_CROPREF);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_DATA, ucsl::resources::swif::v6::SRS_DATA);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_USERDATA, ucsl::resources::swif::v6::SRS_USERDATA);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_TEXTURE, ucsl::resources::swif::v6::SRS_TEXTURE);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_TEXTURELIST, ucsl::resources::swif::v6::SRS_TEXTURELIST);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_CHARACTER_MAPPING, ucsl::resources::swif::v6::SRS_CHARACTER_MAPPING);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_FONT, ucsl::resources::swif::v6::SRS_FONT);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_TEXTDATA, ucsl::resources::swif::v6::SRS_TEXTDATA);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_EFFECT, ucsl::resources::swif::v6::SRS_EFFECT);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_BLUR, ucsl::resources::swif::v6::SRS_BLUR);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_BLUR3D, ucsl::resources::swif::v6::SRS_BLUR3D);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_REFLECT, ucsl::resources::swif::v6::SRS_REFLECT);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_REFLECT3D, ucsl::resources::swif::v6::SRS_REFLECT3D);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_TRS_BASE, ucsl::resources::swif::v6::SRS_TRS_BASE);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_TRS2D, ucsl::resources::swif::v6::SRS_TRS2D);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_TRS3D, ucsl::resources::swif::v6::SRS_TRS3D);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_IMAGECAST, ucsl::resources::swif::v6::SRS_IMAGECAST);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_SLICE, ucsl::resources::swif::v6::SRS_SLICE);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_SLICECAST, ucsl::resources::swif::v6::SRS_SLICECAST);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_LAYER, ucsl::resources::swif::v6::SRS_LAYER);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_REFERENCECAST, ucsl::resources::swif::v6::SRS_REFERENCECAST);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_CASTNODE, ucsl::resources::swif::v6::SRS_CASTNODE);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_CAMERA, ucsl::resources::swif::v6::SRS_CAMERA);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_SCENE, ucsl::resources::swif::v6::SRS_SCENE);
	UCSL_NEWTYPE_STRUCT_SIMPLE(SRS_PROJECT, ucsl::resources::swif::v6::SRS_PROJECT);

    struct SRS_CHUNK_HEADER {
        unsigned int magic;
        unsigned int chunkSize;
    };

    struct SRS_BINARY_FILE_HEADER_CHUNK_HEADER {
        unsigned int chunkCount;
        unsigned int chunksStart;
        unsigned int chunksSize;
        unsigned int addressResolutionHeaderOffset;
        unsigned int revision;
    };

    struct SRS_TEXTURELIST_CHUNK_HEADER {
        unsigned int startOffset;
        unsigned int textureListCount;
    };

    struct SRS_PROJECT_CHUNK_HEADER {
        unsigned int startOffset;
    };

    struct SRS_ADDRESS_RESOLUTION_CHUNK_HEADER {
        unsigned int addressToResolveCount;
        unsigned int isResolved; // 0 if not, 1 if yes
    };
}
