#pragma once

namespace csl::ut
{
	template<typename TKey, typename TValue, typename TOp>
	class HashMap
	{
		inline static constexpr size_t INVALID_KEY = static_cast<size_t>(-1);
		
	protected:
		struct Elem
		{
			size_t m_Hash;
			TKey m_Key;
			TValue m_Value;
		};
		
		Elem* m_pElements{};
		size_t m_Length{};
		size_t m_Capacity{};
		fnd::IAllocator* m_pAllocator{};
		
	protected:
		size_t CalcResize(size_t capacity)
		{
			size_t result;
			for (result = 16; result < capacity; result *= 2);

			if (result < 16)
				result = 16;

			return result;
		}

		Elem* AllocateMemory(size_t count)
		{
			return static_cast<Elem*>(m_pAllocator->Alloc(sizeof(Elem) * count, alignof(Elem)));
		}

		void ReleaseMemory()
		{
			if (!(m_Capacity & csl::ut::SIGN_BIT) && m_pAllocator && m_pElements)
			{
				m_pAllocator->Free(m_pElements);
			}
		}
		
		size_t GetCapacity() const
		{
			return m_Capacity & ~csl::ut::SIGN_BIT;
		}

		size_t GetHashMask() const
		{
			return GetCapacity() - 1;
		}

		void ResizeTbl(size_t capacity)
		{
			size_t oldCap = GetCapacity();
			Elem* oldElements = m_pElements;

			m_Capacity = capacity;
			m_Length = 0;

			m_pElements = AllocateMemory(capacity);
			memset(m_pElements, -1, sizeof(Elem) * capacity);

			if (oldElements)
			{
				for (size_t i = 0; i < oldCap; i++)
				{
					const Elem* pElem = &oldElements[i];

					if (pElem->m_Hash != INVALID_KEY)
					{
						Insert(pElem->m_Key, pElem->m_Value);
						pElem->m_Value.~TValue();
					}
				}

				if (m_pAllocator)
					m_pAllocator->Free(oldElements);
			}
		}

		void Reserve(size_t capacity)
		{
			size_t cap = CalcResize(capacity);
			if (GetCapacity() < cap)
				ResizeTbl(cap);
		}
		
	public:
		HashMap(fnd::IAllocator* pAllocator) : m_Capacity{ csl::ut::SIGN_BIT }
		{
			m_pAllocator = pAllocator;
		}

		HashMap(const HashMap& other) : HashMap{ other.m_pAllocator }
		{
			if (!(other.m_Capacity & csl::ut::SIGN_BIT)) {
				reserve(other.m_Capacity);

				for (auto i = other.begin(); i != other.end(); i++)
					Insert(other.GetKey(i), other.GetValue(i));
			}
		}

		HashMap(HashMap&& other) : HashMap{ other.m_pAllocator }
		{
			m_pElements = other.m_pElements;
			m_Length = other.m_Length;
			m_Capacity = other.m_Capacity;
			other.m_pElements = nullptr;
			other.m_Length = 0;
			other.m_Capacity = csl::ut::SIGN_BIT;
		}

		void reserve(size_t capacity)
		{
			Reserve(capacity);
		}

		~HashMap()
		{
			if (!(m_Capacity & csl::ut::SIGN_BIT))
			{
				for (size_t i = 0; i < GetCapacity(); i++)
				{
					const Elem& pElem = m_pElements[i];
					if (pElem.m_Hash != INVALID_KEY)
						pElem.m_Value.~TValue();
				}
			}

			ReleaseMemory();
			m_Length = 0;
			m_Capacity = 0;
			m_pElements = nullptr;
		}
		
	protected:
		size_t GetBegin() const
		{
			for (size_t i = 0; i < GetCapacity(); i++)
			{
				if (m_pElements[i].m_Hash != INVALID_KEY)
					return i;
			}
			
			return GetCapacity();
		}

		size_t GetNext(size_t idx) const
		{
			for (size_t i = idx + 1; i < GetCapacity(); i++)
			{
				if (m_pElements[i].m_Hash != INVALID_KEY)
					return i;
			}

			return GetCapacity();
		}
		
	public:
		struct iterator
		{
			const HashMap* m_pOwner;
			size_t m_CurIdx;

			friend bool operator==(const iterator& a, const iterator& b) { return a.m_CurIdx == b.m_CurIdx; }
			friend bool operator!=(const iterator& a, const iterator& b) { return a.m_CurIdx != b.m_CurIdx; }

			iterator& operator++() { m_CurIdx = m_pOwner->GetNext(m_CurIdx); return *this; }
			iterator operator++(int) { iterator tmp = *this; m_CurIdx = m_pOwner->GetNext(m_CurIdx); return tmp; }

