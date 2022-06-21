#include <iostream>
#include <stdlib.h>
using namespace std;

// 오늘의 주제 : 템플릿 기초

class Knight
{
public:
	//

public:
	int _hp = 100;
};


template<typename T>
void Print(T a)
{
	cout << a << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 연산자 오버로딩 (전역함수 버전)
ostream& operator<<(ostream & os, const Knight & k)
{
	os << k._hp;
	return os;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
	cout << "Knight!!!!!!!!!!!!!!!!" << endl;
	cout << a._hp << endl;
}

int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	Print(50);
	Print(50.0f);
	Print(50.0);
	Print("HelloWorld");

	int result1 = Add(1, 2);
	float result2 = Add(1.2f, 2.2f);

	Print(100, "Hello");
	
	Knight k1;
	Print(k1);

	return 0;
}
