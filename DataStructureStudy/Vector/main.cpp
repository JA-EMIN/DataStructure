#include <iostream>
#include"Vector.h"
using namespace std;


int main()
{
	//�߰��� ������ ���Խ� �ڿ� �ִ� �����͵��� ��ĭ�� �� �и�
	//�߰� ������ ������ ������ ��ĭ�� ��ܿ�
	//���� �۾����� ���� ó���ӵ� ���� �� ����
	//random access ����, List�� ��带 �߰��� �������� �����Ҵ��� �ʿ������� Vector�� �迭�� ������� �����͸� �Ҵ��ϸ� �ǹǷ� ���������� ���� �� ó�� �ӵ��� ����
	//���� ���� ��� Ȱ�� �ʿ�

	CVector<int> vector;
	/*cout << vector.size() << endl;*/
	for (int i = 1; i < 100; i++)
	{
		vector.push_front(i);
		cout << vector[0] << endl;
	}
	vector.push_front(101);
	//cout << vector.size() << endl;
	cout << vector.top() << endl;


	return 0;
}