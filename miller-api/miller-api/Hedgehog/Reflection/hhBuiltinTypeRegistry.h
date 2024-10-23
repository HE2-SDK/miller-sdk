#pragma once

namespace hh::fnd
{
	class BuiltinTypeRegistry : public BaseObject
	{
	public:
		static RflClassNameRegistry* GetClassNameRegistry();
		static RflTypeInfoRegistry* GetTypeInfoRegistry();
	};
}