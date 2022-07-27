﻿#include <iostream>
using namespace std;
#include <vector>

// 오늘의 주제 : nullptr

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

class Knight
{
public:
	void Test()
	{

	}
};

Knight* FindKnight()
{
	return nullptr;
}

//NullPtr 구현
const
class
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}
private:
	void operator&() const; // 주소값 &을 막는다
} _nullptr;

int main()
{
	int* ptr = NULL;// 0 NULL

	// 1) 오동작
	Test(0);
	//Test(NULL);
	Test(_nullptr);

	&_nullptr;
	// 2) 가독성
	Knight* knight = FindKnight();
	if (knight == _nullptr)
	{

	}

	void (Knight:: * memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _nullptr)
	{

	}

	auto whoami = _nullptr;

	return 0;
}