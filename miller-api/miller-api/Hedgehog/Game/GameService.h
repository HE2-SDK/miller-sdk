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
		typedef GameService* CreateFunction(csl::fnd::IAllocator* allocator);

		const char* name;
		CreateFunction* instantiator;
		void* unk2{};

		GameServiceClass(const char* name, CreateFunction* instantiator, void* unk2) : name{ name }, instantiator{ instantiator }, unk2{ unk2 } {}
	};
	
	class alignas(8) GameService : public hh::fnd::Messenger
	{
	public:
		GameManager* gameManager;
		GameServiceClass* staticClass;
		uint32_t unk20;
		csl::fnd::Mutex mutex;

		GameService(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() {}
		virtual void OnRemovedFromGame() {}
	};
}
