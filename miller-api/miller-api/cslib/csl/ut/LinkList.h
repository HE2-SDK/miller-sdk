#pragma once

namespace csl::ut
{
    class LinkListNode
    {
    public:
        LinkListNode* m_pPrev{};
        LinkListNode* m_pNext{};
    };

    namespace detail {
        class LinkListImpl
        {
        public:
            struct iterator
            {
                LinkListNode* m_pCurNode{};
                size_t m_NodeOffset{};
            };

        protected:
            size_t m_Count;
            int m_NodeOffset;
            LinkListNode* m_pEnd{ reinterpret_cast<LinkListNode*>(&m_pEnd) };
            LinkListNode* m_pRoot{ reinterpret_cast<LinkListNode*>(&m_pEnd) };

            void Initialize()
            {
                m_Count = 0;
                m_pEnd = reinterpret_cast<LinkListNode*>(m_pEnd);
                m_pRoot = reinterpret_cast<LinkListNode*>(m_pEnd);
            }

            LinkListImpl()
            {
                Initialize();
            }

            void insert(iterator iter, LinkListNode* pNode)
            {
                LinkListNode* oldNext;

                ++m_Count;
                oldNext = iter.m_pCurNode->m_pNext;
                pNode->m_pPrev = iter.m_pCurNode;
                pNode->m_pNext = oldNext;
                iter.m_pCurNode->m_pNext = pNode;
                oldNext->m_pPrev = pNode;
            }

            LinkListNode* erase(LinkListNode* pNode)
            {
                LinkListNode* pResult = pNode->m_pPrev;
                m_Count--;
                pNode->m_pPrev->m_pNext = pNode->m_pNext;
                pNode->m_pNext->m_pPrev = pNode->m_pPrev;
                pNode->m_pNext = nullptr;
                pNode->m_pPrev = nullptr;
                return pResult;
            }
        };
    }

	template<class T>
	class LinkList : public detail::LinkListImpl
	{
	public:
		class iterator
		{
			friend LinkList;
			
		protected:
			LinkListNode* m_pCurNode{};
			size_t m_NodeOffset;

		public:
			iterator(LinkListNode* pNode, size_t nodeOffset) : m_pCurNode(pNode), m_NodeOffset(nodeOffset)
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
			friend LinkList;

		protected:
			const LinkListNode* m_pCurNode{};
			size_t m_NodeOffset;

		public:
			const_iterator(const LinkListNode* pNode, size_t nodeOffset) : m_pCurNode(pNode), m_NodeOffset(nodeOffset)
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

		void init(LinkListNode(T::* nodeOffset))
		{
			m_NodeOffset = reinterpret_cast<size_t>(*reinterpret_cast<size_t**>(&nodeOffset));
		}
		
		LinkList()
		{
			
		}

		LinkList(size_t nodeOffset)
		{
			m_NodeOffset = nodeOffset;
		}

		LinkList(LinkListNode(T::*nodeOffset))
		{
			init(nodeOffset);
		}

	private:
		LinkListNode* GetNode(T* pItem)
		{
			return reinterpret_cast<LinkListNode*>(reinterpret_cast<size_t>(pItem) + m_NodeOffset);
		}
		
	public:
		void push_back(T* pItem)
		{
			LinkListImpl::insert({ m_pEnd, m_NodeOffset }, GetNode(pItem));
		}

		void erase(T* pItem)
		{
			LinkListImpl::erase(GetNode(pItem));
		}

		void erase(iterator start, iterator finish)
		{
			LinkListNode* pCurNode = start.m_pCurNode;
			while (pCurNode != finish.m_pCurNode)
			{
				pCurNode = LinkListImpl::erase(pCurNode);
			}
		}

		void clear()
		{
			erase(begin(), end());
		}

		~LinkList()
		{
			clear();
		}
		
		[[nodiscard]] iterator begin() { return iterator(m_pEnd, m_NodeOffset); }
		[[nodiscard]] iterator end()
		{
			return iterator(reinterpret_cast<LinkListNode*>(&m_pEnd), m_NodeOffset);
		}
		[[nodiscard]] const_iterator begin() const { return const_iterator(m_pEnd, m_NodeOffset); }
		[[nodiscard]] const_iterator end() const
		{
			return const_iterator(const_cast<LinkListNode*>(reinterpret_cast<const LinkListNode*>(&m_pEnd)), m_NodeOffset);
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
