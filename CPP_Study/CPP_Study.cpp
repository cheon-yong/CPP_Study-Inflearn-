#include <iostream>

using namespace std;


// 오늘의 주제 : 초기화 리스트

// 멤버 변수 초기화 ? 다양한 문법이 존재

// 초기화 왜 해야할까? 귀찮은데

class Knight
{
public:
	Knight()
	{

	}

public:
	int _hp;
};


int main()
{
	Knight k;

	cout << k._hp << endl;

	if (k._hp < 0)
	{
		cout << "Knight is Dead" << endl;
	}

	return 0;
}
