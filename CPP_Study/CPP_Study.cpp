#include <iostream>
using namespace std;
#include <vector>

// 오늘의 주제 : 중괄호 초기화 { }


class Knight
{
public:
	Knight()
	{

	}
	Knight(initializer_list<int> li)
	{
		cout << "Knight(initializer_list)" << endl;
	}
public:
	int _hp;
};

int main()
{
	// 중괄호 초기화 { }
	int a = 0;
	int b(0);
	int c{ 0 };
	

	Knight k1;
	Knight k2 = k1; // 복사생성자 (대입 연산자 x)
	
	Knight k3{ k1 }; // 기본 생성자
	Knight k4;
	k4 = k1; // 대입 연산자

	int arr[] = { 1,2,3,4 };
	vector<int> v2(10, 1);

	// 중괄호 초기화
	// 1) vector 등 container와 잘 어울린다
	vector<int> v3{ 1, 2, 3, 4 };

	// 2) 축소 변환 방지
	int x = 0;
	//double y{ x }; // 에러

	// 3) Bonus
	Knight k5();

	Knight k6{ 1, 2,3,4,5 };


	// 괄호 초기화 ()를 기본으로 간다
	// - 전통적인 C++ (거부감이 없음)
	// - vector 등 특이한 케이스에 대해서만 { } 사용

	// 중괄호 초기화 { } 를 기본으로 간다
	// - 초기화 문법의 일치화
	// - 축소 변환 방지
	return 0;
}
