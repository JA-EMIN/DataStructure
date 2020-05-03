#pragma once
template<typename T>
class LinkNode
{
	template<typename T>
	friend class LinkedList;
	
	template<typename T>
	friend class ListIterator;

	template<typename T>
	friend class ReverseListIterator;
public:
	LinkNode()
	{
		pNext = nullptr;
		pPrev = nullptr;
	};
	~LinkNode()
	{
	};
private:
	T m_Data;
	LinkNode<T>* pNext;
	LinkNode<T>* pPrev;
};
