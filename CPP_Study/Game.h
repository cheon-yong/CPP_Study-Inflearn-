#pragma once
#include "Player.h"

// [ [ Player ] ]

// ���漱��
class Player;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();
private:
	Player* _player;

};

