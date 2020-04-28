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

	CLinkedList<T>* m_pNext;				//������� �ּ� ����
	CLinkedList<T>* m_pPrev;				//������� �ּ� ����
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
		
		//End�� ���� ��带 ���´�.
		PNODE pPrev = m_pEnd->m_pPrev;

		//���� ���� ���� End��� ���̿� ���� ������ ��� �߰�
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;


		//End���� ���� ������ ��带 ����
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_nSize;
	}
	void push_front(const T& data)
	{
		PNODE pNode = new PNODE;
		pNode->m_nData = data;

		//Begin�� ���� ��带 ���´�
		PNODE pNext = m_pBegin->m_pNext;
		
		//���� ���� ���� Begin ��� ���̿� ���ο� ��� �߰�
		pNext->m_pPrev = pNode;
		pNode->m_pNext = pNext;

		//Begin���� ���� ������ ��带 ����
		m_pBegin->m_pNext = pNode;
		pNode->m_pPrev = m_pBegin;

		++m_nSize;
	}

	void pop_back()
	{
		if (empty())
			assert(false);

		//���� ������ ��带 ������ �ϹǷ� End����� ���� ��带 ���´�.
		PNODE pNode = m_pEnd->m_pPrev;

		//���� ����� ���� ��带 ���´�.
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
			//���� ����� ���� ��带 ���´�.
			PNODE pNext = pNode->m_pNext;
			//���� ��带 �����ش�.
			delete pNode;
			//pNode�� ���� ����� �ּҸ� �־��ش�.
			pNode = pNext;
		}

		m_nSize = 0;
		//Begin��End ����
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
	//����Ʈ�� ������� ��� true, �ƴ� ��� false ��ȯ
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