			TKey& key() const
			{
				return m_pOwner->GetKey(*this);
			}

			TValue& operator*() const
			{
				return m_pOwner->GetValue(*this);
			}

			TValue* operator->() const
			{
				return &operator*();
			}

			operator TValue& ()
			{
				return operator*();
			}
		};

		iterator begin() const
		{
			return iterator{ this, GetBegin() };
		}

		iterator end() const
		{
			return iterator{ this, GetCapacity() };
		}

		void clear()
		{
			m_Length = 0;
			for (size_t i = 0; i < GetCapacity(); ++i)
			{
				auto& element = m_pElements[i];
				
				if (element.m_Hash != INVALID_KEY)
					element.m_Value.~TValue();

				element.m_Hash = INVALID_KEY;
			}
		}

		size_t size() const
		{
			return m_Length;
		}

		iterator InsertAndGet(TKey key, TValue value)
		{
			size_t hash = TOp::hash(key) & 0x7FFFFFFFFFFFFFFF;
			if (m_Length || GetCapacity())
			{
				if (2 * m_Length >= GetCapacity())
				{
					ResizeTbl(2 * GetCapacity());
				}
			}
			else
			{
				ResizeTbl(CalcResize(GetCapacity()));
			}

			size_t idx = hash & GetHashMask();
			Elem* pElem = &m_pElements[idx];

			if (pElem->m_Hash == INVALID_KEY)
			{
				pElem->m_Hash = hash;
				pElem->m_Key = key;
				m_Length++;
			}
			else
			{
				while (pElem->m_Hash != hash || pElem->m_Key != key)
				{
					idx = (idx + 1) & GetHashMask();
					pElem = &m_pElements[idx];

					if (pElem->m_Hash == INVALID_KEY)
					{
						pElem->m_Hash = hash;
						pElem->m_Key = key;
						m_Length++;
						break;
					}
				}
			}

			new (&pElem->m_Value) TValue(value);

			return { this, idx };
		}
		
		void Insert(TKey key, TValue value) {
			InsertAndGet(key, value);
		}

		TValue& GetValueOrFallback(const TKey& key, TValue&& fallback) const {
			auto result = Find(key);

			if (result == end())
				return fallback;

			return GetValue(result);
		}

		iterator Find(const TKey& key) const
		{
			if (!m_pElements)
				return end();
			
			const size_t hash = TOp::hash(key) & 0x7FFFFFFFFFFFFFFF;
			size_t idx = hash & GetHashMask();
			const Elem* pElem = &m_pElements[idx];
			
			if (pElem->m_Hash == INVALID_KEY)
				return end();
			
			while (pElem->m_Hash != hash || !TOp::compare(key, pElem->m_Key))
			{
				idx = (idx + 1) & GetHashMask();
				pElem = &m_pElements[idx];

				if (pElem->m_Hash == INVALID_KEY)
					return end();
			}

			return iterator{ this, idx };
		}

		TKey& GetKey(const iterator& iter) const
		{
			return iter.m_pOwner->m_pElements[iter.m_CurIdx].m_Key;
		}
		
		TValue& GetValue(const iterator& iter) const
		{
			return iter.m_pOwner->m_pElements[iter.m_CurIdx].m_Value;
		}
		
		void Erase(const TKey& key)
		{
			Erase(Find(key));
		}

		void Erase(const iterator& iter)
		{
			if (iter == end())
				return;

			size_t idx = iter.m_CurIdx;
		
			Elem* pElem = &m_pElements[idx];
			pElem->m_Hash = INVALID_KEY;
			m_Length--;

			pElem->m_Value.~TValue();

			size_t lowestIdx = (idx + GetHashMask()) & GetHashMask();
			while (m_pElements[lowestIdx].m_Hash != INVALID_KEY)
				lowestIdx = (lowestIdx + GetHashMask()) & GetHashMask();
			lowestIdx = (lowestIdx + 1) & GetHashMask();

			size_t emptyIdx = idx;

			for (idx = (idx + 1) & GetHashMask(); m_pElements[idx].m_Hash != INVALID_KEY; idx = (idx + 1) & GetHashMask()) {
				size_t desiredIdx = m_pElements[idx].m_Hash & GetHashMask();

				if (idx >= lowestIdx && desiredIdx > emptyIdx)
					continue;

				if (idx < emptyIdx && (desiredIdx > emptyIdx || desiredIdx <= idx))
					continue;

				if (desiredIdx > emptyIdx && desiredIdx < lowestIdx)
					continue;

				m_pElements[emptyIdx] = std::move(m_pElements[idx]);
				m_pElements[idx].m_Hash = INVALID_KEY;
				emptyIdx = idx;
			}
		}
	};
}