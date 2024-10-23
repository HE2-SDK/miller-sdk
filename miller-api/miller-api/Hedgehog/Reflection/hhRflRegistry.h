#pragma once

namespace hh::fnd
{
	template<typename T>
	class RflRegistryTemplate : public BaseObject {
	public:
		csl::ut::StringMap<const T*> items{ GetAllocator() };

		RflRegistryTemplate(csl::fnd::IAllocator* pAllocator) : BaseObject{ pAllocator }
		{
		}

		const T* GetByName(const char* pName) const
		{
			return items.GetValueOrFallback(pName, nullptr);
		}
		
		void Register(const T* pInfo)
		{
			items.Insert(pInfo->GetName(), pInfo);
		}

		void RegisterList(const T** pInfoList)
		{
			size_t i = 0;
			while (pInfoList[i])
			{
				Register(pInfoList[i]);
				i++;
			}
		}

		const csl::ut::StringMap<const T*>& GetItems() const {
			return items;
		}
	};
}
