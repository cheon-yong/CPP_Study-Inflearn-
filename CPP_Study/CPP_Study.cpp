#include <iostream>
#include <stdlib.h>
using namespace std;

// 오늘의 주제 : 함수 포인터

// typedef의 진실
// typedef 왼쪽 오른쪽 값 -> 오른쪽 (커스텀 타입 정의)

// 정확히는 왼쪽/오른쪽 기준이 아니라.
// [선언 문법]에서 typedef을 앞에다 붙이는 쪽

typedef int INTEGER;
typedef int* POINTER;
typedef int ARRAY[20];
typedef int NUMBER;

typedef int (*PFUNC)(int, int);

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

class Knight
{
public:
	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};

typedef int (Knight::*PMEMFUNC)(int, int);

int main()
{
	// 1) 포인터      *
	// 2) 변수 이름   fn
	// 3) 데이터 타입 함수 (인자 int, int 반환은 int)

	PFUNC t;
	t = Test;
	

	int (*fn)(int, int);
	typedef int(FUNC_TYPE)(int, int);
	fn = &Test; // & 생략 가능 (C 언어의 호환성 때문)
	fn(1, 2);
	(*fn)(1, 2);

	cout << "t" << endl;
	t(1, 2);

	// 위 문법으로 [전역 함수 / 정적 함수]만 담을 수 있다 (호출 규약이 동일한 애들
	// fn = &Knight::GetHp;
	Knight k1;
	PMEMFUNC mfn;

	mfn = &Knight::GetHp;
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);


	delete k2;

	return 0;
}
