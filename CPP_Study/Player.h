#pragma once

//#include "Monster.h"

// class는 설계도
class Player
{
public:
	void KillMonster();
	void KillMonster2();
	

public:
	int _hp;
	int _attack;
	Player* _target;
};

