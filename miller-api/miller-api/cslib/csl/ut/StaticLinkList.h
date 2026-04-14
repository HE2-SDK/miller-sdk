#pragma once

namespace csl::ut
{
    class StaticLinkListNode
    {
    public:
        StaticLinkListNode* m_pPrev{};
        StaticLinkListNode* m_pNext{};
    };

	template<class T, int m_NodeOffset>
	class StaticLinkList
	{
	public:
		class iterator
		{
			friend StaticLinkList;
			
		protected:
			StaticLinkListNode* m_pCurNode{};

		public:
			iterator(StaticLinkListNode* pNode) : m_pCurNode(pNode)
			{
				
			}
			
			T* operator->() const
			{
				return reinterpret_cast<T*>(reinterpret_cast<size_t>(m_pCurNode) - m_NodeOffset);
			}

			T& operator*() const
			{
				return *operator->();
			}
			
			friend bool operator==(const iterator& lhs, const iterator& rhs)
			{
				return lhs.m_pCurNode == rhs.m_pCurNode;
			}

			friend bool operator!=(const iterator& lhs, const iterator& rhs)
			{
				return lhs.m_pCurNode != rhs.m_pCurNode;
			}

			iterator& operator++()
			{
				m_pCurNode = m_pCurNode->m_pPrev;
				return *this;
			}

			iterator& operator--()
			{
				m_pCurNode = m_pCurNode->m_pNext;
				return *this;
			}

			operator T* () const
			{
				return operator->();
			}
		};

		class const_iterator
		{
			friend StaticLinkList;

		protected:
			const StaticLinkListNode* m_pCurNode{};

		public:
			const_iterator(const StaticLinkListNode* pNode) : m_pCurNode(pNode)
			{

			}

			T* operator->() const
			{
				return reinterpret_cast<T*>(reinterpret_cast<size_t>(m_pCurNode) - m_NodeOffset);
			}

			T& operator*() const
			{
				return *operator->();
			}

			friend bool operator==(const const_iterator& lhs, const const_iterator& rhs)
			{
				return lhs.m_pCurNode == rhs.m_pCurNode;
			}

			friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs)
			{
				return lhs.m_pCurNode != rhs.m_pCurNode;
			}

			const_iterator& operator++()
			{
				m_pCurNode = m_pCurNode->m_pPrev;
				return *this;
			}

			const_iterator& operator--()
			{
				m_pCurNode = m_pCurNode->m_pNext;
				return *this;
			}

			operator T*() const
			{
				return operator->();
			}
		};

	protected:
		StaticLinkListNode sentinel{ &sentinel, &sentinel };
		size_t m_Count;

		void Initialize()
		{
			m_Count = 0;
			sentinel = { &sentinel, &sentinel };
		}

		StaticLinkList()
		{
			Initialize();
		}

		void insert(iterator iter, StaticLinkListNode* pNode)
		{
			StaticLinkListNode* oldNext;

			++m_Count;
			oldNext = iter.m_pCurNode->m_pNext;
			pNode->m_pPrev = iter.m_pCurNode;
			pNode->m_pNext = oldNext;
			iter.m_pCurNode->m_pNext = pNode;
			oldNext->m_pPrev = pNode;
		}

		StaticLinkListNode* erase(StaticLinkListNode* pNode)
		{
			StaticLinkListNode* pResult = pNode->m_pPrev;
			m_Count--;
			pNode->m_pPrev->m_pNext = pNode->m_pNext;
			pNode->m_pNext->m_pPrev = pNode->m_pPrev;
			pNode->m_pNext = nullptr;
			pNode->m_pPrev = nullptr;
			return pResult;
		}

	private:
		StaticLinkListNode* GetNode(T* pItem)
		{
			return reinterpret_cast<StaticLinkListNode*>(reinterpret_cast<size_t>(pItem) + m_NodeOffset);
		}
		
	public:
		void push_back(T* pItem)
		{
			insert({ sentinel.m_pPrev }, GetNode(pItem));
		}

		void erase(T* pItem)
		{
			erase(GetNode(pItem));
		}

		void erase(iterator start, iterator finish)
		{
			StaticLinkListNode* pCurNode = start.m_pCurNode;
			while (pCurNode != finish.m_pCurNode)
			{
				pCurNode = erase(pCurNode);
			}
		}

		void clear()
		{
			erase(begin(), end());
		}

		~StaticLinkList()
		{
			clear();
		}
		
		[[nodiscard]] iterator begin() { return iterator(sentinel.m_pPrev); }
		[[nodiscard]] iterator end()
		{
			return iterator(&sentinel);
		}
		[[nodiscard]] const_iterator begin() const { return const_iterator(sentinel.m_pPrev); }
		[[nodiscard]] const_iterator end() const
		{
			return const_iterator(&sentinel);
		}
		
		[[nodiscard]] size_t size() const { return m_Count; }

		[[nodiscard]] T* front() const
		{
			if (!size())
				return nullptr;
			
			return begin();
		}
	};
}
