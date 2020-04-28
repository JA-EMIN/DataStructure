#pragma once
#include<assert.h>

template <typename T>
class CListNode
{
	template<typename T>
	friend class CLinkedList;
private:
	CListNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
	~CListNode()
	{
	}
private:

	CLinkedList<T>* m_pNext;				//다음노드 주소 저장
	CLinkedList<T>* m_pPrev;				//이전노드 주소 저장
	T m_nData;
};


template<typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		m_pBegin = new PNODE;
		m_pEnd = new PNODE;
		m_nSize = 0;

		pBegin->m_pNext = pEnd;
		pEnd->m_pPrev = pBegin;
	};
	~CLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	};

	void push_back(const T& data)
	{
		PNODE pNode = new PNODE;
		pNode->m_nData = data;
		
		//End의 이전 노드를 얻어온다.
		PNODE pPrev = m_pEnd->m_pPrev;

		//얻어온 이전 노드와 End노드 사이에 새로 생성한 노드 추가
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;


		//End노드와 새로 생성한 노드를 연결
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_nSize;
	}
	void push_front(const T& data)
	{
		PNODE pNode = new PNODE;
		pNode->m_nData = data;

		//Begin의 다음 노드를 얻어온다
		PNODE pNext = m_pBegin->m_pNext;
		
		//얻어온 다음 노드와 Begin 노드 사이에 새로운 노드 추가
		pNext->m_pPrev = pNode;
		pNode->m_pNext = pNext;

		//Begin노드와 새로 생성한 노드를 연결
		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_nSize;
	}

	void pop_back()
	{
		if (empty())
			assert(false);

		//가장 마지막 노드를 지워야 하므로 End노드의 이전 노드를 얻어온다.
		PNODE pNode = m_pEnd->m_pPrev;

		//지울 노드의 이전 노드를 얻어온다.
		PNODE pPrev = pNode->m_pPrev;
		pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrev;

		delete pNode;
		--m_nSize;
	}

	void pop_front()
	{
		if (empty())
			assert(false);

		PNODE pNode = m_pBegin->m_pNext;
		PNODE pNext = pNode->m_pNext;

		m_pBegin->m_pNext = pNext;
		pNext->m_pPrev = m_pBegin
		delete pNode;
		--m_nSize;
	}

	void clear()
	{
		PNODE pNode = m_pBegin->m_pNext;
		
		while (pNode != m_pEnd)
		{
			//현재 노드의 다음 노드를 얻어온다.
			PNODE pNext = pNode->m_pNext;
			//현재 노드를 지워준다.
			delete pNode;
			//pNode에 다음 노드의 주소를 넣어준다.
			pNode = pNext;
		}

		m_nSize = 0;
		//Begin와End 연결
		pBegin->m_pNext = pEnd;
		pEnd->m_pPrev = pBegin;
	}
	int size() const
	{
		return m_nSize;
	}

	T front() const
	{
		if (empty())
			assert(false);
		return m_pBegin->m_pNext->m_nData;
	}
	T back() const
	{
		if (empty())
			assert(false);
		return m_pEnd->m_pPrev->m_nData;
	}
	//리스트가 비어있을 경우 true, 아닐 경우 false 반환
	bool empty() const
	{
		return m_nSize == 0
	}
private: 
	typedef CListNode<T>* PNODE;
	typedef CListNode<T> NODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	int m_nSize;
};

