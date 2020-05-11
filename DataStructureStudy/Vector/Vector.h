#pragma once
#include <assert.h>
#include<iostream>
template <typename T, int SIZE = 10>
class CVector
{
public:
	CVector()
	{
		m_nSize = 0;
		m_nCapacity = SIZE;
		pVector = new T[m_nCapacity];
	}
	~CVector()
	{
		delete[] pVector;
	}

private:
	T* pVector;
	int m_nCapacity;
	int m_nSize;

public:
	int size()
	{
		return m_nSize;
	}

	bool full()
	{
		return m_nSize == m_nCapacity;
	}

	bool empty()
	{
		return m_nSize == 0;
	}
	void push_back(const T& data)
	{
		if (full())
		{
			m_nCapacity *= 2;
			T* pTemp = new T[m_nCapacity];
			memcpy_s(pTemp, sizeof(T) * m_nCapacity, pVector, sizeof(T) * m_nSize);
			delete[] pVector;
			pVector = pTemp;
		}
		pVector[m_nSize] = data;
		m_nSize++;
	}

	void push_front(const T& data)
	{
		if (full())
		{
			m_nCapacity *= 2;
			T* pTemp = new T[m_nCapacity];
			memcpy_s(pTemp, sizeof(T) * m_nCapacity, pVector, sizeof(T) * m_nSize);
			delete pVector;
			pVector = pTemp;
		}

		if ( m_nSize == 0)
		{
			pVector[m_nSize] = data;
			m_nSize++;
		}
		else
		{		
			T* pTemp = new T[m_nCapacity];
			memcpy_s(pTemp+1, sizeof(T) * (m_nCapacity-1), pVector, sizeof(T) * m_nSize);
			delete pVector;
			pVector = pTemp;
			pVector[0] = data;
			m_nSize++;

		}
	}

	T& pop()
	{
		if (empty())
			assert(false);
		m_nSize--;
		return pVector[m_nSize - 1];
		
	}

	T& top()
	{
		if (empty())
			assert(false);
		return pVector[m_nSize - 1];
	}
public: 
	T& operator [](const int index)
	{
		return pVector[index];
	}
};
