#pragma once
#include "Player.h"

// [ [ Player ] ]

// 전방선언
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

