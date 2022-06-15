#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 실습

struct StatInfo
{
	int hp; // + 0
	int attack; // + 4
	int defence; // + 8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	player = CreatePlayer();

	// 포인터로 전달하는 것이 성능이 훨씬 우수함
	// 복사해서 뱉어내는 방식은 많은 복사 붙여넣기가 일어나는 반면
	// 포인터로 직접 전달하는 방식은 복사가 거의 일어나지 않음
	StatInfo monster;
	CreateMonster(&monster);
	

	bool victory = StartBattle(&player, &monster);
	if (victory)
		cout << "승리 !" << endl;
	else
		cout << "패배 !" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 0;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "플레이어 HP : " << player->hp << endl;

	}
}