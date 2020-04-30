#pragma once
#include "LinkNode.h"
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
};
