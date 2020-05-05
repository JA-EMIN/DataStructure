#pragma once
/*Stack : LIFO
*/
#include <assert.h>

template <typename T>
class CStackNode 
{
	template<typename T>
	friend class CStack;
	template<typename T>
	friend class CStackList;
private:
	CStackNode<T>* m_pNext;
	T			   m_Data;
private:
	CStackNode()
	{
		m_pNext = nullptr;
	}
	~CStackNode()
	{
	}
};

template <typename T>
class CStackList
{
public:
	CStackList() :m_pNode(nullptr), m_nSize(0)
	{

	};
	~CStackList()
	{
		clear();
	};

private:
	typedef CStackNode<T>* PNODE;
	typedef CStackNode<T> NODE;
	PNODE m_pNode;
	int m_nSize;

public:
	void push(const T& data)
	{
		//�����͸� �߰��ϱ� ���� ��� ����
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//���� ������ ����� ���� ���� ������ m_pNode�� �Ҵ�
		//m_pNode�� �׻� ���� �������� �߰��� ����̴�.
		//���� ó�� �߰��Ѵٸ� m_pNode�� nullptr�̱� ������ ���� ������
		//����� ���� ���� nullptr�� �ȴ�.
		pNode->m_pNext = m_pNode;

		//���� ������ ��尡 ���� �������� �߰��� ����̹Ƿ�
		//m_pNode�� �� ����� �ּҷ� �����Ѵ�.
		m_pNode = pNode;
		++m_nSize;
	}

	void clear()
	{
		if (empty())
			assert(false);

		PNODE pNode = m_pNode;
		while (pNode != nullptr)
		{
			//���� ��带 ���´�
			PNODE pNext = pNode->m_pNext;
			//��带 �����
			delete pNode;
			//������ ���� ���� ����
			pNode = pNext;
		}

		m_nSize = 0;
	}
	T& pop()
	{
		if (empty())
			assert(false);

		//���� �������� �߰��� ����� ���� ��带 ���´�.
		PNODE pNext = m_pNode->m_pNext;
		T data = m_pNode->m_Data;

		//���� ������ ��带 �����.
		delete m_pNode;
		m_pNode = pNext;
		--m_nSize;

		return data;
	}
	T& top() const
	{
		if (empty())
			assert(false);

		return m_pNode->m_Data;
	}

	bool empty() const
	{
		return m_nSize == 0;
	}
	int size() const
	{
		return m_nSize;
	}
};

template <typename T, int SIZE = 10>
class CStackArray
{
public:
	CStackArray()
	{
		m_nCapcity = SIZE;
		m_nSize = 0;
		m_pArray = new T[m_nCapcity];
	};
	~CStackArray()
	{
		delete[] m_pArray;
	};
private:
	T* m_pArray;
	int m_nSize;
	int m_nCapcity;

public:
	void push(const T& data)
	{
		if (full())
		{
			m_nCapcity *= 2;
			T* pArray = new T[m_nCapcity];
			//memcpy : �޸𸮸� �������ִ� �Լ�

			memcpy(pArray, m_pArray, sizeof(T)*m_nSize);
			delete[] m_pArray;
			m_pArray = pArray;
		}
		m_pArray[m_nSize] = data;
		++m_nSize;
	}
	T& top() const
	{
		if (empty())
			assert(false);
		return m_pArray[m_nSize-1];
	}

	T& pop()
	{
		if (empty())
			assert(false);
		m_nSize--;
		return m_pArray[m_nSize];
	}

	void clear()
	{
		m_nSize = 0;
	}
	bool empty() const
	{
		return m_nSize == 0;
	}
	
	bool full() const
	{
		return m_nSize == m_nCapcity;
	}
	int size() const
	{
		return m_nSize;
	}

	int capacity() const
	{
		return m_nSize;
	}
 };
