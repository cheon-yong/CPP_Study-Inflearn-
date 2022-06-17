#include <iostream>

using namespace std;


// 오늘의 주제 : 상속성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성
// - 

// GameObject
// - Creature
// --Player, Monster, Npc, Pet
// -Projectile
// -- Arrow, Fireball
// - Env

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, Scroll

class GameObject
{
public:
	int _objectId;
};

class Player : GameObject
{
public:
	Player()
	{
		_hp = 100;
		_attack = 10;
		_defence = 5;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 10;
		_defence = 5;
		cout << "Player(int hp) 기본 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "Player() 소멸자 호출" << endl;
	}
	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

// 메모리

// [ [ Player ] ]
// [   Knight   ]

// 상속 (inheritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N) / 소멸자(1)
// 생성자는 생성 시 호출되는 함수
// Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 둘 다 호출

// 생성자는 부모생성자, 자식생성자 순으로 호출
// 소멸자는 자식소멸자, 부모소멸자 순으로 호출
// 그러나 정확히 말하면 자식생성자가 호출되는데 실행하기 전 부모생성자를 실행하는 것

// class는 일종의 설계도
class Knight : public Player
{
public:
	Knight()
		/*
		* 선처리 영역
		* - 이 부분에서 Player()의 생성자를 호출
		*/
	{
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
		/*
		* 선처리 영역
		* - 이 부분에서 Player()의 생성자를 호출
		*/
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 기본 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "Knight() 소멸자 호출" << endl;
	}
	/*
	* 후처리 영역
	* - 여기서 ~Player() 소멸자를 호출
	*/
	void Move() { cout << "Knight Move 호출" << endl; }
public:
	int _stamina;
};

class Mage : public Player
{
public:
	int _mp;
};

int main()
{
	Knight k(100);
	k._hp = 100;
	k._attack = 15;
	k._defence = 5;
	//k._stamina = 50;
	/*
	k.Move();
	k.Die();
	k.Attack();*/
	return 0;
}
