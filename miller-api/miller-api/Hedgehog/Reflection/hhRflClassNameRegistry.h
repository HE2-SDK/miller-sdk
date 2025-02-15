#pragma once

namespace hh::fnd
{
	class RflClassNameRegistry : public BaseObject, public csl::fnd::Singleton<RflClassNameRegistry>
	{
		static RflClass* staticRflClasses[2081];
	public:
		csl::ut::StringMap<const RflClass*> items{ GetAllocator() };

		RflClassNameRegistry(csl::fnd::IAllocator* pAllocator) : BaseObject{ pAllocator }
		{
		}

		const RflClass* GetClassByName(const char* pName) const
		{
			return items.GetValueOrFallback(pName, nullptr);
		}
		
		void Register(const RflClass* pInfo)
		{
			items.Insert(pInfo->GetName(), pInfo);
		}

		void RegisterList(const RflClass** pInfoList)
		{
			size_t i = 0;
			while (pInfoList[i])
			{
				Register(pInfoList[i]);
				i++;
			}
		}

		const csl::ut::StringMap<const RflClass*>& GetItems() const {
			return items;
		}
	};
}
