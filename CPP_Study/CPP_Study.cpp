﻿#include <iostream>

using namespace std;


// 오늘의 주제 : 은닉성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 은닉성 (Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다!
// 숨기는 이유?
// - 1) 정말 위험하고 건드리면 안되는 경우
// - 2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// - 핸들/페달/문
// 몰라도 됨 (오히려 건드리면 큰일남)
// - 엔진, 각종 전기선

// 접근 지정자
// public(공개적) protected(보호받는) private(개인의)
// - public : 누구한테나 공개. 마음대로 사용
// - protected : 나의 자손들한테만 허락
// - private : 나만 사용할 것 class 내부에서만 사용 가능

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음
// - public : 공개적 상속? 부모님의 유산 설계 그대로 (public -> public, protected -> protected)
// - protected : 보호받는 상속? 내 자손들한테만 물려줄거야 (public -> protected, protected -> protected)
// - private : 개인적인 상속? 나까지만 쓰고 자손들한테는 안물려줄거야 (public -> private, protected -> private)

class Car
{
public: // (멤버) 접근 지정자
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }

	void TurnKey()
	{
		// ...
		RunEngine();
	}
private:
	
protected:
	void DisassembleCar() { }
	void RunEngine() { }
	void ConnectCircuit() { }
public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선
};

class SuperCar : public Car
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

class TestSuperCar : public SuperCar
{
public:
	void Test()
	{
		PushRemoteController();
	}
};

// '캡슐화;
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:
	int GetHP() { return _hp; }
	void SetHp(int hp)
	{ 
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}
	// 사양 : 체력이 50이하로 떨어지면 버서커 모드 발동 (강해짐)
private:
	void SetBerserkerMode()
	{
		cout << "매우 강해짐!" << endl;
	}
private:
	int _hp = 100;
};
int main()
{
	TestSuperCar car;

	

	return 0;
}
