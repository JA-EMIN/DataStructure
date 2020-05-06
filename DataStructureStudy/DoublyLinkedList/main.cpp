#include<iostream>
#include"LinkedList.h"
#include<time.h>
#include<string.h>
using namespace std;


typedef struct _tagStudent
{
	string strName;
	int nNumber;
	int nKor;
	int nEng;
	int nMath;
	int nTotal;
	float avg;
	
}Student, *PStudent;


bool NameCmp(const Student& t_src, const Student& t_dst)
{
	return t_src.strName > t_dst.strName;
}

bool MathCmp(const Student& t_src, const Student& t_dst)
{
	return t_src.nMath > t_dst.nMath;
}

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
	system("cls");
	Student tStudent;
	tStudent.strName = "철수";
	tStudent.nNumber = 0;
	tStudent.nKor = 10;
	tStudent.nEng = 20;
	tStudent.nMath = 30;
	tStudent.nTotal = 60;
	tStudent.avg = 20.f;

	CLinkedList<Student> studentList;
	studentList.push_back(tStudent);

	tStudent.strName = "영희";
	tStudent.nNumber = 1;
	tStudent.nKor = 70;
	tStudent.nEng = 89;
	tStudent.nMath = 61;
	tStudent.nTotal = tStudent.nKor + tStudent.nEng + tStudent.nMath;
	tStudent.avg = tStudent.nTotal / 3.f;

	studentList.push_back(tStudent);

	tStudent.strName = "나서스";
	tStudent.nNumber = 2;
	tStudent.nKor = 40;
	tStudent.nEng = 39;
	tStudent.nMath = 5;
	tStudent.nTotal = tStudent.nKor + tStudent.nEng + tStudent.nMath;
	tStudent.avg = tStudent.nTotal / 3.f;
	studentList.push_back(tStudent);

	CLinkedList<Student>::Iterator studentIter = studentList.begin();
	cout << "이름\t번호\t국어\t영어\t수학\t총점\t평균" << endl;
	while (studentIter != studentList.end())
	{
		cout << (*studentIter).strName << "\t" << (*studentIter).nNumber << "\t" <<
			(*studentIter).nKor << "\t" << (*studentIter).nEng << "\t" << (*studentIter).nMath << "\t"
			<< (*studentIter).nTotal << "\t" << (*studentIter).avg << "\t" << endl;
		++studentIter;
	}

	cout << "After Sorting" << endl;
	studentList.sort(MathCmp);
	cout << "이름\t번호\t국어\t영어\t수학\t총점\t평균" << endl;
	studentIter = studentList.begin();
	while (studentIter != studentList.end())
	{
		cout << (*studentIter).strName << "\t" << (*studentIter).nNumber << "\t" <<
			(*studentIter).nKor << "\t" << (*studentIter).nEng << "\t" << (*studentIter).nMath << "\t"
			<< (*studentIter).nTotal << "\t" << (*studentIter).avg << "\t" << endl;
		++studentIter;
	}
	return 0;
}