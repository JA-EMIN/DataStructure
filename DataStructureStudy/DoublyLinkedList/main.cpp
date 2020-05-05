#include<iostream>
#include"LinkedList.h"
#include<time.h>
using namespace std;


template<typename T>
bool customSort(const T& t_src, const T& t_dst)
{
	return t_src > t_dst;
}
int main()
{
	CLinkedList<int> listInt;
	for (int i = 0; i < 100; i++)
	{
		listInt.push_back(i);
	}

	CLinkedList<int>::Iterator iter = listInt.begin();
	CLinkedList<int>::Iterator iterEnd = listInt.end();
	
	for (iter = listInt.begin(); iter != iterEnd; ++iter)
	{
		//cout << *iter << endl;
	}

	CLinkedList<int>::Reverse_Iterator rIter;
	CLinkedList<int>::Reverse_Iterator rIterEnd = listInt.rEnd();

	for (rIter = listInt.rbegin(); rIter != rIterEnd; ++rIter)
	{
		//cout << *rIter << endl;
	}

	iter = listInt.begin();
	for (int i = 0; i < 30; ++i, ++iter)
	{
	}
	iter = listInt.erase(iter);
	cout << *iter << endl;

	iter = listInt.begin();
	listInt.erase(10);

	for (iter = listInt.begin(); iter != iterEnd; ++iter)
	{
		cout << *iter << endl;
	}
	system("cls");
	srand((unsigned int)time(0));
	listInt.clear();

	cout << "==========Before Sorting============" << endl;
	for (int i = 0; i < 10; i++)
	{
		int iData = rand();
		listInt.push_back(iData);
		cout << iData << endl;
	}
	listInt.sort(customSort);
	cout << "==========After Sorting============" << endl;
	for (iter= listInt.begin(); iter != listInt.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}