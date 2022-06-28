#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// 오늘의 주제 : map

class Player
{
public:
	Player() : _playerId(0) { }
	Player(int playerId) : _playerId(playerId) { }
public:
	int _playerId;
};

int main()
{
	// 연관 컨테이너	

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

	class Node
	{
	public:
		Node* _left;
		Node* _right;

		pair<int, Player*> _data;
		//int _key;
		//Player* _value;
	};

	map<int, int> m;

	// 10만명 입장
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만명 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);
	}

	// Q) ID = 1만인 Player를 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음

	m.find(10000);

	return 0;
}
