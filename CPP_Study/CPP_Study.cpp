#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <algorithm>
#include <set>

// 오늘의 주제 : override, final

class Creature
{
public:
	virtual void Attack()
	{
		cout << "Creature!" << endl;
	}
};

class Player : Creature
{
public:
	virtual void Attack() override
	{
		cout << "Player!" << endl;
	} 
};

class Knight : public Player
{
public:
	void Attack() override // 부모클래스에서 final로 지정되면 재정의 불가
	{
		cout << "Knight!" << endl;
	}

	// 오버로딩(overloading) : 함수 이름의 재사용
	virtual void Attack(int a)
	{
		cout << a << endl;
	}
};

int main()
{
	Player* player = new Knight();

	player->Attack();

	return 0;
}