#pragma once
#include "LinkNode.h"

template<typename T>
class ListIterator {
	template<typename T>
	friend class LinkedList;
public:
	ListIterator()
	{
		m_pNode = nullptr;
	}
	~ListIterator()
	{
	}
private:
	typedef LinkNode<T>* PNODE;
	PNODE m_pNode;
public:
	bool operator == (const ListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}
	bool operator != (const ListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}
	void operator ++()
	{
		m_pNode = m_pNode->pNext;
	}
	void operator --()
	{
		m_pNode = m_pNode->pPrev;
	}
	T& operator *()
	{
		return m_pNode->m_Data;
	}
};
