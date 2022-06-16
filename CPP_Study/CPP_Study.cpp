#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 마무리

// 1) 포인터 vs 배열 2탄
// 2) 주의사항 

int& TestRef()
{
	int a = 1;
	return a;
}

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = {};
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
}
int main()
{
	// 주소를 담는 바구니
	// 진짜는 어딘가에
	// p는 단지 그 곳으로 이동하는 역할
	int* p;

	// 진짜 데이터의 나열
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	// 그런데 상당히 많은 사람들이 [배열 = 포인터] 라고 착각하는 경향이 있음

	// - [배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능!

	// - [TYPE형 1차원 배열]과 [TYPE* 포인터]는 완전히 호환이 된다.
	
	p = arr;


	//cout << p[0] << endl;
	//cout << arr[0] << endl;

	//cout << *p << endl;
	//cout << *arr << endl;

	//cout << *(p + 3) << endl;
	//cout << *(arr + 3) << endl;

	// 그 런 데
	
	// [1][2][3][4]
	int arr2[2][2] = { {1, 2}, {3, 4} };

	//int** pp = (int**)arr2;

	int(*p2)[2] = arr2;

	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;

	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;

	int* pointer = TestPointer();
	TestWrong(pointer);
	
	//cout << (**pp) << endl;

	return 0;
}
