﻿#include <iostream>
#include <stdlib.h>
using namespace std;

// 오늘의 주제 : 함수 객체

void HelloWorld()
{
	cout << "Hellow World" << endl;
}

void HelloNumber(int number)
{
	cout << "Hello Number " << number << endl;
}

class Knight
{
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}

private:
	int _hp = 100;
};

class Functor
{
public:
	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator()(int num)
	{
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;
		return true;
	}
private:
	int _value = 0;

};

class MoveTask
{
public:
	void operator()()
	{
		// TODO
		cout << "해당 좌표로 플레이어 이동" << endl;
	}
public:
	int _playerId;
	int _posX;
	int _posY;
};

int main()
{
	// 함수 객체 (Functor) : 함수처럼 동작하는 객체
	// 함수 포인터의 단점

	// 함수 포인터 선언

	void (*pfunc)(void);

	pfunc = &HelloWorld;
	//pfunc();

	// 함수 포인터 단점
	// 1) 시그니처가 안 맞으면 사용할 수 없다
	// 2) 상태를 가질 수 없다

	// [함수처럼 동작]하는 객체
	// () 연산자 오버로딩

	Functor functor;
	functor();
	bool ret = functor(123);

	// MMO에서 함수 객체를 사용하는 예시
	// 클라 <-> 서버
	// 서버 : 클라가 보내준 네트워크 패킷을 받아서 처리
	// ex) 클라 : 나 (5, 0) 좌표로 이동시켜줘!

	MoveTask task;
	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;

	task();

	return 0;
}
