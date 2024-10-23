#pragma once

namespace csl::fnd
{	
	template<typename T>
	class Singleton
	{
	public:
		static T* instance;

		inline static T* GetInstance()
		{
			return RESOLVE_STATIC_VARIABLE(instance);
		}
	};
}
