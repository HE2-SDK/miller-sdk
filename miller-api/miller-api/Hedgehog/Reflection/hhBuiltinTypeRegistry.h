#pragma once

namespace hh::fnd
{
	class BuiltinTypeRegistry : public BaseObject
	{
	public:
		// TODO: these are actually not static.
		static RflClassNameRegistry* GetClassNameRegistry();
		static RflTypeInfoRegistry* GetTypeInfoRegistry();
	};
}