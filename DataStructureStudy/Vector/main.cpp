#include <iostream>
#include"Vector.h"
using namespace std;


int main()
{
	//중간에 데이터 삽입시 뒤에 있는 데이터들이 한칸씩 쭉 밀림
	//중간 데이터 삭제시 앞으로 한칸씩 당겨옴
	//위의 작업으로 인해 처리속도 느릴 수 있음
	//random access 가능, List에 노드를 추가시 생성자의 동적할당이 필요하지만 Vector나 배열은 빈공간에 데이터만 할당하면 되므로 여유공간이 있을 시 처리 속도가 빠름
	//공간 예약 기능 활용 필요

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