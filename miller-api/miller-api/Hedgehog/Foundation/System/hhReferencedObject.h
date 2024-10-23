#pragma once

namespace hh::fnd
{
	template<typename T>
	class Reference {
		T* ptr{ nullptr };
	public:
		Reference() {
		}

		Reference(const Reference& other) {
			*this = other;
		}

		Reference(Reference&& other) {
			ptr = other.ptr;
			other.ptr = nullptr;
		}

		Reference(T* rawPtr) {
			if (rawPtr != nullptr)
				rawPtr->Acquire();

			ptr = rawPtr;
		}

		~Reference() {
			if (ptr != nullptr)
				ptr->Free();

			ptr = nullptr;
		}

		inline Reference<T>& operator=(T* const other) {
			T* old = ptr;

			if (other != nullptr)
				other->Acquire();

			ptr = other;

			if (old != nullptr)
				old->Free();

			return *this;
		}

		inline Reference<T>& operator=(const Reference<T>& other) {
			*this = other.ptr;
			return *this;
		}

		inline Reference<T>& operator=(Reference<T>&& other) {
			T* old = ptr;

			ptr = other.ptr;
			other.ptr = nullptr;

			if (old != nullptr)
				old->Free();

			return *this;
		}

		inline T& operator*() const {
			return *ptr;
		}

		inline T* operator->() const {
			return ptr;
		}

		inline operator T&() const {
			return *ptr;
		}

		inline operator T*() const {
			return ptr;
		}

		inline bool operator==(const Reference<T>& other) const {
			return ptr == other.ptr;
		}

		inline bool operator==(T* const other) const {
			return ptr == other;
		}
	};

	class alignas(8) ReferencedObject : public BaseObject
	{
		bool isRefCounted{};
		bool unkRefdObjMember{};
		volatile long RefCount{};
		
	public:
		ReferencedObject(csl::fnd::IAllocator* pAllocator, bool isRefCounted) : BaseObject{ pAllocator }, isRefCounted{ isRefCounted } {}

		virtual void ReferencedObject_UnkFunc1() {}

		inline void Acquire() {
			if (isRefCounted) {
				InterlockedExchangeAdd(&RefCount, 1);
			}
		}

		inline void Free() {
			if (isRefCounted) {
				long result = InterlockedExchangeAdd(&RefCount, -1);

				if (result == 1)
					delete this;
			}
		}
	};
}
