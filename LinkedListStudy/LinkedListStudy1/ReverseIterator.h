#pragma once
#include "LinkNode.h"

template<typename T>
class ReverseListIterator {

	template<typename T>
	friend class LinkedList;

public:
	ReverseListIterator()
	{
		m_pNode = nullptr;
	}
	~ReverseListIterator()
	{
	}
private:
	typedef LinkNode<T>* PNODE;
	PNODE m_pNode;
public:
	bool operator == (const ReverseListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}
	bool operator != (const ReverseListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}
	void operator ++()
	{
		m_pNode = m_pNode->pPrev;
	}

	void operator --()
	{
		m_pNode = m_pNode->pNext;
	}
	T& operator *()
	{
		return m_pNode->m_Data;
	}
};
