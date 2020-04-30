#pragma once
template<typename T>
class LinkNode
{
	template<typename T>
	friend class LinkedList;
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
