#include <iostream>
#include "LinkedList.h"

using namespace std;
int main()
{
	CLinkedList<int> listInt;
	for (int i = 0; i < 100; i++)
	{
		listInt.push_back(i);
	}
	cout << "Size : " << listInt.size() << endl;
	return 0;
}