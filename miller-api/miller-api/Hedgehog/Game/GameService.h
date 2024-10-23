#pragma once

#define GAMESERVICE_CLASS_DECLARATION(ClassName) private:\
		static const hh::game::GameServiceClass gameServiceClass;\
		ClassName(csl::fnd::IAllocator* allocator);\
		static hh::game::GameService* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::game::GameServiceClass* GetClass();

namespace hh::game
{
	class GameManager;
	class GameService;

	class alignas(8) GameServiceClass
	{
	public:
		const char* pName;
		GameService* (*instantiator)(csl::fnd::IAllocator* pAllocator);
		void* pUnk2{};
	};
	
	class alignas(8) GameService : public hh::fnd::Messenger
	{
	public:
		GameManager* pGameManager;
		GameServiceClass* pStaticClass;
		uint32_t unk20;
		csl::fnd::Mutex mutex;

		GameService(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() {}
		virtual void OnRemovedFromGame() {}
	};
}
