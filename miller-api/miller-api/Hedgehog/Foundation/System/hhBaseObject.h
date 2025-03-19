#pragma once

#define DEFAULT_CREATE_FUNC(ClassName) public:\
		ClassName(csl::fnd::IAllocator* allocator);\
		static ClassName* Create(csl::fnd::IAllocator* allocator);

#define CREATE_FUNC(ClassName, ...) public:\
		ClassName(csl::fnd::IAllocator* allocator, __VA_ARGS__);\
		static ClassName* Create(csl::fnd::IAllocator* allocator, __VA_ARGS__);

namespace hh::fnd
{
	class alignas(8) BaseObject
	{
	protected:
		csl::fnd::IAllocator* pAllocator{};
	public:
		BaseObject(csl::fnd::IAllocator* pAllocator) : pAllocator{ pAllocator } {}
		virtual ~BaseObject() = default;

		csl::fnd::IAllocator* GetAllocator() const
		{
			return pAllocator;
		}

		static void* operator new(size_t count, void* ptr) {
			return ptr;
		}

		static void operator delete( void* ptr, void* place ) noexcept {
		}

		static void* operator new(size_t count, csl::fnd::IAllocator* pAllocator) {
			return pAllocator->Alloc(count, __STDCPP_DEFAULT_NEW_ALIGNMENT__);
		}

		static void operator delete(void* ptr, csl::fnd::IAllocator* pAllocator) noexcept {
			pAllocator->Free(ptr);
		}

		static void* operator new(size_t count, std::align_val_t al, csl::fnd::IAllocator* pAllocator) {
			return pAllocator->Alloc(count, static_cast<size_t>(al));
		}

		static void operator delete(void* ptr, std::align_val_t al, csl::fnd::IAllocator* pAllocator) noexcept {
			pAllocator->Free(ptr);
		}

		static void operator delete(void* ptr, size_t size) noexcept {
			static_cast<BaseObject*>(ptr)->pAllocator->Free(ptr);
		}
	};
}
