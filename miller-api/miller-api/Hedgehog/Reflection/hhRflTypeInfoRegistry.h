#pragma once

namespace hh::fnd
{
	class RflTypeInfoRegistry : public BaseObject, public csl::fnd::Singleton<RflTypeInfoRegistry>
	{
		static RflTypeInfo* staticRflTypeInfos[2081];
	public:
		csl::ut::StringMap<const RflTypeInfo*> items{ GetAllocator() };

		RflTypeInfoRegistry(csl::fnd::IAllocator* pAllocator) : BaseObject{ pAllocator }
		{
		}

		const RflTypeInfo* GetByName(const char* pName) const
		{
			return items.GetValueOrFallback(pName, nullptr);
		}
		
		void Register(const RflTypeInfo* pInfo)
		{
			items.Insert(pInfo->GetName(), pInfo);
		}

		void RegisterList(const RflTypeInfo** pInfoList)
		{
			size_t i = 0;
			while (pInfoList[i])
			{
				Register(pInfoList[i]);
				i++;
			}
		}

		const csl::ut::StringMap<const RflTypeInfo*>& GetItems() const {
			return items;
		}

		void* ConstructObject(csl::fnd::IAllocator* pAllocator, const char* pName) const;

		void ConstructObject(csl::fnd::IAllocator* pAllocator, void* placement, const char* pName) const
		{
			auto* pTypeInfo = GetByName(pName);
			if (!pTypeInfo)
				return;

			pTypeInfo->ConstructObject(placement, pAllocator);
		}

		void FinishLoadedObject(void* pInstance, const char* pName) const
		{
			auto* pTypeInfo = GetByName(pName);
			if (!pTypeInfo)
				return;

			pTypeInfo->FinishLoadedObject(pInstance);
		}

		void CleanupLoadedObject(void* pInstance, const char* pName) const;
	};
}
