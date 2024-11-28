#pragma once

namespace SurfRide
{
	class BinaryData : public ReferencedObject {
		void* data{};
	public:
		BinaryData(void* data);
		void ResolveAddress();
		static void ResolveAddress(void* data);
		Project* ApplyMemoryImageToProject(bool unkParam);
		SRS_CHUNK_HEADER* GetBinaryFileHeader();
		void ResetAddress(void* start, void* end, unsigned int size);
	};

	Project* ApplyMemoryImageToProject(void* image, bool unkParam);
}
