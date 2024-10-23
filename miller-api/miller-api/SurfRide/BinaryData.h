#pragma once

namespace SurfRide
{
	struct SRS_PROJECT;
	struct SRS_SCENE;
	struct SRS_LAYER;
	struct SRS_CASTNODE;

	struct SRS_CHUNK_HEADER {
		uint32_t magic;
		uint32_t chunkSize;
	};

	struct SRS_ADDRESS_RESOLUTION_CHUNK_HEADER {
		uint32_t addressToResolveCount;
		uint32_t isResolved; // 0 if not, 1 if yes
	};

	struct SRS_ADDRESS_RESOLUTION_CHUNK {
		SRS_CHUNK_HEADER chunkHeader;
		SRS_ADDRESS_RESOLUTION_CHUNK_HEADER header;
	};

	struct SRS_PROJECT_CHUNK_HEADER {
		uint32_t startOffset;
	};

	struct SRS_PROJECT_CHUNK {
		SRS_CHUNK_HEADER chunkHeader;
		SRS_PROJECT_CHUNK_HEADER header;
	};

	struct SRS_TEXTURELIST_CHUNK_HEADER {
		uint32_t startOffset;
		uint32_t textureListCount;
	};

	struct SRS_TEXTURELIST_CHUNK {
		SRS_CHUNK_HEADER chunkHeader;
		SRS_TEXTURELIST_CHUNK_HEADER header;
	};

	struct SRS_BINARY_FILE_HEADER_CHUNK_HEADER {
		uint32_t chunkCount;
		uint32_t chunksStart;
		uint32_t chunksSize;
		uint32_t addressResolutionHeaderOffset;
		uint32_t revision;
	};

	struct SRS_END_CHUNK_HEADER {};

	struct SRS_BINARY_FILE_HEADER_CHUNK {
		SRS_CHUNK_HEADER chunkHeader;
		SRS_BINARY_FILE_HEADER_CHUNK_HEADER header;

		struct ChunkInfo {
			SRS_PROJECT_CHUNK* projectChunk;
			SRS_TEXTURELIST_CHUNK* textureListChunk;

			unsigned int GetTextureListCount() const;
			TextureListIterator GetTextureListIteratorBegin() const;
			TextureListIterator GetTextureList(unsigned int) const;
			ProjectIterator GetProject() const;
		};

		static ChunkInfo GetChunkInfo(void* data);
	};

	class BinaryData : public ReferencedObject {
		void* data{};
	public:
		BinaryData(void* data);
		void ResolveAddress();
		static void ResolveAddress(void* data);
		Project* ApplyMemoryImageToProject(bool unkParam);
		SRS_BINARY_FILE_HEADER_CHUNK* GetBinaryFileHeader();
		void ResetAddress(void* start, void* end, unsigned int size);
	};

	Project* ApplyMemoryImageToProject(void* image, bool unkParam);
}
