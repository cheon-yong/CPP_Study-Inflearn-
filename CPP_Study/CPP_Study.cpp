#include <iostream>

using namespace std;


// 오늘의 주제 : 은닉성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성 = 캡슐화
// - 다형성

// 다형성 (Polymorphism = Poly + morph) = 겉은 똑같은데, 기능이 다르게 동작한다
// - 오버로딩 (Overloading) = 함수 숭복 정의 = 함수 이름의 재사용
// - 오버라이딩 (Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재 정의

// 바인딩(Binding) = 묶는다
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynamic Binding) : 실행 시점에 결정

// 일반 함수는 정적 바인딩을 사용
// 동적 바인딩을 원하면다면? -> 가상 함수 (virtual function)


class Player
{
public:
	void Move() { cout << "Move Player!" << endl; }
	//void Move(int a) { cout << "Mover Player (int) !" << endl; }
	virtual void VMove() { cout << "Move Player!" << endl; }
public:
	int _hp;
};

class Knight : public Player
{
public:
	void Move() { cout << "Move Knight!" << endl; }
	virtual void VMove() { cout << "Move Knight!" << endl; }
public:
	int _stamina;
};

class Mage : public Player
{
public:
	int _mp;
};

void MovePlayer(Player* player)
{
	player->VMove();
}

int main()
{
	// 자식클래스에서 부모클래스는 되지만
	// 부모클래스에서 자식클래스는 쉽지 않음
	Player p;
	MovePlayer(&p); // 플레이어는 플레이어다? YES
	//MoveKnight(&p); // 플레이어는 기사다? NO


	Knight k;
	//MoveKnight(&k); // 기사는 기사다? Yes
	MovePlayer(&k); // 기사는 플레이어다? Yes


	return 0;
}
