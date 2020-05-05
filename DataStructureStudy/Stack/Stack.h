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
		//데이터를 추가하기 위한 노드 생성
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//새로 생성한 노드의 다음 노드로 기존의 m_pNode를 할당
		//m_pNode는 항상 가장 마지막에 추가한 노드이다.
		//만약 처음 추가한다면 m_pNode는 nullptr이기 때문에 새로 생성한
		//노드의 다음 노드는 nullptr이 된다.
		pNode->m_pNext = m_pNode;

		//새로 생성한 노드가 가장 마지막에 추가한 노드이므로
		//m_pNode를 이 노드의 주소로 갱신한다.
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
			//다음 노드를 얻어온다
			PNODE pNext = pNode->m_pNext;
			//노드를 지운다
			delete pNode;
			//얻어놓은 다음 노드로 갱신
			pNode = pNext;
		}

		m_nSize = 0;
	}
	T& pop()
	{
		if (empty())
			assert(false);

		//가장 마지막에 추가된 노드의 다음 노드를 얻어온다.
		PNODE pNext = m_pNode->m_pNext;
		T data = m_pNode->m_Data;

		//가장 마지막 노드를 지운다.
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
			//memcpy : 메모리를 복사해주는 함수

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
