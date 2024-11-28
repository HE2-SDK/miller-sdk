#pragma once

#ifdef EXPORTING_TYPES
namespace csl::ut
{
	template <typename T, typename U = T>
	class Bitset
	{
	public:
		U bits;
	};
}
#else
#include <ucsl/bitset.h>

namespace csl::ut {
	using ucsl::bits::Bitset;
}
#endif
