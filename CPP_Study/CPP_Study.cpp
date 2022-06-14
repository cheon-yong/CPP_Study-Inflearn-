﻿#include <iostream>
using namespace std;

// 오늘의 주제 : TextRPG
enum PlayerType
{
	PT_Knight = 1,
	PT_Archer,
	PT_Mage
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc,
	MT_Skeleton
};

int playerType;
int hp;
int attack;
int defence;

int monsterType;
int monsterHp;
int monsterAttack;
int monsterDefence;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();

int main()
{
	srand(time(0));
	EnterLobby();

	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "로비에 입장했습니다.!" << endl;
		cout << "---------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		//
		cout << "---------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
		cout << "---------------------" << endl;

		int input;
		cin >> input;
		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}

	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "직업을 골라주세요!!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 마법사" << endl;
		cout << "---------------------" << endl;
		cout << "> ";

		cin >> playerType;
		if (playerType == PT_Knight)
		{
			cout << "기사 생성중...!" << endl;
			hp = 150;
			attack = 10;
			defence = 5;
			break;
		}
		else if (playerType == PT_Archer)
		{
			cout << "궁수 생성중...!" << endl;
			hp = 100;
			attack = 15;
			defence = 3;
			break;
		}
		else if (playerType == PT_Mage)
		{
			cout << "기사 생성중...!" << endl;
			hp = 80;
			attack = 25;
			defence = 0;
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "필드에 입장했습니다.!" << endl;
		cout << "---------------------" << endl;


		cout << "[PLAYER] HP : " << hp << " / ATT : " << attack << " / DEF : " << defence << endl;

		CreateRandomMonster();
	}
}

void CreateRandomMonster()
{
	// 1 ~ 3
	monsterType = (rand() % 3) + 1;

	switch (monsterType)
	{
	case MT_Slime:
		cout << "슬라임 생성중 ...! (HP:15 / ATT:5 / DEF:0)" << endl;
		monsterHp = 15;
		monsterAttack = 5;
		monsterDefence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성중 ...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterHp = 40;
		monsterAttack = 10;
		monsterDefence = 3;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중 ...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterHp = 80;
		monsterAttack = 15;
		monsterDefence = 5;
		break;
	}
}