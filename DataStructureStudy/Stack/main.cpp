#include <iostream>
using namespace std;
#include "Stack.h"

int main()
{
	CStackList<char> charStack;
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		charStack.push(ch);
	}
	while (!charStack.empty())
	{
		cout << charStack.pop() << endl;
	}

	CStackList<char> charStack2;
	char strText[10] = "TestStr";
	for (int i = 0; i < strlen(strText); i++)
	{
		charStack2.push(strText[i]);
	}
	for (int i = 0; i < strlen(strText); i++)
	{
		cout << charStack2.pop() << endl;
	}
	CStackArray<int> intStackArr;
	for (int i = 0; i < 10; i++)
	{
		intStackArr.push(i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << intStackArr.pop() << endl;
	} 
	return 0;
}