#pragma once

namespace csl::ut
{
	static constexpr uint32_t SIGN_BIT = 0x80000000;
	
	template<typename T, typename S>
	class Array
	{
	protected:
		T* m_pBuffer{};
		S m_length{};
		S m_capacity{};
		fnd::IAllocator* m_pAllocator{};

		T* get(S i) const
		{
			if (!this->m_pBuffer)
				return nullptr;

			return &this->m_pBuffer[i];
		}

		bool isUninitialized()
		{
			return this->m_capacity & csl::ut::SIGN_BIT;
		}

	public:
		void change_allocator(fnd::IAllocator* new_allocator)
		{
			if (!new_allocator)
			{
				return;
			}

			if (isUninitialized() || !this->m_pBuffer)
			{
				m_pAllocator = new_allocator;
				return;
			}

			if (m_pAllocator == new_allocator)
			{
				return;
			}

			// Make a new m_pBuffer
			T* new_buffer = static_cast<T*>(new_allocator->Alloc(this->capacity() * sizeof(T), 16));

			// Copy buffers
			// memcpy(new_buffer, this->m_pBuffer, sizeof(T) * this->m_length);
			for (S i = 0; i < this->m_length; i++) {
				new (&new_buffer[i]) T{ std::move(this->m_pBuffer[i]) };
				this->m_pBuffer[i].~T();
			}

			// Free our old m_pBuffer
			if (m_pAllocator && !isUninitialized())
			{
				m_pAllocator->Free(this->m_pBuffer);
			}

			m_pAllocator = new_allocator;
			this->m_pBuffer = new_buffer;
		}

		void reserve(S len)
		{
			// We already have enough reserved, return
			if (len <= this->capacity())
				return;

			// Allocate a new m_pBuffer with the appropriate reserved storage
			T* new_buffer = static_cast<T*>(m_pAllocator->Alloc(sizeof(T) * len, 16));

			if (this->m_pBuffer)
			{
				//memcpy(new_buffer, this->m_pBuffer, sizeof(T) * this->m_length);
				for (S i = 0; i < this->m_length; i++) {
					new (&new_buffer[i]) T{ std::move(this->m_pBuffer[i]) };
					this->m_pBuffer[i].~T();
				}
			}

			// Free our old m_pBuffer
			if (!isUninitialized())
			{
				m_pAllocator->Free(this->m_pBuffer);
			}

			// Assign our new m_pBuffer and set the new m_capacity
			this->m_capacity = len;
			this->m_pBuffer = new_buffer;
		}

	public:
		Array() : m_capacity{ csl::ut::SIGN_BIT }
		{
		}

		Array(fnd::IAllocator* in_pAllocator) : m_capacity{ csl::ut::SIGN_BIT }, m_pAllocator{ in_pAllocator }
		{
		}

		Array(S in_capacity, fnd::IAllocator* in_pAllocator) : Array{ in_pAllocator }
		{
			reserve(in_capacity);
		}

		Array(const Array<T, S>& other) : Array<T, S>{ other.capacity(), other.m_pAllocator} {
			for (T& x : other) {
				this->push_back(x);
			}
		}

		Array(Array<T, S>&& other) : Array<T, S>{ other.m_pAllocator } {
			this->m_pBuffer = other.m_pBuffer;
			this->m_length = other.m_length;
			this->m_capacity = other.m_capacity;
			other.m_pBuffer = nullptr;
			other.m_length = 0;
			other.m_capacity = csl::ut::SIGN_BIT;
		}

		~Array()
		{
			for (S i = 0; i < this->m_length; i++) {
				this->m_pBuffer[i].~T();
			}

			if (m_pAllocator && !isUninitialized())
				m_pAllocator->Free(this->m_pBuffer);
		}

		Array<T, S>& operator=(Array<T, S>&& other) {
			for (S i = 0; i < this->m_length; i++) {
				this->m_pBuffer[i].~T();
			}

			if (m_pAllocator && !isUninitialized())
				m_pAllocator->Free(this->m_pBuffer);

			this->m_pAllocator = other.m_pAllocator;
			this->m_pBuffer = other.m_pBuffer;
			this->m_length = other.m_length;
			this->m_capacity = other.m_capacity;
			other.m_pBuffer = nullptr;
			other.m_length = 0;
			other.m_capacity = csl::ut::SIGN_BIT;

			return *this;
		}

		csl::fnd::IAllocator* get_allocator()
		{
			return m_pAllocator;
		}

		void push_back(const T& item)
		{
			if (this->m_length + 1 > this->capacity())
			{
				reserve((this->m_length + 1) * 2);
			}

			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T{ item };
		}

		void push_back(T&& item)
		{
			if (this->m_length + 1 > this->capacity())
			{
				reserve((this->m_length + 1) * 2);
			}

			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T{ std::move(item) };
		}

		void push_back_unchecked(const T& item)
		{
			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T{ item };
		}

		void push_back_unchecked(T&& item)
		{
			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T{ std::move(item) };
		}

		void emplace_back()
		{
			if (this->m_length + 1 > this->capacity())
			{
				reserve((this->m_length + 1) * 2);
			}

			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T{};
		}

		void emplace_back_unchecked()
		{
			this->m_length++;
			new (&this->m_pBuffer[this->m_length - 1]) T{};
		}

		void remove(S i)
		{
			if (i >= this->m_length)
				return;

			this->m_pBuffer[i].~T();

			for (S j = i + 1; j < this->m_length; j++)
				this->m_pBuffer[j - 1] = std::move(this->m_pBuffer[j]);

			this->m_length--;
		}

		bool empty() const
		{
			return this->m_length == 0;
		}

		void clear()
		{
			if (!empty()) {
				for (S i = 0; i < this->m_length; i++) {
					this->m_pBuffer[i].~T();
				}
				this->m_length = 0;
			}
		}

		void swap(csl::ut::Array<T, S>& rArray)
		{
			auto* tempBuffer = this->m_pBuffer;
			auto tempLen = this->m_length;
			auto tempCap = this->m_capacity;
			auto* tempAllocator = this->m_pAllocator;

			this->m_pBuffer = rArray.m_pBuffer;
			this->m_length = rArray.m_length;
			this->m_capacity = rArray.m_capacity;
			this->m_pAllocator = rArray.m_pAllocator;

			rArray.m_pBuffer = tempBuffer;
			rArray.m_length = tempLen;
			rArray.m_capacity = tempCap;
			rArray.m_pAllocator = tempAllocator;
		}

		template<typename U>
		S find(const U& item) const
		{
			for (S i = 0; i < this->m_length; i++)
			{
				if (*this->get(i) == item)
					return i;
			}

			return -1;
		}

		const T& operator[] (S i) const
		{
			return *this->get(i);
		}

		T& operator[] (S i)
		{
			return *this->get(i);
		}
		
	public:
		[[nodiscard]] T* begin() const { return get(0); }

		[[nodiscard]] T* end() const { return get(this->m_length); }

		[[nodiscard]] T front() const { return *get(0); }

		[[nodiscard]] S size() const
		{
			return this->m_length;
		}

		[[nodiscard]] S capacity() const
		{
			return this->m_capacity & ~csl::ut::SIGN_BIT;
		}
	};
}