#pragma once
#include<assert.h>

template <typename T>
class CListNode
{
	template <typename T>
	friend class CLinkedList;

	template <typename T>
	friend class CListIterator;

	template <typename T>
	friend class CListReverseIterator;
private:
	//생성자를 private으로 하면 외부에서 이 객체의 생성을 못한다.
	//생성자를 private으로 하면 외부에서 메모리 해제가 안된다.
	CListNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
	~CListNode()
	{
	}
private:
	T m_Data;
	CListNode<T>* m_pNext;		//이전노드 주솣ㅇ 
	CListNode<T>* m_pPrev;		//다음노드 주소
};
/*
 if you want to apply template to class, there are two ways.
 1. You can apply template in individual funcion in class.
 2. You can also apply template to whole of class.
*/

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		//시작을 정의할 노드 할당
		m_pBegin = new NODE;
		//끝을 정의할 노드 할당
		m_pEnd = new NODE;
		m_nSize = 0;
		 
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

	};
	~CLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	};
private:
	typedef CListNode<T> NODE;
	typedef CListNode<T> *PNODE;

public:
	typedef CListIterator<T> Iterator;
	typedef CListReverseIterator<T> Reverse_Iterator;
private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	int m_nSize;

public:
	void push_back(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pPrev = m_pEnd->m_pPrev;

		pNode->m_pNext = m_pEnd;
		pNode->m_pPrev = pPrev;

		m_pEnd->m_pPrev = pNode;
		pPrev->m_pNext = pNode;
		m_nSize++;
	}

	void push_front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pNext = m_pBegin->m_pNext;
		pNode->m_pPrev = m_pBegin;
		pNode->m_pNext = pNext;

		pNext->m_pPrev = pNode;
		m_pBegin->m_pNext = pNode;
		m_nSize++;
	}

	int size() const
	{
		return m_nSize;
	}

	bool empty() const
	{
		return m_nSize == 0;
	}
	
	void pop_back()
	{
		if (empty())
			assert(false);

		//가장 뒤의 노드를 삭제해야 하므로 End의 이전노드를 삭제노드로 얻어온다.
		PNODE deleteNode = m_pEnd->m_pPrev;
		PNODE pPrev = deleteNode->m_pPrev;
		m_pEnd->m_pPrev = pPrev;
		pPrev->m_pNext = m_pEnd;

		delete deleteNode; 
		m_nSize--;
	}

	void pop_front()
	{
		if (empty())
			assert(false);

		PNODE deleteNode = m_pBegin->m_pNext;
		PNODE pNext = deleteNode->m_pNext;
		
		m_pBegin->m_pNext = pNext;
		pNext->m_pPrev = m_pBegin;

		delete deleteNode;
		m_nSize--;
	}

	T front() const
	{
		if (empty())
			assert(false);
		return m_pBegin->m_pNext->m_Data;
	}

	T back() const
	{
		if (empty())
			assert(false);
		return m_pEnd->m_pPrev->m_Data;
	}

	void clear()
	{
		if (empty())
			return;
		PNODE pNode = m_pBegin->m_pNext;
		while (pNode != m_pEnd)
		{
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_nSize = 0;
	}

	Iterator begin() const
	{
		Iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		
		return iter;
	}

	Iterator end() const
	{
		Iterator iter;
		iter.m_pNode = m_pEnd;

		return iter;
	}

	Reverse_Iterator rbegin() const
	{
		Reverse_Iterator iter;
		iter.m_pNode = m_pEnd->m_pPrev;

		return iter;
	}

	Reverse_Iterator rEnd() const
	{
		Reverse_Iterator iter;
		iter.m_pNode = m_pBegin;

		return iter;
	}

	Iterator erase(const Iterator& iter)
	{
		if (iter.m_pNode == m_pBegin || iter.m_pNode == m_pBegin)
			assert(false);

		PNODE pPrev = iter.m_pNode -> m_pPrev;
		PNODE pNext = iter.m_pNode-> m_pNext;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;
		
		delete iter.m_pNode;
		--m_nSize;

		Iterator result;
		result.m_pNode = pNext;
		return result;
	}

	Iterator erase(const T& data)
	{
		Iterator iter = begin();
		Iterator iterEnd = end();
		
		while (iter != iterEnd)
		{
			if (*iter == data)
			{
				return erase(iter);
			}
			++iter;
		}
		
		return end();
	}

	void sort(bool (*pFunc)(const T&, const T&))
	{
		for (PNODE pFirst = m_pBegin->m_pNext; pFirst != m_pEnd->m_pPrev; pFirst = pFirst->m_pNext)
		{
			for (PNODE pSecond = pFirst->m_pNext; pSecond != m_pEnd; pSecond = pSecond->m_pNext)
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

template <typename T>
class CListIterator
{
	template<typename T>
	friend class CLinkedList;
public:
	CListIterator()
	{
		m_pNode = nullptr;
	};
	~CListIterator()
	{
	};
private:
	typedef CListNode<T>* PNODE;
	typedef CListNode<T> NODE;
	PNODE m_pNode;

public:
	bool operator == (const CListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++()
	{
		m_pNode = m_pNode->m_pNext;
	}
	void operator --()
	{
		m_pNode = m_pNode->m_pPrev;
	}
	T& operator *()
	{
		return m_pNode->m_Data;
	}
	T& operator ->()
	{
		return m_pNode->m_Data;
	}
};

template <typename T>
class CListReverseIterator
{
	template<typename T>
	friend class CLinkedList;

private:
	typedef CListNode<T>* PNODE;
	PNODE m_pNode;

public:
	CListReverseIterator()
	{
		m_pNode = nullptr;
	}
	~CListReverseIterator()
	{

	};

public:
	bool operator ==(const CListReverseIterator<T>& rIter)
	{
		return m_pNode == rIter.m_pNode;
	}
	bool operator !=(const CListReverseIterator<T>& rIter)
	{
		return m_pNode != rIter.m_pNode;
	}
	void operator ++()
	{
		m_pNode = m_pNode->m_pPrev;
	}
	void operator --()
	{
		m_pNode = m_pNode->m_pNext;
	}
	T& operator *()
	{
		return m_pNode->m_Data;
	}

};



