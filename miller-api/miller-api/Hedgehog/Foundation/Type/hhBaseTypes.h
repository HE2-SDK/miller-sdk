#pragma once

namespace hh
{
	namespace fnd
	{
		class RflClass;

		struct Variant
		{
			void* m_pObject;
			const RflClass* m_pClass;
		};
	}
}
