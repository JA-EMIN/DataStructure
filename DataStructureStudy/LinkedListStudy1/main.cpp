#pragma once
#include<iostream>
#include<time.h>
#include"LinkedList.h"

using namespace std;

typedef struct _tagData
{
	int num;
}tagData;

bool bubleSort(const tagData& tag1, const tagData& tag2)
{
	return tag1.num > tag2.num;
}
int main(void)
{
	//LinkedList<int> listInt;
	//for (int i = 0; i < 100; i++)
	//{
	//	listInt.push_back(i);
	//}
	//cout << "Size : " << listInt.size() << endl;

	//LinkedList<int>::Iterator iter;
	//LinkedList<int>::Iterator iterEnd = listInt.end();
	//iter = listInt.begin();
	//while (iter != iterEnd)
	//{
	//	cout << *iter << endl;
	//	++iter;
	//}

	//LinkedList<int>::ReverseIterator reverse_iter;
	//LinkedList<int>::ReverseIterator reverse_End = listInt.rend();
	//reverse_iter = listInt.rbegin();
	//while (reverse_iter != reverse_End)
	//{
	//	cout << *reverse_iter << endl;
	//	++reverse_iter;
	//}

	srand((unsigned int)time(0));
	
	LinkedList<tagData> link;
	for (int i = 0; i < 10; i++)
	{
		tagData tag = {};
		tag.num = rand() % 100;
		link.push_back(tag);
	}
	cout << "===================== Before Sorting ========================" << endl;
	LinkedList<tagData>::Iterator iter = link.begin();
	while (iter != link.end())
	{
		cout << (*iter).num << endl;
		++iter;
	}

	
	cout << "===================== After Sorting ========================" << endl;
	link.sort(bubleSort);
	iter = link.begin();
	while (iter != link.end())
	{
		cout << (*iter).num << endl;
		++iter;
	}
	
	
}