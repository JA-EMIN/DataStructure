#pragma once
#include "LinkNode.h"
#include "ListIterator.h"
#include "ReverseIterator.h"
#include <assert.h>

template<typename T>
class LinkedList
{
public:
	LinkedList()
	{
		m_nSize = 0;
		pBegin = new NODE;
		pEnd = new NODE;

		pBegin->pNext = pEnd;
		pEnd->pPrev = pBegin;
	};
	~LinkedList()
	{
		clear();
		delete pBegin;
		delete pEnd;
	};
private:
	typedef LinkNode<T>* PNODE;
	typedef LinkNode<T> NODE;
public:
	typedef ListIterator<T> Iterator;
	typedef ReverseListIterator<T> ReverseIterator;
	
private:
	PNODE pBegin;
	PNODE pEnd;
	int m_nSize;
public:
	int size() const
	{
		return m_nSize;
	}
	void push_back(const T& data)
	{

		PNODE pNode = new NODE;
		//새로운 노드에 Data 할당
		pNode->m_Data = data;

		PNODE pPrev = pEnd->pPrev;

		//새로운 노드 관계 설정
		pNode->pNext = pEnd;
		pNode->pPrev = pPrev;

		//기존 노드 관계 설정
		pEnd->pPrev = pNode;
		pPrev->pNext = pNode;
		++m_nSize;
	}

	void push_front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pNext = pBegin->pNext;


		pNode->pNext = pNext;
		pNode->pPrev = pBegin;

		pBegin->pNext = pNode;
		pNext->pPrev = pNode;
		++m_nSize;
	}

	void clear()
	{
		PNODE pNode = pBegin->pNext;
		
		while (pNode != pEnd)
		{

			PNODE pNext = pNode->pNext;
			delete pNode;
			pNode = pNext;			
		}

		m_nSize = 0;
		pBegin->pNext = pEnd;
		pEnd->pPrev = pBegin;
	}

	void pop_back()
	{
		if (empty())
			assert(false);
		PNODE pNode = pEnd->pPrev;
		PNODE pPrev = pNode->pPrev;

		delete pNode;
		pEnd ->pPrev = pPrev;
		pPrev ->pNext = pEnd;
		m_nSize--;
	}

	void pop_front()
	{
		if (empty())
			assert(false);
		PNODE pNode = pBegin->pNext;
		PNODE pNext = pNode->pNext;

		delete pNode;
		pBegin->pNext = pNext;
		pNext->pPrev = pBegin;
		m_nSize--;
	}

	bool empty() const
	{
		return m_nSize == 0;
	}

	T front() const
	{
		if (empty())
			assert(false);
		return pBegin->pNext->m_Data;
	}

	T back() const
	{
		if (empty())
			assert(false);
		return pEnd->pPrev->m_Data;
	}

	Iterator begin() const
	{
		Iterator iter;
		iter.m_pNode = pBegin->pNext;
		return iter;
	}

	Iterator end() const
	{
		Iterator iter;
		iter.m_pNode = pEnd;
		return iter;
	}

	ReverseIterator rbegin() const
	{
		ReverseIterator iter;
		iter.m_pNode = pEnd->pPrev;
		return iter;
	}
	
	ReverseIterator rend() const
	{
		ReverseIterator iter;
		iter.m_pNode = pBegin;
		return iter;
	}
	
	void sort(bool (*pFunc)(const T&, const T&))
	{
		for (PNODE pFirst = pBegin->pNext; pFirst != pEnd->pPrev; pFirst = pFirst->pNext)
		{
			for (PNODE pSecond = pFirst->pNext; pSecond != pEnd; pSecond = pSecond->pNext)
			{
				if (pFunc(pFirst->m_Data, pSecond->m_Data))
				{
					T temp = pFirst->m_Data;
					pFirst->m_Data = pSecond->m_Data;
					pSecond->m_Data = temp;
				}
			}
		}

	}
};
